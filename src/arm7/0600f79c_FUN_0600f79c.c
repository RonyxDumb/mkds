/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define AllocateHeapBuf FUN_06009138
#define SetFatalErr FUN_06009360
#define WSetMacAdrs1 FUN_0600a954
#define SendMessageToWmDirect FUN_0600f19c
#define MLME_IssueDisAssIndication FUN_0600f79c

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
u32 MLME_IssueDisAssIndication(u16 *pMacAdrs, u16 reason)
{
    WlMlmeDisAssInd *pInd;

    pInd = (WlMlmeDisAssInd *)AllocateHeapBuf(&wlMan->HeapMan.TmpBuf, sizeof(WlMlmeDisAssInd));
    if ((u32)pInd == HEAPBUF_NOT_ENOUGH_MEMORY) {
        SetFatalErr(WL_FATAL_ERR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }

    pInd->header.code = WL_CMDCODE_MLME_DISASS_IND;
    pInd->header.length = CalcIndMsgLength(WlMlmeDisAssInd);

    WSetMacAdrs1(pInd->peerMacAdrs, pMacAdrs);
    pInd->reasonCode = reason;

    IssueMlmeIndication(&wlMan->HeapMan.TmpBuf, pInd);

    return TRUE;
}
