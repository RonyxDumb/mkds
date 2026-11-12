#include "00/Lib/NitroWiFi/code_021a4b98.h"

#include "00/Lib/GameSpy/code_021a4b84.h"
#include "00/code_021a4000.h"
#include "00/code_021a5000.h"
#include "00/code_021a6000.h"
#include "00/unk_021b5000.h"
#include "code_02142eac.h"
#include "00/code_021a574c.h"
#include "00/Lib/NitroWiFi/code_021a669c.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/Lib/NitroWiFi/util.h"
#include "code_02133048.h"
#include "wm_system.h"
#include "wm_etc.h"
#include "code_0200eddc.h"
#include "00/code_021a54b0.h"
#include "code_0200fc8c.h"
#include "00/code_021a5b3c.h"
#include "code_0214d018.h"
#include "00/Lib/NitroWiFi/code_021a666c.h"
#include "00/Lib/NitroWiFi/code_021a6d1c.h"
#include "Main/Unknown/code_0200e000.h"
#include "os_tick.h"
#include "code_0200f790.h"
#include "00/unk_021b0000.h"
#include "03/Net/ap_scan_callback.h"

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
    buf->mPhase = 1;
    gWcmWork->mNotifyId = 0;
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
    if (work->mPhase != 1) {
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
        case 1:
            WcmConfigure(config, notify);
            break;
        case 2:
            OS_RestoreInterrupts(enabled);
            return 2;
        case 3:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
    }
    switch (WM_Init(gWcmWork, gWcmWork->mDmaNo)) {
        case 3:
            WcmSetPhase(0xb);
            OS_RestoreInterrupts(enabled);
            return 7;
        case 4:
            OS_RestoreInterrupts(enabled);
            return 5;
        case 1:
        case 2:
        case 5:
        case 6:
        default:
            WcmSetPhase(0xb);
            OS_RestoreInterrupts(enabled);
            return 7;
        case 0:
            break;
    }
    if (WM_GetAllowedChannel() == 0) {
        if (WM_Finish() != 0) {
            WcmSetPhase(0xb);
            OS_RestoreInterrupts(enabled);
            return 7;
        }
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    if (WM_SetIndCallback(WcmWmcbIndication) != 0) {
        WcmSetPhase(0xb);
        OS_RestoreInterrupts(enabled);
        return 7;
    }
    result = WM_Enable(WcmWmcbCommon);
    switch (result) {
        case 2:
            WcmSetPhase(2);
            gWcmWork->mNotifyId = 1;
            break;
        case 8:
            WcmSetPhase(0xc);
            OS_RestoreInterrupts(enabled);
            return 1;
        case 3:
        default:
            WcmSetPhase(0xb);
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
        case 4:
            OS_RestoreInterrupts(enabled);
            return 2;
        case 1:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
        case 3:
            result = WM_PowerOff(WcmWmcbCommon);
            switch (result) {
                case 2:
                    WcmSetPhase(4);
                    gWcmWork->mNotifyId = 2;
                    break;
                case 8:
                    OS_RestoreInterrupts(enabled);
                    return 4;
                case 3:
                default:
                    WcmSetPhase(0xb);
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
        case 5:
            WcmEditScanExParam(bssid, essid, option);
            OS_RestoreInterrupts(enabled);
            return 2;
        case 6:
            WcmEditScanExParam(bssid, essid, option);
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
        case 3:
            WcmEditScanExParam(bssid, essid, option);
            DC_InvalidateRange(gWcmWork->mScanExParam.mScanBuf, gWcmWork->mScanExParam.mScanBufSize);
            gWcmWork->mScanCount++;
            result = WM_StartScanEx((Unk021425e8Func) WcmWmcbScanEx, &gWcmWork->mScanExParam);
            switch (result) {
                case 2:
                    WcmSetPhase(5);
                    gWcmWork->mNotifyId = 3;
                    break;
                case 8:
                    OS_RestoreInterrupts(enabled);
                    return 4;
                case 3:
                default:
                    WcmSetPhase(0xb);
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
        case 6:
            WcmSetPhase(7);
            gWcmWork->mNotifyId = 4;
            break;
        case 7:
            OS_RestoreInterrupts(enabled);
            return 2;
        case 3:
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
        case 3:
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
                    MI_CpuFill8(gWcmWork->mWepKey, 0, 0x50);
                } else {
                    MI_CpuCopy8(wepDesc->mKey, gWcmWork->mWepKey, 0x50);
                }
            } else {
                MI_CpuFill8(work->mWepKey, 0, 0x52);
            }
            MI_CpuCopy8(bssDesc, gWcmWork->mBssDesc, 0xc0);
            gWcmWork->mSupportRateSet = gWcmWork->mBasicRateSet | 3;
            WCM_UpdateOption(option);
            break;
        case 8:
            OS_RestoreInterrupts(enabled);
            return 2;
        case 9:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
    }
    result = WM_SetLifeTime(WcmWmcbCommon, 0xffff, 0x50, 0xffff, 0xffff);
    switch (result) {
        case 2:
            WcmSetPhase(8);
            gWcmWork->mNotifyId = 5;
            break;
        case 8:
            OS_RestoreInterrupts(enabled);
            return 4;
        case 3:
        default:
            WcmSetPhase(0xb);
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
        case 10:
            OS_RestoreInterrupts(enabled);
            return 2;
        case 3:
            OS_RestoreInterrupts(enabled);
            return 0;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
        case 9:
            break;
    }
    if (work->mResetting == 1) {
        WcmSetPhase(0xa);
        gWcmWork->mNotifyId = 6;
    } else {
        result = WM_EndDCF(WcmWmcbEndDCF);
        switch (result) {
            case 2:
                WcmSetPhase(0xa);
                gWcmWork->mNotifyId = 6;
                break;
            case 8:
                OS_RestoreInterrupts(enabled);
                return 4;
            case 3:
            default:
                WcmSetPhase(0xb);
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
    Unk02142988 *wmStatus;

    enabled = OS_DisableInterrupts();
    work = gWcmWork;
    if (work == NULL) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    switch (work->mPhase) {
        case 13:
            OS_RestoreInterrupts(enabled);
            return 2;
        case 1:
            OS_RestoreInterrupts(enabled);
            return 0;
        case 6:
            WcmSetPhase(0xd);
            gWcmWork->mNotifyId = 9;
            OS_RestoreInterrupts(enabled);
            return 3;
        case 3:
        case 9:
        case 12:
            break;
        default:
            OS_RestoreInterrupts(enabled);
            return 1;
    }
    if (work->mResetting == 1) {
        WcmSetPhase(0xd);
        gWcmWork->mNotifyId = 9;
    } else {
        wmStatus = WMi_GetStatusAddress();
        DC_InvalidateRange(wmStatus, 2);
        switch (wmStatus->mState) {
            case 0:
                result = WM_Finish();
                if (result == 0) {
                    WcmSetPhase(1);
                    gWcmWork->mNotifyId = 0;
                    OS_RestoreInterrupts(enabled);
                    return 0;
                }
                break;
            case 1:
                result = WM_Disable(WcmWmcbCommon);
                break;
            case 2:
                result = WM_PowerOff(WcmWmcbCommon);
                break;
            default:
                gWcmWork->mResetting = 1;
                result = WM_Reset(WcmWmcbReset);
                break;
        }
        switch (result) {
            case 2:
                WcmSetPhase(0xd);
                gWcmWork->mNotifyId = 9;
                break;
            case 8:
                OS_RestoreInterrupts(enabled);
                return 4;
            case 3:
            default:
                WcmSetPhase(0xb);
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
    connPhase = 0;
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
    gWcmWork->mScanExParam.mScanType = (gWcmWork->mOption & 0x300000) != 0x300000;
    if (bssid == NULL) {
        MI_CpuCopy8(WCM_Bssid_Any, gWcmWork->mScanExParam.mBssid, 6);
    } else {
        MI_CpuCopy8(bssid, gWcmWork->mScanExParam.mBssid, 6);
    }
    if (essid == NULL || essid == WCM_Essid_Any) {
        MI_CpuCopy8(WCM_Essid_Any, gWcmWork->mScanExParam.mSsid, 0x20);
        gWcmWork->mScanExParam.mSsidLength = 0;
    } else {
        MI_CpuCopy8(essid, gWcmWork->mScanExParam.mSsid, 0x20);
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
    gWcmWork->mOption = 0xaaa082;
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
    gWcmWork->mNotifyId = 0;
    WcmNotifyEx(savedId, result, para0, para1, para2);
}

void WcmNotifyEx(s16 notify, u32 result, void *para0, u32 para1, u32 para2) {
    WCMNotice noticeRec;

    if (gWcmWork->mNotify != NULL) {
        noticeRec.mNotify = notify;
        noticeRec.mResult = result;
        noticeRec.mUnk_04 = para0;
        noticeRec.mUnk_08 = para1;
        noticeRec.mUnk_0c = para2;
        gWcmWork->mNotify(&noticeRec);
    }
}

void WcmSetPhase(u32 phase) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (gWcmWork->mPhase == 9 && phase != 9) {
        OS_CancelAlarm(&gWcmWork->mKeepAliveAlarm);
    }
    if (gWcmWork->mPhase != 0xb) {
        gWcmWork->mPhase = phase;
    }
    if (phase == 9) {
        OS_SetAlarm(&gWcmWork->mKeepAliveAlarm, 0x22f5341, WcmKeepAliveAlarm, NULL);
    }
    OS_RestoreInterrupts(enabled);
}

void WCMi_ResetKeepAliveAlarm(void) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    OS_CancelAlarm(&gWcmWork->mKeepAliveAlarm);
    if (gWcmWork->mPhase == 9) {
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
        if (WM_Reset(WcmWmcbReset) != 2) {
            WcmSetPhase(0xb);
            WcmNotify(7, NULL, 0, 0x611);
        }
    }
}

void WcmWmcbIndication(Unk021425e8 *callback) {
    if (callback->mResultCode == 8 && callback->mState == 0x16 && callback->mPort == 0x25) {
        switch (gWcmWork->mPhase) {
            case 8:
                WcmSetPhase(0xc);
                return;
            case 9:
            case 12:
                WcmWmReset();
                return;
            case 10:
                WcmSetPhase(0xc);
                break;
        }
    }
}

void WcmWmcbCommon(Unk021425e8 *callback) {
    WCMWork *work;
    s32 result = 0x14;

    switch (callback->mResultCode) {
        case 0:
            switch (callback->mCommand) {
                case 3:
                    result = WM_PowerOn(WcmWmcbCommon);
                    break;
                case 4:
                    switch (WM_Finish()) {
                        case 0:
                            WcmSetPhase(1);
                            WcmNotify(0, NULL, 0, 0x663);
                            return;
                        case 4:
                        default:
                            WcmSetPhase(0xb);
                            WcmNotify(7, NULL, 0, 0x66a);
                            return;
                    }
                case 5:
                    WcmSetPhase(3);
                    WcmNotify(0, NULL, 0, 0x670);
                    return;
                case 6:
                    result = WM_Disable(WcmWmcbCommon);
                    break;
                case 0x1d:
                    result = WM_SetBeaconIndication((Unk021425e8Func) WcmWmcbCommon, 0);
                    break;
                case 0x19:
                    work = gWcmWork;
                    result = WM_SetWEPKeyEx(WcmWmcbCommon, work->mWepMode, work->mWepKeyId, work->mWepKey);
                    break;
                case 0x27: {
                    u32 option;
                    u16 authMode;
                    u32 powerSave;
                    work = gWcmWork;
                    option = work->mOption;
                    authMode = (option & 0xc0000) == 0xc0000;
                    powerSave = (option & 0x30000) != 0x30000 ? 1 : 0;
                    result = WM_StartConnectEx((Unk021425e8Func) WcmWmcbConnect, (u16 *) work->mBssDesc, NULL,
                                               powerSave, authMode);
                    break;
                }
            }
            if (result == 2) {
                return;
            }
            switch (result) {
                case 8:
                    WcmSetPhase(0xc);
                    WcmNotify(1, gWcmWork->mNotifyId == 5 ? gWcmWork->mBssDesc : 0, 0, 0x6a7);
                    return;
                case 3:
                default:
                    WcmSetPhase(0xb);
                    WcmNotify(7, gWcmWork->mNotifyId == 5 ? gWcmWork->mBssDesc : 0, 0, 0x6b0);
                    return;
            }
            break;
        case 1:
            WcmSetPhase(0xc);
            WcmNotify(1, gWcmWork->mNotifyId == 5 ? gWcmWork->mBssDesc : 0, 0, 0x6d0);
            return;
        case 2:
        case 3:
        case 4:
        default:
            WcmSetPhase(0xb);
            WcmNotify(7, gWcmWork->mNotifyId == 5 ? gWcmWork->mBssDesc : 0, 0, 0x6da);
            return;
    }
}

// Hand-written asm: it counts leading zeros with clz.
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
        case 0:
            if (gWcmWork->mPhase == 5) {
                WcmSetPhase(6);
                WcmNotify(0, 0, 0, 0x6f6);
            }
            switch (gWcmWork->mPhase) {
                case 6:
                    gWcmWork->mNotifyId = 7;
                    if (callback->mState == 5) {
                        DC_InvalidateRange(gWcmWork->mScanExParam.mScanBuf, gWcmWork->mScanExParam.mScanBufSize);
                        for (index = 0; index < callback->mBssDescCount; index++) {
                            WCMi_EntryApList((WMBssDesc *) callback->mBssDesc[index], callback->mLinkLevel[index]);
                            WcmNotifyEx(7, 0, callback->mBssDesc[index], (u32) callback, 0x70b);
                        }
                    }
                    option = gWcmWork->mOption;
                    if ((option & 0xc00000) == 0xc00000) {
                        channelCount = WcmCountBits(option & 0x3ffe);
                        if (channelCount != 0) {
                            scanCount = gWcmWork->mScanCount;
                            if (scanCount % channelCount == 0) {
                                WcmNotifyEx(8, 0, (void *) scanCount, 0, 0x718);
                            }
                        }
                    }
                    gWcmWork->mScanExParam.mChannelList =
                        (1 << WcmGetNextScanChannel(32 - WcmCountLeadingZero(callback->mUnk_0a))) >> 1;
                    DC_InvalidateRange(gWcmWork->mScanExParam.mScanBuf, gWcmWork->mScanExParam.mScanBufSize);
                    gWcmWork->mScanCount++;
                    result = WM_StartScanEx((Unk021425e8Func) WcmWmcbScanEx, &gWcmWork->mScanExParam);
                    break;
                case 7:
                    result = WM_EndScan((Unk021425e8Func) WcmWmcbEndScan);
                    break;
                case 13:
                    WcmWmReset();
                    return;
            }
            switch (result) {
                case 2:
                    return;
                case 8:
                    WcmSetPhase(0xc);
                    WcmNotify(1, 0, 0, 0x743);
                    return;
                case 3:
                default:
                    WcmSetPhase(0xb);
                    WcmNotify(7, 0, 0, 0x74c);
                    return;
            }
        case 1:
            WcmWmReset();
            return;
        case 2:
        case 3:
        case 4:
        default:
            WcmSetPhase(0xb);
            WcmNotify(7, 0, 0, 0x75d);
            return;
    }
}

void WcmWmcbEndScan(Unk021425e8 *callback) {
    switch (callback->mResultCode) {
        case 0:
            WcmSetPhase(3);
            WcmNotify(0, 0, 0, 0x774);
            return;
        case 1:
            WcmWmReset();
            return;
        case 2:
        case 3:
        case 4:
        default:
            WcmSetPhase(0xb);
            WcmNotify(7, 0, 0, 0x784);
            return;
    }
}

void WcmWmcbConnect(WMStartScanExCallback *callback) {
    u16 authId;
    s32 result;

    switch (callback->mErrcode) {
        case 0:
            switch (callback->mState) {
                case 8:
                case 9:
                    switch (gWcmWork->mPhase - 8) {
                        case 2:
                            gWcmWork->mAuthId = 0;
                        case 0:
                            WcmSetPhase(0xc);
                            return;
                        case 1:
                            gWcmWork->mAuthId = 0;
                            gWcmWork->mNotifyId = 6;
                        case 4:
                            WcmWmReset();
                            return;
                        default:
                            break;
                    }
                    break;
                case 7:
                    if (gWcmWork->mPhase == 0xc) {
                        WcmSetPhase(8);
                        WcmWmReset();
                        return;
                    }
                    authId = callback->mUnk_0a;
                    if (authId >= 1 && authId <= 0x7d7) {
                        gWcmWork->mAuthId = authId;
                        result = WM_StartDCF((Unk021425e8Func) WcmWmcbStartDCF, &gWcmWork->mWmWork[0x1500], 0x620);
                        switch (result) {
                            case 2:
                                return;
                            case 8:
                                WcmSetPhase(0xc);
                                WcmNotify(1, gWcmWork->mBssDesc, 0, 0x7d7);
                                return;
                            case 3:
                            default:
                                WcmSetPhase(0xb);
                                WcmNotify(7, gWcmWork->mBssDesc, 0, 0x7e0);
                                return;
                        }
                    }
                    WcmWmReset();
                    return;
                case 6:
                    break;
                default:
                    WcmSetPhase(0xb);
                    WcmNotify(7, gWcmWork->mBssDesc, callback->mState, 0x7ee);
                    return;
            }
            break;
        case 1:
            gWcmWork->mWlStatusOnConnectFail = callback->mBssDescCount;
        case 6:
        case 11:
        case 12:
            WcmSetPhase(8);
            WcmWmReset();
            return;
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 10:
        default:
            WcmSetPhase(0xb);
            WcmNotify(7, gWcmWork->mBssDesc, 0, 0x804);
            return;
    }
}

void WcmWmcbDisconnect(Unk021425e8 *callback) {
    switch (callback->mResultCode) {
        case 0:
            if (gWcmWork->mPhase == 0xc) {
                WcmSetPhase(0xa);
                WcmWmReset();
                return;
            }
            gWcmWork->mAuthId = 0;
            WcmSetPhase(3);
            WcmNotify(0, gWcmWork->mBssDesc, 0, 0x827);
            return;
        case 1:
        case 3:
            WcmSetPhase(0xa);
            WcmWmReset();
            return;
        case 2:
        case 4:
        default:
            WcmSetPhase(0xb);
            WcmNotify(7, gWcmWork->mBssDesc, 0, 0x839);
            return;
    }
}

void WcmWmcbStartDCF(Unk021425e8 *callback) {
    switch (callback->mResultCode) {
        case 0:
            switch (callback->mState) {
                case 0xe:
                    if (gWcmWork->mPhase == 0xc) {
                        WcmSetPhase(8);
                        WcmWmReset();
                        return;
                    }
                    WcmSetPhase(9);
                    WcmNotify(0, gWcmWork->mBssDesc, 0, 0x85d);
                    return;
                case 0xf:
                    WCMi_ShelterRssi(((u16 *) callback->mRecvBuf)[7] >> 8);
                    DC_InvalidateRange(callback->mRecvBuf, 0x620);
                    WCMi_CpsifRecvCallback(callback->mRecvBuf);
                    return;
                default:
                    WcmSetPhase(0xb);
                    WcmNotify(7, gWcmWork->mBssDesc, callback->mState, 0x86b);
                    return;
            }
        case 4:
        default:
            WcmSetPhase(0xb);
            WcmNotify(7, gWcmWork->mBssDesc, 0, 0x877);
            return;
    }
}

void WcmWmcbEndDCF(Unk021425e8 *callback) {
    s32 result;

    switch (callback->mResultCode) {
        case 0:
            if (gWcmWork->mPhase == 0xc) {
                WcmSetPhase(0xa);
                WcmWmReset();
                return;
            }
            result = WM_Disconnect((Unk021425e8Func) WcmWmcbDisconnect, 0);
            switch (result) {
                case 2:
                    return;
                case 8:
                    WcmSetPhase(0xc);
                    WcmNotify(1, gWcmWork->mBssDesc, 0, 0x8a0);
                    return;
                case 3:
                    WcmSetPhase(0xa);
                    WcmWmReset();
                    return;
                default:
                    WcmSetPhase(0xb);
                    WcmNotify(7, gWcmWork->mBssDesc, 0, 0x8ac);
                    return;
            }
        case 1:
        case 3:
            WcmSetPhase(0xa);
            WcmWmReset();
            return;
        case 2:
        case 4:
        default:
            WcmSetPhase(0xb);
            WcmNotify(7, gWcmWork->mBssDesc, 0, 0x8bf);
            return;
    }
}

void WcmWmcbReset(Unk021425e8 *callback) {
    u16 failStatus;
    u32 sharedKeyFlag;
    u32 powerSave;
    s32 result;
    u16 authMode;

    if (callback->mResultCode == 0) {
        gWcmWork->mResetting = 0;
        gWcmWork->mAuthId = 0;
        switch (gWcmWork->mPhase) {
            case 5:
            case 6:
                WcmSetPhase(3);
                WcmNotify(1, 0, 0, 0x8e1);
                return;
            case 7:
                WcmSetPhase(3);
                WcmNotify(0, 0, 0, 0x8e7);
                return;
            case 8:
                failStatus = gWcmWork->mWlStatusOnConnectFail;
                gWcmWork->mWlStatusOnConnectFail = 0;
                if (failStatus == 0x12 && (gWcmWork->mSupportRateSet & 0x24) != 0x24) {
                    gWcmWork->mSupportRateSet |= 0x24;
                    sharedKeyFlag = 0;
                    if ((gWcmWork->mOption & 0xc0000) == 0xc0000) {
                        sharedKeyFlag = 1;
                    }
                    authMode = sharedKeyFlag;
                    if ((gWcmWork->mOption & 0x30000) == 0x30000) {
                        powerSave = 0;
                    } else {
                        powerSave = 1;
                    }
                    result = WM_StartConnectEx((Unk021425e8Func) WcmWmcbConnect, (u16 *) gWcmWork->mBssDesc, 0,
                                               powerSave, authMode);
                    switch (result) {
                        case 2:
                            return;
                        case 8:
                            WcmSetPhase(0xc);
                            WcmNotify(1, gWcmWork->mBssDesc, failStatus, 0x905);
                            return;
                        case 3:
                        default:
                            WcmSetPhase(0xb);
                            WcmNotify(7, gWcmWork->mBssDesc, failStatus, 0x90c);
                            return;
                    }
                }
                WcmSetPhase(3);
                WcmNotify(1, gWcmWork->mBssDesc, failStatus, 0x913);
                return;
            case 9:
            case 12:
                WcmSetPhase(3);
                WcmNotify(0, gWcmWork->mBssDesc, 1, 0x91b);
                return;
            case 10:
                WcmSetPhase(3);
                WcmNotify(0, gWcmWork->mBssDesc, 0, 0x922);
                return;
            case 13:
                result = WM_PowerOff((Unk021425e8Func) WcmWmcbCommon);
                switch (result) {
                    case 2:
                        return;
                    case 8:
                        WcmSetPhase(0xc);
                        WcmNotify(1, 0, 0, 0x930);
                        return;
                    case 3:
                    default:
                        WcmSetPhase(0xb);
                        WcmNotify(7, 0, 0, 0x939);
                        return;
                }
            default:
                WcmSetPhase(0xb);
                WcmNotify(7, 0, gWcmWork->mPhase, 0x93f);
                return;
        }
    }
    WcmSetPhase(0xb);
    WcmNotify(7, 0, 0, 0x946);
}
