#include "Main/Net/scan_connect_callbacks.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "code_0200fc8c.h"
#include "Main/Net/mp_link.h"
#include "code_0214d018.h"

#pragma thumb on

void ScanConnectEndScanCallback(WirelessMessage *info) {
    if (info->mResultCode != 0) {
        ReportScanError(SCAN_ERROR_END, info->mResultCode);
        return;
    }
    gScanConnectWork->mEndScanRequested = 0;
    if (gScanConnectWork->mEndRequested != 0) {
        FinishScanConnect();
        return;
    }
    CallScanCallbackWithEntry(SCAN_EVENT_END, NULL, 0);
}

u32 StartConnectToEntry(u32 entryIndex) {
    MBGameInfoRecvList *entry;
    entry = MB_GetGameInfoRecvList(entryIndex);
    if (entry == NULL) {
        return 0;
    }
    gScanConnectWork->mGgid = entry->mGgid;
    gScanConnectWork->mFileId = entry->mFileNo;
    SetupMPLink(&gScanConnectWork->mMPLink);
    SetMPLinkCallback(MPLinkCallback);
    SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_CONNECTING, 0);
    MI_CpuCopy8(&entry->mScanBuffer, &gScanConnectWork->mScanBuffer, sizeof(WMBssDesc));
    ScanConnectStartConnect(&gScanConnectWork->mScanBuffer);
    return 1;
}

void MPLinkCallback(s32 eventKind, void *eventInfo) {
    WirelessMessage *info = eventInfo;
    u16 resultCode;
    u16 commandCode;
    u16 code;
    switch (eventKind) {
        case MP_LINK_EVENT_UNUSED:
        case MP_LINK_EVENT_SENT:
            break;
        case MP_LINK_EVENT_CONNECT_FAILED:
            SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_CONNECT_FAILED, 0);
            break;
        case MP_LINK_EVENT_CONNECTED:
            SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_LINK_UP, info);
            SetPortCallbackAndStartMP(gScanConnectWork, gScanConnectWork->mReceiveBuffer);
            break;
        case MP_LINK_EVENT_DISCONNECTED:
            SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_LINK_LOST, info);
            break;
        case MP_LINK_EVENT_SEND_READY:
            QueueStateMessage();
            break;
        case MP_LINK_EVENT_RECEIVED:
            ReceivePortMessage(info);
            break;
        case MP_LINK_EVENT_RESET_DONE:
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_SEND_DONE) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_RESET_DONE, 0);
            } else {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_RESET_ABORTED, 0);
            }
            if (gScanConnectWork->mEndRequested != 0) {
                FinishScanConnect();
            }
            break;
        case MP_LINK_EVENT_CALL_FAILED:
            code = info->mResultCode;
            if (gScanConnectWork->mStateCallback != NULL) {
                switch (code) {
                    case WIRELESS_RESULT_REFUSED:
                    case WIRELESS_RESULT_SWITCHED_OFF:
                    case WIRELESS_RESULT_NOT_SET_UP:
                    case WIRELESS_RESULT_BAD_INPUT:
                    case WIRELESS_RESULT_PIPE_ERROR:
                    case WIRELESS_RESULT_NO_ANSWER:
                        code = SCAN_CONNECT_ERROR_WM_REJECTED;
                        break;
                    case WIRELESS_RESULT_TRANSMIT_ERROR:
                    default:
                        code = SCAN_CONNECT_ERROR_OTHER;
                        break;
                }
                resultCode = code;
                gScanConnectWork->mStateCallback(SCAN_CONNECT_STATE_ERROR, &resultCode);
            }
            break;
        case MP_LINK_EVENT_REPLY_FAILED:
            code = info->mCommand;
            if (gScanConnectWork->mStateCallback != NULL) {
                switch (code) {
                    case WIRELESS_REQUEST_POWER_UP_STACK:
                    case WIRELESS_REQUEST_CONFIGURE_HOST:
                    case WIRELESS_REQUEST_OPEN_HOST:
                    case WIRELESS_REQUEST_LEAVE:
                    case WIRELESS_REQUEST_BEGIN_EXCHANGE:
                    case WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA:
                    case WIRELESS_REQUEST_BEGIN_FRAME_MODE:
                    case WIRELESS_REQUEST_QUEUE_FRAME_DATA:
                    case WIRELESS_REQUEST_BEGIN_KEY_SHARE:
                    case WIRELESS_REQUEST_WATCH_BEACONS:
                    case WIRELESS_REQUEST_SET_TIMEOUT:
                        code = SCAN_CONNECT_ERROR_WM_REJECTED;
                        break;
                    case WIRELESS_REQUEST_RESTART:
                    default:
                        code = SCAN_CONNECT_ERROR_OTHER;
                        break;
                }
                commandCode = code;
                gScanConnectWork->mStateCallback(SCAN_CONNECT_STATE_ERROR, &commandCode);
            }
            break;
        case MP_LINK_EVENT_SEND_BUSY:
            break;
    }
}

void ReceivePortMessage(WirelessMessage *info) {
    ParentMessage parentMessage;
    MBi_SetRecvBufferFromParent(&parentMessage, info->mData);
    switch (parentMessage.mKind) {
        case PARENT_MESSAGE_LISTENING:
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_LINK_UP) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_SEND_REQUEST, 0);
            }
            break;
        case PARENT_MESSAGE_TURNED_DOWN:
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_SEND_REQUEST) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_REQUEST_REJECTED, 0);
            }
            break;
        case PARENT_MESSAGE_GAVE_UP:
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_SEND_REQUEST) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_REQUEST_FAILED, 0);
            }
            break;
        case PARENT_MESSAGE_WELCOMED:
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_SEND_REQUEST) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_ACCEPTED, 0);
            }
            break;
        case PARENT_MESSAGE_BEGIN_SEND:
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_ACCEPTED) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_WAIT_START, 0);
            }
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_WAIT_START) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_SEND_START, 0);
            }
            break;
        case PARENT_MESSAGE_SEND_FINISHED:
            if (gScanConnectWork->mState == SCAN_CONNECT_STATE_SEND_START) {
                SetScanConnectStateAndNotify(SCAN_CONNECT_STATE_SEND_DONE, 0);
            } else if (gScanConnectWork->mState == SCAN_CONNECT_STATE_SEND_DONE) {
                StartResetWithFlag();
            }
            break;
    }
}

void QueueStateMessage(void) {
    ChildMessage childMessage;
    MBCommRequestData requestData;
    u8 *payload;
    switch (gScanConnectWork->mState) {
        case SCAN_CONNECT_STATE_SEND_REQUEST:
            requestData.mGgid = gScanConnectWork->mGgid;
            requestData.mVersion = 1;
            requestData.mFileId = gScanConnectWork->mFileId;
            MI_CpuCopy8(gScanConnectWork->mUserInfo, requestData.mUserInfo, sizeof(requestData.mUserInfo));
            childMessage.mKind = CHILD_MESSAGE_REQUEST;
            payload = &childMessage.mKind;
            payload += 3;
            childMessage.mPieceRequestByte = MBi_SendRequestDataPiece(payload, &requestData);
            if (MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer) != NULL) {
                QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            }
            break;
        case SCAN_CONNECT_STATE_ACCEPTED:
            childMessage.mKind = CHILD_MESSAGE_ACCEPT_ACK;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        case SCAN_CONNECT_STATE_WAIT_START:
            break;
        case SCAN_CONNECT_STATE_SEND_START:
            childMessage.mKind = CHILD_MESSAGE_START_ACK;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        case SCAN_CONNECT_STATE_SEND_DONE:
            childMessage.mKind = CHILD_MESSAGE_DONE_ACK;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        default:
            childMessage.mKind = CHILD_MESSAGE_NONE;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
    }
}

#pragma thumb off
