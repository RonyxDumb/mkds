/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CARD_LockRom Card_LockRomResource
#define CARD_UnlockRom Card_UnlockRomResource
#define fsi_card_lock_id SDK_data_0216f354
#define FSi_RomArchiveProc Fs_RomArchive_ExtraFileOperationHandler_Default
#include "FS_rom.h"
#include "FS_archive.h"
#include "FS_file.h"
#include "CARD_pullOut.h"
#include "CARD_rom.h"
#include "CARD_common.h"
#include "MB_mb.h"
#include "OS_printf.h"
#include "code32.h"
extern s32 fsi_card_lock_id;
#pragma thumb off
FSResult FSi_RomArchiveProc(FSFile * p_arc, FSCommandType cmd)
{
#pragma unused(p_arc)
    switch (cmd)
    {
    case FS_COMMAND_ACTIVATE:
        CARD_LockRom((u16)fsi_card_lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_IDLE:
        CARD_UnlockRom((u16)fsi_card_lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_WRITEFILE:
        return FS_RESULT_UNSUPPORTED;
    default:
        return FS_RESULT_PROC_UNKNOWN;
    }
}
