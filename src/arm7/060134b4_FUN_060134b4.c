/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WL_WriteByte FUN_060096e4
#define WL_ReadByte FUN_060096c4
#define SetSSIDElement FUN_060134b4

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
u32 SetSSIDElement(u8 *pBuf)
{
    LPWORK_PARAM pWork = &wlMan->Work;
    u32 len = 0, ssid_len = pWork->SSIDLength;
    u32 i;

    WL_WriteByte(&pBuf[len], ID_SSID_ELEMENT);
    len++;

    WL_WriteByte(&pBuf[len], ssid_len);
    len++;

    for (i = 0; i < ssid_len; i++) {
        WL_WriteByte(&pBuf[len], WL_ReadByte(&pWork->SSID[i]));
        len++;
    }

    return len;
}
