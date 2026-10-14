/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RtcBCD2HEX func_0214d964
#include <nitro/os.h>
#include <nitro/rtc.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
u32 RtcBCD2HEX (u32 bcd)
{
    u32 hex = 0;
    s32 i;
    s32 w;

    for (i = 0; i < 8; i++) {
        if (((bcd >> (i * 4)) & 0x0000000f) >= 0x0a) {
            return hex;
        }
    }

    for (i = 0, w = 1; i < 8; i++, w *= 10) {
        hex += (((bcd >> (i * 4)) & 0x0000000f) * w);
    }

    return hex;
}
