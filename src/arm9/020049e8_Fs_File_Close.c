/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_SendCommand Fs_File_SendOperation
#define FS_CloseFile Fs_File_Close
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"

#pragma thumb off
BOOL FS_CloseFile(FSFile * p_file)
{
    if (!FSi_SendCommand(p_file, FS_COMMAND_CLOSEFILE))
        return FALSE;
    p_file->arc = NULL;
    p_file->command = FS_COMMAND_INVALID;
    p_file->stat &= ~(FS_FILE_STATUS_IS_FILE | FS_FILE_STATUS_IS_DIR);
    return TRUE;
}
