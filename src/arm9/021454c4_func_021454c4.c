/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_CheckIdle func_02142a30
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_SetLifeTime func_021454c4
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_SetLifeTime (WMCallbackFunc callback, u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime)
{
    WMErrCode result;

    result = WMi_CheckIdle();
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_SET_LIFETIME, callback);

    result = WMi_SendCommand(WM_APIID_SET_LIFETIME, 4,
                             (u32)tableNumber,
                             (u32)camLifeTime, (u32)frameLifeTime, (u32)mpLifeTime);

    WM_CHECK_RESULT(result);
    return WM_ERRCODE_OPERATING;
}
