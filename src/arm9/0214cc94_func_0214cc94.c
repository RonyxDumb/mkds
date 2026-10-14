/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_GXDmaParams SDK_data_02180308
#define MIi_DMAFastCallback func_0214cc94
#include "MI_dma_gxcommand.h"

#include "OS_interrupt.h"
#include "OS_reset.h"
#include "code32.h"
#include "sections.h"
extern MIiGXDmaParams MIi_GXDmaParams;
void MIi_DMAFastCallback(void *arg) {
#pragma unused(arg)
    MIi_GXDmaParams.isBusy = FALSE;

    MIi_CallCallback(MIi_GXDmaParams.callback, MIi_GXDmaParams.arg);
}
