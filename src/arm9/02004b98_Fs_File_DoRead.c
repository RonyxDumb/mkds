/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_SendCommand Fs_File_SendOperation
#define FS_WaitAsync Fs_File_WaitAsync
#define FSi_ReadFileCore Fs_File_DoRead
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"
extern BOOL FS_WaitAsync(FSFile * p_file);
#pragma thumb off
int FSi_ReadFileCore(FSFile * p_file, void * dst, s32 len, BOOL async)
{
    const s32 pos = (s32)p_file->prop.file.pos;
    const s32 rest = (s32)(p_file->prop.file.bottom - pos);
    const u32 org = (u32)len;
    if (len > rest)
        len = rest;
    if (len < 0)
        len = 0;
    p_file->arg.readfile.dst = dst;
    p_file->arg.readfile.len_org = org;
    p_file->arg.readfile.len = (u32)len;
    if (!async)
        p_file->stat |= FS_FILE_STATUS_SYNC;
    (void)FSi_SendCommand(p_file, FS_COMMAND_READFILE);
    if (!async)
    {
        if (FS_WaitAsync(p_file))
            len = (s32)(p_file->prop.file.pos - pos);
        else
            len = -1;
    }
    return len;
}
