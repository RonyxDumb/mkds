/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define FifoRecvCallbackTable SDK_data_038078bc
#define PXI_SetFifoRecvCallback FUN_037fb6c0
#include  <nitro.h>
extern PXIFifoCallback FifoRecvCallbackTable[PXI_MAX_FIFO_TAG];
#pragma thumb off
void PXI_SetFifoRecvCallback (int fifotag, PXIFifoCallback callback)
{
    OSIntrMode enabled;
    OSSystemWork * p = OS_GetSystemWork();

    SDK_WARNING(callback == NULL ||
                FifoRecvCallbackTable[fifotag] == NULL ||
                FifoRecvCallbackTable[fifotag] == callback,
                "Fifo Callback overridden [fifotag=%d]\n", fifotag);

    enabled = OS_DisableInterrupts();

    FifoRecvCallbackTable[fifotag] = callback;
    if (callback) {
        p->pxiHandleChecker[PXI_PROC_ARM] |= (1UL << fifotag);
    } else {
        p->pxiHandleChecker[PXI_PROC_ARM] &= ~(1UL << fifotag);
    }
    (void)OS_RestoreInterrupts(enabled);
}
