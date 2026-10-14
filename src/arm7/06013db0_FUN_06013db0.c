/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define DMA_Write FUN_06009788
#define WL_WriteByte FUN_060096e4
#define UpdateGameInfoElement FUN_06013db0

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "TxCtrl.h"
#include "MAC.h"
#include "CAM.h"
#include "MA.h"
#include "Compati.h"
#include "WlOpe.h"
#include "WlIntrTask.h"

#pragma thumb off
void UpdateGameInfoElement(void)
{
    LPWORK_PARAM pWork = &wlMan->Work;
    LPGAME_INFO_ELEMENT pGMIF = (LPGAME_INFO_ELEMENT)((u32)wlMan->TxCtrl.Beacon.pMacFrm->Body + pWork->Ofst.Beacon.GameInfo);

    if (pWork->GameInfoLength != 0) {
        if ((u32)pWork->GameInfoAlign & 1) {
            DMA_Write((void *)((u32)pGMIF->GameInfo - 1), pWork->GameInfoAdrs, pWork->GameInfoLength + 2);
            WL_WriteByte(&pGMIF->VTSF[1], *(vu16 *)V_TSF >> 8);
        } else {
            DMA_Write(pGMIF->GameInfo, pWork->GameInfoAdrs, pWork->GameInfoLength + 1);
        }
    }

    wlMan->TxCtrl.Beacon.pMacFrm->MacHeader.Tx.MPDU = 24 + pWork->Ofst.Beacon.GameInfo + 2 + 3 + 1 + 4 + pWork->GameInfoLength + 4;

    WL_WriteByte(&pGMIF->Length, 3 + 1 + 4 + pWork->GameInfoLength);

    if (wlMan->WlOperation & MAC_BUG_DESTROY_TXBUF) {
        u16 *pId = (u16 *)(((u32)pGMIF + 1 + 1 + 3 + 1 + 4 + pWork->GameInfoLength + 3) & 0xFFFFFFFC);
        pId[0] = DESTROY_TXBUF_ID0;
        pId[1] = DESTROY_TXBUF_ID1;
    }

    pWork->bUpdateGameInfo = FALSE;
}
