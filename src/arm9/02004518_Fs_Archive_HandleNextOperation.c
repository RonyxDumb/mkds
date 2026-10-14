/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define FSi_ReleaseCommand Fs_File_ReleaseOperation
#define OS_RestoreInterrupts Os_RestoreIrq
#define OS_WakeupThread Os_Thread_WakeUp
#define FS_InitFile Fs_File_Initialize
#define FSi_NextCommand Fs_Archive_HandleNextOperation
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"

#pragma thumb off
FSFile * FSi_NextCommand(FSArchive * p_arc)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    if (FSi_IsArchiveCanceling(p_arc))
    {
        FSFile *p, *q;
        p_arc->flag &= ~FS_ARCHIVE_FLAG_CANCELING;
        for (p = p_arc->list.next; p; p = q)
        {
            q = p->link.next;
            if (FS_IsCanceling(p))
            {
                if (p_arc->list.next == p)
                    p_arc->list.next = q;
                FSi_ReleaseCommand(p, FS_RESULT_CANCELED);
                if (!q)
                    q = p_arc->list.next;
            }
        }
    }
    if (!FSi_IsArchiveSuspending(p_arc) && !FS_IsArchiveSuspended(p_arc))
    {
        FSFile * p_file = p_arc->list.next;
        if (p_file != NULL)
        {
            const BOOL is_start = !FSi_IsArchiveRunning(p_arc);
            if (is_start)
                p_arc->flag |= FS_ARCHIVE_FLAG_RUNNING;
            (void)OS_RestoreInterrupts(bak_psr);
            if (is_start)
            {
                if ((p_arc->proc_flag & FS_ARCHIVE_PROC_ACTIVATE) != 0)
                    (void)((*p_arc->proc) (p_file, FS_COMMAND_ACTIVATE));
            }
            bak_psr = OS_DisableInterrupts();
            p_file->stat |= FS_FILE_STATUS_OPERATING;
            if (FS_IsFileSyncMode(p_file))
            {
                OS_WakeupThread(p_file->queue);
                (void)OS_RestoreInterrupts(bak_psr);
                return NULL;
            }
            (void)OS_RestoreInterrupts(bak_psr);
            return p_file;
        }
    }
    if (FSi_IsArchiveRunning(p_arc))
    {
        p_arc->flag &= ~FS_ARCHIVE_FLAG_RUNNING;
        if (p_arc->proc_flag & FS_ARCHIVE_PROC_IDLE)
        {
            FSFile tmp;
            FS_InitFile(&tmp);
            tmp.arc = p_arc;
            (void)((*p_arc->proc)(&tmp, FS_COMMAND_IDLE));
        }
    }
    if (FSi_IsArchiveSuspending(p_arc))
    {
        p_arc->flag &= ~FS_ARCHIVE_FLAG_SUSPENDING;
        p_arc->flag |= FS_ARCHIVE_FLAG_SUSPEND;
        OS_WakeupThread(&p_arc->stat_q);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return NULL;
}
