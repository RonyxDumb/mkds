#include "os_spinLock.h"
#include "code_0200007e.h"
#include "os_thread.h"
#include "code_0200fc8c.h"
#include "registers.h"
#include "00/Lib/DWC/code_02188720.h"

s32 gLockInitialized;

void OS_InitLock(void) {
    OSLockWord *lockWord;
    volatile u32 zero;

    if (gLockInitialized != 0) {
        return;
    }
    gLockInitialized = 1;
    SYSTEM_WORK->mLockInit.mLockFlag = 0;
    OS_LockByWord(0x7e, &SYSTEM_WORK->mLockInit, 0);
    lockWord = &SYSTEM_WORK->mLockInit;
    if (lockWord->mExtension != 0) {
        do {
            OSi_WaitByLoop();
        } while (lockWord->mExtension != 0);
    }
    SYSTEM_WORK->mLockIdFlagMain[0] = 0xffffffff;
    SYSTEM_WORK->mLockIdFlagMain[1] = 0xffff0000;
    zero = 0;
    MIi_CpuClear32(zero, &SYSTEM_WORK->mLockVramC, 0x28);
    reg_MI_EXMEMCNT |= 0x800;
    reg_MI_EXMEMCNT |= 0x80;
    OS_UnlockByWord(0x7e, &SYSTEM_WORK->mLockInit, 0);
    OS_LockByWord(0x7f, &SYSTEM_WORK->mLockInit, 0);
}

s32 OSi_DoLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    s32 lastLockFlag;

    lastLockFlag = OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, disableFiq);
    while (lastLockFlag > 0) {
        OSi_WaitByLoop();
        lastLockFlag = OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, disableFiq);
    }
    return lastLockFlag;
}

s32 OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return OSi_DoLockByWord(lockID, lockp, ctrlFuncp, 0);
}

s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    u32 lastInterrupts;

    if (lockID != lockp->mOwnerID) {
        return -2;
    }
    if (disableFiq != 0) {
        lastInterrupts = OS_DisableInterrupts_IrqAndFiq();
    } else {
        lastInterrupts = OS_DisableInterrupts();
    }
    lockp->mOwnerID = 0;
    if (ctrlFuncp != 0) {
        ctrlFuncp();
    }
    lockp->mLockFlag = 0;
    if (disableFiq != 0) {
        OS_RestoreInterrupts_IrqAndFiq(lastInterrupts);
    } else {
        OS_RestoreInterrupts(lastInterrupts);
    }
    return 0;
}

s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, 0);
}

s32 OSi_DoTryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    u32 lastInterrupts;
    s32 lastLockFlag;

    if (disableFiq != 0) {
        lastInterrupts = OS_DisableInterrupts_IrqAndFiq();
    } else {
        lastInterrupts = OS_DisableInterrupts();
    }
    lastLockFlag = MI_SwapWord(lockID, &lockp->mLockFlag);
    if (lastLockFlag == 0) {
        if (ctrlFuncp != 0) {
            ctrlFuncp();
        }
        lockp->mOwnerID = lockID;
    }
    if (disableFiq != 0) {
        OS_RestoreInterrupts_IrqAndFiq(lastInterrupts);
    } else {
        OS_RestoreInterrupts(lastInterrupts);
    }
    return lastLockFlag;
}

s32 OS_UnlockCartridge(u16 lockID) {
    return OSi_DoUnlockByWord(lockID, &SYSTEM_WORK->mLockCartridge, OSi_FreeCartridgeBus, 1);
}

s32 OS_TryLockCartridge(u16 lockID) {
    return OSi_DoTryLockByWord(lockID, &SYSTEM_WORK->mLockCartridge, OSi_AllocateCartridgeBus, 1);
}

void OSi_AllocateCartridgeBus(void) {
    reg_MI_EXMEMCNT &= ~0x80;
}

void OSi_FreeCartridgeBus(void) {
    reg_MI_EXMEMCNT |= 0x80;
}

s32 OS_LockCard(u16 lockID) {
    return OS_LockByWord(lockID, &SYSTEM_WORK->mLockCard, OSi_AllocateCardBus);
}

s32 OS_UnlockCard(u16 lockID) {
    return OS_UnlockByWord(lockID, &SYSTEM_WORK->mLockCard, OSi_FreeCardBus);
}

void OSi_AllocateCardBus(void) {
    reg_MI_EXMEMCNT &= ~0x800;
}

void OSi_FreeCardBus(void) {
    reg_MI_EXMEMCNT |= 0x800;
}

u16 OS_ReadOwnerOfLockWord(OSLockWord *lockp) {
    return lockp->mOwnerID;
}

void OSi_WaitByLoop(void) {
    OS_SpinWait(0x1000u);
}

asm s32 OS_UnLockCartridge(u16 lockID) {
    ldr r1, =OS_UnlockCartridge
    bx r1
}
// clang-format on

// clang-format off
// Takes the highest set bit out of the two words at 0x027fffb0 (first word, then the second) and returns its number:
// 0x40 plus the bit position counted from the top for the first word, 0x60 plus it for the second, or -3 when both
// words are zero.
// Hand-written asm: counts leading zeros with clz.
asm s32 OS_GetLockID(void) {
    ldr r3, =0x27fffb0
    ldr r1, [r3, #0x0]
    clz r2, r1
    cmp r2, #0x20
    movne r0, #0x40
    bne cd28_clear
    add r3, r3, #0x4
    ldr r1, [r3, #0x0]
    clz r2, r1
    cmp r2, #0x20
    ldr r0, =0xfffffffd
    bxeq lr
    mov r0, #0x60
cd28_clear:
    add r0, r0, r2
    mov r1, #0x80000000
    mov r1, r1, lsr r2
    ldr r2, [r3, #0x0]
    bic r2, r2, r1
    str r2, [r3, #0x0]
    bx lr
}
// clang-format on

// clang-format off
// Hand-written asm: sets bit lockID of the two words at 0x027fffb0 (bits 0x40 to 0x5f in the first, 0x60 and up in the
// second). It tests with pl/mi after a compare.
asm void OS_ReleaseLockID(u16 lockID) {
    ldr r3, =0x27fffb0
    cmp r0, #0x60
    addpl r3, r3, #0x4
    subpl r0, r0, #0x60
    submi r0, r0, #0x40
    mov r1, #0x80000000
    mov r1, r1, lsr r0
    ldr r2, [r3, #0x0]
    orr r2, r2, r1
    str r2, [r3, #0x0]
    bx lr
}
// clang-format on
