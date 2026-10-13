/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "fx.h"

#include "nitro/types.h"
#include "registers.h"
#include "code32.h"

#pragma thumb off
fx64c FX_GetDivResultFx64c(){
    while (reg_CP_DIVCNT & 0x8000) {}
    return (fx64c)reg_CP_DIV_RESULT;
}
