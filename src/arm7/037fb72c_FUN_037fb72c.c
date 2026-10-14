/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_ResetRequestIrqMask FUN_037f881c
#define OS_SetIrqFunction FUN_037f8944
#define OS_EnableIrqMask FUN_037f888c
#define OS_SpinWait FUN_037fafd4
#define OS_RestoreInterrupts FUN_037faf84
#define FifoCtrlInit SDK_data_038078b8
#define FifoRecvCallbackTable SDK_data_038078bc
#define PXIi_HandlerRecvFifoNotEmpty SDK_data_037fb4d4
#define PXI_InitFifo FUN_037fb72c
#include  <nitro.h>
extern u16 FifoCtrlInit;
extern PXIFifoCallback FifoRecvCallbackTable[PXI_MAX_FIFO_TAG];
extern void PXIi_HandlerRecvFifoNotEmpty (void);
#pragma thumb off
void PXI_InitFifo (void)
{
    int i;
    OSIntrMode enabled;
    OSSystemWork * p = OS_GetSystemWork();

    enabled = OS_DisableInterrupts();

    if (!FifoCtrlInit) {
        FifoCtrlInit = TRUE;

        p->pxiHandleChecker[PXI_PROC_ARM] = 0UL;

        for (i = 0; i < PXI_MAX_FIFO_TAG; i++) {
            FifoRecvCallbackTable[i] = NULL;
        }

        reg_PXI_FIFO_CNT =
            (REG_PXI_FIFO_CNT_SEND_CL_MASK |
             REG_PXI_FIFO_CNT_RECV_RI_MASK | REG_PXI_FIFO_CNT_E_MASK | REG_PXI_FIFO_CNT_ERR_MASK);

        (void)OS_ResetRequestIrqMask(OS_IE_FIFO_RECV);
        (void)OS_SetIrqFunction(OS_IE_FIFO_RECV, PXIi_HandlerRecvFifoNotEmpty);
        (void)OS_EnableIrqMask(OS_IE_FIFO_RECV);

#ifndef SDK_FINALROM
        if (OS_IsRunOnEmulator()) {
            reg_PXI_INTF = 0x100;
        } else
#endif
#ifdef  SDK_ARM7
        {
            for (i = 8; i >= 0; i--) {
                reg_PXI_INTF = (u16)(i << 8);
                OS_SpinWait(1000);

                if ((reg_PXI_INTF & 15) != i) {
                    i = 8;
                }
            }
        }
#else
        {
            int timeout;
            s32 c;

            for (i = 0;; i++) {
                c = reg_PXI_INTF & 15;
                reg_PXI_INTF = (u16)(c << 8);

                if (c == 0 && i > 4) {
                    break;
                }

                for (timeout = 1000; (reg_PXI_INTF & 15) == c; timeout--) {
                    if (timeout == 0) {
                        i = 0;
                        break;
                    }
                }
            }
        }
#endif
    }
    (void)OS_RestoreInterrupts(enabled);
}
