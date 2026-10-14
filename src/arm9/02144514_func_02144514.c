/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_GetSystemWork Wm_GetGlobal
#define WMi_CheckStateEx func_02142988
#define DC_InvalidateRange DC_InvalidateRangeNoClean
#define DC_StoreRange DC_SomeClean
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define WMi_SendCommand WM_SomeFn
#define WM_StartDCF func_02144514
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_StartDCF (WMCallbackFunc callback, WMDcfRecvBuf * recvBuf, u16 recvBufSize)
{
    WMErrCode result;
    WMArm9Buf * p = WMi_GetSystemWork();

    result = WMi_CheckState(WM_STATE_CHILD);
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(p->status->dcf_flag), 4);
    if (p->status->dcf_flag == TRUE) {
        WM_WARNING("Already DCF mode. So can't start DCF again.\n");
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if (recvBufSize < 16) {
        WM_WARNING("Parameter \"recvBufSize\" must not be less than %d.\n", 16);
        return WM_ERRCODE_INVALID_PARAM;
    }

    if (recvBuf == NULL) {
        WM_WARNING("Parameter \"recvBuf\" must not be NULL.\n");
        return WM_ERRCODE_INVALID_PARAM;
    }

    if ((u32)recvBuf & 0x01f) {

        WM_WARNING("Parameter \"recvBuf\" is not 32-byte aligned.\n");
    }

    DC_StoreRange(recvBuf, recvBufSize);
    WMi_SetCallbackTable(WM_APIID_START_DCF, callback);

    result = WMi_SendCommand(WM_APIID_START_DCF, 2, (u32)recvBuf, (u32)recvBufSize);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
