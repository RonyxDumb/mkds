/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_SendMessage thunk_FUN_037f9854
#define OS_ReceiveMessage thunk_FUN_037f97b4
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define SND_BeginSleep thunk_FUN_037fb9c0
#define OS_Terminate thunk_FUN_037fb000
#define wmspW SDK_data_06019088
#define WMSP_WlRequest FUN_060005e8
#include "wmsp_private.h"
#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>

#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>

#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>
extern void *WMSP_GetBuffer4Callback2Wm9(void);
extern void WMSP_ReturnResult2Wm9(void *ptr);
extern WMSPWork wmspW;
#pragma thumb off
u16 *WMSP_WlRequest(u16 *request)
{
    OSMessage msg;

    (void)OS_SendMessage(&(wmspW.toWLmsgQ), (OSMessage)request, OS_MESSAGE_BLOCK);
    (void)OS_ReceiveMessage(&(wmspW.confirmQ), &msg, OS_MESSAGE_BLOCK);
    WM_ASSERT(request == msg);

#if SDK_VERSION_WL >= 21000
    {
        WlCmdCfm *cfm = (WlCmdCfm *)WL_CalcConfirmPointer(msg);
        if (cfm->resultCode == WL_CMDRES_FLASH_ERR) {
            WMIndCallback *callback = (WMIndCallback *)WMSP_GetBuffer4Callback2Wm9();
            callback->apiid = WM_APIID_INDICATION;
            callback->errcode = WM_ERRCODE_FLASH_ERROR;
            callback->state = WM_STATECODE_UNKNOWN;
            WMSP_ReturnResult2Wm9(callback);
            SND_BeginSleep();
            OS_Terminate();
        }
    }
#endif

    return (u16 *)msg;
}
