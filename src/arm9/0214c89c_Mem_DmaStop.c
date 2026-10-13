/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define MI_StopDma Mem_DmaStop
#include "MI_dma.h"

#include "OS_interrupt.h"
#include "OS_terminate_proc.h"
#include "code32.h"
#include "sections.h"

void MI_StopDma(u32 dmaNo) {
    OSIntrMode lastIntrMode = OS_DisableInterrupts();
    vu16 *dmaCntp           = &((vu16 *)REG_DMA0SAD_ADDR)[dmaNo * 6 + 5];

    *dmaCntp &= ~0x3a00;
    *dmaCntp &= ~0x8000;

    // delay cycles
    {
        s32 delay = dmaCntp[0];
    }
    {
        s32 delay = dmaCntp[0];
    }

    if (!dmaNo) {
        vu32 *p  = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
        *p       = (vu32)0;
        *(p + 1) = (vu32)0;
        *(p + 2) = (vu32)0x81400001;
    }

    (void)OS_RestoreInterrupts(lastIntrMode);
}
