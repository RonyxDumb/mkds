/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WStart FUN_06009f84
#define SetupTimeOut FUN_060098d4
#define WStop FUN_06009ecc
#define IssueMlmeConfirm FUN_0600fafc
#define MLME_JoinTimeOut SDK_data_0601015c
#define MLME_JoinTask FUN_0601019c

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
extern void IssueMlmeConfirm(void);
extern void MLME_JoinTimeOut(void *arg);
#pragma thumb off
void MLME_JoinTask(void)
{
    LPMLME_MAN pMLME = &wlMan->MLME;

    switch (pMLME->State) {
    case MLME_STATE_JOIN_STARTUP:
        WStart();

        pMLME->Work.Join.Result = FALSE;
        pMLME->Work.Join.Status = WL_CMDLABEL_STS_SUCCESSFUL;

        pMLME->State = MLME_STATE_JOIN_ING;

        SetupTimeOut(pMLME->pReq.Join->timeOut, MLME_JoinTimeOut);
        break;

    case MLME_STATE_JOIN_FIN:

        DbgWlPutchar(B_WL_DBG_MLME, (WL_DBG_MLME_JOIN_FIN));
        DbgClrDDO(DDO_WL_CONNECT, DDO_WL_CONNECT_JOIN);

        pMLME->pCfm.Join->resultCode = pMLME->Work.Join.Result;
        pMLME->pCfm.Join->statusCode = pMLME->Work.Join.Status;

        if (pMLME->Work.Join.Result != WL_CMDRES_SUCCESS) {
            WStop();
        }

        pMLME->State = MLME_STATE_IDLE;

        IssueMlmeConfirm();
        break;
    }
}
