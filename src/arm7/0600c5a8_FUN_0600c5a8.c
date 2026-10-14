/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define WlIntrMpEnd FUN_0600ca18
#define OS_EnableIrqMask thunk_FUN_037f888c
#define MacBugTxMp FUN_0600c5a8

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
extern void WlIntrMpEnd(u32 bMacBugPatch);
#pragma thumb off
void MacBugTxMp(void *arg)
{
#pragma unused(arg)

    u32 x, i;
    u16 seqCtrl, seqCtrl2;

    x = OS_DisableIrqMask(OS_IE_WIRELESS);

    seqCtrl = *(vu16 *)MREG_CURR_SEQCTRL;
    *(vu16 *)MREG_JUMP_TST = 0x1000;
    for (i = 100; i > 0; i--) {
        seqCtrl2 = *(vu16 *)MREG_CURR_SEQCTRL;
        if (seqCtrl != seqCtrl2) {
            break;
        }
    }
    *(vu16 *)MREG_JUMP_TST = 0x0000;
    WlIntrMpEnd(FALSE);

    OS_EnableIrqMask(x);

    DbgWlPrint(B_WL_DBG_ERRMSG, "Exec WlIntrMpEnd\r\n");
}
