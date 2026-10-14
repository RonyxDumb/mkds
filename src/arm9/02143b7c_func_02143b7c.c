/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_CheckStateEx func_02142988
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_EndParent func_02143b7c
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_EndParent (WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_PARENT);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_END_PARENT, callback);

    result = WMi_SendCommand(WM_APIID_END_PARENT, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
