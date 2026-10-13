/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_ConvertPathToFileID Fs_FileId_LoadFromPath
#define FS_OpenFileFast Fs_File_OpenById
#define FS_OpenFile Fs_File_Open
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"
extern BOOL FS_ConvertPathToFileID(FSFileID * p_file_id, const char * path);
extern BOOL FS_OpenFileFast(FSFile * p_file, FSFileID file_id);
#pragma thumb off
BOOL FS_OpenFile(FSFile * p_file, const char * path)
{
    FSFileID file_id;
    return FS_ConvertPathToFileID(&file_id, path) && FS_OpenFileFast(p_file, file_id);
}
