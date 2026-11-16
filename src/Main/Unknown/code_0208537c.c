#include "Main/Unknown/code_0208537c.h"

#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_020172d0.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_0203c8dc.h"

#pragma thumb on

// Picks the row of 'kartAIparam.bin' for the course and the mode; no row in battle and when fieldC is 5 or 6.
void loadKartAIParams(void) {
    RaceSetup *raceSetup;
    KartAiParamRow *r;
    gKartAiParamRow = NULL;
    raceSetup = gRaceMultiConfig;
    if (raceSetup->mRaceKind != RACE_KIND_AWARD && raceSetup->mMode != MODE_BATTLE &&
        raceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        r = arc_getKartModelArcFileSafe(aKartaiparam_bi);
        raceSetup = gRaceMultiConfig;
        if (raceSetup->mMode == MODE_GRAND_PRIX) {
            r = &r[(raceSetup->mCourseId - 1) * 12 + raceSetup->mEngineIndex];
        } else {
            r = &r[(raceSetup->mCourseId - 1) * 12 + (raceSetup->mEngineIndex + 1) * 3];
            switch (raceSetup->mCpuDifficulty) {
                case CPU_DIFFICULTY_NORMAL:
                    r++;
                    break;
                case CPU_DIFFICULTY_HARD:
                    r += 2;
                    break;
            }
        }
        gKartAiParamRow = r;
    }
}

void InitKartAiShared(void) {
    u16 i;
    BOOL zero;
    s32 minusOne;
    gKartAiShared = heap_alloc(proc_getHeap(proc_getCurrent()), 0x144);
    zero = FALSE;
    minusOne = -1;
    for (i = 0; i < 8; i++) {
        gKartAiShared->mRaceProgressScaled[i] = zero;
        gKartAiShared->mKartAtRank[i] = minusOne;
        gKartAiShared->mKind1KartByRank[i] = minusOne;
        gKartAiShared->mNonCpuKartByRank[i] = minusOne;
        gKartAiShared->mTableIndex[i] = zero;
    }
    gKartAiShared->field80 = minusOne;
    gKartAiShared->field84 = minusOne;
    gKartAiShared->field88 = minusOne;
    gKartAiShared->field8C = zero;
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        gKartAiShared->mRandom = &gRaceStatus->mLocalRandom;
    } else {
        gKartAiShared->mRandom = &gRaceStatus->mRandom;
    }
    if (gRaceMultiConfig->mKartCount > 1 && gRaceMultiConfig->mKartCount - gRaceMultiConfig->mHumanAndPeerKartCount == 1) {
        gKartAiShared->field120 = 1;
        gKartAiShared->field124 = ((u32) gRaceMultiConfig->mHumanAndPeerKartCount >> 1) + 1;
    } else {
        gKartAiShared->field120 = 0;
        gKartAiShared->field124 = -1;
    }
    if (gKartAiParamRow != NULL) {
        func_02085bec();
        InitKartAiTableIndices();
        if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
            switch (gRaceMultiConfig->mEngineIndex) {
                case 0:
                    gKartAiShared->field138 = 0;
                    break;
                case 1:
                    gKartAiShared->field138 = 1;
                    break;
                case 2:
                    gKartAiShared->field138 = 2;
                    break;
                default:
                    gKartAiShared->field138 = 1;
                    break;
            }
        } else {
            switch (gRaceMultiConfig->mCpuDifficulty) {
                case CPU_DIFFICULTY_EASY:
                    gKartAiShared->field138 = 0;
                    break;
                case CPU_DIFFICULTY_NORMAL:
                    gKartAiShared->field138 = 1;
                    break;
                case CPU_DIFFICULTY_HARD:
                    gKartAiShared->field138 = 2;
                    break;
                default:
                    gKartAiShared->field138 = 1;
                    break;
            }
        }
        gKartAiParamRow->field4 = FX_Div(gKartAiParamRow->field4, 0x3000);
    }
    InitKartAiNonCpuCounts();
    func_0207fba0();
    InitKartAiTables();
    enit_setupFunctions();
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        SetupBattleKartAiParams();
        mgenit_setupFunctions();
    }
}

void InitKartAiNonCpuCounts(void) {
    u16 j;
    u16 teamIndex;
    BOOL isNonCpu;
    BOOL isNonCpuWithoutTeams;
    KartEntryPlayer *player;
    j = 0;
    gKartAiShared->mNonCpuKartCount = j;
    for (teamIndex = 0; teamIndex < 2; teamIndex++) {
        gKartAiShared->mTeamNonCpuKartCounts[teamIndex] = j;
    }
    for (j = 0; (u32) j < gRaceMultiConfig->mKartCount; j++) {
        if (gRaceMultiConfig->mUseTeams != 0) {
            for (teamIndex = 0; teamIndex < 2; teamIndex++) {
                isNonCpu = FALSE;
                if (gRaceMultiConfig->mCurrentEntries[j].mPlayer.mKind > 3) {
                } else if ((1 << gRaceMultiConfig->mCurrentEntries[j].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    isNonCpu = TRUE;
                }
                if (isNonCpu != FALSE && teamIndex == gRaceMultiConfig->mCurrentEntries[j].mPlayer.mTeamIndex) {
                    gKartAiShared->mTeamNonCpuKartCounts[teamIndex]++;
                    break;
                }
            }
        } else {
            isNonCpuWithoutTeams = FALSE;
            player = &gRaceMultiConfig->mCurrentEntries[j].mPlayer;
            if (player->mKind <= 3 && ((1 << player->mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isNonCpuWithoutTeams = TRUE;
            }
            if (isNonCpuWithoutTeams != FALSE) {
                gKartAiShared->mNonCpuKartCount++;
            }
        }
    }
}

void func_02085bec(void) {
    u16 clearIndex;
    s32 bestNonCpuPoints;
    s32 bestCpuPoints;
    s16 i;
    u16 kartIndex;
    s32 previousTotalPoints;
    BOOL isNonCpu;
    s32 pointsDifference;

    clearIndex = 0;
    bestNonCpuPoints = 0;
    bestCpuPoints = 0;
    for (; clearIndex < 2; clearIndex++) {
        gKartAiShared->field114[clearIndex] = 0;
    }
    gKartAiShared->field110 = 1;
    gKartAiShared->field11C = 0;
    if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
        for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
            kartIndex = i;
            previousTotalPoints = rres_getTotalRankPoints(kartIndex);
            isNonCpu = FALSE;
            if (gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mKind <= 3 &&
                ((1 << gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
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
                if (i == gRaceMultiConfig->field3D5[0]) {
                    gKartAiShared->field114[0] = previousTotalPoints;
                } else if (i == gRaceMultiConfig->field3D5[1]) {
                    gKartAiShared->field114[1] = previousTotalPoints;
                }
            }
        }
        pointsDifference = bestNonCpuPoints - bestCpuPoints;
        if (pointsDifference <= -5) {
            if (gRaceMultiConfig->field3D4 > 1) {
                gKartAiShared->field110 = 0;
                if (gKartAiShared->field114[0] > gKartAiShared->field114[1]) {
                    gKartAiShared->field11C = 1;
                }
            }
        } else if (gRaceMultiConfig->mCpuDifficulty != CPU_DIFFICULTY_EASY && pointsDifference >= 4) {
            gKartAiShared->field110 = 2;
        }
    }
}

void InitKartAiTableIndices(void) {
    u16 a;
    u16 nonCpuKartCount;
    u16 i;
    u16 kartIndex;
    u16 kartCount;
    u16 tableEntryCount;
    u16 tableEntryIndex;
    RaceSetup *raceSetup;
    s32 tableIndex;
    BOOL isNonCpu;
    u32 nextNonCpuTableIndex;
    a = 0;
    nonCpuKartCount = 0;
    nextNonCpuTableIndex = gRaceMultiConfig->mKartCount;
    NNS_FndInitList(&gKartAiShared->mTableIndexList, 4);
    for (i = 0; i < 2; i++) {
        if (gRaceMultiConfig->field3D5[i] >= 0) {
            a++;
        }
    }
    kartCount = gRaceMultiConfig->mKartCount;
    for (kartIndex = 0; (u32) kartIndex < kartCount; kartIndex++) {
        isNonCpu = FALSE;
        if (gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mKind <= 3 &&
            ((1 << gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isNonCpu = TRUE;
        }
        if (isNonCpu != FALSE) {
            nonCpuKartCount++;
        }
    }
    tableEntryCount = kartCount - nonCpuKartCount - a;
    tableEntryIndex = 0;
    for (; tableEntryIndex < tableEntryCount; tableEntryIndex++) {
        gKartAiShared->mTableIndexEntries[tableEntryIndex].mTableIndex = (u16) (tableEntryIndex + a + 1);
        NNS_FndAppendListObject(&gKartAiShared->mTableIndexList, &gKartAiShared->mTableIndexEntries[tableEntryIndex]);
    }
    a = 0;
    raceSetup = gRaceMultiConfig;
    for (; (u32) a < raceSetup->mKartCount; a++) {
        if (raceSetup->mMode == MODE_TIME_ATTACK) {
            tableIndex = a;
        } else {
            tableIndex = PickKartAiTableIndex(a, &nextNonCpuTableIndex);
        }
        gKartAiShared->mTableIndex[a] = tableIndex;
        raceSetup = gRaceMultiConfig;
    }
}

s32 PickKartAiTableIndex(u16 kartIndex, u32 *nextNonCpuTableIndexPointer) {
    s32 tableIndex;
    BOOL hasFixedIndex;
    BOOL g;
    BOOL isNonCpu;
    s32 s;
    s32 m;
    s32 otherIndex;
    u16 k;
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
    m = kartAiShared->field110;
    if (m == 2) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    isNonCpu = FALSE;
    raceSetup = gRaceMultiConfig;
    s = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if ((u32) s <= 3 && ((1 << s) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
        isNonCpu = TRUE;
    }
    if (isNonCpu != FALSE) {
        tableIndex = *nextNonCpuTableIndexPointer;
        *nextNonCpuTableIndexPointer = tableIndex - 1;
    } else {
        if (m == 0) {
            s = kartAiShared->field11C;
            if (s != 0) {
                s = 1;
            } else {
                s = 0;
            }
            if (s == 0) {
                otherIndex = 1;
            } else {
                otherIndex = 0;
            }
            if (kartIndex == raceSetup->field3D5[s]) {
                tableIndex = 1;
                hasFixedIndex = TRUE;
            } else if (kartIndex == (u16) raceSetup->field3D5[otherIndex]) {
                tableIndex = 2;
                hasFixedIndex = TRUE;
            }
        } else {
            for (k = 0; k < 2; k++) {
                s = raceSetup->field3D5[k];
                if (s == kartIndex) {
                    if (k == 0) {
                        tableIndex = 1;
                    } else {
                        tableIndex = 2;
                        if (g != FALSE) {
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
    raceSetup = gRaceMultiConfig;
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

s16 func_02085824(u32 kartIndex) {
    s16 count;
    u16 teamIndex;
    count = 0;
    if (gRaceMultiConfig->mUseTeams != 0) {
        for (teamIndex = 0; teamIndex < 2; teamIndex++) {
            if (teamIndex != gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
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
    u16 i;
    u32 kartRank;
    if (gKartAiParamRow == NULL) {
        return;
    }
    UpdateKartAiRankLists();
    maxRank = 1;
    for (i = 0; (u32) i < gRaceMultiConfig->mKartCount; i++) {
        kartRank = rstat_getPlace(i);
        if (gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (kartRank == 1) {
                gKartAiShared->field88 = i;
            }
            if (kartRank >= maxRank) {
                maxRank = kartRank;
                gKartAiShared->field84 = i;
            }
        }
    }
}

void UpdateKartAiRankLists(void) {
    s32 maxCpuRank;
    u16 i;
    s32 kartRank;
    s32 w;
    s32 listCount;
    s32 rankIndex;
    s32 x;
    s32 kartAtRank;
    u16 q;
    BOOL isNonCpu;
    maxCpuRank = 1;
    for (i = 0; (u32) i < gRaceMultiConfig->mKartCount; i++) {
        w = gMapData->mCheckpointSumQuotient;
        x = rstat_getRaceProgress(i);
        w = ((s64) x * w + 0x800) >> 12;
        kartRank = rstat_getPlace(i);
        gKartAiShared->mRaceProgressScaled[i] = w;
        if (kartRank > 0) {
            q = kartRank - 1;
            if (gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_CPU) {
                if (kartRank > maxCpuRank) {
                    maxCpuRank = kartRank;
                    gKartAiShared->field80 = i;
                }
            }
            gKartAiShared->mKartAtRank[q] = i;
        }
        if (kartRank == 1) {
            if (w >= 0) {
                gKartAiShared->field8C = FX_Div(gKartAiShared->mRaceProgressScaled[i], 0x4ce);
                if (gKartAiShared->field8C < 0x19a) {
                    gKartAiShared->field8C = 0x19a;
                } else if (gKartAiShared->field8C > 0x1000) {
                    gKartAiShared->field8C = 0x1000;
                }
            } else {
                gKartAiShared->field8C = 0;
            }
        }
    }
    listCount = 0;
    for (rankIndex = 0; rankIndex < gRaceMultiConfig->mKartCount; rankIndex++) {
        x = gKartAiShared->mKartAtRank[rankIndex];
        if (x >= 0) {
            q = x;
            if (gRaceMultiConfig->mCurrentEntries[q].mPlayer.mKind == PLAYER_KIND_CPU) {
                gKartAiShared->mKind1KartByRank[listCount] = x;
                listCount++;
            }
        }
    }
    if (gKartAiShared->field120 == 0) {
        return;
    }
    listCount = 0;
    for (rankIndex = 0; rankIndex < gRaceMultiConfig->mKartCount; rankIndex++) {
        kartAtRank = gKartAiShared->mKartAtRank[rankIndex];
        if (kartAtRank >= 0) {
            q = kartAtRank;
            isNonCpu = FALSE;
            if (gRaceMultiConfig->mCurrentEntries[q].mPlayer.mKind <= 3 &&
                ((1 << gRaceMultiConfig->mCurrentEntries[q].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
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
    u16 i;
    rank = -1;
    for (i = 0; (u32) i < gRaceMultiConfig->mKartCount; i++) {
        if (kartIndex == (u16) gKartAiShared->mKind1KartByRank[i]) {
            rank = i + 1;
            break;
        }
    }
    return rank;
}

s32 func_020854a0(u32 p0, u32 p1) {
    return gKartAiShared->mKind1KartByRank[(((p1) + (p0))) - (0x1u)];
}

s32 func_0208548c(void) {
    return gKartAiShared->field8C;
}

s32 GetFirstKind1KartByRank(void) {
    return gKartAiShared->mKind1KartByRank[0];
}

s32 func_02085458(s32 a) {
    s32 listIndex = a - 2;
    s32 result = -1;

    if (listIndex >= 0) {
        result = gKartAiShared->mKind1KartByRank[listIndex];
    }
    return result;
}

s32 func_02085434(void) {
    return gKartAiShared->mNonCpuKartByRank[((gKartAiShared->field124)) - (0x1u)];
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

u32 func_020853dc(void) {
    return (gKartAiShared->field138);
}

// Race progress times CourseMap.field108 as a 1.12 fixed-point product, rounded.
s32 GetKartRaceProgressScaled(u32 kartIndex) {
    s32 checkpointSumQuotient;
    s32 raceProgress;
    checkpointSumQuotient = gMapData->mCheckpointSumQuotient;
    raceProgress = rstat_getRaceProgress(kartIndex);
    return ((s64) raceProgress * checkpointSumQuotient + 0x800) >> 12;
}

BOOL func_02085390(void) {
    return (gKartAiShared->field120);
}

RandomState64 *GetKartAiRandom(void) {
    return gKartAiShared->mRandom;
}
