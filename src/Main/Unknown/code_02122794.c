#include "Main/Unknown/code_02122794.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"

void func_02122ab0(void) {
    StateMachine *stateMachine;
    gStruct217D384->mUnk_19ad = 0;
    stateMachine = &gStruct217D384->mUnk_0008;
    stateMachine->mNextState = 2;
    stateMachine->mNextStateRequested = 1;
}

// Drops the indices set in mKartRemoveMask from the roster; ends the run (step 11) if the own index is removed or one
// kart or none remains.
void RemoveWiFiSessionKarts(void) {
    u8 i;
    u32 bit;
    if (gStruct217D384->mStep == 11 || gStruct217D384->mStep == 12) {
        return;
    }
    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        bit = 1 << i;
        if ((gStruct217D384->mKartMask & bit) != 0 && (gStruct217D384->mKartRemoveMask & bit) != 0) {
            if (i == func_ov000_0219bb50()) {
                gStruct217D384->mUnk_19ad = 1;
                func_ov000_021a2ccc();
                func_ov000_0219bbfc();
                gStruct217D384->mStep = 11;
                return;
            }
            gStruct217D384->mKartMask &= ~bit;
            gStruct217D384->mKartRemoveMask &= ~bit;
            gStruct217D384->mKartCount--;
        }
    }
    if (gStruct217D384->mKartCount <= 1) {
        gStruct217D384->mUnk_19ad = 1;
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        gStruct217D384->mStep = 11;
    }
}

void UpdateWiFiSessionKartTimeouts(void) {
    u8 i;
    u8 ownIndex;
    if (gStruct217D384->mStep > 2 && gStruct217D384->mStep < 9) {
        if (gStruct217D384->mStep == 3) {
            ownIndex = func_ov000_0219bb50();
            if (gStruct217D384->mIndexMessages[ownIndex].mUnk_40 != 1) {
                return;
            }
        }
        for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
            if (i != func_ov000_0219bb50() && (gStruct217D384->mKartMask & (1 << i)) != 0) {
                if (gStruct217D384->mSinceCallbackFrames[i] > 300) {
                    gStruct217D384->mKartRemoveMask |= 1 << i;
                }
            }
        }
    }
    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50() && (gStruct217D384->mKartMask & (1 << i)) != 0) {
            gStruct217D384->mSinceCallbackFrames[i]++;
        }
    }
}

u32 GetKartMaskBit(u32 index) {
    return gStruct217D384->mKartMask & (1 << index);
}

u32 GetKartMaskBitOfPackedIndex(u8 packedIndex) {
    s8 i;
    for (i = 0; i < 4; i++) {
        if (packedIndex == gStruct217D384->mPackedIndices[i]) {
            goto found;
        }
    }
    i = -1;
found:
    if (i == -1) {
        return 0;
    }
    return gStruct217D384->mKartMask & (1 << (u8) i);
}
