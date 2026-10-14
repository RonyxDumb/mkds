/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_VSNPrintf SDK_data_0200d118
#define OS_VSPrintf Util_VSPrintF
#include "nitro/types.h"
#include "OS_printf.h"
#include "code32.h"
extern s32 OS_VSNPrintf(s8 *buffer, s32 bufsz, const s8 *format, void *args);
s32 OS_VSPrintf(s8 *buffer, const s8 *format, void *args)
{
    return OS_VSNPrintf(buffer, 0x7FFFFFFF, format, args);
}
