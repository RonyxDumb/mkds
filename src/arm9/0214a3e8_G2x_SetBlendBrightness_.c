/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G2x_SetBlendBrightness_(volatile u16 *ptr, fx32 a, fx32 brightness){
    if (brightness < 0)
    {
        ptr[0] = (u16)(a | 0xC0);
        ptr[2] = (u16)(-brightness);
    }
    else
    {
        ptr[0] = (u16)(a | 0x80);
        ptr[2] = (u16)brightness;
    }
}
