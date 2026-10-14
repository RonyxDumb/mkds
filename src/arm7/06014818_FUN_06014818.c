/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define ClearQueuedPri FUN_060147a0
#define MessageDeleteTx FUN_060143cc
#define OS_EnableIrqMask thunk_FUN_037f888c
#define ClearTxData FUN_06014818

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "TxCtrl.h"
#include "MAC.h"
#include "CAM.h"
#include "MA.h"
#include "Compati.h"
#include "WlOpe.h"
#include "WlIntrTask.h"
extern void ClearQueuedPri(u32 pri);
extern void MessageDeleteTx(u32 pri, u32 bMsg);
#pragma thumb off
void ClearTxData(void)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;
    u32 x;

    x = OS_DisableIrqMask(OS_IE_WIRELESS);

    switch (wlMan->Work.Mode) {
    case WL_CMDLABEL_MODE_PARENT:
        *(vu16 *)MREG_TXQ_RESET = TXQ_RST_TXQ0 | TXQ_RST_TXQ2;

        if (pTxCtrl->Txq[QID_BROADCAST].Busy) {
            ClearQueuedPri(QID_BROADCAST);
        }

        MessageDeleteTx(QID_BROADCAST, TRUE);
        break;

    default:
        *(vu16 *)MREG_TXQ_RESET = TXQ_RST_TXQ0;
        break;
    }

    if (pTxCtrl->Txq[QID_DATA].Busy) {
        ClearQueuedPri(QID_DATA);
    }

    MessageDeleteTx(QID_DATA, TRUE);

    OS_EnableIrqMask(x);
}
