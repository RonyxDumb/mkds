/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ClearTxKeyData FUN_06014930
#define ClearTxMp FUN_060148d0
#define ClearTxData FUN_06014818
#define MA_ClrDataReqCmd FUN_060125e0
#include "nitro/os/common/interrupt.h"

#include "WlSys.h"

#include "WlLib.h"
#include "MAC.h"
#include "MA.h"
#include "WlOpe.h"

#pragma thumb off
u16 MA_ClrDataReqCmd(WlCmdReq *pReqt, WlCmdCfm *pCfmt)
{
    WlMaClrDataReq *pReq = (WlMaClrDataReq *)pReqt;

    pCfmt->header.length = 1;

    if (pReq->flag & WL_CMDLABEL_CLRDATA_KEYDATA) {
        ClearTxKeyData();
    }
    if (pReq->flag & WL_CMDLABEL_CLRDATA_MP) {
        ClearTxMp();
    }
    if (pReq->flag & WL_CMDLABEL_CLRDATA_DATA) {
        ClearTxData();
    }

    return WL_CMDRES_SUCCESS;
}
