/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define MI_WaitDma FUN_037fb1a8
#include <nitro.h>

#include "../include/mi_dma.h"
    #include <nitro/itcm_begin.h>

    #include <nitro/itcm_end.h>

#pragma thumb off
void MI_WaitDma (u32 dmaNo)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    vu32 * dmaCntp = &((vu32 *)REG_DMA0SAD_ADDR)[dmaNo * 3 + 2];

    MIi_ASSERT_DMANO(dmaNo);
    while (*dmaCntp & REG_MI_DMA0CNT_E_MASK) {
    }

    if (dmaNo == MIi_DUMMY_DMA_NO) {
        vu32 * p = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
        *p = (vu32)MIi_DUMMY_SRC;
        *(p + 1) = (vu32)MIi_DUMMY_DEST;
        *(p + 2) = (vu32)MIi_DUMMY_CNT;
    }

    (void)OS_RestoreInterrupts(enabled);
}
