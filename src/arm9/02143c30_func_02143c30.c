/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WmCheckParentParameter func_02143c30
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
BOOL WmCheckParentParameter (const WMParentParam * param)
{
    if (param->userGameInfoLength > WM_SIZE_USER_GAMEINFO) {
        OS_TWarning("User gameInfo length must be less than %d .\n", WM_SIZE_USER_GAMEINFO);
        return FALSE;
    }

    if ((param->beaconPeriod < 10) || (param->beaconPeriod > 1000)) {
        OS_TWarning("Beacon send period must be between 10 and 1000 .\n");
        return FALSE;
    }

    if ((param->channel < 1) || (param->channel > 14)) {
        OS_TWarning("Channel must be between 1 and 14 .\n");
        return FALSE;
    }

    return TRUE;
}
