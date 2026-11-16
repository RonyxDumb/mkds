#include "Main/Unknown/code_0202a360.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02122734.h"
#include "00/code_02181f98.h"

#pragma opt_rebuildconditionals off

#pragma thumb on

static inline Unk0217aa1c_144_00 *func_0202a360_inline(s32 teamIndex) {
    return &rres_sRaceResults->mTeamResults[rres_205DB28()].mTeams[teamIndex];
}

u32 result_getResultType(void) {
    RaceSetup *raceSetup;
    s32 kartCount;
    s32 ownEntryIndex;
    s32 scores[8];
    s32 unused;
    s32 i;
    s32 maxScore;
    s32 allEqual;
    s32 kartIndex;
    s32 courseIndex;
    s32 team0Score;
    s32 team1Score;
    s32 ownTeamIndex;
    s32 ownIndex;
    KartCourseResult *record;

    raceSetup = gRaceMultiConfig;
    kartCount = raceSetup->mKartCount;
    if (raceSetup->mMode == MODE_GRAND_PRIX) {
        if (gStruct217B488->mCupRankIndex < 3) {
            return 0;
        }
        return 1;
    }
    switch (gSystemData->field20) {
        case 0:
            ownEntryIndex = 0;
            break;
        case 1:
        case 2:
            if (gStruct217AA00->field0 == 2) {
                ownIndex = gStruct217AA00->mOwnIndex;
            } else {
                ownIndex = 0;
            }
            ownEntryIndex = gStruct217AA00->field1E52[(u16) ownIndex].mEntryIndex;
            break;
        case 3:
            ownEntryIndex = (u16) GetPackedIndex(func_ov000_0219bb50());
            break;
    }
    if (gRaceMultiConfig->mUseTeams != 0) {
        ownTeamIndex = gRaceMultiConfig->mCurrentEntries[ownEntryIndex].mPlayer.mTeamIndex;
        switch (gRaceMultiConfig->mRuleKind) {
            case 1:
                team0Score = func_0202a360_inline(0)->field2;
                team1Score = func_0202a360_inline(1)->field2;
                break;
            case 2:
                team0Score = func_0202a360_inline(0)->field0;
                team1Score = func_0202a360_inline(1)->field0;
                break;
        }
        if (team0Score == team1Score) {
            return 7;
        }
        if (team0Score > team1Score) {
            if (ownTeamIndex == 0) {
                return 5;
            }
            return 6;
        }
        if (ownTeamIndex == 1) {
            return 5;
        }
        return 6;
    }
    i = 0;
    maxScore = -1;
    allEqual = 1;
    for (; i < kartCount; i++) {
        if (gSystemData->field20 == 3 || gRaceMultiConfig->mRuleKind == 2) {
            kartIndex = rres_205DC7C((u16) i);
            courseIndex = rres_205DB28();
            record = &rres_sRaceResults->mKartResults[courseIndex][rres_205DC7C(kartIndex)];
            scores[i] = record->mTotalPoints;
        } else {
            kartIndex = rres_205DC7C((u16) i);
            courseIndex = rres_205DB28();
            record = &rres_sRaceResults->mKartResults[courseIndex][rres_205DC7C(kartIndex)];
            scores[i] = record->mWinCount;
        }
        if (maxScore < scores[i]) {
            maxScore = scores[i];
        }
    }
    for (i = 1; i < kartCount; i++) {
        allEqual = allEqual & (scores[0] == scores[i]);
    }
    if (allEqual != 0) {
        return 4;
    }
    if (maxScore == scores[ownEntryIndex]) {
        return 2;
    }
    return 3;
}

#pragma thumb off
