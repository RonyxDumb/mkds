#include "os_irqHandler.h"
#include "code_0200c914.h"
#include "os_thread.h"
#include "code_0200fc8c.h"
#include "code_0200007e.h"

// Optionally clears the bits irqFlags of the IRQ check flag, then sleeps the thread until one of them is set.
void OS_WaitIrq(u32 clear, u32 irqFlags) {
    u32 enabled;
    DtcmData *dtcm;
    u32 *pendingFlags;

    enabled = OS_DisableInterrupts();
    dtcm = HW_DTCM;
    if (clear != 0) {
        dtcm->mIrqCheckFlags &= ~irqFlags;
    }
    OS_RestoreInterrupts(enabled);
    dtcm = HW_DTCM;
    if ((irqFlags & dtcm->mIrqCheckFlags) != 0) {
        return;
    }
    pendingFlags = &dtcm->mIrqCheckFlags;
    do {
        OS_SleepThread(&gDtcmData.mIrqThreadQueue);
    } while ((irqFlags & *pendingFlags) == 0);
}
