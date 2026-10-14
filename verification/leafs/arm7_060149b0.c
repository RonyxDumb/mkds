/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define TxEndKeyData FUN_060149b0

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
void TxEndKeyData(LPTXQ pTxq)
{
    u32 retrycnt = LoadLow(&pTxq->pMacFrm->MacHeader.Tx.rsv_RetryCount);
    WlCounter *pCounter = &wlMan->Counter;

    if (retrycnt == 0) {
        DbgWlPutchar(B_WL_DBG_MP, (WL_DBG_TX_MP_NULL));
        pCounter->multiPoll.txNull++;
    } else {
        DbgWlPutchar(B_WL_DBG_MP, (WL_DBG_TX_MP_KEY));
        pCounter->multiPoll.txKey += retrycnt;
    }

    pTxq->OutCount++;

    pTxq->Busy = FALSE;
}
