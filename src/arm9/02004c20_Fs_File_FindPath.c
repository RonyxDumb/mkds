/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_FindArchive Fs_FindArchiveByMountName
#define FSi_SendCommand Fs_File_SendOperation
#define current_dir_pos SDK_data_0216f344
#define FSi_FindPath Fs_File_FindPath
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"
extern FSDirPos current_dir_pos;
#pragma thumb off
BOOL FSi_FindPath(FSFile * p_dir, const char * path, FSFileID * p_file_id, FSDirPos * p_dir_pos)
{
    FSDirPos pos;
    if (FSi_IsSlash(MI_ReadByte(path)))
    {
        pos.arc = current_dir_pos.arc;
        pos.own_id = 0;
        pos.pos = 0;
        pos.index = 0;
        path++;
    }
    else
    {
        int i;
        pos = current_dir_pos;
        for (i = 0; i <= FS_ARCHIVE_NAME_LEN_MAX; ++i)
        {
            u32 c = MI_ReadByte(path + i);
            if (!c || FSi_IsSlash(c))
                break;
            else if (c == ':')
            {
                FSArchive * const p_arc = FS_FindArchive(path, i);
                if (!p_arc)
                {
                    return FALSE;
                }
                else if (!FS_IsArchiveLoaded(p_arc))
                {
                    return FALSE;
                }
                pos.arc = p_arc;
                pos.pos = 0;
                pos.index = 0;
                pos.own_id = 0;
                path += i + 1;
                if (FSi_IsSlash(MI_ReadByte(path)))
                    ++path;
                break;
            }
        }
    }
    p_dir->arc = pos.arc;
    p_dir->arg.findpath.path = path;
    p_dir->arg.findpath.pos = pos;
    if (p_dir_pos)
    {
        p_dir->arg.findpath.find_directory = TRUE;
        p_dir->arg.findpath.result.dir = p_dir_pos;
    }
    else
    {
        p_dir->arg.findpath.find_directory = FALSE;
        p_dir->arg.findpath.result.file = p_file_id;
    }
    return FSi_SendCommand(p_dir, FS_COMMAND_FINDPATH);
}
