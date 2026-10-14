/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_LockMutex FUN_037f9a0c
#define SVC_WaitByLoop thunk_FUN_038011a4
#define wmspW SDK_data_06019088
#define WMSP_GetBuffer4Callback2Wm9 FUN_03807424
#include "wmsp_private.h"
#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>

#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>

#include <nitro/wram_begin.h>

#include <nitro/wram_end.h>
extern WMSPWork wmspW;
#pragma thumb off
void *WMSP_GetBuffer4Callback2Wm9(void)
{
    OS_LockMutex(&(wmspW.fifoExclusive));

    while (OS_GetSystemWork()->wm_callback_control & WM_EXCEPTION_CB_MASK) {
        SVC_WaitByLoop(256);
    }
    OS_GetSystemWork()->wm_callback_control |= WM_EXCEPTION_CB_MASK;

    return (void *)(wmspW.wm7buf->fifo7to9);
}
