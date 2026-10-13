/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2_GetBG3CharPtr GetVramBg3BaseOffset_Top
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void *G2_GetBG3CharPtr(){
    s32 temp1 = (s32)(reg_GX_DISPCNT & 0x7);
    u32 temp = reg_G2_BG3CNT;
    if (temp1 < 3 || (temp1 < 6 && !(temp & 0x80)))
    {
        u32 temp1 = (((reg_GX_DISPCNT & 0x7000000) >> 0x18) << 0x10);
        u32 temp2 = (temp & 0x3C) >> 2;
        return (void *)(0x6000000 + temp1 + (temp2 << 0xE));
    }
    else
    {
        return NULL;
    }
}
