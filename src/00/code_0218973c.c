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
    WCM_SearchAsync(bssid, essid, mode | gAcSearchChannel[channel]);
}

u32 DWCi_AC_ConnectRetryAP(void) {
    ACWORK *work;
    u32 nextPhase;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    nextPhase = 9;
    switch (WCM_GetPhase()) {
        case 3:
            nextPhase = work->mPhaseBak;
            if (work->mDuplicateFlag == 1) {
                work->mFindList[work->mConnectNo].mState = 0;
                nextPhase = 7;
            } else if (nextPhase >= 3 && nextPhase <= 5) {
                DWCi_AC_SearchReStart(nextPhase);
            }
            break;
        case 6:
            WCM_EndSearchAsync();
            break;
        case 9:
            WCM_DisconnectAsync();
            break;
        case 12:
            WCM_TerminateAsync();
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
    MIi_CpuClear32(clearValue, work->mSearchList, 0x144);
    switch (type) {
        case 0:
            work->mSearchListNum = MakeAroundList(work);
            break;
        case 1:
            work->mSearchListNum =
                MakeDifferChannelList(work->mFindListNum, work->mFindList, work->mSearchList, work->mBssDesc);
            break;
        case 2:
            work->mSearchListNum = MakeStealthList(work);
            break;
    }
    return work->mSearchListNum;
}
