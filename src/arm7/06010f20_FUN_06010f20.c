/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WSetPowerMgtMode FUN_0600ae2c
#define WSetForcePowerState FUN_0600adec
#define WSetPowerState FUN_0600ae00
#define MLME_PwrMgtReqCmd FUN_06010f20

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
u16 MLME_PwrMgtReqCmd(WlCmdReq *pReqt, WlCmdCfm *pCfmt)
{
    WlMlmePowerMgtReq *pReq = (WlMlmePowerMgtReq *)pReqt;

    pCfmt->header.length = CalcCfmMsgLength(WlMlmePowerMgtReq);

    if (pReq->pwrMgtMode > MAX_PWRMGT_MODE) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->wakeUp > MAX_PWRMGT_WAVEUP) {
        return WL_CMDRES_INVALID_PARAM;
    }
    if (pReq->recieveDtims > MAX_PWRMGT_RXDTIMS) {
        return WL_CMDRES_INVALID_PARAM;
    }

    WSetPowerMgtMode(pReq->pwrMgtMode);
    if (pReq->pwrMgtMode == WL_CMDLABEL_PMG_PS) {
        if (pReq->wakeUp == WL_CMDLABEL_WAKEUP_CONT_SLEEP) {
            WSetForcePowerState(FPWR_STS_SLEEP);
        } else {
            WSetForcePowerState(FPWR_STS_DISABLE);
        }

        wlMan->Work.RxDtims = pReq->recieveDtims;
    } else {
        WSetForcePowerState(FPWR_STS_ACTIVE);

        WSetPowerState(PWRSTS_ACT);
    }

    return WL_CMDRES_SUCCESS;
}
