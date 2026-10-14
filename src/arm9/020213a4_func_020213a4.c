/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define sReserveListEnd SDK_data_021732d4
#define sReserveList SDK_data_021732d0
#define SND_PushCommand func_020213a4
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"
extern struct SNDCommand *sReserveListEnd;
extern struct SNDCommand *sReserveList;
void SND_PushCommand(struct SNDCommand *cmd) {
    OSIntrMode oldirq = OS_DisableInterrupts();

    struct SNDCommand *newend = cmd;
    if (sReserveListEnd == NULL) {
        sReserveList = cmd;
        sReserveListEnd = cmd;
    } else {
        sReserveListEnd->llNext = cmd;
        sReserveListEnd = cmd;
    }

    cmd->llNext = NULL;

    (void)OS_RestoreInterrupts(oldirq);
}
