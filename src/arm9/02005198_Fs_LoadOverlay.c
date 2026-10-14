/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_LoadOverlayInfo Fs_OverlayInfo_Load
#define FS_LoadOverlayImage Fs_OverlayInfo_LoadImage
#define FS_StartOverlay Fs_OverlayInfo_Start
#define FS_LoadOverlay Fs_LoadOverlay
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
extern BOOL FS_LoadOverlayInfo(FSOverlayInfo * p_ovi, MIProcessor target, FSOverlayID id);
extern BOOL FS_LoadOverlayImage(FSOverlayInfo * p_ovi);
extern void FS_StartOverlay(FSOverlayInfo * p_ovi);
#pragma thumb off
BOOL FS_LoadOverlay(MIProcessor target, FSOverlayID id)
{
    FSOverlayInfo ovi;
    if (!FS_LoadOverlayInfo(&ovi, target, id) || !FS_LoadOverlayImage(&ovi))
        return FALSE;
    FS_StartOverlay(&ovi);
    return TRUE;
}
