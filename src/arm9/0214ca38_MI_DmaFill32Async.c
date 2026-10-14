/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define MIi_DmaSetParams_noInt func_01fffe8c
#define OS_RestoreInterrupts Os_RestoreIrq
#include "MI_dma.h"

#include "OS_interrupt.h"
#include "OS_terminate_proc.h"
#include "code32.h"
#include "sections.h"
extern void MI_WaitDma(u32 dmaNo);
extern void MIi_DmaSetParams_noInt(u32 dmaNo, u32 src, u32 dest, u32 ctrl);
void MI_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg) {
    if (!size) {
        MIi_CallCallback(callback, arg);
    } else {
        MI_WaitDma(dmaNo);

        if (callback) {
            OSi_EnterDmaCallback(dmaNo, callback, arg);
            MIi_DmaSetParams_src32(dmaNo, data, (u32)dest, MI_CNT_CLEAR32_IF(size));
        } else {
            MIi_DmaSetParams_src32(dmaNo, data, (u32)dest, MI_CNT_CLEAR32(size));
        }
    }
}
