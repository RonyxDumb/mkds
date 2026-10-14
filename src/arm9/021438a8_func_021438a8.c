/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_CheckStateEx func_02142988
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_EndScan func_021438a8
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_EndScan (WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_SCAN);
    WM_CHECK_RESULT(result);

    WMi_SetCallbackTable(WM_APIID_END_SCAN, callback);

    result = WMi_SendCommand(WM_APIID_END_SCAN, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
