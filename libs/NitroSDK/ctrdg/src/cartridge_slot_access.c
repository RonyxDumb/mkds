#include "cartridge_slot_access.h"
#include "interrupt_control.h"
#include "lock_word_and_bus_ownership.h"
#include "thread_scheduler.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "arm_fifo_messaging.h"
#include "bios_calls.h"
#include "cartridge_pxi_send.h"
#include "dma_copy_fill_wait.h"
#include "registers.h"

#pragma thumb on

CTRDGWork gCartridgeState;
s32 gCartridgeInitStarted;
s32 gHeaderCopyStarted;
CartridgeHeaderCopy gCartridgeHeaderCopy;
s32 (*gCartridgeRemovalCallback)(void);
s32 gCartridgeUnusedWord0;
s32 gCartridgeUnusedWord1;
s32 gCartridgeUnusedWord2;

void CTRDG_Init(void) {
    if (gCartridgeInitStarted == 0) {
        gCartridgeInitStarted = 1;
        CTRDGi_InitCommon();
        PXI_Init();
        while (PXI_IsCallbackReady(13, 1) == 0) {
        }
        PXI_SetFifoRecvCallback(13, CTRDGi_CallbackForInitModuleInfo);
        CTRDGi_InitModuleInfo();
        PXI_SetFifoRecvCallback(13, 0);
        PXI_SetFifoRecvCallback(13, CTRDGi_PulledOutCallback);
        gCartridgeRemovalCallback = 0;
    }
}

// Runs once. Copies the cartridge header under the cartridge lock, fills the module info record from it, and sends the
// address of the header buffer on tag 13, then waits for the reply.
void CTRDGi_InitModuleInfo(void) {
    u32 savedIrqMask;
    u16 savedIme;
    CartridgeAccessSave procLock;
    CartridgeAccessSave savedAccessCycle;
    s32 savedBit15;
    s32 infoIndex;
    CTRDGModuleInfo *idInfo;
    CartridgeHeaderCopy *headerCopy;

    if (gHeaderCopyStarted != 0) {
        return;
    }
    gHeaderCopyStarted = 1;
    if ((reg_GX_POSTFLG & 1) == 0) {
        return;
    }
    savedIrqMask = OS_SetIrqMask(0x40000);
    savedIme = reg_OS_IME;
    reg_OS_IME = 1;
    CTRDGi_LockByProcessor(gCartridgeState.mLockId, &procLock);
    savedBit15 = (reg_MI_EXMEMCNT & 0x8000) >> 15;
    CTRDGi_ChangeLatestAccessCycle(&savedAccessCycle);
    reg_MI_EXMEMCNT = reg_MI_EXMEMCNT & ~0x8000;
    DC_InvalidateRange(OFFSET_PTR(CartridgeHeaderTail, &gCartridgeHeaderCopy, 0x80), 0x40);
    MI_DmaCopy16(1, (const void *) 0x08000080, OFFSET_PTR(CartridgeHeaderTail, &gCartridgeHeaderCopy, 0x80), 0x40);
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0x8000) | (savedBit15 << 15);
    CTRDGi_RestoreAccessCycle(&savedAccessCycle);
    CTRDGi_UnlockByProcessor(gCartridgeState.mLockId, &procLock);
    headerCopy = &gCartridgeHeaderCopy;
    idInfo = &SYSTEM_WORK->mCartridgeModuleInfo;
    idInfo->mIdHalfword = gCartridgeHeaderCopy.mHeaderTailCopy.mModuleId;
    for (infoIndex = 0; infoIndex < 3; infoIndex++) {
        idInfo->mExLsiId[infoIndex] = headerCopy->mHeaderTailCopy.mExLsiId[infoIndex];
    }
    idInfo->mMakerCode = headerCopy->mHeaderTailCopy.mMakerCode;
    idInfo->mIdWord = headerCopy->mHeaderTailCopy.mGameCode;
    MIi_CpuCopy32((void *) 0xffff0020, gCartridgeHeaderCopy.mBiosBytes, 0x9c);
    DC_FlushAll();
    CTRDGi_SendtoPxi(((((u32) &gCartridgeHeaderCopy - 0x02000000) >> 5) << 6) | 1);
    while (gCartridgeState.mReplyReceived != 1) {
        WaitByLoop(1);
    }
    reg_OS_IME;
    reg_OS_IME = savedIme;
    OS_SetIrqMask(savedIrqMask);
}

void CTRDGi_CallbackForInitModuleInfo(u32 tag, u32 data) {
    if ((data & 0x3f) == 1) {
        gCartridgeState.mReplyReceived = 1;
    } else {
        OS_Terminate();
    }
}

void CTRDGi_PulledOutCallback(u32 tag, u32 data) {
    s32 terminateNow;

    if ((data & 0x3f) == 0x11) {
        terminateNow = 0;
        if (gCartridgeRemovalCallback != 0) {
            terminateNow = gCartridgeRemovalCallback();
        }
        if (terminateNow != 0) {
            CTRDG_TerminateForPulledOut();
            return;
        }
    } else {
        OS_Terminate();
    }
}

void CTRDG_TerminateForPulledOut(void) {
    CTRDGi_SendtoPxi(2);
    OS_Terminate();
}

void CTRDGi_InitCommon(void) {
    u32 zero;

    zero = 0;
    CpuSet(&zero, &gCartridgeState, 0x05000001);
    gCartridgeState.mLockId = OS_GetLockID();
}

s32 CTRDG_IsExisting(void) {
    s32 exists;
    CartridgeAccessSave procLock;
    CartridgeAccessSave savedAccessCycle;
    CTRDGModuleInfo *idInfo;
    CTRDGHeader *cartridgeHeader;

    idInfo = &SYSTEM_WORK->mCartridgeModuleInfo;
    cartridgeHeader = (CTRDGHeader *) 0x08000000;
    exists = 1;
    if (idInfo->mIdHalfword == CARTRIDGE_NO_ID_HALFWORD) {
        return 0;
    }
    if (idInfo->mDetectPullOut == 1) {
        return 0;
    }
    CTRDGi_LockByProcessor(gCartridgeState.mLockId, &procLock);
    CTRDGi_ChangeLatestAccessCycle(&savedAccessCycle);
    if ((cartridgeHeader->mIdSelector == CARTRIDGE_ID_SELECTOR_HEADER_HALFWORD &&
         idInfo->mIdHalfword != cartridgeHeader->mIdHalfword) ||
        (cartridgeHeader->mIdSelector != CARTRIDGE_ID_SELECTOR_HEADER_HALFWORD &&
         idInfo->mIdHalfword != *(u16 *) 0x0801fffe) ||
        (idInfo->mIdWord != cartridgeHeader->mIdWord && idInfo->mIsAgbCartridge)) {
        idInfo->mDetectPullOut = 1;
        exists = 0;
    }
    CTRDGi_RestoreAccessCycle(&savedAccessCycle);
    CTRDGi_UnlockByProcessor(gCartridgeState.mLockId, &procLock);
    return exists;
}

void CTRDGi_ChangeLatestAccessCycle(CartridgeAccessSave *r) {
    r->mCycle1 = (reg_MI_EXMEMCNT & 0xc) >> 2;
    r->mCycle2 = (reg_MI_EXMEMCNT & 0x10) >> 4;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | 0xc;
    reg_MI_EXMEMCNT &= ~0x10;
}

void CTRDGi_RestoreAccessCycle(CartridgeAccessSave *r) {
    u32 cycle1;
    u32 cycle2;

    cycle1 = r->mCycle1;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0xc) | (cycle1 << 2);
    cycle2 = r->mCycle2;
    reg_MI_EXMEMCNT = (reg_MI_EXMEMCNT & ~0x10) | (cycle2 << 4);
}

void CTRDGi_LockByProcessor(u16 lockID, CartridgeAccessSave *info) {
    for (;;) {
        info->mSavedIrq = OS_DisableInterrupts();
        info->mOwnerFlag = OS_ReadOwnerOfLockWord(&SYSTEM_WORK->mLockCartridge) & 0x40;
        if (info->mOwnerFlag != 0) {
            break;
        }
        if (OS_TryLockCartridge(lockID) == 0) {
            break;
        }
        OS_RestoreInterrupts(info->mSavedIrq);
        WaitByLoop(1);
    }
}

void CTRDGi_UnlockByProcessor(u16 lockID, CartridgeAccessSave *info) {
    if (info->mOwnerFlag == 0) {
        OS_UnLockCartridge(lockID);
    }
    OS_RestoreInterrupts(info->mSavedIrq);
}
