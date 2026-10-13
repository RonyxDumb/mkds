/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define MIi_DmaSetParams func_01ffff38
#include "MI_dma.h"

#include "OS_interrupt.h"
#include "OS_terminate_proc.h"
#include "code32.h"
#include "sections.h"

void MIi_DmaSetParams(u32 dmaNo, u32 src, u32 dest, u32 ctrl) {
    OSIntrMode lastIntrMode = OS_DisableInterrupts();
    vu32 *p                 = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
    *p                      = (vu32)src;
    *(p + 1)                = (vu32)dest;
    *(p + 2)                = (vu32)ctrl;
    (void)OS_RestoreInterrupts(lastIntrMode);
}
