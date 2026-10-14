/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FX_DivS32 Fx_DivS32
#include "fx.h"

#include "nitro/types.h"
#include "registers.h"
#include "code32.h"

#pragma thumb off
fx32 FX_DivS32(fx32 numerator, fx32 denominator){
    reg_CP_DIVCNT = 0x0;
    *(REGType32v *)&reg_CP_DIV_NUMER = (u32)numerator; //32bit write for some reason
    reg_CP_DIV_DENOM = (u32)denominator;
    while (reg_CP_DIVCNT & 0x8000) {}
    return (fx32)(*(REGType32v *)&reg_CP_DIV_RESULT);
}
