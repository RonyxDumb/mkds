/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define WmspError FUN_0600335c
#include "wmsp_private.h"

#pragma thumb off
void WmspError(u16 wlCommand, u16 wlResult)
{
    WMStartParentCallback *cb;

    cb = (WMStartParentCallback *)WMSP_GetBuffer4Callback2Wm9();
    cb->apiid = WM_APIID_START_PARENT;
    cb->errcode = WM_ERRCODE_FAILED;
    cb->state = WM_STATECODE_PARENT_START;
    cb->wlCmdID = wlCommand;
    cb->wlResult = wlResult;
    WMSP_ReturnResult2Wm9((void *)cb);
}
