#include "Main/Net/mp_link.h"

#include "code_0200fc8c.h"
#include "Main/Net/scan_connect_callbacks.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "code_020091fc.h"
#include "mb_gameinfo.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "code_02009908.h"
#include "code_0200c0d8.h"
#include "03/Net/essid_packet_steps.h"

const u8 gDefaultScanBssid[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
u16 gScanConnectInitialized;
struct MPLink *gMPLink;
struct ScanConnectWork *gScanConnectWork;

#pragma thumb on
void SetupMPLink(MPLink *link) {
    gMPLink = link;
    link->mUnk_0c = 0;
    gMPLink->mMPStarted = 0;
    gMPLink->mUnk_1e = 0;
    gMPLink->mDataQueued = 0;
    gMPLink->mResetting = 0;
    gMPLink->mSendBuffer = NULL;
    gMPLink->mReceiveBuffer = NULL;
    gMPLink->mCallback = NULL;
}
#pragma thumb off

#pragma thumb on

void SetMPLinkCallback(UnkFunc *callback) {
    u32 irqState = (OS_DisableInterrupts());
    u32 restoredIrq;
    gMPLink->mCallback = callback;
    restoredIrq = (OS_RestoreInterrupts(irqState));
}

#pragma thumb off

#pragma thumb on

void ScanConnectStartConnect(WMBssDesc *scanBuffer) {
    s32 wmResult;
    gMPLink->mMPStarted = 0;
    gMPLink->mResetting = 0;
    gMPLink->mSendBufferSize = (scanBuffer->mGameInfo.mChildMaxSize + 0x21) & ~0x1f;
    gMPLink->mReceiveBufferSize = ((scanBuffer->mGameInfo.mParentMaxSize + 0x55) & ~0x1f) * 2;
    gMPLink->mUnk_14 = scanBuffer->mGameInfo.mParentMaxSize;
    gMPLink->mUnk_16 = scanBuffer->mGameInfo.mChildMaxSize;
    gMPLink->mUnk_18 = gMPLink->mUnk_14 - 6;
    MBi_SetChildMPMaxSize(gMPLink->mUnk_16);
    wmResult = WM_StartConnectEx(ScanConnectStartConnectCallback, (u16 *) scanBuffer, NULL, 1, 0);
    if (wmResult != 2) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(11, 0);
        }
    }
}

void ScanConnectStartConnectCallback(Unk021425e8 *result) {
    if (result->mResultCode != 0) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(11, result);
        }
    } else {
        switch (result->mReplyState) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
                break;
            case 9:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(10, 0);
                }
                break;
            case 7:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(6, result);
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
    wmResult = WM_SetPortCallback(1, PortCallback, NULL);
    if (wmResult != 0) {
        mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            portError.mCommand = 14;
            portError.mResultCode = wmResult;
            mpLink->mCallback(0xff, &portError);
        }
        return;
    }
    mpLink = gMPLink;
    wmResult = WM_StartMPEx(ScanConnectStartMPCallback, receiveBuffer, mpLink->mReceiveBufferSize, sendBuffer,
                            mpLink->mSendBufferSize, 1, 0, 0, 0, 1, 1);
    if (wmResult != 2) {
        mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            startError.mCommand = 14;
            startError.mResultCode = wmResult;
            mpLink->mCallback(0xff, &startError);
        }
    }
}

void ScanConnectStartMPCallback(Unk021425e8 *result) {
    CommandResult errorResult;
    CommandResult stateResult;
    MPLink *mpLink;
    u16 command;
    u16 resultCode = result->mResultCode;
    if (resultCode != 0) {
        if (resultCode != 15 && resultCode != 9 && resultCode != 13) {
            command = result->mCommand;
            mpLink = gMPLink;
            if (mpLink->mCallback != NULL) {
                errorResult.mCommand = command;
                errorResult.mResultCode = resultCode;
                mpLink->mCallback(0x100, &errorResult);
            }
        }
    } else {
        switch (result->mState) {
            case 10:
                gMPLink->mMPStarted = 1;
                gMPLink->mDataQueued = 0;
                gMPLink->mUnk_1e = 0;
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(20, 0);
                }
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(25, 0);
                }
                break;
            case 11:
            default:
                command = result->mCommand;
                mpLink = gMPLink;
                if (mpLink->mCallback != NULL) {
                    stateResult.mCommand = command;
                    stateResult.mResultCode = 1;
                    mpLink->mCallback(0x100, &stateResult);
                }
                break;
            case 12:
            case 13:
                break;
        }
    }
}

void StartResetWithFlag(void) {
    CommandResult errorResult;
    s32 wmResult;
    gMPLink->mResetting = 1;
    wmResult = WM_Reset(StartResetWithFlagCallback);
    if (wmResult != 2) {
        MPLink *mpLink;
        gMPLink->mResetting = 0;
        mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = 1;
            errorResult.mResultCode = wmResult;
            mpLink->mCallback(0xff, &errorResult);
        }
    }
}

void StartResetWithFlagCallback(Unk021425e8 *result) {
    CommandResult errorResult;
    u16 resultCode;
    gMPLink->mResetting = 0;
    resultCode = result->mResultCode;
    if (resultCode != 0) {
        u16 command = result->mCommand;
        MPLink *mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = command;
            errorResult.mResultCode = resultCode;
            mpLink->mCallback(0x100, &errorResult);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(15, 0);
        }
    }
}

void StartReset(void) {
    CommandResult errorResult;
    s32 wmResult = WM_Reset(StartResetCallback);
    if (wmResult != 2) {
        MPLink *mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = 1;
            errorResult.mResultCode = wmResult;
            mpLink->mCallback(0xff, &errorResult);
        }
    }
}

void StartResetCallback(Unk021425e8 *result) {
    CommandResult errorResult;
    u16 resultCode = result->mResultCode;
    if (resultCode != 0) {
        u16 command = result->mCommand;
        MPLink *mpLink = gMPLink;
        if (mpLink->mCallback != NULL) {
            errorResult.mCommand = command;
            errorResult.mResultCode = resultCode;
            mpLink->mCallback(0x100, &errorResult);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(15, 0);
        }
    }
}

u32 IsMPReadyToQueueData(void) {
    u32 ready = 0;
    u32 mpActive = 0;
    MPLink *mpLink = gMPLink;
    if (mpLink->mMPStarted == 1 && mpLink->mDataQueued == 0) {
        mpActive = 1;
    }
    if (mpActive != 0 && mpLink->mResetting == 0) {
        ready = 1;
    }
    return ready;
}

void PortCallback(Unk021425e8 *result) {
    if (result->mResultCode == 0) {
        switch (result->mState) {
            case 7:
            case 9:
                break;
            case 21:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(9, result);
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
        return 1;
    }
    wmResult = WM_SetMPDataToPortEx(QueueMPDataCallback, NULL, data, (u16) dataSize, destBitmap, 1, 3);
    if (wmResult == 2) {
        gMPLink->mDataQueued = 1;
        return 2;
    }
    return wmResult;
}

void QueueMPDataCallback(Unk021425e8 *result) {
    gMPLink->mDataQueued = 0;
    if (result->mResultCode == 0) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(8, result);
        }
    } else if (result->mResultCode == 9) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(0x29, result);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(0x12, result);
        }
    }
    if (gMPLink->mCallback != NULL) {
        gMPLink->mCallback(0x19, 0);
    }
}

void ClearPortCallback(void) {
    WM_SetPortCallback(1, NULL, NULL);
}

void InitScanConnectWork(ScanConnectWork *work, void *initData) {
    if (gScanConnectInitialized == 0) {
        gScanConnectInitialized = 1;
        MI_CpuFill8(work, 0, 0x5f20);
        gScanConnectWork = work;
        work->mState = 0;
        MI_CpuCopy8(initData, gScanConnectWork->mUnk_05c4, 0x16);
        MBi_SetBeaconRecvStatusBuffer(gScanConnectWork->mUnk_05e8);
        MB_InitRecvGameInfoStatus();
        MBi_SetScanLockFunc(SetScanBssid, ClearUseScanBssid);
    }
}

void CloseScanConnect(void) {
    if (gScanConnectWork->mEndRequested == 0) {
        gScanConnectWork->mEndRequested = 1;
        switch (gScanConnectWork->mState) {
            case 0:
                if (gScanConnectWork->mRepeatScan != 0) {
                    gScanConnectWork->mRepeatScan = 0;
                    return;
                }
                if (gScanConnectWork->mEndScanRequested == 0) {
                    FinishScanConnect();
                    return;
                }
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 6:
            case 14:
            case 19:
                StartReset();
                break;
            case 5:
            case 7:
            case 8:
            case 9:
                StartResetWithFlag();
                break;
            case 10:
                break;
            case 11:
            case 12:
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
    gScanConnectInitialized = 0;
    gScanConnectWork->mEndRequested = 0;
    ClearPortCallback();
    SetScanConnectStateAndNotify(0x14, NULL);
}

u32 GetScanConnectWorkSize(void) {
    return 0x5f20u;
}

void SetScanConnectStateCallback(UnkFunc *callback) {
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

void StartRepeatedScan(UnkFunc *callback, u32 param) {
    gScanConnectWork->mScanCallback = callback;
    gScanConnectWork->mUnk_05e4 = param;
    gScanConnectWork->mScanParams.mChannel = 0;
    gScanConnectWork->mScanParams.mScanBuf = &gScanConnectWork->mScanBuffer;
    gScanConnectWork->mRepeatScan = 1;
    gScanConnectWork->mUseScanBssid = 0;
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
    if (work->mUseScanBssid != 0) {
        work->mScanParams.mMaxChannelTime = 0xdc;
    } else {
        bssid = work->mScanParams.mBssid;
        defaultBssid = gDefaultScanBssid;
        bssid[0] = defaultBssid[0];
        bssid[1] = defaultBssid[1];
        bssid[2] = defaultBssid[2];
        bssid[3] = defaultBssid[3];
        bssid[4] = defaultBssid[4];
        bssid[5] = defaultBssid[5];
        gScanConnectWork->mScanParams.mMaxChannelTime = 10;
        if (PickScanChannel() == 0) {
            ReportScanError(0x1e, 0);
            return;
        }
    }
    if (gScanConnectWork->mScanParams.mChannel == 0) {
        gScanConnectWork->mScanParams.mChannel = 1;
    }
    wmResult = WM_StartScan(ScanConnectStartScanCallback, &gScanConnectWork->mScanParams);
    if (wmResult != 2) {
        ReportScanError(0xa, wmResult);
    }
}

void ScanConnectStartScanCallback(Unk021425e8 *result) {
    if (result->mResultCode != 0) {
        ReportScanError(0xa, result->mResultCode);
        return;
    }
    switch (result->mReplyState) {
        case 3:
            break;
        case 5:
            if (result->mUnk_38.mUnk_00[1] == gScanConnectWork->mUnk_05e4) {
                DC_InvalidateRange(&gScanConnectWork->mScanBuffer, 0xc0);
                MB_RecvGameInfoBeacon(EntryCallback, result->mAid, &gScanConnectWork->mScanBuffer);
                MB_CountGameInfoLifetime(EntryCallback, 1);
            }
        case 4:
            MB_CountGameInfoLifetime(EntryCallback, 0);
            if (gScanConnectWork->mRepeatScan != 0) {
                ScanConnectStartScan();
            } else {
                ScanConnectEndScan();
            }
            break;
        default:
            ReportScanError(0xa, 1);
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
            args.mScanBuffer = entry->mScanBuffer;
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
        gScanConnectWork->mScanCallback(2, &args);
    }
}

void SetScanBssid(const u8 *bssid) {
    u8 *dest;
    gScanConnectWork->mUseScanBssid = 1;
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
    gScanConnectWork->mUseScanBssid = 0;
}
#pragma thumb off

#pragma thumb on

void EntryCallback(u32 event, void *entry, u32 entryIndex) {
    switch (event) {
        case 0:
        case 2:
        case 4:
            break;
        case 1:
            CallScanCallbackWithEntry(0, entry, entryIndex);
            break;
        case 3:
            CallScanCallbackWithEntry(1, entry, entryIndex);
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
        if (gScanConnectWork->mScanParams.mChannel > 0x10) {
            gScanConnectWork->mScanParams.mChannel = 1;
        }
    } while ((allowedChannels & (1 << (gScanConnectWork->mScanParams.mChannel - 1))) == 0);
    return 1;
}

void RequestEndScan(void) {
    gScanConnectWork->mRepeatScan = 0;
    gScanConnectWork->mEndScanRequested = 1;
}

#pragma thumb off

#pragma thumb on

void ScanConnectEndScan(void) {
    u32 wmResult;
    wmResult = WM_EndScan(ScanConnectEndScanCallback);
    if (wmResult != 2) {
        ReportScanError(0xb, wmResult & 0xffff);
    }
}

#pragma thumb off
