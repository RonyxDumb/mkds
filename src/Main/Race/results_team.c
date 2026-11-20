#include "Main/Race/results_team.h"
#include "Main/Race/results_gp.h"
#include "Main/Race/cup_records.h"
#include "Main/System/low_byte.h"
#include "Main/Net/packed_index.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"

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
        if (gMenuShared->mCupRankIndex < CUP_RANK_TROPHY_COUNT) {
            return RESULT_SCENE_SEQ_KIND_GP_TROPHY;
        }
        return RESULT_SCENE_SEQ_KIND_GP_NO_TROPHY;
    }
    switch (gStartupWork->mConnectionKind) {
        case CONNECTION_KIND_NONE:
            ownEntryIndex = 0;
            break;
        case CONNECTION_KIND_MEMBER_SELECT:
        case CONNECTION_KIND_WL_MENU:
            if (gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD) {
                ownIndex = gConnectionWork->mOwnIndex;
            } else {
                ownIndex = 0;
            }
            ownEntryIndex = GetParticipantPosByIndex(ownIndex)->mEntryIndex;
            break;
        case CONNECTION_KIND_WIFI_MENU:
            ownEntryIndex = (u16) GetPackedIndex(DWC_GetMyAID());
            break;
    }
    if (gRaceSetup->mUseTeams != 0) {
        ownTeamIndex = gRaceSetup->mCurrentEntries[ownEntryIndex].mPlayer.mTeamIndex;
        switch (gRaceSetup->mRuleKind) {
            case RULE_KIND_WIN_COUNT:
                team0Score = GetCourseTeamResult(0)->mWinCount;
                team1Score = GetCourseTeamResult(1)->mWinCount;
                break;
            case RULE_KIND_RACE_COUNT:
                team0Score = GetCourseTeamResult(0)->mTotalPoints;
                team1Score = GetCourseTeamResult(1)->mTotalPoints;
                break;
        }
        if (team0Score == team1Score) {
            return RESULT_SCENE_SEQ_KIND_TEAM_DRAW;
        }
        if (team0Score > team1Score) {
            if (ownTeamIndex == 0) {
                return RESULT_SCENE_SEQ_KIND_TEAM_WON;
            }
            return RESULT_SCENE_SEQ_KIND_TEAM_LOST;
        }
        if (ownTeamIndex == 1) {
            return RESULT_SCENE_SEQ_KIND_TEAM_WON;
        }
        return RESULT_SCENE_SEQ_KIND_TEAM_LOST;
    }
    scoreIndex = 0;
    maxScore = -1;
    allEqual = 1;
    for (; scoreIndex < kartCount; scoreIndex++) {
        if (gStartupWork->mConnectionKind == CONNECTION_KIND_WIFI_MENU ||
            gRaceSetup->mRuleKind == RULE_KIND_RACE_COUNT) {
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
        return RESULT_SCENE_SEQ_KIND_DRAW;
    }
    if (maxScore == scores[ownEntryIndex]) {
        return RESULT_SCENE_SEQ_KIND_WON;
    }
    return RESULT_SCENE_SEQ_KIND_LOST;
}

#pragma thumb off
