/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_DmaSetParams func_01ffff38
#define MIi_GXDmaParams SDK_data_02180308
#define MIi_DMAFastCallback SDK_data_0214cc94
#define MI_SendGXCommandAsyncFast func_0214ccd4
#include "MI_dma_gxcommand.h"

#include "OS_interrupt.h"
#include "OS_reset.h"
#include "code32.h"
#include "sections.h"
extern MIiGXDmaParams MIi_GXDmaParams;
extern void MIi_DMAFastCallback(void *arg);
void MI_SendGXCommandAsyncFast(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg) {
    if (!commandLength) {
        MIi_CallCallback(callback, arg);
        return;
    }

    while (MIi_GXDmaParams.isBusy) {}

    MIi_GXDmaParams.isBusy   = TRUE;
    MIi_GXDmaParams.dmaNo    = dmaNo;
    MIi_GXDmaParams.callback = callback;
    MIi_GXDmaParams.arg      = arg;

    MIi_CheckAnotherAutoDMA(dmaNo, 0x38000000);

    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, commandLength, MI_DMA_SRC_INC);

    MI_WaitDma(dmaNo);

    OSi_EnterDmaCallback(dmaNo, MIi_DMAFastCallback, NULL);
    MIi_DmaSetParams(dmaNo, (u32)src, (u32)REG_GXFIFO_ADDR, MI_CNT_GXCOPY_IF(commandLength));
}
