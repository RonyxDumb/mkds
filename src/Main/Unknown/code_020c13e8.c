#include "Main/Unknown/code_020c13e8.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_0203c8dc.h"

void StartRaceGoalS(void) {
    s32 sortKeys[8];
    u32 framesSinceEntryEnd;
    s32 minusOne;
    BOOL falseValue;
    s32 zero;
    s32 isHumanGhostOrPeer;
    s32 humanGhostPeerFlag;
    u16 i;

    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    gRaceGoalS->mRunning = 1;
    if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mUseTeams != 0) {
        gRaceGoalS->mUpdate = SlideInRaceGoalSTeams;
        gRaceGoalS->mUpdateFrames = 0;
        RequestRaceHudSubScreenState5();
    } else {
        gRaceGoalS->mUpdate = SlideInRaceGoalS;
        gRaceGoalS->mUpdateFrames = 0;
    }
    minusOne = -1;
    falseValue = FALSE;
    zero = 0;
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        gRaceGoalS->mRowKartIndex[i] = i;
        if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            isHumanGhostOrPeer = falseValue;
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isHumanGhostOrPeer = 1;
            }
            humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zero;
            sortKeys[i] = humanGhostPeerFlag * 8 + 8 - GetKartRank(i);
            if (GetKartRank(i) == 1) {
                sortKeys[i] += 0x20;
            }
            sortKeys[i] = sortKeys[i] * minusOne;
        } else {
            sortKeys[i] = GetKartRank(i);
        }
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, sortKeys, gRaceSetup->mKartCount);
    if (gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == MODE_WIFI) {
        if (TryGetRaceUpdateFramesSinceEntryEnd(&framesSinceEntryEnd) != 0) {
            if (framesSinceEntryEnd >= 0xb4) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x46);
            }
        }
    }
}

void SlideInRaceGoalS(void) {
    s32 frame;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x14) {
        gRaceGoalS->mOffsetX = InterpolateS16(1, -0x100, 0, frame, 0x14);
    } else {
        gRaceGoalS->mOffsetX = 0;
        gRaceGoalS->mUpdate = HoldRaceGoalSPreviousNumbers;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void HoldRaceGoalSPreviousNumbers(void) {
    s32 frame;
    u16 keyABits;
    InputSlotIndex inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame >= 0x5a) {
        gRaceGoalS->mUpdate = CountUpRaceGoalSNumbers;
        gRaceGoalS->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputSlots[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        gRaceGoalS->mUpdate = CountUpRaceGoalSNumbers;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void CountUpRaceGoalSNumbers(void) {
    s32 frame;
    u16 keyABits;
    u16 i;
    BOOL allReached;
    s32 target;
    u32 kartIndex;
    u32 courseIndex;
    KartCourseResult *record;
    InputSlotIndex inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame % 5 == 0) {
        allReached = TRUE;
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                target = gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)].mWinCount;
            } else {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
                target = record->mTotalPoints;
            }
            if (gRaceGoalS->mShownNumbers[i] < target) {
                if (gRaceGoalS->mShownNumbers[i] < 0x3e8) {
                    gRaceGoalS->mShownNumbers[i]++;
                    allReached = FALSE;
                }
            }
        }
        if (allReached != FALSE) {
            gRaceGoalS->mUpdate = HoldRaceGoalSNumbers;
            gRaceGoalS->mUpdateFrames = 0;
            gRaceGoalS->mUpdateFrames = 0;
            if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x29);
            }
        } else {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x29);
        }
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputSlots[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        gRaceGoalS->mUpdate = HoldRaceGoalSNumbers;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void HoldRaceGoalSNumbers(void) {
    s32 frame;
    u16 keyABits;
    u16 i;
    u32 kartIndex;
    u32 courseIndex;
    KartCourseResult *record;
    InputSlotIndex inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x5a) {
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                gRaceGoalS->mShownNumbers[i] = gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)].mWinCount;
            } else {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
                gRaceGoalS->mShownNumbers[i] = record->mTotalPoints;
            }
        }
    } else {
        if (gRaceSetup->mUseTeams != 0) {
            gRaceGoalS->mUpdate = SlideOutRaceGoalS;
            gRaceGoalS->mUpdateFrames = 0;
        } else if (gRaceSetup->mCourseNumber == 1) {
            gRaceGoalS->mUpdate = HoldRaceGoalSRows;
            gRaceGoalS->mUpdateFrames = 0;
        } else {
            gRaceGoalS->mUpdate = HideRaceGoalSRows;
            gRaceGoalS->mUpdateFrames = 0;
        }
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputSlots[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        if (gRaceSetup->mUseTeams != 0) {
            gRaceGoalS->mUpdate = SlideOutRaceGoalS;
            gRaceGoalS->mUpdateFrames = 0;
        } else if (gRaceSetup->mCourseNumber == 1) {
            gRaceGoalS->mUpdate = HoldRaceGoalSRows;
            gRaceGoalS->mUpdateFrames = 0;
        } else {
            gRaceGoalS->mUpdate = HideRaceGoalSRows;
            gRaceGoalS->mUpdateFrames = 0;
        }
    }
}

void HideRaceGoalSRows(void) {
    s32 frame;
    s32 hiddenRows;
    u16 keyABits;
    u16 j;
    InputSlotIndex inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x2d) {
        hiddenRows = gRaceGoalS->mHiddenRowCount;
        if (hiddenRows < gRaceSetup->mKartCount) {
            if (frame % 5 == 0) {
                switch (hiddenRows) {
                    case 0:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x32);
                        break;
                    case 1:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x33);
                        break;
                    case 2:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x34);
                        break;
                    case 3:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x35);
                        break;
                    case 4:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x36);
                        break;
                    case 5:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x37);
                        break;
                    case 6:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x38);
                        break;
                    case 7:
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x39);
                        break;
                }
                gRaceGoalS->mRowVisible[gRaceGoalS->mHiddenRowCount++] = 0;
            }
        }
    } else {
        RefreshRaceGoalSRows();
        gRaceGoalS->mUpdate = ShowRaceGoalSRows;
        gRaceGoalS->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputSlots[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        for (j = 0; j < (u32) gRaceSetup->mKartCount; j++) {
            gRaceGoalS->mRowVisible[j] = 0;
        }
        gRaceGoalS->mHiddenRowCount = gRaceSetup->mKartCount;
        RefreshRaceGoalSRows();
        gRaceGoalS->mUpdate = ShowRaceGoalSRows;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void ShowRaceGoalSRows(void) {
    s32 frame;
    s32 hiddenRows;
    u16 keyABits;
    InputSlotIndex inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    hiddenRows = gRaceGoalS->mHiddenRowCount;
    if (hiddenRows > 0) {
        if (frame % 5 == 0) {
            gRaceGoalS->mHiddenRowCount = hiddenRows - 1;
            gRaceGoalS->mRowVisible[gRaceGoalS->mHiddenRowCount] = 1;
            switch (gRaceGoalS->mHiddenRowCount) {
                case 0:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x2a);
                    break;
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x2b);
                    break;
                case 2:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x2c);
                    break;
                case 3:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x2d);
                    break;
                case 4:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x2e);
                    break;
                case 5:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x2f);
                    break;
                case 6:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x30);
                    break;
                case 7:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x31);
                    break;
            }
        }
    } else {
        gRaceGoalS->mUpdate = HoldRaceGoalSRows;
        gRaceGoalS->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputSlots[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        gRaceGoalS->mUpdate = HoldRaceGoalSRows;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

static inline CourseTeamResult *RaceGoalSGetCourseTeamResult(s32 teamIndex) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

void HoldRaceGoalSRows(void) {
    s32 frame;
    s32 i;
    s32 bestValue;
    s32 teamOneValue;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x3c) {
        RefreshRaceGoalSRows();
        for (i = 0; i < gRaceSetup->mKartCount; i++) {
            gRaceGoalS->mRowVisible[i] = 1;
        }
    } else {
        if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            if (gRaceSetup->mUseTeams != 0) {
                bestValue = RaceGoalSGetCourseTeamResult(0)->mWinCount;
                teamOneValue = RaceGoalSGetCourseTeamResult(1)->mWinCount;
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
}
