#include "00/Lib/NitroWiFi/wireless_connection_manager.h"
#include "00/Lib/DWC/access_point_connect.h"
#include "00/Lib/DWC/access_point_manager.h"
#include "00/Lib/DWC/access_point_wep_key.h"
#include "00/Lib/DWC/access_point_auth_mode.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/search_list_build.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "tick_counter.h"
#include "narrow_string_functions.h"
#include "cpu_copy_fill.h"

s32 DisConnectAP(void) {
    switch (WCM_GetPhase()) {
        case WIFI_LINK_PHASE_NONE:
            return 1;
        case WIFI_LINK_PHASE_STOPPED:
            WCM_Finish();
            break;
        case WIFI_LINK_PHASE_READY:
            WCM_CleanupAsync();
            break;
        case WIFI_LINK_PHASE_SEARCHING:
            WCM_EndSearchAsync();
            break;
        case WIFI_LINK_PHASE_CONNECTED:
            WCM_DisconnectAsync();
            break;
        case WIFI_LINK_PHASE_ABORT_PENDING:
            WCM_TerminateAsync();
            break;
        case WIFI_LINK_PHASE_FAILED:
            DWCi_AC_SetError(0);
            return -1;
    }
    return 0;
}

BOOL CleanupSocketApi(void) {
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
    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    switch (phase) {
        case AC_PHASE_CONNECT_START:
            phase = ConnectStart(work);
            break;
        case AC_PHASE_CONNECT_AP:
            phase = ConnectAP(work);
            break;
    }
    return phase;
}

u32 ConnectStart(ACWORK *work) {
    WMBssDesc *bssDesc;

    bssDesc = &work->mBssDesc[work->mConnectNo];
    work->mConnectApType = GetConnectType(work);
    MI_CpuFill8(&work->mWepKey, 0, sizeof(WCMWepDesc));
    if (FillApWepKey(work, work->mConnectApType, &work->mWepKey) != 0) {
        work->mAuthMode = 1;
        if (((bssDesc->mCapaInfo >> 4) & 1) == 0) {
            work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_ERROR_51100;
            return 9;
        }
        if (work->mConnectApType == AUTO_CONNECT_AP_TYPE_NWCUSBAP_SSID && bssDesc->mSsid[9] == 0) {
            work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_ERROR_51100;
            return 9;
        }
    } else {
        work->mAuthMode = 0;
        if (((bssDesc->mCapaInfo >> 4) & 1) == 1) {
            work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_ERROR_51100;
            return 9;
        }
    }
    work->mCount = 0;
    work->mConnectResult = AUTO_CONNECT_RESULT_NONE;
    return AC_PHASE_CONNECT_AP;
}

u32 ConnectAP(ACWORK *work) {
    WMBssDesc *bssDesc;
    u32 powerMode;
    u32 connPhase;

    connPhase = WCM_GetPhase();
    bssDesc = &work->mBssDesc[work->mConnectNo];
    if (connPhase == WIFI_LINK_PHASE_READY) {
        powerMode = GetPowerMode(work);
        work->mCount++;
        if (work->mCount > 3) {
            work->mCount = 0;
            work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_FAILED;
            return AC_PHASE_CONNECT_RETRY;
        }
        if (work->mCount != 1) {
            if (work->mConnectResult == AUTO_CONNECT_RESULT_RETRY_AUTH_FALLBACK) {
                work->mAuthMode = 0;
            } else if (work->mConnectResult == AUTO_CONNECT_RESULT_ERROR_51100) {
                work->mCount = 0;
                work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_ERROR_51100;
                return AC_PHASE_CONNECT_RETRY;
            } else if (work->mConnectResult == AUTO_CONNECT_RESULT_ERROR_51200) {
                work->mCount = 0;
                work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_ERROR_51200;
                return AC_PHASE_CONNECT_RETRY;
            }
        }
        WCM_ConnectAsync(bssDesc, &work->mWepKey, powerMode | GetAuthMode(work));
    } else if (connPhase == WIFI_LINK_PHASE_CONNECTED) {
        work->mCount = 0;
        work->mTimeOut = OS_GetTick();
        return AC_PHASE_TEST_START;
    }
    return AC_PHASE_CONNECT_AP;
}

u8 GetConnectType(ACWORK *work) {
    WMBssDesc *bssDesc;
    s32 apType;
    s32 searchIndex;
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
        for (searchIndex = 0; searchIndex < work->mSearchListNum; searchIndex++) {
            if (bssDesc->mSsidLength == work->mSearchList[searchIndex].mSsidLength &&
                strncmp((const char *) bssDesc->mSsid, (const char *) work->mSearchList[searchIndex].mSsid,
                        bssDesc->mSsidLength) == 0) {
                if (matchCount == 0) {
                    apType = work->mSearchList[searchIndex].mApType;
                } else {
                    work->mSearchList[searchIndex].mDuplicateMatch = 1;
                    work->mDuplicateFlag = 1;
                }
                matchCount++;
            }
        }
    } else {
        searchIndex = apType;
        matchCount = apType;
        for (; searchIndex < work->mSearchListNum; searchIndex++) {
            if (work->mSearchList[searchIndex].mDuplicateMatch == 1) {
                if (matchCount == 0) {
                    work->mSearchList[searchIndex].mDuplicateMatch = 0;
                    apType = work->mSearchList[searchIndex].mApType;
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
