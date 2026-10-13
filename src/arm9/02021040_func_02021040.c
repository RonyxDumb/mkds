/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define sFreeList SDK_data_021732d0
#define SND_CountFreeCommand func_02021040
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"
extern struct SNDCommand *sFreeList;
s32 SND_CountFreeCommand(void) {
    OSIntrMode oldirq = OS_DisableInterrupts();
    
    s32 count = 0;
    for (struct SNDCommand *cmd = sFreeList; cmd != NULL; cmd = cmd->llNext)
        count++;

    (void)OS_RestoreInterrupts(oldirq);
    return count;
}
