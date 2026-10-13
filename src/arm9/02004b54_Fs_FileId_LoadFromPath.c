/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_InitFile Fs_File_Initialize
#define FSi_FindPath Fs_File_FindPath
#define FS_ConvertPathToFileID Fs_FileId_LoadFromPath
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"
extern void FS_InitFile(FSFile * p_file);
extern BOOL FSi_FindPath(FSFile * p_dir, const char * path, FSFileID * p_file_id, FSDirPos * p_dir_pos);
#pragma thumb off
BOOL FS_ConvertPathToFileID(FSFileID * p_file_id, const char * path)
{
    FSFile dir;
    FS_InitFile(&dir);
    if (!FSi_FindPath(&dir, path, p_file_id, NULL))
        return FALSE;
    return TRUE;
}
