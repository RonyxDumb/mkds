/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ReleaseHeapBuf FUN_060090b4
#define DefragTimerTask FUN_06015740

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "RxCtrl.h"
#include "MAC.h"
#include "CAM.h"
#include "MA.h"
#include "WlOpe.h"

#pragma thumb off
void DefragTimerTask(void)
{
    LPDEFRAG_LIST pList = wlMan->RxCtrl.DefragList;
    u32 i;

    for (i = 0; i < MAX_DEFRAG_NUM; i++) {
        if (pList[i].RestTime != 0) {
            if (--pList[i].RestTime == 0) {
                DbgWlPutchar(B_WL_DBG_DEFRAG, (WL_DBG_DEFRAG_TIMEOUT));

                ReleaseHeapBuf(&wlMan->HeapMan.TmpBuf, pList[i].pPacket);
            }
        }
    }
}
