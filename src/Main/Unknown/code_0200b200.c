#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Net/ScanConnect.h"
#include "code_0214d018.h"

#pragma thumb on

void MBFi_StateOutEndScan(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        MBFi_ScanErrorCallback(0xb, a->mResultCode);
        return;
    }
    mbf_work->mEndScanRequested = 0;
    if (mbf_work->mEndRequested != 0) {
        MBFi_EndComplete();
        return;
    }
    MBFi_ScanCallback(3, NULL, 0);
}

u32 MB_FakeEntryToParent(u32 entryIndex) {
    EntryRecord *v1;
    v1 = MB_GetGameInfoRecvList(entryIndex);
    if (v1 == NULL) {
        return 0;
    }
    mbf_work->field5F08 = v1->field4B8;
    mbf_work->field5F0C = v1->field4B5;
    MBi_WMSetBuffer((u32) mbf_work->mMPLink);
    MBi_WMSetCallback((u32) MBFi_WMCallback);
    MBFi_CommChangeChildState(1, 0);
    MI_CpuCopy8(v1->mScanBuffer, mbf_work->mScanBuffer, 0xc0);
    MBi_WMStartConnect(mbf_work->mScanBuffer);
    return 1;
}

void MBFi_WMCallback(s32 a, Unk021425e8 *b) {
    u16 v1;
    u16 v2;
    u16 t;
    switch (a) {
        case 7:
        case 8:
            break;
        case 11:
            MBFi_CommChangeChildState(3, 0);
            break;
        case 6:
            MBFi_CommChangeChildState(2, b);
            SetPortCallbackAndStartMP(mbf_work, mbf_work->mReceiveBuffer);
            break;
        case 10:
            MBFi_CommChangeChildState(4, b);
            break;
        case 25:
            MBFi_CommChildSendData();
            break;
        case 9:
            MBFi_CommChildRecvData(b);
            break;
        case 15:
            if (mbf_work->mState == 10) {
                MBFi_CommChangeChildState(11, 0);
            } else {
                MBFi_CommChangeChildState(12, 0);
            }
            if (mbf_work->mEndRequested != 0) {
                MBFi_EndComplete();
            }
            break;
        case 0xff:
            t = b->mResultCode;
            if (mbf_work->mStateCallback != NULL) {
                switch (t) {
                    case 1:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                    case 9:
                        t = 9;
                        break;
                    case 15:
                    default:
                        t = 8;
                        break;
                }
                v1 = t;
                mbf_work->mStateCallback(0x13, &v1);
            }
            break;
        case 0x100:
            t = b->mCommand;
            if (mbf_work->mStateCallback != NULL) {
                switch (t) {
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
                        t = 9;
                        break;
                    case 1:
                    default:
                        t = 8;
                        break;
                }
                v2 = t;
                mbf_work->mStateCallback(0x13, &v2);
            }
            break;
        case 0x29:
            break;
    }
}

void MBFi_CommChildRecvData(Unk021425e8 *a) {
    ParentMessage v1;
    MBi_SetRecvBufferFromParent(&v1, a->fieldC);
    switch (v1.mKind) {
        case 1:
            if (mbf_work->mState == 2) {
                MBFi_CommChangeChildState(5, 0);
            }
            break;
        case 2:
            if (mbf_work->mState == 5) {
                MBFi_CommChangeChildState(6, 0);
            }
            break;
        case 6:
            if (mbf_work->mState == 5) {
                MBFi_CommChangeChildState(0xe, 0);
            }
            break;
        case 3:
            if (mbf_work->mState == 5) {
                MBFi_CommChangeChildState(7, 0);
            }
            break;
        case 4:
            if (mbf_work->mState == 7) {
                MBFi_CommChangeChildState(8, 0);
            }
            if (mbf_work->mState == 8) {
                MBFi_CommChangeChildState(9, 0);
            }
            break;
        case 5:
            if (mbf_work->mState == 9) {
                MBFi_CommChangeChildState(10, 0);
            } else if (mbf_work->mState == 10) {
                StartResetWithFlag();
            }
            break;
    }
}

void MBFi_CommChildSendData(void) {
    ChildMessage v1;
    Unk0200c12c v2;
    u8 *p;
    switch (mbf_work->mState) {
        case 5:
            v2.field0 = mbf_work->field5F08;
            v2.field1A = 1;
            v2.field1C = mbf_work->field5F0C;
            MI_CpuCopy8(mbf_work->field5C4, v2.field4, 0x16);
            v1.mKind = 7;
            p = &v1.mKind;
            p += 3;
            *(u8 *) &v1.field2 = CopyNextPiece(p, &v2);
            if (WriteChildMessage(&v1, mbf_work->mMessageBuffer) != NULL) {
                QueueMPDataIfReady(8, 0xffff, mbf_work->mMessageBuffer);
            }
            break;
        case 7:
            v1.mKind = 8;
            WriteChildMessage(&v1, mbf_work->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, mbf_work->mMessageBuffer);
            break;
        case 8:
            break;
        case 9:
            v1.mKind = 10;
            WriteChildMessage(&v1, mbf_work->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, mbf_work->mMessageBuffer);
            break;
        case 10:
            v1.mKind = 11;
            WriteChildMessage(&v1, mbf_work->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, mbf_work->mMessageBuffer);
            break;
        default:
            v1.mKind = 0;
            WriteChildMessage(&v1, mbf_work->mMessageBuffer);
            QueueMPDataIfReady(8, 0xffff, mbf_work->mMessageBuffer);
            break;
    }
}

#pragma thumb off
