/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_WakeupThread Os_Thread_WakeUp
#define OS_RestoreInterrupts Os_RestoreIrq
#define FSi_TranslateCommand Fs_File_DoExecuteOperation
#define FSi_NextCommand Fs_Archive_HandleNextOperation
#define FSi_ExecuteAsyncCommand Fs_File_ExecuteAsyncOperation
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"
extern FSFile * FSi_NextCommand(FSArchive * p_arc);
#pragma thumb off
void FSi_ExecuteAsyncCommand(FSFile * p_file)
{
    FSArchive *const p_arc = p_file->arc;
    while (p_file)
    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        p_file->stat |= FS_FILE_STATUS_OPERATING;
        if (FS_IsFileSyncMode(p_file))
        {
            OS_WakeupThread(p_file->queue);
            (void)OS_RestoreInterrupts(bak_psr);
            break;
        }
        p_file->stat |= FS_FILE_STATUS_ASYNC;
        (void)OS_RestoreInterrupts(bak_psr);
        if (FSi_TranslateCommand(p_file, p_file->command) == FS_RESULT_PROC_ASYNC)
            break;
        p_file = FSi_NextCommand(p_arc);
    }
}
