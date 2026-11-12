#include "Main/Race/race_goal_s_numbers.h"
#include "Main/Race/cup_records.h"
#include "Main/Race/race.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/race_goal_s_rows.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/race_goal_s_finish.h"
#include "Main/System/low_byte.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Menu/data_02175628.h"
#include "Main/MapObjects/data_0217b000.h"
#include "player.h"
#include "code_0212df7c.h"
#include "Main/Race/race_clock.h"
#include "Main/Sound/sound_system.h"

void StartRaceGoalS(void) {
    s32 sortKeys[8];
    u32 framesSinceEntryEnd;
    s32 minusOne;
    BOOL falseValue;
    s32 zero;
    s32 isHumanGhostOrPeer;
    s32 humanGhostPeerFlag;
    u16 rowIndex;

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
    for (rowIndex = 0; rowIndex < (u32) gRaceSetup->mKartCount; rowIndex++) {
        gRaceGoalS->mRowKartIndex[rowIndex] = rowIndex;
        if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            isHumanGhostOrPeer = falseValue;
            if (gRaceSetup->mCurrentEntries[rowIndex].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[rowIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isHumanGhostOrPeer = 1;
            }
            humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zero;
            sortKeys[rowIndex] = humanGhostPeerFlag * 8 + 8 - GetKartRank(rowIndex);
            if (GetKartRank(rowIndex) == 1) {
                sortKeys[rowIndex] += 0x20;
            }
            sortKeys[rowIndex] = sortKeys[rowIndex] * minusOne;
        } else {
            sortKeys[rowIndex] = GetKartRank(rowIndex);
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
    u16 rowIndex;
    BOOL allReached;
    s32 target;
    u32 kartIndex;
    u32 courseIndex;
    KartCourseResult *record;
    InputSlotIndex inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame % 5 == 0) {
        allReached = TRUE;
        for (rowIndex = 0; rowIndex < (u32) gRaceSetup->mKartCount; rowIndex++) {
            if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                kartIndex = GetLowByte(rowIndex);
                courseIndex = GetCourseIndexInCup();
                target = gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)].mWinCount;
            } else {
                kartIndex = GetLowByte(rowIndex);
                courseIndex = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
                target = record->mTotalPoints;
            }
            if (gRaceGoalS->mShownNumbers[rowIndex] < target) {
                if (gRaceGoalS->mShownNumbers[rowIndex] < 0x3e8) {
                    gRaceGoalS->mShownNumbers[rowIndex]++;
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
    u16 rowIndex;
    u32 kartIndex;
    u32 courseIndex;
    KartCourseResult *record;
    InputSlotIndex inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x5a) {
        for (rowIndex = 0; rowIndex < (u32) gRaceSetup->mKartCount; rowIndex++) {
            if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                kartIndex = GetLowByte(rowIndex);
                courseIndex = GetCourseIndexInCup();
                gRaceGoalS->mShownNumbers[rowIndex] =
                    gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)].mWinCount;
            } else {
                kartIndex = GetLowByte(rowIndex);
                courseIndex = GetCourseIndexInCup();
                record = &gCupRecords->mKartResults[courseIndex][GetLowByte(kartIndex)];
                gRaceGoalS->mShownNumbers[rowIndex] = record->mTotalPoints;
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
    u16 rowIndex;
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
        for (rowIndex = 0; rowIndex < (u32) gRaceSetup->mKartCount; rowIndex++) {
            gRaceGoalS->mRowVisible[rowIndex] = 0;
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
    s32 rowIndex;
    s32 bestValue;
    s32 teamOneValue;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x3c) {
        RefreshRaceGoalSRows();
        for (rowIndex = 0; rowIndex < gRaceSetup->mKartCount; rowIndex++) {
            gRaceGoalS->mRowVisible[rowIndex] = 1;
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
