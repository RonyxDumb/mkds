/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WmspStabilizeBeacon FUN_06008054
#include "wmsp_private.h"

#pragma thumb off
void WmspStabilizeBeacon(void)
{
    *(vu16 *)MREG_TMPTT_ACT_TIME = 200;
    *(vu16 *)MREG_TBTT_ACT_TIME = 2000;
    *(vu16 *)MREG_RF_WAKEUP_TIME = 0x0202;
}
