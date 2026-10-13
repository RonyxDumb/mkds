/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_IsRunOnEmulator Os_IsEmulator
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define IsCommandAvailable Sound_IsCommandAvailable
#include "SND_alarm.h"
#include "SND_command.h"
#include "SND_work.h"
#include "OS_emulator.h"
#include "OS_system.h"
#include "OS_cache.h"
#include "PXI_fifo.h"
#include "code32.h"

BOOL IsCommandAvailable(void) {
    if (!OS_IsRunOnEmulator())
        return TRUE;

    OSIntrMode oldirq = OS_DisableInterrupts();
    // TODO use proper register names here
    // is this some kind of debug or ensata register?
    *(vu32 *)0x4FFF200 = 0x10;
    u32 resp = *(vu32 *)0x4FFF200;
    (void)OS_RestoreInterrupts(oldirq);
    return resp != 0;
}
