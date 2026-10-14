/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WL_WriteByte FUN_060096e4
#define RateBit2Element SDK_data_06018ad4
#define SetSupRateSet FUN_060133fc

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
u32 SetSupRateSet(u8 *pBuf)
{
    LPWORK_PARAM pWork = &wlMan->Work;
    u8 *pBase = pBuf;
    u32 len = 0;
    u32 i;

    WL_WriteByte(&pBuf[0], ID_SUPRATE_ELEMENT);
    len++;

    len++;

    for (i = 0; i < sizeof(pWork->RateSet.Basic) * 8; i++) {
        if (pWork->RateSet.Support & (0x01 << i)) {
            if (pWork->RateSet.Basic & (0x01 << i)) {
                WL_WriteByte(&pBuf[len], (RateBit2Element[i] | 0x80));
            } else {
                WL_WriteByte(&pBuf[len], RateBit2Element[i]);
            }
            len++;
        }
    }

    WL_WriteByte(&pBase[1], (len - 2));

    return len;
}
