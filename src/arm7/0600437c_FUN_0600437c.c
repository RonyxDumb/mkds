/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define WmspError FUN_0600437c
#include "wmsp_private.h"

#pragma thumb off
void WmspError(u16 wlCommand, u16 wlResult, u16 wlStatus)
{
    WMStartConnectCallback *callback = (WMStartConnectCallback *)WMSP_GetBuffer4Callback2Wm9();
    callback->apiid = WM_APIID_START_CONNECT;
    callback->errcode = WM_ERRCODE_FAILED;
    callback->wlCmdID = wlCommand;
    callback->wlResult = wlResult;
    callback->wlStatus = wlStatus;
    WMSP_ReturnResult2Wm9(callback);
}
