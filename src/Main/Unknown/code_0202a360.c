#include "Main/Unknown/code_0202a360.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02122734.h"
#include "00/code_02181f98.h"

#pragma opt_rebuildconditionals off

#pragma thumb on

static inline CourseTeamResult *GetCourseTeamResult(s32 teamIndex) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

u32 GetResultSceneSeqKind(void) {
    RaceSetup *raceSetup;
    s32 kartCount;
    s32 ownEntryIndex;
    s32 scores[8];
    s32 unused;
    s32 scoreIndex;
    s32 maxScore;
    s32 allEqual;
    s32 kartIndex;
    s32 courseIndex;
    s32 team0Score;
    s32 team1Score;
    s32 ownTeamIndex;
    s32 ownIndex;
    KartCourseResult *record;

    raceSetup = gRaceSetup;
    kartCount = raceSetup->mKartCount;
    if (raceSetup->mMode == MODE_GRAND_PRIX) {
        if (gMenuShared->mCupRankIndex < 3) {
            return 0;
        }
        return 1;
    }
    switch (gStartupWork->mConnectionKind) {
        case 0:
            ownEntryIndex = 0;
            break;
        case 1:
        case 2:
            if (gConnectionWork->mConnectionMode == 2) {
                ownIndex = gConnectionWork->mOwnIndex;
            } else {
                ownIndex = 0;
            }
            ownEntryIndex = GetParticipantPosByIndex(ownIndex)->mEntryIndex;
            break;
        case 3:
            ownEntryIndex = (u16) GetPackedIndex(GetOwnParticipantIndex());
            break;
    }
    if (gRaceSetup->mUseTeams != 0) {
        ownTeamIndex = gRaceSetup->mCurrentEntries[ownEntryIndex].mPlayer.mTeamIndex;
        switch (gRaceSetup->mRuleKind) {
            case 1:
                team0Score = GetCourseTeamResult(0)->mWinCount;
                team1Score = GetCourseTeamResult(1)->mWinCount;
                break;
            case 2:
                team0Score = GetCourseTeamResult(0)->mTotalPoints;
                team1Score = GetCourseTeamResult(1)->mTotalPoints;
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
    scoreIndex = 0;
    maxScore = -1;
    allEqual = 1;
    for (; scoreIndex < kartCount; scoreIndex++) {
        if (gStartupWork->mConnectionKind == 3 || gRaceSetup->mRuleKind == 2) {
            kartIndex = GetLowByte((u16) scoreIndex);
            courseIndex = GetCourseIndexInCup();
            record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
            scores[scoreIndex] = record->mTotalPoints;
        } else {
            kartIndex = GetLowByte((u16) scoreIndex);
            courseIndex = GetCourseIndexInCup();
            record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
            scores[scoreIndex] = record->mWinCount;
        }
        if (maxScore < scores[scoreIndex]) {
            maxScore = scores[scoreIndex];
        }
    }
    for (scoreIndex = 1; scoreIndex < kartCount; scoreIndex++) {
        allEqual = allEqual & (scores[0] == scores[scoreIndex]);
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
