/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define AllocateHeapBuf FUN_06009138
#define SetFatalErr FUN_06009360
#define WSetMacAdrs1 FUN_0600a954
#define SendMessageToWmDirect FUN_0600f19c
#define MLME_IssueDeAuthIndication FUN_0600fa04

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
u32 MLME_IssueDeAuthIndication(u16 *pMacAdrs, u16 reason)
{
    WlMlmeDeAuthInd *pInd;

    pInd = (WlMlmeDeAuthInd *)AllocateHeapBuf(&wlMan->HeapMan.TmpBuf, sizeof(WlMlmeDeAuthInd));
    if ((u32)pInd == HEAPBUF_NOT_ENOUGH_MEMORY) {
        SetFatalErr(WL_FATAL_ERR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }

    pInd->header.code = WL_CMDCODE_MLME_DEAUTH_IND;
    pInd->header.length = CalcIndMsgLength(WlMlmeDeAuthInd);

    WSetMacAdrs1(pInd->peerMacAdrs, pMacAdrs);
    pInd->reasonCode = reason;

    IssueMlmeIndication(&wlMan->HeapMan.TmpBuf, pInd);

    return TRUE;
}
