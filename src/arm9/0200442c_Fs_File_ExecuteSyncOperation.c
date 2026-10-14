/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_TranslateCommand Fs_File_DoExecuteOperation
#define FSi_ReleaseCommand Fs_File_ReleaseOperation
#define FSi_NextCommand Fs_Archive_HandleNextOperation
#define FSi_ExecuteAsyncCommand Fs_File_ExecuteAsyncOperation
#define FSi_ExecuteSyncCommand Fs_File_ExecuteSyncOperation
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"
extern FSFile * FSi_NextCommand(FSArchive * p_arc);
extern void FSi_ExecuteAsyncCommand(FSFile * p_file);
#pragma thumb off
BOOL FSi_ExecuteSyncCommand(FSFile * p_file)
{
    FSFile * p_target;
    FSResult ret = FSi_TranslateCommand(p_file, p_file->command);
    FSi_ReleaseCommand(p_file, ret);
    p_target = FSi_NextCommand(p_file->arc);
    if (p_target)
        FSi_ExecuteAsyncCommand(p_target);
    return FS_IsSucceeded(p_file);
}
