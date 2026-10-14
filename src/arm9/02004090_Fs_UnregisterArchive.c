/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define current_dir_pos SDK_data_0216f344
#define arc_list SDK_data_0216f340
#define FS_ReleaseArchiveName Fs_UnregisterArchive
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"
extern FSDirPos current_dir_pos;
extern FSArchive * arc_list;
#pragma thumb off
void FS_ReleaseArchiveName(FSArchive * p_arc)
{
    if (p_arc->name.pack)
    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if (p_arc->next)
            p_arc->next->prev = p_arc->prev;
        if (p_arc->prev)
            p_arc->prev->next = p_arc->next;
        p_arc->name.pack = 0;
        p_arc->next = p_arc->prev = NULL;
        p_arc->flag &= ~FS_ARCHIVE_FLAG_REGISTER;
        if (current_dir_pos.arc == p_arc)
        {
            current_dir_pos.arc = arc_list;
            current_dir_pos.pos = 0;
            current_dir_pos.index = 0;
            current_dir_pos.own_id = 0;
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }
}
