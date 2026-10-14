/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_CheckStateEx func_02142988
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_SetEntry func_021453ec
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_SetEntry (WMCallbackFunc callback, BOOL enabled)
{
    WMErrCode result;

    result = WMi_CheckStateEx(2, WM_STATE_PARENT, WM_STATE_MP_PARENT);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_SET_ENTRY, callback);

    result = WMi_SendCommand(WM_APIID_SET_ENTRY, 1, (u32)enabled);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
