/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ClearQueuedPri FUN_060147a0

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
void ClearQueuedPri(u32 pri)
{
    LPTXQ pTxq = &wlMan->TxCtrl.Txq[pri];

    if (!pTxq->Busy) {
        return;
    }

    if (pTxq->pMacFrm->MacHeader.Tx.Status == 0) {
        pTxq->pFrm->MacHeader.Tx.Status = 2;
    } else {
        pTxq->pFrm->MacHeader.Tx.Status = pTxq->pMacFrm->MacHeader.Tx.Status;
    }

    (*pTxq->pEndFunc)(pTxq->pFrm, FALSE);
}
