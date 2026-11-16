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

void func_020c1ef8(void) {
    s32 sortKeys[8];
    u32 framesSinceEntryEnd;
    s32 minusOne;
    BOOL falseValue;
    s32 zero;
    s32 isHumanGhostOrPeer;
    s32 humanGhostPeerFlag;
    u16 i;

    if (gRaceStatus->mRaceDone == 0) {
        return;
    }
    r2d_sResults->mUnk_00a4 = 1;
    if (gRaceMultiConfig->mMode == MODE_BATTLE && gRaceMultiConfig->mUseTeams != 0) {
        r2d_sResults->mUpdate = func_020c0f48;
        r2d_sResults->mUpdateFrames = 0;
        RequestRaceHudSubScreenState5();
    } else {
        r2d_sResults->mUpdate = SlideInRaceGoalS;
        r2d_sResults->mUpdateFrames = 0;
    }
    minusOne = -1;
    falseValue = FALSE;
    zero = 0;
    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        r2d_sResults->mRowKartIndex[i] = i;
        if (gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE) {
            isHumanGhostOrPeer = falseValue;
            if (gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                ((1 << gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isHumanGhostOrPeer = 1;
            }
            humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zero;
            sortKeys[i] = humanGhostPeerFlag * 8 + 8 - rstat_getPlace(i);
            if (rstat_getPlace(i) == 1) {
                sortKeys[i] += 0x20;
            }
            sortKeys[i] = sortKeys[i] * minusOne;
        } else {
            sortKeys[i] = rstat_getPlace(i);
        }
    }
    SortIndicesByKey(r2d_sResults->mRowKartIndex, sortKeys, gRaceMultiConfig->mKartCount);
    if (gRaceMultiConfig->mMode == MODE_VS || gRaceMultiConfig->mMode == 5) {
        if (race_20617A8(&framesSinceEntryEnd) != 0) {
            if (framesSinceEntryEnd >= 0xb4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x46);
            }
        }
    }
}

void SlideInRaceGoalS(void) {
    s32 frame;

    frame = r2d_sResults->mUpdateFrames++;
    if (frame < 0x14) {
        r2d_sResults->mOffsetX = mutil_interpolate(1, -0x100, 0, frame, 0x14);
    } else {
        r2d_sResults->mOffsetX = 0;
        r2d_sResults->mUpdate = func_020c1de4;
        r2d_sResults->mUpdateFrames = 0;
    }
}

void func_020c1de4(void) {
    s32 frame;
    u16 keyABits;
    InputSlotIndex inputSlot;

    frame = r2d_sResults->mUpdateFrames++;
    if (frame >= 0x5a) {
        r2d_sResults->mUpdate = func_020c1bc0;
        r2d_sResults->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputUnits[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        r2d_sResults->mUpdate = func_020c1bc0;
        r2d_sResults->mUpdateFrames = 0;
    }
}

void func_020c1bc0(void) {
    s32 frame;
    u16 keyABits;
    u16 i;
    BOOL allReached;
    s32 target;
    u32 kartIndex;
    u32 courseIndex;
    KartCourseResult *record;
    InputSlotIndex inputSlot;

    frame = r2d_sResults->mUpdateFrames++;
    if (frame % 5 == 0) {
        allReached = TRUE;
        for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
            if (gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE) {
                kartIndex = rres_205DC7C(i);
                courseIndex = rres_205DB28();
                target = rres_sRaceResults->mKartResults[courseIndex][rres_205DC7C(kartIndex)].mWinCount;
            } else {
                kartIndex = rres_205DC7C(i);
                courseIndex = rres_205DB28();
                record = &rres_sRaceResults->mKartResults[courseIndex][rres_205DC7C(kartIndex)];
                target = record->mTotalPoints;
            }
            if (r2d_sResults->mShownNumbers[i] < target) {
                if (r2d_sResults->mShownNumbers[i] < 0x3e8) {
                    r2d_sResults->mShownNumbers[i]++;
                    allReached = FALSE;
                }
            }
        }
        if (allReached != FALSE) {
            r2d_sResults->mUpdate = func_020c195c;
            r2d_sResults->mUpdateFrames = 0;
            r2d_sResults->mUpdateFrames = 0;
            if (gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x29);
            }
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x29);
        }
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputUnits[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        r2d_sResults->mUpdate = func_020c195c;
        r2d_sResults->mUpdateFrames = 0;
    }
}

void func_020c195c(void) {
    s32 frame;
    u16 keyABits;
    u16 i;
    u32 kartIndex;
    u32 courseIndex;
    KartCourseResult *record;
    InputSlotIndex inputSlot;

    frame = r2d_sResults->mUpdateFrames++;
    if (frame < 0x5a) {
        for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
            if (gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE) {
                kartIndex = rres_205DC7C(i);
                courseIndex = rres_205DB28();
                r2d_sResults->mShownNumbers[i] = rres_sRaceResults->mKartResults[courseIndex][rres_205DC7C(kartIndex)].mWinCount;
            } else {
                kartIndex = rres_205DC7C(i);
                courseIndex = rres_205DB28();
                record = &rres_sRaceResults->mKartResults[courseIndex][rres_205DC7C(kartIndex)];
                r2d_sResults->mShownNumbers[i] = record->mTotalPoints;
            }
        }
    } else {
        if (gRaceMultiConfig->mUseTeams != 0) {
            r2d_sResults->mUpdate = func_020c0fd0;
            r2d_sResults->mUpdateFrames = 0;
        } else if (gRaceMultiConfig->mCourseNumber == 1) {
            r2d_sResults->mUpdate = func_020c13e8;
            r2d_sResults->mUpdateFrames = 0;
        } else {
            r2d_sResults->mUpdate = func_020c1728;
            r2d_sResults->mUpdateFrames = 0;
        }
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputUnits[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        if (gRaceMultiConfig->mUseTeams != 0) {
            r2d_sResults->mUpdate = func_020c0fd0;
            r2d_sResults->mUpdateFrames = 0;
        } else if (gRaceMultiConfig->mCourseNumber == 1) {
            r2d_sResults->mUpdate = func_020c13e8;
            r2d_sResults->mUpdateFrames = 0;
        } else {
            r2d_sResults->mUpdate = func_020c1728;
            r2d_sResults->mUpdateFrames = 0;
        }
    }
}

void func_020c1728(void) {
    s32 frame;
    s32 hiddenRows;
    u16 keyABits;
    u16 j;
    InputSlotIndex inputSlot;

    frame = r2d_sResults->mUpdateFrames++;
    if (frame < 0x2d) {
        hiddenRows = r2d_sResults->mHiddenRowCount;
        if (hiddenRows < gRaceMultiConfig->mKartCount) {
            if (frame % 5 == 0) {
                switch (hiddenRows) {
                    case 0:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x32);
                        break;
                    case 1:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x33);
                        break;
                    case 2:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x34);
                        break;
                    case 3:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x35);
                        break;
                    case 4:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x36);
                        break;
                    case 5:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x37);
                        break;
                    case 6:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x38);
                        break;
                    case 7:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x39);
                        break;
                }
                r2d_sResults->mRowVisible[r2d_sResults->mHiddenRowCount++] = 0;
            }
        }
    } else {
        func_020c1060();
        r2d_sResults->mUpdate = func_020c155c;
        r2d_sResults->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputUnits[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        for (j = 0; j < (u32) gRaceMultiConfig->mKartCount; j++) {
            r2d_sResults->mRowVisible[j] = 0;
        }
        r2d_sResults->mHiddenRowCount = gRaceMultiConfig->mKartCount;
        func_020c1060();
        r2d_sResults->mUpdate = func_020c155c;
        r2d_sResults->mUpdateFrames = 0;
    }
}

void func_020c155c(void) {
    s32 frame;
    s32 hiddenRows;
    u16 keyABits;
    InputSlotIndex inputSlot;

    frame = r2d_sResults->mUpdateFrames++;
    hiddenRows = r2d_sResults->mHiddenRowCount;
    if (hiddenRows > 0) {
        if (frame % 5 == 0) {
            r2d_sResults->mHiddenRowCount = hiddenRows - 1;
            r2d_sResults->mRowVisible[r2d_sResults->mHiddenRowCount] = 1;
            switch (r2d_sResults->mHiddenRowCount) {
                case 0:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2a);
                    break;
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2b);
                    break;
                case 2:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2c);
                    break;
                case 3:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2d);
                    break;
                case 4:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2e);
                    break;
                case 5:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2f);
                    break;
                case 6:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x30);
                    break;
                case 7:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x31);
                    break;
            }
        }
    } else {
        r2d_sResults->mUpdate = func_020c13e8;
        r2d_sResults->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = gInputUnits[inputSlot].mPressedBits & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        r2d_sResults->mUpdate = func_020c13e8;
        r2d_sResults->mUpdateFrames = 0;
    }
}

static inline Unk0217aa1c_144_00 *func_020c13e8_inline(s32 teamIndex) {
    return &rres_sRaceResults->mTeamResults[rres_205DB28()].mTeams[teamIndex];
}

void func_020c13e8(void) {
    s32 frame;
    s32 i;
    s32 a;
    s32 teamOneValue;

    frame = r2d_sResults->mUpdateFrames++;
    if (frame < 0x3c) {
        func_020c1060();
        for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
            r2d_sResults->mRowVisible[i] = 1;
        }
    } else {
        if (gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE) {
            if (gRaceMultiConfig->mUseTeams != 0) {
                a = func_020c13e8_inline(0)->mUnk_02;
                teamOneValue = func_020c13e8_inline(1)->mUnk_02;
                if (a <= teamOneValue) {
                    a = teamOneValue;
                }
            } else {
                a = r2d_sResults->mShownNumbers[r2d_sResults->mRowKartIndex[0]];
            }
            r2d_sResults->mUnk_00b4 = a >= gRaceMultiConfig->mCourseCount;
        } else {
            r2d_sResults->mUnk_00b4 = gRaceMultiConfig->mCourseNumber >= gRaceMultiConfig->mCourseCount;
        }
        r2d_sResults->mUpdate = func_020c13d0;
        r2d_sResults->mUpdateFrames = 0;
    }
}
