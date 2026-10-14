/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WSetStaState FUN_0600a970
#define WSetMacAdrs1 FUN_0600a954
#define MLME_AuthTask FUN_06010078
#define MLME_AuthReqCmd FUN_06010b38

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
extern void MLME_AuthTask(void);
#pragma thumb off
u16 MLME_AuthReqCmd(WlCmdReq *pReqt, WlCmdCfm *pCfmt)
{
    LPWORK_PARAM pWork = &wlMan->Work;
    LPCONFIG_PARAM pConfig = &wlMan->Config;
    LPMLME_MAN pMLME = &wlMan->MLME;
    WlMlmeAuthReq *pReq = (WlMlmeAuthReq *)pReqt;
    WlMlmeAuthCfm *pCfm = (WlMlmeAuthCfm *)pCfmt;

    pCfmt->header.length = CalcCfmMsgLength(WlMlmeAuthCfm);

    if ((pConfig->Mode != WL_CMDLABEL_MODE_HOTSPOT) && (pConfig->Mode != WL_CMDLABEL_MODE_CHILD)) {
        return WL_CMDRES_ILLEGAL_MODE;
    }

    if (pWork->STA < STA_CLASS1) {
        return WL_CMDRES_STATE_WRONG;
    }

    if (pReq->peerMacAdrs[0] & 0x0001) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->algorithm > MAX_AUTHTYPE) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->timeOut > MAX_AUTH_TIMEOUT) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->timeOut < MIN_AUTH_TIMEOUT) {
        return WL_CMDRES_INVALID_PARAM;
    }

    WSetStaState(STA_CLASS1);

    pMLME->pReq.Auth = pReq;
    pMLME->pCfm.Auth = pCfm;

    pMLME->State = MLME_STATE_AUTH_STARTUP;

    pCfm->algorithm = pMLME->pReq.Auth->algorithm;
    WSetMacAdrs1(pCfm->peerMacAdrs, pMLME->pReq.Auth->peerMacAdrs);

    MLME_AuthTask();

    return WL_CMDRES_OPERATING_MLME;
}
