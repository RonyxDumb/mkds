/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define SNDi_CallAlarmHandler Sound_CallAlarmHandler
#define OS_RestoreInterrupts Os_RestoreIrq
#define PxiFifoCallback Sound_FifoHandler
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"

void PxiFifoCallback(PXIFifoTag tag, u32 data, BOOL) {
#pragma unused (tag)
    OSIntrMode oldirq = OS_DisableInterrupts();
    SNDi_CallAlarmHandler((s32)data);
    (void)OS_RestoreInterrupts(oldirq);
}
