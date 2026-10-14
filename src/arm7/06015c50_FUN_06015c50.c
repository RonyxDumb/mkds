/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WSetMacAdrs1 FUN_0600a954
#define NewDefragment FUN_060159f8
#define MoreDefragment FUN_060157b8
#define ReleaseHeapBuf FUN_060090b4
#define AddTask FUN_06008a8c
#define DefragTask FUN_06015c50

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "RxCtrl.h"
#include "MAC.h"
#include "CAM.h"
#include "MA.h"
#include "WlOpe.h"
extern void NewDefragment(LPRXFRM_MAC pMFrm, LPDEFRAG_TBL pDefragTbl);
extern void MoreDefragment(LPRXFRM_MAC pMFrm, LPDEFRAG_TBL pDefragTbl);
#pragma thumb off
void DefragTask(void)
{
    LPHEAP_MAN pHeapMan = &wlMan->HeapMan;
    LPRXPACKET pPacket;
    LPRXFRM pFrm;
    DEFRAG_TBL defragTbl;
    u32 fc;

    pPacket = (LPRXPACKET)GetHeapBufHeadAdrs(&pHeapMan->Defrag);
    if ((u32)pPacket == HEAPBUF_HEAD_NONE) {
        return;
    }
    pFrm = &pPacket->frame;

    if (wlMan->Work.STA != STA_CLASS3) {
        goto defrag_task_exit;
    }

    DbgWlPutchar(B_WL_DBG_DEFRAG, (WL_DBG_DEFRAG_IN));

    if (pFrm->MacHeader.Rx.MPDU > 24 + MAX_DEFRAG_DATASIZE) {
        DbgPuts("Defrag Limit Len\r");
        goto defrag_task_exit;
    }

    fc = pFrm->Dot11Header.FrameCtrl.Data;

    if (fc & B_FC_TODS) {
        WSetMacAdrs1(defragTbl.DA, pFrm->Dot11Header.Adrs3);
        if (fc & B_FC_FROMDS) {
            DbgPuts("defrag from/to ds err\r");
            goto defrag_task_exit;
        } else {
            WSetMacAdrs1(defragTbl.SA, pFrm->Dot11Header.Adrs2);
        }
    } else {
        WSetMacAdrs1(defragTbl.DA, pFrm->Dot11Header.Adrs1);
        if (fc & B_FC_FROMDS) {
            WSetMacAdrs1(defragTbl.SA, pFrm->Dot11Header.Adrs3);
        } else {
            WSetMacAdrs1(defragTbl.SA, pFrm->Dot11Header.Adrs2);
        }
    }
    defragTbl.SeqCtrl.Data = pFrm->Dot11Header.SeqCtrl.Data;

    if ((fc & B_FC_MOREFRAG) && (pFrm->Dot11Header.SeqCtrl.Bit.FragNum == 0)) {
        NewDefragment((LPRXFRM_MAC)&pFrm->MacHeader, &defragTbl);
    } else {
        MoreDefragment((LPRXFRM_MAC)&pFrm->MacHeader, &defragTbl);
    }

defrag_task_exit:
    ReleaseHeapBuf(&pHeapMan->Defrag, pPacket);

    if (GetHeapBufCount(&pHeapMan->Defrag) != 0) {
        AddTask(TASK_NORMAL_PRIORITY, DEFRAG_TASK_ID);
    }
}
