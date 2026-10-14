/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#include "MI_dma.h"

#include "OS_interrupt.h"
#include "OS_terminate_proc.h"
#include "code32.h"
#include "sections.h"

void MI_WaitDma(u32 dmaNo) {
    OSIntrMode lastIntrMode = OS_DisableInterrupts();
    vu32 *dmaCntp;
    MIi_WAIT_BEFOREDMA(dmaCntp, dmaNo);

    if (!dmaNo) {
        vu32 *p  = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
        *p       = (vu32)0;
        *(p + 1) = (vu32)0;
        *(p + 2) = (vu32)0x81400001;
    }

    (void)OS_RestoreInterrupts(lastIntrMode);
}
