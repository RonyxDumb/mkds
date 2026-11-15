#include "code_021458c4.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0200f328.h"
#include "code_02000b44.h"
#include "os_thread.h"
#include "code_0200007e.h"
#include "card_common.h"
#include "card_request.h"
#include "unk_02000000.h"
#include "Main/Net/data_0216f000.h"
#include "mb_data.h"
#include "code_0200c914.h"
#include "code_0214c778.h"
#include "code_0214d018.h"
#include "mi_dma_card.h"
#include "code_0214d5b8.h"
#include "registers.h"
#include "card_pullOut.h"

u32 gRomBaseOffset;
CARDRomStat gRomReadState __attribute__((aligned(32)));

// Worker thread: sleeps until CARDiCommon.mFlag has the task bit, then runs CARDiCommon.mTaskFunc.
void CARDi_TaskThread(void *arg) {
    CARDiCommon *common;
    u32 enabled;

    common = &gAccessState;
    for (;;) {
        enabled = OS_DisableInterrupts();
        while ((common->mFlag & 8) == 0) {
            common->mCurTh = &common->mThread;
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(enabled);
        common->mTaskFunc(common);
    }
}

// Sends a request on tag 11 and waits for the reply, trying again while the result is 4. The first call sends the init
// request with the address of CARDiCommon.mCmd. Returns 1 when CARDiCommandArg.mResult is 0.
int CARDi_Request(CARDiCommon *common, int reqType, int retryCount) {
    u32 enabled;
    s32 result;
    CARDiCommandArg *cmd;

    if (!(common->mFlag & 2)) {
        common->mFlag |= 2;
        if (PXI_IsCallbackReady(11, 1) == 0) {
            do {
                OS_SpinWait(100);
            } while (PXI_IsCallbackReady(11, 1) == 0);
        }
        CARDi_Request(common, 0, 1);
    }
    DC_FlushRange(common->mCmd, 0x40);
    DC_WaitWriteBufferEmpty();
    do {
        common->mCommand = reqType;
        common->mFlag |= 0x20;
        while (PXI_SendWordByFifo(11, reqType, 1) < 0) {
        }
        if (reqType == 0) {
            cmd = common->mCmd;
            while (PXI_SendWordByFifo(11, (u32) cmd, 1) < 0) {
            }
        }
        enabled = OS_DisableInterrupts();
        while (common->mFlag & 0x20) {
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(enabled);
        result = common->mCmd->mResult;
    } while (result == ROM_ACCESS_AGAIN && --retryCount > 0);
    return result == ROM_ACCESS_SUCCEEDED;
}

// Copies from CARDRomStat.mCacheBuf to the destination when the buffered page is the one at CARDiCommon.mSrc. Returns 1
// while CARDiCommon.mLen is not 0.
int CARDi_ReadFromCache(CARDRomStat *romStat) {
    CARDiCommon *common;
    u32 curPage;
    u32 len;
    u32 offset;

    common = &gAccessState;
    curPage = common->mSrc & -0x200;
    if (curPage == romStat->mCachePage) {
        offset = common->mSrc - curPage;
        len = 0x200 - offset;
        if (len > common->mLen) {
            len = common->mLen;
        }
        MI_CpuCopy8((u8 *) romStat->mCacheBuf + offset, (void *) common->mDst, len);
        common->mSrc += len;
        common->mDst += len;
        common->mLen -= len;
    }
    return common->mLen != 0;
}

// Waits for the card to be idle, then writes the 8 command bytes of a ROM operation, high byte first.
void CARDi_SetRomOp(u32 cmd1, u32 cmd2) {
    while (reg_MI_MCCNT1 & 0x80000000) {
    }
    reg_MI_MCCNT0_HI = 0xc0;
    reg_MI_MCCMD0 = cmd1 >> 24;
    reg_MI_MCCMD1 = cmd1 >> 16;
    reg_MI_MCCMD2 = cmd1 >> 8;
    reg_MI_MCCMD3 = cmd1;
    reg_MI_MCCMD4 = cmd2 >> 24;
    reg_MI_MCCMD5 = cmd2 >> 16;
    reg_MI_MCCMD6 = cmd2 >> 8;
    reg_MI_MCCMD7 = cmd2;
}

// Starts a DMA of one ROM page into CARDiCommon.mDst and the read command for CARDiCommon.mSrc.
void CARDi_SetCardDma(void) {
    CARDiCommon *common;

    common = (CARDiCommon *) (u32) &gAccessState;
    MIi_CardDmaCopy32(common->mDma, (void *) &reg_MI_MCD1, (void *) common->mDst, 0x200);
    CARDi_SetRomOp((common->mSrc >> 8) | 0xb7000000, common->mSrc << 24);
    reg_MI_MCCNT1 = gRomReadState.mCtrl;
}

// Card DMA interrupt handler: advances one page, then starts the next page or finishes the transfer.
void CARDi_OnReadCard(void) {
    CARDiCommon *common;
    CARDCallback callback;
    void *callbackArg;
    u32 enabled;

    MI_StopDma(gAccessState.mDma);
    gAccessState.mSrc += 0x200;
    gAccessState.mDst += 0x200;
    gAccessState.mLen -= 0x200;
    if (gAccessState.mLen == 0) {
        OS_DisableIrqMask(0x80000);
        OS_ResetRequestIrqMask(0x80000);
        common = (CARDiCommon *) (u32) &gAccessState;
        common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
        callback = common->mCallback;
        callbackArg = common->mCallbackArg;
        enabled = OS_DisableInterrupts();
        common->mFlag &= ~0x4c;
        OS_WakeupThread(&common->mBusyQ);
        if (common->mFlag & 0x10) {
            OS_WakeupThreadDirect(&common->mThread);
        }
        OS_RestoreInterrupts(enabled);
        if (callback != 0) {
            callback(callbackArg);
        }
    } else {
        CARDi_SetCardDma();
    }
}

// Starts a ROM read by DMA when the channel, alignment, destination and length allow it and returns 1; returns 0
// otherwise. Always sets CARDRomStat.mCtrl.
int CARDi_TryReadCardDma(CARDRomStat *romStat) {
    u32 dtcm;
    int inTcm;
    CARDiCommon *common;
    u32 dst;
    u32 len;
    int isAsync;
    int aligned;
    int dmaUsable;
    u32 end;
    u32 enabled;
    u32 mod;

    common = &gAccessState;
    isAsync = 0;
    aligned = 0;
    dmaUsable = 0;
    dst = common->mDst;
    len = common->mLen;
    if ((dst & 3) == 0 && common->mDma <= 3) {
        int inMainRam;
        dtcm = OS_GetDTCMAddress();
        end = dst + len;
        inTcm = 1;
        inMainRam = 0;
        if (end > 0x01ff8000) {
            if (dst < 0x02000000) {
                inMainRam = 1;
            } else {
                inMainRam = 0;
            }
        }
        if (inMainRam == 0) {
            if (dtcm >= end || dtcm + 0x4000 <= dst) {
                inTcm = 0;
            }
        }
        if (inTcm == 0) {
            dmaUsable = 1;
        }
    }
    if (dmaUsable != 0) {
        if (((common->mSrc | len) & 0x1ff) == 0) {
            aligned = 1;
        }
    }
    if (aligned != 0 && len != 0) {
        isAsync = 1;
    }
    romStat->mCtrl = (SYSTEM_WORK->mRomHeader.mRomCtrl & ~0x07000000) | 0xa1000000;
    if (isAsync != 0) {
        enabled = OS_DisableInterrupts();
        IC_InvalidateRange((void *) dst, len);
        mod = dst & 31;
        if (mod != 0) {
            dst -= mod;
            DC_StoreRange((void *) dst, 32);
            DC_StoreRange((void *) (dst + len), 32);
            len += 32;
        }
        DC_InvalidateRange((void *) dst, len);
        DC_WaitWriteBufferEmpty();
        OS_SetIrqFunction(0x80000, CARDi_OnReadCard);
        OS_ResetRequestIrqMask(0x80000);
        OS_EnableIrqMask(0x80000);
        OS_RestoreInterrupts(enabled);
        CARDi_SetCardDma();
    }
    return isAsync;
}

// Reads 0x200-byte ROM pages with the CPU, straight into the destination when it is aligned and big enough, otherwise
// through CARDRomStat.mCacheBuf.
void CARDi_ReadCard(CARDRomStat *romStat) {
    CARDiCommon *common;
    u32 *dst;
    u32 *cacheBuf;
    u32 page;
    u32 pos;
    u32 ctrl;
    u32 data;

    common = &gAccessState;
    cacheBuf = romStat->mCacheBuf;
    for (;;) {
        page = common->mSrc & -0x200;
        if (page != common->mSrc || (((u32) (dst = (u32 *) common->mDst)) & 3) != 0 || common->mLen < 0x200) {
            dst = cacheBuf;
            romStat->mCachePage = page;
        }
        CARDi_SetRomOp((page >> 8) | 0xb7000000, page << 24);
        reg_MI_MCCNT1 = romStat->mCtrl;
        pos = 0;
        do {
            ctrl = reg_MI_MCCNT1;
            if (ctrl & 0x800000) {
                data = reg_MI_MCD1;
                if (pos < 0x200) {
                    dst[pos] = data;
                    pos++;
                }
            }
        } while (ctrl & 0x80000000);
        if ((u32) dst == common->mDst) {
            gAccessState.mSrc += 0x200;
            gAccessState.mDst += 0x200;
            gAccessState.mLen -= 0x200;
            if (gAccessState.mLen == 0) {
                return;
            }
        } else if (CARDi_ReadFromCache(romStat) == 0) {
            return;
        }
    }
}

// Task for a ROM read the DMA path did not take: reads the rest through CARDRomStat.mReadFunc, then ends the transfer
// and calls the callback.
void CARDi_ReadRomSyncCore(CARDiCommon *taskCommon) {
    CARDiCommon *common;
    CARDRomStat *romStat;
    CARDCallback callback;
    void *callbackArg;
    u32 enabled;

    romStat = &gRomReadState;
    if (CARDi_ReadFromCache(romStat) != 0) {
        romStat->mReadFunc(romStat);
    }
    common = (CARDiCommon *) (u32) &gAccessState;
    common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
    callback = common->mCallback;
    callbackArg = common->mCallbackArg;
    enabled = OS_DisableInterrupts();
    common->mFlag &= ~0x4c;
    OS_WakeupThread(&common->mBusyQ);
    if (common->mFlag & 0x10) {
        OS_WakeupThreadDirect(&common->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
}

// Starts a ROM read of the given channel, offset, destination and length. Waits for the previous transfer first and
// adds gRomBaseOffset to the offset. Reads by DMA when possible, otherwise on the worker thread or the calling thread.
void CARDi_ReadRom(u32 dma, u32 src, u32 dst, u32 len, CARDCallback callback, void *callbackArg, u32 isAsync) {
    CARDiCommon *common;
    CARDRomStat *romStat;
    u32 enabled;

    common = (CARDiCommon *) (u32) &gAccessState;
    romStat = &gRomReadState;
    CARD_CheckEnabled();
    enabled = OS_DisableInterrupts();
    while (common->mFlag & 4) {
        OS_SleepThread(&common->mBusyQ);
    }
    common->mFlag |= 4;
    common->mCallback = callback;
    common->mCallbackArg = callbackArg;
    OS_RestoreInterrupts(enabled);
    common->mDma = dma;
    common->mSrc = src + gRomBaseOffset;
    common->mDst = dst;
    common->mLen = len;
    if (dma <= 3) {
        MI_StopDma(dma);
    }
    if (CARDi_TryReadCardDma(romStat) != 0) {
        if (isAsync == 0) {
            CARD_WaitRomAsync();
        }
    } else if (isAsync != 0) {
        CARDi_SetTask(CARDi_ReadRomSyncCore);
    } else {
        common->mCurTh = OSi_ThreadInfo.mCurrentThread;
        CARDi_ReadRomSyncCore(common);
    }
}

// Sets up the card state once: clears the transfer words, CARDi_InitCommon, stores the page reader in gRomReadState and
// installs the pull-out callback.
void CARD_Init(void) {
    CARDiCommon *common;

    common = &gAccessState;
    if (common->mFlag != 0) {
        return;
    }
    common->mFlag = 1;
    common->mSrc = common->mDst = common->mLen = 0;
    common->mDma = -1;
    common->mCallback = 0;
    common->mCallbackArg = 0;
    gRomBaseOffset = 0;
    CARDi_InitCommon();
    gRomReadState.mReadFunc = CARDi_GetRomAccessor();
    CARD_InitPulledOutCallback();
}

// Waits for the running transfer to end.
int CARD_WaitRomAsync(void) {
    return CARDi_WaitAsync();
}

// Returns the CPU page reader.
CARDRomReadFunc CARDi_GetRomAccessor(void) {
    return CARDi_ReadCard;
}

// Task that sends the backup transfer in pieces of at most 0x100 bytes through CARDiCommon.mBackupCachePageBuf, then
// ends the transfer and calls the callback.
void CARDi_RequestStreamCommandCore(CARDiCommon *common) {
    u32 reqType;
    u32 reqMode;
    u32 retryCount;
    u32 len;
    u32 *buf;
    CARDCallback callback;
    void *callbackArg;
    u32 enabled;

    reqType = common->mReqType;
    reqMode = common->mReqMode;
    retryCount = common->mReqRetry;
    OSi_ReferSymbol((u32) BuildInfo.mBackup);
    do {
        len = common->mLen;
        if (len > 0x100) {
            len = 0x100;
        }
        common->mCmd->mLen = len;
        if (common->mFlag & 0x40) {
            common->mFlag &= ~0x40;
            common->mCmd->mResult = ROM_ACCESS_CALLED_OFF;
            break;
        }
        if (reqMode == 0) {
            DC_InvalidateRange(common->mBackupCachePageBuf, len);
            common->mCmd->mSrc = common->mSrc;
            common->mCmd->mDst = (u32) common->mBackupCachePageBuf;
        } else {
            MI_CpuCopy8((void *) common->mSrc, common->mBackupCachePageBuf, len);
            DC_FlushRange(common->mBackupCachePageBuf, len);
            DC_WaitWriteBufferEmpty();
            common->mCmd->mSrc = (s32) common->mBackupCachePageBuf;
            common->mCmd->mDst = common->mDst;
        }
        if (CARDi_Request(common, reqType, retryCount) == 0) {
            break;
        }
        if (reqMode == 2) {
            if (CARDi_Request(common, 9, 1) == 0) {
                break;
            }
        } else if (reqMode == 0) {
            MI_CpuCopy8(common->mBackupCachePageBuf, (void *) common->mDst, len);
        }
        common->mSrc += len;
        common->mDst += len;
        common->mLen -= len;
    } while (common->mLen != 0);
    callback = common->mCallback;
    callbackArg = common->mCallbackArg;
    enabled = OS_DisableInterrupts();
    common->mFlag &= ~0x4c;
    OS_WakeupThread(&common->mBusyQ);
    if (common->mFlag & 0x10) {
        OS_WakeupThreadDirect(&common->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
}

// Starts a backup transfer of the given source, destination and length. Waits for the previous transfer first. The
// game always passes isAsync 1, which queues CARDi_RequestStreamCommandCore on the worker thread.
int CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, CARDCallback callback, void *callbackArg, u32 isAsync,
                               u32 reqType, u32 reqRetry, u32 reqMode) {
    CARDiCommon *common;
    u32 enabled;

    common = (CARDiCommon *) (u32) &gAccessState;
    OSi_ReferSymbol((u32) BuildInfo.mBackup);
    enabled = OS_DisableInterrupts();
    while (common->mFlag & 4) {
        OS_SleepThread(&common->mBusyQ);
    }
    common->mFlag |= 4;
    common->mCallback = callback;
    common->mCallbackArg = callbackArg;
    OS_RestoreInterrupts(enabled);
    common->mSrc = src;
    common->mDst = dst;
    common->mLen = len;
    common->mReqType = reqType;
    common->mReqRetry = reqRetry;
    common->mReqMode = reqMode;
    if (isAsync != 0) {
        CARDi_SetTask(CARDi_RequestStreamCommandCore);
        return 1;
    }
    gAccessState.mCurTh = OSi_ThreadInfo.mCurrentThread;
    CARDi_RequestStreamCommandCore(common);
    return common->mCmd->mResult == ROM_ACCESS_SUCCEEDED;
}

// Sets the backup type, then reads one byte of the backup to identify it. Returns 1 when CARDiCommandArg.mResult is 0.
int CARD_IdentifyBackup(s32 type) {
    CARDiCommon *common;
    CARDCallback callback;
    void *callbackArg;
    u32 enabled;

    common = &gAccessState;
    OSi_ReferSymbol((u32) BuildInfo.mBackup);
    if (type == 0) {
        OS_Terminate();
    }
    CARD_CheckEnabled();
    enabled = OS_DisableInterrupts();
    while (common->mFlag & 4) {
        OS_SleepThread(&common->mBusyQ);
    }
    common->mFlag |= 4;
    common->mCallback = 0;
    common->mCallbackArg = 0;
    OS_RestoreInterrupts(enabled);
    CARDi_IdentifyBackupCore(type);
    gAccessState.mCurTh = OSi_ThreadInfo.mCurrentThread;
    CARDi_Request(common, 2, 1);
    common->mCmd->mSrc = 0;
    common->mCmd->mDst = (u32) common->mBackupCachePageBuf;
    common->mCmd->mLen = 1;
    CARDi_Request(common, 6, 1);
    callback = common->mCallback;
    callbackArg = common->mCallbackArg;
    enabled = OS_DisableInterrupts();
    common->mFlag &= ~0x4c;
    OS_WakeupThread(&common->mBusyQ);
    if (common->mFlag & 0x10) {
        OS_WakeupThreadDirect(&common->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
    return common->mCmd->mResult == ROM_ACCESS_SUCCEEDED;
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
// An unsupported type clears them and stores ROM_ACCESS_UNSUPPORTED_TYPE in CARDiCommandArg.mResult.
void CARDi_IdentifyBackupCore(s32 type) {
    CARDiCommandArg *commandArg;
    u32 size;
    u32 typeLow;

    commandArg = gAccessState.mCmd;
    MI_CpuFill8(&commandArg->mTotalSize, 0, 0x28);
    commandArg->mType = type;
    if (type == 0) {
        return;
    }
    size = 1 << ((type >> 8) & 0xff);
    commandArg->mTotalSize = size;
    typeLow = type & 0xff;
    if (typeLow == 1) {
        switch (size) {
            case 0x200:
                commandArg->mPageSize = BACKUP_DEVICE_512B_PAGE_SIZE;
                commandArg->mAddrWidth = 1;
                commandArg->mProgramPage = BACKUP_DEVICE_PROGRAM_PAGE_COMMON;
                break;
            case 0x2000:
                commandArg->mPageSize = BACKUP_DEVICE_8KB_PAGE_SIZE;
                commandArg->mAddrWidth = 2;
                commandArg->mProgramPage = BACKUP_DEVICE_PROGRAM_PAGE_COMMON;
                break;
            case 0x10000:
                commandArg->mPageSize = BACKUP_DEVICE_64KB_PAGE_SIZE;
                commandArg->mAddrWidth = 2;
                commandArg->mProgramPage = BACKUP_DEVICE_64KB_PROGRAM_PAGE;
                break;
            default:
                goto fail;
        }
    } else if (typeLow == 2) {
        switch (size) {
            case 0x40000:
                commandArg->mWritePage = 0x18b;
                commandArg->mWritePageTotal = 0x127f;
                commandArg->mUnk_3c = 0x127f;
                commandArg->mUnk_38 = 0x13435;
                commandArg->mUnk_34 = 0x13435;
                break;
            case 0x80000:
            case 0x100000:
                commandArg->mWritePage = 0x18b;
                commandArg->mWritePageTotal = 0;
                commandArg->mUnk_3c = 0x127f;
                commandArg->mUnk_38 = 0x13435;
                break;
            default:
                goto fail;
        }
        commandArg->mSectSize = 0x10000;
        commandArg->mPageSize = BACKUP_DEVICE_LARGE_PAGE_SIZE;
        commandArg->mAddrWidth = 3;
        commandArg->mProgramPage = BACKUP_DEVICE_PROGRAM_PAGE_COMMON;
    } else if (typeLow == 3 && (size == 0x2000 || size == 0x8000)) {
        commandArg->mPageSize = size;
        commandArg->mAddrWidth = 2;
    } else {
    fail:
        commandArg->mType = 0;
        commandArg->mTotalSize = 0;
        gAccessState.mCmd->mResult = ROM_ACCESS_UNSUPPORTED_TYPE;
        return;
    }
}

// Makes the worker thread run the task: sets its priority, CARDiCommon.mCurTh and CARDiCommon.mTaskFunc, sets the task
// bit of CARDiCommon.mFlag and wakes the thread.
void CARDi_SetTask(void (*task)(CARDiCommon *)) {
    CARDiCommon *common;

    common = (CARDiCommon *) (u32) &gAccessState;
    OS_SetThreadPriority(&common->mThread, common->mPriority);
    common->mCurTh = &common->mThread;
    common->mTaskFunc = task;
    common->mFlag |= 8;
    OS_WakeupThreadDirect(&common->mThread);
}

// Takes the lock for the owner and target, waiting while another owner holds it. Reusing an owner with a different
// target ends in OS_Terminate.
void CARDi_LockResource(u32 owner, u32 target) {
    CARDiCommon *common;
    u32 enabled;

    common = (CARDiCommon *) (u32) &gAccessState;
    enabled = OS_DisableInterrupts();
    if (common->mLockOwner == owner) {
        if (common->mLockTarget != target) {
            OS_Terminate();
        }
    } else {
        while (common->mLockOwner != -3) {
            OS_SleepThread(&common->mLockQueue);
        }
        common->mLockOwner = owner;
        common->mLockTarget = target;
    }
    common->mLockRef++;
    common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
    OS_RestoreInterrupts(enabled);
}

// Gives the lock back. At a count of 0 the owner becomes -3 and the waiting threads wake up. A wrong owner or target
// ends in OS_Terminate.
void CARDi_UnlockResource(u32 owner, u32 target) {
    CARDiCommon *common;
    u32 enabled;

    common = &gAccessState;
    enabled = OS_DisableInterrupts();
    if (common->mLockOwner != owner || common->mLockRef == 0) {
        OS_Terminate();
    } else {
        if (common->mLockTarget != target) {
            OS_Terminate();
        }
        common->mLockRef--;
        if (common->mLockRef == 0) {
            common->mLockOwner = -3;
            common->mLockTarget = 0;
            OS_WakeupThread(&common->mLockQueue);
        }
    }
    common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
    OS_RestoreInterrupts(enabled);
}

// Sets up the lock and the command block, creates the worker thread and installs the tag 11 reply callback. Enables
// card access unless the halfword at 0x027ffc40 is 2.
void CARDi_InitCommon(void) {
    CARDiCommon *common;

    common = &gAccessState;
    common->mLockOwner = -3;
    common->mLockRef = 0;
    common->mLockTarget = 0;
    common->mCmd = &gRequestBlock;
    MemFillWordsByBlock_inline(&gRequestBlock, 0x40);
    DC_FlushRange(&gRequestBlock, 0x40);
    if (SYSTEM_WORK->mWmBootBuf.mBootType != BOOT_TYPE_MULTIBOOT) {
        MI_CpuCopy8(&SYSTEM_WORK->mRomHeader, HW_CARD_ROM_HEADER, sizeof(SYSTEM_WORK->mRomHeader));
    }
    common->mLockQueue.mTail = 0;
    common->mLockQueue.mHead = common->mLockQueue.mTail;
    common->mBusyQ.mTail = 0;
    common->mBusyQ.mHead = common->mBusyQ.mTail;
    common->mPriority = 4;
    OS_CreateThread(&common->mThread, CARDi_TaskThread, 0, (u8 *) &gRomBaseOffset, 0x400, common->mPriority);
    OS_WakeupThreadDirect(&common->mThread);
    PXI_SetFifoRecvCallback(11, CARDi_OnFifoRecv);
    if (SYSTEM_WORK->mWmBootBuf.mBootType != BOOT_TYPE_MULTIBOOT) {
        CARD_Enable(1);
    }
}
