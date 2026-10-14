/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WStop FUN_06009ecc
#define WInitCounter FUN_0600a888
#define MLME_ResetReqCmd FUN_06010fcc

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "Param.h"
#include "WlNic.h"
#include "WlCmdIf.h"
#include "MLME.h"
#include "MAC.h"
#include "Flash.h"

#include "TxCtrl.h"

#pragma thumb off
u16 MLME_ResetReqCmd(WlCmdReq *pReqt, WlCmdCfm *pCfmt)
{
    WlMlmeResetReq *pReq = (WlMlmeResetReq *)pReqt;

    pCfmt->header.length = CalcCfmMsgLength(WlMlmeResetCfm);

    if (pReq->mib > MAX_DEFAULT_MIB) {
        return WL_CMDRES_INVALID_PARAM;
    }

    WStop();

    if (pReq->mib == WL_CMDLABEL_RST_MIB_CLR) {
        WInitCounter();
    }

    return WL_CMDRES_SUCCESS;
}
