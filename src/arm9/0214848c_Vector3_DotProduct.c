/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_DotProduct Vector3_DotProduct
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
fx32 VEC_DotProduct(const struct Vecx32 *a, const struct Vecx32 *b){
    return (fx32)(((fx64)a->x * b->x + (fx64)a->y * b->y + (fx64)a->z * b->z + (1 << (FX64_INT_SHIFT - 1))) >> FX64_INT_SHIFT);
}
