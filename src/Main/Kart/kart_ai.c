#include "Main/Kart/kart_ai.h"

#include "Main/Race/race_progress_lap.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "code_02147cd8.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/cup_records.h"
#include "Main/Kart/code_0207e654.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Race/data_020f36d8.h"
#include "code_020172d0.h"
#include "code_0201750c.h"
#include "Main/Race/race_clock.h"

#pragma thumb on

KartAiParamRow *gKartAiParamRow;
KartAiShared *gKartAiShared;

// Picks the row of 'kartAIparam.bin' for the course and the mode; no row in battle and when mUnk_00c is 5 or 6.
void SetKartAiParamRow(void) {
    RaceSetup *raceSetup;
    KartAiParamRow *paramRow;
    gKartAiParamRow = NULL;
    raceSetup = gRaceSetup;
    if (raceSetup->mRaceKind != RACE_KIND_AWARD && raceSetup->mMode != MODE_BATTLE &&
        raceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        paramRow = GetKartModelFile("kartAIparam.bin");
        raceSetup = gRaceSetup;
        if (raceSetup->mMode == MODE_GRAND_PRIX) {
            paramRow = &paramRow[(raceSetup->mCourseId - 1) * 12 + raceSetup->mEngineIndex];
        } else {
            paramRow = &paramRow[(raceSetup->mCourseId - 1) * 12 + (raceSetup->mEngineIndex + 1) * 3];
            switch (raceSetup->mCpuDifficulty) {
                case CPU_DIFFICULTY_NORMAL:
                    paramRow++;
                    break;
                case CPU_DIFFICULTY_HARD:
                    paramRow += 2;
                    break;
            }
        }
        gKartAiParamRow = paramRow;
    }
}

void InitKartAiShared(void) {
    u16 kartIndex;
    BOOL zero;
    s32 minusOne;
    gKartAiShared = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x144);
    zero = FALSE;
    minusOne = -1;
    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        gKartAiShared->mRaceProgressScaled[kartIndex] = zero;
        gKartAiShared->mKartAtRank[kartIndex] = minusOne;
        gKartAiShared->mKind1KartByRank[kartIndex] = minusOne;
        gKartAiShared->mNonCpuKartByRank[kartIndex] = minusOne;
        gKartAiShared->mTableIndex[kartIndex] = zero;
    }
    gKartAiShared->mLastRankCpuKart = minusOne;
    gKartAiShared->mLastRankNotCpuKart = minusOne;
    gKartAiShared->mFirstRankNotCpuKart = minusOne;
    gKartAiShared->mFirstRankProgressRatio = zero;
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gKartAiShared->mRandom = &gRaceProgress->mLocalRandom;
    } else {
        gKartAiShared->mRandom = &gRaceProgress->mRandom;
    }
    if (gRaceSetup->mKartCount > 1 && gRaceSetup->mKartCount - gRaceSetup->mHumanAndPeerKartCount == 1) {
        gKartAiShared->mOneKartNotHumanOrPeer = 1;
        gKartAiShared->mNonCpuRank = ((u32) gRaceSetup->mHumanAndPeerKartCount >> 1) + 1;
    } else {
        gKartAiShared->mOneKartNotHumanOrPeer = 0;
        gKartAiShared->mNonCpuRank = -1;
    }
    if (gKartAiParamRow != NULL) {
        InitKartAiGrandPrixPoints();
        InitKartAiTableIndices();
        if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            switch (gRaceSetup->mEngineIndex) {
                case 0:
                    gKartAiShared->mEngineOrDifficultyIndex = 0;
                    break;
                case 1:
                    gKartAiShared->mEngineOrDifficultyIndex = 1;
                    break;
                case 2:
                    gKartAiShared->mEngineOrDifficultyIndex = 2;
                    break;
                default:
                    gKartAiShared->mEngineOrDifficultyIndex = 1;
                    break;
            }
        } else {
            switch (gRaceSetup->mCpuDifficulty) {
                case CPU_DIFFICULTY_EASY:
                    gKartAiShared->mEngineOrDifficultyIndex = 0;
                    break;
                case CPU_DIFFICULTY_NORMAL:
                    gKartAiShared->mEngineOrDifficultyIndex = 1;
                    break;
                case CPU_DIFFICULTY_HARD:
                    gKartAiShared->mEngineOrDifficultyIndex = 2;
                    break;
                default:
                    gKartAiShared->mEngineOrDifficultyIndex = 1;
                    break;
            }
        }
        gKartAiParamRow->mGapTableScale = FX_Div(gKartAiParamRow->mGapTableScale, 0x3000);
    }
    InitKartAiNonCpuCounts();
    SetupKartAiGlobals();
    InitKartAiTables();
    SetupRaceItemEntries();
    if (gRaceSetup->mMode == MODE_BATTLE) {
        SetupBattleKartAiParams();
        SetupBattleItemEntries();
    }
}

void InitKartAiNonCpuCounts(void) {
    u16 kartIndex;
    u16 teamIndex;
    BOOL isNonCpu;
    BOOL isNonCpuWithoutTeams;
    KartEntryPlayer *player;
    kartIndex = 0;
    gKartAiShared->mNonCpuKartCount = kartIndex;
    for (teamIndex = 0; teamIndex < 2; teamIndex++) {
        gKartAiShared->mTeamNonCpuKartCounts[teamIndex] = kartIndex;
    }
    for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        if (gRaceSetup->mUseTeams != 0) {
            for (teamIndex = 0; teamIndex < 2; teamIndex++) {
                isNonCpu = FALSE;
                if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind > 3) {
                } else if ((1 << gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind) &
                           PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    isNonCpu = TRUE;
                }
                if (isNonCpu != FALSE && teamIndex == gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                    gKartAiShared->mTeamNonCpuKartCounts[teamIndex]++;
                    break;
                }
            }
        } else {
            isNonCpuWithoutTeams = FALSE;
            player = &gRaceSetup->mCurrentEntries[kartIndex].mPlayer;
            if (player->mKind <= 3 && ((1 << player->mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isNonCpuWithoutTeams = TRUE;
            }
            if (isNonCpuWithoutTeams != FALSE) {
                gKartAiShared->mNonCpuKartCount++;
            }
        }
    }
}

void InitKartAiGrandPrixPoints(void) {
    u16 clearIndex;
    s32 bestNonCpuPoints;
    s32 bestCpuPoints;
    s16 entryIndex;
    u16 kartIndex;
    s32 previousTotalPoints;
    BOOL isNonCpu;
    s32 pointsDifference;

    clearIndex = 0;
    bestNonCpuPoints = 0;
    bestCpuPoints = 0;
    for (; clearIndex < 2; clearIndex++) {
        gKartAiShared->mListedCpuKartPoints[clearIndex] = 0;
    }
    gKartAiShared->mPointsGapKind = KART_AI_POINTS_GAP_NONE;
    gKartAiShared->mLowerPointsListedCpuIndex = 0;
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        for (entryIndex = 0; entryIndex < gRaceSetup->mKartCount; entryIndex++) {
            kartIndex = entryIndex;
            previousTotalPoints = GetKartPreviousTotalPoints(kartIndex);
            isNonCpu = FALSE;
            if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isNonCpu = TRUE;
            }
            if (isNonCpu != FALSE) {
                if (previousTotalPoints > bestNonCpuPoints) {
                    bestNonCpuPoints = previousTotalPoints;
                }
            } else {
                if (previousTotalPoints > bestCpuPoints) {
                    bestCpuPoints = previousTotalPoints;
                }
                if (entryIndex == gRaceSetup->mListedCpuEntryIndices[0]) {
                    gKartAiShared->mListedCpuKartPoints[0] = previousTotalPoints;
                } else if (entryIndex == gRaceSetup->mListedCpuEntryIndices[1]) {
                    gKartAiShared->mListedCpuKartPoints[1] = previousTotalPoints;
                }
            }
        }
        pointsDifference = bestNonCpuPoints - bestCpuPoints;
        if (pointsDifference <= -5) {
            if (gRaceSetup->mListedCpuCount > 1) {
                gKartAiShared->mPointsGapKind = KART_AI_POINTS_GAP_NON_CPU_BEHIND;
                if (gKartAiShared->mListedCpuKartPoints[0] > gKartAiShared->mListedCpuKartPoints[1]) {
                    gKartAiShared->mLowerPointsListedCpuIndex = 1;
                }
            }
        } else if (gRaceSetup->mCpuDifficulty != CPU_DIFFICULTY_EASY && pointsDifference >= 4) {
            gKartAiShared->mPointsGapKind = KART_AI_POINTS_GAP_NON_CPU_AHEAD;
        }
    }
}

void InitKartAiTableIndices(void) {
    u16 count;
    u16 nonCpuKartCount;
    u16 listedIndex;
    u16 kartIndex;
    u16 kartCount;
    u16 tableEntryCount;
    u16 tableEntryIndex;
    RaceSetup *raceSetup;
    s32 tableIndex;
    BOOL isNonCpu;
    u32 nextNonCpuTableIndex;
    count = 0;
    nonCpuKartCount = 0;
    nextNonCpuTableIndex = gRaceSetup->mKartCount;
    NNS_FndInitList(&gKartAiShared->mTableIndexList, 4);
    for (listedIndex = 0; listedIndex < 2; listedIndex++) {
        if (gRaceSetup->mListedCpuEntryIndices[listedIndex] >= 0) {
            count++;
        }
    }
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; (u32) kartIndex < kartCount; kartIndex++) {
        isNonCpu = FALSE;
        if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isNonCpu = TRUE;
        }
        if (isNonCpu != FALSE) {
            nonCpuKartCount++;
        }
    }
    tableEntryCount = kartCount - nonCpuKartCount - count;
    tableEntryIndex = 0;
    for (; tableEntryIndex < tableEntryCount; tableEntryIndex++) {
        gKartAiShared->mTableIndexEntries[tableEntryIndex].mTableIndex = (u16) (tableEntryIndex + count + 1);
        NNS_FndAppendListObject(&gKartAiShared->mTableIndexList, &gKartAiShared->mTableIndexEntries[tableEntryIndex]);
    }
    count = 0;
    raceSetup = gRaceSetup;
    for (; (u32) count < raceSetup->mKartCount; count++) {
        if (raceSetup->mMode == MODE_TIME_ATTACK) {
            tableIndex = count;
        } else {
            tableIndex = PickKartAiTableIndex(count, &nextNonCpuTableIndex);
        }
        gKartAiShared->mTableIndex[count] = tableIndex;
        raceSetup = gRaceSetup;
    }
}

s32 PickKartAiTableIndex(u16 kartIndex, u32 *nextNonCpuTableIndexPointer) {
    s32 tableIndex;
    BOOL hasFixedIndex;
    BOOL isNonCpuAhead;
    BOOL isNonCpu;
    s32 value;
    s32 pointsGapKind;
    s32 otherIndex;
    u16 listedIndex;
    NNSFndList *tableIndexList;
    u16 listCount;
    u32 listPosition;
    u16 randomLimit;
    u16 randomLimitCopy;
    KartAiShared *kartAiShared;
    RaceSetup *raceSetup;
    RandomState64 *random;
    KartAiTableIndexEntry *entry;
    hasFixedIndex = FALSE;
    tableIndex = -1;
    kartAiShared = gKartAiShared;
    pointsGapKind = kartAiShared->mPointsGapKind;
    if (pointsGapKind == KART_AI_POINTS_GAP_NON_CPU_AHEAD) {
        isNonCpuAhead = TRUE;
    } else {
        isNonCpuAhead = FALSE;
    }
    isNonCpu = FALSE;
    raceSetup = gRaceSetup;
    value = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if ((u32) value <= 3 && ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
        isNonCpu = TRUE;
    }
    if (isNonCpu != FALSE) {
        tableIndex = *nextNonCpuTableIndexPointer;
        *nextNonCpuTableIndexPointer = tableIndex - 1;
    } else {
        if (pointsGapKind == KART_AI_POINTS_GAP_NON_CPU_BEHIND) {
            value = kartAiShared->mLowerPointsListedCpuIndex;
            if (value != 0) {
                value = 1;
            } else {
                value = 0;
            }
            if (value == 0) {
                otherIndex = 1;
            } else {
                otherIndex = 0;
            }
            if (kartIndex == raceSetup->mListedCpuEntryIndices[value]) {
                tableIndex = 1;
                hasFixedIndex = TRUE;
            } else if (kartIndex == (u16) raceSetup->mListedCpuEntryIndices[otherIndex]) {
                tableIndex = 2;
                hasFixedIndex = TRUE;
            }
        } else {
            for (listedIndex = 0; listedIndex < 2; listedIndex++) {
                value = raceSetup->mListedCpuEntryIndices[listedIndex];
                if (value == kartIndex) {
                    if (listedIndex == 0) {
                        tableIndex = 1;
                    } else {
                        tableIndex = 2;
                        if (isNonCpuAhead != FALSE) {
                            tableIndex = 1;
                        }
                    }
                    hasFixedIndex = TRUE;
                    break;
                }
            }
        }
        if (hasFixedIndex == FALSE) {
            tableIndexList = &gKartAiShared->mTableIndexList;
            listCount = tableIndexList->mCount;
            random = gKartAiShared->mRandom;
            randomLimit = listCount - 1;
            if (randomLimit == 0) {
                listPosition = 0;
            } else {
                random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
                randomLimitCopy = (u16) listCount - 1;
                if (randomLimitCopy == 0) {
                    listPosition = random->mValue >> 32;
                } else {
                    listPosition = (s64) (u32) (random->mValue >> 32) * (s64) (u32) randomLimitCopy >> 32;
                }
            }
            entry = NNS_FndGetNthListObject(tableIndexList, listPosition);
            tableIndex = entry->mTableIndex;
            NNS_FndRemoveListObject(tableIndexList, entry);
        }
    }
    return tableIndex;
}

#pragma thumb off

void DecrementKartAiNonCpuCount(u32 kartIndex) {
    RaceSetup *raceSetup;
    BOOL isNonCpu;
    s16 teamIndex;
    raceSetup = gRaceSetup;
    isNonCpu = FALSE;
    if (raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind <= 3 &&
        ((1 << raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
        isNonCpu = TRUE;
    }
    if (isNonCpu == FALSE) {
        return;
    }
    if (raceSetup->mUseTeams != 0) {
        for (teamIndex = 0; teamIndex < 2; teamIndex++) {
            if (teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                if (gKartAiShared->mTeamNonCpuKartCounts[teamIndex] > 0) {
                    gKartAiShared->mTeamNonCpuKartCounts[teamIndex]--;
                }
                break;
            }
        }
    } else {
        if (gKartAiShared->mNonCpuKartCount > 0) {
            gKartAiShared->mNonCpuKartCount--;
        }
    }
}

s16 GetNonCpuKartCountOutsideKartTeam(u32 kartIndex) {
    s16 count;
    u16 teamIndex;
    count = 0;
    if (gRaceSetup->mUseTeams != 0) {
        for (teamIndex = 0; teamIndex < 2; teamIndex++) {
            if (teamIndex != gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                count = count + gKartAiShared->mTeamNonCpuKartCounts[teamIndex];
            }
        }
    } else {
        count = gKartAiShared->mNonCpuKartCount;
    }
    return count;
}

void UpdateKartAiShared(void) {
    u32 maxRank;
    u16 kartIndex;
    u32 kartRank;
    if (gKartAiParamRow == NULL) {
        return;
    }
    UpdateKartAiRankLists();
    maxRank = 1;
    for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        kartRank = GetKartRank(kartIndex);
        if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (kartRank == 1) {
                gKartAiShared->mFirstRankNotCpuKart = kartIndex;
            }
            if (kartRank >= maxRank) {
                maxRank = kartRank;
                gKartAiShared->mLastRankNotCpuKart = kartIndex;
            }
        }
    }
}

void UpdateKartAiRankLists(void) {
    s32 maxCpuRank;
    u16 kartIndex;
    s32 kartRank;
    s32 scaledProgress;
    s32 listCount;
    s32 rankIndex;
    s32 value;
    s32 kartAtRank;
    u16 index;
    BOOL isNonCpu;
    maxCpuRank = 1;
    for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        scaledProgress = gCourseMap->mCheckpointSumQuotient;
        value = GetKartRaceProgress(kartIndex);
        scaledProgress = MUL_FIXED12_ROUNDED(value, scaledProgress);
        kartRank = GetKartRank(kartIndex);
        gKartAiShared->mRaceProgressScaled[kartIndex] = scaledProgress;
        if (kartRank > 0) {
            index = kartRank - 1;
            if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
                if (kartRank > maxCpuRank) {
                    maxCpuRank = kartRank;
                    gKartAiShared->mLastRankCpuKart = kartIndex;
                }
            }
            gKartAiShared->mKartAtRank[index] = kartIndex;
        }
        if (kartRank == 1) {
            if (scaledProgress >= 0) {
                gKartAiShared->mFirstRankProgressRatio = FX_Div(gKartAiShared->mRaceProgressScaled[kartIndex], 0x4ce);
                if (gKartAiShared->mFirstRankProgressRatio < 0x19a) {
                    gKartAiShared->mFirstRankProgressRatio = 0x19a;
                } else if (gKartAiShared->mFirstRankProgressRatio > 0x1000) {
                    gKartAiShared->mFirstRankProgressRatio = 0x1000;
                }
            } else {
                gKartAiShared->mFirstRankProgressRatio = 0;
            }
        }
    }
    listCount = 0;
    for (rankIndex = 0; rankIndex < gRaceSetup->mKartCount; rankIndex++) {
        value = gKartAiShared->mKartAtRank[rankIndex];
        if (value >= 0) {
            index = value;
            if (gRaceSetup->mCurrentEntries[index].mPlayer.mKind == PLAYER_KIND_CPU) {
                gKartAiShared->mKind1KartByRank[listCount] = value;
                listCount++;
            }
        }
    }
    if (gKartAiShared->mOneKartNotHumanOrPeer == 0) {
        return;
    }
    listCount = 0;
    for (rankIndex = 0; rankIndex < gRaceSetup->mKartCount; rankIndex++) {
        kartAtRank = gKartAiShared->mKartAtRank[rankIndex];
        if (kartAtRank >= 0) {
            index = kartAtRank;
            isNonCpu = FALSE;
            if (gRaceSetup->mCurrentEntries[index].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[index].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isNonCpu = TRUE;
            }
            if (isNonCpu != FALSE) {
                gKartAiShared->mNonCpuKartByRank[listCount] = kartAtRank;
                listCount++;
            }
        }
    }
}

s32 GetKartRankAmongKind1(u16 kartIndex) {
    s32 rank;
    u16 rankIndex;
    rank = -1;
    for (rankIndex = 0; (u32) rankIndex < gRaceSetup->mKartCount; rankIndex++) {
        if (kartIndex == (u16) gKartAiShared->mKind1KartByRank[rankIndex]) {
            rank = rankIndex + 1;
            break;
        }
    }
    return rank;
}

s32 GetKind1KartByRankPlusOffset(u32 rank, u32 offset) {
    return gKartAiShared->mKind1KartByRank[(((offset) + (rank))) - (0x1u)];
}

s32 GetFirstRankProgressRatio(void) {
    return gKartAiShared->mFirstRankProgressRatio;
}

s32 GetFirstKind1KartByRank(void) {
    return gKartAiShared->mKind1KartByRank[0];
}

s32 GetKind1KartAheadOfRank(s32 rank) {
    s32 listIndex = rank - 2;
    s32 result = -1;

    if (listIndex >= 0) {
        result = gKartAiShared->mKind1KartByRank[listIndex];
    }
    return result;
}

s32 GetKartAtNonCpuRank(void) {
    return gKartAiShared->mNonCpuKartByRank[((gKartAiShared->mNonCpuRank)) - (0x1u)];
}

KartAiParamRow *GetKartAiParamRow(void) {
    return gKartAiParamRow;
}

s32 GetKartIndexAtRank(u32 rank) {
    return gKartAiShared->mKartAtRank[(rank) - (0x1u)];
}

u32 GetKartAiTableIndex(u32 kartIndex) {
    return (gKartAiShared->mTableIndex[kartIndex]);
}

u32 GetKartAiEngineOrDifficultyIndex(void) {
    return (gKartAiShared->mEngineOrDifficultyIndex);
}

// Race progress times CourseMap.mUnk_108 as a 1.12 fixed-point product, rounded.
s32 GetKartRaceProgressScaled(u32 kartIndex) {
    s32 checkpointSumQuotient;
    s32 raceProgress;
    checkpointSumQuotient = gCourseMap->mCheckpointSumQuotient;
    raceProgress = GetKartRaceProgress(kartIndex);
    return MUL_FIXED12_ROUNDED(raceProgress, checkpointSumQuotient);
}

BOOL IsOneKartNotHumanOrPeer(void) {
    return (gKartAiShared->mOneKartNotHumanOrPeer);
}

RandomState64 *GetKartAiRandom(void) {
    return gKartAiShared->mRandom;
}
