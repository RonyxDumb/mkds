#include "00/code_02188ee0.h"
#include "00/code_02188720.h"
#include "00/code_02188de4.h"
#include "00/code_02188ea0.h"
#include "00/unk_021b4000.h"
#include "00/code_021884d8.h"
#include "00/code_021894e4.h"
#include "00/code_021a8aa8.h"
#include "code_0200f5ac.h"
#include "code_02139f70.h"
#include "code_0214d018.h"

s32 DisConnectAP(void) {
    switch (func_ov000_021a5bfc()) {
        case 0:
            return 1;
        case 1:
            func_ov000_021a6428();
            break;
        case 3:
            func_ov000_021a61e4();
            break;
        case 6:
            func_ov000_021a6024();
            break;
        case 9:
            func_ov000_021a5db0();
            break;
        case 12:
            func_ov000_021a5c24();
            break;
        case 11:
            DWCi_AC_SetError(0);
            return -1;
    }
    return 0;
}

BOOL CloseAutoConnectSocket(void) {
    s32 result;

    result = func_ov000_021a8c8c();
    if (result == 0 || result == -0x27) {
        return 1;
    }
    return 0;
}

u32 DWCi_AC_ConnectAP(void) {
    u32 phase;
    ACWORK *work;

    phase = DWCi_AC_GetPhase();
    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    switch (phase) {
        case 7:
            phase = ConnectStart(work);
            break;
        case 8:
            phase = ConnectAP(work);
            break;
    }
    return phase;
}

u32 ConnectStart(ACWORK *work) {
    Unk02188ee0 *bssDesc;

    bssDesc = &work->mUnk_470[work->mUnk_d13];
    work->mUnk_d0d = GetConnectType(work);
    MI_CpuFill8(&work->mUnk_cb8, 0, 0x52);
    if (FillApWepKey(work, work->mUnk_d0d, &work->mUnk_cb8) != 0) {
        work->mUnk_d0b_2 = 1;
        if (((bssDesc->mUnk_2c >> 4) & 1) == 0) {
            work->mUnk_444[work->mUnk_d13].mUnk_00 = 3;
            return 9;
        }
        if (work->mUnk_d0d == 6 && bssDesc->mUnk_15 == 0) {
            work->mUnk_444[work->mUnk_d13].mUnk_00 = 3;
            return 9;
        }
    } else {
        work->mUnk_d0b_2 = 0;
        if (((bssDesc->mUnk_2c >> 4) & 1) == 1) {
            work->mUnk_444[work->mUnk_d13].mUnk_00 = 3;
            return 9;
        }
    }
    work->mUnk_d15 = 0;
    work->mUnk_d14 = 0;
    return 8;
}

u32 ConnectAP(ACWORK *work) {
    Unk02188ee0 *bssDesc;
    u32 powerMode;
    u32 connPhase;

    connPhase = func_ov000_021a5bfc();
    bssDesc = &work->mUnk_470[work->mUnk_d13];
    if (connPhase == 3) {
        powerMode = GetPowerMode(work);
        work->mUnk_d15++;
        if (work->mUnk_d15 > 3) {
            work->mUnk_d15 = 0;
            work->mUnk_444[work->mUnk_d13].mUnk_00 = 1;
            return 9;
        }
        if (work->mUnk_d15 != 1) {
            if (work->mUnk_d14 == 1) {
                work->mUnk_d0b_2 = 0;
            } else if (work->mUnk_d14 == 2) {
                work->mUnk_d15 = 0;
                work->mUnk_444[work->mUnk_d13].mUnk_00 = 3;
                return 9;
            } else if (work->mUnk_d14 == 3) {
                work->mUnk_d15 = 0;
                work->mUnk_444[work->mUnk_d13].mUnk_00 = 4;
                return 9;
            }
        }
        func_ov000_021a5e84((Unk021a5e84 *) bssDesc, &work->mUnk_cb8, powerMode | GetAuthMode(work));
    } else if (connPhase == 9) {
        work->mUnk_d15 = 0;
        work->mUnk_cb0 = OS_GetTick();
        return 10;
    }
    return 8;
}

u8 GetConnectType(ACWORK *work) {
    Unk02188ee0 *bssDesc;
    s32 apType;
    s32 i;
    s32 matchCount;

    bssDesc = &work->mUnk_470[work->mUnk_d13];
    apType = 0;
    if (work->mUnk_d0c_6 == 0) {
        matchCount = apType;
        if (bssDesc->mUnk_0a == 0x20) {
            apType = DWCi_AC_CheckNintendoSSID((Unk02188408Entry0xc0 *) bssDesc);
            if (apType > 0) {
                matchCount++;
            } else {
                apType = 0;
            }
        } else if (bssDesc->mUnk_0a == 8) {
            apType = DWCi_AC_CheckFreespot(bssDesc);
            if (apType != 0) {
                matchCount++;
            } else {
                apType = 0;
            }
        }
        for (i = 0; i < work->mUnk_d10; i++) {
            if (bssDesc->mUnk_0a == work->mUnk_300[i].mUnk_03 &&
                strncmp((const char *) bssDesc->mUnk_0c, (const char *) work->mUnk_300[i].mUnk_04, bssDesc->mUnk_0a) ==
                    0) {
                if (matchCount == 0) {
                    apType = work->mUnk_300[i].mUnk_01;
                } else {
                    work->mUnk_300[i].mUnk_00_hi = 1;
                    work->mUnk_d0c_6 = 1;
                }
                matchCount++;
            }
        }
    } else {
        i = apType;
        matchCount = apType;
        for (; i < work->mUnk_d10; i++) {
            if (work->mUnk_300[i].mUnk_00_hi == 1) {
                if (matchCount == 0) {
                    work->mUnk_300[i].mUnk_00_hi = 0;
                    apType = work->mUnk_300[i].mUnk_01;
                }
                matchCount++;
            }
        }
        if (matchCount == 1) {
            work->mUnk_d0c_6 = 0;
        }
    }
    return apType;
}
