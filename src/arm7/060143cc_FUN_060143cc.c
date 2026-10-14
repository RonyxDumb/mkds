/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetHeapBufNextAdrs FUN_06008e48
#define CAM_DecFrameCount FUN_0600ec88
#define IssueMaDataConfirm FUN_060125a8
#define MessageDeleteTx FUN_060143cc

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
void MessageDeleteTx(u32 pri, u32 bMsg)
{
    WlMaDataReq *pReq, *pNextReq;
    LPTXFRM pFrm;

    pReq = (WlMaDataReq *)GetHeapBufHeadAdrs(&wlMan->HeapMan.TxPri[pri]);
    if ((u32)pReq == HEAPBUF_HEAD_NONE) {
        return;
    }

    do {
        pNextReq = (WlMaDataReq *)GetHeapBufNextAdrs(pReq);
        pFrm = (LPTXFRM)&pReq->frame;

        if (pri != QID_BROADCAST) {
            CAM_DecFrameCount(pFrm);
        }

        pFrm->MacHeader.Tx.Status = 2;

        if (bMsg) {
            IssueMaDataConfirm(&wlMan->HeapMan.TxPri[pri], pReq);
        }

        pReq = pNextReq;

    } while ((u32)pReq != HEAPBUF_HEAD_NONE);
}
