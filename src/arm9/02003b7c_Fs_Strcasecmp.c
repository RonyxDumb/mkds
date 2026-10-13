/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_StrNICmp Fs_Strcasecmp
#include "nitro.h"
#include "FS_file.h"
#include "FS_command.h"
#include "MI_byteAccess.h"
#include "MI_memory.h"
#include "FSi_util.h"
#include "FS_command_default.h"
#include "code32.h"

#pragma thumb off
u32 FSi_StrNICmp(const char * str1, const char * str2, u32 len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        u32 c = (u32)(MI_ReadByte(str1 + i) - 'A');
        u32 d = (u32)(MI_ReadByte(str2 + i) - 'A');
        if (c <= 'Z' - 'A')
            c += 'a' - 'A';
        if (d <= 'Z' - 'A')
            d += 'a' - 'A';
        if (c != d)
            return c - d;
    }
    return 0;
}
