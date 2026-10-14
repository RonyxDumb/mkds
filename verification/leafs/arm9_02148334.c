/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_Fx16CrossProduct VecFx16_CrossProduct
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
void VEC_Fx16CrossProduct(struct Vecx16 *a, struct Vecx16 *b, struct Vecx16 *dst){
    fx32 x, y, z;
    x = ((a->y * b->z - a->z * b->y + (1 << (FX64_INT_SHIFT - 1))) >> FX64_INT_SHIFT);
    y = ((a->z * b->x - a->x * b->z + (1 << (FX64_INT_SHIFT - 1))) >> FX64_INT_SHIFT);
    z = ((a->x * b->y - a->y * b->x + (1 << (FX64_INT_SHIFT - 1))) >> FX64_INT_SHIFT);
    dst->x = (fx16)x;
    dst->y = (fx16)y;
    dst->z = (fx16)z;
}
