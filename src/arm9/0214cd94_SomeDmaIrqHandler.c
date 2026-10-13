/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask Os_DisableIrqHandler
#define OS_SetIrqFunction Os_SetIrqHandler
#define MIi_GXDmaParams SDK_data_02180308
#define MIi_DMACallback SomeDmaIrqHandler
#include "MI_dma_gxcommand.h"

#include "OS_interrupt.h"
#include "OS_reset.h"
#include "code32.h"
#include "sections.h"
extern MIiGXDmaParams MIi_GXDmaParams;
void MIi_DMACallback(void *arg) {
#pragma unused(arg)
    (void)OS_DisableIrqMask(OS_IE_GXFIFO);

    G3X_SetFifoIntrCond(MIi_GXDmaParams.fifoCond);
    OS_SetIrqFunction(OS_IE_GXFIFO, MIi_GXDmaParams.fifoFunc);

    MIi_GXDmaParams.isBusy = FALSE;

    MIi_CallCallback(MIi_GXDmaParams.callback, MIi_GXDmaParams.arg);
}
