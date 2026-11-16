#include "00/Lib/NitroWiFi/wifi_stack_bridge.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/NitroWiFi/wireless_connection_config.h"
#include "thread_scheduler.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "mutex_init_decl.h"
#include "signed_int_divide.h"
#include "wireless_link_control.h"
#include "ITCM/model_draw_and_irq_handler.h"

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
            if (WM_SetDCFData(WcmCpsifKACallback, work->mBssDesc.mBssid, work->mSendBuf, 0) != 2) {
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
        mac = work->mBssDesc.mBssid;
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
        ssidBytes = work->mBssDesc.mSsid;
        ssidLength = work->mBssDesc.mSsidLength;
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
        case WIRELESS_RESULT_SUCCEEDED:
        case WIRELESS_RESULT_REFUSED:
        case WIRELESS_RESULT_BAD_PHASE:
        case WIRELESS_RESULT_SWITCHED_OFF:
        case WIRELESS_RESULT_NOT_SET_UP:
        case WIRELESS_RESULT_BAD_INPUT:
        case WIRELESS_RESULT_NO_REMOTE:
        case WIRELESS_RESULT_PIPE_ERROR:
        default:
            OS_UnlockMutex(&gWcmCpsifWork.mSendMutex);
            OS_RestoreInterrupts(enabled);
            return -5;
        case WIRELESS_CALL_QUEUED:
            OS_SleepThread(&gWcmCpsifWork.mSendQ);
            switch (gWcmCpsifWork.mSendResult) {
                case WIRELESS_RESULT_REFUSED:
                default:
                    OS_UnlockMutex(&gWcmCpsifWork.mSendMutex);
                    OS_RestoreInterrupts(enabled);
                    return -5;
                case WIRELESS_RESULT_SUCCEEDED:
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
