/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_VSPrintf func_02138540
#define OS_SPrintf func_02138510
#include "nitro/types.h"
#include "OS_printf.h"
#include "code32.h"
extern s32 OS_VSPrintf(s8 *buffer, const s8 *format, void *args);
s32 OS_SPrintf(s8 *buffer, const s8 *format, ...)
{
    void *args = (void *)((u32 *)((u32)&format & ~0x3) + 1); // hack since mwccarm doesn't have <stdarg.h> apparently
    return OS_VSPrintf(buffer, format, args);
}
