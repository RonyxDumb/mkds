/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define FS_SuspendArchive Fs_Archive_Suspend
#define FSi_ReleaseCommand Fs_File_ReleaseOperation
#define FS_ResumeArchive Fs_Archive_Resume
#define OS_RestoreInterrupts Os_RestoreIrq
#define FS_UnloadArchive Fs_Archive_UnloadFatFnt
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"
extern BOOL FS_SuspendArchive(FSArchive * p_arc);
extern BOOL FS_ResumeArchive(FSArchive * p_arc);
#pragma thumb off
BOOL FS_UnloadArchive(FSArchive * p_arc)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    if (FS_IsArchiveLoaded(p_arc))
    {
        if (FS_IsArchiveTableLoaded(p_arc))
        {
            OS_TWarning("memory may leak. preloaded-table of archive \"%s\" (0x%08X)", p_arc->name.ptr, p_arc->load_mem);
        }
        {
            FSFile *p, *q;
            BOOL bak_state = FS_SuspendArchive(p_arc);
            p_arc->flag |= FS_ARCHIVE_FLAG_UNLOADING;
            for (p = p_arc->list.next; p; p = q)
            {
                q = p->link.next;
                FSi_ReleaseCommand(p, FS_RESULT_CANCELED);
            }
            p_arc->list.next = NULL;
            if (bak_state)
                (void)FS_ResumeArchive(p_arc);
        }
        p_arc->base = 0;
        p_arc->fat = 0;
        p_arc->fat_size = 0;
        p_arc->fnt = 0;
        p_arc->fnt_size = 0;
        p_arc->fat_bak = p_arc->fnt_bak = 0;
        p_arc->flag &= ~(FS_ARCHIVE_FLAG_CANCELING | FS_ARCHIVE_FLAG_LOADED | FS_ARCHIVE_FLAG_UNLOADING);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return TRUE;
}
