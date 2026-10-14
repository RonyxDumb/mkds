/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define FifoRecvCallbackTable SDK_data_0218032c
#define PXI_SetFifoRecvCallback Fifo_RegisterHandler
#include "consts.h"
#include "OS_interrupt.h"
#include "OS_system.h"
#include "PXI_fifo.h"
#include "systemWork.h"
#include "code32.h"
extern PXIFifoCallback FifoRecvCallbackTable[PXI_MAX_FIFO_TAG];
void PXI_SetFifoRecvCallback(s32 fifotag, PXIFifoCallback callback)
{
    OSSystemWork *p = OS_GetSystemWork();
    OSIntrMode enabled = OS_DisableInterrupts();

    FifoRecvCallbackTable[fifotag] = callback;
    if (callback)
    {
        p->pxiHandleChecker[PXI_PROC_ARM9] |= (1UL << fifotag);
    }
    else
    {
        p->pxiHandleChecker[PXI_PROC_ARM9] &= ~(1UL << fifotag);
    }
    (void)OS_RestoreInterrupts(enabled);
}
