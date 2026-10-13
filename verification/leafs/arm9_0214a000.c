/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2_GetBG1CharPtr GetVramBg1BaseOffset_Top
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void *G2_GetBG1CharPtr(){
    u32 temp = (u32)(((reg_G2_BG1CNT & 0x3C) >> 0x2) << 0xE);
    return (void *)(0x6000000 + (((reg_GX_DISPCNT & 0x7000000) >> 0x18) << 0x10) + temp);
}
