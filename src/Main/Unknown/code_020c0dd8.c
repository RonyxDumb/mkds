#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_0203c8dc.h"

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
    u16 i;
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
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                isHumanGhostOrPeer = falseValueFirst;
                if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                    ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    isHumanGhostOrPeer = 1;
                }
                humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zeroFirst;
                lowByte = GetLowByte(i);
                courseIndexInCup = GetCourseIndexInCup();
                score = gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)].mWinCount;
                sortKeys[i] = score * 16 + humanGhostPeerFlag * 8 + 8 - GetKartRank(i);
            } else {
                isHumanGhostOrPeer = falseValueSecond;
                if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                    ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    isHumanGhostOrPeer = 1;
                }
                humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zeroSecond;
                lowByte = GetLowByte(i);
                courseIndexInCup = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)];
                score = record->mTotalPoints;
                sortKeys[i] = score * 16 + humanGhostPeerFlag * 8 + 8 - GetKartRank(i);
                lowByte = GetLowByte(i);
                courseIndexInCup = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndexInCup][GetLowByte(lowByte)];
                gRaceGoalS->mShownNumbers[i] = record->mTotalPoints;
            }
        }
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        gRaceGoalS->mRowKartIndex[i] = i;
        sortKeys[i] = sortKeys[i] * minusOne;
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, sortKeys, gRaceSetup->mKartCount);
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        {
            for (rowIndex = 0; rowIndex < (u32) gRaceSetup->mKartCount; rowIndex++) {
                if (kartIndex == gRaceGoalS->mRowKartIndex[rowIndex]) {
                    newRowIndex = rowIndex;
                    SetKartCupRank(kartIndex, (rowIndex + 1) & 0xff);
                    data_0217b488->mUnk_ec[kartIndex] = rowIndex;
                    break;
                }
            }
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                if (kartIndex == gRaceGoalS->mPreviousRowKartIndex[i]) {
                    previousRowIndex = i;
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

static inline CourseTeamResult *func_020c0dd8_inline(s32 j) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[j];
}

void RefreshRaceGoalSCourseCountReached(void) {
    s32 bestValue;
    s32 teamOneValue;

    if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mUseTeams != 0) {
            bestValue = func_020c0dd8_inline(0)->mWinCount;
            teamOneValue = func_020c0dd8_inline(1)->mWinCount;
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
