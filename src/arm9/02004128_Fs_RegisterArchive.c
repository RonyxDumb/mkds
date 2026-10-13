/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define FS_FindArchive Fs_FindArchiveByMountName
#define FSi_GetPackedName Fs_PackArchiveMountName
#define OS_RestoreInterrupts Os_RestoreIrq
#define arc_list SDK_data_0216f340
#define current_dir_pos SDK_data_0216f344
#define FS_RegisterArchiveName Fs_RegisterArchive
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"
extern FSArchive * const FS_FindArchive(const char * name, int name_len);
extern u32 FSi_GetPackedName(const char * name, int name_len);
extern FSArchive * arc_list;
extern FSDirPos current_dir_pos;
#pragma thumb off
BOOL FS_RegisterArchiveName(FSArchive * p_arc, const char * name, int name_len)
{
    BOOL ret = FALSE;
    OSIntrMode bak_psr = OS_DisableInterrupts();
    if (!FS_FindArchive(name, name_len))
    {
        FSArchive * p_tail = arc_list;
        if (!p_tail)
        {
            arc_list = p_arc;
            current_dir_pos.arc = p_arc;
            current_dir_pos.pos = 0;
            current_dir_pos.index = 0;
            current_dir_pos.own_id = 0;
        }
        else
        {
            while (p_tail->next)
                p_tail = p_tail->next;
            p_tail->next = p_arc;
            p_arc->prev = p_tail;
        }
        p_arc->name.pack = FSi_GetPackedName(name, name_len);
        p_arc->flag |= FS_ARCHIVE_FLAG_REGISTER;
        ret = TRUE;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return ret;
}
