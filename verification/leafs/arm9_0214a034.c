/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2S_GetBG0CharPtr GetVramBg0BaseOffset_Bottom
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void *G2S_GetBG0CharPtr(){
    return (void *)(0x6200000 + (((reg_G2S_DB_BG0CNT & 0x3C) >> 0x2) << 0xE));
}
