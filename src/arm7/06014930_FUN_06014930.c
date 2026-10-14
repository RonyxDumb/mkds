/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define WClearKSID FUN_0600aa0c
#define OS_EnableIrqMask thunk_FUN_037f888c
#define ClearTxKeyData FUN_06014930

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
void ClearTxKeyData(void)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;
    u32 x;

    x = OS_DisableIrqMask(OS_IE_WIRELESS);

    if (wlMan->Config.NullKeyRes == 0) {
        WClearKSID(NULL);
    }

    *(vu16 *)MREG_TXQ_RESET = TXQ_RST_KEYIN | TXQ_RST_KEYOUT;

    pTxCtrl->Key[0].Busy = FALSE;
    pTxCtrl->Key[1].Busy = FALSE;

    OS_EnableIrqMask(x);
}
