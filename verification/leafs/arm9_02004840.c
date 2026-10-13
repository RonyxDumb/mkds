/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_SeekFile Fs_File_Seek
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"

#pragma thumb off
BOOL FS_SeekFile(FSFile * p_file, s32 offset, FSSeekFileMode origin)
{
    switch (origin)
    {
    case FS_SEEK_SET:
        offset += p_file->prop.file.top;
        break;
    case FS_SEEK_CUR:
        offset += p_file->prop.file.pos;
        break;
    case FS_SEEK_END:
        offset += p_file->prop.file.bottom;
        break;
    default:
        return FALSE;
    }
    if (offset < (s32)p_file->prop.file.top)
        offset = (s32)p_file->prop.file.top;
    if (offset > (s32)p_file->prop.file.bottom)
        offset = (s32)p_file->prop.file.bottom;
    p_file->prop.file.pos = (u32)offset;
    return TRUE;
}
