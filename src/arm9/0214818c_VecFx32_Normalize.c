/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_Normalize VecFx32_Normalize
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
void VEC_Normalize(const struct Vecx32 *a, struct Vecx32 *dst){
    fx64 l2 = (fx64)a->x * a->x;
    l2 += (fx64)a->y * a->y;
    l2 += (fx64)a->z * a->z;
    //1/sqrt(l) is computed by calculating sqrt(l)*(1/l)
    reg_CP_DIVCNT = 0x2;
    reg_CP_DIV_NUMER = 0x0100000000000000;
    reg_CP_DIV_DENOM = (u64)l2;
    reg_CP_SQRTCNT = 0x1;
    reg_CP_SQRT_PARAM = (u64)(l2 * 4);
    while (reg_CP_SQRTCNT & 0x8000) {} //wait for sqrt to finish
    fx32 sqrtresult = (fx32)reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {} //wait for division to finish
    l2 = (fx64)reg_CP_DIV_RESULT;
    l2 = sqrtresult * l2;
    dst->x = (fx32)((l2 * a->x + (1LL << (0x2D - 1))) >> 0x2D);
    dst->y = (fx32)((l2 * a->y + (1LL << (0x2D - 1))) >> 0x2D);
    dst->z = (fx32)((l2 * a->z + (1LL << (0x2D - 1))) >> 0x2D);
}
