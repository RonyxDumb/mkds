/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define OS_EnableIrqMask thunk_FUN_037f888c
#define Pri2QBit SDK_data_06019080
#define ResetTxqPri FUN_06014708

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
extern const u16 Pri2QBit[];
#pragma thumb off
void ResetTxqPri(u32 pri)
{
    u32 x;
    LPTXQ pTxq = &wlMan->TxCtrl.Txq[pri];

    x = OS_DisableIrqMask(OS_IE_WIRELESS);

    *(vu16 *)MREG_TXQ_RESET = Pri2QBit[pri];

    if (pTxq->Busy) {
        if ((pTxq->pFrm->Dot11Header.FrameCtrl.Data & B_FC_WEP) == 0) {
            pTxq->pFrm->MacHeader.Tx.rsv_RetryCount = pTxq->pMacFrm->MacHeader.Tx.rsv_RetryCount;
        }

        pTxq->pFrm->Dot11Header.SeqCtrl.Data = pTxq->pMacFrm->Dot11Header.SeqCtrl.Data;

        DbgClrDDO(DDO_WL_PS2, DDO_WL_PS2_TXQ0 << pri);
        DbgClrDDO(DDO_WL_MACBUG_NOTPOLL, DDO_WL_MACBUG_NOTPOLL_TXQ0 << pri);
    }

    OS_EnableIrqMask(x);
}
