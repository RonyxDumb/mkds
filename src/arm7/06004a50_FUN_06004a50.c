/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define WmspError FUN_06004a50
#include "wmsp_private.h"

#pragma thumb off
void WmspError(u16 wlCommand, u16 wlResult, u16 tryBmp, u16 resBmp)
{
    WMDisconnectCallback *callback = (WMDisconnectCallback *)WMSP_GetBuffer4Callback2Wm9();
    callback->apiid = WM_APIID_DISCONNECT;
    callback->errcode = WM_ERRCODE_FAILED;
    callback->wlCmdID = wlCommand;
    callback->wlResult = wlResult;
    callback->tryBitmap = tryBmp;
    callback->disconnectedBitmap = resBmp;
    WMSP_ReturnResult2Wm9(callback);
}
