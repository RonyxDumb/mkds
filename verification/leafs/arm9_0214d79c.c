/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PXI_IsCallbackReady Fifo_IsHandlerReady
#include "consts.h"
#include "OS_interrupt.h"
#include "OS_system.h"
#include "PXI_fifo.h"
#include "systemWork.h"
#include "code32.h"

BOOL PXI_IsCallbackReady(s32 fifotag, PXIProc proc)
{
    OSSystemWork *p = OS_GetSystemWork();

    return (p->pxiHandleChecker[proc] & (1UL << fifotag)) ? TRUE : FALSE;
}
