#include "Main/Race/race_goal_s_rows.h"
#include "Main/Race/cup_records.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/race_goal_s_finish.h"
#include "Main/System/low_byte.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/MapObjects/data_0217b000.h"
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
        for (index = 0; index < (u32) gRaceSetup->mKartCount; index++) {
            if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                isHumanGhostOrPeer = falseValueFirst;
                if (gRaceSetup->mCurrentEntries[index].mPlayer.mKind <= 3 &&
                    ((1 << gRaceSetup->mCurrentEntries[index].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    isHumanGhostOrPeer = 1;
                }
                humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zeroFirst;
                lowByte = GetLowByte(index);
                courseIndexInCup = GetCourseIndexInCup();
                score = gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)].mWinCount;
                sortKeys[index] = score * 16 + humanGhostPeerFlag * 8 + 8 - GetKartRank(index);
            } else {
                isHumanGhostOrPeer = falseValueSecond;
                if (gRaceSetup->mCurrentEntries[index].mPlayer.mKind <= 3 &&
                    ((1 << gRaceSetup->mCurrentEntries[index].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    isHumanGhostOrPeer = 1;
                }
                humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zeroSecond;
                lowByte = GetLowByte(index);
                courseIndexInCup = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)];
                score = record->mTotalPoints;
                sortKeys[index] = score * 16 + humanGhostPeerFlag * 8 + 8 - GetKartRank(index);
                lowByte = GetLowByte(index);
                courseIndexInCup = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)];
                gRaceGoalS->mShownNumbers[index] = record->mTotalPoints;
            }
        }
    }
    for (index = 0; index < (u32) gRaceSetup->mKartCount; index++) {
        gRaceGoalS->mRowKartIndex[index] = index;
        sortKeys[index] = sortKeys[index] * minusOne;
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, sortKeys, gRaceSetup->mKartCount);
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        {
            for (rowIndex = 0; rowIndex < (u32) gRaceSetup->mKartCount; rowIndex++) {
                if (kartIndex == gRaceGoalS->mRowKartIndex[rowIndex]) {
                    newRowIndex = rowIndex;
                    SetKartCupRank(kartIndex, (rowIndex + 1) & 0xff);
                    gMenuShared->mOrderIndices[kartIndex] = rowIndex;
                    break;
                }
            }
            for (index = 0; index < (u32) gRaceSetup->mKartCount; index++) {
                if (kartIndex == gRaceGoalS->mPreviousRowKartIndex[index]) {
                    previousRowIndex = index;
                    break;
                }
            }
            if (newRowIndex < previousRowIndex) {
                gRaceGoalS->mRankComparison[kartIndex] = 1;
            } else if (newRowIndex > previousRowIndex) {
                gRaceGoalS->mRankComparison[kartIndex] = 0;
            } else {
                gRaceGoalS->mRankComparison[kartIndex] = 2;
            }
        }
    }
}

void SlideOutRaceGoalS(void) {
    s32 frame;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x14) {
        gRaceGoalS->mOffsetX = InterpolateS16(1, 0, 0x100, frame, 0x14);
    } else {
        gRaceGoalS->mOffsetX = 0x100;
        gRaceGoalS->mUpdate = SlideInRaceGoalSTeams;
        gRaceGoalS->mUpdateFrames = 0;
        RequestRaceHudSubScreenState5();
    }
}

void SlideInRaceGoalSTeams(void) {
    s32 frame;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x14) {
        gRaceGoalS->mOffsetX = InterpolateS16(1, 0x80, 0, frame, 0x14);
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
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

void RefreshRaceGoalSCourseCountReached(void) {
    s32 bestValue;
    s32 teamOneValue;

    if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mUseTeams != 0) {
            bestValue = RaceGoalSRowsGetCourseTeamResult(0)->mWinCount;
            teamOneValue = RaceGoalSRowsGetCourseTeamResult(1)->mWinCount;
            if (bestValue <= teamOneValue) {
                bestValue = teamOneValue;
            }
        } else {
            bestValue = gRaceGoalS->mShownNumbers[gRaceGoalS->mRowKartIndex[0]];
        }
        gRaceGoalS->mCourseCountReached = bestValue >= gRaceSetup->mCourseCount;
    } else {
        gRaceGoalS->mCourseCountReached = gRaceSetup->mCourseNumber >= gRaceSetup->mCourseCount;
    }
    gRaceGoalS->mUpdate = FinishRaceGoalS;
    gRaceGoalS->mUpdateFrames = 0;
}
