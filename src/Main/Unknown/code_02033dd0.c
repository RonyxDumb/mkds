#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"

// Reads the table of gCupRecords, a row chosen by one call and a column by another.
static inline KartCourseResult *ResultsBattleGetKartCourseResult(u32 entryIndex) {
    return &gCupRecords->mKartResults[GetCourseIndexInCup()][GetLowByte(entryIndex)];
}

#pragma thumb on

void WriteGhostGetScanRegisters(void) {
    s16 offset;
    u32 subWinOutBits;
    u32 subWinInBits;
    s32 negatedOffset;
    s32 mainWinInBits;

    offset = GetInterpolatedValue(&gTimeAttackGhostGetScan->mInterpolation);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    switch (offset) {
        default:
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
            mainWinInBits = (reg_G2_WININ & ~0x3f) | 0x1f;
            reg_G2_WININ = mainWinInBits | 0x20;
            reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
            reg_G2_WIN0H = 0xff;
            reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
            subWinInBits = (reg_G2S_DB_WININ & ~0x3f) | 0x1f;
            reg_G2S_DB_WININ = subWinInBits | 0x20;
            subWinOutBits = (reg_G2S_DB_WINOUT & ~0x3f) | 7;
            reg_G2S_DB_WINOUT = subWinOutBits | 0x20;
            reg_G2S_DB_WIN0H = 0xff;
            reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
            break;
        case 0:
            reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
            break;
    }
}

void AssignResultsBattleTeamOrder(void) {
    ResultsBattle *resultsBattle;
    s32 nextOrderIndex;
    s32 team1Count;
    s32 entryIndex;

    nextOrderIndex = 0;
    team1Count = 0;
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 0) {
            gResultsBattle->mEntries[entryIndex].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            team1Count++;
        }
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            gResultsBattle->mEntries[entryIndex].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
}

void AssignResultsBattleTeamOrderByScore(void) {
    ResultsBattle *resultsBattle;
    s32 scores[8];
    s32 team0Entries[8];
    s32 team1Entries[8];
    s32 team0BestIndex;
    s32 nextOrderIndex;
    s32 memberIndex;
    s32 team0Count;
    s32 kartIndex;
    s32 team1Count;
    s32 team1Step;
    s32 team0BestScore;
    s32 team0Step;
    s32 team1BestScore;
    s32 team1BestIndex;

    nextOrderIndex = 0;
    team0Count = 0;
    team1Count = 0;
    for (kartIndex = 0; kartIndex < (resultsBattle = gResultsBattle)->mKartCount; kartIndex++) {
        scores[kartIndex] = resultsBattle->mEntries[kartIndex].mScore;
    }
    for (kartIndex = 0; kartIndex < (resultsBattle = *(ResultsBattle **) &gResultsBattle)->mKartCount; kartIndex++) {
        if (GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 0) {
            team0Entries[team0Count] = kartIndex;
            team0Count = team0Count + 1;
        } else {
            team1Entries[team1Count] = kartIndex;
            team1Count = team1Count + 1;
        }
    }
    for (team0Step = 0; team0Step < team0Count; team0Step++) {
        team0BestScore = -1;
        team0BestIndex = -1;
        for (memberIndex = 0; memberIndex < team0Count; memberIndex++) {
            if (team0BestScore < scores[team0Entries[memberIndex]]) {
                team0BestScore = scores[team0Entries[memberIndex]];
                team0BestIndex = memberIndex;
            }
        }
        gResultsBattle->mEntries[team0Entries[team0BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team0Entries[team0BestIndex]] = -2;
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (team1Step = 0; team1Step < team1Count; team1Step++) {
        team1BestScore = -1;
        team1BestIndex = -1;
        for (memberIndex = 0; memberIndex < team1Count; memberIndex++) {
            if (team1BestScore < scores[team1Entries[memberIndex]]) {
                team1BestScore = scores[team1Entries[memberIndex]];
                team1BestIndex = memberIndex;
            }
        }
        gResultsBattle->mEntries[team1Entries[team1BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team1Entries[team1BestIndex]] = -2;
    }
}

void FillResultsBattleEntries(void) {
    u16 rankKartIndex;
    u16 kartIndex;
    s32 higherCount;

    for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
        if (gResultsBattle->mMode == 3 || gRaceSetup->mRuleKind == 2) {
            gResultsBattle->mEntries[kartIndex].mScore =
                ResultsBattleGetKartCourseResult(GetLowByte(kartIndex))->mTotalPoints;
        } else {
            gResultsBattle->mEntries[kartIndex].mScore =
                ResultsBattleGetKartCourseResult(GetLowByte(kartIndex))->mWinCount;
        }
    }
    for (rankKartIndex = 0; rankKartIndex < gResultsBattle->mKartCount; rankKartIndex++) {
        higherCount = 0;
        for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
            if (rankKartIndex != kartIndex &&
                gResultsBattle->mEntries[rankKartIndex].mScore < gResultsBattle->mEntries[kartIndex].mScore) {
                higherCount++;
            }
        }
        gResultsBattle->mEntries[rankKartIndex].mRank = higherCount;
    }
    if (gRaceSetup->mUseTeams != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mRuleKind == 1) {
            AssignResultsBattleTeamOrder();
        } else {
            AssignResultsBattleTeamOrderByScore();
        }
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
            gResultsBattle->mEntries[kartIndex].mOrderIndex = gMenuShared->mUnk_ec[kartIndex];
        }
    } else {
        for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
            gResultsBattle->mEntries[kartIndex].mOrderIndex = GetKartCupRank(kartIndex) - 1;
        }
    }
}

s32 AreResultsBattleRanksAllZero(void) {
    s32 allRanksZero;
    s32 kartIndex;

    allRanksZero = 1;
    kartIndex = 0;
    for (; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
        allRanksZero &= gResultsBattle->mEntries[kartIndex].mRank == 0 ? 1 : 0;
    }
    return allRanksZero;
}

s32 IsResultsBattleTimerRunOut(void) {
    BOOL result;

    result = FALSE;
    if (gResultsBattle->mUseTimer != FALSE && gResultsBattle->mTimer == 0) {
        result = TRUE;
    }
    return result;
}

s32 IsResultsBattleTimerBelow300(void) {
    BOOL result;

    result = FALSE;
    if (gResultsBattle->mUseTimer != FALSE && gResultsBattle->mTimer < 0x12c) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off
