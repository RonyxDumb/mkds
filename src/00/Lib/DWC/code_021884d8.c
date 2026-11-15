#include "00/Lib/DWC/code_021884d8.h"

#include "00/unk_021b4000.h"
#include "00/Lib/DWC/code_02188008.h"

void DWCi_AC_FreeAll(void) {
    ACHOLD *hold;
    void *buffer;

    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    if ((hold->mAllocState & AC_MEM_WORK) != 0) {
        buffer = DWCi_AC_GetMemPtr(AC_MEM_WORK);
        hold->mAllocState &= ~AC_MEM_WORK;
        hold->mFree(AC_MEM_WORK, buffer, 0xd18);
    }
    if ((hold->mAllocState & AC_MEM_NETCHECK) != 0) {
        buffer = DWCi_AC_GetMemPtr(AC_MEM_NETCHECK);
        hold->mAllocState &= ~AC_MEM_NETCHECK;
        hold->mFree(AC_MEM_NETCHECK, buffer, 0xc);
    }
    if ((hold->mAllocState & AC_MEM_SOC_CONFIG) != 0) {
        buffer = DWCi_AC_GetMemPtr(AC_MEM_SOC_CONFIG);
        hold->mAllocState &= ~AC_MEM_SOC_CONFIG;
        hold->mFree(AC_MEM_SOC_CONFIG, buffer, 0x58);
    }
    if ((hold->mAllocState & AC_MEM_WCM_BUFFER) != 0) {
        buffer = DWCi_AC_GetMemPtr(AC_MEM_WCM_BUFFER);
        hold->mAllocState &= ~AC_MEM_WCM_BUFFER;
        hold->mFree(AC_MEM_WCM_BUFFER, buffer, 0x2300);
    }
    if ((hold->mAllocState & AC_MEM_HOLD) != 0) {
        hold->mAllocState &= ~AC_MEM_HOLD;
        hold->mFree(AC_MEM_HOLD, hold, 0x18);
    }
}

void *DWCi_AC_GetMemPtr(u32 name) {
    if ((name & AC_MEM_HOLD) != 0) {
        return gAcHold;
    }
    if ((name & AC_MEM_WCM_BUFFER) != 0) {
        return gWcmBuffer;
    }
    if ((name & AC_MEM_SOC_CONFIG) != 0) {
        return gSocConfig;
    }
    if ((name & AC_MEM_NETCHECK) != 0) {
        return gNetCheck;
    }
    if ((name & AC_MEM_WORK) != 0) {
        return gAcWork;
    }
    return NULL;
}

void DWCi_AC_SetPhase(u8 phase) {
    ACHOLD *hold;
    ACWORK *work;

    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
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
    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    hold->mError = errorValue;
    value = DWCi_AC_GetPhase();
    hold->mErrorPhase = value;
}

u32 DWCi_AC_GetError(void) {
    u32 error;
    error = gAcHold->mError;
    return error;
}

void SetAcHoldApType(u8 apType) {
    gAcHold->mApType = DWCi_ConvConnectAPType(apType);
}

u8 DWCi_ConvConnectAPType(u8 apType) {
    if (apType > 2) {
        apType -= 3;
    }
    return apType;
}
