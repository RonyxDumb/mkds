/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_Fx16DotProduct VecFx16_DotProduct
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
fx32 VEC_Fx16DotProduct(struct Vecx16 *a, struct Vecx16 *b){
    fx32 temp1, temp2;
    temp1 = (a->x * b->x) + (a->y * b->y);
    temp2 = (a->z * b->z) + (1 << (FX64_INT_SHIFT - 1));
    return (fx32)(((fx64)temp1 + temp2) >> FX64_INT_SHIFT);
}
