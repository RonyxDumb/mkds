/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSP_DisconnectCore FUN_06004a9c
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define WMSP_Disconnect FUN_06005060
#include "wmsp_private.h"
extern BOOL WMSP_DisconnectCore(u32 *args, BOOL indicateFlag, u16 *disconnected);
#pragma thumb off
void WMSP_Disconnect(OSMessage msg)
{
    BOOL result;
    u16 tryBmp;
    u16 resBmp;

    tryBmp = (u16)(((u32 *)msg)[1]);
    result = WMSP_DisconnectCore(msg, FALSE, &resBmp);

    if (result == TRUE) {
        WMDisconnectCallback *const callback = (WMDisconnectCallback *)WMSP_GetBuffer4Callback2Wm9();
        callback->apiid = WM_APIID_DISCONNECT;
        callback->errcode = WM_ERRCODE_SUCCESS;
        callback->tryBitmap = tryBmp;
        callback->disconnectedBitmap = resBmp;
        (void)WMSP_ReturnResult2Wm9(callback);
        return;
    }
}
