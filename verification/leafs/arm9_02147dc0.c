/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "fx.h"

#include "nitro/types.h"
#include "registers.h"
#include "code32.h"

#pragma thumb off
fx32 FX_GetSqrtResult(){
    while (reg_CP_SQRTCNT & 0x8000) {}
    return (fx32)((reg_CP_SQRT_RESULT + (1 << (0xA - 1))) >> 0xA);
}
