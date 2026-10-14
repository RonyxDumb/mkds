/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CAM_Search FUN_0600ef30
#define CAM_IncFrameCount FUN_0600ecf4
#define MoveHeapBuf FUN_06009040
#define SetManCtrlFrame FUN_06014338

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
void SetManCtrlFrame(LPTXFRM pFrm)
{
    pFrm->FirmHeader.CamAdrs = CAM_Search(pFrm->Dot11Header.Adrs1);
    if (pFrm->FirmHeader.CamAdrs == CAM_NOT_FOUND) {
        pFrm->FirmHeader.CamAdrs = 0;
    }

    pFrm->FirmHeader.FrameTime = wlMan->Work.IntervalCount;

    if (pFrm->Dot11Header.FrameCtrl.Data & B_FC_WEP) {
        pFrm->MacHeader.Tx.MPDU += 8;
    }

    CAM_IncFrameCount(pFrm);
    MoveHeapBuf(&wlMan->HeapMan.TmpBuf, &wlMan->HeapMan.TxPri[QID_MANCTRL], CalcReqAdrsFromFrame(pFrm));
}
