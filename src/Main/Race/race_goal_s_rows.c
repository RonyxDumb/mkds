#include "Main/Race/race_goal_s_rows.h"
#include "Main/Race/cup_records.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/race_goal_s_finish.h"
#include "Main/System/low_byte.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/race_clock.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"

void RefreshRaceGoalSRows(void) {
    s32 sortKeys[8];
    s32 humanGhostPeerFlag;
    u32 lowByte;
    u32 courseIndexInCup;
    u32 score;
    KartCourseResult *record;
    s32 isHumanGhostOrPeer;
    BOOL falseValueFirst;
    s32 zeroFirst;
    BOOL falseValueSecond;
    s32 zeroSecond;
    u16 index;
    u16 rowIndex;
    u16 kartIndex;
    s32 newRowIndex;
    s32 previousRowIndex;
    s32 minusOne;

    minusOne = -1;
    falseValueFirst = FALSE;
    zeroFirst = 0;
    falseValueSecond = FALSE;
    zeroSecond = 0;
    {
        for (index = 0; index < (u32) g_GlobalCO->mKartCount; index++) {
            if (g_GlobalCO->mRuleKind == RULE_KIND_WIN_COUNT || g_GlobalCO->mMode == MODE_BATTLE) {
                isHumanGhostOrPeer = falseValueFirst;
                if (g_GlobalCO->mCurrentEntries[index].mPlayer.mKind <= PLAYER_KIND_PEER &&
                    ((1 << g_GlobalCO->mCurrentEntries[index].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    isHumanGhostOrPeer = 1;
                }
                humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zeroFirst;
                lowByte = Int32ToInt8(index);
                courseIndexInCup = GetSomeLUMaxIndex();
                score = g_GlobalLU->mKartResults[courseIndexInCup][Int32ToInt8(lowByte)].mWinCount;
                sortKeys[index] = score * 16 + humanGhostPeerFlag * 8 + 8 - GetSomeRacerFlags(index);
            } else {
                isHumanGhostOrPeer = falseValueSecond;
                if (g_GlobalCO->mCurrentEntries[index].mPlayer.mKind <= PLAYER_KIND_PEER &&
                    ((1 << g_GlobalCO->mCurrentEntries[index].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    isHumanGhostOrPeer = 1;
                }
                humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zeroSecond;
                lowByte = Int32ToInt8(index);
                courseIndexInCup = GetSomeLUMaxIndex();
                record = &g_GlobalLU->mKartResults[courseIndexInCup][Int32ToInt8(lowByte)];
                score = record->mTotalPoints;
                sortKeys[index] = score * 16 + humanGhostPeerFlag * 8 + 8 - GetSomeRacerFlags(index);
                lowByte = Int32ToInt8(index);
                courseIndexInCup = GetSomeLUMaxIndex();
                record = &g_GlobalLU->mKartResults[courseIndexInCup][Int32ToInt8(lowByte)];
                gRaceGoalS->mShownNumbers[index] = record->mTotalPoints;
            }
        }
    }
    for (index = 0; index < (u32) g_GlobalCO->mKartCount; index++) {
        gRaceGoalS->mRowKartIndex[index] = index;
        sortKeys[index] = sortKeys[index] * minusOne;
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, sortKeys, g_GlobalCO->mKartCount);
    for (kartIndex = 0; kartIndex < (u32) g_GlobalCO->mKartCount; kartIndex++) {
        {
            for (rowIndex = 0; rowIndex < (u32) g_GlobalCO->mKartCount; rowIndex++) {
                if (kartIndex == gRaceGoalS->mRowKartIndex[rowIndex]) {
                    newRowIndex = rowIndex;
                    SetKartCupRank(kartIndex, (rowIndex + 1) & 0xff);
                    g_GlobalB488->mOrderIndices[kartIndex] = rowIndex;
                    break;
                }
            }
            for (index = 0; index < (u32) g_GlobalCO->mKartCount; index++) {
                if (kartIndex == gRaceGoalS->mPreviousRowKartIndex[index]) {
                    previousRowIndex = index;
                    break;
                }
            }
            if (newRowIndex < previousRowIndex) {
                gRaceGoalS->mRankComparison[kartIndex] = RACE_GOAL_S_RANK_UP;
            } else if (newRowIndex > previousRowIndex) {
                gRaceGoalS->mRankComparison[kartIndex] = RACE_GOAL_S_RANK_DOWN;
            } else {
                gRaceGoalS->mRankComparison[kartIndex] = RACE_GOAL_S_RANK_SAME;
            }
        }
    }
}

void SlideOutRaceGoalS(void) {
    s32 frame;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < RACE_GOAL_S_SLIDE_FRAMES) {
        gRaceGoalS->mOffsetX = ComputeValueInterpolation_from_thumb(1, 0, RACE_GOAL_S_SLIDE_OFFSET, frame, RACE_GOAL_S_SLIDE_FRAMES);
    } else {
        gRaceGoalS->mOffsetX = RACE_GOAL_S_SLIDE_OFFSET;
        gRaceGoalS->mUpdate = SlideInRaceGoalSTeams;
        gRaceGoalS->mUpdateFrames = 0;
        RequestRaceHudSubScreenGoalTeams();
    }
}

void SlideInRaceGoalSTeams(void) {
    s32 frame;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < RACE_GOAL_S_SLIDE_FRAMES) {
        gRaceGoalS->mOffsetX = ComputeValueInterpolation_from_thumb(1, 0x80, 0, frame, 0x14);
    } else {
        gRaceGoalS->mOffsetX = 0;
        gRaceGoalS->mUpdate = AdvanceRaceGoalSRefreshRows;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void AdvanceRaceGoalSRefreshRows(void) {
    RefreshRaceGoalSRows();
    gRaceGoalS->mUpdate = AdvanceRaceGoalSToRefreshCourseCountReached;
    gRaceGoalS->mUpdateFrames = 0;
}

void AdvanceRaceGoalSToRefreshCourseCountReached(void) {
    gRaceGoalS->mUpdate = RefreshRaceGoalSCourseCountReached;
    gRaceGoalS->mUpdateFrames = 0;
}

static inline CourseTeamResult *RaceGoalSRowsGetCourseTeamResult(s32 teamIndex) {
    return &g_GlobalLU->mTeamResults[GetSomeLUMaxIndex()].mTeams[teamIndex];
}

void RefreshRaceGoalSCourseCountReached(void) {
    s32 bestValue;
    s32 teamOneValue;

    if (g_GlobalCO->mRuleKind == RULE_KIND_WIN_COUNT || g_GlobalCO->mMode == MODE_BATTLE) {
        if (g_GlobalCO->mUseTeams != 0) {
            bestValue = RaceGoalSRowsGetCourseTeamResult(0)->mWinCount;
            teamOneValue = RaceGoalSRowsGetCourseTeamResult(1)->mWinCount;
            if (bestValue <= teamOneValue) {
                bestValue = teamOneValue;
            }
        } else {
            bestValue = gRaceGoalS->mShownNumbers[gRaceGoalS->mRowKartIndex[0]];
        }
        gRaceGoalS->mCourseCountReached = bestValue >= g_GlobalCO->mCourseCount;
    } else {
        gRaceGoalS->mCourseCountReached = g_GlobalCO->mCourseNumber >= g_GlobalCO->mCourseCount;
    }
    gRaceGoalS->mUpdate = FinishRaceGoalS;
    gRaceGoalS->mUpdateFrames = 0;
}
