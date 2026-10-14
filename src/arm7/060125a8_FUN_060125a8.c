/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SendMessageToWmDirect SDK_data_0600f19c
#define IssueMaDataConfirm FUN_060125a8
#include "nitro/os/common/interrupt.h"

#include "WlSys.h"

#include "WlLib.h"
#include "MAC.h"
#include "MA.h"
#include "WlOpe.h"

#pragma thumb off
void IssueMaDataConfirm(LPHEAPBUF_MAN pBufMan, void *pBuf)
{
    WlMaDataReq *pReq;
    WlMaDataCfm *pCfm;

    pReq = (WlMaDataReq *)pBuf;
    pCfm = (WlMaDataCfm *)WL_CalcConfirmPointer(pReq);

    pReq->header.code = pCfm->header.code;

    pCfm->header.length = CalcCfmMsgLength(WlMaDataCfm);
    pCfm->resultCode = WL_CMDRES_SUCCESS;
    pCfm->txStatus = pReq->frame.status;

    SendMessageToWmDirect(pBufMan, pReq);
}
