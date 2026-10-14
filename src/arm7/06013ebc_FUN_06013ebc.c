/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WCalcManRate FUN_0600a450
#define WSetMacAdrs3 FUN_0600a8d4
#define WL_WriteByte FUN_060096e4
#define WL_ReadByte FUN_060096c4
#define SetSupRateSet FUN_060133fc
#define BC_ADRS SDK_data_06018ab4
#define MakeBeaconFrame FUN_06013ebc

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
extern u32 SetSupRateSet(u8 *pBuf);
#pragma thumb off
void MakeBeaconFrame(void)
{
    LPTXFRM_MAC pFrm = wlMan->TxCtrl.Beacon.pMacFrm;
    LPCONFIG_PARAM pConfig = &wlMan->Config;
    LPWORK_PARAM pWork = &wlMan->Work;
    LPBEACON_BODY pBody;
    u8 *pBuf;
    u8 *p;
    u32 i, vtsf;
    u16 *p16;

    p16 = (u16 *)&pFrm->MacHeader.Tx;
    *p16++ = 0;
    *p16++ = 0;
    *p16++ = 0;
    *p16++ = 0;
    *p16++ = WCalcManRate();

    pFrm->Dot11Header.FrameCtrl.Data = FC_BEACON;
    pFrm->Dot11Header.DurationID = 0;
    WSetMacAdrs3(pFrm->Dot11Header.Adrs1, (u16 *)BC_ADRS, pConfig->MacAdrs, pConfig->MacAdrs);
    pFrm->Dot11Header.SeqCtrl.Data = 0;

    pBody = (LPBEACON_BODY)pFrm->Body;

    pBody->TimeStamp[0] = 0;
    pBody->TimeStamp[1] = 0;
    pBody->BeaconInterval = pWork->BeaconPeriod;
    pBody->CapaInfo.Data = pWork->CapaInfo;

    pBuf = pBody->Buf;
    if (pConfig->BeaconType == WL_CMDLABEL_INCLUDE_SSID) {
        pWork->Ofst.Beacon.SSID = (u16)((u32)pBuf - (u32)pFrm->Body);
        WL_WriteByte(pBuf++, ID_SSID_ELEMENT);
        WL_WriteByte(pBuf++, pWork->SSIDLength);
        for (i = 0; i < pWork->SSIDLength; i++) {
            WL_WriteByte(pBuf++, WL_ReadByte(&pWork->SSID[i]));
        }
        WL_WriteByte(&pBuf[-i - 1], i);
    } else {
        pWork->Ofst.Beacon.SSID = 0;
    }

    pBuf += SetSupRateSet(pBuf);

    WL_WriteByte(pBuf++, ID_DS_PARAM_ELEMENT);
    WL_WriteByte(pBuf++, 1);
    WL_WriteByte(pBuf++, pWork->CurrChannel);

    pWork->Ofst.Beacon.TIM = (u16)((u32)pBuf - (u32)pBody);
    *(u16 *)MREG_BCN_DTIM_OFST = pWork->Ofst.Beacon.TIM + 2;
    WL_WriteByte(pBuf++, ID_TIM_ELEMENT);
    WL_WriteByte(pBuf++, 3 + 2);
    WL_WriteByte(pBuf++, 0);
    WL_WriteByte(pBuf++, pWork->DTIMPeriod);
    WL_WriteByte(pBuf++, 0);
    WL_WriteByte(pBuf++, 0);
    WL_WriteByte(pBuf++, 0);

    pWork->Ofst.Beacon.GameInfo = (u16)((u32)pBuf - (u32)pBody);
    pWork->GameInfoAlign = pWork->Ofst.Beacon.GameInfo & 1;
    WL_WriteByte(pBuf++, ID_GAME_INFO_ELEMENT);
    WL_WriteByte(pBuf++, 3 + 1 + 4 + pWork->GameInfoLength);
    WL_WriteByte(pBuf++, GAME_INFO_OUI_0);
    WL_WriteByte(pBuf++, GAME_INFO_OUI_1);
    WL_WriteByte(pBuf++, GAME_INFO_OUI_2);
    WL_WriteByte(pBuf++, GAME_INFO_SUBTYPE);
    if (pWork->PowerMgtMode == WL_CMDLABEL_PMG_PS) {
        WL_WriteByte(pBuf++, pConfig->ActiveZone);
        WL_WriteByte(pBuf++, (pConfig->ActiveZone >> 8));
    } else {
        WL_WriteByte(pBuf++, 0xFF);
        WL_WriteByte(pBuf++, 0xFF);
    }
    vtsf = *(u16 *)V_TSF;
    WL_WriteByte(pBuf++, vtsf & 0x00FF);
    WL_WriteByte(pBuf++, vtsf >> 8);
    p = (u8 *)pWork->GameInfoAdrs;
    for (i = 0; i < pWork->GameInfoLength; i++) {
        WL_WriteByte(pBuf++, WL_ReadByte(p));
        p++;
    }
    if (pWork->GameInfoAlign) {
        p = (u8 *)((u32)pWork->GameInfoAdrs + pWork->GameInfoLength - 1);
        for (i = 0; i < pWork->GameInfoLength; i++, p--) {
            WL_WriteByte(p + 1, WL_ReadByte(p));
        }
    }

    if (wlMan->WlOperation & MAC_BUG_DESTROY_TXBUF) {
        u16 *pId = (u16 *)(((u32)pBuf + 3) & 0xFFFFFFFC);
        pId[0] = DESTROY_TXBUF_ID0;
        pId[1] = DESTROY_TXBUF_ID1;
    }

    pWork->bUpdateGameInfo = FALSE;

    pFrm->MacHeader.Tx.MPDU = 24 + (u32)pBuf - (u32)pBody + 4;
}
