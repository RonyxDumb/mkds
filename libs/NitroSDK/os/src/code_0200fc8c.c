#include "code_0200fc8c.h"

#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0214d5b8.h"

u16 OSi_IsResetOccurred;
u16 OSi_IsInitReset;

// Copies the 6-byte MAC address from the fixed system block into macAddress.
void OS_GetMacAddress(void *macAddress) {
    MI_CpuCopy8(SYSTEM_WORK->mNvramUserInfo.mMacAddress, macAddress, 6);
}

// Fills info from the owner data block in the system area.
void OS_GetOwnerInfo(OwnerInfo *info) {
    NvramUserInfo *source;

    source = &SYSTEM_WORK->mNvramUserInfo;
    info->mLanguage = (u32) (source->mOption << 29) >> 29;
    info->mFavoriteColor = (u32) (source->mFavoriteColor << 28) >> 28;
    info->mBirthdayMonth = source->mBirthdayMonth;
    info->mBirthdayDay = source->mBirthdayDay;
    info->mNickNameLength = source->mNickNameLength;
    info->mCommentLength = source->mCommentLength;
    MIi_CpuCopy16(source->mNickName, info->mNickName, 0x14);
    MIi_CpuCopy16(source->mComment, info->mComment, 0x34);
}

// Opens the reset channel once and installs OSi_CommonCallback on it.
void OS_InitReset(void) {
    if (OSi_IsInitReset != 0) {
        return;
    }
    OSi_IsInitReset = 1;
    PXI_Init();
    while (PXI_IsCallbackReady(0xc, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(0xc, OSi_CommonCallback);
}

// Handles reset-channel commands: command 0x10 sets the flag, any other command terminates.
void OSi_CommonCallback(u32 tag, u32 data) {
    if (((data & 0x7f00) << 8) >> 16 == 0x10) {
        OSi_IsResetOccurred = 1;
        return;
    }
    OS_Terminate();
}

// Disables interrupts and halts forever.
void OS_Terminate(void) {
    while (1) {
        OS_DisableInterrupts();
        OS_Halt();
    }
}

// clang-format off
// Clears the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_EnableInterrupts(void) {
    mrs r0, cpsr
    bic r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Sets the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_DisableInterrupts(void) {
    mrs r0, cpsr
    orr r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Replaces the interrupt disable bit (0x80) of the status register with the one in r0 and returns the previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_RestoreInterrupts(OSIntrMode state) {
    mrs r1, cpsr
    bic r2, r1, #0x80
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0x80
    bx lr
}

// Sets the bits 0xc0 of the status register and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_DisableInterrupts_IrqAndFiq(void) {
    mrs r0, cpsr
    orr r1, r0, #0xc0
    msr cpsr_c, r1
    and r0, r0, #0xc0
    bx lr
}

// Replaces the bits 0xc0 of the status register with those in r0 and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state) {
    mrs r1, cpsr
    bic r2, r1, #0xc0
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0xc0
    bx lr
}

// Returns the low five bits of the status register.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 OS_GetProcMode(void) {
    mrs r0, cpsr
    and r0, r0, #0x1f
    bx lr
}

// Writes zero to a coprocessor 15 register.
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void OS_Halt(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}

// Subtracts 4 from r0 until a subtraction borrows (a wait of about r0 / 4 loops).
// Kept as asm: `subs` followed by a carry test (bhs).
asm void OS_SpinWait(u32 cycle) {
loop:
    subs r0, r0, #0x4
    bhs loop
    bx lr
}
// clang-format on
