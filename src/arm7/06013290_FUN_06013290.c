/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WL_WriteByte FUN_060096e4
#define WL_ReadByte FUN_060096c4
#define SetGameInfoElement FUN_06013290

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
u32 SetGameInfoElement(u8 *pBuf)
{
    LPWORK_PARAM pWork = &wlMan->Work;
    LPCONFIG_PARAM pConfig = &wlMan->Config;
    u32 i, j, vtsf;
    u8 *p;

    i = 0;

    WL_WriteByte(&pBuf[i], ID_GAME_INFO_ELEMENT);
    i++;

    WL_WriteByte(&pBuf[i], wlMan->Work.GameInfoLength + 3 + 1 + 4);
    i++;

    WL_WriteByte(&pBuf[i], GAME_INFO_OUI_0);
    i++;
    WL_WriteByte(&pBuf[i], GAME_INFO_OUI_1);
    i++;
    WL_WriteByte(&pBuf[i], GAME_INFO_OUI_2);
    i++;

    WL_WriteByte(&pBuf[i], GAME_INFO_SUBTYPE);
    i++;

    WL_WriteByte(&pBuf[i], pConfig->ActiveZone);
    i++;
    WL_WriteByte(&pBuf[i], pConfig->ActiveZone >> 8);
    i++;

    vtsf = *(vu16 *)V_TSF;
    WL_WriteByte(&pBuf[i], vtsf & 0x00FF);
    i++;
    WL_WriteByte(&pBuf[i], vtsf >> 8);
    i++;

    if (pWork->GameInfoLength != 0) {
        p = (u8 *)pWork->GameInfoAdrs;
        if (pWork->GameInfoAlign & 1) {
            p++;
        }

        for (j = 0; j < pWork->GameInfoLength; j++) {
            WL_WriteByte(&pBuf[i], WL_ReadByte(p));
            i++;
            p++;
        }
    }

    return i;
}
