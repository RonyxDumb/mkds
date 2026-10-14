/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_ReadFileCommand Fs_File_DefaultOperation_ReadFile
#include "nitro.h"
#include "FS_file.h"
#include "FS_command.h"
#include "MI_byteAccess.h"
#include "MI_memory.h"
#include "FSi_util.h"
#include "FS_command_default.h"
#include "code32.h"

#pragma thumb off
FSResult FSi_ReadFileCommand(FSFile * p_file)
{
    FSArchive *const p_arc = p_file->arc;
    const u32 pos = p_file->prop.file.pos;
    const u32 len = p_file->arg.readfile.len;
    void *const dst = p_file->arg.readfile.dst;
    p_file->prop.file.pos += len;
    return (*p_arc->read_func)(p_arc, dst, pos, len);
}
