/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define WmspError FUN_0600425c
#include "wmsp_private.h"

#pragma thumb off
void WmspError(u16 wlCommand, u16 wlResult)
{
    WMCallback *callback = (WMCallback *)WMSP_GetBuffer4Callback2Wm9();
    callback->apiid = WM_APIID_END_SCAN;
    callback->errcode = WM_ERRCODE_FAILED;
    callback->wlCmdID = wlCommand;
    callback->wlResult = wlResult;
    WMSP_ReturnResult2Wm9(callback);
}
