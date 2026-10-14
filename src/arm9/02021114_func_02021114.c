/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define sReserveList SDK_data_021732d0
#define sFinishedTag SDK_data_021732cc
#define sCurrentTag SDK_data_021732e8
#define SND_GetCurrentCommandTag func_02021114
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"
extern struct SNDCommand *sReserveList;
extern u32 sFinishedTag;
extern u32 sCurrentTag;
u32 SND_GetCurrentCommandTag(void) {
    OSIntrMode oldirq = OS_DisableInterrupts();

    u32 retval;
    if (sReserveList == NULL)
        retval = sFinishedTag;
    else
        retval = sCurrentTag;

    (void)OS_RestoreInterrupts(oldirq);
    return retval;
}
