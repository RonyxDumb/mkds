/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MessageDeleteTx FUN_060143cc
#define ReleaseHeapBuf FUN_060090b4
#define DeleteAllTxFrames FUN_06014464

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
extern void MessageDeleteTx(u32 pri, u32 bMsg);
#pragma thumb off
void DeleteAllTxFrames(void)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;

    switch (wlMan->Work.Mode) {
    case WL_CMDLABEL_MODE_PARENT:
        MessageDeleteTx(0, TRUE);
        MessageDeleteTx(1, FALSE);
        MessageDeleteTx(2, TRUE);
        if (pTxCtrl->Mp.Busy) {
            DbgPrint("Release MPEndInd\r\n");
            pTxCtrl->Mp.Busy = 0;
            pTxCtrl->Mp.InCount--;

            ReleaseHeapBuf(&wlMan->HeapMan.TmpBuf, pTxCtrl->pMpEndInd);
        }
        break;

    case WL_CMDLABEL_MODE_CHILD:
    case WL_CMDLABEL_MODE_HOTSPOT:
        MessageDeleteTx(0, TRUE);
        MessageDeleteTx(1, FALSE);
        MessageDeleteTx(2, FALSE);
        break;

    default:
        MessageDeleteTx(0, FALSE);
        MessageDeleteTx(1, FALSE);
        MessageDeleteTx(2, FALSE);
        break;
    }
}
