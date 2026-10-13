/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2_GetBG0ScrPtr func_0214a314
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void *G2_GetBG0ScrPtr(){
    u32 temp = (u32)(((reg_G2_BG0CNT & 0x1F00) >> 0x8) << 0xB);
    return (void *)(0x6000000 + (((reg_GX_DISPCNT & 0x38000000) >> 0x1B) << 0x10) + temp);
}
