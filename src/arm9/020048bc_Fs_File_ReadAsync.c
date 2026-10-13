/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_ReadFileCore SDK_data_02004b98
#define FS_ReadFileAsync Fs_File_ReadAsync
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"
extern int FSi_ReadFileCore(FSFile * p_file, void * dst, s32 len, BOOL async);
#pragma thumb off
int FS_ReadFileAsync(FSFile * p_file, void * dst, s32 len)
{
    return FSi_ReadFileCore(p_file, dst, len, TRUE);
}
