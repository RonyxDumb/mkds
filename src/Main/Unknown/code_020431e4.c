#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_0204a9e4.h"
#include "Main/Unknown/code_020470c4.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

static inline s32 func_020431e4_inline(ConnectionWork *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mConnectionMode) != 0 && p->mState != 13) {
        r = TRUE;
    }
    return r;
}

u16 GetPadInputSlot(void) {
    return 9;
}

BOOL IsInputOpenDuringRace(void) {
    return (data_02175624->mFlags & INPUT_STATE_OPEN_DURING_RACE) != 0;
}

void SetReadRaceKeys(u32 enable) {
    if (GetCurrentSceneNumber() == 2 && enable != 0) {
        data_02175624->mFlags |= INPUT_STATE_READ_RACE_KEYS;
    } else {
        data_02175624->mFlags &= ~INPUT_STATE_READ_RACE_KEYS;
    }
}

void ResetInputSlotsFromParticipants(void) {
    u16 i;
    u16 j;
    ConnectionWork *connectionWork;
    InputSlot *inputSlot;

    for (i = 0; i < 8; i++) {
        inputSlot = &gInputSlots[i];
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording(&inputSlot->mUnk_28);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    connectionWork = gConnectionWork;
    if (func_020431e4_inline(connectionWork) != 0) {
        for (j = 0; j < 8; j++) {
            if (connectionWork->mParticipantMask & (1 << connectionWork->mUnk_1e8c[j])) {
                gInputSlots[j].mSourceKind = 4;
            }
        }
    }
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = FALSE;
}

void ResetInputSlotsFromRaceSetup(void) {
    s32 i;
    s32 k;
    u16 entryIndex;
    s32 inputSlotIndex;
    BOOL isNonCpu;
    InputSlot *inputSlot;
    RaceSetup *raceSetup;
    ConnectionWork *connectionWork;
    s32 playerKind;

    for (i = 0; i < 10; i++) {
        inputSlot = &gInputSlots[(u32) i];
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording(&inputSlot->mUnk_28);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    gInputSlots[8].mSourceKind = 5;
    gInputSlots[9].mSourceKind = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = FALSE;
    inputSlot = gInputSlots;
    for (k = 0; k < 10; k++) {
        ResetInputSlot(inputSlot);
        inputSlot->mRequestedBits = 0;
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot++;
    }
    raceSetup = gRaceSetup;
    connectionWork = gConnectionWork;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        playerKind = raceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        isNonCpu = FALSE;
        inputSlotIndex = raceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
        if ((u32) playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isNonCpu = TRUE;
        }
        if (isNonCpu != FALSE) {
            if (entryIndex == raceSetup->mEntryIndex) {
                if (func_020431e4_inline(connectionWork) != 0) {
                    gInputSlots[inputSlotIndex].mSourceKind = 4;
                } else if (raceSetup->mRaceKind == RACE_KIND_REPLAY) {
                    gInputSlots[inputSlotIndex].mSourceKind = 1;
                } else {
                    gInputSlots[inputSlotIndex].mSourceKind = 2;
                }
            } else if (playerKind == 2) {
                gInputSlots[inputSlotIndex].mSourceKind = 1;
            } else if (raceSetup->mMode == 5) {
                gInputSlots[inputSlotIndex].mSourceKind = 7;
            } else {
                gInputSlots[inputSlotIndex].mSourceKind = 4;
            }
        } else if (playerKind == 1) {
            gInputSlots[inputSlotIndex].mSourceKind = 3;
        }
    }
}
