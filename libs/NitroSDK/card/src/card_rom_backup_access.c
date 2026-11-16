#include "card_rom_backup_access.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "memory_protection.h"
#include "startup_entry.h"
#include "thread_scheduler.h"
#include "bios_calls.h"
#include "card_enable_and_lock.h"
#include "card_fifo_receive.h"
#include "build_info_layout.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "multiboot_piece_buffers.h"
#include "interrupt_control.h"
#include "dma_copy_fill_wait.h"
#include "cpu_copy_fill.h"
#include "card_dma_copy.h"
#include "arm_fifo_messaging.h"
#include "registers.h"
#include "card_removal_handling.h"

u32 g_SomeOffsetBase;
CARDRomStat g_Card_RomContext __attribute__((aligned(32)));

// Worker thread: sleeps until CARDiCommon.mFlag has the task bit, then runs CARDiCommon.mTaskFunc.
void Card_ContextThreadMain(void *arg) {
    CARDiCommon *common;
    u32 enabled;

    common = &g_Card_Context;
    for (;;) {
        enabled = Os_DisableIrq();
        while ((common->mFlag & BACKUP_ACCESS_FLAG_TASK_PENDING) == 0) {
            common->mCurTh = &common->mThread;
            Os_Thread_Sleep(0);
        }
        Os_RestoreIrq(enabled);
        common->mTaskFunc(common);
    }
}

// Sends a request on tag 11 and waits for the reply, trying again while the result is 4. The first call sends the StructDC_SomeFn_from_thumb
// request with the address of CARDiCommon.mCmd. Returns 1 when CARDiCommandArg.mResult is 0.
int Card_Request(CARDiCommon *common, int reqType, int retryCount) {
    u32 enabled;
    s32 result;
    CARDiCommandArg *cmd;

    if (!(common->mFlag & BACKUP_ACCESS_FLAG_REQUEST_CHANNEL_READY)) {
        common->mFlag |= BACKUP_ACCESS_FLAG_REQUEST_CHANNEL_READY;
        if (Fifo_IsHandlerReady(11, 1) == 0) {
            do {
                Os_SpinWait(100);
            } while (Fifo_IsHandlerReady(11, 1) == 0);
        }
        Card_Request(common, 0, 1);
    }
    Arm_FlushRange(common->mCmd, 0x40);
    Mem_DcDrainWriteBuffer();
    do {
        common->mCommand = reqType;
        common->mFlag |= BACKUP_ACCESS_FLAG_REQUEST_PENDING;
        while (Fifo_SendWord(11, reqType, 1) < 0) {
        }
        if (reqType == 0) {
            cmd = common->mCmd;
            while (Fifo_SendWord(11, (u32) cmd, 1) < 0) {
            }
        }
        enabled = Os_DisableIrq();
        while (common->mFlag & BACKUP_ACCESS_FLAG_REQUEST_PENDING) {
            Os_Thread_Sleep(0);
        }
        Os_RestoreIrq(enabled);
        result = common->mCmd->mResult;
    } while (result == ROM_ACCESS_AGAIN && --retryCount > 0);
    return result == ROM_ACCESS_SUCCEEDED;
}

// Copies from CARDRomStat.mCacheBuf to the destination when the buffered page is the one at CARDiCommon.mSrc. Returns 1
// while CARDiCommon.mLen is not 0.
int GlobalSZ_SomeFn(CARDRomStat *romStat) {
    CARDiCommon *common;
    u32 curPage;
    u32 len;
    u32 offset;

    common = &g_Card_Context;
    curPage = common->mSrc & -0x200;
    if (curPage == romStat->mCachePage) {
        offset = common->mSrc - curPage;
        len = 0x200 - offset;
        if (len > common->mLen) {
            len = common->mLen;
        }
        Mem_CpuCopy8((u8 *) romStat->mCacheBuf + offset, (void *) common->mDst, len);
        common->mSrc += len;
        common->mDst += len;
        common->mLen -= len;
    }
    return common->mLen != 0;
}

// Waits for the card to be idle, then writes the 8 command bytes of a ROM operation, high byte first.
void Card_WriteRomOperation(u32 cmd1, u32 cmd2) {
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
void MaybeGamecardTransferSY(void) {
    CARDiCommon *common;

    common = (CARDiCommon *) (u32) &g_Card_Context;
    MIi_CardDmaCopy32(common->mDma, (void *) &reg_MI_MCD1, (void *) common->mDst, 0x200);
    Card_WriteRomOperation((common->mSrc >> 8) | 0xb7000000, common->mSrc << 24);
    reg_MI_MCCNT1 = g_Card_RomContext.mCtrl;
}

// Card DMA interrupt handler: advances one page, then starts the next page or finishes the transfer.
void CardIRQHandler(void) {
    CARDiCommon *common;
    CARDCallback callback;
    void *callbackArg;
    u32 enabled;

    Mem_DmaStop(g_Card_Context.mDma);
    g_Card_Context.mSrc += 0x200;
    g_Card_Context.mDst += 0x200;
    g_Card_Context.mLen -= 0x200;
    if (g_Card_Context.mLen == 0) {
        Os_DisableIrqHandler(0x80000);
        SetIF(0x80000);
        common = (CARDiCommon *) (u32) &g_Card_Context;
        common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
        callback = common->mCallback;
        callbackArg = common->mCallbackArg;
        enabled = Os_DisableIrq();
        common->mFlag &= ~BACKUP_ACCESS_FLAG_TRANSFER_MASK;
        Os_Thread_WakeUp(&common->mBusyQ);
        if (common->mFlag & BACKUP_ACCESS_FLAG_WAKE_WORKER) {
            Os_Thread_WakeUpDirect(&common->mThread);
        }
        Os_RestoreIrq(enabled);
        if (callback != 0) {
            callback(callbackArg);
        }
    } else {
        MaybeGamecardTransferSY();
    }
}

// Starts a ROM read by DMA when the channel, alignment, destination and length allow it and returns 1; returns 0
// otherwise. Always sets CARDRomStat.mCtrl.
int StructSZ_SomeFn(CARDRomStat *romStat) {
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

    common = &g_Card_Context;
    isAsync = 0;
    aligned = 0;
    dmaUsable = 0;
    dst = common->mDst;
    len = common->mLen;
    if ((dst & 3) == 0 && common->mDma <= ROM_CARD_LAST_DMA_CHANNEL) {
        int inMainRam;
        dtcm = GetDtcmStartAddress();
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
        enabled = Os_DisableIrq();
        IC_InvalidateRangeNoClean((void *) dst, len);
        mod = dst & 31;
        if (mod != 0) {
            dst -= mod;
            DC_SomeClean((void *) dst, 32);
            DC_SomeClean((void *) (dst + len), 32);
            len += 32;
        }
        DC_InvalidateRangeNoClean((void *) dst, len);
        Mem_DcDrainWriteBuffer();
        Os_SetIrqHandler(0x80000, CardIRQHandler);
        SetIF(0x80000);
        Os_EnableIrqHandler(0x80000);
        Os_RestoreIrq(enabled);
        MaybeGamecardTransferSY();
    }
    return isAsync;
}

// Reads 0x200-byte ROM pages with the CPU, straight into the destination when it is aligned and big enough, otherwise
// through CARDRomStat.mCacheBuf.
void Card_DefaultRomAccess(CARDRomStat *romStat) {
    CARDiCommon *common;
    u32 *dst;
    u32 *cacheBuf;
    u32 page;
    u32 pos;
    u32 ctrl;
    u32 data;

    common = &g_Card_Context;
    cacheBuf = romStat->mCacheBuf;
    for (;;) {
        page = common->mSrc & -0x200;
        if (page != common->mSrc || (((u32) (dst = (u32 *) common->mDst)) & 3) != 0 ||
            common->mLen < CARD_ROM_PAGE_SIZE) {
            dst = cacheBuf;
            romStat->mCachePage = page;
        }
        Card_WriteRomOperation((page >> 8) | 0xb7000000, page << 24);
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
            g_Card_Context.mSrc += 0x200;
            g_Card_Context.mDst += 0x200;
            g_Card_Context.mLen -= 0x200;
            if (g_Card_Context.mLen == 0) {
                return;
            }
        } else if (GlobalSZ_SomeFn(romStat) == 0) {
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

    romStat = &g_Card_RomContext;
    if (GlobalSZ_SomeFn(romStat) != 0) {
        romStat->mReadFunc(romStat);
    }
    common = (CARDiCommon *) (u32) &g_Card_Context;
    common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
    callback = common->mCallback;
    callbackArg = common->mCallbackArg;
    enabled = Os_DisableIrq();
    common->mFlag &= ~BACKUP_ACCESS_FLAG_TRANSFER_MASK;
    Os_Thread_WakeUp(&common->mBusyQ);
    if (common->mFlag & BACKUP_ACCESS_FLAG_WAKE_WORKER) {
        Os_Thread_WakeUpDirect(&common->mThread);
    }
    Os_RestoreIrq(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
}

// Starts a ROM read of the given channel, offset, destination and length. Waits for the previous transfer first and
// adds g_SomeOffsetBase to the offset. Reads by DMA when possible, otherwise on the worker thread or the calling thread.
void CARDi_ReadRom(u32 dma, u32 src, u32 dst, u32 len, CARDCallback callback, void *callbackArg, u32 isAsync) {
    CARDiCommon *common;
    CARDRomStat *romStat;
    u32 enabled;

    common = (CARDiCommon *) (u32) &g_Card_Context;
    romStat = &g_Card_RomContext;
    EnsureCardEnabled();
    enabled = Os_DisableIrq();
    while (common->mFlag & BACKUP_ACCESS_FLAG_BUSY) {
        Os_Thread_Sleep(&common->mBusyQ);
    }
    common->mFlag |= BACKUP_ACCESS_FLAG_BUSY;
    common->mCallback = callback;
    common->mCallbackArg = callbackArg;
    Os_RestoreIrq(enabled);
    common->mDma = dma;
    common->mSrc = src + g_SomeOffsetBase;
    common->mDst = dst;
    common->mLen = len;
    if (dma <= ROM_CARD_LAST_DMA_CHANNEL) {
        Mem_DmaStop(dma);
    }
    if (StructSZ_SomeFn(romStat) != 0) {
        if (isAsync == 0) {
            j_WaitForPendingCardOperation_0();
        }
    } else if (isAsync != 0) {
        Card_SetTask(CARDi_ReadRomSyncCore);
    } else {
        common->mCurTh = g_Os_ThreadInfo.mCurrentThread;
        CARDi_ReadRomSyncCore(common);
    }
}

// Sets up the card state once: clears the transfer words, Card_InitializeContext, stores the page reader in g_Card_RomContext and
// installs the pull-out callback.
void Card_Initialize(void) {
    CARDiCommon *common;

    common = &g_Card_Context;
    if (common->mFlag != 0) {
        return;
    }
    common->mFlag = BACKUP_ACCESS_FLAG_INITIALIZED;
    common->mSrc = common->mDst = common->mLen = 0;
    common->mDma = -1;
    common->mCallback = 0;
    common->mCallbackArg = 0;
    g_SomeOffsetBase = 0;
    Card_InitializeContext();
    g_Card_RomContext.mReadFunc = Card_GetRomAccessFunction();
    Card_InitializePulledOutCallback();
}

// Waits for the running transfer to end.
int j_WaitForPendingCardOperation_0(void) {
    return WaitForPendingCardOperation();
}

// Returns the CPU page reader.
CARDRomReadFunc Card_GetRomAccessFunction(void) {
    return Card_DefaultRomAccess;
}

// Task that sends the backup transfer in pieces of at most 0x100 bytes through CARDiCommon.mBackupCachePageBuf, then
// ends the transfer and calls the callback.
void Card_BackupCommandTask(CARDiCommon *common) {
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
    Os_ReferSymbol(g_StartModuleParams.mBackup);
    do {
        len = common->mLen;
        if (len > 0x100) {
            len = 0x100;
        }
        common->mCmd->mLen = len;
        if (common->mFlag & BACKUP_ACCESS_FLAG_STOP_REQUESTED) {
            common->mFlag &= ~BACKUP_ACCESS_FLAG_STOP_REQUESTED;
            common->mCmd->mResult = ROM_ACCESS_CALLED_OFF;
            break;
        }
        if (reqMode == 0) {
            DC_InvalidateRangeNoClean(common->mBackupCachePageBuf, len);
            common->mCmd->mSrc = common->mSrc;
            common->mCmd->mDst = (u32) common->mBackupCachePageBuf;
        } else {
            Mem_CpuCopy8((void *) common->mSrc, common->mBackupCachePageBuf, len);
            Arm_FlushRange(common->mBackupCachePageBuf, len);
            Mem_DcDrainWriteBuffer();
            common->mCmd->mSrc = (s32) common->mBackupCachePageBuf;
            common->mCmd->mDst = common->mDst;
        }
        if (Card_Request(common, reqType, retryCount) == 0) {
            break;
        }
        if (reqMode == 2) {
            if (Card_Request(common, 9, 1) == 0) {
                break;
            }
        } else if (reqMode == 0) {
            Mem_CpuCopy8(common->mBackupCachePageBuf, (void *) common->mDst, len);
        }
        common->mSrc += len;
        common->mDst += len;
        common->mLen -= len;
    } while (common->mLen != 0);
    callback = common->mCallback;
    callbackArg = common->mCallbackArg;
    enabled = Os_DisableIrq();
    common->mFlag &= ~BACKUP_ACCESS_FLAG_TRANSFER_MASK;
    Os_Thread_WakeUp(&common->mBusyQ);
    if (common->mFlag & BACKUP_ACCESS_FLAG_WAKE_WORKER) {
        Os_Thread_WakeUpDirect(&common->mThread);
    }
    Os_RestoreIrq(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
}

// Starts a backup transfer of the given source, destination and length. Waits for the previous transfer first. The
// game always passes isAsync 1, which queues Card_BackupCommandTask on the worker thread.
int Card_RequestStreamCommand(u32 src, u32 dst, u32 len, CARDCallback callback, void *callbackArg, u32 isAsync,
                               u32 reqType, u32 reqRetry, u32 reqMode) {
    CARDiCommon *common;
    u32 enabled;

    common = (CARDiCommon *) (u32) &g_Card_Context;
    Os_ReferSymbol(g_StartModuleParams.mBackup);
    enabled = Os_DisableIrq();
    while (common->mFlag & BACKUP_ACCESS_FLAG_BUSY) {
        Os_Thread_Sleep(&common->mBusyQ);
    }
    common->mFlag |= BACKUP_ACCESS_FLAG_BUSY;
    common->mCallback = callback;
    common->mCallbackArg = callbackArg;
    Os_RestoreIrq(enabled);
    common->mSrc = src;
    common->mDst = dst;
    common->mLen = len;
    common->mReqType = reqType;
    common->mReqRetry = reqRetry;
    common->mReqMode = reqMode;
    if (isAsync != 0) {
        Card_SetTask(Card_BackupCommandTask);
        return 1;
    }
    g_Card_Context.mCurTh = g_Os_ThreadInfo.mCurrentThread;
    Card_BackupCommandTask(common);
    return common->mCmd->mResult == ROM_ACCESS_SUCCEEDED;
}

// Sets the backup type, then reads one byte of the backup to identify it. Returns 1 when CARDiCommandArg.mResult is 0.
int MaybeInitializeBackup(s32 type) {
    CARDiCommon *common;
    CARDCallback callback;
    void *callbackArg;
    u32 enabled;

    common = &g_Card_Context;
    Os_ReferSymbol(g_StartModuleParams.mBackup);
    if (type == 0) {
        Os_Terminate();
    }
    EnsureCardEnabled();
    enabled = Os_DisableIrq();
    while (common->mFlag & BACKUP_ACCESS_FLAG_BUSY) {
        Os_Thread_Sleep(&common->mBusyQ);
    }
    common->mFlag |= BACKUP_ACCESS_FLAG_BUSY;
    common->mCallback = 0;
    common->mCallbackArg = 0;
    Os_RestoreIrq(enabled);
    CARDi_IdentifyBackupCore(type);
    g_Card_Context.mCurTh = g_Os_ThreadInfo.mCurrentThread;
    Card_Request(common, 2, 1);
    common->mCmd->mSrc = 0;
    common->mCmd->mDst = (u32) common->mBackupCachePageBuf;
    common->mCmd->mLen = 1;
    Card_Request(common, 6, 1);
    callback = common->mCallback;
    callbackArg = common->mCallbackArg;
    enabled = Os_DisableIrq();
    common->mFlag &= ~BACKUP_ACCESS_FLAG_TRANSFER_MASK;
    Os_Thread_WakeUp(&common->mBusyQ);
    if (common->mFlag & BACKUP_ACCESS_FLAG_WAKE_WORKER) {
        Os_Thread_WakeUpDirect(&common->mThread);
    }
    Os_RestoreIrq(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
    return common->mCmd->mResult == ROM_ACCESS_SUCCEEDED;
}

// Waits for the running transfer to end.
int j_WaitForPendingCardOperation(void) {
    return WaitForPendingCardOperation();
}

// Returns 1 when no transfer is running.
int CardIsNotBusy(void) {
    return Card_IsNotBusy();
}

// Fills CARDiCommandArg.mType and the device description (size, page size, address width, timings) for a backup type.
// An unsupported type clears them and stores ROM_ACCESS_UNSUPPORTED_TYPE in CARDiCommandArg.mResult.
void CARDi_IdentifyBackupCore(s32 type) {
    CARDiCommandArg *commandArg;
    u32 size;
    u32 typeLow;

    commandArg = g_Card_Context.mCmd;
    Mem_CpuFill8(&commandArg->mTotalSize, 0, 0x28);
    commandArg->mType = type;
    if (type == 0) {
        return;
    }
    size = 1 << ((type >> 8) & 0xff);
    commandArg->mTotalSize = size;
    typeLow = type & 0xff;
    if (typeLow == 1) {
        switch (size) {
            case BACKUP_DEVICE_SIZE_512B:
                commandArg->mPageSize = BACKUP_DEVICE_512B_PAGE_SIZE;
                commandArg->mAddrWidth = 1;
                commandArg->mProgramPage = BACKUP_DEVICE_PROGRAM_PAGE_COMMON;
                break;
            case BACKUP_DEVICE_SIZE_8KB:
                commandArg->mPageSize = BACKUP_DEVICE_8KB_PAGE_SIZE;
                commandArg->mAddrWidth = 2;
                commandArg->mProgramPage = BACKUP_DEVICE_PROGRAM_PAGE_COMMON;
                break;
            case BACKUP_DEVICE_SIZE_64KB:
                commandArg->mPageSize = BACKUP_DEVICE_64KB_PAGE_SIZE;
                commandArg->mAddrWidth = 2;
                commandArg->mProgramPage = BACKUP_DEVICE_64KB_PROGRAM_PAGE;
                break;
            default:
                goto fail;
        }
    } else if (typeLow == 2) {
        switch (size) {
            case BACKUP_DEVICE_SIZE_256KB:
                commandArg->mWritePage = 0x18b;
                commandArg->mWritePageTotal = 0x127f;
                commandArg->mUnk_3c = 0x127f;
                commandArg->mUnk_38 = 0x13435;
                commandArg->mUnk_34 = 0x13435;
                break;
            case BACKUP_DEVICE_SIZE_512KB:
            case BACKUP_DEVICE_SIZE_1MB:
                commandArg->mWritePage = 0x18b;
                commandArg->mWritePageTotal = 0;
                commandArg->mUnk_3c = 0x127f;
                commandArg->mUnk_38 = 0x13435;
                break;
            default:
                goto fail;
        }
        commandArg->mSectSize = BACKUP_DEVICE_LARGE_SECTOR_SIZE;
        commandArg->mPageSize = BACKUP_DEVICE_LARGE_PAGE_SIZE;
        commandArg->mAddrWidth = 3;
        commandArg->mProgramPage = BACKUP_DEVICE_PROGRAM_PAGE_COMMON;
    } else if (typeLow == 3 && (size == BACKUP_DEVICE_SIZE_8KB || size == BACKUP_DEVICE_SIZE_32KB)) {
        commandArg->mPageSize = size;
        commandArg->mAddrWidth = 2;
    } else {
    fail:
        commandArg->mType = 0;
        commandArg->mTotalSize = 0;
        g_Card_Context.mCmd->mResult = ROM_ACCESS_UNSUPPORTED_TYPE;
        return;
    }
}

// Makes the worker thread run the task: sets its priority, CARDiCommon.mCurTh and CARDiCommon.mTaskFunc, sets the task
// bit of CARDiCommon.mFlag and wakes the thread.
void Card_SetTask(void (*task)(CARDiCommon *)) {
    CARDiCommon *common;

    common = (CARDiCommon *) (u32) &g_Card_Context;
    Os_Thread_SetPriority(&common->mThread, common->mPriority);
    common->mCurTh = &common->mThread;
    common->mTaskFunc = task;
    common->mFlag |= BACKUP_ACCESS_FLAG_TASK_PENDING;
    Os_Thread_WakeUpDirect(&common->mThread);
}

// Takes the lock for the owner and target, waiting while another owner holds it. Reusing an owner with a different
// target ends in Os_Terminate.
void Card_LockResource(u32 owner, u32 target) {
    CARDiCommon *common;
    u32 enabled;

    common = (CARDiCommon *) (u32) &g_Card_Context;
    enabled = Os_DisableIrq();
    if (common->mLockOwner == owner) {
        if (common->mLockTarget != target) {
            Os_Terminate();
        }
    } else {
        while (common->mLockOwner != -3) {
            Os_Thread_Sleep(&common->mLockQueue);
        }
        common->mLockOwner = owner;
        common->mLockTarget = target;
    }
    common->mLockRef++;
    common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
    Os_RestoreIrq(enabled);
}

// Gives the lock back. At a count of 0 the owner becomes -3 and the waiting threads wake up. A wrong owner or target
// ends in Os_Terminate.
void Card_UnlockResource(u32 owner, u32 target) {
    CARDiCommon *common;
    u32 enabled;

    common = &g_Card_Context;
    enabled = Os_DisableIrq();
    if (common->mLockOwner != owner || common->mLockRef == 0) {
        Os_Terminate();
    } else {
        if (common->mLockTarget != target) {
            Os_Terminate();
        }
        common->mLockRef--;
        if (common->mLockRef == 0) {
            common->mLockOwner = -3;
            common->mLockTarget = 0;
            Os_Thread_WakeUp(&common->mLockQueue);
        }
    }
    common->mCmd->mResult = ROM_ACCESS_SUCCEEDED;
    Os_RestoreIrq(enabled);
}

// Sets up the lock and the command block, creates the worker thread and installs the tag 11 reply callback. Enables
// card access unless the halfword at 0x027ffc40 is 2.
void Card_InitializeContext(void) {
    CARDiCommon *common;

    common = &g_Card_Context;
    common->mLockOwner = -3;
    common->mLockRef = 0;
    common->mLockTarget = 0;
    common->mCmd = &g_Card_Command;
    MemFillWordsByBlock_inline(&g_Card_Command, 0x40);
    Arm_FlushRange(&g_Card_Command, 0x40);
    if (SYSTEM_WORK->mWmBootBuf.mBootType != BOOT_TYPE_MULTIBOOT) {
        Mem_CpuCopy8(&SYSTEM_WORK->mRomHeader, HW_CARD_ROM_HEADER, sizeof(SYSTEM_WORK->mRomHeader));
    }
    common->mLockQueue.mTail = 0;
    common->mLockQueue.mHead = common->mLockQueue.mTail;
    common->mBusyQ.mTail = 0;
    common->mBusyQ.mHead = common->mBusyQ.mTail;
    common->mPriority = BACKUP_TASK_THREAD_PRIORITY;
    Os_Thread_Create(&common->mThread, Card_ContextThreadMain, 0, (u8 *) &g_SomeOffsetBase, 0x400, common->mPriority);
    Os_Thread_WakeUpDirect(&common->mThread);
    Fifo_RegisterHandler(11, Card_FifoHandler);
    if (SYSTEM_WORK->mWmBootBuf.mBootType != BOOT_TYPE_MULTIBOOT) {
        Card_SetEnabled(1);
    }
}
