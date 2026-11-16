#include "lock_word_and_bus_ownership.h"
#include "bios_calls.h"
#include "thread_scheduler.h"
#include "reset_interrupts_halt.h"
#include "registers.h"
#include "00/Lib/DWC/access_point_manager.h"

s32 g_Os_LockInitialized;

void Os_InitializeLock(void) {
    OSLockWord *lockWord;
    volatile u32 zero;

    if (g_Os_LockInitialized != 0) {
        return;
    }
    g_Os_LockInitialized = 1;
    SYSTEM_WORK->mLockInit.mLockFlag = 0;
    Os_Lock_TryLock(0x7e, &SYSTEM_WORK->mLockInit, 0);
    lockWord = &SYSTEM_WORK->mLockInit;
    if (lockWord->mExtension != 0) {
        do {
            Os_Lock_Wait();
        } while (lockWord->mExtension != 0);
    }
    SYSTEM_WORK->mLockIdFlagMain[0] = 0xffffffff;
    SYSTEM_WORK->mLockIdFlagMain[1] = 0xffff0000;
    zero = 0;
    MIi_CpuClear32(zero, &SYSTEM_WORK->mLockVramC, 0x28);
    reg_MI_EXMEMCNT |= 0x800;
    reg_MI_EXMEMCNT |= 0x80;
    Os_Lock_Unlock(0x7e, &SYSTEM_WORK->mLockInit, 0);
    Os_Lock_TryLock(0x7f, &SYSTEM_WORK->mLockInit, 0);
}

s32 Os_Lock_TryLockImpl(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    s32 previousFlag;

    previousFlag = Os_Lock_HandleTryLock(lockID, lockp, ctrlFuncp, disableFiq);
    while (previousFlag > 0) {
        Os_Lock_Wait();
        previousFlag = Os_Lock_HandleTryLock(lockID, lockp, ctrlFuncp, disableFiq);
    }
    return previousFlag;
}

s32 Os_Lock_TryLock(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return Os_Lock_TryLockImpl(lockID, lockp, ctrlFuncp, 0);
}

s32 Os_Lock_UnlockImpl(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    u32 savedIrqState;

    if (lockID != lockp->mOwnerID) {
        return -2;
    }
    if (disableFiq != 0) {
        savedIrqState = Os_DisableIrqFiq();
    } else {
        savedIrqState = Os_DisableIrq();
    }
    lockp->mOwnerID = 0;
    if (ctrlFuncp != 0) {
        ctrlFuncp();
    }
    lockp->mLockFlag = 0;
    if (disableFiq != 0) {
        Os_RestoreIrqFiq(savedIrqState);
    } else {
        Os_RestoreIrq(savedIrqState);
    }
    return 0;
}

s32 Os_Lock_Unlock(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void)) {
    return Os_Lock_UnlockImpl(lockID, lockp, ctrlFuncp, 0);
}

s32 Os_Lock_HandleTryLock(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq) {
    u32 savedIrqState;
    s32 previousFlag;

    if (disableFiq != 0) {
        savedIrqState = Os_DisableIrqFiq();
    } else {
        savedIrqState = Os_DisableIrq();
    }
    previousFlag = Mem_Swap16(lockID, &lockp->mLockFlag);
    if (previousFlag == 0) {
        if (ctrlFuncp != 0) {
            ctrlFuncp();
        }
        lockp->mOwnerID = lockID;
    }
    if (disableFiq != 0) {
        Os_RestoreIrqFiq(savedIrqState);
    } else {
        Os_RestoreIrq(savedIrqState);
    }
    return previousFlag;
}

s32 Operation_CartArm7(u16 lockID) {
    return Os_Lock_UnlockImpl(lockID, &SYSTEM_WORK->mLockCartridge, SetCartOwnerArm7, 1);
}

s32 Operation_CartArm9(u16 lockID) {
    return Os_Lock_HandleTryLock(lockID, &SYSTEM_WORK->mLockCartridge, SetCartOwnerArm9, 1);
}

void SetCartOwnerArm9(void) {
    reg_MI_EXMEMCNT &= ~0x80;
}

void SetCartOwnerArm7(void) {
    reg_MI_EXMEMCNT |= 0x80;
}

s32 Os_TryLockCard(u16 lockID) {
    return Os_Lock_TryLock(lockID, &SYSTEM_WORK->mLockCard, SetCardOwnerArm9);
}

s32 Os_UnlockCard(u16 lockID) {
    return Os_Lock_Unlock(lockID, &SYSTEM_WORK->mLockCard, SetCardOwnerArm7);
}

void SetCardOwnerArm9(void) {
    reg_MI_EXMEMCNT &= ~0x800;
}

void SetCardOwnerArm7(void) {
    reg_MI_EXMEMCNT |= 0x800;
}

u16 Os_Lock_GetOwnerId(OSLockWord *lockp) {
    return lockp->mOwnerID;
}

void Os_Lock_Wait(void) {
    Os_SpinWait(0x1000u);
}

asm s32 j_Operation_CartArm7(u16 lockID) {
    ldr r1, =Operation_CartArm7
    bx r1
}
// clang-format on

// clang-format off
// Takes the highest set bit out of the two words at 0x027fffb0 (first word, then the second) and returns its number:
// 0x40 plus the bit position counted from the top for the first word, 0x60 plus it for the second, or -3 when both
// words are zero.
// Kept as asm: counts leading zeros with clz.
asm s32 Os_AllocateLockId(void) {
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
// Kept as asm: sets bit lockID of the two words at 0x027fffb0 (bits 0x40 to 0x5f in the first, 0x60 and up in the
// second). It tests with pl/mi after a compare.
asm void Os_ReleaseLockId(u16 lockID) {
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
