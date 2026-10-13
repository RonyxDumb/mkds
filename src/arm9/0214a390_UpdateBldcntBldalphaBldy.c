/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2x_SetBlendBrightnessExt_ UpdateBldcntBldalphaBldy
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G2x_SetBlendBrightnessExt_(u16 *ptr, fx32 a, fx32 b, fx32 c, fx32 d, fx32 brightness){
    ptr[1] = (u16)(c | (d << 0x8));
    if (brightness < 0)
    {
        ptr[0] = (u16)(0xC0 | a | (b << 0x8));
        ptr[2] = (u16)(-brightness);
    }
    else
    {
        ptr[0] = (u16)(0x80 | a | (b << 0x8));
        ptr[2] = (u16)brightness;
    }
}
