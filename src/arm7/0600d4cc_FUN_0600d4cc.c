/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WUpdateCounter FUN_0600a684
#define WlIntrCntOvf FUN_0600d4cc

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
void WlIntrCntOvf(void) __attribute__((never_inline))
{
    DbgWlPutchar(B_WL_DBG_INT, (WL_DBG_INT_CNTOVF));
    DbgSetDDO(DDO_WL_INT, DDO_WL_INT_CNTOVF);

    WUpdateCounter();

    DbgClrDDO(DDO_WL_INT, DDO_WL_INT_CNTOVF);

#if (EMU_MACREG)
    *(vu16 *)MREG_ISR &= ~MISR_CNT_OVF;
#else
    *(vu16 *)MREG_CNTOVF_ISR = 0xFFFF;
    *(vu16 *)MREG_ISR = MISR_CNT_OVF;
#endif
}
