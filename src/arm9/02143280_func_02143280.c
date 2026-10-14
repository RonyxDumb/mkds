/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_CheckInitialized Wm_CheckInitialized
#define WM_GetAllowedChannel func_02143280
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
u16 WM_GetAllowedChannel (void)
{
#ifdef WM_PRECALC_ALLOWEDCHANNEL
    WMErrCode result;

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return WM_GET_ALLOWED_CHANNEL_BEFORE_INIT;
    }

    return *((u16 *)((u32)(OS_GetSystemWork()->nvramUserInfo) +
                     ((sizeof(NVRAMConfig) + 3) & ~0x00000003) + 6));
#else
    WMErrCode result;
    WMArm9Buf * p = WMi_GetSystemWork();

    result = WMi_CheckIdle();
    if (result != WM_ERRCODE_SUCCESS) {
        return WM_GET_ALLOWED_CHANNEL_BEFORE_INIT;
    }

    DC_InvalidateRange(&(p->status->allowedChannel), 2);
    return p->status->allowedChannel;
#endif
}
