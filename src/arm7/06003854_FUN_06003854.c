/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define WmspError FUN_06003854
#include "wmsp_private.h"

#pragma thumb off
void WmspError(u16 wlCommand, u16 wlResult, BOOL exFlag)
{
    WMStartScanCallback *callback = (WMStartScanCallback *)WMSP_GetBuffer4Callback2Wm9();
    if (exFlag) {
        callback->apiid = WM_APIID_START_SCAN_EX;
    } else {
        callback->apiid = WM_APIID_START_SCAN;
    }
    callback->errcode = WM_ERRCODE_FAILED;
    callback->state = WM_STATECODE_PARENT_NOT_FOUND;
    callback->wlCmdID = wlCommand;
    callback->wlResult = wlResult;

    WMSP_ReturnResult2Wm9(callback);
}
