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
    if ((p == NULL ? 0 : p->field0) != 0 && p->field4 != 13) {
        r = TRUE;
    }
    return r;
}

u16 input_getDirectInputUnitId(void) {
    return 9;
}

u32 input_getFlagsBit0(void) {
    return (input_sPadData->mFlags & INPUT_STATE_OPEN_DURING_RACE) != 0;
}

void input_setFlagsBit1(u32 enable) {
    if (scproc_getCurrentScene() == 2 && enable != 0) {
        input_sPadData->mFlags |= INPUT_STATE_READ_RACE_KEYS;
    } else {
        input_sPadData->mFlags &= ~INPUT_STATE_READ_RACE_KEYS;
    }
}

void input_2043410(void) {
    u16 i;
    u16 j;
    ConnectionWork *z;
    InputSlot *inputSlot;

    for (i = 0; i < 8; i++) {
        inputSlot = &gInputUnits[i];
        pad_init(inputSlot);
        pad_initAutoRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->field44 = 0;
        inputSlot->mBitMask = 0x2fff;
        irec_init((KeyRecording *) &inputSlot->field28);
        spi_initTpMic((InputSlotPair *) &inputSlot->mPairX);
    }
    z = gStruct217AA00;
    if (func_020431e4_inline(z) != 0) {
        for (j = 0; j < 8; j++) {
            if (z->mParticipantMask & (1 << z->field1E8C[j])) {
                gInputUnits[j].mSourceKind = 4;
            }
        }
    }
    input_sPadData->field8 = 0;
    input_sPadData->fieldC = FALSE;
}

void input_20431E4(void) {
    s32 i;
    s32 k;
    u16 entryIndex;
    s32 inputSlotIndex;
    BOOL t;
    InputSlot *inputSlot;
    RaceSetup *raceSetup;
    ConnectionWork *z;
    s32 playerKind;

    for (i = 0; i < 10; i++) {
        inputSlot = &gInputUnits[(u32) i];
        pad_init(inputSlot);
        pad_initAutoRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->field44 = 0;
        inputSlot->mBitMask = 0x2fff;
        irec_init((KeyRecording *) &inputSlot->field28);
        spi_initTpMic((InputSlotPair *) &inputSlot->mPairX);
    }
    gInputUnits[8].mSourceKind = 5;
    gInputUnits[9].mSourceKind = 6;
    input_sPadData->field8 = 0;
    input_sPadData->fieldC = FALSE;
    inputSlot = gInputUnits;
    for (k = 0; k < 10; k++) {
        pad_init(inputSlot);
        inputSlot->mRequestedBits = 0;
        pad_initAutoRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot++;
    }
    raceSetup = gRaceMultiConfig;
    z = gStruct217AA00;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        playerKind = raceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        t = FALSE;
        inputSlotIndex = raceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
        if ((u32) playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            t = TRUE;
        }
        if (t != FALSE) {
            if (entryIndex == raceSetup->mEntryIndex) {
                if (func_020431e4_inline(z) != 0) {
                    gInputUnits[inputSlotIndex].mSourceKind = 4;
                } else if (raceSetup->mRaceKind == 2) {
                    gInputUnits[inputSlotIndex].mSourceKind = 1;
                } else {
                    gInputUnits[inputSlotIndex].mSourceKind = 2;
                }
            } else if (playerKind == 2) {
                gInputUnits[inputSlotIndex].mSourceKind = 1;
            } else if (raceSetup->mMode == 5) {
                gInputUnits[inputSlotIndex].mSourceKind = 7;
            } else {
                gInputUnits[inputSlotIndex].mSourceKind = 4;
            }
        } else if (playerKind == 1) {
            gInputUnits[inputSlotIndex].mSourceKind = 3;
        }
    }
}
