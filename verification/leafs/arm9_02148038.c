/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_Fx16Normalize VecFx16_Normalize
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
void VEC_Fx16Normalize(struct Vecx16 *a, struct Vecx16 *dst){
    fx64 l2 = a->x * a->x;
    l2 += a->y * a->y;
    l2 += a->z * a->z;
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
    dst->x = (fx16)((l2 * a->x + (1LL << (0x2D - 1))) >> 0x2D);
    dst->y = (fx16)((l2 * a->y + (1LL << (0x2D - 1))) >> 0x2D);
    dst->z = (fx16)((l2 * a->z + (1LL << (0x2D - 1))) >> 0x2D);
}
