/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2S_GetBG2CharPtr GetVramBg2BaseOffset_Bottom
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void *G2S_GetBG2CharPtr(){
    s32 temp1 = (s32)(reg_GXS_DB_DISPCNT & 0x7);
    u32 temp = reg_G2S_DB_BG2CNT;
    if (temp1 < 5 || !(temp & 0x80))
    {
        u32 temp2 = ((temp & 0x3C) >> 2) << 0xE;
        return (void *)(0x6200000 + temp2);
    }
    else
    {
        return NULL;
    }
}
