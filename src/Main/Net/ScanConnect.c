#include "Main/Net/ScanConnect.h"

#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_020091fc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020091e0.h"
#include "Main/Unknown/code_02008e10.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02009908.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "03/code_021b94b8.h"

#pragma thumb on
u32 MBi_WMSetBuffer(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gMPLink;
    *(u32 *) ((value2) + 0u) = value0;
    value1 = 0u;
    *(u32 *) ((value0) + 12u) = value1;
    gMPLink->mMPStarted = value1;
    gMPLink->mUnk_1e = value1;
    gMPLink->mDataQueued = value1;
    gMPLink->mResetting = value1;
    value0 = *(const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 4u) = value1;
    value0 = *(const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 8u) = value1;
    value0 = *(const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void MBi_WMSetCallback(u32 callback) {
    u32 v1 = ((callback) + (0x0u));
    u32 v2 = (OS_DisableInterrupts());
    u32 v3 = ((u32) (&gMPLink));
    u32 v4 = (*(u32 *) ((v3) + (0)));
    u32 v6;
    *(u32 *) ((v4) + (0)) = v1;
    v6 = (OS_RestoreInterrupts(v2));
}

#pragma thumb off

#pragma thumb on

void MBi_WMStartConnect(u8 *scanBuffer) {
    s32 r;
    gMPLink->mMPStarted = 0;
    gMPLink->mResetting = 0;
    gMPLink->mSendBufferSize = (*OFFSET_PTR(u16, scanBuffer, 0x4e) + 0x21) & ~0x1f;
    gMPLink->mReceiveBufferSize = ((*OFFSET_PTR(u16, scanBuffer, 0x4c) + 0x55) & ~0x1f) * 2;
    gMPLink->mUnk_14 = *OFFSET_PTR(u16, scanBuffer, 0x4c);
    gMPLink->mUnk_16 = *OFFSET_PTR(u16, scanBuffer, 0x4e);
    gMPLink->mUnk_18 = gMPLink->mUnk_14 - 6;
    SetupPieceSizes(gMPLink->mUnk_16);
    r = WM_StartConnectEx(ScanConnectStartConnectCallback, (u16 *) scanBuffer, NULL, 1, 0);
    if (r != 2) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(11, 0);
        }
    }
}

void ScanConnectStartConnectCallback(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(11, a);
        }
    } else {
        switch (a->mUnk_08_0) {
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
                    gMPLink->mCallback(6, a);
                }
                break;
        }
    }
}

void SetPortCallbackAndStartMP(void *sendBuffer, u8 *receiveBuffer) {
    CommandResult v;
    CommandResult w;
    s32 r;
    MPLink *p;
    gMPLink->mSendBuffer = sendBuffer;
    gMPLink->mReceiveBuffer = receiveBuffer;
    r = WM_SetIndCallback(1, PortCallback, NULL);
    if (r != 0) {
        p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = 14;
            v.mResultCode = r;
            p->mCallback(0xff, &v);
        }
        return;
    }
    p = gMPLink;
    r = WM_StartMPEx(ScanConnectStartMPCallback, receiveBuffer, p->mReceiveBufferSize, sendBuffer, p->mSendBufferSize,
                     1, 0, 0, 0, 1, 1);
    if (r != 2) {
        p = gMPLink;
        if (p->mCallback != NULL) {
            w.mCommand = 14;
            w.mResultCode = r;
            p->mCallback(0xff, &w);
        }
    }
}

void ScanConnectStartMPCallback(Unk021425e8 *a) {
    CommandResult v;
    CommandResult w;
    MPLink *p;
    u16 c;
    u16 b = a->mResultCode;
    if (b != 0) {
        if (b != 15 && b != 9 && b != 13) {
            c = a->mCommand;
            p = gMPLink;
            if (p->mCallback != NULL) {
                v.mCommand = c;
                v.mResultCode = b;
                p->mCallback(0x100, &v);
            }
        }
    } else {
        switch (a->mUnk_04) {
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
                c = a->mCommand;
                p = gMPLink;
                if (p->mCallback != NULL) {
                    w.mCommand = c;
                    w.mResultCode = 1;
                    p->mCallback(0x100, &w);
                }
                break;
            case 12:
            case 13:
                break;
        }
    }
}

void StartResetWithFlag(void) {
    CommandResult v;
    s32 r;
    gMPLink->mResetting = 1;
    r = WM_Reset(StartResetWithFlagCallback);
    if (r != 2) {
        MPLink *p;
        gMPLink->mResetting = 0;
        p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = 1;
            v.mResultCode = r;
            p->mCallback(0xff, &v);
        }
    }
}

void StartResetWithFlagCallback(Unk021425e8 *a) {
    CommandResult v;
    u16 b;
    gMPLink->mResetting = 0;
    b = a->mResultCode;
    if (b != 0) {
        u16 c = a->mCommand;
        MPLink *p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = c;
            v.mResultCode = b;
            p->mCallback(0x100, &v);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(15, 0);
        }
    }
}

void StartReset(void) {
    CommandResult v;
    s32 r = WM_Reset(StartResetCallback);
    if (r != 2) {
        MPLink *p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = 1;
            v.mResultCode = r;
            p->mCallback(0xff, &v);
        }
    }
}

void StartResetCallback(Unk021425e8 *a) {
    CommandResult v;
    u16 b = a->mResultCode;
    if (b != 0) {
        u16 c = a->mCommand;
        MPLink *p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = c;
            v.mResultCode = b;
            p->mCallback(0x100, &v);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(15, 0);
        }
    }
}

u32 IsMPReadyToQueueData(void) {
    u32 r = 0;
    u32 v = 0;
    MPLink *p = gMPLink;
    if (p->mMPStarted == 1 && p->mDataQueued == 0) {
        v = 1;
    }
    if (v != 0 && p->mResetting == 0) {
        r = 1;
    }
    return r;
}

void PortCallback(Unk021425e8 *a) {
    if (a->mResultCode == 0) {
        switch (a->mUnk_04) {
            case 7:
            case 9:
                break;
            case 21:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(9, a);
                }
                break;
        }
    }
}

s32 QueueMPDataIfReady(u32 a, u16 b, u8 *c) {
    s32 r;
    DC_FlushRange(c, 4);
    DC_WaitWriteBufferEmpty();
    if (IsMPReadyToQueueData() == 0) {
        return 1;
    }
    r = WM_SetMPDataToPortEx(QueueMPDataCallback, NULL, c, (u16) a, b, 1, 3);
    if (r == 2) {
        gMPLink->mDataQueued = 1;
        return 2;
    }
    return r;
}

void QueueMPDataCallback(Unk021425e8 *a) {
    gMPLink->mDataQueued = 0;
    if (a->mResultCode == 0) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(8, a);
        }
    } else if (a->mResultCode == 9) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(0x29, a);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(0x12, a);
        }
    }
    if (gMPLink->mCallback != NULL) {
        gMPLink->mCallback(0x19, 0);
    }
}

void MBi_WMClearCallback(void) {
    WM_SetIndCallback(1, NULL, NULL);
}

void MB_FakeInit(ScanConnectWork *a, void *b) {
    if (*(u16 *) &mbf_initialize == 0) {
        *(u16 *) &mbf_initialize = 1;
        MI_CpuFill8(a, 0, 0x5f20);
        mbf_work = a;
        a->mState = 0;
        MI_CpuCopy8(b, mbf_work->mUnk_05c4, 0x16);
        MBi_SetBeaconRecvStatusBuffer(mbf_work->mUnk_05e8);
        MB_InitRecvGameInfoStatus();
        MBi_SetScanLockFunc((UnkFunc *) MBFi_ScanLock, (UnkFunc *) MBFi_ScanUnlock);
    }
}

void MB_FakeEnd(void) {
    if (mbf_work->mEndRequested == 0) {
        mbf_work->mEndRequested = 1;
        switch (mbf_work->mState) {
            case 0:
                if (mbf_work->mRepeatScan != 0) {
                    mbf_work->mRepeatScan = 0;
                    return;
                }
                if (mbf_work->mEndScanRequested == 0) {
                    MBFi_EndComplete();
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
                MBFi_EndComplete();
                break;
            default:
                OS_Terminate();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void MBFi_EndComplete(void) {
    *(u16 *) &mbf_initialize = 0;
    mbf_work->mEndRequested = 0;
    MBi_WMClearCallback();
    MBFi_CommChangeChildState(0x14, NULL);
}

u32 MB_FakeGetWorkSize(void) {
    return 0x5f20u;
}

void MB_FakeSetCStateCallback(UnkFunc *callback) {
    u32 v1 = (u32) callback;
    u32 v2 = (OS_DisableInterrupts());
    u32 v3 = ((u32) (&mbf_work));
    u32 v4 = (*(u32 *) ((v3) + (0)));
    u32 v5 = 0x5e0u;
    u32 v7;
    *(u32 *) ((v4) + (0 + (v5))) = v1;
    v7 = (OS_RestoreInterrupts(v2));
}

#pragma thumb off

#pragma thumb on

void MBFi_CommChangeChildState(u32 state, void *b) {
    u32 v1;
    v1 = OS_DisableInterrupts();
    mbf_work->mState = state;
    OS_RestoreInterrupts(v1);
    if (mbf_work->mStateCallback != NULL) {
        mbf_work->mStateCallback(state, b);
    }
}

#pragma thumb off

#pragma thumb on

void MB_FakeStartScanParent(UnkFunc *callback, u32 b) {
    mbf_work->mScanCallback = callback;
    mbf_work->mUnk_05e4 = b;
    mbf_work->mScanParams.mUnk_04 = 0;
    mbf_work->mScanParams.mUnk_00 = mbf_work->mScanBuffer;
    mbf_work->mRepeatScan = 1;
    mbf_work->mUseScanBssid = 0;
    mbf_work->mUnk_05ee = 0;
    MBFi_StateInStartScan();
}

#pragma thumb off

#pragma thumb on

void MBFi_StateInStartScan(void) {
    s32 r;
    ScanConnectWork *d;
    u8 *p;
    u8 *q;
    d = mbf_work;
    if (d->mUseScanBssid != 0) {
        d->mScanParams.mUnk_06 = 0xdc;
    } else {
        p = d->mScanParams.mUnk_08;
        q = gDefaultScanBssid;
        p[0] = q[0];
        p[1] = q[1];
        p[2] = q[2];
        p[3] = q[3];
        p[4] = q[4];
        p[5] = q[5];
        mbf_work->mScanParams.mUnk_06 = 10;
        if (RotateChannel() == 0) {
            MBFi_ScanErrorCallback(0x1e, 0);
            return;
        }
    }
    if (mbf_work->mScanParams.mUnk_04 == 0) {
        mbf_work->mScanParams.mUnk_04 = 1;
    }
    r = WM_StartScan(MBFi_StateOutStartScanParent, &mbf_work->mScanParams);
    if (r != 2) {
        MBFi_ScanErrorCallback(0xa, r);
    }
}

void MBFi_StateOutStartScanParent(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        MBFi_ScanErrorCallback(0xa, a->mResultCode);
        return;
    }
    switch (a->mUnk_08_0) {
        case 3:
            break;
        case 5:
            if (a->mUnk_38.mUnk_00[1] == mbf_work->mUnk_05e4) {
                DC_InvalidateRange(mbf_work->mScanBuffer, 0xc0);
                MB_RecvGameInfoBeacon(MBFi_CommBeaconRecvCallback, a->mUnk_12, (ScanBlock *) mbf_work->mScanBuffer);
                MB_CountGameInfoLifetime(MBFi_CommBeaconRecvCallback, 1);
            }
        case 4:
            MB_CountGameInfoLifetime(MBFi_CommBeaconRecvCallback, 0);
            if (mbf_work->mRepeatScan != 0) {
                MBFi_StateInStartScan();
            } else {
                MBFi_StateInEndScan();
            }
            break;
        default:
            MBFi_ScanErrorCallback(0xa, 1);
            break;
    }
}

void MBFi_ScanCallback(u32 a, EntryRecord *entry, u32 entryIndex) {
    ScanEntryArgs v;
    ScanConnectWork *d;
    d = mbf_work;
    if (d->mScanCallback != NULL) {
        v.mEntryIndex = entryIndex;
        if (entry != NULL) {
            v.mEntry = entry;
            v.mScanBuffer = entry->mScanBuffer;
        } else {
            v.mEntry = NULL;
            v.mScanBuffer = NULL;
        }
        d->mScanCallback(a, &v);
    }
}

void MBFi_ScanErrorCallback(u16 a, u16 b) {
    ScanErrorArgs v;
    if (mbf_work->mScanCallback != NULL) {
        v.mUnk_00 = a;
        v.mUnk_02 = b;
        mbf_work->mScanCallback(2, &v);
    }
}

void MBFi_ScanLock(const u8 *a) {
    u8 *p;
    mbf_work->mUseScanBssid = 1;
    p = mbf_work->mScanParams.mUnk_08;
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    p[3] = a[3];
    p[4] = a[4];
    p[5] = a[5];
}

#pragma thumb off

#pragma thumb on
u32 MBFi_ScanUnlock(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &mbf_work;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x5f00u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

void MBFi_CommBeaconRecvCallback(u32 a, void *entry, u32 entryIndex) {
    switch (a) {
        case 0:
        case 2:
        case 4:
            break;
        case 1:
            MBFi_ScanCallback(0, entry, entryIndex);
            break;
        case 3:
            MBFi_ScanCallback(1, entry, entryIndex);
            break;
    }
}

u32 RotateChannel(void) {
    u16 a;
    a = WM_GetAllowedChannel();
    if (a == 0x8000 || a == 0) {
        return 0;
    }
    mbf_work->mScanParams.mUnk_04++;
    do {
        mbf_work->mScanParams.mUnk_04++;
        if (mbf_work->mScanParams.mUnk_04 > 0x10) {
            mbf_work->mScanParams.mUnk_04 = 1;
        }
    } while ((a & (1 << (mbf_work->mScanParams.mUnk_04 - 1))) == 0);
    return 1;
}

void RequestEndScan(void) {
    mbf_work->mRepeatScan = 0;
    mbf_work->mEndScanRequested = 1;
}

#pragma thumb off

#pragma thumb on

void MBFi_StateInEndScan(void) {
    u32 v1;
    v1 = WM_EndScan(MBFi_StateOutEndScan);
    if (v1 != 2) {
        MBFi_ScanErrorCallback(0xb, v1 & 0xffff);
    }
}

#pragma thumb off
