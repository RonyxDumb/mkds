#include "00/Lib/DWC/code_021884d8.h"

#include "00/unk_021b4000.h"
#include "00/Lib/DWC/code_02188008.h"

void DWCi_AC_FreeAll(void) {
    ACHOLD *hold;
    void *buffer;

    hold = DWCi_AC_GetMemPtr(1);
    if ((hold->mAllocState & 0x10) != 0) {
        buffer = DWCi_AC_GetMemPtr(0x10);
        hold->mAllocState &= ~0x10;
        hold->mFree(0x10, buffer, 0xd18);
    }
    if ((hold->mAllocState & 8) != 0) {
        buffer = DWCi_AC_GetMemPtr(8);
        hold->mAllocState &= ~8;
        hold->mFree(8, buffer, 0xc);
    }
    if ((hold->mAllocState & 4) != 0) {
        buffer = DWCi_AC_GetMemPtr(4);
        hold->mAllocState &= ~4;
        hold->mFree(4, buffer, 0x58);
    }
    if ((hold->mAllocState & 2) != 0) {
        buffer = DWCi_AC_GetMemPtr(2);
        hold->mAllocState &= ~2;
        hold->mFree(2, buffer, 0x2300);
    }
    if ((hold->mAllocState & 1) != 0) {
        hold->mAllocState &= ~1;
        hold->mFree(1, hold, 0x18);
    }
}

void *DWCi_AC_GetMemPtr(u32 name) {
    if ((name & 1) != 0) {
        return gAcHold;
    }
    if ((name & 2) != 0) {
        return gWcmBuffer;
    }
    if ((name & 4) != 0) {
        return gSocConfig;
    }
    if ((name & 8) != 0) {
        return gNetCheck;
    }
    if ((name & 0x10) != 0) {
        return gAcWork;
    }
    return NULL;
}

void DWCi_AC_SetPhase(u8 phase) {
    ACHOLD *hold;
    ACWORK *work;

    hold = DWCi_AC_GetMemPtr(1);
    work = DWCi_AC_GetMemPtr(0x10);
    hold->mPhase = phase;
    if (phase < 0x10) {
        if (phase > hold->mEndSequence) {
            hold->mEndSequence = phase;
            if (phase > 7) {
                hold->mEndType = DWCi_ConvConnectAPType(work->mConnectApType);
                hold->mEndState = work->mFindList[work->mConnectNo].mState;
            }
        }
    }
}

u8 DWCi_AC_GetPhase(void) {
    u32 phase;
    phase = gAcHold->mPhase;
    return phase;
}

void DWCi_AC_SetError(u32 error) {
    u32 value = error;
    ACHOLD *hold;
    u32 errorValue;
    errorValue = (value) + (0u);
    hold = DWCi_AC_GetMemPtr(1);
    hold->mError = errorValue;
    value = DWCi_AC_GetPhase();
    hold->mUnk_0a = value;
}

u32 DWCi_AC_GetError(void) {
    u32 error;
    error = gAcHold->mError;
    return error;
}

void SetAcHoldApType(u8 apType) {
    gAcHold->mUnk_17 = DWCi_ConvConnectAPType(apType);
}

u8 DWCi_ConvConnectAPType(u8 apType) {
    if (apType > 2) {
        apType -= 3;
    }
    return apType;
}
