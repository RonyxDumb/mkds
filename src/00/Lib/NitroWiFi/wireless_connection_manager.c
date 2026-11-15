#include "00/Lib/NitroWiFi/wireless_connection_manager.h"

#include "00/Lib/GameSpy/query_key_register.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "wireless_link_control.h"
#include "00/Lib/NitroWiFi/wireless_connection_config.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "00/Lib/NitroWiFi/wifi_stack_bridge.h"
#include "00/Lib/NitroWiFi/rssi_link_level.h"
#include "signed_int_divide.h"
#include "wireless_system_commands.h"
#include "wireless_beacon_wep_settings.h"
#include "arena_cache_init.h"
#include "00/Lib/NitroWiFi/wireless_indication_callback.h"
#include "reset_interrupts_halt.h"
#include "00/Lib/NitroWiFi/wireless_connection_options.h"
#include "cpu_copy_fill.h"
#include "00/Lib/NitroWiFi/oldest_access_point.h"
#include "00/Lib/NitroWiFi/link_status.h"
#include "thread_scheduler.h"
#include "tick_counter.h"
#include "alarm_timer.h"
#include "03/Net/ap_scan_callback.h"

const u8 WCM_Essid_Any[32] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                              0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                              0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const u8 WCM_Bssid_Any[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
WCMWork *gWcmWork;

WCMApList *WcmSearchApList(const u8 *bssid) {
    WCMWork *work;
    WCMApListHeader *aplistHeader;
    WCMApList *apNode;

    work = WCMi_GetSystemWork();
    aplistHeader = work->mPbdBuffer;
    apNode = NULL;
    if (bssid == NULL) {
        return NULL;
    }
    if (aplistHeader != NULL && work->mNbdBuffer > 0xc) {
        for (apNode = aplistHeader->mHead; apNode != NULL; apNode = apNode->mNext) {
            if (WCM_CompareBssID((u8 *) (void *) apNode->mData + 4, bssid) != 0) {
                break;
            }
        }
    }
    return apNode;
}

WCMApList *WcmSearchIndexedApList(u32 index) {
    WCMWork *work;
    WCMApListHeader *aplistHeader;
    WCMApList *apNode;

    work = WCMi_GetSystemWork();
    aplistHeader = work->mPbdBuffer;
    apNode = NULL;
    if (aplistHeader != NULL && work->mNbdBuffer > 0xc) {
        for (apNode = aplistHeader->mHead; apNode != NULL; apNode = apNode->mNext) {
            if (apNode->mIndex == index) {
                break;
            }
        }
    }
    return apNode;
}

void WcmAppendApList(WCMApList *aplist) {
    WCMWork *work;
    WCMApListHeader *aplistHeader;
    WCMApList *entry;

    work = WCMi_GetSystemWork();
    aplistHeader = work->mPbdBuffer;
    if (aplist != NULL && aplistHeader != NULL && work->mNbdBuffer > 0xc) {
        for (entry = aplistHeader->mHead; entry != NULL; entry = entry->mNext) {
            if (entry == aplist) {
                if (entry->mPrevious != NULL) {
                    entry->mPrevious->mNext = entry->mNext;
                } else {
                    aplistHeader->mHead = entry->mNext;
                }
                if (entry->mNext != NULL) {
                    entry->mNext->mPrevious = entry->mPrevious;
                } else {
                    aplistHeader->mTail = entry->mPrevious;
                }
                break;
            }
        }
        aplist->mNext = NULL;
        aplist->mPrevious = aplistHeader->mTail;
        aplistHeader->mTail = aplist;
        if (aplist->mPrevious != NULL) {
            aplist->mPrevious->mNext = aplist;
        } else {
            aplistHeader->mHead = aplist;
        }
        if (entry == NULL) {
            aplist->mIndex = aplistHeader->mCount;
            aplistHeader->mCount++;
        }
    }
}

s32 WCM_Init(WCMWork *buf, u32 len) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (gWcmWork != NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (buf == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (((u32) buf & 0x1f) != 0) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (len < sizeof(WCMWork)) {
        OS_RestoreInterrupts(enabled);
        return 6;
    }
    gWcmWork = buf;
    buf->mPhase = WIFI_LINK_PHASE_STOPPED;
    gWcmWork->mNotifyId = WIFI_NOTIFY_NONE;
    gWcmWork->mMaxScanTime = 0;
    gWcmWork->mApListLock = 0;
    gWcmWork->mResetting = 0;
    gWcmWork->mAuthId = 0;
    gWcmWork->mWlStatusOnConnectFail = 0;
    WcmInitOption();
    WCMi_InitCpsif();
    if (OS_IsTickAvailable() == 0) {
        OS_InitTick();
    }
    if (OS_IsAlarmAvailable() == 0) {
        OS_InitAlarm();
    }
    OS_CreateAlarm(&gWcmWork->mKeepAliveAlarm);
    OS_RestoreInterrupts(enabled);
    return 0;
}

BOOL WCM_Finish(void) {
    u32 enabled;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    if (work->mPhase != WIFI_LINK_PHASE_STOPPED) {
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    gWcmWork = NULL;
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

s32 WCM_StartupAsync(WCMConfig *config, void (*notify)(WCMNotice *)) {
    u32 enabled;
    s32 result;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case WIFI_LINK_PHASE_STOPPED:
            WcmConfigure(config, notify);
            break;
        case WIFI_LINK_PHASE_STARTING:
            OS_RestoreInterrupts(enabled);
            return 2;
        case WIFI_LINK_PHASE_READY:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
    }
    switch (WM_Init(gWcmWork, gWcmWork->mDmaNo)) {
        case WIRELESS_RESULT_BAD_PHASE:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            OS_RestoreInterrupts(enabled);
            return 7;
        case WIRELESS_RESULT_SWITCHED_OFF:
            OS_RestoreInterrupts(enabled);
            return 5;
        case WIRELESS_RESULT_REFUSED:
        case WIRELESS_RESULT_OCCUPIED:
        case WIRELESS_RESULT_NOT_SET_UP:
        case WIRELESS_RESULT_BAD_INPUT:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            OS_RestoreInterrupts(enabled);
            return 7;
        case WIRELESS_RESULT_SUCCEEDED:
            break;
    }
    if (WM_GetAllowedChannel() == 0) {
        if (WM_Finish() != WIRELESS_RESULT_SUCCEEDED) {
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            OS_RestoreInterrupts(enabled);
            return 7;
        }
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    if (WM_SetIndCallback(WcmWmcbIndication) != WIRELESS_RESULT_SUCCEEDED) {
        WcmSetPhase(WIFI_LINK_PHASE_FAILED);
        OS_RestoreInterrupts(enabled);
        return 7;
    }
    result = WM_Enable(WcmWmcbCommon);
    switch (result) {
        case WIRELESS_CALL_QUEUED:
            WcmSetPhase(WIFI_LINK_PHASE_STARTING);
            gWcmWork->mNotifyId = WIFI_NOTIFY_ENABLE_REQUEST;
            break;
        case WIRELESS_RESULT_PIPE_ERROR:
            WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
            OS_RestoreInterrupts(enabled);
            return 1;
        case WIRELESS_RESULT_BAD_PHASE:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            OS_RestoreInterrupts(enabled);
            return 7;
    }
    OS_RestoreInterrupts(enabled);
    return 3;
}

s32 WCM_CleanupAsync(void) {
    u32 enabled;
    s32 result;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case WIFI_LINK_PHASE_STOPPING:
            OS_RestoreInterrupts(enabled);
            return 2;
        case WIFI_LINK_PHASE_STOPPED:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
        case WIFI_LINK_PHASE_READY:
            result = WM_PowerOff(WcmWmcbCommon);
            switch (result) {
                case WIRELESS_CALL_QUEUED:
                    WcmSetPhase(WIFI_LINK_PHASE_STOPPING);
                    gWcmWork->mNotifyId = WIFI_NOTIFY_POWER_OFF_REQUEST;
                    break;
                case WIRELESS_RESULT_PIPE_ERROR:
                    OS_RestoreInterrupts(enabled);
                    return 4;
                case WIRELESS_RESULT_BAD_PHASE:
                default:
                    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                    OS_RestoreInterrupts(enabled);
                    return 7;
            }
            OS_RestoreInterrupts(enabled);
            return 3;
    }
}

s32 WCM_SearchAsync(const void *bssid, const u8 *essid, u32 option) {
    if (bssid == NULL || essid == NULL) {
        return WCM_EndSearchAsync();
    }
    return WCM_BeginSearchAsync(bssid, essid, option);
}

s32 WCM_BeginSearchAsync(const void *bssid, const u8 *essid, u32 option) {
    u32 enabled;
    s32 result;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case WIFI_LINK_PHASE_SEARCH_STARTING:
            WcmEditScanExParam(bssid, essid, option);
            OS_RestoreInterrupts(enabled);
            return 2;
        case WIFI_LINK_PHASE_SEARCHING:
            WcmEditScanExParam(bssid, essid, option);
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
        case WIFI_LINK_PHASE_READY:
            WcmEditScanExParam(bssid, essid, option);
            DC_InvalidateRange(gWcmWork->mScanExParam.mScanBuf, gWcmWork->mScanExParam.mScanBufSize);
            gWcmWork->mScanCount++;
            result = WM_StartScanEx((WirelessMessageCallback) WcmWmcbScanEx, &gWcmWork->mScanExParam);
            switch (result) {
                case WIRELESS_CALL_QUEUED:
                    WcmSetPhase(WIFI_LINK_PHASE_SEARCH_STARTING);
                    gWcmWork->mNotifyId = WIFI_NOTIFY_SCAN_START_REQUEST;
                    break;
                case WIRELESS_RESULT_PIPE_ERROR:
                    OS_RestoreInterrupts(enabled);
                    return 4;
                case WIRELESS_RESULT_BAD_PHASE:
                default:
                    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                    OS_RestoreInterrupts(enabled);
                    return 7;
            }
            OS_RestoreInterrupts(enabled);
            return 3;
    }
}

s32 WCM_EndSearchAsync(void) {
    u32 enabled;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case WIFI_LINK_PHASE_SEARCHING:
            WcmSetPhase(WIFI_LINK_PHASE_SEARCH_STOPPING);
            gWcmWork->mNotifyId = WIFI_NOTIFY_SCAN_STOP_REQUEST;
            break;
        case WIFI_LINK_PHASE_SEARCH_STOPPING:
            OS_RestoreInterrupts(enabled);
            return 2;
        case WIFI_LINK_PHASE_READY:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 3;
}

s32 WCM_ConnectAsync(WMBssDesc *bssDesc, WCMWepDesc *wepDesc, u32 option) {
    u32 enabled;
    s32 result;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case WIFI_LINK_PHASE_READY:
            if (bssDesc == NULL) {
                OS_RestoreInterrupts(enabled);
                return 1;
            }
            if (bssDesc->mGameInfoLength != 0) {
                OS_RestoreInterrupts(enabled);
                return 1;
            }
            if (wepDesc != NULL) {
                if (wepDesc->mMode >= 4 || wepDesc->mKeyId >= 4) {
                    OS_RestoreInterrupts(enabled);
                    return 1;
                }
                work->mWepMode = wepDesc->mMode;
                gWcmWork->mWepKeyId = wepDesc->mKeyId;
                if (gWcmWork->mWepMode == 0) {
                    MI_CpuFill8(gWcmWork->mWepKey, 0, sizeof(gWcmWork->mWepKey));
                } else {
                    MI_CpuCopy8(wepDesc->mKey, gWcmWork->mWepKey, sizeof(gWcmWork->mWepKey));
                }
            } else {
                MI_CpuFill8(work->mWepKey, 0, sizeof(WCMWepDesc));
            }
            MI_CpuCopy8(bssDesc, &gWcmWork->mBssDesc, sizeof(gWcmWork->mBssDesc));
            gWcmWork->mBssDesc.mRateSet.mSupport = gWcmWork->mBssDesc.mRateSet.mBasic | 3;
            WCM_UpdateOption(option);
            break;
        case WIFI_LINK_PHASE_CONNECTING:
            OS_RestoreInterrupts(enabled);
            return 2;
        case WIFI_LINK_PHASE_CONNECTED:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
    }
    result = WM_SetLifeTime(WcmWmcbCommon, 0xffff, 0x50, 0xffff, 0xffff);
    switch (result) {
        case WIRELESS_CALL_QUEUED:
            WcmSetPhase(WIFI_LINK_PHASE_CONNECTING);
            gWcmWork->mNotifyId = WIFI_NOTIFY_CONNECT_REQUEST;
            break;
        case WIRELESS_RESULT_PIPE_ERROR:
            OS_RestoreInterrupts(enabled);
            return 4;
        case WIRELESS_RESULT_BAD_PHASE:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            OS_RestoreInterrupts(enabled);
            return 7;
    }
    OS_RestoreInterrupts(enabled);
    return 3;
}

s32 WCM_DisconnectAsync(void) {
    u32 enabled;
    s32 result;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case WIFI_LINK_PHASE_DISCONNECTING:
            OS_RestoreInterrupts(enabled);
            return 2;
        case WIFI_LINK_PHASE_READY:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
        case WIFI_LINK_PHASE_CONNECTED:
            break;
    }
    if (work->mResetting == 1) {
        WcmSetPhase(WIFI_LINK_PHASE_DISCONNECTING);
        gWcmWork->mNotifyId = WIFI_NOTIFY_DISCONNECT_REQUEST;
    } else {
        result = WM_EndDCF(WcmWmcbEndDCF);
        switch (result) {
            case WIRELESS_CALL_QUEUED:
                WcmSetPhase(WIFI_LINK_PHASE_DISCONNECTING);
                gWcmWork->mNotifyId = WIFI_NOTIFY_DISCONNECT_REQUEST;
                break;
            case WIRELESS_RESULT_PIPE_ERROR:
                OS_RestoreInterrupts(enabled);
                return 4;
            case WIRELESS_RESULT_BAD_PHASE:
            default:
                WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                OS_RestoreInterrupts(enabled);
                return 7;
        }
    }
    OS_RestoreInterrupts(enabled);
    return 3;
}

s32 WCM_TerminateAsync(void) {
    u32 enabled;
    s32 result;
    WCMWork *work;
    WMStatus *wmStatus;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case WIFI_LINK_PHASE_TERMINATING:
            OS_RestoreInterrupts(enabled);
            return 2;
        case WIFI_LINK_PHASE_STOPPED:
            OS_RestoreInterrupts(enabled);
            return 0;
        case WIFI_LINK_PHASE_SEARCHING:
            WcmSetPhase(WIFI_LINK_PHASE_TERMINATING);
            gWcmWork->mNotifyId = WIFI_NOTIFY_LINK_TERMINATING;
            OS_RestoreInterrupts(enabled);
            return 3;
        case WIFI_LINK_PHASE_READY:
        case WIFI_LINK_PHASE_CONNECTED:
        case WIFI_LINK_PHASE_ABORT_PENDING:
            break;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
    }
    if (work->mResetting == 1) {
        WcmSetPhase(WIFI_LINK_PHASE_TERMINATING);
        gWcmWork->mNotifyId = WIFI_NOTIFY_LINK_TERMINATING;
    } else {
        wmStatus = WMi_GetStatusAddress();
        DC_InvalidateRange(wmStatus, 2);
        switch (wmStatus->mState) {
            case WIRELESS_UNIT_STATE_DISABLED:
                result = WM_Finish();
                if (result == WIRELESS_RESULT_SUCCEEDED) {
                    WcmSetPhase(WIFI_LINK_PHASE_STOPPED);
                    gWcmWork->mNotifyId = WIFI_NOTIFY_NONE;
                    OS_RestoreInterrupts(enabled);
                    return 0;
                }
                break;
            case WIRELESS_UNIT_STATE_ENABLED:
                result = WM_Disable(WcmWmcbCommon);
                break;
            case WIRELESS_UNIT_STATE_POWERED_ON:
                result = WM_PowerOff(WcmWmcbCommon);
                break;
            default:
                gWcmWork->mResetting = 1;
                result = WM_Reset(WcmWmcbReset);
                break;
        }
        switch (result) {
            case WIRELESS_CALL_QUEUED:
                WcmSetPhase(WIFI_LINK_PHASE_TERMINATING);
                gWcmWork->mNotifyId = WIFI_NOTIFY_LINK_TERMINATING;
                break;
            case WIRELESS_RESULT_PIPE_ERROR:
                OS_RestoreInterrupts(enabled);
                return 4;
            case WIRELESS_RESULT_BAD_PHASE:
            default:
                WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                OS_RestoreInterrupts(enabled);
                return 7;
        }
    }
    OS_RestoreInterrupts(enabled);
    return 3;
}

u32 WCM_GetPhase(void) {
    u32 enabled;
    u32 connPhase;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    connPhase = WIFI_LINK_PHASE_NONE;
    work = gWcmWork;
    if (work != NULL) {
        connPhase = work->mPhase;
    }
    OS_RestoreInterrupts(enabled);
    return connPhase;
}

u32 WCM_UpdateOption(u32 option) {
    u32 enabled;
    u32 clearMask;
    u32 previousOption;
    WCMWork *work;

    enabled = OS_DisableInterrupts();
    clearMask = 0;
    work = gWcmWork;
    previousOption = work->mOption;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (option & 0x8000) {
        clearMask |= 0x3ffe;
        if ((option & 0x3ffe) == 0) {
            option |= 0xa082;
        }
    }
    if (option & 0x20000) {
        clearMask |= 0x10000;
    }
    if (option & 0x80000) {
        clearMask |= 0x40000;
    }
    if (option & 0x200000) {
        clearMask |= 0x100000;
    }
    if (option & 0x800000) {
        clearMask |= 0x400000;
    }
    work->mOption = option | (previousOption & ~clearMask);
    OS_RestoreInterrupts(enabled);
    return previousOption;
}

WCMWork *WCMi_GetSystemWork(void) {
    return gWcmWork;
}

void WcmConfigure(WCMConfig *config, void (*notify)(WCMNotice *)) {
    u8 *bufferStart;

    if (config == NULL) {
        gWcmWork->mDmaNo = 3;
        gWcmWork->mPbdBuffer = NULL;
        gWcmWork->mNbdBuffer = 0;
        gWcmWork->mNbdMode = 0;
    } else {
        gWcmWork->mDmaNo = config->mDmaNo & 3;
        bufferStart = config->mPbdBuffer;
        if ((((4 - ((u32) bufferStart & 3)) & 3) + 0xc) > config->mNbdBuffer) {
            gWcmWork->mPbdBuffer = NULL;
            gWcmWork->mNbdBuffer = 0;
        } else {
            gWcmWork->mPbdBuffer = (WCMApListHeader *) (((u32) bufferStart + 3) & ~3);
            gWcmWork->mNbdBuffer = config->mNbdBuffer - ((4 - ((u32) config->mPbdBuffer & 3)) & 3);
            MI_CpuFill8(gWcmWork->mPbdBuffer, 0, gWcmWork->mNbdBuffer);
        }
        gWcmWork->mNbdMode = config->mNbdMode;
    }
    gWcmWork->mNotify = notify;
}

void WcmEditScanExParam(const void *bssid, const u8 *essid, u32 option) {
    u16 maxChannelTime;
    s32 essidLength;

    WCM_UpdateOption(option);
    gWcmWork->mScanExParam.mScanBuf = gWcmWork->mRecvBuf;
    gWcmWork->mScanExParam.mScanBufSize = 0x400;
    gWcmWork->mScanExParam.mChannelList = (1 << WcmGetNextScanChannel(0)) >> 1;
    maxChannelTime = gWcmWork->mMaxScanTime;
    if (maxChannelTime == 0) {
        maxChannelTime = WM_GetDispersionScanPeriod();
    }
    gWcmWork->mScanExParam.mMaxChannelTime = maxChannelTime;
    gWcmWork->mScanExParam.mScanType = (gWcmWork->mOption & WCM_OPTION_MASK_SCANTYPE) != WCM_OPTION_MASK_SCANTYPE;
    if (bssid == NULL) {
        MI_CpuCopy8(WCM_Bssid_Any, gWcmWork->mScanExParam.mBssid, 6);
    } else {
        MI_CpuCopy8(bssid, gWcmWork->mScanExParam.mBssid, 6);
    }
    if (essid == NULL || essid == WCM_Essid_Any) {
        MI_CpuCopy8(WCM_Essid_Any, gWcmWork->mScanExParam.mSsid, sizeof(gWcmWork->mScanExParam.mSsid));
        gWcmWork->mScanExParam.mSsidLength = 0;
    } else {
        MI_CpuCopy8(essid, gWcmWork->mScanExParam.mSsid, sizeof(gWcmWork->mScanExParam.mSsid));
        for (essidLength = 0; essidLength < 0x20; essidLength++) {
            if (*essid == 0) {
                break;
            }
            essid++;
        }
        gWcmWork->mScanExParam.mSsidLength = essidLength;
    }
    gWcmWork->mScanCount = 0;
}

void WcmInitOption(void) {
    gWcmWork->mOption = WCM_OPTION_ROUNDSCAN_IGNORE | WCM_OPTION_SCANTYPE_PASSIVE | WCM_OPTION_AUTH_OPENSYSTEM |
                        WCM_OPTION_POWER_SAVE | WCM_OPTION_CHANNEL_RDC;
}

u16 WcmGetNextScanChannel(u16 channel) {
    s32 offset;
    s32 candidate;
    u32 option;

    offset = 0;
    candidate = channel;
    option = gWcmWork->mOption;
    do {
        if (option & (1 << (candidate % 13 + 1))) {
            break;
        }
        candidate++;
        offset++;
    } while (offset < 13);
    return (channel + offset) % 13 + 1;
}

void WcmNotify(u32 result, const void *para0, u32 para1, u32 para2) {
    s16 savedId;

    savedId = gWcmWork->mNotifyId;
    gWcmWork->mNotifyId = WIFI_NOTIFY_NONE;
    WcmNotifyEx(savedId, result, para0, para1, para2);
}

void WcmNotifyEx(s16 notify, u32 result, void *para0, u32 para1, u32 para2) {
    WCMNotice noticeRec;

    if (gWcmWork->mNotify != NULL) {
        noticeRec.mNotify = notify;
        noticeRec.mResult = result;
        noticeRec.mParameter0 = para0;
        noticeRec.mParameter1 = para1;
        noticeRec.mParameter2 = para2;
        gWcmWork->mNotify(&noticeRec);
    }
}

void WcmSetPhase(u32 phase) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (gWcmWork->mPhase == WIFI_LINK_PHASE_CONNECTED && phase != WIFI_LINK_PHASE_CONNECTED) {
        OS_CancelAlarm(&gWcmWork->mKeepAliveAlarm);
    }
    if (gWcmWork->mPhase != WIFI_LINK_PHASE_FAILED) {
        gWcmWork->mPhase = phase;
    }
    if (phase == WIFI_LINK_PHASE_CONNECTED) {
        OS_SetAlarm(&gWcmWork->mKeepAliveAlarm, 0x22f5341, WcmKeepAliveAlarm, NULL);
    }
    OS_RestoreInterrupts(enabled);
}

void WCMi_ResetKeepAliveAlarm(void) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    OS_CancelAlarm(&gWcmWork->mKeepAliveAlarm);
    if (gWcmWork->mPhase == WIFI_LINK_PHASE_CONNECTED) {
        OS_SetAlarm(&gWcmWork->mKeepAliveAlarm, 0x22f5341, WcmKeepAliveAlarm, NULL);
    }
    OS_RestoreInterrupts(enabled);
}

void WcmKeepAliveAlarm(void *arg) {
    WCMi_CpsifSendNullPacket();
    WCMi_ResetKeepAliveAlarm();
}

void WcmWmReset(void) {
    if (gWcmWork->mResetting == 0) {
        gWcmWork->mResetting = 1;
        if (WM_Reset(WcmWmcbReset) != WIRELESS_CALL_QUEUED) {
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE, NULL, 0, 0x611);
        }
    }
}

void WcmWmcbIndication(WirelessMessage *callback) {
    if (callback->mResultCode == WIRELESS_RESULT_PIPE_ERROR && callback->mState == WIRELESS_STATE_EVENT_FATAL &&
        callback->mPort == 0x25) {
        switch (gWcmWork->mPhase) {
            case WIFI_LINK_PHASE_CONNECTING:
                WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                return;
            case WIFI_LINK_PHASE_CONNECTED:
            case WIFI_LINK_PHASE_ABORT_PENDING:
                WcmWmReset();
                return;
            case WIFI_LINK_PHASE_DISCONNECTING:
                WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                break;
        }
    }
}

void WcmWmcbCommon(WirelessMessage *callback) {
    WCMWork *work;
    s32 result = 0x14;

    switch (callback->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            switch (callback->mCommand) {
                case WIRELESS_REQUEST_ACTIVATE:
                    result = WM_PowerOn(WcmWmcbCommon);
                    break;
                case WIRELESS_REQUEST_DEACTIVATE:
                    switch (WM_Finish()) {
                        case WIRELESS_RESULT_SUCCEEDED:
                            WcmSetPhase(WIFI_LINK_PHASE_STOPPED);
                            WcmNotify(WIFI_REPORT_SUCCEEDED, NULL, 0, 0x663);
                            return;
                        case WIRELESS_RESULT_SWITCHED_OFF:
                        default:
                            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                            WcmNotify(WIFI_REPORT_UNRECOVERABLE, NULL, 0, 0x66a);
                            return;
                    }
                case WIRELESS_REQUEST_RADIO_ON:
                    WcmSetPhase(WIFI_LINK_PHASE_READY);
                    WcmNotify(WIFI_REPORT_SUCCEEDED, NULL, 0, 0x670);
                    return;
                case WIRELESS_REQUEST_RADIO_OFF:
                    result = WM_Disable(WcmWmcbCommon);
                    break;
                case WIRELESS_REQUEST_SET_TIMEOUT:
                    result = WM_SetBeaconIndication(WcmWmcbCommon, 0);
                    break;
                case WIRELESS_REQUEST_WATCH_BEACONS:
                    work = gWcmWork;
                    result = WM_SetWEPKeyEx(WcmWmcbCommon, work->mWepMode, work->mWepKeyId, work->mWepKey);
                    break;
                case WIRELESS_REQUEST_SET_CIPHER_KEY: {
                    u32 option;
                    u16 authMode;
                    u32 powerSave;
                    work = gWcmWork;
                    option = work->mOption;
                    authMode = (option & 0xc0000) == 0xc0000;
                    powerSave = (option & 0x30000) != 0x30000 ? 1 : 0;
                    result = WM_StartConnectEx((WirelessMessageCallback) WcmWmcbConnect, &work->mBssDesc, NULL,
                                               powerSave, authMode);
                    break;
                }
            }
            if (result == WIRELESS_CALL_QUEUED) {
                return;
            }
            switch (result) {
                case WIRELESS_RESULT_PIPE_ERROR:
                    WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                    WcmNotify(WIFI_REPORT_DECLINED,
                              gWcmWork->mNotifyId == WIFI_NOTIFY_CONNECT_REQUEST ? &gWcmWork->mBssDesc : 0, 0, 0x6a7);
                    return;
                case WIRELESS_RESULT_BAD_PHASE:
                default:
                    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                    WcmNotify(WIFI_REPORT_UNRECOVERABLE,
                              gWcmWork->mNotifyId == WIFI_NOTIFY_CONNECT_REQUEST ? &gWcmWork->mBssDesc : 0, 0, 0x6b0);
                    return;
            }
            break;
        case WIRELESS_RESULT_REFUSED:
            WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
            WcmNotify(WIFI_REPORT_DECLINED,
                      gWcmWork->mNotifyId == WIFI_NOTIFY_CONNECT_REQUEST ? &gWcmWork->mBssDesc : 0, 0, 0x6d0);
            return;
        case WIRELESS_RESULT_OCCUPIED:
        case WIRELESS_RESULT_BAD_PHASE:
        case WIRELESS_RESULT_SWITCHED_OFF:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE,
                      gWcmWork->mNotifyId == WIFI_NOTIFY_CONNECT_REQUEST ? &gWcmWork->mBssDesc : 0, 0, 0x6da);
            return;
    }
}

// Kept as asm: it counts leading zeros with clz.
// clang-format off
#pragma thumb off
asm u32 WcmCountBits(u32 bits) {
    mov r1, r0
    mov r0, #0
    mov r3, #1
count_bits:
    clz r2, r1
    rsbs r2, r2, #31
    bxlo lr
    bic r1, r1, r3, lsl r2
    add r0, r0, #1
    b count_bits
}

asm u32 WcmCountLeadingZero(u32 value) {
    clz r0, r0
    bx lr
}
#pragma thumb on
// clang-format on

void WcmWmcbScanEx(WMStartScanExCallback *callback) {
    s32 result;
    s32 index;
    u32 option;
    u32 channelCount;
    u32 scanCount;

    result = 0x14;
    switch (callback->mErrcode) {
        case WIRELESS_RESULT_SUCCEEDED:
            if (gWcmWork->mPhase == WIFI_LINK_PHASE_SEARCH_STARTING) {
                WcmSetPhase(WIFI_LINK_PHASE_SEARCHING);
                WcmNotify(WIFI_REPORT_SUCCEEDED, 0, 0, 0x6f6);
            }
            switch (gWcmWork->mPhase) {
                case WIFI_LINK_PHASE_SEARCHING:
                    gWcmWork->mNotifyId = WIFI_NOTIFY_SEARCH_FOUND;
                    if (callback->mState == WIRELESS_STATE_HOST_SIGHTED) {
                        DC_InvalidateRange(gWcmWork->mScanExParam.mScanBuf, gWcmWork->mScanExParam.mScanBufSize);
                        for (index = 0; index < callback->mBssDescCount; index++) {
                            WCMi_EntryApList(callback->mBssDesc[index], callback->mLinkLevel[index]);
                            WcmNotifyEx(WIFI_NOTIFY_SEARCH_FOUND, WIFI_REPORT_SUCCEEDED, callback->mBssDesc[index],
                                        (u32) callback, 0x70b);
                        }
                    }
                    option = gWcmWork->mOption;
                    if ((option & 0xc00000) == 0xc00000) {
                        channelCount = WcmCountBits(option & 0x3ffe);
                        if (channelCount != 0) {
                            scanCount = gWcmWork->mScanCount;
                            if (scanCount % channelCount == 0) {
                                WcmNotifyEx(WIFI_NOTIFY_SCAN_ROUND, WIFI_REPORT_SUCCEEDED, (void *) scanCount, 0,
                                            0x718);
                            }
                        }
                    }
                    gWcmWork->mScanExParam.mChannelList =
                        (1 << WcmGetNextScanChannel(32 - WcmCountLeadingZero(callback->mChannelList))) >> 1;
                    DC_InvalidateRange(gWcmWork->mScanExParam.mScanBuf, gWcmWork->mScanExParam.mScanBufSize);
                    gWcmWork->mScanCount++;
                    result = WM_StartScanEx((WirelessMessageCallback) WcmWmcbScanEx, &gWcmWork->mScanExParam);
                    break;
                case WIFI_LINK_PHASE_SEARCH_STOPPING:
                    result = WM_EndScan(WcmWmcbEndScan);
                    break;
                case WIFI_LINK_PHASE_TERMINATING:
                    WcmWmReset();
                    return;
            }
            switch (result) {
                case WIRELESS_CALL_QUEUED:
                    return;
                case WIRELESS_RESULT_PIPE_ERROR:
                    WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                    WcmNotify(WIFI_REPORT_DECLINED, 0, 0, 0x743);
                    return;
                case WIRELESS_RESULT_BAD_PHASE:
                default:
                    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                    WcmNotify(WIFI_REPORT_UNRECOVERABLE, 0, 0, 0x74c);
                    return;
            }
        case WIRELESS_RESULT_REFUSED:
            WcmWmReset();
            return;
        case WIRELESS_RESULT_OCCUPIED:
        case WIRELESS_RESULT_BAD_PHASE:
        case WIRELESS_RESULT_SWITCHED_OFF:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE, 0, 0, 0x75d);
            return;
    }
}

void WcmWmcbEndScan(WirelessMessage *callback) {
    switch (callback->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            WcmSetPhase(WIFI_LINK_PHASE_READY);
            WcmNotify(WIFI_REPORT_SUCCEEDED, 0, 0, 0x774);
            return;
        case WIRELESS_RESULT_REFUSED:
            WcmWmReset();
            return;
        case WIRELESS_RESULT_OCCUPIED:
        case WIRELESS_RESULT_BAD_PHASE:
        case WIRELESS_RESULT_SWITCHED_OFF:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE, 0, 0, 0x784);
            return;
    }
}

void WcmWmcbConnect(WMStartConnectCallback *callback) {
    u16 authId;
    s32 result;

    switch (callback->mErrCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            switch (callback->mState) {
                case WIRELESS_STATE_CHILD_NO_ACTION:
                case WIRELESS_STATE_UNLINKED:
                    switch (gWcmWork->mPhase - WIFI_LINK_PHASE_CONNECTING) {
                        case WIFI_LINK_PHASE_DISCONNECTING - WIFI_LINK_PHASE_CONNECTING:
                            gWcmWork->mAuthId = 0;
                        case WIFI_LINK_PHASE_CONNECTING - WIFI_LINK_PHASE_CONNECTING:
                            WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                            return;
                        case WIFI_LINK_PHASE_CONNECTED - WIFI_LINK_PHASE_CONNECTING:
                            gWcmWork->mAuthId = 0;
                            gWcmWork->mNotifyId = WIFI_NOTIFY_DISCONNECT_REQUEST;
                        case WIFI_LINK_PHASE_ABORT_PENDING - WIFI_LINK_PHASE_CONNECTING:
                            WcmWmReset();
                            return;
                        default:
                            break;
                    }
                    break;
                case WIRELESS_STATE_LINKED:
                    if (gWcmWork->mPhase == WIFI_LINK_PHASE_ABORT_PENDING) {
                        WcmSetPhase(WIFI_LINK_PHASE_CONNECTING);
                        WcmWmReset();
                        return;
                    }
                    authId = callback->mAid;
                    if (authId >= 1 && authId <= 0x7d7) {
                        gWcmWork->mAuthId = authId;
                        result = WM_StartDCF(WcmWmcbStartDCF, &gWcmWork->mWmWork[0x1500], 0x620);
                        switch (result) {
                            case WIRELESS_CALL_QUEUED:
                                return;
                            case WIRELESS_RESULT_PIPE_ERROR:
                                WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                                WcmNotify(WIFI_REPORT_DECLINED, &gWcmWork->mBssDesc, 0, 0x7d7);
                                return;
                            case WIRELESS_RESULT_BAD_PHASE:
                            default:
                                WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                                WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, 0, 0x7e0);
                                return;
                        }
                    }
                    WcmWmReset();
                    return;
                case WIRELESS_STATE_CHILD_SESSION_START:
                    break;
                default:
                    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                    WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, callback->mState, 0x7ee);
                    return;
            }
            break;
        case WIRELESS_RESULT_REFUSED:
            gWcmWork->mWlStatusOnConnectFail = callback->mWlStatus;
        case WIRELESS_RESULT_BAD_INPUT:
        case WIRELESS_RESULT_NOT_LISTED:
        case WIRELESS_RESULT_LIST_FULL:
            WcmSetPhase(WIFI_LINK_PHASE_CONNECTING);
            WcmWmReset();
            return;
        case WIRELESS_RESULT_OCCUPIED:
        case WIRELESS_RESULT_BAD_PHASE:
        case WIRELESS_RESULT_SWITCHED_OFF:
        case WIRELESS_RESULT_NOT_SET_UP:
        case WIRELESS_RESULT_NO_REMOTE:
        case WIRELESS_RESULT_PIPE_ERROR:
        case WIRELESS_RESULT_NO_ANSWER:
        case WIRELESS_RESULT_SEND_BACKLOG:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, 0, 0x804);
            return;
    }
}

void WcmWmcbDisconnect(WirelessMessage *callback) {
    switch (callback->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            if (gWcmWork->mPhase == WIFI_LINK_PHASE_ABORT_PENDING) {
                WcmSetPhase(WIFI_LINK_PHASE_DISCONNECTING);
                WcmWmReset();
                return;
            }
            gWcmWork->mAuthId = 0;
            WcmSetPhase(WIFI_LINK_PHASE_READY);
            WcmNotify(WIFI_REPORT_SUCCEEDED, &gWcmWork->mBssDesc, 0, 0x827);
            return;
        case WIRELESS_RESULT_REFUSED:
        case WIRELESS_RESULT_BAD_PHASE:
            WcmSetPhase(WIFI_LINK_PHASE_DISCONNECTING);
            WcmWmReset();
            return;
        case WIRELESS_RESULT_OCCUPIED:
        case WIRELESS_RESULT_SWITCHED_OFF:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, 0, 0x839);
            return;
    }
}

void WcmWmcbStartDCF(WirelessMessage *callback) {
    switch (callback->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            switch (callback->mState) {
                case WIRELESS_STATE_DCF_RUNNING:
                    if (gWcmWork->mPhase == WIFI_LINK_PHASE_ABORT_PENDING) {
                        WcmSetPhase(WIFI_LINK_PHASE_CONNECTING);
                        WcmWmReset();
                        return;
                    }
                    WcmSetPhase(WIFI_LINK_PHASE_CONNECTED);
                    WcmNotify(WIFI_REPORT_SUCCEEDED, &gWcmWork->mBssDesc, 0, 0x85d);
                    return;
                case WIRELESS_STATE_DCF_FRAME_RECEIVED:
                    WCMi_ShelterRssi(((u16 *) callback->mRecvBuf)[7] >> 8);
                    DC_InvalidateRange(callback->mRecvBuf, 0x620);
                    WCMi_CpsifRecvCallback(callback->mRecvBuf);
                    return;
                default:
                    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                    WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, callback->mState, 0x86b);
                    return;
            }
        case WIRELESS_RESULT_SWITCHED_OFF:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, 0, 0x877);
            return;
    }
}

void WcmWmcbEndDCF(WirelessMessage *callback) {
    s32 result;

    switch (callback->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            if (gWcmWork->mPhase == WIFI_LINK_PHASE_ABORT_PENDING) {
                WcmSetPhase(WIFI_LINK_PHASE_DISCONNECTING);
                WcmWmReset();
                return;
            }
            result = WM_Disconnect(WcmWmcbDisconnect, 0);
            switch (result) {
                case WIRELESS_CALL_QUEUED:
                    return;
                case WIRELESS_RESULT_PIPE_ERROR:
                    WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                    WcmNotify(WIFI_REPORT_DECLINED, &gWcmWork->mBssDesc, 0, 0x8a0);
                    return;
                case WIRELESS_RESULT_BAD_PHASE:
                    WcmSetPhase(WIFI_LINK_PHASE_DISCONNECTING);
                    WcmWmReset();
                    return;
                default:
                    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                    WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, 0, 0x8ac);
                    return;
            }
        case WIRELESS_RESULT_REFUSED:
        case WIRELESS_RESULT_BAD_PHASE:
            WcmSetPhase(WIFI_LINK_PHASE_DISCONNECTING);
            WcmWmReset();
            return;
        case WIRELESS_RESULT_OCCUPIED:
        case WIRELESS_RESULT_SWITCHED_OFF:
        default:
            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
            WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, 0, 0x8bf);
            return;
    }
}

void WcmWmcbReset(WirelessMessage *callback) {
    u16 failStatus;
    u32 sharedKeyFlag;
    u32 powerSave;
    s32 result;
    u16 authMode;

    if (callback->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        gWcmWork->mResetting = 0;
        gWcmWork->mAuthId = 0;
        switch (gWcmWork->mPhase) {
            case WIFI_LINK_PHASE_SEARCH_STARTING:
            case WIFI_LINK_PHASE_SEARCHING:
                WcmSetPhase(WIFI_LINK_PHASE_READY);
                WcmNotify(WIFI_REPORT_DECLINED, 0, 0, 0x8e1);
                return;
            case WIFI_LINK_PHASE_SEARCH_STOPPING:
                WcmSetPhase(WIFI_LINK_PHASE_READY);
                WcmNotify(WIFI_REPORT_SUCCEEDED, 0, 0, 0x8e7);
                return;
            case WIFI_LINK_PHASE_CONNECTING:
                failStatus = gWcmWork->mWlStatusOnConnectFail;
                gWcmWork->mWlStatusOnConnectFail = 0;
                if (failStatus == 0x12 &&
                    (gWcmWork->mBssDesc.mRateSet.mSupport & WCM_CAMOUFLAGE_RATESET) != WCM_CAMOUFLAGE_RATESET) {
                    gWcmWork->mBssDesc.mRateSet.mSupport |= WCM_CAMOUFLAGE_RATESET;
                    sharedKeyFlag = 0;
                    if ((gWcmWork->mOption & WCM_OPTION_MASK_AUTH) == WCM_OPTION_MASK_AUTH) {
                        sharedKeyFlag = 1;
                    }
                    authMode = sharedKeyFlag;
                    if ((gWcmWork->mOption & WCM_OPTION_MASK_POWER) == WCM_OPTION_MASK_POWER) {
                        powerSave = 0;
                    } else {
                        powerSave = 1;
                    }
                    result = WM_StartConnectEx((WirelessMessageCallback) WcmWmcbConnect, &gWcmWork->mBssDesc, 0,
                                               powerSave, authMode);
                    switch (result) {
                        case WIRELESS_CALL_QUEUED:
                            return;
                        case WIRELESS_RESULT_PIPE_ERROR:
                            WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                            WcmNotify(WIFI_REPORT_DECLINED, &gWcmWork->mBssDesc, failStatus, 0x905);
                            return;
                        case WIRELESS_RESULT_BAD_PHASE:
                        default:
                            WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                            WcmNotify(WIFI_REPORT_UNRECOVERABLE, &gWcmWork->mBssDesc, failStatus, 0x90c);
                            return;
                    }
                }
                WcmSetPhase(WIFI_LINK_PHASE_READY);
                WcmNotify(WIFI_REPORT_DECLINED, &gWcmWork->mBssDesc, failStatus, 0x913);
                return;
            case WIFI_LINK_PHASE_CONNECTED:
            case WIFI_LINK_PHASE_ABORT_PENDING:
                WcmSetPhase(WIFI_LINK_PHASE_READY);
                WcmNotify(WIFI_REPORT_SUCCEEDED, &gWcmWork->mBssDesc, 1, 0x91b);
                return;
            case WIFI_LINK_PHASE_DISCONNECTING:
                WcmSetPhase(WIFI_LINK_PHASE_READY);
                WcmNotify(WIFI_REPORT_SUCCEEDED, &gWcmWork->mBssDesc, 0, 0x922);
                return;
            case WIFI_LINK_PHASE_TERMINATING:
                result = WM_PowerOff(WcmWmcbCommon);
                switch (result) {
                    case WIRELESS_CALL_QUEUED:
                        return;
                    case WIRELESS_RESULT_PIPE_ERROR:
                        WcmSetPhase(WIFI_LINK_PHASE_ABORT_PENDING);
                        WcmNotify(WIFI_REPORT_DECLINED, 0, 0, 0x930);
                        return;
                    case WIRELESS_RESULT_BAD_PHASE:
                    default:
                        WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                        WcmNotify(WIFI_REPORT_UNRECOVERABLE, 0, 0, 0x939);
                        return;
                }
            default:
                WcmSetPhase(WIFI_LINK_PHASE_FAILED);
                WcmNotify(WIFI_REPORT_UNRECOVERABLE, 0, gWcmWork->mPhase, 0x93f);
                return;
        }
    }
    WcmSetPhase(WIFI_LINK_PHASE_FAILED);
    WcmNotify(WIFI_REPORT_UNRECOVERABLE, 0, 0, 0x946);
}
