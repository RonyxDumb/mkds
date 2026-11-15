#include "00/Lib/NitroWiFi/wireless_connection_control.h"
#include "00/Lib/DWC/access_point_scan.h"
#include "00/Lib/DWC/search_list_build.h"
#include "00/Lib/DWC/access_point_search.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/access_point_connect.h"
#include "00/Lib/NitroWiFi/wcm_search_defaults.h"
#include "cpu_copy_fill.h"

const u32 gAcSearchChannel[13] = {0x8002, 0x8004, 0x8008, 0x8010, 0x8020, 0x8040, 0x8080,
                                  0x8100, 0x8200, 0x8400, 0x8800, 0x9000, 0xa000};

void ScanStart(const u8 *bssid, const u8 *essid, s32 channel, u32 mode) {
    if (channel > 12) {
        channel = 12;
    }
    WCM_SearchAsync(bssid, essid, mode | gAcSearchChannel[channel]);
}

u32 DWCi_AC_ConnectRetryAP(void) {
    ACWORK *work;
    u32 nextPhase;

    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    nextPhase = AC_PHASE_CONNECT_RETRY;
    switch (WCM_GetPhase()) {
        case WIFI_LINK_PHASE_READY:
            nextPhase = work->mPhaseBak;
            if (work->mDuplicateFlag == 1) {
                work->mFindList[work->mConnectNo].mState = 0;
                nextPhase = AC_PHASE_CONNECT_START;
            } else if (nextPhase >= AC_PHASE_SEARCH_AROUND && nextPhase <= AC_PHASE_SEARCH_HIDDEN) {
                DWCi_AC_SearchReStart(nextPhase);
            }
            break;
        case WIFI_LINK_PHASE_SEARCHING:
            WCM_EndSearchAsync();
            break;
        case WIFI_LINK_PHASE_CONNECTED:
            WCM_DisconnectAsync();
            break;
        case WIFI_LINK_PHASE_ABORT_PENDING:
            WCM_TerminateAsync();
            DWCi_AC_SetError(4);
            nextPhase = AC_PHASE_ERROR;
            break;
        case WIFI_LINK_PHASE_FAILED:
            DWCi_AC_SetError(0);
            nextPhase = AC_PHASE_ERROR;
            break;
    }
    return nextPhase;
}

u8 DWCi_AC_MakeSearchList(u32 type) {
    ACWORK *work;
    volatile u32 clearValue;

    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    clearValue = 0;
    MIi_CpuClear32(clearValue, work->mSearchList, 0x144);
    switch (type) {
        case AC_SEARCH_LIST_AROUND:
            work->mSearchListNum = MakeAroundList(work);
            break;
        case AC_SEARCH_LIST_OTHER_CHANNELS:
            work->mSearchListNum =
                MakeDifferChannelList(work->mFindListNum, work->mFindList, work->mSearchList, work->mBssDesc);
            break;
        case AC_SEARCH_LIST_HIDDEN:
            work->mSearchListNum = MakeStealthList(work);
            break;
    }
    return work->mSearchListNum;
}
