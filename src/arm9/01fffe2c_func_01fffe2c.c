/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_DmaSetParams_wait_noInt func_01fffe2c
#include "MI_dma.h"

#include "OS_interrupt.h"
#include "OS_terminate_proc.h"
#include "code32.h"
#include "sections.h"

void MIi_DmaSetParams_wait_noInt(u32 dmaNo, u32 src, u32 dest, u32 ctrl) {
    vu32 *p  = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
    *p       = (vu32)src;
    *(p + 1) = (vu32)dest;
    *(p + 2) = (vu32)ctrl;

    // delay cycles
    {
        u32 delay = reg_MI_DMA0SAD;
    }
    {
        u32 delay = reg_MI_DMA0SAD;
    }

    if (!dmaNo) {
        *p       = (vu32)0;
        *(p + 1) = (vu32)0;
        *(p + 2) = (vu32)0x81400001;
    }

    // delay cycles
    {
        u32 delay = reg_MI_DMA0SAD;
    }
    {
        u32 delay = reg_MI_DMA0SAD;
    }
}
