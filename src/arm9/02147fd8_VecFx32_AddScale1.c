/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_MultAdd VecFx32_AddScale1
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
void VEC_MultAdd(fx32 factor, struct Vecx32  *a, struct Vecx32 *b, struct Vecx32 *dst){
    dst->x = (fx32)(((fx64)factor * a->x) >> FX32_INT_SHIFT) + b->x;
    dst->y = (fx32)(((fx64)factor * a->y) >> FX32_INT_SHIFT) + b->y;
    dst->z = (fx32)(((fx64)factor * a->z) >> FX32_INT_SHIFT) + b->z;
}
