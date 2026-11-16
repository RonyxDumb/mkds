#include "Main/Race/race_setup_input.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/results_gp.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Sound/scene_sound_set.h"
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
#include "Main/Sound/sound_seq.h"
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

const u32 g_InternalCourseIdOrderedTable[8][4] = {{0x14, 0x16, 0x1f, 0x12}, {0x1b, 0x1c, 0x21, 0x18}, {0x1e, 0x11, 0x19, 0x13},
                                     {0x22, 0x1a, 0x20, 0x1d}, {0xa, 0xb, 0xd, 0xe},     {0x23, 0x10, 0xc, 9},
                                     {0xf, 0x24, 0x25, 0x26},  {0x27, 0x17, 0x28, 1}};
const u32 gCupIndicesTwoCups[2] = {0, 4};
const u32 gThreeCourseIds[3] = {0x2c, 0x2f, 0x2b};
const u32 gSixCourseIds[6] = {0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f};
const u16 g_CharacterMaskTable[13] = {0x10, 1, 2, 4, 0x20, 0x40, 0x80, 8, 0x400, 0x100, 0x200, 0x800, 0x1000};
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

BOOL HasSomeSecretFlag(s32 cupIndex) {
    u32 engineOrMirrorIndex;
    engineOrMirrorIndex = (u8) g_GlobalCO->mNextHeader.mEngineIndex;
    if (g_GlobalCO->mNextHeader.mMirrorMode != 0) {
        engineOrMirrorIndex = 3;
    }
    switch (cupIndex) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (CheckSecretFlag(engineOrMirrorIndex)) {
                return TRUE;
            }
            break;
        case 3:
            if (CheckSecretFlag(engineOrMirrorIndex + 4)) {
                return TRUE;
            }
            break;
        case 6:
            if (CheckSecretFlag(engineOrMirrorIndex + 8)) {
                return TRUE;
            }
            break;
        case 7:
            if (CheckSecretFlag(engineOrMirrorIndex + 12)) {
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
    switch (g_GlobalCO->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
        case MODE_WIFI:
            noCpuNumbers = TRUE;
            break;
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        if (noCpuNumbers == FALSE && g_GlobalCO->mNextEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
            g_GlobalCO->mNextEntries[entryIndex].mPlayer.mNumber = nextCpuNumber;
            nextCpuNumber = nextCpuNumber + 1;
        } else {
            g_GlobalCO->mNextEntries[entryIndex].mPlayer.mNumber = -1;
        }
    }
    g_GlobalCO->mNextCpuNumber = nextCpuNumber;
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
    s32 flag;
    u32 cupCount;
    const u32 *cupTable;
    u32 listIndex;
    u32 courseCount;
    flag = 0;
    CreateGlobalLU();
    g_GlobalCO->mCourseListIndex = 0;
    g_GlobalCO->mNextHeader.mCourseNumber = 1;
    if (isVersus != 0) {
        g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else if (g_GlobalP->mMultiSimple) {
        g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_START_BATTLE;
    }
    for (listIndex = 0; listIndex < RACE_SETUP_COURSE_LIST_LENGTH; listIndex++) {
        g_GlobalCO->mCourseList[listIndex] = 0;
    }
    switch (g_GlobalP->mConnectionKind) {
        case CONNECTION_KIND_MEMBER_SELECT:
        case CONNECTION_KIND_WL_MENU:
            flag = (g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0;
            break;
    }
    switch (g_GlobalCO->mNextHeader.mCourseListMode) {
        case COURSE_LIST_MODE_IN_ORDER:
            if (isVersus != 0) {
                u8 cupSlot;
                u8 courseSlot;
                u32 entryCount;
                s32 currentCourseId;
                s32 enabledCount;
                cupCount = flag != 0 ? 2 : 8;
                cupTable = flag != 0 ? gCupIndicesTwoCups : gCupIndicesEightCups;
                currentCourseId = g_GlobalCO->mNextHeader.mCourseId;
                entryCount = cupCount * 4;
                for (flag = 0; flag < entryCount; flag++) {
                    cupSlot = flag / 4;
                    courseSlot = flag % 4;
                    if (currentCourseId == g_InternalCourseIdOrderedTable[cupTable[cupSlot]][courseSlot]) {
                        break;
                    }
                }
                enabledCount = 0;
                for (flag = 0; flag < entryCount; flag++) {
                    if (HasSomeSecretFlag(cupTable[cupSlot]) != FALSE) {
                        g_GlobalCO->mCourseList[enabledCount] = g_InternalCourseIdOrderedTable[cupTable[cupSlot]][courseSlot];
                        enabledCount = (u8) (enabledCount + 1);
                    }
                    courseSlot = courseSlot + 1;
                    if (courseSlot >= 4) {
                        courseSlot = 0;
                        cupSlot = cupSlot + 1;
                        if (cupSlot >= cupCount) {
                            cupSlot = 0;
                        }
                    }
                }
                return;
            } else {
                s32 currentCourseId;
                u32 startIndex;
                courseCount = flag != 0 ? 3 : 6;
                startIndex = 0;
                cupTable = flag != 0 ? gThreeCourseIds : gSixCourseIds;
                currentCourseId = g_GlobalCO->mNextHeader.mCourseId;
                for (listIndex = 0; listIndex < courseCount; listIndex++) {
                    startIndex = listIndex;
                    if (currentCourseId == cupTable[listIndex]) {
                        break;
                    }
                }
                for (listIndex = 0; listIndex < courseCount; listIndex++) {
                    g_GlobalCO->mCourseList[listIndex] = cupTable[startIndex];
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
                cupCount = flag != 0 ? 2 : 8;
                cupTable = flag != 0 ? gCupIndicesTwoCups : gCupIndicesEightCups;
                entryCount = cupCount * 4;
                enabledCount = 0;
                for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
                    cupSlot = entryIndex / 4;
                    courseSlot = entryIndex % 4;
                    if (HasSomeSecretFlag(cupTable[cupSlot]) != FALSE) {
                        g_GlobalCO->mCourseList[enabledCount] = g_InternalCourseIdOrderedTable[cupTable[cupSlot]][courseSlot];
                        enabledCount = (u8) (enabledCount + 1);
                    }
                }
                swapCount = enabledCount * 2;
                for (passIndex = 0; passIndex < swapCount; passIndex++) {
                    swapIndex = NextRandomBelowU16(random, (vu16) (enabledCount - 1));
                    shuffleIndex = passIndex % enabledCount;
                    swapTemp = g_GlobalCO->mCourseList[shuffleIndex];
                    if (swapIndex >= shuffleIndex) {
                        swapIndex = swapIndex + 1;
                    }
                    g_GlobalCO->mCourseList[shuffleIndex] = g_GlobalCO->mCourseList[swapIndex];
                    g_GlobalCO->mCourseList[swapIndex] = swapTemp;
                }
            } else {
                s32 courseIndex;
                RandomState64 *random;
                random = GetRandomState();
                courseCount = flag != 0 ? 3 : 6;
                cupTable = flag != 0 ? gThreeCourseIds : gSixCourseIds;
                for (courseIndex = 0; courseIndex < courseCount; courseIndex++) {
                    g_GlobalCO->mCourseList[courseIndex] = cupTable[courseIndex];
                }
                courseIndex = 0;
                if (courseIndex < courseCount) {
                    cupCount = (u16) (courseCount - 1);
                    for (; courseIndex < courseCount; courseIndex++) {
                        u8 swapIndex;
                        u8 swapTemp;
                        swapIndex = BuildCourseListNextRandomBelowU16(random, cupCount);
                        swapTemp = g_GlobalCO->mCourseList[courseIndex];
                        if (swapIndex >= courseIndex) {
                            swapIndex = swapIndex + 1;
                        }
                        g_GlobalCO->mCourseList[courseIndex] = g_GlobalCO->mCourseList[swapIndex];
                        g_GlobalCO->mCourseList[swapIndex] = swapTemp;
                    }
                }
            }
            g_GlobalCO->mNextHeader.mCourseId = g_GlobalCO->mCourseList[0];
            break;
    }
}

void AssignCpuNumbersAndSetupFirstCourse(void) {
    u8 entryIndex;
    u8 humanIndex;
    AssignCpuNumbers();
    switch (g_GlobalCO->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            CreateGlobalLU();
            g_GlobalCO->mNextHeader.mCourseNumber = 1;
            g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            g_GlobalCO->mNextHeader.mCourseId =
                g_InternalCourseIdOrderedTable[g_GlobalCO->mNextHeader.mCupIndex][g_GlobalCO->mNextHeader.mCourseNumber - 1];
            break;
        case MODE_VS:
            BuildCourseList(1);
            break;
        case MODE_BATTLE:
            BuildCourseList(0);
            break;
        case MODE_WIFI:
            humanIndex = 0xff;
            CreateGlobalLU();
            g_GlobalCO->mNextHeader.mCourseNumber = 1;
            g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                if (g_GlobalCO->mNextEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    humanIndex = entryIndex;
                    break;
                }
            }
            g_GlobalCO->mNextHeader.mFollowedKartIndex = humanIndex;
            break;
        case MODE_MISSION_RUN:
            CreateGlobalLU();
            if (g_GlobalCO->mNextHeader.mMissionTableColumn == 9) {
                g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_START_GP;
            } else {
                g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            }
            g_GlobalCO->mNextHeader.mCourseNumber = 1;
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
    entryIndex = g_GlobalCO->mEntryIndex;
    g_GlobalB488->mCupRankIndex = GetSomeRacerPosition(entryIndex) - 1;
    g_GlobalB488->mGrade = ComputeGrandPrixRecordValue();
    g_GlobalB488->mCharacterIndex = g_GlobalCO->mCurrentEntries[(u8) entryIndex].mCharacterIndex;
    g_GlobalB488->mCupIndex = g_GlobalCO->mCupIndex;
    g_GlobalB488->mEngineIndex = g_GlobalCO->mEngineIndex;
    g_GlobalB488->mMirrorMode = g_GlobalCO->mMirrorMode;
    lowByte = Int32ToInt8((u8) entryIndex);
    courseIndexInCup = GetSomeLUMaxIndex();
    courseResult = &g_GlobalLU->mKartResults[courseIndexInCup][Int32ToInt8(lowByte)];
    g_GlobalB488->mTotalPoints = courseResult->mTotalPoints;
    g_GlobalB488->mKartIndex = g_GlobalCO->mCurrentEntries[(u8) entryIndex].mKartIndex;
    for (index = 0; index < 4; index++) {
        MinuteSecondMillisecondTime finishTime;
        GetKartCourseFinishTime(&finishTime, g_GlobalCO->mEntryIndex, index);
        g_GlobalB488->mCourseTimes[index] = finishTime;
    }
    if ((u32) GetSomeRacerPosition(g_GlobalCO->mEntryIndex) > 3) {
        return FALSE;
    }
    g_GlobalCO->mNextHeader.mCourseId = COURSE_ID_AWARD;
    g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_AWARD;
    for (index = 0; index < 3; index++) {
        for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
            if (GetSomeRacerPosition(kartIndex) == index + 1) {
                break;
            }
        }
        StructCO_ConfigureRacerDefault(index, GetCurrentEntry(kartIndex)->mCharacterIndex, GetCurrentEntry(kartIndex)->mKartIndex,
                         PLAYER_KIND_CPU, -1, 3);
    }
    for (; index < 8; index++) {
        StructCO_ConfigureRacerDefault(index, index, index * 3, PLAYER_KIND_NONE, -1, 3);
    }
    for (index = 0; index < 8; index++) {
        rankIndex = GetSomeRacerPosition(index) - 1;
        g_GlobalB488->mCupRankKartIndices[rankIndex] = g_GlobalCO->mCurrentEntries[index].mKartIndex;
        g_GlobalB488->mCupRankCharacterIndices[rankIndex] = g_GlobalCO->mCurrentEntries[index].mCharacterIndex;
    }
    g_GlobalCO->mNextHeader.mFollowedKartIndex = GetSomeRacerPosition(g_GlobalCO->mEntryIndex) - 1;
    return TRUE;
}

void SetupStaffRollRace(s32 useTrueStaffRoll) {
    u8 index;
    s8 searchIndex;
    s32 characterIndex;
    s32 kartIndex;
    if (useTrueStaffRoll != 0) {
        g_GlobalCO->mNextHeader.mCourseId = COURSE_ID_STAFFROLLTRUE;
    } else {
        g_GlobalCO->mNextHeader.mCourseId = COURSE_ID_STAFFROLL;
    }
    g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
    g_GlobalCO->mNextHeader.mEngineIndex = ENGINE_CLASS_MEDIUM;
    g_GlobalCO->mNextHeader.mFollowedKartIndex = 0;
    for (index = 0; index < 8; index++) {
        for (searchIndex = 0; searchIndex < g_GlobalCO->mKartCount; searchIndex++) {
            if (GetSomeRacerPosition(searchIndex) == index + 1) {
                break;
            }
        }
        if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
            if ((g_GlobalCO->mMode == MODE_MISSION_RUN ? g_GlobalCO->mMissionTableRow : -1) == 6 &&
                (g_GlobalCO->mMode == MODE_MISSION_RUN ? g_GlobalCO->mMissionTableColumn : -1) == 9) {
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
        } else if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
            if (GetStaffRollKindAfterGp() != 2) {
                characterIndex = index;
                kartIndex = index * 3;
            } else {
                characterIndex = g_GlobalB488->mCupRankCharacterIndices[index];
                kartIndex = g_GlobalB488->mCupRankKartIndices[index];
            }
        } else {
            characterIndex = index;
            kartIndex = index * 3;
        }
        StructCO_ConfigureRacerDefault(index, characterIndex, kartIndex, PLAYER_KIND_CPU, -1, 3);
    }
}

s32 AdvanceToNextCourse(void) {
    BOOL result;
    s32 entryIndex;
    s32 newSlot;
    s32 oldSlot;
    result = TRUE;
    g_GlobalCO->mNextHeader.mCourseNumber++;
    if (g_GlobalCO->mListedCpuCount > 1) {
        for (entryIndex = 0; entryIndex < g_GlobalCO->mKartCount; entryIndex++) {
            oldSlot = g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mListedCpuSlot;
            newSlot = 3;
            if (oldSlot != 0) {
                if (oldSlot == 1) {
                    newSlot = 0;
                }
            } else {
                newSlot = 1;
            }
            g_GlobalCO->mNextEntries[entryIndex].mPlayer.mListedCpuSlot = newSlot;
        }
    }
    switch (g_GlobalCO->mCourseListMode) {
        case COURSE_LIST_MODE_SINGLE:
            result = FALSE;
            break;
        case COURSE_LIST_MODE_IN_ORDER:
        case COURSE_LIST_MODE_SHUFFLED:
            g_GlobalCO->mCourseListIndex++;
            if (g_GlobalCO->mCourseList[g_GlobalCO->mCourseListIndex] == 0) {
                g_GlobalCO->mCourseListIndex = 0;
            }
            g_GlobalCO->mNextHeader.mCourseId = g_GlobalCO->mCourseList[g_GlobalCO->mCourseListIndex];
            break;
    }
    return result;
}

s32 AdvanceToNextCourseWrapper(void) {
    return AdvanceToNextCourse();
}

s32 AdvanceToNextBattleCourse(void) {
    if (g_GlobalP->mMultiSimple) {
        g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    } else {
        g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_START_BATTLE;
    }
    return AdvanceToNextCourse();
}

BOOL CopyCourseIdAndAdvanceCourseNumber(void) {
    g_GlobalB488->mUnk_5c[g_GlobalCO->mCourseNumber] = g_GlobalCO->mCourseId;
    g_GlobalCO->mNextHeader.mCourseNumber++;
    return g_GlobalCO->mNextHeader.mCourseNumber <= COURSES_PER_CUP;
}

static inline void SetNextRaceEntryWrapper(s32 listedCpuSlot, u32 teamIndex, s32 playerKind, u32 kartIndex,
                                           u32 characterIndex, s32 entryIndex) {
    StructCO_ConfigureRacerDefault(entryIndex, characterIndex, kartIndex, playerKind, teamIndex, listedCpuSlot);
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

void PopulateGlobalCO(void) {
    u16 index;
    MinuteSecondMillisecondTime *time;

    g_GlobalCO->mNextHeader.mCourseId = COURSE_ID_CROSS;
    g_GlobalCO->mNextHeader.mCupIndex = 0;
    g_GlobalCO->mNextHeader.mMode = MODE_GRAND_PRIX;
    g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    g_GlobalCO->mNextHeader.mEngineIndex = ENGINE_CLASS_SLOW;
    g_GlobalCO->mNextHeader.mCpuDifficulty = 0;
    g_GlobalCO->mNextHeader.mBattleKind = 0;
    g_GlobalCO->mNextHeader.mRuleKind = RULE_KIND_FREE;
    g_GlobalCO->mNextHeader.mCourseListMode = COURSE_LIST_MODE_SINGLE;
    g_GlobalCO->mNextHeader.mGhostRecordIndex = GHOST_RECORD_INDEX_COURSE;
    Mem_CpuFill8(&g_GlobalCO->mNextHeader.mMissionFileRow, 0, sizeof(g_GlobalCO->mNextHeader.mMissionFileRow));
    g_GlobalCO->mNextHeader.mMissionTableRow = -1;
    g_GlobalCO->mNextHeader.mMissionTableColumn = -1;
    g_GlobalCO->mNextHeader.mUnk_56[0] = 0;
    g_GlobalCO->mNextHeader.mMirrorMode = 0;
    g_GlobalCO->mNextHeader.mUseTeams = 0;
    g_GlobalCO->mNextHeader.mSeed = 0;
    g_GlobalCO->mNextHeader.mCourseNumber = 1;
    g_GlobalCO->mNextHeader.mEntryIndex = -1;
    g_GlobalCO->mNextHeader.mFollowedKartIndex = 0;
    g_GlobalCO->mNextHeader.mLapCount = -1;
    for (index = 0; index < 8; index++) {
        g_GlobalCO->mNextEntries[index].mCharacterIndex = index;
        g_GlobalCO->mNextEntries[index].mKartIndex = index * 3;
        g_GlobalCO->mNextEntries[index].mPlayer.mKind = index == 0 ? PLAYER_KIND_HUMAN : PLAYER_KIND_CPU;
        g_GlobalCO->mNextEntries[index].mPlayer.mTeamIndex = -1;
        g_GlobalCO->mNextEntries[index].mPlayer.mListedCpuSlot = KART_ENTRY_LISTED_CPU_SLOT_NONE;
        g_GlobalCO->mNextEntries[index].mPlayer.mIndex = index;
        g_GlobalCO->mNextEntries[index].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_NONE;
        g_GlobalCO->mNextEntries[index].mPlayer.mListedCpuFlags = 0;
        g_GlobalCO->mNextEntries[index].mPlayer.mName = NULL;
        g_GlobalCO->mNextEntries[index].mPlayer.mHasEmblem = 0;
        g_GlobalCO->mNextEntries[index].mPlayer.mRegion = g_GlobalP->mRegion;
        g_GlobalCO->mNextEntries[index].mPlayer.mEmblemData = NULL;
        g_GlobalCO->mNextEntries[index].mPlayer.mFriendData = 0;
    }
    g_GlobalCO->mNextEntries[7].mPlayer.mListedCpuSlot = 0;
    g_GlobalCO->mNextEntries[6].mPlayer.mListedCpuSlot = 1;
    g_GlobalCO->mKartCount = 0;
    g_GlobalCO->mHumanAndPeerKartCount = 0;
    for (index = 0; index < 2; index++) {
        g_GlobalCO->mTeamKartCounts[index] = 0;
    }
    g_GlobalCO->mListedCpuCount = 0;
    for (index = 0; index < 2; index++) {
        g_GlobalCO->mListedCpuEntryIndices[index] = -1;
    }
    g_GlobalCO->mCourseCount = 0;
    for (index = 0; index < 0x21; index++) {
        g_GlobalCO->mCourseList[index] = 0;
    }
    g_GlobalCO->mCourseListIndex = 0;
    time = &g_GlobalCO->mGhostTime;
    time->mMinute = 0;
    time->mSecond = 0;
    time->mMillisecond = 0;
    for (index = 0; index < 5; index++) {
        time = &g_GlobalCO->mGhostLapTimes[index];
        time->mMinute = 0;
        time->mSecond = 0;
        time->mMillisecond = 0;
    }
    CreateGlobalLU();
    CreateGlobalRE();
    PrepareRace();
}

void PrepareCurrentRaceRacer(s32 entryIndex) {
    BackupBuffers *backupBuffers;
    ConnectionWork *connectionWork;
    void **nameSlot;
    void **emblemDataSlot;
    u8 *hasEmblemSlot;
    u8 *regionSlot;
    u8 *lowestRecordValueSlot;
    DWCAccFriendData **friendDataSlot;
    BOOL emblemFlag;
    BOOL hasEmblem;
    BOOL connectionActive;
    s8 participantOfKart;
    u8 participantIndex;

    backupBuffers = g_SaveDataHolder;
    nameSlot = &g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mName;
    emblemDataSlot = &g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mEmblemData;
    hasEmblemSlot = &g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mHasEmblem;
    regionSlot = &g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mRegion;
    lowestRecordValueSlot = &g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mLowestGrandPrixRecordValue;
    friendDataSlot = &g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mFriendData;
    emblemFlag = FALSE;
    if (backupBuffers->mEmblemRecord->mFilled != 0) {
        emblemFlag = backupBuffers->mFirstBlock->mEmblemOff == 0;
    }
    if (emblemFlag != FALSE) {
        hasEmblem = TRUE;
    } else {
        hasEmblem = FALSE;
    }
    *nameSlot = NULL;
    *emblemDataSlot = NULL;
    *hasEmblemSlot = 0;
    *friendDataSlot = 0;
    *regionSlot = g_GlobalP->mRegion;
    *lowestRecordValueSlot = 0;
    if (entryIndex == g_GlobalCO->mEntryIndex) {
        *nameSlot = &g_SaveDataHolder->mFirstBlock->mPlayerName;
        *emblemDataSlot = &g_SaveDataHolder->mEmblemRecord->mEmblemData;
        *hasEmblemSlot = hasEmblem != FALSE ? 1 : 0;
        *regionSlot = g_GlobalP->mRegion;
        *lowestRecordValueSlot = GetWorstStarRank_from_thumb();
        return;
    }
    switch (g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind) {
        case PLAYER_KIND_HUMAN:
            connectionWork = g_GlobalZE;
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
            *emblemDataSlot = &GetPlayerRecordByEntryIndex(g_GlobalZE, entryIndex)->mEmblem[0];
            *hasEmblemSlot = GetPlayerRecordByEntryIndex(g_GlobalZE, entryIndex)->mHasEmblem;
            *regionSlot = GetPlayerRecordByEntryIndex(g_GlobalZE, entryIndex)->mRegion;
            *friendDataSlot =
                IsBootInfoFirstWordTwo() || (g_GlobalZE->mGroupSendMask &
                                             (1 << g_GlobalZE->mParticipantIndexByPos[entryIndex])) != 0
                    ? 0
                    : &GetPlayerRecordByEntryIndex(g_GlobalZE, entryIndex)->mFriendData;
            *lowestRecordValueSlot =
                GetPlayerRecordByEntryIndex(g_GlobalZE, entryIndex)->mLowestGrandPrixRecordValue;
            break;
        case PLAYER_KIND_GHOST:
            switch (g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mGhostRecordIndex) {
                case GHOST_RECORD_INDEX_COURSE:
                    *nameSlot = &g_SaveDataHolder->mCourseGhostRecord->mHead.mName;
                    *emblemDataSlot = &g_SaveDataHolder->mEmblemRecord->mEmblemData;
                    *hasEmblemSlot = hasEmblem != FALSE ? 1 : 0;
                    *regionSlot = g_SaveDataHolder->mCourseGhostRecord->mHead.mRegion;
                    *lowestRecordValueSlot = 0;
                    break;
                case GHOST_RECORD_INDEX_FIRST_SLOT:
                    *nameSlot = &g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mName;
                    *emblemDataSlot = &g_SaveDataHolder->mSlotGhostRecords[0]->mEmblem;
                    *hasEmblemSlot = g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mHasEmblem;
                    *regionSlot = g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mRegion;
                    *lowestRecordValueSlot = g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mLowestGrandPrixRecordValue;
                    break;
                case GHOST_RECORD_INDEX_SECOND_SLOT:
                    *nameSlot = &g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mName;
                    *emblemDataSlot = &g_SaveDataHolder->mSlotGhostRecords[1]->mEmblem;
                    *hasEmblemSlot = 1;
                    *regionSlot = g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mRegion;
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
            *nameSlot = GetSomeBTKNickname(participantIndex);
            *emblemDataSlot = GetSomeBTKEmblemData(participantIndex);
            *hasEmblemSlot = GetSomeBTKUseCustomEmblemFlag(participantIndex);
            *regionSlot = GetMaybeSomeWifiIdx(participantIndex);
            *friendDataSlot = GetSomeBTKFriendCode(participantIndex);
            *lowestRecordValueSlot = GetWorstRankStarValue(participantIndex);
            break;
    }
}

void RefreshListedCpuEntryIndices(void) {
    u8 listedCount;
    s8 entryIndex;

    listedCount = 0;
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        g_GlobalCO->mListedCpuEntryIndices[entryIndex] = -1;
    }
    for (entryIndex = 0; entryIndex < g_GlobalCO->mKartCount; entryIndex++) {
        if ((GetCurrentEntry(entryIndex)->mPlayer.mListedCpuFlags & KART_ENTRY_LISTED_CPU_FLAG) != 0) {
            SetListedCpuEntryIndex(g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mListedCpuSlot, entryIndex);
            listedCount++;
        }
    }
    g_GlobalCO->mListedCpuCount = listedCount;
}

BOOL MaybeLoadPersonalGhost(s32 courseId, s32 entryIndex) {
    u8 lapIndex;
    BOOL result;
    GhostRecord *ghostRecord;

    result = FALSE;
    if (g_GlobalCO->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return TRUE;
    }
    ghostRecord = g_SaveDataHolder->mCourseGhostRecord;
    if (ghostRecord->mHead.mFilled == 1) {
        StructCO_ConfigureRacerDefault(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        g_GlobalCO->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_COURSE;
        Mem_CpuCopy8(ghostRecord->mKeyRecordingBuffer, g_GlobalCYT[entryIndex].mKeyRecording.mBuffer,
                    sizeof(KeyRecordingBuffer));
        result = TRUE;
        GetGhostFinishTimeByIndex(0, &g_GlobalCO->mGhostTime);
        for (lapIndex = 1; lapIndex <= 5; lapIndex++) {
            GetGhostLapTimeByIndex(0, lapIndex, &g_GlobalCO->mGhostLapTimes[lapIndex - 1]);
        }
    }
    return result;
}

BOOL MaybeLoadDownloadGhost(s32 courseId, s32 entryIndex) {
    SlotGhostRecord *ghostRecord;
    s32 filled;
    u8 lapIndex;

    if (g_GlobalCO->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return 1;
    }
    ghostRecord = g_SaveDataHolder->mSlotGhostRecords[0];
    filled = ghostRecord->mHead.mFilled == 1 ? 1 : 0;
    if (filled != 0) {
        StructCO_ConfigureRacerDefault(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        g_GlobalCO->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_FIRST_SLOT;
        Mem_CpuCopy8(ghostRecord->mKeyRecordingBuffer, g_GlobalCYT[entryIndex].mKeyRecording.mBuffer,
                    sizeof(KeyRecordingBuffer));
        GetGhostFinishTimeByIndex(1, &g_GlobalCO->mGhostTime);
        for (lapIndex = 1; lapIndex <= 5; lapIndex++) {
            GetGhostLapTimeByIndex(1, lapIndex, &g_GlobalCO->mGhostLapTimes[lapIndex - 1]);
        }
    } else {
        StructCO_ConfigureRacerDefault(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    }
    return filled;
}

BOOL MaybeLoadStaffGhost(s32 courseId, s32 entryIndex) {
    SlotGhostRecord *ghostRecord;
    u8 lapIndex;

    if (g_GlobalCO->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return TRUE;
    }
    ghostRecord = g_SaveDataHolder->mSlotGhostRecords[1];
    if (ghostRecord != NULL && ghostRecord->mHead.mFilled == 1) {
        StructCO_ConfigureRacerDefault(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        g_GlobalCO->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = GHOST_RECORD_INDEX_SECOND_SLOT;
        Mem_CpuCopy8(ghostRecord->mKeyRecordingBuffer, g_GlobalCYT[entryIndex].mKeyRecording.mBuffer,
                    sizeof(KeyRecordingBuffer));
        StructNKPG_CopyToTime_from_thumb(&ghostRecord->mHead, &g_GlobalCO->mGhostTime);
        for (lapIndex = 1; lapIndex <= 5; lapIndex++) {
            StructNKPG_AnotherCopyToTime_from_thumb(&ghostRecord->mHead, lapIndex, &g_GlobalCO->mGhostLapTimes[lapIndex - 1]);
        }
        return TRUE;
    }
    StructCO_ConfigureRacerDefault(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    return FALSE;
}

void PrepareRace(void) {
    s16 entryIndex;
    GhostRecord *ghostRecord;
    ConnectionWork *connectionWork;
    u16 value;
    u16 entryCount;
    u8 searchIndex;
    BOOL connectionActive;

    entryCount = 0;
    switch (g_GlobalCO->mNextHeader.mMode) {
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
            ghostRecord = g_SaveDataHolder->mCourseGhostRecord;
            if (ghostRecord->mHead.mFilled == 1) {
                g_GlobalCO->mFirstGhostRecordFilled = 1;
                g_GlobalCO->mFirstGhostRecordMinute = ghostRecord->mHead.mMinute;
                g_GlobalCO->mFirstGhostRecordSecond = ghostRecord->mHead.mSecond;
                g_GlobalCO->mFirstGhostRecordMillisecond = ghostRecord->mHead.mMillisecond;
            } else {
                g_GlobalCO->mFirstGhostRecordFilled = 0;
                g_GlobalCO->mFirstGhostRecordMinute = 0;
                g_GlobalCO->mFirstGhostRecordSecond = 0;
                g_GlobalCO->mFirstGhostRecordMillisecond = 0;
            }
            switch (g_GlobalCO->mNextHeader.mGhostRecordIndex) {
                case GHOST_RECORD_INDEX_COURSE:
                    if (MaybeLoadPersonalGhost(g_GlobalCO->mNextHeader.mCourseId, 1) != 0) {
                        value++;
                    }
                    break;
                case GHOST_RECORD_INDEX_FIRST_SLOT:
                    if (MaybeLoadDownloadGhost(g_GlobalCO->mNextHeader.mCourseId, 1) != 0) {
                        value++;
                    }
                    break;
                case GHOST_RECORD_INDEX_SECOND_SLOT:
                    if (MaybeLoadStaffGhost(g_GlobalCO->mNextHeader.mCourseId, 1) != FALSE) {
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
    switch (g_GlobalCO->mNextHeader.mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_AWARD:
            g_GlobalCO->mNextHeader.mEntryIndex = g_GlobalCO->mNextHeader.mFollowedKartIndex;
            break;
        case RACE_KIND_STAFF_ROLL:
            g_GlobalCO->mNextHeader.mEntryIndex = g_GlobalCO->mNextHeader.mFollowedKartIndex;
            entryCount = 8;
            break;
        case RACE_KIND_NORMAL:
        case RACE_KIND_REPLAY:
        case RACE_KIND_START_GP:
        case RACE_KIND_START_BATTLE:
            entryIndex = 0;
            for (searchIndex = 0; searchIndex < 8; searchIndex++) {
                if (g_GlobalCO->mNextEntries[searchIndex].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    entryIndex = searchIndex;
                    break;
                }
            }
            connectionWork = g_GlobalZE;
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
            g_GlobalCO->mNextHeader.mEntryIndex = entryIndex;
            g_GlobalCO->mNextHeader.mFollowedKartIndex = entryIndex;
            break;
    }
    g_GlobalCO->mCurrent = g_GlobalCO->mNext;
    MaybeSetRacerCount(entryCount);
    RefreshListedCpuEntryIndices();
    for (value = 0; value < 8; value++) {
        PrepareCurrentRaceRacer(value);
    }
}

void Scene_Menu2_FinalizeImpl(void) {
    u8 entryIndex;
    u32 tableIndex;
    u8 cupIndex;
    u8 courseIndexInCup;
    RaceSetupHeader *nextHeader;
    s32 cupCourseId;
    u8 rankIndex;
    s32 kartIndex;

    switch (g_GlobalCO->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            if (g_GlobalCO->mNextHeader.mCourseId == COURSE_ID_AWARD) {
                g_GlobalCO->mNextHeader.mCourseId = COURSE_ID_AWARD;
                g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_AWARD;
                for (entryIndex = 3; entryIndex < 8; entryIndex++) {
                    StructCO_ConfigureRacerDefault(entryIndex, entryIndex, entryIndex * 3, PLAYER_KIND_NONE, -1, 3);
                }
                g_GlobalCO->mNextHeader.mFollowedKartIndex = 0;
            } else if ((u32) (g_GlobalCO->mNextHeader.mCourseId - 0x35) <= 1) {
                g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
                g_GlobalCO->mNextHeader.mEngineIndex = ENGINE_CLASS_MEDIUM;
                for (rankIndex = 0; rankIndex < 8; rankIndex++) {
                    s8 rankKartIndex;
                    for (rankKartIndex = 0; rankKartIndex < g_GlobalCO->mKartCount; rankKartIndex++) {
                        if (rankIndex + 1 == GetSomeRacerPosition(rankKartIndex)) {
                            break;
                        }
                    }
                    kartIndex = rankIndex * 3;
                    if (g_GlobalCO->mNextHeader.mCourseId != COURSE_ID_STAFFROLLTRUE) {
                        SetNextRaceEntryWrapper(3, -1, 1, kartIndex, rankIndex, rankIndex);
                    }
                }
                g_GlobalCO->mNextHeader.mFollowedKartIndex = 0;
            } else {
                for (tableIndex = 0; tableIndex < 32; tableIndex++) {
                    cupIndex = (s32) tableIndex / 4;
                    courseIndexInCup = (s32) tableIndex % 4;
                    cupCourseId = g_InternalCourseIdOrderedTable[cupIndex][courseIndexInCup];
                    if (g_GlobalCO->mNextHeader.mCourseId == cupCourseId) {
                        break;
                    }
                    if (tableIndex == 31) {
                        cupIndex = 0;
                        courseIndexInCup = 3;
                    }
                }
                g_GlobalCO->mNextHeader.mCourseNumber = (u8) (courseIndexInCup + 1);
                nextHeader = &g_GlobalCO->mNextHeader;
                g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_START_GP;
                g_GlobalCO->mNextHeader.mCupIndex = cupIndex;
            }
            break;
        case MODE_BATTLE:
            if (g_GlobalP->mMultiSimple != 0) {
                g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            } else {
                g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_START_BATTLE;
            }
            break;
        case MODE_MISSION_RUN:
            break;
        default:
            g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
    }
}

void ResetRacersForTimeTrial(void) {
    u16 entryIndex;

    if (g_GlobalCO->mNextHeader.mMode != MODE_TIME_ATTACK) {
        return;
    }
    g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    for (entryIndex = 1; entryIndex < 8; entryIndex++) {
        g_GlobalCO->mNextEntries[entryIndex].mCharacterIndex = entryIndex;
        g_GlobalCO->mNextEntries[entryIndex].mKartIndex = entryIndex;
        g_GlobalCO->mNextEntries[entryIndex].mPlayer.mKind = PLAYER_KIND_NONE;
        g_GlobalCO->mNextEntries[entryIndex].mPlayer.mIndex = entryIndex;
    }
}

// In battle there is one lap.
u16 GetCurrentLapCount(void) {
    RaceSetup *raceSetup;
    u16 lapCount;

    lapCount = 1;
    raceSetup = g_GlobalCO;
    if (raceSetup->mMode != MODE_BATTLE) {
        if (raceSetup->mLapCount <= 0) {
            lapCount = g_GlobalPE->mSettings->mLapCountOrBattleSeconds;
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
    courseId = g_GlobalCO->mNextHeader.mCourseId;
    mode = g_GlobalCO->mNextHeader.mMode;
    RequestMPWaitRaceArchives((void *) courseId, (void *) mode);
}

static inline void ReadPadKeysAndUpdateTouchMic(void) {
    if ((SYSTEM_WORK->mButtonXY & SYSTEM_BUTTON_XY_CLOSED) >> 15) {
        g_Global5624->mPadKeys = 0;
    } else {
        g_Global5624->mPadKeys = ((reg_PAD_KEYINPUT | SYSTEM_WORK->mButtonXY) ^ 0x2fff) & 0x2fff;
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
        StructCY_SomeFn(inputSlot);
        StructCY_SomeFn_0(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot->mSourceKind = INPUT_SOURCE_NONE;
        inputSlot->mRequestedBits = 0;
        inputSlot->mIsBlocked = 0;
        inputSlot->mBitMask = INPUT_SLOT_BIT_MASK_DEFAULT;
        StructCYB_SomeFn(&inputSlot->mKeyRecording);
        StructCYA_SomeFn(&inputSlot->mPair);
    }
    g_GlobalCYT[INPUT_SLOT_PAD_OR_PARTICIPANT].mSourceKind = INPUT_SOURCE_PAD_OR_PARTICIPANT;
    g_GlobalCYT[INPUT_SLOT_PAD_AND_TOUCH].mSourceKind = INPUT_SOURCE_PAD_AND_TOUCH;
    g_Global5624->mParticipantPosition = 0;
    g_Global5624->mUnk_0c = FALSE;
    slot = g_GlobalCYT;
    for (resetIndex = 0; resetIndex < 10; resetIndex++) {
        StructCY_SomeFn(slot);
        slot->mRequestedBits = 0;
        StructCY_SomeFn_0(slot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        slot++;
    }
}

static inline RaceSetup *GetRaceSetup(void) {
    return g_GlobalCO;
}

void ReplaceEntryWithCpu(u32 entryIndex) {
    s32 listedCpuSlot;
    RaceSetup *raceSetup;

    listedCpuSlot = 3;
    if (g_GlobalCO->mListedCpuEntryIndices[0] == -1) {
        listedCpuSlot = 0;
    } else if (g_GlobalCO->mListedCpuEntryIndices[1] == -1) {
        listedCpuSlot = 1;
    }
    StructCO_ConfigureRacerDefault(entryIndex, g_GlobalCO->mCurrentEntries[entryIndex].mCharacterIndex,
                     g_GlobalCO->mCurrentEntries[entryIndex].mKartIndex, PLAYER_KIND_CPU,
                     g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mTeamIndex, listedCpuSlot);
    raceSetup = g_GlobalCO;
    raceSetup->mCurrentEntries[entryIndex] = raceSetup->mNextEntries[entryIndex];
    if (listedCpuSlot < 2) {
        raceSetup->mListedCpuEntryIndices[listedCpuSlot] = entryIndex;
    }
    g_GlobalCO->mNextEntries[entryIndex].mPlayer.mNumber = g_GlobalCO->mNextCpuNumber;
    g_GlobalCO->mNextCpuNumber = g_GlobalCO->mNextCpuNumber + 1;
}

void SetNextRaceFromMissionRow(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn) {
    u8 entryIndex;

    g_GlobalCO->mNextHeader.mMissionFileRow = *missionFileRow;
    g_GlobalCO->mNextHeader.mMissionTableRow = tableRow;
    g_GlobalCO->mNextHeader.mMissionTableColumn = tableColumn;
    g_GlobalCO->mNextHeader.mMode = MODE_MISSION_RUN;
    g_GlobalCO->mNextHeader.mCourseId = missionFileRow->mCourseId;
    g_GlobalCO->mNextHeader.mMirrorMode = (missionFileRow->mFlags & MISSION_FILE_ROW_FLAG_MIRROR) != 0 ? 1 : 0;
    g_GlobalCO->mNextHeader.mUseTeams = 0;
    g_GlobalCO->mNextHeader.mRuleKind = RULE_KIND_FREE;
    g_GlobalCO->mNextHeader.mCourseListMode = COURSE_LIST_MODE_SINGLE;
    g_GlobalCO->mNextHeader.mBattleKind = 0;
    g_GlobalCO->mCourseCount = 0;
    g_GlobalCO->mNextHeader.mEngineIndex = missionFileRow->mEngineIndex;
    StructCO_ConfigureRacerDefault(0, missionFileRow->mCharacterIndex0, missionFileRow->mKartIndex0, PLAYER_KIND_HUMAN, -1, 3);
    if (missionFileRow->mCharacterIndex1 != MISSION_FILE_ROW_NO_SECOND_KART &&
        missionFileRow->mKartIndex1 != MISSION_FILE_ROW_NO_SECOND_KART) {
        StructCO_ConfigureRacerDefault(1, missionFileRow->mCharacterIndex1, missionFileRow->mKartIndex1, PLAYER_KIND_CPU, -1, 3);
        g_GlobalCO->mNextHeader.mCpuDifficulty = CPU_DIFFICULTY_NORMAL;
    } else {
        StructCO_ConfigureRacerDefault(1, -1, -1, PLAYER_KIND_NONE, -1, 3);
        g_GlobalCO->mNextHeader.mCpuDifficulty = 0;
    }
    for (entryIndex = 2; entryIndex < 8; entryIndex++) {
        StructCO_ConfigureRacerDefault(entryIndex, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
}

void ReadCourseGhostRecordAndWait(u32 courseId) {
    g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mFilled = 0;
    g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitForWorkerTask();
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    }
}

void ReadCourseAndSlotGhostRecords(u32 courseId, u8 slotIndex) {
    g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mFilled = 0;
    g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mFilled = 0;
    g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitForWorkerTask();
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    }
    ReadSlotGhostRecord(slotIndex);
    WaitForWorkerTask();
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mFilled = 0;
    }
}

// Reads the course ghost record, then loads its ghost file; a failed load leaves a NULL record that is then
// zero-filled.
void LoadStaffGhost(u32 courseId) {
    SlotGhostRecord *ghostRecord;
    char path[0x80];

    ghostRecord = NULL;
    g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mFilled = 0;
    g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mFilled = 0;
    g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitForWorkerTask();
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    }
    if (FindFormatGhostBinPath(courseId, path, 0x80) != FALSE) {
        ghostRecord = GetReadStaffGhost_from_thumb(path);
    }
    if (ghostRecord != NULL) {
        return;
    }
    Mem_CpuFill8(ghostRecord, 0, sizeof(SlotGhostRecord));
    ghostRecord->mHead.mFilled = 0;
}

void SelectGhostReadCourseRecordAndWait(u32 courseId) {
    g_SaveDataHolder->mSlotGhostRecords[0]->mHead.mFilled = 0;
    g_SaveDataHolder->mSlotGhostRecords[1]->mHead.mFilled = 0;
    g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitForWorkerTask();
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        g_SaveDataHolder->mCourseGhostRecord->mHead.mFilled = 0;
    }
}

void MaybeReloadRacersSfx(u32 useCurrentEntries) {
    u16 entryIndex;
    RaceSetup *raceSetup;
    u32 bankMask;

    bankMask = 0;
    entryIndex = 0;
    for (; entryIndex < (u32) (raceSetup = GetRaceSetup())->mKartCount; entryIndex++) {
        if (useCurrentEntries != 0) {
            bankMask |= g_CharacterMaskTable[raceSetup->mCurrentEntries[entryIndex].mCharacterIndex];
        } else {
            bankMask |= g_CharacterMaskTable[raceSetup->mNextEntries[entryIndex].mCharacterIndex];
        }
    }
    MaybeReloadRacerSbnksSwars(bankMask);
}

void Input_Initialize(void *heap) {
    s32 slotIndex;

    Input_MaybeInitializeTouch();
    CreateGlobal59C4(heap);
    for (slotIndex = 0; slotIndex <= 1; slotIndex++) {
        AllocateInputRecord(&g_GlobalCYT[slotIndex].mKeyRecording, heap);
    }
    for (; slotIndex < 10; slotIndex++) {
        StructCYB_ResetInputRecord(&g_GlobalCYT[slotIndex].mKeyRecording);
    }
    g_Global5624 = Mem_AllocateHeap(heap, sizeof(*g_Global5624));
    ResetInputSlotsAndRepeat();
    ReadPadKeysAndUpdateTouchMic();
    ReadPadKeysAndUpdateTouchMic();
}

void MaybeResetInput(void) {
    ResetInputSlotsAndRepeat();
}

void StartInputSlots(void) {
    s32 resetIndex;
    s32 clearIndex;
    InputSlot *inputSlot;
    InputSlot *slot;

    inputSlot = g_GlobalCYT;
    for (resetIndex = 0; resetIndex < 10; resetIndex++) {
        StructCY_SomeFn(inputSlot);
        inputSlot->mRequestedBits = 0;
        StructCY_SomeFn_0(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot++;
    }
    StartTouchAutoSampling();
    UpdateInputSlots();
    slot = g_GlobalCYT;
    for (clearIndex = 0; clearIndex < 10; clearIndex++) {
        slot->mHoldLong = 0;
        slot->mLongHoldEnabled = 0;
        StructCY_SomeFn_0(slot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        slot++;
    }
    g_Global5624->mPadKeys = 0;
    g_Global5624->mFlags = 0;
}

void StopTouchAutoSamplingWrapper(void) {
    StopTouchAutoSampling();
}

void ClearInputSlots(void) {
    s32 slotIndex;
    InputSlot *inputSlot;

    inputSlot = g_GlobalCYT;
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        StructCY_SomeFn_1(inputSlot);
        inputSlot++;
    }
}

void SetNoKeysAndUpdateInputSlots(void) {
    g_Global5624->mFlags |= INPUT_STATE_NO_KEYS;
    UpdateInputSlots();
}

void j_ResetGlobal59C4(void) {
    ResetGlobal59C4();
}

void SetLeftRightKeysSwapped(u32 mirrorMode) {
    if (mirrorMode != 0) {
        g_Global5624->mFlags |= INPUT_STATE_FLAG_LEFT_RIGHT_SWAPPED;
    } else {
        g_Global5624->mFlags &= ~INPUT_STATE_FLAG_LEFT_RIGHT_SWAPPED;
    }
}

void UpdatePadKeysAndTouchMic(void) {
    ReadPadKeysAndUpdateTouchMic();
}

u32 GetPadKeys(void) {
    return (g_Global5624->mPadKeys);
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

    padKeys = g_Global5624->mPadKeys;
    packedTouchPoint = GetPackedTouchPoint();
    padOrParticipantKeys = padKeys;
    padOrParticipantTouchPoint = packedTouchPoint;
    micOverThreshold = g_Global59C4->mMicOverThreshold;
    if (InputSlotsIsConnectionActive(g_GlobalZE) != 0) {
        padOrParticipantKeys = GetParticipantPadKeys(GetParticipantIndex(g_Global5624->mParticipantPosition));
        padOrParticipantTouchPoint =
            g_GlobalZE->mDataSharing.mReceivedRecords[GetParticipantIndex(g_Global5624->mParticipantPosition)]
                .mTouchPoint;
        GetParticipantIndex(g_Global5624->mParticipantPosition);
    }
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        slotKeys = 0;
        touchPoint = 0xffff;
        micValue = slotKeys;
        isBlocked = (g_Global5624->mFlags & INPUT_STATE_OPEN_DURING_RACE) ? 1 : 0;
        skipUpdate = FALSE;
        canReadKeys = (GetCurrentSceneId() != 2 || (g_Global5624->mFlags & INPUT_STATE_READ_RACE_KEYS)) ? 1 : 0;
        inputSlot = &g_GlobalCYT[slotIndex];
        flags = g_Global5624->mFlags;
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
                            if (g_Global5624->mFlags & INPUT_STATE_FLAG_LEFT_RIGHT_SWAPPED) {
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
                        g_GlobalZE->mDataSharing.mReceivedRecords[GetParticipantIndex(slotIndex)].mTouchPoint;
                    micValue = g_GlobalZE->mDataSharing.mReceivedRecords[GetParticipantIndex(slotIndex)]
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
            StructG_UpdateInput(keys, &inputSlot->mHead);
        }
        UpdateInputSlotPair(&inputSlot->mPair, touchPoint, micValue);
    }
}

// Takes effect only for slots whose source kind is INPUT_SOURCE_REQUESTED_BITS or INPUT_SOURCE_WIFI_REQUESTED_BITS.
void RequestBits(s32 slotIndex, u32 bits) {
    if (g_GlobalCYT[slotIndex].mSourceKind == INPUT_SOURCE_REQUESTED_BITS ||
        g_GlobalCYT[slotIndex].mSourceKind == INPUT_SOURCE_WIFI_REQUESTED_BITS) {
        g_GlobalCYT[slotIndex].mRequestedBits |= bits;
    }
}

void Struct5624_SetXflag1(u32 openDuringRace) {
    if (openDuringRace != 0) {
        g_Global5624->mFlags |= INPUT_STATE_OPEN_DURING_RACE;
        return;
    }
    g_Global5624->mFlags &= ~INPUT_STATE_OPEN_DURING_RACE;
}

u32 GetVolatileHalfwordIndex39(void) {
    return g_GlobalCYT[INPUT_SLOT_PAD_AND_TOUCH].mHoldLong;
}
