/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_GetPackedName Fs_PackArchiveMountName
#include "FS_archive.h"
#include "FS_command.h"
#include "FSi_util.h"
#include "MI_memory.h"
#include "MI_byteAccess.h"
#include "OS_printf.h"
#include "code32.h"

#pragma thumb off
u32 FSi_GetPackedName(const char * name, int name_len)
{
    u32 ret = 0;
    if (name_len <= FS_ARCHIVE_NAME_LEN_MAX)
    {
        int i = 0;
        for (; i < name_len; i++)
        {
            u32 c = MI_ReadByte(name + i);
            if (!c)
                break;
            c = (u32)(c - 'A');
            if (c <= (u32)('Z' - 'A'))
                c = (u32)(c + 'a');
            else
                c = (u32)(c + 'A');
            ret |= (u32)(c << (i * 8));
        }
    }
    return ret;
}
