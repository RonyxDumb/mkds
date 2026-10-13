/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define sFinishedTag SDK_data_021732cc
#define SND_IsFinishedCommandTag func_020210c0
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"
extern u32 sFinishedTag;
BOOL SND_IsFinishedCommandTag(u32 tag) {
    OSIntrMode oldirq = OS_DisableInterrupts();

    BOOL result;
    if (tag > sFinishedTag) {
        if (tag - sFinishedTag < 0x80000000)
            result = FALSE;
        else
            result = TRUE;
    } else {
        if (sFinishedTag - tag < 0x80000000)
            result = TRUE;
        else
            result = FALSE;
    }

    (void)OS_RestoreInterrupts(oldirq);
    return result;
}
