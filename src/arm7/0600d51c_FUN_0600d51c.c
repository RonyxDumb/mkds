/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WlIntrActEnd FUN_0600d51c

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
void WlIntrActEnd(void) __attribute__((never_inline))
{
    LPWORK_PARAM pWork = &wlMan->Work;

#if (EMU_MACREG)
    *(vu16 *)MREG_ISR &= ~MISR_ACTEND;
#else
    *(vu16 *)MREG_ISR = MISR_ACTEND;
#endif

    TxqClose(TXQ_OPEN_TXQ2 | TXQ_OPEN_TXQ1 | TXQ_OPEN_TXQ0);

    if (pWork->bFirstTbtt == 1) {
        pWork->bFirstTbtt = 2;
    } else if (pWork->bFirstTbtt == 2) {
        pWork->bFirstTbtt = 0;
    } else if ((pWork->Mode == WL_CMDLABEL_MODE_CHILD) && (pWork->STA != STA_CLASS3)) {
        *(vu16 *)MREG_MP_POWER_SEQ = 0;
    }
}
