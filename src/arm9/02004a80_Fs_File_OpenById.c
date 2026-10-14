/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_SendCommand Fs_File_SendOperation
#define FS_OpenFileFast Fs_File_OpenById
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"

#pragma thumb off
BOOL FS_OpenFileFast(FSFile * p_file, FSFileID file_id)
{
    if (!file_id.arc)
        return FALSE;
    p_file->arc = file_id.arc;
    p_file->arg.openfilefast.id = file_id;
    if (!FSi_SendCommand(p_file, FS_COMMAND_OPENFILEFAST))
        return FALSE;
    p_file->stat |= FS_FILE_STATUS_IS_FILE;
    p_file->stat &= ~FS_FILE_STATUS_IS_DIR;
    return TRUE;
}
