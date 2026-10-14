/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_GetSystemWork Wm_GetGlobal
#define WMi_CheckStateEx func_02142988
#define DC_InvalidateRange DC_InvalidateRangeNoClean
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_EndMP func_02143fbc
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_EndMP (WMCallbackFunc callback)
{
    WMErrCode result;
    WMArm9Buf * p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, WM_STATE_MP_PARENT, WM_STATE_MP_CHILD);
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(p->status->mp_flag), 4);
    if (p->status->mp_flag == FALSE) {
        WM_WARNING("It is not MP mode now.\n");
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    WMi_SetCallbackTable(WM_APIID_END_MP, callback);

    result = WMi_SendCommand(WM_APIID_END_MP, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
