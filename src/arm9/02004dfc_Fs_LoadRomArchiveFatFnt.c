/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_LoadArchiveTables SDK_data_02003e24
#define fsi_arc_rom SDK_data_0216f36c
#define FS_TryLoadTable Fs_LoadRomArchiveFatFnt
#include "FS_rom.h"
#include "FS_archive.h"
#include "FS_file.h"
#include "CARD_pullOut.h"
#include "CARD_rom.h"
#include "CARD_common.h"
#include "MB_mb.h"
#include "OS_printf.h"
#include "code32.h"
extern FSArchive fsi_arc_rom;
#pragma thumb off
u32 FS_TryLoadTable(void * p_mem, u32 size)
{
    return FS_LoadArchiveTables(&fsi_arc_rom, p_mem, size);
}
