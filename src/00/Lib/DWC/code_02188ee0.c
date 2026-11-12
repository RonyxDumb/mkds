#include "00/Lib/DWC/code_02188ee0.h"
#include "00/Lib/DWC/code_02188720.h"
#include "00/Lib/DWC/code_02188de4.h"
#include "00/Lib/DWC/code_02188ea0.h"
#include "00/unk_021b4000.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/DWC/code_021894e4.h"
#include "00/code_021a8aa8.h"
#include "os_tick.h"
#include "code_02139f70.h"
#include "code_0214d018.h"

s32 DisConnectAP(void) {
    switch (WCM_GetPhase()) {
        case 0:
            return 1;
        case 1:
            WCM_Finish();
            break;
        case 3:
            WCM_CleanupAsync();
            break;
        case 6:
            WCM_EndSearchAsync();
            break;
        case 9:
            WCM_DisconnectAsync();
            break;
        case 12:
            WCM_TerminateAsync();
            break;
        case 11:
            DWCi_AC_SetError(0);
            return -1;
    }
    return 0;
}

BOOL CloseAutoConnectSocket(void) {
    s32 result;

    result = SOC_Cleanup();
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
    WMBssDesc *bssDesc;

    bssDesc = &work->mBssDesc[work->mConnectNo];
    work->mConnectApType = GetConnectType(work);
    MI_CpuFill8(&work->mWepKey, 0, 0x52);
    if (FillApWepKey(work, work->mConnectApType, &work->mWepKey) != 0) {
        work->mAuthMode = 1;
        if (((bssDesc->mCapaInfo >> 4) & 1) == 0) {
            work->mFindList[work->mConnectNo].mState = 3;
            return 9;
        }
        if (work->mConnectApType == 6 && bssDesc->mSsid[9] == 0) {
            work->mFindList[work->mConnectNo].mState = 3;
            return 9;
        }
    } else {
        work->mAuthMode = 0;
        if (((bssDesc->mCapaInfo >> 4) & 1) == 1) {
            work->mFindList[work->mConnectNo].mState = 3;
            return 9;
        }
    }
    work->mCount = 0;
    work->mConnectResult = 0;
    return 8;
}

u32 ConnectAP(ACWORK *work) {
    WMBssDesc *bssDesc;
    u32 powerMode;
    u32 connPhase;

    connPhase = WCM_GetPhase();
    bssDesc = &work->mBssDesc[work->mConnectNo];
    if (connPhase == 3) {
        powerMode = GetPowerMode(work);
        work->mCount++;
        if (work->mCount > 3) {
            work->mCount = 0;
            work->mFindList[work->mConnectNo].mState = 1;
            return 9;
        }
        if (work->mCount != 1) {
            if (work->mConnectResult == 1) {
                work->mAuthMode = 0;
            } else if (work->mConnectResult == 2) {
                work->mCount = 0;
                work->mFindList[work->mConnectNo].mState = 3;
                return 9;
            } else if (work->mConnectResult == 3) {
                work->mCount = 0;
                work->mFindList[work->mConnectNo].mState = 4;
                return 9;
            }
        }
        WCM_ConnectAsync(bssDesc, &work->mWepKey, powerMode | GetAuthMode(work));
    } else if (connPhase == 9) {
        work->mCount = 0;
        work->mTimeOut = OS_GetTick();
        return 10;
    }
    return 8;
}

u8 GetConnectType(ACWORK *work) {
    WMBssDesc *bssDesc;
    s32 apType;
    s32 i;
    s32 matchCount;

    bssDesc = &work->mBssDesc[work->mConnectNo];
    apType = 0;
    if (work->mDuplicateFlag == 0) {
        matchCount = apType;
        if (bssDesc->mSsidLength == 0x20) {
            apType = DWCi_AC_CheckNintendoSSID(bssDesc);
            if (apType > 0) {
                matchCount++;
            } else {
                apType = 0;
            }
        } else if (bssDesc->mSsidLength == 8) {
            apType = DWCi_AC_CheckFreespot(bssDesc);
            if (apType != 0) {
                matchCount++;
            } else {
                apType = 0;
            }
        }
        for (i = 0; i < work->mSearchListNum; i++) {
            if (bssDesc->mSsidLength == work->mSearchList[i].mSsidLength &&
                strncmp((const char *) bssDesc->mSsid, (const char *) work->mSearchList[i].mSsid, bssDesc->mSsidLength) ==
                    0) {
                if (matchCount == 0) {
                    apType = work->mSearchList[i].mApType;
                } else {
                    work->mSearchList[i].mDuplicateMatch = 1;
                    work->mDuplicateFlag = 1;
                }
                matchCount++;
            }
        }
    } else {
        i = apType;
        matchCount = apType;
        for (; i < work->mSearchListNum; i++) {
            if (work->mSearchList[i].mDuplicateMatch == 1) {
                if (matchCount == 0) {
                    work->mSearchList[i].mDuplicateMatch = 0;
                    apType = work->mSearchList[i].mApType;
                }
                matchCount++;
            }
        }
        if (matchCount == 1) {
            work->mDuplicateFlag = 0;
        }
    }
    return apType;
}
