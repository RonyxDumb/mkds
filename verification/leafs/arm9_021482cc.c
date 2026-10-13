/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_Mag VecFx32_Norm
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
fx32 VEC_Mag(struct Vecx32 *a){
    fx64 l2 = (fx64)a->x * a->x;
    l2 += (fx64)a->y * a->y;
    l2 += (fx64)a->z * a->z;
    reg_CP_SQRTCNT = 0x1;
    reg_CP_SQRT_PARAM = (u64)(l2 * 4);
    while (reg_CP_SQRTCNT & 0x8000) {} //wait for coprocessor to finish
    return ((fx32)reg_CP_SQRT_RESULT + 1) >> 1;
}
