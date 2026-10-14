/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define MIi_DmaSetParams_wait_noInt func_01fffe2c
#define OS_RestoreInterrupts Os_RestoreIrq
#define MI_DmaFill32 Mem_DmaFill32
#include "MI_dma.h"

#include "OS_interrupt.h"
#include "OS_terminate_proc.h"
#include "code32.h"
#include "sections.h"
extern void MIi_DmaSetParams_wait_noInt(u32 dmaNo, u32 src, u32 dest, u32 ctrl);
void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size) {
    vu32 *dmaCntp;
    if (!size) {
        return;
    }

    MIi_WAIT_BEFOREDMA(dmaCntp, dmaNo);

    MIi_DmaSetParams_wait_src32(dmaNo, data, (u32)dest, MI_CNT_CLEAR32(size));

    do {
        while (*dmaCntp & 0x80000000) {}
    } while (0);
}
