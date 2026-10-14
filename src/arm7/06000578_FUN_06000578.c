/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_SendMessage thunk_FUN_037f9854
#define WMSP_GetBuffer4Callback2Wm9 thunk_FUN_03807424
#define WMSP_ReturnResult2Wm9 thunk_FUN_038074cc
#define wmspW SDK_data_06019088
#define WmspPxiCallback FUN_06000578
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
void WmspPxiCallback(PXIFifoTag tag, u32 data, BOOL err)
{
#pragma unused(tag)

    BOOL result;

    if (err) {
        return;
    }

    WMSP_DLOGF_REQUEST_QUEUE("[R]:=%d", *((u16 *)data) & ~WM_API_REQUEST_ACCEPTED);

    result = OS_SendMessage(&(wmspW.requestQ), (OSMessage)data, OS_MESSAGE_NOBLOCK);

    if (!result) {
        if (wmspW.wm7buf != NULL) {
            WMCallback *cb = (WMCallback *)WMSP_GetBuffer4Callback2Wm9();

            cb->apiid = *((u16 *)data);
            cb->errcode = WM_ERRCODE_FIFO_ERROR;
            cb->wlCmdID = 0;
            cb->wlResult = 0;
            WMSP_ReturnResult2Wm9((void *)cb);
        }
    }
}
