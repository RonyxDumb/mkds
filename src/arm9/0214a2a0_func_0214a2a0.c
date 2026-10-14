/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G2S_GetBG1ScrPtr func_0214a2a0
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void *G2S_GetBG1ScrPtr(){
    return (void *)(0x6200000 + (((reg_G2S_DB_BG1CNT & 0x1F00) >> 0x8) << 0xB));
}
