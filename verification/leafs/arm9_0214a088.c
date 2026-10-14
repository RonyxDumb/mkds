/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2S_GetBG3ScrPtr func_0214a088
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void *G2S_GetBG3ScrPtr(){
    u32 temp12 = (reg_GXS_DB_DISPCNT & 0x7);
    u32 temp3 = reg_G2S_DB_BG3CNT;
    u32 temp1 = ((temp3 & 0x1F00) >> 0x8);
    switch (temp12)
    {
        case 0:
        case 1:
        case 2:
            return (void *)(0x6200000 + (temp1 << 0xB));
        case 3:
        case 4:
        case 5:
            if (temp3 & 0x80)
                return (void *)(0x6200000 + (temp1 << 0xE));
            else
                return (void *)(0x6200000 + (temp1 << 0xB));
        case 6:
            return NULL;
        default:
            return NULL;
    }
}
