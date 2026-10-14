/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_Terminate Os_Terminate
#include "MI_dma.h"

#include "OS_interrupt.h"
#include "OS_terminate_proc.h"
#include "code32.h"
#include "sections.h"

void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType) {
    u32 dmaCnt;
    u32 timing;
    for (int i = 0; i < 3; i++) {
        if (i == dmaNo) {
            continue;
        }

        dmaCnt = *(REGType32v *)(REG_ADDR_DMA0CNT + i * 12);

        if (!(dmaCnt & 0x80000000)) {
            continue;
        }

        timing = dmaCnt & 0x38000000;

        if (timing == dmaType
            || (timing == 0x8000000 && dmaType == MI_DMA_TIMING_H_BLANK)
            || (timing == MI_DMA_TIMING_H_BLANK && dmaType == 0x8000000)) {
            continue;
        }

        if (timing == 0x18000000
            || timing == 0x20000000
            || timing == 0x28000000
            || timing == 0x30000000
            || timing == 0x38000000
            || timing == 0x8000000
            || timing == 0x10000000) {
            OS_Terminate();
        }
    }
}
