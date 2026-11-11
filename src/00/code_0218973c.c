#include "00/code_0218973c.h"
#include "00/code_021894e4.h"
#include "00/code_021898dc.h"
#include "00/unk_021b4000.h"
#include "00/code_021884d8.h"
#include "00/code_02188ee0.h"
#include "00/unk_021b0000.h"
#include "code_0214d018.h"

void ScanStart(const u8 *bssid, const u8 *essid, s32 channel, u32 mode) {
    if (channel > 12) {
        channel = 12;
    }
    func_ov000_021a61c4(bssid, essid, mode | gAcSearchChannel[channel]);
}

u32 DWCi_AC_ConnectRetryAP(void) {
    ACWORK *work;
    u32 nextPhase;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    nextPhase = 9;
    switch (func_ov000_021a5bfc()) {
        case 3:
            nextPhase = work->mUnk_d0e;
            if (work->mUnk_d0c_6 == 1) {
                work->mUnk_444[work->mUnk_d13].mUnk_00 = 0;
                nextPhase = 7;
            } else if (nextPhase >= 3 && nextPhase <= 5) {
                DWCi_AC_SearchReStart(nextPhase);
            }
            break;
        case 6:
            func_ov000_021a6024();
            break;
        case 9:
            func_ov000_021a5db0();
            break;
        case 12:
            func_ov000_021a5c24();
            DWCi_AC_SetError(4);
            nextPhase = 0x11;
            break;
        case 11:
            DWCi_AC_SetError(0);
            nextPhase = 0x11;
            break;
    }
    return nextPhase;
}

u8 DWCi_AC_MakeSearchList(u32 type) {
    ACWORK *work;
    volatile u32 clearValue;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    clearValue = 0;
    MIi_CpuClear32(clearValue, work->mUnk_300, 0x144);
    switch (type) {
        case 0:
            work->mUnk_d10 = MakeAroundList(work);
            break;
        case 1:
            work->mUnk_d10 = MakeDifferChannelList(work->mUnk_d12, work->mUnk_444, work->mUnk_300, work->mUnk_470);
            break;
        case 2:
            work->mUnk_d10 = MakeStealthList(work);
            break;
    }
    return work->mUnk_d10;
}
