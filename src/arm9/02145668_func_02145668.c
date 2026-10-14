/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_CheckIdle func_02142a30
#define DC_StoreRange DC_SomeClean
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_SetWEPKeyEx func_02145668
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_SetWEPKeyEx (WMCallbackFunc callback, u16 wepmode, u16 wepkeyid, const u8 * wepkey)
{
    WMErrCode result;

    result = WMi_CheckIdle();
    WM_CHECK_RESULT(result);

    if (wepmode > 3) {
        WM_WARNING("Parameter \"wepmode\" must be less than %d.\n", 3);
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (wepmode != WM_WEPMODE_NO) {
        if (wepkey == NULL) {
            WM_WARNING("Parameter \"wepkey\" must not be NULL.\n");
            return WM_ERRCODE_INVALID_PARAM;
        }

        if (wepkeyid > 3) {
            WM_WARNING("Parameter \"wepkeyid\" must be less than %d.\n", 3);
        }

        if ((u32)wepkey & 0x01f) {
            WM_WARNING("Parameter \"wepkey\" is not 32-byte aligned.\n");
        }

        DC_StoreRange((void *)wepkey, WM_SIZE_WEPKEY);
    }

    WMi_SetCallbackTable(WM_APIID_SET_WEPKEY_EX, callback);

    result = WMi_SendCommand(WM_APIID_SET_WEPKEY_EX, 3, (u32)wepmode, (u32)wepkey, (u32)wepkeyid);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
