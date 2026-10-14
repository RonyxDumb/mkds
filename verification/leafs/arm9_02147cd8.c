/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FX_ModS32 func_02147cd8
#include "fx.h"

#include "nitro/types.h"
#include "registers.h"
#include "code32.h"

#pragma thumb off
fx32 FX_ModS32(fx32 num, fx32 mod){
    reg_CP_DIVCNT = 0x0;
    *(REGType32v *)&reg_CP_DIV_NUMER = (u32)num; //32bit write for some reason
    reg_CP_DIV_DENOM = (u32)mod;
    while (reg_CP_DIVCNT & 0x8000) {}
    return (fx32)(*(REGType32v *)&reg_CP_DIVREM_RESULT);
}
