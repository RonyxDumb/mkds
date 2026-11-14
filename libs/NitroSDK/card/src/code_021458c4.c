#include "code_021458c4.h"
#include "code_0214613c.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0200f328.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02000000.h"
#include "code_021457ec.h"
#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_02146000.h"
#include "card_request.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217f000.h"
#include "code_0200c914.h"
#include "os_thread.h"
#include "code_0214c778.h"
#include "code_0214d018.h"
#include "mi_dma_card.h"
#include "code_0214d5b8.h"
#include "registers.h"
#include "code_02146af4.h"

CARDiCommandArg gRequestBlock;
CARDiCommon gAccessState;

// Task that sends the backup transfer in pieces of at most 0x100 bytes through CARDiCommon.mBackupCachePageBuf, then
// ends the transfer and calls the callback.
void CARDi_RequestStreamCommandCore(CARDiCommon *p) {
    u32 reqType;
    u32 reqMode;
    u32 retryCount;
    u32 len;
    u32 *buf;
    UnkFunc *callback;
    u32 callbackArg;
    u32 enabled;

    reqType = p->mReqType;
    reqMode = p->mReqMode;
    retryCount = p->mReqRetry;
    func_02000b44((u32) (BuildInfo + 0x24));
    do {
        len = p->mLen;
        if (len > 0x100) {
            len = 0x100;
        }
        p->mCmd->mLen = len;
        if (p->mFlag & 0x40) {
            p->mFlag &= ~0x40;
            p->mCmd->mResult = 7;
            break;
        }
        if (reqMode == 0) {
            DC_InvalidateRange(p->mBackupCachePageBuf, len);
            p->mCmd->mSrc = p->mSrc;
            p->mCmd->mDst = (u32) p->mBackupCachePageBuf;
        } else {
            MI_CpuCopy8((void *) p->mSrc, p->mBackupCachePageBuf, len);
            DC_FlushRange(p->mBackupCachePageBuf, len);
            DC_WaitWriteBufferEmpty();
            p->mCmd->mSrc = (s32) p->mBackupCachePageBuf;
            p->mCmd->mDst = p->mDst;
        }
        if (CARDi_Request(p, reqType, retryCount) == 0) {
            break;
        }
        if (reqMode == 2) {
            if (CARDi_Request(p, 9, 1) == 0) {
                break;
            }
        } else if (reqMode == 0) {
            MI_CpuCopy8(p->mBackupCachePageBuf, (void *) p->mDst, len);
        }
        p->mSrc += len;
        p->mDst += len;
        p->mLen -= len;
    } while (p->mLen != 0);
    callback = p->mCallback;
    callbackArg = p->mCallbackArg;
    enabled = OS_DisableInterrupts();
    p->mFlag &= ~0x4c;
    OS_WakeupThread(&p->mBusyQ);
    if (p->mFlag & 0x10) {
        OS_WakeupThreadDirect(&p->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
}

// Starts a backup transfer of the given source, destination and length. Waits for the previous transfer first. The
// game always passes isAsync 1, which queues CARDi_RequestStreamCommandCore on the worker thread.
int CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, UnkFunc *callback, void *callbackArg, u32 isAsync,
                               u32 reqType, u32 reqRetry, u32 reqMode) {
    CARDiCommon *p;
    u32 enabled;

    p = (CARDiCommon *) (u32) &gAccessState;
    func_02000b44((u32) (BuildInfo + 0x24));
    enabled = OS_DisableInterrupts();
    while (p->mFlag & 4) {
        OS_SleepThread(&p->mBusyQ);
    }
    p->mFlag |= 4;
    p->mCallback = callback;
    p->mCallbackArg = (u32) callbackArg;
    OS_RestoreInterrupts(enabled);
    p->mSrc = src;
    p->mDst = dst;
    p->mLen = len;
    p->mReqType = reqType;
    p->mReqRetry = reqRetry;
    p->mReqMode = reqMode;
    if (isAsync != 0) {
        CARDi_SetTask(CARDi_RequestStreamCommandCore);
        return 1;
    }
    gAccessState.mCurTh = data_0216ff5c.mCurrentThread;
    CARDi_RequestStreamCommandCore(p);
    return p->mCmd->mResult == 0;
}

// Sets the backup type, then reads one byte of the backup to identify it. Returns 1 when CARDiCommandArg.mResult is 0.
int CARD_IdentifyBackup(s32 type) {
    CARDiCommon *p;
    UnkFunc *callback;
    u32 callbackArg;
    u32 enabled;

    p = &gAccessState;
    func_02000b44((u32) (BuildInfo + 0x24));
    if (type == 0) {
        OS_Terminate();
    }
    CARD_CheckEnabled();
    enabled = OS_DisableInterrupts();
    while (p->mFlag & 4) {
        OS_SleepThread(&p->mBusyQ);
    }
    p->mFlag |= 4;
    p->mCallback = 0;
    p->mCallbackArg = 0;
    OS_RestoreInterrupts(enabled);
    CARDi_IdentifyBackupCore(type);
    gAccessState.mCurTh = data_0216ff5c.mCurrentThread;
    CARDi_Request(p, 2, 1);
    p->mCmd->mSrc = 0;
    p->mCmd->mDst = (u32) p->mBackupCachePageBuf;
    p->mCmd->mLen = 1;
    CARDi_Request(p, 6, 1);
    callback = p->mCallback;
    callbackArg = p->mCallbackArg;
    enabled = OS_DisableInterrupts();
    p->mFlag &= ~0x4c;
    OS_WakeupThread(&p->mBusyQ);
    if (p->mFlag & 0x10) {
        OS_WakeupThreadDirect(&p->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
    return p->mCmd->mResult == 0;
}

// Waits for the running transfer to end.
int CARD_WaitBackupAsync(void) {
    return CARDi_WaitAsync();
}

// Returns 1 when no transfer is running.
int CARD_TryWaitBackupAsync(void) {
    return CARDi_TryWaitAsync();
}

// Fills CARDiCommandArg.mType and the device description (size, page size, address width, timings) for a backup type.
// An unknown type clears them and stores 3 in CARDiCommandArg.mResult.
void CARDi_IdentifyBackupCore(s32 type) {
    CARDiCommandArg *p;
    u32 size;
    u32 device;

    p = gAccessState.mCmd;
    MI_CpuFill8(&p->mTotalSize, 0, 0x28);
    p->mType = type;
    if (type == 0) {
        return;
    }
    size = 1 << ((type >> 8) & 0xff);
    p->mTotalSize = size;
    device = type & 0xff;
    if (device == 1) {
        switch (size) {
            case 0x200:
                p->mPageSize = 0x10;
                p->mAddrWidth = 1;
                p->mProgramPage = 0x4f;
                break;
            case 0x2000:
                p->mPageSize = 0x20;
                p->mAddrWidth = 2;
                p->mProgramPage = 0x4f;
                break;
            case 0x10000:
                p->mPageSize = 0x80;
                p->mAddrWidth = 2;
                p->mProgramPage = 0x9e;
                break;
            default:
                goto fail;
        }
    } else if (device == 2) {
        switch (size) {
            case 0x40000:
                p->mWritePage = 0x18b;
                p->mWritePageTotal = 0x127f;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                p->mUnk_34 = 0x13435;
                break;
            case 0x80000:
            case 0x100000:
                p->mWritePage = 0x18b;
                p->mWritePageTotal = 0;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                break;
            default:
                goto fail;
        }
        p->mSectSize = 0x10000;
        p->mPageSize = 0x100;
        p->mAddrWidth = 3;
        p->mProgramPage = 0x4f;
    } else if (device == 3 && (size == 0x2000 || size == 0x8000)) {
        p->mPageSize = size;
        p->mAddrWidth = 2;
    } else {
    fail:
        p->mType = 0;
        p->mTotalSize = 0;
        gAccessState.mCmd->mResult = 3;
        return;
    }
}

// Makes the worker thread run the task: sets its priority, CARDiCommon.mCurTh and CARDiCommon.mTaskFunc, sets the task
// bit of CARDiCommon.mFlag and wakes the thread.
void CARDi_SetTask(void (*task)(CARDiCommon *)) {
    CARDiCommon *p;

    p = (CARDiCommon *) (u32) &gAccessState;
    OS_SetThreadPriority(&p->mThread, p->mPriority);
    p->mCurTh = &p->mThread;
    p->mTaskFunc = task;
    p->mFlag |= 8;
    OS_WakeupThreadDirect(&p->mThread);
}

// Takes the lock for the owner and target, waiting while another owner holds it. Reusing an owner with a different
// target ends in OS_Terminate.
void CARDi_LockResource(u32 owner, u32 target) {
    CARDiCommon *p;
    u32 enabled;

    p = (CARDiCommon *) (u32) &gAccessState;
    enabled = OS_DisableInterrupts();
    if (p->mLockOwner == owner) {
        if (p->mLockTarget != target) {
            OS_Terminate();
        }
    } else {
        while (p->mLockOwner != -3) {
            OS_SleepThread(&p->mLockQueue);
        }
        p->mLockOwner = owner;
        p->mLockTarget = target;
    }
    p->mLockRef++;
    p->mCmd->mResult = 0;
    OS_RestoreInterrupts(enabled);
}

// Gives the lock back. At a count of 0 the owner becomes -3 and the waiting threads wake up. A wrong owner or target
// ends in OS_Terminate.
void CARDi_UnlockResource(u32 owner, u32 target) {
    CARDiCommon *p;
    u32 enabled;

    p = &gAccessState;
    enabled = OS_DisableInterrupts();
    if (p->mLockOwner != owner || p->mLockRef == 0) {
        OS_Terminate();
    } else {
        if (p->mLockTarget != target) {
            OS_Terminate();
        }
        p->mLockRef--;
        if (p->mLockRef == 0) {
            p->mLockOwner = -3;
            p->mLockTarget = 0;
            OS_WakeupThread(&p->mLockQueue);
        }
    }
    p->mCmd->mResult = 0;
    OS_RestoreInterrupts(enabled);
}

// Sets up the lock and the command block, creates the worker thread and installs the tag 11 reply callback. Enables
// card access unless the halfword at 0x027ffc40 is 2.
void CARDi_InitCommon(void) {
    CARDiCommon *p;

    p = &gAccessState;
    p->mLockOwner = -3;
    p->mLockRef = 0;
    p->mLockTarget = 0;
    p->mCmd = &gRequestBlock;
    MemFillWordsByBlock_inline(&gRequestBlock, 0x40);
    DC_FlushRange(&gRequestBlock, 0x40);
    if (*(u16 *) 0x027ffc40 != 2) {
        MI_CpuCopy8((void *) 0x027ffe00, (void *) 0x027ffa80, 0x160);
    }
    p->mLockQueue.mTail = 0;
    p->mLockQueue.mHead = p->mLockQueue.mTail;
    p->mBusyQ.mTail = 0;
    p->mBusyQ.mHead = p->mBusyQ.mTail;
    p->mPriority = 4;
    OS_CreateThread(&p->mThread, CARDi_TaskThread, 0, (u8 *) &gRomBaseOffset, 0x400, p->mPriority);
    OS_WakeupThreadDirect(&p->mThread);
    PXI_SetFifoRecvCallback(11, CARDi_OnFifoRecv);
    if (*(u16 *) 0x027ffc40 != 2) {
        CARD_Enable(1);
    }
}
