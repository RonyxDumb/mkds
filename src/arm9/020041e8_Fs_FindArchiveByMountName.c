/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_GetPackedName Fs_PackArchiveMountName
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define arc_list SDK_data_0216f340
#define FS_FindArchive Fs_FindArchiveByMountName
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"
extern u32 FSi_GetPackedName(const char * name, int name_len);
extern FSArchive * arc_list;
#pragma thumb off
FSArchive * const FS_FindArchive(const char * name, int name_len)
{
    u32 pack = FSi_GetPackedName(name, name_len);
    OSIntrMode bak_psr = OS_DisableInterrupts();
    FSArchive * p_arc = arc_list;
    while (p_arc && (p_arc->name.pack != pack))
        p_arc = p_arc->next;
    (void)OS_RestoreInterrupts(bak_psr);
    return p_arc;
}
