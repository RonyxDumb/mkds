/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define IC_InvalidateRange IC_InvalidateRangeNoClean
#define DC_InvalidateRange DC_InvalidateRangeNoClean
#define MI_CpuFill8 Mem_CpuFill8
#define FS_ClearOverlayImage Fs_OverlayInfo_ClearImage
#include "nitro.h"
#include "DGT_common.h"
#include "DGT_dgt.h"
#include "OS_cache.h"
#include "OS_system.h"
#include "OS_printf.h"
#include "MI_memory.h"
#include "MI_uncompress.h"
#include "FS_rom.h"
#include "FS_overlay.h"
#include "FS_mw_dtor.h"
#include "MB_mb.h"
#include "code32.h"

#pragma thumb off
void FS_ClearOverlayImage(FSOverlayInfo * p_ovi)
{
    u8 * const im_start = FS_GetOverlayAddress(p_ovi);
    u32 const ram_size = FS_GetOverlayImageSize(p_ovi);
    u32 const total_size = FS_GetOverlayTotalSize(p_ovi);

    IC_InvalidateRange(im_start, total_size);
    DC_InvalidateRange(im_start, total_size);
    MI_CpuFill8(im_start + ram_size, 0, total_size - ram_size);
}
