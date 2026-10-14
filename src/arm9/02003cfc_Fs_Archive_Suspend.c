/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_SleepThread Os_Thread_Sleep
#define OS_RestoreInterrupts Os_RestoreIrq
#define FS_SuspendArchive Fs_Archive_Suspend
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"

#pragma thumb off
BOOL FS_SuspendArchive(FSArchive * p_arc)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    const BOOL bak_stat = !FS_IsArchiveSuspended(p_arc);
    if (bak_stat)
    {
        if (FSi_IsArchiveRunning(p_arc))
        {
            p_arc->flag |= FS_ARCHIVE_FLAG_SUSPENDING;
            do {
                OS_SleepThread(&p_arc->stat_q);
            } while (FSi_IsArchiveSuspending(p_arc));
        }
        else
        {
            p_arc->flag |= FS_ARCHIVE_FLAG_SUSPEND;
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return bak_stat;
}
