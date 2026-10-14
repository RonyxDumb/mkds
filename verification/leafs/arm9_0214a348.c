/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2x_ChangeBlendBrightness_ func_0214a348
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G2x_ChangeBlendBrightness_(u16 *ptr, fx32 brightness){
    u32 temp = *ptr;
    if (brightness < 0)
    {
        if ((temp & 0xC0) == 0x80)
        {
            ptr[0] = (u16)((temp & ~0xC0) | 0xC0);
        }
        ptr[2] = (u16)(-brightness);
    }
    else
    {
        if ((temp & 0xC0) == 0xC0)
        {
            ptr[0] = (u16)((temp & ~0xC0) | 0x80);
        }
        ptr[2] = (u16)brightness;
    }
}
