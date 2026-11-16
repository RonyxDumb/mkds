#include "reset_interrupts_halt.h"

#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "arm_fifo_messaging.h"

u16 g_GotReset;
u16 g_ResetFifoHandlerInit;

// Copies the 6-byte MAC address from the fixed system block into macAddress.
void Os_GetMacAddress(void *macAddress) {
    Mem_CpuCopy8(SYSTEM_WORK->mNvramUserInfo.mMacAddress, macAddress, 6);
}

// Fills info from the owner data block in the system area.
void Os_GetPersonalData(OwnerInfo *info) {
    NvramUserInfo *source;

    source = &SYSTEM_WORK->mNvramUserInfo;
    info->mLanguage = (u32) (source->mOption << 29) >> 29;
    info->mFavoriteColor = (u32) (source->mFavoriteColor << 28) >> 28;
    info->mBirthdayMonth = source->mBirthdayMonth;
    info->mBirthdayDay = source->mBirthdayDay;
    info->mNickNameLength = source->mNickNameLength;
    info->mCommentLength = source->mCommentLength;
    CopyMemory16(source->mNickName, info->mNickName, 0x14);
    CopyMemory16(source->mComment, info->mComment, 0x34);
}

// Opens the reset channel once and installs Os_FifoResetHandler on it.
void Os_InitializeResetFifoHandler(void) {
    if (g_ResetFifoHandlerInit != 0) {
        return;
    }
    g_ResetFifoHandlerInit = 1;
    j_Fifo_Initialize();
    while (Fifo_IsHandlerReady(0xc, 1) == 0) {
    }
    Fifo_RegisterHandler(0xc, Os_FifoResetHandler);
}

// Handles reset-channel commands: command 0x10 sets the flag, any other command terminates.
void Os_FifoResetHandler(u32 tag, u32 data) {
    if (((data & 0x7f00) << 8) >> 16 == 0x10) {
        g_GotReset = 1;
        return;
    }
    Os_Terminate();
}

// Disables interrupts and halts forever.
void Os_Terminate(void) {
    while (1) {
        Os_DisableIrq();
        Os_Halt();
    }
}

// clang-format off
// Clears the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode Os_EnableIrq(void) {
    mrs r0, cpsr
    bic r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Sets the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode Os_DisableIrq(void) {
    mrs r0, cpsr
    orr r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Replaces the interrupt disable bit (0x80) of the status register with the one in r0 and returns the previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode Os_RestoreIrq(OSIntrMode state) {
    mrs r1, cpsr
    bic r2, r1, #0x80
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0x80
    bx lr
}

// Sets the bits 0xc0 of the status register and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode Os_DisableIrqFiq(void) {
    mrs r0, cpsr
    orr r1, r0, #0xc0
    msr cpsr_c, r1
    and r0, r0, #0xc0
    bx lr
}

// Replaces the bits 0xc0 of the status register with those in r0 and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode Os_RestoreIrqFiq(OSIntrMode state) {
    mrs r1, cpsr
    bic r2, r1, #0xc0
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0xc0
    bx lr
}

// Returns the low five bits of the status register.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 Arm_GetProcessorMode(void) {
    mrs r0, cpsr
    and r0, r0, #0x1f
    bx lr
}

// Writes zero to a coprocessor 15 register.
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void Os_Halt(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}

// Subtracts 4 from r0 until a subtraction borrows (a wait of about r0 / 4 loops).
// Kept as asm: `subs` followed by a carry test (bhs).
asm void Os_SpinWait(u32 cycle) {
loop:
    subs r0, r0, #0x4
    bhs loop
    bx lr
}
// clang-format on
