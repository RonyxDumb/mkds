/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "fx.h"

#include "nitro/types.h"
#include "registers.h"
#include "code32.h"

#pragma thumb off
void FX_InvAsync(fx32 x){
    reg_CP_DIVCNT = 0x1;
    reg_CP_DIV_NUMER = (fx64)0x00001000 << 32;
    reg_CP_DIV_DENOM = (u32)x;
}
