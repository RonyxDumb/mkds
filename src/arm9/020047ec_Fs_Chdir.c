/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_InitFile Fs_File_Initialize
#define FSi_FindPath Fs_File_FindPath
#define current_dir_pos SDK_data_0216f344
#define FS_ChangeDir Fs_Chdir
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"
extern void FS_InitFile(FSFile * p_file);
extern BOOL FSi_FindPath(FSFile * p_dir, const char * path, FSFileID * p_file_id, FSDirPos * p_dir_pos);
extern FSDirPos current_dir_pos;
#pragma thumb off
BOOL FS_ChangeDir(const char * path)
{
    FSDirPos pos;
    FSFile dir;
    FS_InitFile(&dir);
    if (!FSi_FindPath(&dir, path, NULL, &pos))
        return FALSE;
    current_dir_pos = pos;
    return TRUE;
}
