/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ResetTxqPri FUN_06014708
#define AddTask FUN_06008a8c
#define SetParentTbttTxq FUN_0600c614

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "MA.h"
#include "TxCtrl.h"
#include "RxCtrl.h"
#include "MAC.h"
#include "WlIntr.h"
#include "Compati.h"
#include "MA.h"
#include "WlOpe.h"

#pragma thumb off
void SetParentTbttTxq(void)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;
    u32 bTask = FALSE;

    ResetTxqPri(QID_BROADCAST);
    ResetTxqPri(QID_MANCTRL);
    ResetTxqPri(QID_DATA);

    if (pTxCtrl->Txq[QID_BROADCAST].Busy) {
        if (pTxCtrl->Txq[QID_BROADCAST].pMacFrm->MacHeader.Tx.Status != 0) {
            bTask = TRUE;
        } else {
            pTxCtrl->Txq[QID_BROADCAST].Busy = 0;
        }
    }

    if (pTxCtrl->Txq[QID_MANCTRL].Busy) {
        if (pTxCtrl->Txq[QID_MANCTRL].pMacFrm->MacHeader.Tx.Status != 0) {
            bTask = TRUE;
        } else {
            pTxCtrl->Txq[QID_MANCTRL].Busy = 0;
        }
    }

    if (pTxCtrl->Txq[QID_DATA].Busy) {
        if (pTxCtrl->Txq[QID_DATA].pMacFrm->MacHeader.Tx.Status != 0) {
            bTask = TRUE;
        } else {
            pTxCtrl->Txq[QID_DATA].Busy = 0;
        }
    }

    if (bTask) {
        AddTask(TASK_CRITICAL_PRIORITY, INTR_TXEND_TASK_ID);
    }
    AddTask(TASK_CRITICAL_PRIORITY, PARENT_TBTT_TXQ_TASK_ID);
}
