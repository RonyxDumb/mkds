/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_GetMacAddress Os_GetMacAddress
#define WM_GetDispersionScanPeriod func_02143090
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
u16 WM_GetDispersionScanPeriod (void)
{
    u8 mac[6];
    u16 ret;
    s32 i;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++) {
        ret += mac[i];
    }

    ret += OS_GetVBlankCount();
    ret *= 13;

    return (u16)(WM_DEFAULT_SCAN_PERIOD + (ret % 10));
}
