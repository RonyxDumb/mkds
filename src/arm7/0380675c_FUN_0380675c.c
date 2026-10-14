/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_CpuCopyFast FUN_037fb2c4
#define wvrVramImageBuf SDK_data_0380a340
#define wvrVramImageBufSize SDK_data_0380a348
#define WvrLoad FUN_0380675c
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
extern void *wvrVramImageBuf;
extern u32 wvrVramImageBufSize;
#pragma thumb off
void WvrLoad(void)
{
    if (wvrVramImageBuf == NULL) {
        return;
    }

    MI_CpuCopyFast(wvrVramImageBuf, (void *)HW_EXT_WRAM, wvrVramImageBufSize);
}
