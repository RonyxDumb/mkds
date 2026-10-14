/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_ThreadInfo SDK_data_038076fc
#define WvrCheckThreadRunning FUN_03806650
#include "nitro/os/common/printf.h"
#include "nitro/wm/ARM7/wm.h"
#include <nitro/ctrdg/ARM7/ctrdg.h>
#include <nitro/mi/memory.h>
#include <nitro/os.h>
#include <nitro/os/common/alloc.h>
#include <nitro/pxi/common/fifo.h>
#include <nitro/spi/ARM7/pm.h>
#include <nitro/spi/common/pm_common.h>

#include "wmsp_private.h"

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
BOOL WvrCheckThreadRunning(OSThread *pThread)
{
    OSThread *list;

    if (pThread == NULL) {
        return FALSE;
    }

    list = OSi_ThreadInfo.list;
    while (list) {
        if (list == pThread) {
            switch (pThread->state) {
            case OS_THREAD_STATE_WAITING:
            case OS_THREAD_STATE_READY:
                return TRUE;
            case OS_THREAD_STATE_TERMINATED:
            default:
                return FALSE;
            }
        }
        list = list->next;
    }
    return FALSE;
}
