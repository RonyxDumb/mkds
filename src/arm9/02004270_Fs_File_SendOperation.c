/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define FSi_ReleaseCommand Fs_File_ReleaseOperation
#define OS_RestoreInterrupts Os_RestoreIrq
#define FSi_ExecuteAsyncCommand Fs_File_ExecuteAsyncOperation
#define OS_SleepThread Os_Thread_Sleep
#define FSi_ExecuteSyncCommand Fs_File_ExecuteSyncOperation
#define FSi_SendCommand Fs_File_SendOperation
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"
extern void FSi_ExecuteAsyncCommand(FSFile * p_file);
extern BOOL FSi_ExecuteSyncCommand(FSFile * p_file);
#pragma thumb off
BOOL FSi_SendCommand(FSFile * p_file, FSCommandType command)
{
    FSArchive * p_arc = p_file->arc;
    const int bit = 1 << command;
    p_file->command = command;
    p_file->error = FS_RESULT_BUSY;
    p_file->stat |= FS_FILE_STATUS_BUSY;
    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if (FSi_IsArchiveUnloading(p_arc))
        {
            FSi_ReleaseCommand(p_file, FS_RESULT_CANCELLED);
            (void)OS_RestoreInterrupts(bak_psr);
            return FALSE;
        }
        if ((bit & FS_ARCHIVE_PROC_SYNC) != 0)
            p_file->stat |= FS_FILE_STATUS_SYNC;
        FSi_AppendToList(p_file, (FSFile *)&p_arc->list);
        if (!FS_IsArchiveSuspended(p_arc) && !FSi_IsArchiveRunning(p_arc))
        {
            p_arc->flag |= FS_ARCHIVE_FLAG_RUNNING;
            (void)OS_RestoreInterrupts(bak_psr);
            if ((p_arc->proc_flag & FS_ARCHIVE_PROC_ACTIVATE))
                (void)((*p_arc->proc)(p_file, FS_COMMAND_ACTIVATE));
            bak_psr = OS_DisableInterrupts();
            p_file->stat |= FS_FILE_STATUS_OPERATING;
            if (!FS_IsFileSyncMode(p_file))
            {
                (void)OS_RestoreInterrupts(bak_psr);
                FSi_ExecuteAsyncCommand(p_file);
                return TRUE;
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
        else if (!FS_IsFileSyncMode(p_file))
        {
            (void)OS_RestoreInterrupts(bak_psr);
            return TRUE;
        }
        else
        {
            do
            {
                OS_SleepThread(p_file->queue);
            } while (!(p_file->stat & FS_FILE_STATUS_OPERATING));
            (void)OS_RestoreInterrupts(bak_psr);
        }
    }
    return FSi_ExecuteSyncCommand(p_file);
}
