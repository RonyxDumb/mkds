/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define InitHeapBufMan FUN_06008e2c
#define AllocateHeapBuf FUN_06009138
#define InitializeHeapBuf FUN_06008d48

#include "WlSys.h"

#include "WlLib.h"
#include "BufMan.h"
#include "TaskMan.h"
#include "Param.h"
extern void InitHeapBufMan(LPHEAPBUF_MAN pBufMan, u16 Flag);
extern void *AllocateHeapBuf(LPHEAPBUF_MAN pBufMan, u32 Length);
#pragma thumb off
void InitializeHeapBuf(LPHEAP_INFO pHeapInfo)
{
    LPHEAP_MAN pHeapMan = &wlMan->HeapMan;
    LPWORK_PARAM pWork = &wlMan->Work;

    pHeapMan->HeapInfo.heapType = pHeapInfo->heapType;
    pHeapMan->HeapInfo.func.os.id = pHeapInfo->func.os.id;
    pHeapMan->HeapInfo.func.os.heapHandle = pHeapInfo->func.os.heapHandle;

    InitHeapBufMan(&pHeapMan->TmpBuf, HEAPBUF_TMP);
    InitHeapBufMan(&pHeapMan->TxPri[0], HEAPBUF_TXPRI0);
    InitHeapBufMan(&pHeapMan->TxPri[1], HEAPBUF_TXPRI1);
    InitHeapBufMan(&pHeapMan->TxPri[2], HEAPBUF_TXPRI2);
    InitHeapBufMan(&pHeapMan->MaDataCfm, HEAPBUF_MADATACFM);
    InitHeapBufMan(&pHeapMan->RxData, HEAPBUF_RXDATA);
    InitHeapBufMan(&pHeapMan->RxBeacon, HEAPBUF_RXBEACON);
    InitHeapBufMan(&pHeapMan->RxManCtrl, HEAPBUF_RXMANCTRL);
    InitHeapBufMan(&pHeapMan->Defrag, HEAPBUF_DEFRAG);
    InitHeapBufMan(&pHeapMan->ToWM, HEAPBUF_TOWM);
    InitHeapBufMan(&pHeapMan->RequestCmd, HEAPBUF_REQUEST_CMD);

    pWork->GameInfoAdrs = (LPHEAPBUF_HEADER)((u32)AllocateHeapBuf(&pHeapMan->TmpBuf, MAX_GAMEINFO_LENGTH + 1) + WL_RSV * 2);
    pWork->GameInfoLength = 0;
    pWork->bUpdateGameInfo = FALSE;
}
