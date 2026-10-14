/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define WmspError FUN_06000080
#include "wmsp_private.h"
#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>

#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>

#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>
extern void *WMSP_GetBuffer4Callback2Wm9(void);
extern void WMSP_ReturnResult2Wm9(void *ptr);
#pragma thumb off
void WmspError(u16 wmApiID, u16 wlCommand, u16 wlResult)
{
    WMStartConnectCallback *callback = (WMStartConnectCallback *)WMSP_GetBuffer4Callback2Wm9();
    callback->apiid = wmApiID;
    callback->errcode = WM_ERRCODE_FAILED;
    callback->wlCmdID = wlCommand;
    callback->wlResult = wlResult;
    WMSP_ReturnResult2Wm9(callback);
}
