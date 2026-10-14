/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WaitLoop_Rxpe FUN_0600f0ec

#include "WlSys.h"
#include "WlLib.h"

#include "MAC.h"
#include "DbgChar.h"
#include "WaitLoop.h"

#pragma thumb off
void WaitLoop_Rxpe(void)
{
    u32 i;

    for (i = 4000; i > 0; i--) {
        if (*(vu16 *)MREG_SIGNAL_STATE & SIGNAL_STATE_RXPE) {
            return;
        }
    }

    DbgWlPrint(B_WL_DBG_ERRMSG, "RX_PE timeout\r\n");
}
