/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_GetMacAddress Os_GetMacAddress
#define WM_GetDispersionBeaconPeriod MaybeGeneratePseudoRandomValue
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
u16 WM_GetDispersionBeaconPeriod (void)
{
    u8 mac[6];
    u16 ret;
    s32 i;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++) {
        ret += mac[i];
    }

    ret += OS_GetVBlankCount();
    ret *= 7;

    return (u16)(WM_DEFAULT_BEACON_PERIOD + (ret % 20));
}
