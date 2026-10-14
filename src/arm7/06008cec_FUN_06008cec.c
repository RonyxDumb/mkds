/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ReleaseAllHeapBuf FUN_06008c98
#define ReleaseAllWlHeapBuf FUN_06008cec

#include "WlSys.h"

#include "WlLib.h"
#include "BufMan.h"
#include "TaskMan.h"
#include "Param.h"
extern void ReleaseAllHeapBuf(LPHEAPBUF_MAN pHeapBufMan);
#pragma thumb off
void ReleaseAllWlHeapBuf(void)
{
    LPHEAP_MAN pHeapMan = &wlMan->HeapMan;

    ReleaseAllHeapBuf(&pHeapMan->TxPri[0]);
    ReleaseAllHeapBuf(&pHeapMan->TxPri[1]);
    ReleaseAllHeapBuf(&pHeapMan->TxPri[2]);
    ReleaseAllHeapBuf(&pHeapMan->MaDataCfm);
    ReleaseAllHeapBuf(&pHeapMan->RxData);
    ReleaseAllHeapBuf(&pHeapMan->RxBeacon);
    ReleaseAllHeapBuf(&pHeapMan->RxManCtrl);
    ReleaseAllHeapBuf(&pHeapMan->Defrag);
}
