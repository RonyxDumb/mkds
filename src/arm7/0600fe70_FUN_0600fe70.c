/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MakeReAssReqFrame FUN_06013bc8
#define AddTask FUN_06008a8c
#define TxManCtrlFrame FUN_060143ac
#define SetupTimeOut FUN_060098d4
#define ClearQueuedPri FUN_060147a0
#define MessageDeleteTx FUN_060143cc
#define IssueMlmeConfirm FUN_0600fafc
#define MLME_ReAssTimeOut SDK_data_0600fe2c
#define MLME_ReAssTask FUN_0600fe70

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
extern void MLME_ReAssTimeOut(void *arg);
#pragma thumb off
void MLME_ReAssTask(void)
{
#ifndef SDK_SMALL_BUILD_WL
    LPMLME_MAN pMLME = &wlMan->MLME;
    void *pFrm;

    switch (pMLME->State) {
    case MLME_STATE_REASS_STARTUP:

        pFrm = MakeReAssReqFrame(pMLME->pReq.ReAss->newApMacAdrs);
        if ((u32)pFrm == HEAPBUF_NOT_ENOUGH_MEMORY) {
            pMLME->pCfm.ReAss->resultCode = WL_CMDRES_NOT_ENOUGH_MEM;

            pMLME->State = MLME_STATE_REASS_FIN;

            AddTask(TASK_NORMAL_PRIORITY, MLME_REASS_TASK_ID);
        } else {
            pMLME->State = MLME_STATE_REASS_ING;

            TxManCtrlFrame((LPTXFRM)pFrm);

            SetupTimeOut(pMLME->pReq.ReAss->timeOut, MLME_ReAssTimeOut);
        }
        break;

    case MLME_STATE_REASS_FIN:

        ClearQueuedPri(QID_MANCTRL);
        MessageDeleteTx(QID_MANCTRL, FALSE);

        pMLME->State = MLME_STATE_IDLE;

        IssueMlmeConfirm();
        break;
    }
#endif
}
