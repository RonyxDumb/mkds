/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_Terminate Os_Terminate
#define OSi_IsResetOccurred SDK_data_02170280
#define OSi_CommonCallback Os_FifoResetHandler
#include "OS_reset.h"

#include "nitro/types.h"
#include "MB_mb.h"
#include "OS_terminate_proc.h"
#include "OS_interrupt.h"
#include "OS_system.h"
#include "OS_spinLock.h"
#include "OS_cache.h"
#include "sections.h"
#include "MI_dma.h"
#include "CARD_common.h"
#include "PXI_init.h"
#include "PXI_fifo.h"
#include "code32.h"
extern vu16 OSi_IsResetOccurred;
void OSi_CommonCallback(PXIFifoTag tag, u32 data, BOOL err) {
#pragma unused(tag, err) //needed because otherwise -W all errors
    u16 command = (u16)((data & OS_PXI_COMMAND_MASK) >> OS_PXI_COMMAND_SHIFT);
    if (command == OS_PXI_COMMAND_RESET)
    {
        OSi_IsResetOccurred = TRUE;
        return;
    }
    OS_Terminate();
}
