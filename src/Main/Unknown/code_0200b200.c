#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "code_0214d018.h"

#pragma thumb on

void ScanConnectEndScanCallback(Unk021425e8 *info) {
    if (info->mResultCode != 0) {
        ReportScanError(0xb, info->mResultCode);
        return;
    }
    gScanConnectWork->mEndScanRequested = 0;
    if (gScanConnectWork->mEndRequested != 0) {
        FinishScanConnect();
        return;
    }
    CallScanCallbackWithEntry(3, NULL, 0);
}

u32 StartConnectToEntry(u32 entryIndex) {
    MBGameInfoRecvList *entry;
    entry = MB_GetGameInfoRecvList(entryIndex);
    if (entry == NULL) {
        return 0;
    }
    gScanConnectWork->mUnk_5f08 = entry->mUnk_4b8;
    gScanConnectWork->mUnk_5f0c = entry->mUnk_4b5;
    SetupMPLink(&gScanConnectWork->mMPLink);
    SetMPLinkCallback(MPLinkCallback);
    SetScanConnectStateAndNotify(1, 0);
    MI_CpuCopy8(entry->mScanBuffer, &gScanConnectWork->mScanBuffer, 0xc0);
    ScanConnectStartConnect(&gScanConnectWork->mScanBuffer);
    return 1;
}

void MPLinkCallback(s32 eventKind, Unk021425e8 *info) {
    u16 resultCode;
    u16 commandCode;
    u16 code;
    switch (eventKind) {
        case 7:
        case 8:
            break;
        case 11:
            SetScanConnectStateAndNotify(3, 0);
            break;
        case 6:
            SetScanConnectStateAndNotify(2, info);
            SetPortCallbackAndStartMP(gScanConnectWork, gScanConnectWork->mReceiveBuffer);
            break;
        case 10:
            SetScanConnectStateAndNotify(4, info);
            break;
        case 25:
            QueueStateMessage();
            break;
        case 9:
            ReceivePortMessage(info);
            break;
        case 15:
            if (gScanConnectWork->mState == 10) {
                SetScanConnectStateAndNotify(11, 0);
            } else {
                SetScanConnectStateAndNotify(12, 0);
            }
            if (gScanConnectWork->mEndRequested != 0) {
                FinishScanConnect();
            }
            break;
        case 0xff:
            code = info->mResultCode;
            if (gScanConnectWork->mStateCallback != NULL) {
                switch (code) {
                    case 1:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                    case 9:
                        code = 9;
                        break;
                    case 15:
                    default:
                        code = 8;
                        break;
                }
                resultCode = code;
                gScanConnectWork->mStateCallback(0x13, &resultCode);
            }
            break;
        case 0x100:
            code = info->mCommand;
            if (gScanConnectWork->mStateCallback != NULL) {
                switch (code) {
                    case 0:
                    case 7:
                    case 8:
                    case 13:
                    case 14:
                    case 15:
                    case 17:
                    case 18:
                    case 21:
                    case 25:
                    case 29:
                        code = 9;
                        break;
                    case 1:
                    default:
                        code = 8;
                        break;
                }
                commandCode = code;
                gScanConnectWork->mStateCallback(0x13, &commandCode);
            }
            break;
        case 0x29:
            break;
    }
}

void ReceivePortMessage(Unk021425e8 *info) {
    ParentMessage parentMessage;
    MBi_SetRecvBufferFromParent(&parentMessage, info->mUnk_0c);
    switch (parentMessage.mKind) {
        case 1:
            if (gScanConnectWork->mState == 2) {
                SetScanConnectStateAndNotify(5, 0);
            }
            break;
        case 2:
            if (gScanConnectWork->mState == 5) {
                SetScanConnectStateAndNotify(6, 0);
            }
            break;
        case 6:
            if (gScanConnectWork->mState == 5) {
                SetScanConnectStateAndNotify(0xe, 0);
            }
            break;
        case 3:
            if (gScanConnectWork->mState == 5) {
                SetScanConnectStateAndNotify(7, 0);
            }
            break;
        case 4:
            if (gScanConnectWork->mState == 7) {
                SetScanConnectStateAndNotify(8, 0);
            }
            if (gScanConnectWork->mState == 8) {
                SetScanConnectStateAndNotify(9, 0);
            }
            break;
        case 5:
            if (gScanConnectWork->mState == 9) {
                SetScanConnectStateAndNotify(10, 0);
            } else if (gScanConnectWork->mState == 10) {
                StartResetWithFlag();
            }
            break;
    }
}

void QueueStateMessage(void) {
    ChildMessage childMessage;
    Unk0200c12c requestData;
    u8 *payload;
    switch (gScanConnectWork->mState) {
        case 5:
            requestData.mUnk_00 = gScanConnectWork->mUnk_5f08;
            requestData.mUnk_1a = 1;
            requestData.mUnk_1c = gScanConnectWork->mUnk_5f0c;
            MI_CpuCopy8(gScanConnectWork->mUnk_05c4, requestData.mUnk_04, 0x16);
            childMessage.mKind = 7;
            payload = &childMessage.mKind;
            payload += 3;
            *(u8 *) &childMessage.mUnk_02 = MBi_SendRequestDataPiece(payload, &requestData);
            if (MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer) != NULL) {
                QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            }
            break;
        case 7:
            childMessage.mKind = 8;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        case 8:
            break;
        case 9:
            childMessage.mKind = 10;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        case 10:
            childMessage.mKind = 11;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
        default:
            childMessage.mKind = 0;
            MBi_MakeChildSendBuffer(&childMessage, gScanConnectWork->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, gScanConnectWork->mMessageBuffer);
            break;
    }
}

#pragma thumb off
