/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_GetSystemWork Wm_GetGlobal
#define WMi_CheckStateEx func_02142988
#define DC_InvalidateRange DC_InvalidateRangeNoClean
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_EndDCF func_021443b0
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_EndDCF (WMCallbackFunc callback)
{
    WMErrCode result;
    WMArm9Buf * p = WMi_GetSystemWork();

    result = WMi_CheckState(WM_STATE_DCF_CHILD);
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(p->status->dcf_flag), 4);
    if (p->status->dcf_flag == FALSE) {
        WM_WARNING("It is not DCF mode now.\n");
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    WMi_SetCallbackTable(WM_APIID_END_DCF, callback);

    result = WMi_SendCommand(WM_APIID_END_DCF, 0);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
