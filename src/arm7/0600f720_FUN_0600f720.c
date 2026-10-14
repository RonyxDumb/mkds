/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define AllocateHeapBuf FUN_06009138
#define SetFatalErr FUN_06009360
#define WSetMacAdrs1 FUN_0600a954
#define SendMessageToWmDirect FUN_0600f19c
#define MLME_IssueBeaconLostIndication FUN_0600f720

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
u32 MLME_IssueBeaconLostIndication(u16 *pMacAdrs)
{
    WlMlmeBeaconLostInd *pInd;

    pInd = (WlMlmeBeaconLostInd *)AllocateHeapBuf(&wlMan->HeapMan.TmpBuf, sizeof(WlMlmeBeaconLostInd));
    if ((u32)pInd == HEAPBUF_NOT_ENOUGH_MEMORY) {
        SetFatalErr(WL_FATAL_ERR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }

    pInd->header.code = WL_CMDCODE_MLME_BCLOST_IND;
    pInd->header.length = CalcIndMsgLength(WlMlmeBeaconLostInd);

    WSetMacAdrs1(pInd->apMacAdrs, pMacAdrs);

    IssueMlmeIndication(&wlMan->HeapMan.TmpBuf, pInd);

    return TRUE;
}
