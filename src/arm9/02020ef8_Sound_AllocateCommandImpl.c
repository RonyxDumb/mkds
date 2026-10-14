/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define sFreeList SDK_data_021732c8
#define sFreeListEnd SDK_data_021732d8
#define AllocCommand Sound_AllocateCommandImpl
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"
extern struct SNDCommand *sFreeList;
extern struct SNDCommand *sFreeListEnd;
struct SNDCommand *AllocCommand(void) {
    OSIntrMode oldirq = OS_DisableInterrupts();
    if (sFreeList == NULL) {
        (void)OS_RestoreInterrupts(oldirq);
        return NULL;
    }

    struct SNDCommand *retval = sFreeList;

    sFreeList = sFreeList->llNext;
    if (sFreeList == NULL)
        sFreeListEnd = NULL;
    (void)OS_RestoreInterrupts(oldirq);
    return retval;
}
