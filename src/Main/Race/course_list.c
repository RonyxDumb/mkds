#include "Main/Race/course_list.h"
#include "00/code_02181f98.h"
#include "Main/Race/results_gp.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Sound/scene_sound_set.h"
#include "Main/Race/cup_records.h"
#include "Main/System/low_byte.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Race/gp_records_killer.h"

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
    s32 flag;
    u32 cupCount;
    const u32 *cupTable;
    u32 listIndex;
    u32 courseCount;
    flag = 0;
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
    for (listIndex = 0; listIndex < 0x21; listIndex++) {
        gRaceSetup->mCourseList[listIndex] = 0;
    }
    switch (gStartupWork->mConnectionKind) {
        case 1:
        case 2:
            flag = (gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0;
            break;
    }
    switch (gRaceSetup->mNextHeader.mCourseListMode) {
        case 1:
            if (isVersus != 0) {
                u8 cupSlot;
                u8 courseSlot;
                u32 entryCount;
                s32 currentCourseId;
                s32 enabledCount;
                cupCount = flag != 0 ? 2 : 8;
                cupTable = flag != 0 ? data_usa_021540c0 : data_usa_02154108;
                currentCourseId = gRaceSetup->mNextHeader.mCourseId;
                entryCount = cupCount * 4;
                for (flag = 0; flag < entryCount; flag++) {
                    cupSlot = flag / 4;
                    courseSlot = flag % 4;
                    if (currentCourseId == gCupCourseIdTable[cupTable[cupSlot]][courseSlot]) {
                        break;
                    }
                }
                enabledCount = 0;
                for (flag = 0; flag < entryCount; flag++) {
                    if (IsCupEnabled(cupTable[cupSlot]) != FALSE) {
                        gRaceSetup->mCourseList[enabledCount] = gCupCourseIdTable[cupTable[cupSlot]][courseSlot];
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
                cupTable = flag != 0 ? data_usa_021540c8 : data_usa_021540d4;
                currentCourseId = gRaceSetup->mNextHeader.mCourseId;
                for (listIndex = 0; listIndex < courseCount; listIndex++) {
                    startIndex = listIndex;
                    if (currentCourseId == cupTable[listIndex]) {
                        break;
                    }
                }
                for (listIndex = 0; listIndex < courseCount; listIndex++) {
                    gRaceSetup->mCourseList[listIndex] = cupTable[startIndex];
                    startIndex++;
                    if (startIndex >= courseCount) {
                        startIndex = 0;
                    }
                }
                return;
            }
        case 2:
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
                cupTable = flag != 0 ? data_usa_021540c0 : data_usa_02154108;
                entryCount = cupCount * 4;
                enabledCount = 0;
                for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
                    cupSlot = entryIndex / 4;
                    courseSlot = entryIndex % 4;
                    if (IsCupEnabled(cupTable[cupSlot]) != FALSE) {
                        gRaceSetup->mCourseList[enabledCount] = gCupCourseIdTable[cupTable[cupSlot]][courseSlot];
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
                courseCount = flag != 0 ? 3 : 6;
                cupTable = flag != 0 ? data_usa_021540c8 : data_usa_021540d4;
                for (courseIndex = 0; courseIndex < courseCount; courseIndex++) {
                    gRaceSetup->mCourseList[courseIndex] = cupTable[courseIndex];
                }
                courseIndex = 0;
                if (courseIndex < courseCount) {
                    cupCount = (u16) (courseCount - 1);
                    for (; courseIndex < courseCount; courseIndex++) {
                        u8 swapIndex;
                        u8 swapTemp;
                        swapIndex = BuildCourseListNextRandomBelowU16(random, cupCount);
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
    gMenuShared->mCupRankIndex = GetKartCupRank((u16) entryIndex) - 1;
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
        GetKartCourseFinishTime(&finishTime, (u16) gRaceSetup->mEntryIndex, index);
        gMenuShared->mCourseTimes[index] = finishTime;
    }
    if ((u32) GetKartCupRank((u16) gRaceSetup->mEntryIndex) > 3) {
        return FALSE;
    }
    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_AWARD;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_AWARD;
    for (index = 0; index < 3; index++) {
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
            if (GetKartCupRank((u16) kartIndex) == index + 1) {
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
    gRaceSetup->mNextHeader.mFollowedKartIndex = GetKartCupRank((u16) gRaceSetup->mEntryIndex) - 1;
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
    gRaceSetup->mNextHeader.mEngineIndex = 1;
    gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
    for (index = 0; index < 8; index++) {
        for (searchIndex = 0; searchIndex < gRaceSetup->mKartCount; searchIndex++) {
            if (GetKartCupRank((u16) searchIndex) == index + 1) {
                break;
            }
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            if ((gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1) == 6 &&
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
        case 0:
            result = FALSE;
            break;
        case 1:
        case 2:
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
    return gRaceSetup->mNextHeader.mCourseNumber <= 4;
}
