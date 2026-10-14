/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define WlIntrMpEndTask FUN_0600db3c
#define OS_EnableIrqMask thunk_FUN_037f888c
#define ClearTxMp FUN_060148d0

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
void ClearTxMp(void)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;
    u32 x;

    x = OS_DisableIrqMask(OS_IE_WIRELESS);

    *(vu16 *)MREG_TXQ_RESET = TXQ_RST_MP;

    if (pTxCtrl->Mp.Busy) {
        WlIntrMpEndTask();
    }

    OS_EnableIrqMask(x);
}
