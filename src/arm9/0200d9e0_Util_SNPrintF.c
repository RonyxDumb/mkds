/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_VSNPrintf Util_VSNPrintF
#define OS_SNPrintf Util_SNPrintF
#include "nitro/types.h"
#include "OS_printf.h"
#include "code32.h"
extern s32 OS_VSNPrintf(s8 *buffer, s32 bufsz, const s8 *format, void *args);
s32 OS_SNPrintf(s8 *buffer, s32 bufsz, const s8 *format, ...)
{
    void *args = (void *)((u32 *)((u32)&format & ~0x3) + 1); // hack since mwccarm doesn't have <stdarg.h> apparently
    return OS_VSNPrintf(buffer, bufsz, format, args);
}
