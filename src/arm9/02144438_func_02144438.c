/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMi_GetSystemWork Wm_GetGlobal
#define WMi_CheckStateEx func_02142988
#define DC_InvalidateRange DC_InvalidateRangeNoClean
#define DC_StoreRange DC_SomeClean
#define WMi_SetCallbackTable SetSomeFunctionPtr
#define MI_CpuCopy8 Mem_CpuCopy8
#define WMi_SendCommand WM_SomeFn
#define WM_SetDCFData func_02144438
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMErrCode WM_SetDCFData (WMCallbackFunc callback, const u8 * destAdr, const u16 * sendData, u16 sendDataSize)
{
    WMErrCode result;
    WMArm9Buf * p = WMi_GetSystemWork();
    u32 wMac[2];

    result = WMi_CheckState(WM_STATE_DCF_CHILD);
    WM_CHECK_RESULT(result);

    DC_InvalidateRange(&(p->status->dcf_flag), 4);
    if (p->status->dcf_flag == FALSE) {
        WM_WARNING("It is not DCF mode now.\n");
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if (sendDataSize > WM_DCF_MAX_SIZE) {
        WM_WARNING("Parameter \"sendDataSize\" is over %d.\n", WM_DCF_MAX_SIZE);
        return WM_ERRCODE_INVALID_PARAM;
    }

    if ((u32)sendData & 0x01f) {

        WM_WARNING("Parameter \"sendData\" is not 32-byte aligned.\n");
    }

    DC_StoreRange((void *)sendData, sendDataSize);
    WMi_SetCallbackTable(WM_APIID_SET_DCF_DATA, callback);
    MI_CpuCopy8(destAdr, wMac, 6);

    result = WMi_SendCommand(WM_APIID_SET_DCF_DATA, 4, (u32)wMac[0], (u32)wMac[1], (u32)sendData, (u32)sendDataSize);
    WM_CHECK_RESULT(result);

    return WM_ERRCODE_OPERATING;
}
