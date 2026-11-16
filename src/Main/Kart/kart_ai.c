#include "Main/Kart/kart_ai.h"

#include "Main/Race/race_progress_lap.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "fixed_vector_math.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/cup_records.h"
#include "Main/Kart/kart_ai_follow.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "linked_list_ops.h"
#include "linked_list_init.h"
#include "Main/Race/race_clock.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

KartAiParamRow *g_KartAIParamPtr;
KartAiShared *g_GlobalAEBC;

// Picks the row of 'kartAIparam.bin' for the course and mode; none in battle or when RaceSetup.mRaceKind is 5 or 6.
void MaybeLoadKartAIData_from_thumb(void) {
    RaceSetup *raceSetup;
    KartAiParamRow *paramRow;
    g_KartAIParamPtr = NULL;
    raceSetup = g_GlobalCO;
    if (raceSetup->mRaceKind != RACE_KIND_AWARD && raceSetup->mMode != MODE_BATTLE &&
        raceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        paramRow = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("kartAIparam.bin");
        raceSetup = g_GlobalCO;
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
        g_KartAIParamPtr = paramRow;
    }
}

void CreateGlobalAEBC_from_thumb(void) {
    u16 kartIndex;
    BOOL zero;
    s32 minusOne;
    g_GlobalAEBC = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*g_GlobalAEBC));
    zero = FALSE;
    minusOne = -1;
    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        g_GlobalAEBC->mRaceProgressScaled[kartIndex] = zero;
        g_GlobalAEBC->mKartAtRank[kartIndex] = minusOne;
        g_GlobalAEBC->mCpuKartByRank[kartIndex] = minusOne;
        g_GlobalAEBC->mNonCpuKartByRank[kartIndex] = minusOne;
        g_GlobalAEBC->mTableIndex[kartIndex] = zero;
    }
    g_GlobalAEBC->mLastRankCpuKart = minusOne;
    g_GlobalAEBC->mLastRankNotCpuKart = minusOne;
    g_GlobalAEBC->mFirstRankNotCpuKart = minusOne;
    g_GlobalAEBC->mFirstRankProgressRatio = zero;
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
        g_GlobalAEBC->mRandom = &g_GlobalMV->mLocalRandom;
    } else {
        g_GlobalAEBC->mRandom = &g_GlobalMV->mRandom;
    }
    if (g_GlobalCO->mKartCount > 1 && g_GlobalCO->mKartCount - g_GlobalCO->mHumanAndPeerKartCount == 1) {
        g_GlobalAEBC->mOneKartNotHumanOrPeer = 1;
        g_GlobalAEBC->mNonCpuRank = ((u32) g_GlobalCO->mHumanAndPeerKartCount >> 1) + 1;
    } else {
        g_GlobalAEBC->mOneKartNotHumanOrPeer = 0;
        g_GlobalAEBC->mNonCpuRank = -1;
    }
    if (g_KartAIParamPtr != NULL) {
        InitKartAiGrandPrixPoints();
        InitKartAiTableIndices();
        if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
            switch (g_GlobalCO->mEngineIndex) {
                case ENGINE_CLASS_SLOW:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_LOW;
                    break;
                case ENGINE_CLASS_MEDIUM:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_MEDIUM;
                    break;
                case ENGINE_CLASS_FAST:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_HIGH;
                    break;
                default:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_MEDIUM;
                    break;
            }
        } else {
            switch (g_GlobalCO->mCpuDifficulty) {
                case CPU_DIFFICULTY_EASY:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_LOW;
                    break;
                case CPU_DIFFICULTY_NORMAL:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_MEDIUM;
                    break;
                case CPU_DIFFICULTY_HARD:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_HIGH;
                    break;
                default:
                    g_GlobalAEBC->mEngineOrDifficultyIndex = KART_AI_LEVEL_MEDIUM;
                    break;
            }
        }
        g_KartAIParamPtr->mGapTableScale = FX_Div(g_KartAIParamPtr->mGapTableScale, 0x3000);
    }
    InitKartAiNonCpuCounts();
    SetupKartAiGlobals();
    InitKartAiTables();
    SetupRaceItemEntries();
    if (g_GlobalCO->mMode == MODE_BATTLE) {
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
    g_GlobalAEBC->mNonCpuKartCount = kartIndex;
    for (teamIndex = 0; teamIndex < 2; teamIndex++) {
        g_GlobalAEBC->mTeamNonCpuKartCounts[teamIndex] = kartIndex;
    }
    for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
        if (g_GlobalCO->mUseTeams != 0) {
            for (teamIndex = 0; teamIndex < 2; teamIndex++) {
                isNonCpu = FALSE;
                if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind > PLAYER_KIND_PEER) {
                } else if ((1 << g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind) &
                           PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    isNonCpu = TRUE;
                }
                if (isNonCpu != FALSE && teamIndex == g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                    g_GlobalAEBC->mTeamNonCpuKartCounts[teamIndex]++;
                    break;
                }
            }
        } else {
            isNonCpuWithoutTeams = FALSE;
            player = &g_GlobalCO->mCurrentEntries[kartIndex].mPlayer;
            if (player->mKind <= PLAYER_KIND_PEER && ((1 << player->mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isNonCpuWithoutTeams = TRUE;
            }
            if (isNonCpuWithoutTeams != FALSE) {
                g_GlobalAEBC->mNonCpuKartCount++;
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
        g_GlobalAEBC->mListedCpuKartPoints[clearIndex] = 0;
    }
    g_GlobalAEBC->mPointsGapKind = KART_AI_POINTS_GAP_NONE;
    g_GlobalAEBC->mLowerPointsListedCpuIndex = 0;
    if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
        for (entryIndex = 0; entryIndex < g_GlobalCO->mKartCount; entryIndex++) {
            kartIndex = entryIndex;
            previousTotalPoints = GetKartPreviousTotalPoints(kartIndex);
            isNonCpu = FALSE;
            if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind <= PLAYER_KIND_PEER &&
                ((1 << g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
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
                if (entryIndex == g_GlobalCO->mListedCpuEntryIndices[0]) {
                    g_GlobalAEBC->mListedCpuKartPoints[0] = previousTotalPoints;
                } else if (entryIndex == g_GlobalCO->mListedCpuEntryIndices[1]) {
                    g_GlobalAEBC->mListedCpuKartPoints[1] = previousTotalPoints;
                }
            }
        }
        pointsDifference = bestNonCpuPoints - bestCpuPoints;
        if (pointsDifference <= -5) {
            if (g_GlobalCO->mListedCpuCount > 1) {
                g_GlobalAEBC->mPointsGapKind = KART_AI_POINTS_GAP_NON_CPU_BEHIND;
                if (g_GlobalAEBC->mListedCpuKartPoints[0] > g_GlobalAEBC->mListedCpuKartPoints[1]) {
                    g_GlobalAEBC->mLowerPointsListedCpuIndex = 1;
                }
            }
        } else if (g_GlobalCO->mCpuDifficulty != CPU_DIFFICULTY_EASY && pointsDifference >= 4) {
            g_GlobalAEBC->mPointsGapKind = KART_AI_POINTS_GAP_NON_CPU_AHEAD;
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
    nextNonCpuTableIndex = g_GlobalCO->mKartCount;
    IntrusiveListWrapper_InitializeEmpty(&g_GlobalAEBC->mTableIndexList, 4);
    for (listedIndex = 0; listedIndex < 2; listedIndex++) {
        if (g_GlobalCO->mListedCpuEntryIndices[listedIndex] >= 0) {
            count++;
        }
    }
    kartCount = g_GlobalCO->mKartCount;
    for (kartIndex = 0; (u32) kartIndex < kartCount; kartIndex++) {
        isNonCpu = FALSE;
        if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind <= PLAYER_KIND_PEER &&
            ((1 << g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isNonCpu = TRUE;
        }
        if (isNonCpu != FALSE) {
            nonCpuKartCount++;
        }
    }
    tableEntryCount = kartCount - nonCpuKartCount - count;
    tableEntryIndex = 0;
    for (; tableEntryIndex < tableEntryCount; tableEntryIndex++) {
        g_GlobalAEBC->mTableIndexEntries[tableEntryIndex].mTableIndex = (u16) (tableEntryIndex + count + 1);
        IntrusiveListWrapper_InsertLast(&g_GlobalAEBC->mTableIndexList, &g_GlobalAEBC->mTableIndexEntries[tableEntryIndex]);
    }
    count = 0;
    raceSetup = g_GlobalCO;
    for (; (u32) count < raceSetup->mKartCount; count++) {
        if (raceSetup->mMode == MODE_TIME_ATTACK) {
            tableIndex = count;
        } else {
            tableIndex = PickKartAiTableIndex(count, &nextNonCpuTableIndex);
        }
        g_GlobalAEBC->mTableIndex[count] = tableIndex;
        raceSetup = g_GlobalCO;
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
    kartAiShared = g_GlobalAEBC;
    pointsGapKind = kartAiShared->mPointsGapKind;
    if (pointsGapKind == KART_AI_POINTS_GAP_NON_CPU_AHEAD) {
        isNonCpuAhead = TRUE;
    } else {
        isNonCpuAhead = FALSE;
    }
    isNonCpu = FALSE;
    raceSetup = g_GlobalCO;
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
            tableIndexList = &g_GlobalAEBC->mTableIndexList;
            listCount = tableIndexList->mCount;
            random = g_GlobalAEBC->mRandom;
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
            entry = IntrusiveListWrapper_GetAtIndex(tableIndexList, listPosition);
            tableIndex = entry->mTableIndex;
            IntrusiveListWrapper_RemoveItem(tableIndexList, entry);
        }
    }
    return tableIndex;
}

#pragma thumb off

void DecrementKartAiNonCpuCount(u32 kartIndex) {
    RaceSetup *raceSetup;
    BOOL isNonCpu;
    s16 teamIndex;
    raceSetup = g_GlobalCO;
    isNonCpu = FALSE;
    if (raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind <= PLAYER_KIND_PEER &&
        ((1 << raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
        isNonCpu = TRUE;
    }
    if (isNonCpu == FALSE) {
        return;
    }
    if (raceSetup->mUseTeams != 0) {
        for (teamIndex = 0; teamIndex < 2; teamIndex++) {
            if (teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                if (g_GlobalAEBC->mTeamNonCpuKartCounts[teamIndex] > 0) {
                    g_GlobalAEBC->mTeamNonCpuKartCounts[teamIndex]--;
                }
                break;
            }
        }
    } else {
        if (g_GlobalAEBC->mNonCpuKartCount > 0) {
            g_GlobalAEBC->mNonCpuKartCount--;
        }
    }
}

s16 GetNonCpuKartCountOutsideKartTeam(u32 kartIndex) {
    s16 count;
    u16 teamIndex;
    count = 0;
    if (g_GlobalCO->mUseTeams != 0) {
        for (teamIndex = 0; teamIndex < 2; teamIndex++) {
            if (teamIndex != g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                count = count + g_GlobalAEBC->mTeamNonCpuKartCounts[teamIndex];
            }
        }
    } else {
        count = g_GlobalAEBC->mNonCpuKartCount;
    }
    return count;
}

void UpdateKartAiShared(void) {
    u32 maxRank;
    u16 kartIndex;
    u32 kartRank;
    if (g_KartAIParamPtr == NULL) {
        return;
    }
    UpdateKartAiRankLists();
    maxRank = 1;
    for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
        kartRank = GetSomeRacerFlags(kartIndex);
        if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (kartRank == 1) {
                g_GlobalAEBC->mFirstRankNotCpuKart = kartIndex;
            }
            if (kartRank >= maxRank) {
                maxRank = kartRank;
                g_GlobalAEBC->mLastRankNotCpuKart = kartIndex;
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
    for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
        scaledProgress = g_GlobalPE->mCheckpointSumQuotient;
        value = GetSomeRacerValue(kartIndex);
        scaledProgress = MUL_FIXED12_ROUNDED(value, scaledProgress);
        kartRank = GetSomeRacerFlags(kartIndex);
        g_GlobalAEBC->mRaceProgressScaled[kartIndex] = scaledProgress;
        if (kartRank > 0) {
            index = kartRank - 1;
            if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
                if (kartRank > maxCpuRank) {
                    maxCpuRank = kartRank;
                    g_GlobalAEBC->mLastRankCpuKart = kartIndex;
                }
            }
            g_GlobalAEBC->mKartAtRank[index] = kartIndex;
        }
        if (kartRank == 1) {
            if (scaledProgress >= 0) {
                g_GlobalAEBC->mFirstRankProgressRatio = FX_Div(g_GlobalAEBC->mRaceProgressScaled[kartIndex], 0x4ce);
                if (g_GlobalAEBC->mFirstRankProgressRatio < KART_AI_FIRST_RANK_RATIO_MIN) {
                    g_GlobalAEBC->mFirstRankProgressRatio = KART_AI_FIRST_RANK_RATIO_MIN;
                } else if (g_GlobalAEBC->mFirstRankProgressRatio > TO_FIXED12(1)) {
                    g_GlobalAEBC->mFirstRankProgressRatio = TO_FIXED12(1);
                }
            } else {
                g_GlobalAEBC->mFirstRankProgressRatio = 0;
            }
        }
    }
    listCount = 0;
    for (rankIndex = 0; rankIndex < g_GlobalCO->mKartCount; rankIndex++) {
        value = g_GlobalAEBC->mKartAtRank[rankIndex];
        if (value >= 0) {
            index = value;
            if (g_GlobalCO->mCurrentEntries[index].mPlayer.mKind == PLAYER_KIND_CPU) {
                g_GlobalAEBC->mCpuKartByRank[listCount] = value;
                listCount++;
            }
        }
    }
    if (g_GlobalAEBC->mOneKartNotHumanOrPeer == 0) {
        return;
    }
    listCount = 0;
    for (rankIndex = 0; rankIndex < g_GlobalCO->mKartCount; rankIndex++) {
        kartAtRank = g_GlobalAEBC->mKartAtRank[rankIndex];
        if (kartAtRank >= 0) {
            index = kartAtRank;
            isNonCpu = FALSE;
            if (g_GlobalCO->mCurrentEntries[index].mPlayer.mKind <= PLAYER_KIND_PEER &&
                ((1 << g_GlobalCO->mCurrentEntries[index].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isNonCpu = TRUE;
            }
            if (isNonCpu != FALSE) {
                g_GlobalAEBC->mNonCpuKartByRank[listCount] = kartAtRank;
                listCount++;
            }
        }
    }
}

s32 GetKartRankAmongCpuKarts(u16 kartIndex) {
    s32 rank;
    u16 rankIndex;
    rank = -1;
    for (rankIndex = 0; (u32) rankIndex < g_GlobalCO->mKartCount; rankIndex++) {
        if (kartIndex == (u16) g_GlobalAEBC->mCpuKartByRank[rankIndex]) {
            rank = rankIndex + 1;
            break;
        }
    }
    return rank;
}

s32 GetCpuKartByRankPlusOffset(u32 rank, u32 offset) {
    return g_GlobalAEBC->mCpuKartByRank[(((offset) + (rank))) - (0x1u)];
}

s32 GetFirstRankProgressRatio(void) {
    return g_GlobalAEBC->mFirstRankProgressRatio;
}

s32 GetFirstCpuKartByRank(void) {
    return g_GlobalAEBC->mCpuKartByRank[0];
}

s32 GetCpuKartAheadOfRank(s32 rank) {
    s32 listIndex = rank - 2;
    s32 result = -1;

    if (listIndex >= 0) {
        result = g_GlobalAEBC->mCpuKartByRank[listIndex];
    }
    return result;
}

s32 GetKartAtNonCpuRank(void) {
    return g_GlobalAEBC->mNonCpuKartByRank[((g_GlobalAEBC->mNonCpuRank)) - (0x1u)];
}

KartAiParamRow *GetKartAiParamRow(void) {
    return g_KartAIParamPtr;
}

s32 GetKartIndexAtRank(u32 rank) {
    return g_GlobalAEBC->mKartAtRank[(rank) - (0x1u)];
}

u32 GetKartAiTableIndex(u32 kartIndex) {
    return (g_GlobalAEBC->mTableIndex[kartIndex]);
}

u32 GetKartAiEngineOrDifficultyIndex(void) {
    return (g_GlobalAEBC->mEngineOrDifficultyIndex);
}

// Race progress times CourseMap.mUnk_108 as a 1.12 fixed-point product, rounded.
s32 GetKartRaceProgressScaled(u16 kartIndex) {
    s32 checkpointSumQuotient;
    s32 raceProgress;
    checkpointSumQuotient = g_GlobalPE->mCheckpointSumQuotient;
    raceProgress = GetSomeRacerValue(kartIndex);
    return MUL_FIXED12_ROUNDED(raceProgress, checkpointSumQuotient);
}

BOOL IsOneKartNotHumanOrPeer(void) {
    return (g_GlobalAEBC->mOneKartNotHumanOrPeer);
}

RandomState64 *GetKartAiRandom(void) {
    return g_GlobalAEBC->mRandom;
}
