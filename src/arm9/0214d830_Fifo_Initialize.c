/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_ResetRequestIrqMask SetIF
#define OS_SetIrqFunction Os_SetIrqHandler
#define OS_EnableIrqMask Os_EnableIrqHandler
#define OS_RestoreInterrupts Os_RestoreIrq
#define FifoCtrlInit SDK_data_02180328
#define FifoRecvCallbackTable SDK_data_0218032c
#define PXIi_HandlerRecvFifoNotEmpty SDK_data_0214d5c4
#define PXI_InitFifo Fifo_Initialize
#include "consts.h"
#include "OS_interrupt.h"
#include "OS_system.h"
#include "PXI_fifo.h"
#include "systemWork.h"
#include "code32.h"
extern u16 FifoCtrlInit;
extern PXIFifoCallback FifoRecvCallbackTable[PXI_MAX_FIFO_TAG];
extern void PXIi_HandlerRecvFifoNotEmpty(void);
void PXI_InitFifo(void)
{
    OSSystemWork *p = OS_GetSystemWork();
    OSIntrMode enabled = OS_DisableInterrupts();
    s32 i;

    if (!FifoCtrlInit)
    {
        FifoCtrlInit = TRUE;

        p->pxiHandleChecker[PXI_PROC_ARM9] = 0UL;

        for (i = 0; i < PXI_MAX_FIFO_TAG; i++)
        {
            FifoRecvCallbackTable[i] = NULL;
        }

        reg_PXI_SUBP_FIFO_CNT = (REG_PXI_SUBP_FIFO_CNT_SEND_CL_MASK
                                 | REG_PXI_SUBP_FIFO_CNT_RECV_RI_MASK | REG_PXI_SUBP_FIFO_CNT_E_MASK | REG_PXI_SUBP_FIFO_CNT_ERR_MASK);

        (void)OS_ResetRequestIrqMask(OS_IE_SPFIFO_RECV);
        (void)OS_SetIrqFunction(OS_IE_SPFIFO_RECV, PXIi_HandlerRecvFifoNotEmpty);
        (void)OS_EnableIrqMask(OS_IE_SPFIFO_RECV);

        {
            s32 timeout;
            s32 c;

            for (i = 0; ; i++)
            {
                c = reg_PXI_SUBPINTF & 15;
                reg_PXI_SUBPINTF = (u16)(c << 8);

                if (c == 0 && i > 4)
                {
                    break;
                }

                for (timeout = 1000; (reg_PXI_SUBPINTF & 15) == c; timeout--)
                {
                    if (timeout == 0)
                    {
                        i = 0;
                        break;
                    }
                }
            }
        }
    }
    (void)OS_RestoreInterrupts(enabled);
}
