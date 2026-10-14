/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WlIntrRxEndTask FUN_0600dc28
#define WDisableTmpttPowerSave FUN_0600ac28
#define SendMessageToWmDirect FUN_0600f19c
#define WlIntrMpEndTask FUN_0600db3c

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
#include "WlIntrTask.h"
#include "WlOpe.h"
extern void WlIntrRxEndTask(void);
#pragma thumb off
void WlIntrMpEndTask(void)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;
    u32 cnt;

    if (pTxCtrl->Mp.Busy == 0) {
        return;
    }

    if (pTxCtrl->pMpEndInd->mpKey.bitmap != pTxCtrl->Mp.pMacFrm->MacHeader.Tx.Status2) {
        WlIntrRxEndTask();
    }

    cnt = LoadLow(&pTxCtrl->Mp.pMacFrm->MacHeader.Tx.rsv_RetryCount);
    if (cnt) {
        wlMan->Counter.multiPoll.txMp += cnt;
    } else {
        wlMan->Counter.multiPoll.txMp++;
    }

    pTxCtrl->Mp.OutCount++;

    pTxCtrl->pMpEndInd->mpKey.errBitmap = pTxCtrl->pMpEndInd->mpKey.bitmap ^ pTxCtrl->Mp.pMacFrm->MacHeader.Tx.Status2;

    pTxCtrl->RestBitmap = pTxCtrl->pMpEndInd->mpKey.bitmap;

    pTxCtrl->Mp.Busy = FALSE;

    if (wlMan->Work.TmpttPs) {
        WDisableTmpttPowerSave();
    }

    SendMessageToWmDirect(&wlMan->HeapMan.TmpBuf, pTxCtrl->pMpEndInd);
}
