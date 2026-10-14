/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define MI_StopDma FUN_037fb124
#include <nitro.h>

#include "../include/mi_dma.h"
    #include <nitro/itcm_begin.h>

    #include <nitro/itcm_end.h>

#pragma thumb off
void MI_StopDma (u32 dmaNo)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    vu16 * dmaCntp = &((vu16 *)REG_DMA0SAD_ADDR)[dmaNo * 6 + 5];

    MIi_ASSERT_DMANO(dmaNo);

    *dmaCntp &= ~((MI_DMA_TIMING_MASK | MI_DMA_CONTINUOUS_ON) >> 16);
    *dmaCntp &= ~(MI_DMA_ENABLE >> 16);

    {
        s32 dummy = dmaCntp[0];
    }
    {
        s32 dummy = dmaCntp[0];
    }

    if (dmaNo == MIi_DUMMY_DMA_NO) {
        vu32 * p = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
        *p = (vu32)MIi_DUMMY_SRC;
        *(p + 1) = (vu32)MIi_DUMMY_DEST;
        *(p + 2) = (vu32)MIi_DUMMY_CNT;
    }

    (void)OS_RestoreInterrupts(enabled);
}
