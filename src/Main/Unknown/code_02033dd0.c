#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"

// Reads the table of rres_sRaceResults, a row chosen by one call and a column by another.
static inline KartCourseResult *func_02033e6c_inline(u32 entryIndex) {
    return &rres_sRaceResults->mKartResults[rres_205DB28()][rres_205DC7C(entryIndex)];
}

#pragma thumb on

void func_02034244(void) {
    s16 offset;
    u32 b;
    u32 c;
    s32 negatedOffset;
    s32 e;

    offset = interp_interpolate(&sGhostReceiveState->field194);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    switch (offset) {
        default:
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
            e = (reg_G2_WININ & ~0x3f) | 0x1f;
            reg_G2_WININ = e | 0x20;
            reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
            reg_G2_WIN0H = 0xff;
            reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
            c = (reg_G2S_DB_WININ & ~0x3f) | 0x1f;
            reg_G2S_DB_WININ = c | 0x20;
            b = (reg_G2S_DB_WINOUT & ~0x3f) | 7;
            reg_G2S_DB_WINOUT = b | 0x20;
            reg_G2S_DB_WIN0H = 0xff;
            reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
            break;
        case 0:
            reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
            break;
    }
}

void bres_2034188(void) {
    ResultsBattle *o;
    s32 nextOrderIndex;
    s32 team1Count;
    s32 i;

    nextOrderIndex = 0;
    team1Count = 0;
    for (i = 0; i < bres_sState->mKartCount; i++) {
        if (gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 0) {
            bres_sState->mEntries[i].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
    for (i = 0; i < bres_sState->mKartCount; i++) {
        if (gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 1) {
            team1Count++;
        }
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (i = 0; i < bres_sState->mKartCount; i++) {
        if (gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 1) {
            bres_sState->mEntries[i].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
}

void bres_2034024(void) {
    ResultsBattle *o;
    s32 scores[8];
    s32 team0Entries[8];
    s32 team1Entries[8];
    s32 team0BestIndex;
    s32 nextOrderIndex;
    s32 k;
    s32 team0Count;
    s32 i;
    s32 team1Count;
    s32 j;
    s32 team0BestScore;
    s32 d;
    s32 team1BestScore;
    s32 team1BestIndex;

    nextOrderIndex = 0;
    team0Count = 0;
    team1Count = 0;
    for (i = 0; i < (o = bres_sState)->mKartCount; i++) {
        scores[i] = o->mEntries[i].mScore;
    }
    for (i = 0; i < (o = *(ResultsBattle **) &bres_sState)->mKartCount; i++) {
        if (gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 0) {
            team0Entries[team0Count] = i;
            team0Count = team0Count + 1;
        } else {
            team1Entries[team1Count] = i;
            team1Count = team1Count + 1;
        }
    }
    for (d = 0; d < team0Count; d++) {
        team0BestScore = -1;
        team0BestIndex = -1;
        for (k = 0; k < team0Count; k++) {
            if (team0BestScore < scores[team0Entries[k]]) {
                team0BestScore = scores[team0Entries[k]];
                team0BestIndex = k;
            }
        }
        bres_sState->mEntries[team0Entries[team0BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team0Entries[team0BestIndex]] = -2;
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (j = 0; j < team1Count; j++) {
        team1BestScore = -1;
        team1BestIndex = -1;
        for (k = 0; k < team1Count; k++) {
            if (team1BestScore < scores[team1Entries[k]]) {
                team1BestScore = scores[team1Entries[k]];
                team1BestIndex = k;
            }
        }
        bres_sState->mEntries[team1Entries[team1BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team1Entries[team1BestIndex]] = -2;
    }
}

void bres_2033E6C(void) {
    u16 j;
    u16 k;
    s32 higherCount;

    for (k = 0; k < bres_sState->mKartCount; k++) {
        if (bres_sState->mMode == 3 || gRaceMultiConfig->mRuleKind == 2) {
            bres_sState->mEntries[k].mScore = func_02033e6c_inline(rres_205DC7C(k))->mTotalPoints;
        } else {
            bres_sState->mEntries[k].mScore = func_02033e6c_inline(rres_205DC7C(k))->mWinCount;
        }
    }
    for (j = 0; j < bres_sState->mKartCount; j++) {
        higherCount = 0;
        for (k = 0; k < bres_sState->mKartCount; k++) {
            if (j != k && bres_sState->mEntries[j].mScore < bres_sState->mEntries[k].mScore) {
                higherCount++;
            }
        }
        bres_sState->mEntries[j].mRank = higherCount;
    }
    if (gRaceMultiConfig->mUseTeams != 0) {
        if (gRaceMultiConfig->mMode == MODE_BATTLE && gRaceMultiConfig->mRuleKind == 1) {
            bres_2034188();
        } else {
            bres_2034024();
        }
    } else if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        for (k = 0; k < bres_sState->mKartCount; k++) {
            bres_sState->mEntries[k].mOrderIndex = gStruct217B488->fieldEC[k];
        }
    } else {
        for (k = 0; k < bres_sState->mKartCount; k++) {
            bres_sState->mEntries[k].mOrderIndex = rres_getGlobalRank(k) - 1;
        }
    }
}

s32 bres_2033E24(void) {
    s32 allRanksZero;
    s32 i;

    allRanksZero = 1;
    i = 0;
    for (; i < bres_sState->mKartCount; i++) {
        allRanksZero &= bres_sState->mEntries[i].mRank == 0 ? 1 : 0;
    }
    return allRanksZero;
}

s32 bres_2033DFC(void) {
    BOOL result;

    result = FALSE;
    if (bres_sState->mUseTimer != FALSE && bres_sState->mTimer == 0) {
        result = TRUE;
    }
    return result;
}

s32 bres_2033DD0(void) {
    BOOL result;

    result = FALSE;
    if (bres_sState->mUseTimer != FALSE && bres_sState->mTimer < 0x12c) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off
