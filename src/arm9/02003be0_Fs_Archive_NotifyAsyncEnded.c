/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_ReleaseCommand Fs_File_ReleaseOperation
#define FSi_NextCommand Fs_Archive_HandleNextOperation
#define FSi_ExecuteAsyncCommand Fs_File_ExecuteAsyncOperation
#define OS_DisableInterrupts Os_DisableIrq
#define OS_WakeupThread Os_Thread_WakeUp
#define OS_RestoreInterrupts Os_RestoreIrq
#define FS_NotifyArchiveAsyncEnd Fs_Archive_NotifyAsyncEnded
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
void FS_NotifyArchiveAsyncEnd(FSArchive *p_arc, FSResult ret)
{
    if (FSi_IsArchiveAsync(p_arc))
    {
        FSFile *p_file = p_arc->list.next;
        p_arc->flag &= ~FS_ARCHIVE_FLAG_IS_ASYNC;
        FSi_ReleaseCommand(p_file, ret);
        p_file = FSi_NextCommand(p_arc);
        if (p_file)
            FSi_ExecuteAsyncCommand(p_file);
    }
    else
    {
        FSFile *p_file = p_arc->list.next;
        OSIntrMode bak_psr = OS_DisableInterrupts();
        p_file->error = ret;
        p_arc->flag &= ~FS_ARCHIVE_FLAG_IS_SYNC;
        OS_WakeupThread(&p_arc->sync_q);
        (void)OS_RestoreInterrupts(bak_psr);
    }
}
