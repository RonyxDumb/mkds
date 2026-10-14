/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "fx.h"

#include "nitro/types.h"
#include "registers.h"
#include "code32.h"

#pragma thumb off
fx32 FX_GetDivResult(){
    while (reg_CP_DIVCNT & 0x8000) {}
    return (fx32)((reg_CP_DIV_RESULT + (1 << (0x14 - 1))) >> 0x14);
}
