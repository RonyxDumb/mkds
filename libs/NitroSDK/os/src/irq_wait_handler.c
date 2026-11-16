#include "irq_wait_handler.h"
#include "interrupt_control.h"
#include "thread_scheduler.h"
#include "reset_interrupts_halt.h"
#include "bios_calls.h"

// The start of the data TCM up to the interrupt check word.
typedef struct IrqCheckView {
    u8 mPad[0x3ff8];
    u32 mCheckFlags;
} IrqCheckView;

// Optionally clears the bits irqFlags of the IRQ check flag, then sleeps the thread until one of them is set.
void WaitForIRQ(u32 clear, u32 irqFlags) {
    u32 enabled;
    IrqCheckView *dtcm;
    u32 *pendingFlags;

    enabled = Os_DisableIrq();
    dtcm = (IrqCheckView *) HW_DTCM;
    if (clear != 0) {
        dtcm->mCheckFlags &= ~irqFlags;
    }
    Os_RestoreIrq(enabled);
    dtcm = (IrqCheckView *) HW_DTCM;
    if ((irqFlags & dtcm->mCheckFlags) != 0) {
        return;
    }
    pendingFlags = &dtcm->mCheckFlags;
    do {
        Os_Thread_Sleep(&g_DTCM);
    } while ((irqFlags & *pendingFlags) == 0);
}
