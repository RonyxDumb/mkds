/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_DmaSetParams func_01ffff38
#define OS_ResetRequestIrqMask SetIF
#define MIi_GXDmaParams SDK_data_02180308
#define MIi_DMACallback SDK_data_0214cd94
#define MIi_FIFOCallback func_0214ce08
#include "MI_dma_gxcommand.h"

#include "OS_interrupt.h"
#include "OS_reset.h"
#include "code32.h"
#include "sections.h"
extern MIiGXDmaParams MIi_GXDmaParams;
extern void MIi_DMACallback(void *arg);
void MIi_FIFOCallback(void) {
    if (!MIi_GXDmaParams.length) {
        return;
    }

    u32 length = (MIi_GXDmaParams.length >= MIi_GX_LENGTH_ONCE) ? MIi_GX_LENGTH_ONCE : MIi_GXDmaParams.length;
    u32 src    = MIi_GXDmaParams.src;

    MIi_GXDmaParams.length -= length;
    MIi_GXDmaParams.src += length;

    if (!MIi_GXDmaParams.length) {
        OSi_EnterDmaCallback(MIi_GXDmaParams.dmaNo, MIi_DMACallback, NULL);
        MIi_DmaSetParams(MIi_GXDmaParams.dmaNo, src, (u32)REG_GXFIFO_ADDR, MI_CNT_SEND32_IF(length));
        (void)OS_ResetRequestIrqMask(OS_IE_GXFIFO);
    } else {
        MIi_DmaSetParams(MIi_GXDmaParams.dmaNo, src, (u32)REG_GXFIFO_ADDR, MI_CNT_SEND32(length));
        (void)OS_ResetRequestIrqMask(OS_IE_GXFIFO);
    }
}
