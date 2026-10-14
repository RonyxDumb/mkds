/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WlIntrRfWakeup FUN_0600d508

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
void WlIntrRfWakeup(void) __attribute__((never_inline))
{
#if (EMU_MACREG)
    *(vu16 *)MREG_ISR &= ~MISR_RF_WAKEUP;
#else
    *(vu16 *)MREG_ISR = MISR_RF_WAKEUP;
#endif

    DbgSetDDO(DDO_WL_INT, DDO_WL_INT_RFWAKEUP);
    DbgSetDDO(DDO_WL_PS, DDO_WL_PS_RF_WAKEUP);
    DbgSetDDO(DDO_WL_PS2, DDO_WL_PS2_RF_WAKEUP);
    DbgWlPutchar(B_WL_DBG_INT, (WL_DBG_INT_RFWAKEUP));
    DbgClrDDO(DDO_WL_INT, DDO_WL_INT_RFWAKEUP);
    DbgClrDDO(DDO_WL_PS, DDO_WL_PS_RF_WAKEUP);
    DbgSetDDO(DDO_WL_PS2, DDO_WL_PS2_RF_WAKEUP);
}
