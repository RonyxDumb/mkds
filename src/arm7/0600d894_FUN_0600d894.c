/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define AddTask FUN_06008a8c
#define WlIntrPreTbtt FUN_0600d894

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
#include "WlOpe.h"

#pragma thumb off
void WlIntrPreTbtt(void) __attribute__((never_inline))
{
    LPWORK_PARAM pWork = &wlMan->Work;

#if (EMU_MACREG)
    *(vu16 *)MREG_ISR &= ~MISR_PRE_TBTT;
#else
    *(vu16 *)MREG_ISR = MISR_PRE_TBTT;
#endif

    DbgWlPutchar(B_WL_DBG_INT, (WL_DBG_INT_PRETBTT));
    DbgSetDDO(DDO_WL_INT, DDO_WL_INT_PRETBTT);

    if ((pWork->STA == STA_CLASS3) && (pWork->BeaconLostTh != 0) && (pWork->CurrListenInterval == pWork->ListenInterval)) {
        if (++pWork->BeaconLostCnt > pWork->BeaconLostTh) {
            DbgSetDDO(DDO_WL_LSTN_INT, DDO_WL_LSTN_INT_BEACON_LOST);
            DbgSetDDO(DDO_WL_PS2, DDO_WL_PS2_BCN_LOST);

            pWork->BeaconLostCnt = 0;

            AddTask(TASK_HIGH_PRIORITY, MLME_BEACON_LOST_TASK_ID);

            DbgClrDDO(DDO_WL_LSTN_INT, DDO_WL_LSTN_INT_BEACON_LOST);
            DbgClrDDO(DDO_WL_PS2, DDO_WL_PS2_BCN_LOST);
        }
    }

    pWork->PowerState = 1;

    DbgClrDDO(DDO_WL_INT, DDO_WL_INT_PRETBTT);
}
