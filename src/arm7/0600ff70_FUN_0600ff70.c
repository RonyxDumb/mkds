/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MakeAssReqFrame FUN_06013c80
#define AddTask FUN_06008a8c
#define TxManCtrlFrame FUN_060143ac
#define SetupTimeOut FUN_060098d4
#define ResetTxqPri FUN_06014708
#define ClearQueuedPri FUN_060147a0
#define MessageDeleteTx FUN_060143cc
#define IssueMlmeConfirm FUN_0600fafc
#define MLME_AssTimeOut SDK_data_0600ff2c
#define MLME_AssTask FUN_0600ff70

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
extern void MLME_AssTimeOut(void *arg);
#pragma thumb off
void MLME_AssTask(void)
{
    LPMLME_MAN pMLME = &wlMan->MLME;
    void *pFrm;

    switch (pMLME->State) {
    case MLME_STATE_ASS_STARTUP:
        pFrm = MakeAssReqFrame(pMLME->pReq.Ass->peerMacAdrs);
        if ((u32)pFrm == HEAPBUF_NOT_ENOUGH_MEMORY) {
            pMLME->pCfm.Ass->resultCode = WL_CMDRES_NOT_ENOUGH_MEM;

            pMLME->State = MLME_STATE_ASS_FIN;

            AddTask(TASK_NORMAL_PRIORITY, MLME_ASS_TASK_ID);
        } else {
            pMLME->State = MLME_STATE_ASS_ING;

            TxManCtrlFrame((LPTXFRM)pFrm);

            SetupTimeOut(pMLME->pReq.Ass->timeOut, MLME_AssTimeOut);
        }
        break;

    case MLME_STATE_ASS_FIN:
        ResetTxqPri(QID_MANCTRL);
        ClearQueuedPri(QID_MANCTRL);
        MessageDeleteTx(QID_MANCTRL, FALSE);

        pMLME->State = MLME_STATE_IDLE;

        IssueMlmeConfirm();
        break;
    }
}
