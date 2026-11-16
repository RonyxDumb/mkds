#include "Main/Race/race_setup_input.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/results_gp.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Sound/startup_sound_set_player_back_lights_and_random.h"
#include "Main/Race/cup_records.h"
#include "Main/System/low_byte.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Save/ghost_record.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Net/player_record.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/System/input_slots.h"
#include "cpu_copy_fill.h"
#include "Main/Net/mp.h"
#include "reset_interrupts_halt.h"
#include "Main/System/input_slot_repeat.h"
#include "Main/Race/race_keys.h"
#include "Main/System/touch_mic_input.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/participant_index.h"
#include "Main/System/wireless_vram_state.h"
#include "Main/System/key_recording.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Race/mission_file_row.h"
#include "Main/System/heap.h"
#include "Main/Race/race_scene.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/key_recording_reset.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/Save/mission_record.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/input_slot_pair_reset.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "card_rom_backup_access.h"
#include "registers.h"
#include "model_texture_bind.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

const u32 gCupCourseIdTable[8][4] = {{0x14, 0x16, 0x1f, 0x12}, {0x1b, 0x1c, 0x21, 0x18}, {0x1e, 0x11, 0x19, 0x13},
                                     {0x22, 0x1a, 0x20, 0x1d}, {0xa, 0xb, 0xd, 0xe},     {0x23, 0x10, 0xc, 9},
                                     {0xf, 0x24, 0x25, 0x26},  {0x27, 0x17, 0x28, 1}};
const u32 gCupIndicesTwoCups[2] = {0, 4};
const u32 gThreeCourseIds[3] = {0x2c, 0x2f, 0x2b};
const u32 gSixCourseIds[6] = {0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f};
const u16 gCharacterSndBankMasks[13] = {0x10, 1, 2, 4, 0x20, 0x40, 0x80, 8, 0x400, 0x100, 0x200, 0x800, 0x1000};
const u32 gCupIndicesEightCups[8] = {0, 1, 2, 3, 4, 5, 6, 7};

static inline u32 BuildCourseListNextRandomBelowU16(RandomState64 *randomState64, u32 limit) {
    u64 result;
    if (limit == 0) {
        result = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            result = randomState64->mValue >> 32;
        } else {
            result = ((randomState64->mValue >> 32) * limit) >> 32;
        }
    }
    return (u16) result;
}

BOOL IsCupEnabled(s32 cupIndex) {
    u32 engineOrMirrorIndex;
    engineOrMirrorIndex = (u8) gRaceSetup->mNextHeader.mEngineIndex;
    if (gRaceSetup->mNextHeader.mMirrorMode != 0) {
        engineOrMirrorIndex = 3;
    }
    switch (cupIndex) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (IsBitSetInAnyParticipant(engineOrMirrorIndex)) {
                return TRUE;
            }
            break;
        case 3:
            if (IsBitSetInAnyParticipant(engineOrMirrorIndex + 4)) {
                return TRUE;
            }
            break;
        case 6:
            if (IsBitSetInAnyParticipant(engineOrMirrorIndex + 8)) {
                return TRUE;
            }
            break;
        case 7:
            if (IsBitSetInAnyParticipant(engineOrMirrorIndex + 12)) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void AssignCpuNumbers(void) {
    u8 nextCpuNumber;
    BOOL noCpuNumbers;
    u8 entryIndex;
    nextCpuNumber = 1;
    noCpuNumbers = FALSE;
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
        case MODE_WIFI:
            noCpuNumbers = TRUE;
            break;
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        if (noCpuNumbers == FALSE && gRaceSetup->mNextEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
            gRaceSetup->mNextEntries[entryIndex].mPlayer.mNumber = nextCpuNumber;
            nextCpuNumber = nextCpuNumber + 1;
        } else {
            gRaceSetup->mNextEntries[entryIndex].mPlayer.mNumber = -1;
        }
    }
    gRaceSetup->mNextCpuNumber = nextCpuNumber;
}

u32 NextRandomBelowU16(RandomState64 *randomState64, u32 limit) {
    u64 result;
    if (limit == 0) {
        result = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            result = randomState64->mValue >> 32;
        } else {
            result = ((randomState64->mValue >> 32) * limit) >> 32;
        }
    }
    return (u16) result;
}

void BuildCourseList(s32 isVersus) {
    s32 multibootSetupOrEntryIndex;
    u32 cupCountOrLastCourseIndex;
    const u32 *cupOrCourseIdTable;
    u32 listIndex;
    u32 courseCount;
    multibootSetupOrEntryIndex = 0;
    ResetCupRecords();
    gRaceSetup->mCourseListIndex = 0;
    gRaceSetup->mNextHeader.mCourseNumber = 1;
    if (isVersus != 0) {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else if (gStartupWork->mMultiSimple) {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_BATTLE;
    }
    for (listIndex = 0; listIndex < RACE_SETUP_COURSE_LIST_LENGTH; listIndex++) {
        gRaceSetup->mCourseList[listIndex] = 0;
    }
    switch (gStartupWork->mConnectionKind) {
        case CONNECTION_KIND_MEMBER_SELECT:
        case CONNECTION_KIND_WL_MENU:
            multibootSetupOrEntryIndex = (gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0;
            break;
    }
    switch (gRaceSetup->mNextHeader.mCourseListMode) {
        case COURSE_LIST_MODE_IN_ORDER:
            if (isVersus != 0) {
                u8 cupSlot;
                u8 courseSlot;
                u32 entryCount;
                s32 currentCourseId;
                s32 enabledCount;
                cupCountOrLastCourseIndex = multibootSetupOrEntryIndex != 0 ? 2 : 8;
                cupOrCourseIdTable = multibootSetupOrEntryIndex != 0 ? gCupIndicesTwoCups : gCupIndicesEightCups;
                currentCourseId = gRaceSetup->mNextHeader.mCourseId;
                entryCount = cupCountOrLastCourseIndex * 4;
                for (multibootSetupOrEntryIndex = 0; multibootSetupOrEntryIndex < entryCount; multibootSetupOrEntryIndex++) {
                    cupSlot = multibootSetupOrEntryIndex / 4;
                    courseSlot = multibootSetupOrEntryIndex % 4;
                    if (currentCourseId == gCupCourseIdTable[cupOrCourseIdTable[cupSlot]][courseSlot]) {
                        break;
                    }
                }
                enabledCount = 0;
                for (multibootSetupOrEntryIndex = 0; multibootSetupOrEntryIndex < entryCount; multibootSetupOrEntryIndex++) {
                    if (IsCupEnabled(cupOrCourseIdTable[cupSlot]) != FALSE) {
                        gRaceSetup->mCourseList[enabledCount] = gCupCourseIdTable[cupOrCourseIdTable[cupSlot]][courseSlot];
                        enabledCount = (u8) (enabledCount + 1);
                    }
                    courseSlot = courseSlot + 1;
                    if (courseSlot >= 4) {
                        courseSlot = 0;
                        cupSlot = cupSlot + 1;
                        if (cupSlot >= cupCountOrLastCourseIndex) {
                            cupSlot = 0;
                        }
                    }
                }
                return;
            } else {
                s32 currentCourseId;
                u32 startIndex;
                courseCount = multibootSetupOrEntryIndex != 0 ? 3 : 6;
                startIndex = 0;
                cupOrCourseIdTable = multibootSetupOrEntryIndex != 0 ? gThreeCourseIds : gSixCourseIds;
                currentCourseId = gRaceSetup->mNextHeader.mCourseId;
                for (listIndex = 0; listIndex < courseCount; listIndex++) {
                    startIndex = listIndex;
                    if (currentCourseId == cupOrCourseIdTable[listIndex]) {
                        break;
                    }
                }
                for (listIndex = 0; listIndex < courseCount; listIndex++) {
                    gRaceSetup->mCourseList[listIndex] = cupOrCourseIdTable[startIndex];
                    startIndex++;
                    if (startIndex >= courseCount) {
                        startIndex = 0;
                    }
                }
                return;
            }
        case COURSE_LIST_MODE_SHUFFLED:
            if (isVersus != 0) {
                RandomState64 *random;
                u32 entryCount;
                s32 entryIndex;
                s32 enabledCount;
                u8 courseSlot;
                u8 cupSlot;
                u8 swapIndex;
                u8 shuffleIndex;
                u8 swapTemp;
                s32 swapCount;
                s32 passIndex;
                random = GetRandomState();
                cupCountOrLastCourseIndex = multibootSetupOrEntryIndex != 0 ? 2 : 8;
                cupOrCourseIdTable = multibootSetupOrEntryIndex != 0 ? gCupIndicesTwoCups : gCupIndicesEightCups;
                entryCount = cupCountOrLastCourseIndex * 4;
                enabledCount = 0;
                for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
                    cupSlot = entryIndex / 4;
                    courseSlot = entryIndex % 4;
                    if (IsCupEnabled(cupOrCourseIdTable[cupSlot]) != FALSE) {
                        gRaceSetup->mCourseList[enabledCount] = gCupCourseIdTable[cupOrCourseIdTable[cupSlot]][courseSlot];
                        enabledCount = (u8) (enabledCount + 1);
                    }
                }
                swapCount = enabledCount * 2;
                for (passIndex = 0; passIndex < swapCount; passIndex++) {
                    swapIndex = NextRandomBelowU16(random, (vu16) (enabledCount - 1));
                    shuffleIndex = passIndex % enabledCount;
                    swapTemp = gRaceSetup->mCourseList[shuffleIndex];
                    if (swapIndex >= shuffleIndex) {
                        swapIndex = swapIndex + 1;
                    }
                    gRaceSetup->mCourseList[shuffleIndex] = gRaceSetup->mCourseList[swapIndex];
                    gRaceSetup->mCourseList[swapIndex] = swapTemp;
                }
            } else {
                s32 courseIndex;
                RandomState64 *random;
                random = GetRandomState();
                courseCount = multibootSetupOrEntryIndex != 0 ? 3 : 6;
                cupOrCourseIdTable = multibootSetupOrEntryIndex != 0 ? gThreeCourseIds : gSixCourseIds;
                for (courseIndex = 0; courseIndex < courseCount; courseIndex++) {
                    gRaceSetup->mCourseList[courseIndex] = cupOrCourseIdTable[courseIndex];
                }
                courseIndex = 0;
                if (courseIndex < courseCount) {
                    cupCountOrLastCourseIndex = (u16) (courseCount - 1);
                    for (; courseIndex < courseCount; courseIndex++) {
                        u8 swapIndex;
                        u8 swapTemp;
                        swapIndex = BuildCourseListNextRandomBelowU16(random, cupCountOrLastCourseIndex);
                        swapTemp = gRaceSetup->mCourseList[courseIndex];
                        if (swapIndex >= courseIndex) {
                            swapIndex = swapIndex + 1;
                        }
                        gRaceSetup->mCourseList[courseIndex] = gRaceSetup->mCourseList[swapIndex];
                        gRaceSetup->mCourseList[swapIndex] = swapTemp;
                    }
                }
            }
            gRaceSetup->mNextHeader.mCourseId = gRaceSetup->mCourseList[0];
            break;
    }
}

void AssignCpuNumbersAndSetupFirstCourse(void) {
    u8 entryIndex;
    u8 humanIndex;
    AssignCpuNumbers();
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            ResetCupRecords();
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            gRaceSetup->mNextHeader.mCourseId =
                gCupCourseIdTable[gRaceSetup->mNextHeader.mCupIndex][gRaceSetup->mNextHeader.mCourseNumber - 1];
            break;
        case MODE_VS:
            BuildCourseList(1);
            break;
        case MODE_BATTLE:
            BuildCourseList(0);
            break;
        case MODE_WIFI:
            humanIndex = 0xff;
            ResetCupRecords();
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                if (gRaceSetup->mNextEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    humanIndex = entryIndex;
                    break;
                }
            }
            gRaceSetup->mNextHeader.mFollowedKartIndex = humanIndex;
            break;
        case MODE_MISSION_RUN:
            ResetCupRecords();
            if (gRaceSetup->mNextHeader.mMissionTableColumn == 9) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            } else {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            }
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            break;
    }
}

BOOL CopyEntryResultAndSetupAwardRace(void) {
    s8 entryIndex;
    u8 index;
    s8 kartIndex;
    u8 courseIndexInCup;
    u32 lowByte;
    s32 rankIndex;
    KartCourseResult *courseResult;
    entryIndex = gRaceSetup->mEntryIndex;
    gMenuShared->mCupRankIndex = GetKartCupRank(entryIndex) - 1;
    gMenuShared->mGrade = ComputeGrandPrixRecordValue();
    gMenuShared->mCharacterIndex = gRaceSetup->mCurrentEntries[(u8) entryIndex].mCharacterIndex;
    gMenuShared->mCupIndex = gRaceSetup->mCupIndex;
    gMenuShared->mEngineIndex = gRaceSetup->mEngineIndex;
    gMenuShared->mMirrorMode = gRaceSetup->mMirrorMode;
    lowByte = GetLowByte((u8) entryIndex);
    courseIndexInCup = GetCourseIndexInCup();
    courseResult = &gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)];
    gMenuShared->mTotalPoints = courseResult->mTotalPoints;
    gMenuShared->mKartIndex = gRaceSetup->mCurrentEntries[(u8) entryIndex].mKartIndex;
    for (index = 0; index < 4; index++) {
        MinuteSecondMillisecondTime finishTime;
        GetKartCourseFinishTime(&finishTime, gRaceSetup->mEntryIndex, index);
        gMenuShared->mCourseTimes[index] = finishTime;
    }
    if ((u32) GetKartCupRank(gRaceSetup->mEntryIndex) > 3) {
        return FALSE;
    }
    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_AWARD;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_AWARD;
    for (index = 0; index < 3; index++) {
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
            if (GetKartCupRank(kartIndex) == index + 1) {
                break;
            }
        }
        SetNextRaceEntry(index, GetCurrentEntry(kartIndex)->mCharacterIndex, GetCurrentEntry(kartIndex)->mKartIndex,
                         PLAYER_KIND_CPU, -1, 3);
    }
    for (; index < 8; index++) {
        SetNextRaceEntry(index, index, index * 3, PLAYER_KIND_NONE, -1, 3);
    }
    for (index = 0; index < 8; index++) {
        rankIndex = GetKartCupRank(index) - 1;
        gMenuShared->mCupRankKartIndices[rankIndex] = gRaceSetup->mCurrentEntries[index].mKartIndex;
        gMenuShared->mCupRankCharacterIndices[rankIndex] = gRaceSetup->mCurrentEntries[index].mCharacterIndex;
    }
    gRaceSetup->mNextHeader.mFollowedKartIndex = GetKartCupRank(gRaceSetup->mEntryIndex) - 1;
    return TRUE;
}

void SetupStaffRollRace(s32 useTrueStaffRoll) {
    u8 index;
    s8 searchIndex;
    s32 characterIndex;
    s32 kartIndex;
    if (useTrueStaffRoll != 0) {
        gRaceSetup->mNextHeader.mCourseId = COURSE_ID_STAFFROLLTRUE;
    } else {
        gRaceSetup->mNextHeader.mCourseId = COURSE_ID_STAFFROLL;
    }
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
    gRaceSetup->mNextHeader.mEngineIndex = ENGINE_CLASS_MEDIUM;
    gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
    for (index = 0; index < 8; index++) {
        for (searchIndex = 0; searchIndex < gRaceSetup->mKartCount; searchIndex++) {
            if (GetKartCupRank(searchIndex) == index + 1) {
                break;
            }
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            if ((gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1) == MISSION_TABLE_ROW_KING_ICE_DONKETU &&
                (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9) {
                if (index == 0) {
                    characterIndex = 7;
                    kartIndex = 0x15;
                } else if (index == 7) {
                    characterIndex = 0;
                    kartIndex = characterIndex;
                } else {
                    characterIndex = index;
                    kartIndex = index * 3;
                }
            } else {
                characterIndex = index;
                kartIndex = index * 3;
            }
        } else if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            if (GetStaffRollKindAfterGp() != 2) {
                characterIndex = index;
                kartIndex = index * 3;
            } else {
                characterIndex = gMenuShared->mCupRankCharacterIndices[index];
                kartIndex = gMenuShared->mCupRankKartIndices[index];
            }
        } else {
            characterIndex = index;
            kartIndex = index * 3;
        }
        SetNextRaceEntry(index, characterIndex, kartIndex, PLAYER_KIND_CPU, -1, 3);
    }
}

s32 AdvanceToNextCourse(void) {
    BOOL result;
    s32 entryIndex;
    s32 newSlot;
    s32 oldSlot;
    result = TRUE;
    gRaceSetup->mNextHeader.mCourseNumber++;
    if (gRaceSetup->mListedCpuCount > 1) {
        for (entryIndex = 0; entryIndex < gRaceSetup->mKartCount; entryIndex++) {
            oldSlot = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mListedCpuSlot;
            newSlot = 3;
            if (oldSlot != 0) {
                if (oldSlot == 1) {
                    newSlot = 0;
                }
            } else {
                newSlot = 1;
            }
            gRaceSetup->mNextEntries[entryIndex].mPlayer.mListedCpuSlot = newSlot;
        }
    }
    switch (gRaceSetup->mCourseListMode) {
        case COURSE_LIST_MODE_SINGLE:
            result = FALSE;
            break;
        case COURSE_LIST_MODE_IN_ORDER:
        case COURSE_LIST_MODE_SHUFFLED:
            gRaceSetup->mCourseListIndex++;
            if (gRaceSetup->mCourseList[gRaceSetup->mCourseListIndex] == 0) {
                gRaceSetup->mCourseListIndex = 0;
            }
            gRaceSetup->mNextHeader.mCourseId = gRaceSetup->mCourseList[gRaceSetup->mCourseListIndex];
            break;
    }
    return result;
}

s32 AdvanceToNextCourseWrapper(void) {
    return AdvanceToNextCourse();
}

s32 AdvanceToNextBattleCourse(void) {
    if (gStartupWork->mMultiSimple) {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_BATTLE;
    }
    return AdvanceToNextCourse();
}

BOOL CopyCourseIdAndAdvanceCourseNumber(void) {
    gMenuShared->mUnk_5c[gRaceSetup->mCourseNumber] = gRaceSetup->mCourseId;
    gRaceSetup->mNextHeader.mCourseNumber++;
    return gRaceSetup->mNextHeader.mCourseNumber <= COURSES_PER_CUP;
}

static inline void SetNextRaceEntryWrapper(s32 listedCpuSlot, u32 teamIndex, s32 playerKind, u32 kartIndex,
                                           u32 characterIndex, s32 entryIndex) {
    SetNextRaceEntry(entryIndex, characterIndex, kartIndex, playerKind, teamIndex, listedCpuSlot);
}

static inline PlayerRecord *GetPlayerRecordByEntryIndex(ConnectionWork *connectionWork, s32 entryIndex) {
    u16 participantIndex;

    participantIndex = connectionWork->mParticipantIndexByPos[entryIndex];
    return participantIndex == 0xffff ? 0 : &connectionWork->mPlayerRecords[participantIndex];
}

static inline BOOL IsBootInfoFirstWordTwo(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return TRUE;
    }
    return FALSE;
}

void ResetRaceSetup(void) {
    u16 index;
    MinuteSecondMillisecondTime *time;

    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_CROSS;
    gRaceSetup->mNextHeader.mCupIndex = 0;
    gRaceSetup->mNextHeader.mMode = MODE_GRAND_PRIX;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    gRaceSetup->mNextHeader.mEngineIndex = ENGINE_CLASS_SLOW;
    gRaceSetup->mNextHeader.mCpuDifficulty = 0;
    gRaceSetup->mNextHeader.mBattleKind = 0;
    gRaceSetup->mNextHeader.mRuleKind = RULE_KIND_FREE;
    gRaceSetup->mNextHeader.mCourseListMode = COURSE_LIST_MODE_SINGLE;
    gRaceSetup->mNextHeader.mGhostRecordIndex = GHOST_RECORD_INDEX_COURSE;
    MI_CpuFill8(&gRaceSetup->mNextHeader.mMissionFileRow, 0, sizeof(gRaceSetup->mNextHeader.mMissionFileRow));
    gRaceSetup->mNextHeader.mMissionTableRow = -1;
    gRaceSetup->mNextHeader.mMissionTableColumn = -1;
    gRaceSetup->mNextHeader.mUnk_56[0] = 0;
    gRaceSetup->mNextHeader.mMirrorMode = 0;
    gRaceSetup->mNextHeader.mUseTeams = 0;
    gRaceSetup->mNextHeader.mSeed = 0;
    gRaceSetup->mNextHeader.mCourseNumber = 1;
    gRaceSetup->mNextHeader.mEntryIndex = -1;
    gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
    gRaceSetup->mNextHeader.mLapCount = -1;
    for (index = 0; index < 8; index++) {
        gRaceSetup->mNextEntries[index].mCharacterIndex = index;
        gRaceSetup->mNextEntries[index].mKartIndex = index * 3;
        gRaceSetup->mNextEntries[index].mPlayer.mKind = index == 0 ? PLAYER_KIND_HUMAN : PLAYER_KIND_CPU;
        gRaceSetup->mNextEntries[index].mPlayer.mTeamIndex = -1;
        gRaceSetup->mNextEntries[index].mPlayer.mListedCpuSlot = KART_ENTRY_LISTED_CPU_SLOT_NONE;
        gRaceSetup->mNextEntries[index].mPlayer.mIndex = index;
        gRaceSetup->mNextEntries[index].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_NONE;
        gRaceSetup->mNextEntries[index].mPlayer.mListedCpuFlags = 0;
        gRaceSetup->mNextEntries[index].mPlayer.mName = NULL;
        gRaceSetup->mNextEntries[index].mPlayer.mHasEmblem = 0;
        gRaceSetup->mNextEntries[index].mPlayer.mRegion = gStartupWork->mRegion;
        gRaceSetup->mNextEntries[index].mPlayer.mEmblemData = NULL;
        gRaceSetup->mNextEntries[index].mPlayer.mFriendData = 0;
    }
    gRaceSetup->mNextEntries[7].mPlayer.mListedCpuSlot = 0;
    gRaceSetup->mNextEntries[6].mPlayer.mListedCpuSlot = 1;
    gRaceSetup->mKartCount = 0;
    gRaceSetup->mHumanAndPeerKartCount = 0;
    for (index = 0; index < 2; index++) {
        gRaceSetup->mTeamKartCounts[index] = 0;
    }
    gRaceSetup->mListedCpuCount = 0;
    for (index = 0; index < 2; index++) {
        gRaceSetup->mListedCpuEntryIndices[index] = -1;
    }
    gRaceSetup->mCourseCount = 0;
    for (index = 0; index < 0x21; index++) {
        gRaceSetup->mCourseList[index] = 0;
    }
    gRaceSetup->mCourseListIndex = 0;
    time = &gRaceSetup->mGhostTime;
    time->mMinute = 0;
    time->mSecond = 0;
    time->mMillisecond = 0;
    for (index = 0; index < 5; index++) {
        time = &gRaceSetup->mGhostLapTimes[index];
        time->mMinute = 0;
        time->mSecond = 0;
        time->mMillisecond = 0;
    }
    ResetCupRecords();
    ResetParticipantKartMap();
    SetCurrentRaceFromNext();
}

void SetCurrentEntryPlayer(s32 entryIndex) {
    BackupBuffers *backupBuffers;
    ConnectionWork *connectionWork;
    void **nameSlot;
    void **emblemDataSlot;
    u8 *hasEmblemSlot;
    u8 *regionSlot;
    u8 *lowestRecordValueSlot;
    DWCAccFriendData **friendDataSlot;
    BOOL emblemFilledAndOn;
    BOOL hasEmblem;
    BOOL connectionActive;
    s8 participantOfKart;
    u8 participantIndex;

    backupBuffers = gBackupBuffers;
    nameSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName;
    emblemDataSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mEmblemData;
    hasEmblemSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mHasEmblem;
    regionSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mRegion;
    lowestRecordValueSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mLowestGrandPrixRecordValue;
    friendDataSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mFriendData;
    emblemFilledAndOn = FALSE;
    if (backupBuffers->mEmblemRecord->mFilled != 0) {
        emblemFilledAndOn = backupBuffers->mFirstBlock->mEmblemOff == 0;
    }
    if (emblemFilledAndOn != FALSE) {
        hasEmblem = TRUE;
    } else {
        hasEmblem = FALSE;
    }
    *nameSlot = NULL;
    *emblemDataSlot = NULL;
    *hasEmblemSlot = 0;
    *friendDataSlot = 0;
    *regionSlot = gStartupWork->mRegion;
    *lowestRecordValueSlot = 0;
    if (entryIndex == gRaceSetup->mEntryIndex) {
        *nameSlot = &gBackupBuffers->mFirstBlock->mPlayerName;
        *emblemDataSlot = &gBackupBuffers->mEmblemRecord->mEmblemData;
        *hasEmblemSlot = hasEmblem != FALSE ? 1 : 0;
        *regionSlot = gStartupWork->mRegion;
        *lowestRecordValueSlot = GetLowestGrandPrixRecordValue();
        return;
    }
    switch (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind) {
        case PLAYER_KIND_HUMAN:
            connectionWork = gConnectionWork;
            connectionActive = FALSE;
            if ((connectionWork == NULL ? CONNECTION_MODE_NONE : connectionWork->mConnectionMode) !=
                    CONNECTION_MODE_NONE &&
                connectionWork->mState != CONNECTION_STATE_ENDED) {
                connectionActive = TRUE;
            }
            if (connectionActive == FALSE) {
                return;
            }
            if (GetPlayerRecordByEntryIndex(connectionWork, entryIndex) == NULL) {
                return;
            }
            *nameSlot = GetPlayerRecordByEntryIndex(connectionWork, entryIndex);
            *emblemDataSlot = &GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mEmblem[0];
            *hasEmblemSlot = GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mHasEmblem;
            *regionSlot = GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mRegion;
            *friendDataSlot =
                IsBootInfoFirstWordTwo() || (gConnectionWork->mGroupSendMask &
                                             (1 << gConnectionWork->mParticipantIndexByPos[entryIndex])) != 0
                    ? 0
                    : &GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mFriendData;
            *lowestRecordValueSlot =
                GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mLowestGrandPrixRecordValue;
            break;
        case PLAYER_KIND_GHOST:
            switch (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mGhostRecordIndex) {
                case GHOST_RECORD_INDEX_COURSE:
                    *nameSlot = &gBackupBuffers->mCourseGhostRecord->mHead.mName;
                    *emblemDataSlot = &gBackupBuffers->mEmblemRecord->mEmblemData;
                    *hasEmblemSlot = hasEmblem != FALSE ? 1 : 0;
                    *regionSlot = gBackupBuffers->mCourseGhostRecord->mHead.mRegion;
                    *lowestRecordValueSlot = 0;
                    break;
                case GHOST_RECORD_INDEX_FIRST_SLOT:
                    *nameSlot = &gBackupBuffers->mSlotGhostRecords[0]->mHead.mName;
                    *emblemDataSlot = &gBackupBuffers->mSlotGhostRecords[0]->mEmblem;
                    *hasEmblemSlot = gBackupBuffers->mSlotGhostRecords[0]->mHead.mHasEmblem;
                    *regionSlot = gBackupBuffers->mSlotGhostRecords[0]->mHead.mRegion;
                    *lowestRecordValueSlot = gBackupBuffers->mSlotGhostRecords[0]->mHead.mLowestGrandPrixRecordValue;
                    break;
                case GHOST_RECORD_INDEX_SECOND_SLOT:
                    *nameSlot = &gBackupBuffers->mSlotGhostRecords[1]->mHead.mName;
                    *emblemDataSlot = &gBackupBuffers->mSlotGhostRecords[1]->mEmblem;
                    *hasEmblemSlot = 1;
                    *regionSlot = gBackupBuffers->mSlotGhostRecords[1]->mHead.mRegion;
                    *lowestRecordValueSlot = 1;
                    break;
            }
            break;
        case PLAYER_KIND_PEER:
            participantOfKart = GetParticipantOfKart(entryIndex);
            if (participantOfKart < 0) {
                return;
            }
            participantIndex = participantOfKart;
            *nameSlot = GetPlayerRecordName(participantIndex);
            *emblemDataSlot = GetPlayerRecordEmblem(participantIndex);
            *hasEmblemSlot = HasPlayerRecordEmblem(participantIndex);
            *regionSlot = GetPlayerRecordRegion(participantIndex);
            *friendDataSlot = GetPlayerRecordFriendData(participantIndex);
            *lowestRecordValueSlot = GetPlayerRecordLowestGrandPrixValue(participantIndex);
            break;
    }
}

void RefreshListedCpuEntryIndices(void) {
    u8 listedCount;
    s8 entryIndex;

    listedCount = 0;
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        gRaceSetup->mListedCpuEntryIndices[entryIndex] = -1;
    }
    for (entryIndex = 0; entryIndex < gRaceSetup->mKartCount; entryIndex++) {
        if ((GetCurrentEntry(entryIndex)->mPlayer.mListedCpuFlags & KART_ENTRY_LISTED_CPU_FLAG) != 0) {
            SetListedCpuEntryIndex(gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mListedCpuSlot, entryIndex);
            listedCount++;
        }
    }
    gRaceSetup->mListedCpuCount = listedCount;
}

BOOL SetNextEntryFromCourseGhost(s32 courseId, s32 entryIndex) {
    u8 lapNumber;
    BOOL result;
    GhostRecord *ghostRecord;

    result = FALSE;
    if (gRaceSetup->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return TRUE;
    }
    ghostRecord = gBackupBuffers->mCourseGhostRecord;
    if (ghostRecord->mHead.mFilled == 1) {
        SetNextRaceEntry(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_COURSE;
        MI_CpuCopy8(ghostRecord->mKeyRecordingBuffer, gInputSlots[entryIndex].mKeyRecording.mBuffer,
                    sizeof(KeyRecordingBuffer));
        result = TRUE;
        GetGhostFinishTimeByIndex(0, &gRaceSetup->mGhostTime);
        for (lapNumber = 1; lapNumber <= 5; lapNumber++) {
            GetGhostLapTimeByIndex(0, lapNumber, &gRaceSetup->mGhostLapTimes[lapNumber - 1]);
        }
    }
    return result;
}

BOOL SetNextEntryFromFirstSlotGhost(s32 courseId, s32 entryIndex) {
    SlotGhostRecord *ghostRecord;
    s32 filled;
    u8 lapNumber;

    if (gRaceSetup->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return 1;
    }
    ghostRecord = gBackupBuffers->mSlotGhostRecords[0];
    filled = ghostRecord->mHead.mFilled == 1 ? 1 : 0;
    if (filled != 0) {
        SetNextRaceEntry(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_FIRST_SLOT;
        MI_CpuCopy8(ghostRecord->mKeyRecordingBuffer, gInputSlots[entryIndex].mKeyRecording.mBuffer,
                    sizeof(KeyRecordingBuffer));
        GetGhostFinishTimeByIndex(1, &gRaceSetup->mGhostTime);
        for (lapNumber = 1; lapNumber <= 5; lapNumber++) {
            GetGhostLapTimeByIndex(1, lapNumber, &gRaceSetup->mGhostLapTimes[lapNumber - 1]);
        }
    } else {
        SetNextRaceEntry(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    }
    return filled;
}

BOOL SetNextEntryFromSecondSlotGhost(s32 courseId, s32 entryIndex) {
    SlotGhostRecord *ghostRecord;
    u8 lapNumber;

    if (gRaceSetup->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return TRUE;
    }
    ghostRecord = gBackupBuffers->mSlotGhostRecords[1];
    if (ghostRecord != NULL && ghostRecord->mHead.mFilled == 1) {
        SetNextRaceEntry(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_SECOND_SLOT;
        MI_CpuCopy8(ghostRecord->mKeyRecordingBuffer, gInputSlots[entryIndex].mKeyRecording.mBuffer,
                    sizeof(KeyRecordingBuffer));
        GetGhostFinishTime(&ghostRecord->mHead, &gRaceSetup->mGhostTime);
        for (lapNumber = 1; lapNumber <= 5; lapNumber++) {
            GetGhostLapTime(&ghostRecord->mHead, lapNumber, &gRaceSetup->mGhostLapTimes[lapNumber - 1]);
        }
        return TRUE;
    }
    SetNextRaceEntry(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    return FALSE;
}

void SetCurrentRaceFromNext(void) {
    s16 entryIndex;
    GhostRecord *ghostRecord;
    ConnectionWork *connectionWork;
    u16 value;
    u16 entryCount;
    u8 searchIndex;
    BOOL connectionActive;

    entryCount = 0;
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_BATTLE:
        case MODE_VS:
            entryCount = 8;
            break;
        case MODE_WIFI:
            entryCount = 4;
            break;
        case MODE_TIME_ATTACK:
            value = 1;
            ghostRecord = gBackupBuffers->mCourseGhostRecord;
            if (ghostRecord->mHead.mFilled == 1) {
                gRaceSetup->mFirstGhostRecordFilled = 1;
                gRaceSetup->mFirstGhostRecordMinute = ghostRecord->mHead.mMinute;
                gRaceSetup->mFirstGhostRecordSecond = ghostRecord->mHead.mSecond;
                gRaceSetup->mFirstGhostRecordMillisecond = ghostRecord->mHead.mMillisecond;
            } else {
                gRaceSetup->mFirstGhostRecordFilled = 0;
                gRaceSetup->mFirstGhostRecordMinute = 0;
                gRaceSetup->mFirstGhostRecordSecond = 0;
                gRaceSetup->mFirstGhostRecordMillisecond = 0;
            }
            switch (gRaceSetup->mNextHeader.mGhostRecordIndex) {
                case GHOST_RECORD_INDEX_COURSE:
                    if (SetNextEntryFromCourseGhost(gRaceSetup->mNextHeader.mCourseId, 1) != 0) {
                        value++;
                    }
                    break;
                case GHOST_RECORD_INDEX_FIRST_SLOT:
                    if (SetNextEntryFromFirstSlotGhost(gRaceSetup->mNextHeader.mCourseId, 1) != 0) {
                        value++;
                    }
                    break;
                case GHOST_RECORD_INDEX_SECOND_SLOT:
                    if (SetNextEntryFromSecondSlotGhost(gRaceSetup->mNextHeader.mCourseId, 1) != FALSE) {
                        value++;
                    }
                    break;
                case GHOST_RECORD_INDEX_NONE:
                    break;
            }
            entryCount = value;
            break;
        case MODE_MISSION_RUN:
            entryCount = 2;
            break;
    }
    switch (gRaceSetup->mNextHeader.mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_AWARD:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            break;
        case RACE_KIND_STAFF_ROLL:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            entryCount = 8;
            break;
        case RACE_KIND_NORMAL:
        case RACE_KIND_REPLAY:
        case RACE_KIND_START_GP:
        case RACE_KIND_START_BATTLE:
            entryIndex = 0;
            for (searchIndex = 0; searchIndex < 8; searchIndex++) {
                if (gRaceSetup->mNextEntries[searchIndex].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    entryIndex = searchIndex;
                    break;
                }
            }
            connectionWork = gConnectionWork;
            connectionActive = FALSE;
            if ((connectionWork == NULL ? CONNECTION_MODE_NONE : connectionWork->mConnectionMode) !=
                    CONNECTION_MODE_NONE &&
                connectionWork->mState != CONNECTION_STATE_ENDED) {
                connectionActive = TRUE;
            }
            if (connectionActive != FALSE) {
                entryIndex =
                    connectionWork
                        ->mParticipantPosByIndex[(u16) (connectionWork->mConnectionMode == CONNECTION_MODE_CHILD
                                                            ? connectionWork->mOwnIndex
                                                            : 0)]
                        .mEntryIndex;
            }
            gRaceSetup->mNextHeader.mEntryIndex = entryIndex;
            gRaceSetup->mNextHeader.mFollowedKartIndex = entryIndex;
            break;
    }
    gRaceSetup->mCurrent = gRaceSetup->mNext;
    RefreshRaceSetupKartCounts(entryCount);
    RefreshListedCpuEntryIndices();
    for (value = 0; value < 8; value++) {
        SetCurrentEntryPlayer(value);
    }
}

void SetNextRaceByMode(void) {
    u8 entryIndex;
    u32 tableIndex;
    u8 cupIndex;
    u8 courseIndexInCup;
    RaceSetupHeader *nextHeader;
    s32 cupCourseId;
    u8 rankIndex;
    s32 kartIndex;

    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            if (gRaceSetup->mNextHeader.mCourseId == COURSE_ID_AWARD) {
                gRaceSetup->mNextHeader.mCourseId = COURSE_ID_AWARD;
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_AWARD;
                for (entryIndex = 3; entryIndex < 8; entryIndex++) {
                    SetNextRaceEntry(entryIndex, entryIndex, entryIndex * 3, PLAYER_KIND_NONE, -1, 3);
                }
                gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
            } else if ((u32) (gRaceSetup->mNextHeader.mCourseId - 0x35) <= 1) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
                gRaceSetup->mNextHeader.mEngineIndex = ENGINE_CLASS_MEDIUM;
                for (rankIndex = 0; rankIndex < 8; rankIndex++) {
                    s8 rankKartIndex;
                    for (rankKartIndex = 0; rankKartIndex < gRaceSetup->mKartCount; rankKartIndex++) {
                        if (rankIndex + 1 == GetKartCupRank(rankKartIndex)) {
                            break;
                        }
                    }
                    kartIndex = rankIndex * 3;
                    if (gRaceSetup->mNextHeader.mCourseId != COURSE_ID_STAFFROLLTRUE) {
                        SetNextRaceEntryWrapper(3, -1, 1, kartIndex, rankIndex, rankIndex);
                    }
                }
                gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
            } else {
                for (tableIndex = 0; tableIndex < 32; tableIndex++) {
                    cupIndex = (s32) tableIndex / 4;
                    courseIndexInCup = (s32) tableIndex % 4;
                    cupCourseId = gCupCourseIdTable[cupIndex][courseIndexInCup];
                    if (gRaceSetup->mNextHeader.mCourseId == cupCourseId) {
                        break;
                    }
                    if (tableIndex == 31) {
                        cupIndex = 0;
                        courseIndexInCup = 3;
                    }
                }
                gRaceSetup->mNextHeader.mCourseNumber = (u8) (courseIndexInCup + 1);
                nextHeader = &gRaceSetup->mNextHeader;
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
                gRaceSetup->mNextHeader.mCupIndex = cupIndex;
            }
            break;
        case MODE_BATTLE:
            if (gStartupWork->mMultiSimple != 0) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            } else {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_BATTLE;
            }
            break;
        case MODE_MISSION_RUN:
            break;
        default:
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
    }
}

void ResetTimeAttackNextEntries(void) {
    u16 entryIndex;

    if (gRaceSetup->mNextHeader.mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    for (entryIndex = 1; entryIndex < 8; entryIndex++) {
        gRaceSetup->mNextEntries[entryIndex].mCharacterIndex = entryIndex;
        gRaceSetup->mNextEntries[entryIndex].mKartIndex = entryIndex;
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mKind = PLAYER_KIND_NONE;
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mIndex = entryIndex;
    }
}

// In battle there is one lap.
u16 GetLapCount(void) {
    RaceSetup *raceSetup;
    u16 lapCount;

    lapCount = 1;
    raceSetup = gRaceSetup;
    if (raceSetup->mMode != MODE_BATTLE) {
        if (raceSetup->mLapCount <= 0) {
            lapCount = gCourseMap->mSettings->mLapCountOrBattleSeconds;
        } else {
            lapCount = raceSetup->mLapCount;
        }
    }
    return lapCount;
}

void RequestMPWaitRaceArchivesForNextRace(void) {
    u32 courseId;
    u32 mode;
    u32 unusedValue;
    courseId = gRaceSetup->mNextHeader.mCourseId;
    mode = gRaceSetup->mNextHeader.mMode;
    RequestMPWaitRaceArchives((void *) courseId, (void *) mode);
}

static inline void ReadPadKeysAndUpdateTouchMic(void) {
    if ((SYSTEM_WORK->mButtonXY & SYSTEM_BUTTON_XY_CLOSED) >> 15) {
        gInputState->mPadKeys = 0;
    } else {
        gInputState->mPadKeys = ((reg_PAD_KEYINPUT | SYSTEM_WORK->mButtonXY) ^ 0x2fff) & 0x2fff;
    }
    UpdateTouchMicInput();
}

static inline void ResetInputSlotsAndRepeat(void) {
    s32 slotIndex;
    s32 resetIndex;
    InputSlot *inputSlot;
    InputSlot *slot;

    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        inputSlot = GetInputSlot(slotIndex);
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot->mSourceKind = INPUT_SOURCE_NONE;
        inputSlot->mRequestedBits = 0;
        inputSlot->mIsBlocked = 0;
        inputSlot->mBitMask = INPUT_SLOT_BIT_MASK_DEFAULT;
        ResetKeyRecording(&inputSlot->mKeyRecording);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    gInputSlots[INPUT_SLOT_PAD_OR_PARTICIPANT].mSourceKind = INPUT_SOURCE_PAD_OR_PARTICIPANT;
    gInputSlots[INPUT_SLOT_PAD_AND_TOUCH].mSourceKind = INPUT_SOURCE_PAD_AND_TOUCH;
    gInputState->mParticipantPosition = 0;
    gInputState->mUnk_0c = FALSE;
    slot = gInputSlots;
    for (resetIndex = 0; resetIndex < 10; resetIndex++) {
        ResetInputSlot(slot);
        slot->mRequestedBits = 0;
        SetInputSlotRepeat(slot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        slot++;
    }
}

static inline RaceSetup *GetRaceSetup(void) {
    return gRaceSetup;
}

void ReplaceEntryWithCpu(u32 entryIndex) {
    s32 listedCpuSlot;
    RaceSetup *raceSetup;

    listedCpuSlot = 3;
    if (gRaceSetup->mListedCpuEntryIndices[0] == -1) {
        listedCpuSlot = 0;
    } else if (gRaceSetup->mListedCpuEntryIndices[1] == -1) {
        listedCpuSlot = 1;
    }
    SetNextRaceEntry(entryIndex, gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex,
                     gRaceSetup->mCurrentEntries[entryIndex].mKartIndex, PLAYER_KIND_CPU,
                     gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex, listedCpuSlot);
    raceSetup = gRaceSetup;
    raceSetup->mCurrentEntries[entryIndex] = raceSetup->mNextEntries[entryIndex];
    if (listedCpuSlot < 2) {
        raceSetup->mListedCpuEntryIndices[listedCpuSlot] = entryIndex;
    }
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mNumber = gRaceSetup->mNextCpuNumber;
    gRaceSetup->mNextCpuNumber = gRaceSetup->mNextCpuNumber + 1;
}

void SetNextRaceFromMissionRow(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn) {
    u8 entryIndex;

    gRaceSetup->mNextHeader.mMissionFileRow = *missionFileRow;
    gRaceSetup->mNextHeader.mMissionTableRow = tableRow;
    gRaceSetup->mNextHeader.mMissionTableColumn = tableColumn;
    gRaceSetup->mNextHeader.mMode = MODE_MISSION_RUN;
    gRaceSetup->mNextHeader.mCourseId = missionFileRow->mCourseId;
    gRaceSetup->mNextHeader.mMirrorMode = (missionFileRow->mFlags & MISSION_FILE_ROW_FLAG_MIRROR) != 0 ? 1 : 0;
    gRaceSetup->mNextHeader.mUseTeams = 0;
    gRaceSetup->mNextHeader.mRuleKind = RULE_KIND_FREE;
    gRaceSetup->mNextHeader.mCourseListMode = COURSE_LIST_MODE_SINGLE;
    gRaceSetup->mNextHeader.mBattleKind = 0;
    gRaceSetup->mCourseCount = 0;
    gRaceSetup->mNextHeader.mEngineIndex = missionFileRow->mEngineIndex;
    SetNextRaceEntry(0, missionFileRow->mCharacterIndex0, missionFileRow->mKartIndex0, PLAYER_KIND_HUMAN, -1, 3);
    if (missionFileRow->mCharacterIndex1 != MISSION_FILE_ROW_NO_SECOND_KART &&
        missionFileRow->mKartIndex1 != MISSION_FILE_ROW_NO_SECOND_KART) {
        SetNextRaceEntry(1, missionFileRow->mCharacterIndex1, missionFileRow->mKartIndex1, PLAYER_KIND_CPU, -1, 3);
        gRaceSetup->mNextHeader.mCpuDifficulty = CPU_DIFFICULTY_NORMAL;
    } else {
        SetNextRaceEntry(1, -1, -1, PLAYER_KIND_NONE, -1, 3);
        gRaceSetup->mNextHeader.mCpuDifficulty = 0;
    }
    for (entryIndex = 2; entryIndex < 8; entryIndex++) {
        SetNextRaceEntry(entryIndex, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
}

void ReadCourseGhostRecordAndWait(u32 courseId) {
    gBackupBuffers->mSlotGhostRecords[0]->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[1]->mHead.mFilled = 0;
    gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    }
}

void ReadCourseAndSlotGhostRecords(u32 courseId, u8 slotIndex) {
    gBackupBuffers->mSlotGhostRecords[0]->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[1]->mHead.mFilled = 0;
    gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[0]->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[1]->mHead.mFilled = 0;
    gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    }
    ReadSlotGhostRecord(slotIndex);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        gBackupBuffers->mSlotGhostRecords[0]->mHead.mFilled = 0;
    }
}

// Reads the course ghost record, then loads its ghost file; a failed load leaves a NULL record that is then
// zero-filled.
void ReadCourseGhostRecordAndLoadFile(u32 courseId) {
    SlotGhostRecord *ghostRecord;
    char path[0x80];

    ghostRecord = NULL;
    gBackupBuffers->mSlotGhostRecords[0]->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[1]->mHead.mFilled = 0;
    gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[0]->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[1]->mHead.mFilled = 0;
    gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    }
    if (TryFormatGhostPath(courseId, path, 0x80) != FALSE) {
        ghostRecord = LoadGhostRecordFile(path);
    }
    if (ghostRecord != NULL) {
        return;
    }
    MI_CpuFill8(ghostRecord, 0, sizeof(SlotGhostRecord));
    ghostRecord->mHead.mFilled = 0;
}

void SelectGhostReadCourseRecordAndWait(u32 courseId) {
    gBackupBuffers->mSlotGhostRecords[0]->mHead.mFilled = 0;
    gBackupBuffers->mSlotGhostRecords[1]->mHead.mFilled = 0;
    gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        gBackupBuffers->mCourseGhostRecord->mHead.mFilled = 0;
    }
}

void LoadSndBanksForCharacters(u32 useCurrentEntries) {
    u16 entryIndex;
    RaceSetup *raceSetup;
    u32 bankMask;

    bankMask = 0;
    entryIndex = 0;
    for (; entryIndex < (u32) (raceSetup = GetRaceSetup())->mKartCount; entryIndex++) {
        if (useCurrentEntries != 0) {
            bankMask |= gCharacterSndBankMasks[raceSetup->mCurrentEntries[entryIndex].mCharacterIndex];
        } else {
            bankMask |= gCharacterSndBankMasks[raceSetup->mNextEntries[entryIndex].mCharacterIndex];
        }
    }
    LoadSndBanksAndWaveArcsIfChanged(bankMask);
}

void InitInputSlotsAndTouchMic(void *heap) {
    s32 slotIndex;

    InitTouchPanelAndSetCalibration();
    InitTouchMicInput(heap);
    for (slotIndex = 0; slotIndex <= 1; slotIndex++) {
        InitKeyRecordingBuffer(&gInputSlots[slotIndex].mKeyRecording, heap);
    }
    for (; slotIndex < 10; slotIndex++) {
        ClearKeyRecordingBufferPointer(&gInputSlots[slotIndex].mKeyRecording);
    }
    gInputState = HeapAlloc(heap, sizeof(*gInputState));
    ResetInputSlotsAndRepeat();
    ReadPadKeysAndUpdateTouchMic();
    ReadPadKeysAndUpdateTouchMic();
}

void ResetInputSlots(void) {
    ResetInputSlotsAndRepeat();
}

void StartInputSlots(void) {
    s32 resetIndex;
    s32 clearIndex;
    InputSlot *inputSlot;
    InputSlot *slot;

    inputSlot = gInputSlots;
    for (resetIndex = 0; resetIndex < 10; resetIndex++) {
        ResetInputSlot(inputSlot);
        inputSlot->mRequestedBits = 0;
        SetInputSlotRepeat(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot++;
    }
    StartTouchAutoSampling();
    UpdateInputSlots();
    slot = gInputSlots;
    for (clearIndex = 0; clearIndex < 10; clearIndex++) {
        slot->mHoldLong = 0;
        slot->mLongHoldEnabled = 0;
        SetInputSlotRepeat(slot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        slot++;
    }
    gInputState->mPadKeys = 0;
    gInputState->mFlags = 0;
}

void StopTouchAutoSamplingWrapper(void) {
    StopTouchAutoSampling();
}

void ClearInputSlots(void) {
    s32 slotIndex;
    InputSlot *inputSlot;

    inputSlot = gInputSlots;
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        ClearInputSlotBitsAndRepeat(inputSlot);
        inputSlot++;
    }
}

void SetNoKeysAndUpdateInputSlots(void) {
    gInputState->mFlags |= INPUT_STATE_NO_KEYS;
    UpdateInputSlots();
}

void ReleaseTouchMicInputWrapper(void) {
    ReleaseTouchMicInput();
}

void SetLeftRightKeysSwapped(u32 mirrorMode) {
    if (mirrorMode != 0) {
        gInputState->mFlags |= INPUT_STATE_FLAG_LEFT_RIGHT_SWAPPED;
    } else {
        gInputState->mFlags &= ~INPUT_STATE_FLAG_LEFT_RIGHT_SWAPPED;
    }
}

void UpdatePadKeysAndTouchMic(void) {
    ReadPadKeysAndUpdateTouchMic();
}

u32 GetPadKeys(void) {
    return (gInputState->mPadKeys);
}

static inline s32 InputSlotsIsConnectionActive(ConnectionWork *connectionWork) {
    BOOL result = FALSE;
    if ((connectionWork == NULL ? CONNECTION_MODE_NONE : connectionWork->mConnectionMode) != CONNECTION_MODE_NONE &&
        connectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

void UpdateInputSlots(void) {
    u8 slotIndex;
    u16 packedTouchPoint;
    u16 padOrParticipantKeys;
    u16 padOrParticipantTouchPoint;
    u16 padKeys;
    s32 micOverThreshold;
    u16 slotKeys;
    u16 keys;
    s32 touchPoint;
    InputSlot *inputSlot;
    s32 micValue;
    BOOL skipUpdate;
    s32 canReadKeys;
    s32 isBlocked;
    s32 sourceKind;
    u16 flags;

    padKeys = gInputState->mPadKeys;
    packedTouchPoint = GetPackedTouchPoint();
    padOrParticipantKeys = padKeys;
    padOrParticipantTouchPoint = packedTouchPoint;
    micOverThreshold = gTouchMicInput->mMicOverThreshold;
    if (InputSlotsIsConnectionActive(gConnectionWork) != 0) {
        padOrParticipantKeys = GetParticipantPadKeys(GetParticipantIndex(gInputState->mParticipantPosition));
        padOrParticipantTouchPoint =
            gConnectionWork->mDataSharing.mReceivedRecords[GetParticipantIndex(gInputState->mParticipantPosition)]
                .mTouchPoint;
        GetParticipantIndex(gInputState->mParticipantPosition);
    }
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        slotKeys = 0;
        touchPoint = 0xffff;
        micValue = slotKeys;
        isBlocked = (gInputState->mFlags & INPUT_STATE_OPEN_DURING_RACE) ? 1 : 0;
        skipUpdate = FALSE;
        canReadKeys = (GetCurrentSceneNumber() != 2 || (gInputState->mFlags & INPUT_STATE_READ_RACE_KEYS)) ? 1 : 0;
        inputSlot = &gInputSlots[slotIndex];
        flags = gInputState->mFlags;
        if (!(flags & INPUT_STATE_NO_KEYS)) {
            sourceKind = inputSlot->mSourceKind;
            if (isBlocked == 0) {
                isBlocked = inputSlot->mIsBlocked;
            }
            switch (sourceKind) {
                case INPUT_SOURCE_KEY_RECORDING_PLAYBACK:
                    if (isBlocked == 0) {
                        if (canReadKeys != 0) {
                            slotKeys = ReadKeysFromKeyRecording(&inputSlot->mKeyRecording);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    touchPoint = 0xffff;
                    micValue = 0;
                    break;
                case INPUT_SOURCE_PAD_RECORDED:
                    if (isBlocked == 0) {
                        if (canReadKeys != 0) {
                            slotKeys = padKeys;
                            if (flags & 4) {
                                slotKeys = padKeys & 0xffcf;
                                if (padKeys & PAD_KEY_LEFT) {
                                    slotKeys |= PAD_KEY_RIGHT;
                                }
                                if (padKeys & PAD_KEY_RIGHT) {
                                    slotKeys |= PAD_KEY_LEFT;
                                }
                            }
                            AppendKeysToKeyRecording(&inputSlot->mKeyRecording, slotKeys);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    touchPoint = packedTouchPoint;
                    micValue = micOverThreshold;
                    break;
                case INPUT_SOURCE_REQUESTED_BITS:
                case INPUT_SOURCE_WIFI_REQUESTED_BITS:
                    if (isBlocked != 0) {
                        skipUpdate = TRUE;
                    } else {
                        micValue = 0;
                        slotKeys = inputSlot->mRequestedBits;
                        touchPoint = 0xffff;
                        inputSlot->mRequestedBits = micValue;
                    }
                    break;
                case INPUT_SOURCE_PAD_OR_PARTICIPANT:
                    slotKeys = padOrParticipantKeys;
                    touchPoint = padOrParticipantTouchPoint;
                    micValue = 0;
                    break;
                case INPUT_SOURCE_PARTICIPANT:
                    if (isBlocked == 0) {
                        if (canReadKeys != 0) {
                            slotKeys = GetParticipantPadKeys(GetParticipantIndex(slotIndex));
                            if (gInputState->mFlags & INPUT_STATE_FLAG_LEFT_RIGHT_SWAPPED) {
                                keys = slotKeys & 0xffcf;
                                if (slotKeys & PAD_KEY_LEFT) {
                                    keys |= PAD_KEY_RIGHT;
                                }
                                if (slotKeys & PAD_KEY_RIGHT) {
                                    keys |= PAD_KEY_LEFT;
                                }
                                slotKeys = keys;
                            }
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    touchPoint =
                        gConnectionWork->mDataSharing.mReceivedRecords[GetParticipantIndex(slotIndex)].mTouchPoint;
                    micValue = gConnectionWork->mDataSharing.mReceivedRecords[GetParticipantIndex(slotIndex)]
                                   .mMicOverThreshold;
                    break;
                case INPUT_SOURCE_PAD_AND_TOUCH:
                    slotKeys = padKeys;
                    touchPoint = packedTouchPoint;
                    micValue = micOverThreshold;
                    break;
                case INPUT_SOURCE_NONE:
                    slotKeys = 0;
                    touchPoint = 0xffff;
                    micValue = slotKeys;
                    break;
            }
        }
        keys = slotKeys & inputSlot->mBitMask;
        if (skipUpdate == FALSE) {
            UpdateInputSlot(keys, &inputSlot->mHead);
        }
        UpdateInputSlotPair(&inputSlot->mPair, touchPoint, micValue);
    }
}

// Takes effect only for slots whose source kind is INPUT_SOURCE_REQUESTED_BITS or INPUT_SOURCE_WIFI_REQUESTED_BITS.
void RequestBits(s32 slotIndex, u32 bits) {
    if (gInputSlots[slotIndex].mSourceKind == INPUT_SOURCE_REQUESTED_BITS ||
        gInputSlots[slotIndex].mSourceKind == INPUT_SOURCE_WIFI_REQUESTED_BITS) {
        gInputSlots[slotIndex].mRequestedBits |= bits;
    }
}

void SetInputOpenDuringRace(u32 openDuringRace) {
    if (openDuringRace != 0) {
        gInputState->mFlags |= INPUT_STATE_OPEN_DURING_RACE;
        return;
    }
    gInputState->mFlags &= ~INPUT_STATE_OPEN_DURING_RACE;
}

u32 GetVolatileHalfwordIndex39(void) {
    return gInputSlots[INPUT_SLOT_PAD_AND_TOUCH].mHoldLong;
}
