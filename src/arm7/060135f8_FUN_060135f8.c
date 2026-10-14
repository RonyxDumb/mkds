/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WSetMacAdrs2 SDK_data_0600a920
#define MakePsPollFrame FUN_060135f8

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
void MakePsPollFrame(u16 aid)
{
    LPTXFRM_MAC pMFrm = wlMan->TxCtrl.Txq[QID_PSPOLL].pMacFrm;

    DbgWlPutchar(B_WL_DBG_MANCTRL, (WL_DBG_TX_PSPOLL));

    pMFrm->MacHeader.Tx.Status = 0;
    pMFrm->MacHeader.Tx.Status2 = 0;
    pMFrm->MacHeader.Tx.rsv_RetryCount = 0;
    pMFrm->MacHeader.Tx.MPDU = 28 - 6 - 2;

    pMFrm->Dot11Header.FrameCtrl.Data = FC_PSPOLL;
    pMFrm->Dot11Header.DurationID = 0xC000 | aid;
    WSetMacAdrs2(pMFrm->Dot11Header.Adrs1, wlMan->Work.BSSID, wlMan->Config.MacAdrs);
}
