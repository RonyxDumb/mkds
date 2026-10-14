/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WSetStaState FUN_0600a970
#define WClearAids FUN_0600aa54
#define MLME_AssTask FUN_0600ff70
#define MLME_AssReqCmd FUN_06010914

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
extern void MLME_AssTask(void);
#pragma thumb off
u16 MLME_AssReqCmd(WlCmdReq *pReqt, WlCmdCfm *pCfmt)
{
    WlMlmeAssReq *pReq = (WlMlmeAssReq *)pReqt;
    LPWORK_PARAM pWork = &wlMan->Work;
    LPCONFIG_PARAM pConfig = &wlMan->Config;
    LPMLME_MAN pMLME = &wlMan->MLME;

    pCfmt->header.length = CalcCfmMsgLength(WlMlmeAssCfm);

    if ((pConfig->Mode != WL_CMDLABEL_MODE_HOTSPOT) && (pConfig->Mode != WL_CMDLABEL_MODE_CHILD)) {
        return WL_CMDRES_ILLEGAL_MODE;
    }

    if (pWork->STA < STA_CLASS2) {
        return WL_CMDRES_STATE_WRONG;
    }

    if (pReq->peerMacAdrs[0] & 0x0001 != 0) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->listenInterval == 0) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->listenInterval > MAX_LISTEN_INTERVAL) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->timeOut > MAX_ASS_TIMEOUT) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->timeOut < MIN_ASS_TIMEOUT) {
        return WL_CMDRES_INVALID_PARAM;
    }

    WSetStaState(STA_CLASS2);
    WClearAids();

    pWork->ListenInterval = pReq->listenInterval;
    pWork->CurrListenInterval = pReq->listenInterval;

    pMLME->pReq.Ass = (WlMlmeAssReq *)pReqt;
    pMLME->pCfm.Ass = (WlMlmeAssCfm *)pCfmt;

    pMLME->State = MLME_STATE_ASS_STARTUP;

    MLME_AssTask();

    return WL_CMDRES_OPERATING_MLME;
}
