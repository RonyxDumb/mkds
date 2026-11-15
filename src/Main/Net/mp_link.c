#include "Main/Net/mp_link.h"

#include "reset_interrupt_enable.h"
#include "Main/Net/scan_connect_callbacks.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "thread_scheduler.h"
#include "mb_data.h"
#include "multiboot_game_entry.h"
#include "multiboot_game_info_beacon.h"
#include "arena_cache_init.h"
#include "cpu_copy_fill.h"
#include "multiboot_scan_lock.h"
#include "multiboot_data_pieces.h"
#include "03/Net/essid_packet_steps.h"

const u8 gDefaultScanBssid[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
u16 gScanConnectInitialized;
struct MPLink *gMPLink;
struct ScanConnectWork *gScanConnectWork;

#pragma thumb on
void SetupMPLink(MPLink *link) {
    gMPLink = link;
    link->mUnk_0c = 0;
    gMPLink->mMPStarted = FALSE;
    gMPLink->mUnk_1e = 0;
    gMPLink->mDataQueued = FALSE;
    gMPLink->mResetting = FALSE;
    gMPLink->mSendBuffer = NULL;
    gMPLink->mReceiveBuffer = NULL;
    gMPLink->mCallback = NULL;
}
#pragma thumb off

#pragma thumb on

void SetMPLinkCallback(MPLinkEventCallback callback) {
    u32 irqState = (OS_DisableInterrupts());
    u32 restoredIrq;
    gMPLink->mCallback = callback;
    restoredIrq = (OS_RestoreInterrupts(irqState));
}

#pragma thumb off

#pragma thumb on

void ScanConnectStartConnect(WMBssDesc *scanBuffer) {
    s32 wmResult;
    gMPLink->mMPStarted = FALSE;
    gMPLink->mResetting = FALSE;
    gMPLink->mSendBufferSize = (scanBuffer->mGameInfo.mChildMaxSize + 0x21) & ~0x1f;
    gMPLink->mReceiveBufferSize = ((scanBuffer->mGameInfo.mParentMaxSize + 0x55) & ~0x1f) * 2;
    gMPLink->mParentMaxSize = scanBuffer->mGameInfo.mParentMaxSize;
    gMPLink->mChildMaxSize = scanBuffer->mGameInfo.mChildMaxSize;
    gMPLink->mParentPayloadSize = gMPLink->mParentMaxSize - 6;
    MBi_SetChildMPMaxSize(gMPLink->mChildMaxSize);
    wmResult = WM_StartConnectEx(ScanConnectStartConnectCallback, scanBuffer, NULL, 1, 0);
    if (wmResult != WIRELESS_CALL_QUEUED) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(MP_LINK_EVENT_CONNECT_FAILED, 0);
        }
    }
}

void ScanConnectStartConnectCallback(WirelessMessage *result) {
    if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(MP_LINK_EVENT_CONNECT_FAILED, result);
        }
    } else {
        switch (result->mReplyState) {
            case WIRELESS_STATE_SESSION_START:
            case WIRELESS_STATE_NEVER_HANDLED:
            case WIRELESS_STATE_FORWARD_UNLESS_RESETTING:
            case WIRELESS_STATE_SEARCH_NO_ACTION:
            case WIRELESS_STATE_SEARCH_EMPTY:
            case WIRELESS_STATE_HOST_SIGHTED:
            case WIRELESS_STATE_CHILD_SESSION_START:
            case WIRELESS_STATE_CHILD_NO_ACTION:
                break;
            case WIRELESS_STATE_UNLINKED:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(MP_LINK_EVENT_DISCONNECTED, 0);
                }
                break;
            case WIRELESS_STATE_LINKED:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(MP_LINK_EVENT_CONNECTED, result);
                }
                break;
        }
    }
}

void SetPortCallbackAndStartMP(void *sendBuffer, u8 *receiveBuffer) {
    CommandResult portError;
    CommandResult startError;
    s32 wmResult;
    MPLink *mpLink;
    gMPLink->mSendBuffer = sendBuffer;
    gMPLink->mReceiveBuffer = receiveBuffer;
    wmResult = WM_SetPortCallback(MP_LINK_PORT, PortCallback, NULL);
    if (wmResult != WIRELESS_RESULT_SUCCEEDED) {
        mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            portError.mCommand = WIRELESS_REQUEST_BEGIN_EXCHANGE;
            portError.mResultCode = wmResult;
            mpLink->mCallback(MP_LINK_EVENT_CALL_FAILED, &portError);
        }
        return;
    }
    mpLink = gMPLink;
    wmResult = WM_StartMPEx(ScanConnectStartMPCallback, receiveBuffer, mpLink->mReceiveBufferSize, sendBuffer,
                            mpLink->mSendBufferSize, 1, 0, 0, 0, 1, 1);
    if (wmResult != WIRELESS_CALL_QUEUED) {
        mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            startError.mCommand = WIRELESS_REQUEST_BEGIN_EXCHANGE;
            startError.mResultCode = wmResult;
            mpLink->mCallback(MP_LINK_EVENT_CALL_FAILED, &startError);
        }
    }
}

void ScanConnectStartMPCallback(WirelessMessage *result) {
    CommandResult errorResult;
    CommandResult stateResult;
    MPLink *mpLink;
    u16 command;
    u16 resultCode = result->mResultCode;
    if (resultCode != WIRELESS_RESULT_SUCCEEDED) {
        if (resultCode != WIRELESS_RESULT_TRANSMIT_ERROR && resultCode != WIRELESS_RESULT_NO_ANSWER &&
            resultCode != WIRELESS_RESULT_EMPTY_STATION_MASK) {
            command = result->mCommand;
            mpLink = gMPLink;
            if (mpLink->mCallback != NULL) {
                errorResult.mCommand = command;
                errorResult.mResultCode = resultCode;
                mpLink->mCallback(MP_LINK_EVENT_REPLY_FAILED, &errorResult);
            }
        }
    } else {
        switch (result->mState) {
            case WIRELESS_STATE_EXCHANGE_BEGUN:
                gMPLink->mMPStarted = TRUE;
                gMPLink->mDataQueued = FALSE;
                gMPLink->mUnk_1e = 0;
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(MP_LINK_EVENT_MP_STARTED, 0);
                }
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(MP_LINK_EVENT_SEND_READY, 0);
                }
                break;
            case WIRELESS_STATE_EXCHANGE_PASS_RECV_BUFFER:
            default:
                command = result->mCommand;
                mpLink = gMPLink;
                if (mpLink->mCallback != NULL) {
                    stateResult.mCommand = command;
                    stateResult.mResultCode = WIRELESS_RESULT_REFUSED;
                    mpLink->mCallback(MP_LINK_EVENT_REPLY_FAILED, &stateResult);
                }
                break;
            case WIRELESS_STATE_EXCHANGE_IGNORED_FIRST:
            case WIRELESS_STATE_EXCHANGE_IGNORED_SECOND:
                break;
        }
    }
}

void StartResetWithFlag(void) {
    CommandResult errorResult;
    s32 wmResult;
    gMPLink->mResetting = TRUE;
    wmResult = WM_Reset(StartResetWithFlagCallback);
    if (wmResult != WIRELESS_CALL_QUEUED) {
        MPLink *mpLink;
        gMPLink->mResetting = FALSE;
        mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = WIRELESS_REQUEST_RESTART;
            errorResult.mResultCode = wmResult;
            mpLink->mCallback(MP_LINK_EVENT_CALL_FAILED, &errorResult);
        }
    }
}

void StartResetWithFlagCallback(WirelessMessage *result) {
    CommandResult errorResult;
    u16 resultCode;
    gMPLink->mResetting = FALSE;
    resultCode = result->mResultCode;
    if (resultCode != WIRELESS_RESULT_SUCCEEDED) {
        u16 command = result->mCommand;
        MPLink *mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = command;
            errorResult.mResultCode = resultCode;
            mpLink->mCallback(MP_LINK_EVENT_REPLY_FAILED, &errorResult);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(MP_LINK_EVENT_RESET_DONE, 0);
        }
    }
}

void StartReset(void) {
    CommandResult errorResult;
    s32 wmResult = WM_Reset(StartResetCallback);
    if (wmResult != WIRELESS_CALL_QUEUED) {
        MPLink *mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = WIRELESS_REQUEST_RESTART;
            errorResult.mResultCode = wmResult;
            mpLink->mCallback(MP_LINK_EVENT_CALL_FAILED, &errorResult);
        }
    }
}

void StartResetCallback(WirelessMessage *result) {
    CommandResult errorResult;
    u16 resultCode = result->mResultCode;
    if (resultCode != WIRELESS_RESULT_SUCCEEDED) {
        u16 command = result->mCommand;
        MPLink *mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = command;
            errorResult.mResultCode = resultCode;
            mpLink->mCallback(MP_LINK_EVENT_REPLY_FAILED, &errorResult);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(MP_LINK_EVENT_RESET_DONE, 0);
        }
    }
}

u32 IsMPReadyToQueueData(void) {
    u32 ready = 0;
    u32 mpActive = 0;
    MPLink *mpLink = gMPLink;
    if (mpLink->mMPStarted == TRUE && mpLink->mDataQueued == FALSE) {
        mpActive = 1;
    }
    if (mpActive != 0 && mpLink->mResetting == FALSE) {
        ready = 1;
    }
    return ready;
}

void PortCallback(void *portMessage) {
    WirelessMessage *result = portMessage;
    if (result->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        switch (result->mState) {
            case WIRELESS_STATE_LINKED:
            case WIRELESS_STATE_UNLINKED:
                break;
            case WIRELESS_STATE_PORT_DATA_ARRIVED:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(MP_LINK_EVENT_RECEIVED, result);
                }
                break;
        }
    }
}

s32 QueueMPDataIfReady(u32 dataSize, u16 destBitmap, u8 *data) {
    s32 wmResult;
    DC_FlushRange(data, 4);
    DC_WaitWriteBufferEmpty();
    if (IsMPReadyToQueueData() == 0) {
        return MP_LINK_QUEUE_NOT_READY;
    }
    wmResult = WM_SetMPDataToPortEx(QueueMPDataCallback, NULL, data, (u16) dataSize, destBitmap, MP_LINK_PORT, 3);
    if (wmResult == WIRELESS_CALL_QUEUED) {
        gMPLink->mDataQueued = TRUE;
        return WIRELESS_CALL_QUEUED;
    }
    return wmResult;
}

void QueueMPDataCallback(WirelessMessage *result) {
    gMPLink->mDataQueued = FALSE;
    if (result->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(MP_LINK_EVENT_SENT, result);
        }
    } else if (result->mResultCode == WIRELESS_RESULT_NO_ANSWER) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(MP_LINK_EVENT_SEND_BUSY, result);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(MP_LINK_EVENT_SEND_FAILED, result);
        }
    }
    if (gMPLink->mCallback != NULL) {
        gMPLink->mCallback(MP_LINK_EVENT_SEND_READY, 0);
    }
}

void ClearPortCallback(void) {
    WM_SetPortCallback(MP_LINK_PORT, NULL, NULL);
}

void InitScanConnectWork(ScanConnectWork *work, void *initData) {
    if (gScanConnectInitialized == FALSE) {
        gScanConnectInitialized = TRUE;
        MI_CpuFill8(work, 0, SCAN_CONNECT_WORK_SIZE);
        gScanConnectWork = work;
        work->mState = SCAN_CONNECT_STATE_IDLE;
        MI_CpuCopy8(initData, gScanConnectWork->mUserInfo, 0x16);
        MBi_SetBeaconRecvStatusBuffer(gScanConnectWork->mBeaconRecvStatus);
        MB_InitRecvGameInfoStatus();
        MBi_SetScanLockFunc(SetScanBssid, ClearUseScanBssid);
    }
}

void CloseScanConnect(void) {
    if (gScanConnectWork->mEndRequested == FALSE) {
        gScanConnectWork->mEndRequested = TRUE;
        switch (gScanConnectWork->mState) {
            case SCAN_CONNECT_STATE_IDLE:
                if (gScanConnectWork->mRepeatScan != FALSE) {
                    gScanConnectWork->mRepeatScan = FALSE;
                    return;
                }
                if (gScanConnectWork->mEndScanRequested == FALSE) {
                    FinishScanConnect();
                    return;
                }
                break;
            case SCAN_CONNECT_STATE_CONNECTING:
            case SCAN_CONNECT_STATE_LINK_UP:
            case SCAN_CONNECT_STATE_CONNECT_FAILED:
            case SCAN_CONNECT_STATE_LINK_LOST:
            case SCAN_CONNECT_STATE_REQUEST_REJECTED:
            case SCAN_CONNECT_STATE_REQUEST_FAILED:
            case SCAN_CONNECT_STATE_ERROR:
                StartReset();
                break;
            case SCAN_CONNECT_STATE_SEND_REQUEST:
            case SCAN_CONNECT_STATE_ACCEPTED:
            case SCAN_CONNECT_STATE_WAIT_START:
            case SCAN_CONNECT_STATE_SEND_START:
                StartResetWithFlag();
                break;
            case SCAN_CONNECT_STATE_SEND_DONE:
                break;
            case SCAN_CONNECT_STATE_RESET_DONE:
            case SCAN_CONNECT_STATE_RESET_ABORTED:
                FinishScanConnect();
                break;
            default:
                OS_Terminate();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void FinishScanConnect(void) {
    gScanConnectInitialized = FALSE;
    gScanConnectWork->mEndRequested = FALSE;
    ClearPortCallback();
    SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_FINISHED, NULL);
}

u32 GetScanConnectWorkSize(void) {
    return SCAN_CONNECT_WORK_SIZE;
}

void SetScanConnectStateCallback(ScanConnectStateFunc callback) {
    u32 irqState = (OS_DisableInterrupts());
    u32 restoredIrq;
    gScanConnectWork->mStateCallback = callback;
    restoredIrq = (OS_RestoreInterrupts(irqState));
}

#pragma thumb off

#pragma thumb on

void SetScanConnectStateAndNotify(u32 state, void *info) {
    u32 irqState;
    irqState = OS_DisableInterrupts();
    gScanConnectWork->mState = state;
    OS_RestoreInterrupts(irqState);
    if (gScanConnectWork->mStateCallback != NULL) {
        gScanConnectWork->mStateCallback(state, info);
    }
}

#pragma thumb off

#pragma thumb on

void StartRepeatedScan(ScanEventCallback callback, u32 param) {
    gScanConnectWork->mScanCallback = callback;
    gScanConnectWork->mScanGgid = param;
    gScanConnectWork->mScanParams.mChannel = 0;
    gScanConnectWork->mScanParams.mScanBuf = &gScanConnectWork->mScanBuffer;
    gScanConnectWork->mRepeatScan = TRUE;
    gScanConnectWork->mUseScanBssid = FALSE;
    gScanConnectWork->mUnk_05ee = 0;
    ScanConnectStartScan();
}

#pragma thumb off

#pragma thumb on

void ScanConnectStartScan(void) {
    s32 wmResult;
    ScanConnectWork *work;
    u8 *bssid;
    const u8 *defaultBssid;
    work = gScanConnectWork;
    if (work->mUseScanBssid != FALSE) {
        work->mScanParams.mMaxChannelTime = SCAN_CHANNEL_TIME_LOCKED;
    } else {
        bssid = work->mScanParams.mBssid;
        defaultBssid = gDefaultScanBssid;
        bssid[0] = defaultBssid[0];
        bssid[1] = defaultBssid[1];
        bssid[2] = defaultBssid[2];
        bssid[3] = defaultBssid[3];
        bssid[4] = defaultBssid[4];
        bssid[5] = defaultBssid[5];
        gScanConnectWork->mScanParams.mMaxChannelTime = SCAN_CHANNEL_TIME_ANY;
        if (PickScanChannel() == 0) {
            ReportScanError(SCAN_ERROR_NO_CHANNEL, 0);
            return;
        }
    }
    if (gScanConnectWork->mScanParams.mChannel == 0) {
        gScanConnectWork->mScanParams.mChannel = SCAN_CHANNEL_FIRST;
    }
    wmResult = WM_StartScan(ScanConnectStartScanCallback, &gScanConnectWork->mScanParams);
    if (wmResult != WIRELESS_CALL_QUEUED) {
        ReportScanError(SCAN_ERROR_START, wmResult);
    }
}

void ScanConnectStartScanCallback(WirelessMessage *result) {
    if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        ReportScanError(SCAN_ERROR_START, result->mResultCode);
        return;
    }
    switch (result->mReplyState) {
        case WIRELESS_STATE_SEARCH_NO_ACTION:
            break;
        case WIRELESS_STATE_HOST_SIGHTED:
            if (result->mGameInfo.mGgid == gScanConnectWork->mScanGgid) {
                DC_InvalidateRange(&gScanConnectWork->mScanBuffer, sizeof(gScanConnectWork->mScanBuffer));
                MB_RecvGameInfoBeacon(EntryCallback, result->mAid, &gScanConnectWork->mScanBuffer);
                MB_CountGameInfoLifetime(EntryCallback, 1);
            }
        case WIRELESS_STATE_SEARCH_EMPTY:
            MB_CountGameInfoLifetime(EntryCallback, 0);
            if (gScanConnectWork->mRepeatScan != FALSE) {
                ScanConnectStartScan();
            } else {
                ScanConnectEndScan();
            }
            break;
        default:
            ReportScanError(SCAN_ERROR_START, WIRELESS_RESULT_REFUSED);
            break;
    }
}

void CallScanCallbackWithEntry(u32 event, MBGameInfoRecvList *entry, u32 entryIndex) {
    ScanEntryArgs args;
    ScanConnectWork *work;
    work = gScanConnectWork;
    if (work->mScanCallback != NULL) {
        args.mEntryIndex = entryIndex;
        if (entry != NULL) {
            args.mEntry = entry;
            args.mScanBuffer = &entry->mScanBuffer;
        } else {
            args.mEntry = NULL;
            args.mScanBuffer = NULL;
        }
        work->mScanCallback(event, &args);
    }
}

void ReportScanError(u16 errorCode, u16 resultCode) {
    ScanErrorArgs args;
    if (gScanConnectWork->mScanCallback != NULL) {
        args.mErrorCode = errorCode;
        args.mResultCode = resultCode;
        gScanConnectWork->mScanCallback(SCAN_EVENT_ERROR, &args);
    }
}

void SetScanBssid(const u8 *bssid) {
    u8 *dest;
    gScanConnectWork->mUseScanBssid = TRUE;
    dest = gScanConnectWork->mScanParams.mBssid;
    dest[0] = bssid[0];
    dest[1] = bssid[1];
    dest[2] = bssid[2];
    dest[3] = bssid[3];
    dest[4] = bssid[4];
    dest[5] = bssid[5];
}

#pragma thumb off

#pragma thumb on
void ClearUseScanBssid(void) {
    gScanConnectWork->mUseScanBssid = FALSE;
}
#pragma thumb off

#pragma thumb on

void EntryCallback(u32 event, void *entry, u32 entryIndex) {
    switch (event) {
        case 0:
        case BEACON_ENTRY_EVENT_INCOMPLETE:
        case BEACON_ENTRY_EVENT_NO_FREE_SLOT:
            break;
        case BEACON_ENTRY_EVENT_COMPLETE:
            CallScanCallbackWithEntry(SCAN_EVENT_ENTRY_NEW, entry, entryIndex);
            break;
        case BEACON_ENTRY_EVENT_TIMED_OUT:
            CallScanCallbackWithEntry(SCAN_EVENT_ENTRY_UPDATED, entry, entryIndex);
            break;
    }
}

u32 PickScanChannel(void) {
    u16 allowedChannels;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0x8000 || allowedChannels == 0) {
        return 0;
    }
    gScanConnectWork->mScanParams.mChannel++;
    do {
        gScanConnectWork->mScanParams.mChannel++;
        if (gScanConnectWork->mScanParams.mChannel > SCAN_CHANNEL_LAST) {
            gScanConnectWork->mScanParams.mChannel = SCAN_CHANNEL_FIRST;
        }
    } while ((allowedChannels & (1 << (gScanConnectWork->mScanParams.mChannel - 1))) == 0);
    return 1;
}

void RequestEndScan(void) {
    gScanConnectWork->mRepeatScan = FALSE;
    gScanConnectWork->mEndScanRequested = TRUE;
}

#pragma thumb off

#pragma thumb on

void ScanConnectEndScan(void) {
    u32 wmResult;
    wmResult = WM_EndScan(ScanConnectEndScanCallback);
    if (wmResult != WIRELESS_CALL_QUEUED) {
        ReportScanError(SCAN_ERROR_END, wmResult & 0xffff);
    }
}

#pragma thumb off
