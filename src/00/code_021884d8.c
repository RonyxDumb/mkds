#include "00/code_021884d8.h"

#include "00/unk_021b4000.h"
#include "00/code_02188008.h"

void DWCi_AC_FreeAll(void) {
    ACHOLD *hold;
    void *buffer;

    hold = (ACHOLD *) DWCi_AC_GetMemPtr(1);
    if ((hold->mUnk_08 & 0x10) != 0) {
        buffer = (void *) DWCi_AC_GetMemPtr(0x10);
        hold->mUnk_08 &= ~0x10;
        hold->mUnk_04(0x10, buffer, 0xd18);
    }
    if ((hold->mUnk_08 & 8) != 0) {
        buffer = (void *) DWCi_AC_GetMemPtr(8);
        hold->mUnk_08 &= ~8;
        hold->mUnk_04(8, buffer, 0xc);
    }
    if ((hold->mUnk_08 & 4) != 0) {
        buffer = (void *) DWCi_AC_GetMemPtr(4);
        hold->mUnk_08 &= ~4;
        hold->mUnk_04(4, buffer, 0x58);
    }
    if ((hold->mUnk_08 & 2) != 0) {
        buffer = (void *) DWCi_AC_GetMemPtr(2);
        hold->mUnk_08 &= ~2;
        hold->mUnk_04(2, buffer, 0x2300);
    }
    if ((hold->mUnk_08 & 1) != 0) {
        hold->mUnk_08 &= ~1;
        hold->mUnk_04(1, hold, 0x18);
    }
}

u32 DWCi_AC_GetMemPtr(u32 name) {
    if ((name & 1) != 0) {
        return (u32) gAcHold;
    }
    if ((name & 2) != 0) {
        return *(u32 *) &gWcmBuffer;
    }
    if ((name & 4) != 0) {
        return *(u32 *) &gSocConfig;
    }
    if ((name & 8) != 0) {
        return *(u32 *) &gNetCheck;
    }
    if ((name & 0x10) != 0) {
        return *(u32 *) &gAcWork;
    }
    return 0;
}

void DWCi_AC_SetPhase(u8 phase) {
    ACHOLD *hold;
    Unk02188408 *work;

    hold = (ACHOLD *) DWCi_AC_GetMemPtr(1);
    work = (Unk02188408 *) DWCi_AC_GetMemPtr(0x10);
    hold->mUnk_09 = phase;
    if (phase < 0x10) {
        if (phase > hold->mUnk_16) {
            hold->mUnk_16 = phase;
            if (phase > 7) {
                hold->mUnk_15 = DWCi_ConvConnectAPType(work->mUnk_d0d);
                hold->mUnk_14 = work->mUnk_444[work->mUnk_d13].mUnk_00;
            }
        }
    }
}

u8 DWCi_AC_GetPhase(void) {
    u32 phase;
    phase = gAcHold->mUnk_09;
    return phase;
}

void DWCi_AC_SetError(u32 error) {
    u32 value0 = error;
    u32 hold;
    u32 errorValue;
    errorValue = (value0) + (0u);
    value0 = 1u;
    value0 = DWCi_AC_GetMemPtr(value0);
    hold = (value0) + (0u);
    *(u32 *) ((hold) + 12u) = errorValue;
    value0 = DWCi_AC_GetPhase();
    *(u8 *) ((hold) + 10u) = value0;
}

u32 DWCi_AC_GetError(void) {
    u32 error;
    error = gAcHold->mUnk_0c;
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
