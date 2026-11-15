#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/Lib/NitroWiFi/code_021a669c.h"
#include "03/Net/essid_packet_steps.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "00/code_021a5000.h"
#include "os_thread.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/code_021a68dc.h"
#include "code_0200edc0.h"
#include "code_02133048.h"
#include "code_02142eac.h"
#include "ITCM/code_01ff8000.h"

WCMCpsifWork gWcmCpsifWork;

void WCMi_InitCpsif(void) {
    if (gWcmCpsifWork.mInitialized == 0) {
        gWcmCpsifWork.mInitialized = 1;
        gWcmCpsifWork.mSendResult = 0;
        gWcmCpsifWork.mSendQ.mTail = NULL;
        gWcmCpsifWork.mSendQ.mHead = NULL;
        OS_InitMutex(&gWcmCpsifWork.mSendMutex);
    }
}

void WCMi_CpsifRecvCallback(WMDcfRecvBuf *recv) {
    WCMRecvInd callback = gWcmCpsifWork.mRecvCallback;

    if (callback != NULL) {
        callback(recv->mSrcAdrs, recv->mDestAdrs, recv->mData, recv->mLength);
    }
}

void WCMi_CpsifSendNullPacket(void) {
    WCMWork *work;

    work = WCMi_GetSystemWork();
    if (work != NULL && work->mPhase == WIFI_LINK_PHASE_CONNECTED && work->mResetting != 1) {
        if (WcmCpsifTryLockMutexInIRQ(&gWcmCpsifWork.mSendMutex) != 0) {
            if (WM_SetDCFData(WcmCpsifKACallback, work->mBssid, work->mSendBuf, 0) != 2) {
                WcmCpsifUnlockMutexInIRQ(&gWcmCpsifWork.mSendMutex);
            }
        }
    }
}

u8 *WCM_GetApMacAddress(void) {
    u8 *mac = NULL;
    WCMWork *work;
    u32 enabled;

    work = WCMi_GetSystemWork();
    enabled = OS_DisableInterrupts();
    if (work != NULL && work->mPhase == WIFI_LINK_PHASE_CONNECTED && work->mResetting == 0) {
        mac = work->mBssid;
    }
    OS_RestoreInterrupts(enabled);
    return mac;
}

u8 *WCM_GetApEssid(u16 *length) {
    u8 *ssidBytes = NULL;
    u16 ssidLength = 0;
    WCMWork *work;
    u32 enabled;

    work = WCMi_GetSystemWork();
    enabled = OS_DisableInterrupts();
    if (work != NULL && work->mPhase == WIFI_LINK_PHASE_CONNECTED && work->mResetting == 0) {
        ssidBytes = work->mSsid;
        ssidLength = work->mSsidLength;
    }
    OS_RestoreInterrupts(enabled);
    if (length != NULL) {
        *length = ssidLength;
    }
    return ssidBytes;
}

u32 WCM_SetRecvDCFCallback(WCMRecvInd callback) {
    u32 enabled = (u32) callback;
    u32 cpsifWork;
    u32 recvCallback;
    recvCallback = (enabled) + (0u);
    enabled = OS_DisableInterrupts();
    cpsifWork = (u32) &gWcmCpsifWork;
    *(u32 *) ((cpsifWork) + 40u) = recvCallback;
    enabled = OS_RestoreInterrupts(enabled);
    return enabled;
}

s32 WCM_SendDCFData(const void *dstAddr, const void *buf, s32 len) {
    u32 enabled;
    WCMWork *work;
    s32 result;

    enabled = OS_DisableInterrupts();
    if (WCMi_GetSystemWork() == NULL) {
        OS_RestoreInterrupts(enabled);
        return -1;
    }
    OS_LockMutex(&gWcmCpsifWork.mSendMutex);
    work = WCMi_GetSystemWork();
    if (work == NULL) {
        OS_UnlockMutex(&gWcmCpsifWork.mSendMutex);
        OS_RestoreInterrupts(enabled);
        return -1;
    }
    if (work->mPhase != WIFI_LINK_PHASE_CONNECTED || work->mResetting == 1) {
        OS_UnlockMutex(&gWcmCpsifWork.mSendMutex);
        OS_RestoreInterrupts(enabled);
        return -4;
    }
    MI_CpuCopy8(buf, work->mSendBuf, len);
    result = WM_SetDCFData(WcmCpsifWmCallback, dstAddr, work->mSendBuf, len);
    switch (result) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            OS_UnlockMutex(&gWcmCpsifWork.mSendMutex);
            OS_RestoreInterrupts(enabled);
            return -5;
        case 2:
            OS_SleepThread(&gWcmCpsifWork.mSendQ);
            switch (gWcmCpsifWork.mSendResult) {
                case 1:
                default:
                    OS_UnlockMutex(&gWcmCpsifWork.mSendMutex);
                    OS_RestoreInterrupts(enabled);
                    return -5;
                case 0:
                    OS_UnlockMutex(&gWcmCpsifWork.mSendMutex);
                    OS_RestoreInterrupts(enabled);
                    return len;
            }
    }
}

void WcmCpsifWmCallback(WirelessMessage *callback) {
    if (callback->mCommand == WIRELESS_REQUEST_QUEUE_FRAME_DATA) {
        gWcmCpsifWork.mSendResult = callback->mResultCode;
        if (callback->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
            WCMi_ResetKeepAliveAlarm();
        }
        OS_WakeupThread(&gWcmCpsifWork.mSendQ);
    }
}

void WcmCpsifKACallback(WirelessMessage *event) {
    WcmCpsifUnlockMutexInIRQ(&gWcmCpsifWork.mSendMutex);
}

BOOL WcmCpsifTryLockMutexInIRQ(OSMutex *mutex) {
    if (mutex->mHolder == NULL) {
        mutex->mHolder = (struct OSThread *) OS_IrqHandler;
        mutex->mLockCount = mutex->mLockCount + 1;
        return 1;
    }
    if (mutex->mHolder == (struct OSThread *) OS_IrqHandler) {
        mutex->mLockCount = mutex->mLockCount + 1;
        return 1;
    }
    return 0;
}
