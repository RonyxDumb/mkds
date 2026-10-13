/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define FSi_NextCommand Fs_Archive_HandleNextOperation
#define OS_RestoreInterrupts Os_RestoreIrq
#define FSi_ExecuteAsyncCommand Fs_File_ExecuteAsyncOperation
#define FS_ResumeArchive Fs_Archive_Resume
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
BOOL FS_ResumeArchive(FSArchive * p_arc)
{
    FSFile * p_target = NULL;
    OSIntrMode bak_psr = OS_DisableInterrupts();
    const BOOL bak_stat = !FS_IsArchiveSuspended(p_arc);
    if (!bak_stat)
    {
        p_arc->flag &= ~FS_ARCHIVE_FLAG_SUSPEND;
        p_target = FSi_NextCommand(p_arc);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    if (p_target)
        FSi_ExecuteAsyncCommand(p_target);
    return bak_stat;
}
