/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_SendCommand Fs_File_SendOperation
#define FS_OpenFileDirect Fs_File_OpenRaw
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"

#pragma thumb off
BOOL FS_OpenFileDirect(FSFile * p_file, FSArchive * p_arc, u32 image_top, u32 image_bottom, u32 file_index)
{
    p_file->arc = p_arc;
    p_file->arg.openfiledirect.index = file_index;
    p_file->arg.openfiledirect.top = image_top;
    p_file->arg.openfiledirect.bottom = image_bottom;
    if (!FSi_SendCommand(p_file, FS_COMMAND_OPENFILEDIRECT))
        return FALSE;
    p_file->stat |= FS_FILE_STATUS_IS_FILE;
    p_file->stat &= ~FS_FILE_STATUS_IS_DIR;
    return TRUE;
}
