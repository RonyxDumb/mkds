/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CAM_IncFrameCount FUN_0600ecf4
#define MoveHeapBuf FUN_06009040
#define TxqPri FUN_0601536c
#define MA_TestDataReqCmd FUN_0601262c
#include "nitro/os/common/interrupt.h"

#include "WlSys.h"

#include "WlLib.h"
#include "MAC.h"
#include "MA.h"
#include "WlOpe.h"

#pragma thumb off
u16 MA_TestDataReqCmd(WlCmdReq *pReqt, WlCmdCfm *pCfmt)
{
    WlMaDataReq *pReq = (WlMaDataReq *)pReqt;
    LPTXFRM pFrm;

    pCfmt->header.length = 1;

    pReqt->header.code = CONTINUOUS_DATA_MODE;

    pFrm = (LPTXFRM)&pReq->frame;

    pFrm->FirmHeader.CamAdrs = 0;

    pFrm->MacHeader.Tx.MPDU = pFrm->FirmHeader.Length;

    CAM_IncFrameCount(pFrm);
    MoveHeapBuf(&wlMan->HeapMan.RequestCmd, &wlMan->HeapMan.TxPri[QID_DATA], pReq);
    TxqPri(QID_DATA);

    return WL_CMDRES_SUCCESS;
}
