/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_WriteFileCommand Fs_File_DefaultOperation_WriteFile
#include "nitro.h"
#include "FS_file.h"
#include "FS_command.h"
#include "MI_byteAccess.h"
#include "MI_memory.h"
#include "FSi_util.h"
#include "FS_command_default.h"
#include "code32.h"

#pragma thumb off
FSResult FSi_WriteFileCommand(FSFile * p_file)
{
    FSArchive *const p_arc = p_file->arc;
    const u32 pos = p_file->prop.file.pos;
    const u32 len = p_file->arg.writefile.len;
    const void *const src = p_file->arg.writefile.src;
    p_file->prop.file.pos += len;
    return (*p_arc->write_func)(p_arc, src, pos, len);
}
