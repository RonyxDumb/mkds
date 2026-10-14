/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define AllocateHeapBuf FUN_06009138
#define DMA_Read FUN_060097b8
#define TakeoutRxFrame FUN_0600da04

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "MA.h"
#include "TxCtrl.h"
#include "RxCtrl.h"
#include "MAC.h"
#include "WlIntr.h"
#include "Compati.h"
#include "MA.h"
#include "WlIntrTask.h"
#include "WlOpe.h"

#pragma thumb off
LPRXFRM TakeoutRxFrame(LPRXFRM_MAC pMFrm, u32 length) __attribute__((never_inline))
{
    LPRXPACKET pPacket;
    LPRXFRM pFrm;

    DbgSetDDO(DDO_WL_INT, DDO_WL_INT_RXFRAME);

    pPacket = (LPRXPACKET)AllocateHeapBuf(&wlMan->HeapMan.TmpBuf, length + sizeof(WlCmdHeader) + sizeof(MAC_HEADER) + sizeof(FIRM_HEADER) + sizeof(WlCmdCfm));

    if ((u32)pPacket == HEAPBUF_NOT_ENOUGH_MEMORY) {
        DbgClrDDO(DDO_WL_INT, DDO_WL_INT_RXFRAME);
#if (WL_USE_EXT_HEAPBUF)
        DbgPrint("HO(%u)", length);
#else
        DbgPrint("HO(%u:%d)", length, OS_CheckHeap(wlMan->HeapMan.HeapInfo.func.os.id, wlMan->HeapMan.HeapInfo.func.os.heapHandle));
#endif
        return (LPRXFRM)HEAPBUF_NOT_ENOUGH_MEMORY;
    }
    pFrm = (LPRXFRM)&pPacket->frame;

    DbgSetDDO(DDO_WL_INT, DDO_WL_INT_RXDMA);

    DMA_Read((void *)&pFrm->MacHeader, (void *)pMFrm, length + sizeof(MAC_HEADER));

    pFrm->FirmHeader.Length = length - 24;
    StoreHigh(&pFrm->MacHeader.Rx.Service_Rate, LoadLow(&pFrm->MacHeader.Rx.rsv_RSSI));

    DbgClrDDO(DDO_WL_INT, DDO_WL_INT_RXDMA | DDO_WL_INT_RXFRAME);

    return pFrm;
}
