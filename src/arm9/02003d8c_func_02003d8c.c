/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FS_SuspendArchive Fs_Archive_Suspend
#define FS_ResumeArchive Fs_Archive_Resume
#define FS_UnloadArchiveTables func_02003d8c
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
void * FS_UnloadArchiveTables(FSArchive * p_arc)
{
    void *ret = NULL;
    if (FS_IsArchiveLoaded(p_arc))
    {
        BOOL bak_stat = FS_SuspendArchive(p_arc);
        if (FS_IsArchiveTableLoaded(p_arc))
        {
            p_arc->flag &= ~FS_ARCHIVE_FLAG_TABLE_LOAD;
            ret = p_arc->load_mem;
            p_arc->load_mem = NULL;
            p_arc->fat = p_arc->fat_bak;
            p_arc->fnt = p_arc->fnt_bak;
            p_arc->table_func = p_arc->read_func;
        }
        if (bak_stat)
            (void)FS_ResumeArchive(p_arc);
    }
    return ret;
}
