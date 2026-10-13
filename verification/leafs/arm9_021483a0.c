/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_CrossProduct VecFx32_CrossProduct
#include "registers.h"
#include "fx.h"
#include "code32.h"

#pragma thumb off
void VEC_CrossProduct(const struct Vecx32 *a, const struct Vecx32 *b, struct Vecx32 *dst){
    fx32 x, y, z;
    x = (fx32)(((fx64)a->y * b->z - (fx64)a->z * b->y + (1 << (FX64_INT_SHIFT - 1))) >> FX64_INT_SHIFT);
    y = (fx32)(((fx64)a->z * b->x - (fx64)a->x * b->z + (1 << (FX64_INT_SHIFT - 1))) >> FX64_INT_SHIFT);
    z = (fx32)(((fx64)a->x * b->y - (fx64)a->y * b->x + (1 << (FX64_INT_SHIFT - 1))) >> FX64_INT_SHIFT);
    dst->x = x;
    dst->y = y;
    dst->z = z;
}
