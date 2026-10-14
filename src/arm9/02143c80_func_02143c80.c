/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_CheckStateEx func_02142988
#define WmCheckParentParameter func_02143c30
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define DC_StoreRange DC_SomeClean
#define WMi_SendCommand WM_SomeFn
#define WM_SetParentParameter func_02143c80
#include <nitro/wm.h>

#include "wm_arm9_private.h"
extern BOOL WmCheckParentParameter (const WMParentParam * param);
#pragma thumb off
WMErrCode WM_SetParentParameter (WMCallbackFunc callback, const WMParentParam * pparaBuf)
{
    WMErrCode result;

    result = WMi_CheckState(WM_STATE_IDLE);
    WM_CHECK_RESULT(result);

    if (pparaBuf == NULL) {
        WM_WARNING("Parameter \"pparaBuf\" must not be NULL.\n");
        return WM_ERRCODE_INVALID_PARAM;
    }

    if ((u32)pparaBuf & 0x01f) {
        WM_WARNING("Parameter \"pparaBuf\" is not 32-byte aligned.\n");
    }

    if (pparaBuf->userGameInfoLength > 0) {
        if (pparaBuf->userGameInfo == NULL) {
            WM_WARNING("Parameter \"pparaBuf->userGameInfo\" must not be NULL.\n");
            return WM_ERRCODE_INVALID_PARAM;
        }

        if ((u32)(pparaBuf->userGameInfo) & 0x01f) {
            WM_WARNING("Parameter \"pparaBuf->userGameInfo\" is not 32-byte aligned.\n");
        }
    }

    if ((pparaBuf->parentMaxSize +
         (pparaBuf->KS_Flag ? WM_SIZE_KS_PARENT_DATA + WM_SIZE_MP_PARENT_PADDING : 0) >
         WM_SIZE_MP_DATA_MAX)
        || (pparaBuf->childMaxSize +
            (pparaBuf->KS_Flag ? WM_SIZE_KS_CHILD_DATA + WM_SIZE_MP_CHILD_PADDING : 0) >
            WM_SIZE_MP_DATA_MAX)) {
        WM_WARNING("Transfer data size is over %d byte.\n", WM_SIZE_MP_DATA_MAX);
        return WM_ERRCODE_INVALID_PARAM;
    }
    (void)WmCheckParentParameter(pparaBuf);

    WMi_SetCallbackTable(WM_APIID_SET_P_PARAM, callback);
    DC_StoreRange((void *)pparaBuf, WM_PARENT_PARAM_SIZE);

    if (pparaBuf->userGameInfoLength > 0) {
        DC_StoreRange(pparaBuf->userGameInfo, pparaBuf->userGameInfoLength);
    }

    result = WMi_SendCommand(WM_APIID_SET_P_PARAM, 1, (u32)pparaBuf);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
