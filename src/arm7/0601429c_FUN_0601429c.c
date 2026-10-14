/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WCalcManRate FUN_0600a450
#define TxPsPollFrame FUN_0601429c

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

#pragma thumb off
void TxPsPollFrame(void)
{
    LPTXQ pTxq = &wlMan->TxCtrl.Txq[QID_PSPOLL];

    pTxq->InCount++;
    DbgSetDDO(DDO_WL_PSPOLL, DDO_WL_PSPOLL_BUSY);

    if (pTxq->Busy) {
        pTxq->pMacFrm->MacHeader.Tx.rsv_RetryCount = 0;
    } else {
        pTxq->Busy = TRUE;

        pTxq->pMacFrm->MacHeader.Tx.Status = 0;
        pTxq->pMacFrm->MacHeader.Tx.rsv_RetryCount = 0;
        pTxq->pMacFrm->MacHeader.Tx.Service_Rate = WCalcManRate();

        *(vu16 *)(MREG_TXQ + QID_PSPOLL * 4) = TXQ_ENABLE | (u16)SetMacTxAdrs(pTxq->pMacFrm);
    }
}
