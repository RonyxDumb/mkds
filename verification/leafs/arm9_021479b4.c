/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MTX_Concat44 func_021479b4
#include "nitro/types.h"
#include "MI_memory.h"
#include "fx.h"
#include "code32.h"

#include "code16.h" //following funcs are thumb

#pragma thumb off
void MTX_Concat44(struct Mtx44 *a, struct Mtx44 *b, struct Mtx44 *c){
    struct Mtx44 temp;
    struct Mtx44 *dst;
    fx32 a0, a1, a2, a3;
    fx32 b0, b1, b2, b3;

    if (c == b)
        dst = &temp;
    else
        dst = c;

    a0 = a->_[0];
    a1 = a->_[1];
    a2 = a->_[2];
    a3 = a->_[3];
    dst->_[0] =  (fx32)(((fx64)a0  * b->_[0] + (fx64)a1  * b->_[4] + (fx64)a2  * b->_[8]  + (fx64)a3  * b->_[12]) >> FX32_INT_SHIFT);
    dst->_[1] =  (fx32)(((fx64)a0  * b->_[1] + (fx64)a1  * b->_[5] + (fx64)a2  * b->_[9]  + (fx64)a3  * b->_[13]) >> FX32_INT_SHIFT);
    dst->_[3] =  (fx32)(((fx64)a0  * b->_[3] + (fx64)a1  * b->_[7] + (fx64)a2  * b->_[11] + (fx64)a3  * b->_[15]) >> FX32_INT_SHIFT);
    b0 = b->_[2];
    b1 = b->_[6];
    b2 = b->_[10];
    b3 = b->_[14];
    dst->_[2] =  (fx32)(((fx64)a0  * b0 + (fx64)a1  * b1 + (fx64)a2  * b2 + (fx64)a3  * b3) >> FX32_INT_SHIFT);
    a0 = a->_[4];
    a1 = a->_[5];
    a2 = a->_[6];
    a3 = a->_[7];
    dst->_[6] =  (fx32)(((fx64)a0  * b0 + (fx64)a1  * b1 + (fx64)a2  * b2 + (fx64)a3  * b3) >> FX32_INT_SHIFT);
    dst->_[5] =  (fx32)(((fx64)a0  * b->_[1] + (fx64)a1  * b->_[5] + (fx64)a2  * b->_[9]  + (fx64)a3  * b->_[13]) >> FX32_INT_SHIFT);
    dst->_[7] =  (fx32)(((fx64)a0  * b->_[3] + (fx64)a1  * b->_[7] + (fx64)a2  * b->_[11] + (fx64)a3  * b->_[15]) >> FX32_INT_SHIFT);
    b0 = b->_[0];
    b1 = b->_[4];
    b2 = b->_[8];
    b3 = b->_[12];
    dst->_[4] =  (fx32)(((fx64)a0  * b0 + (fx64)a1  * b1 + (fx64)a2  * b2  + (fx64)a3  * b3) >> FX32_INT_SHIFT);
    a0 = a->_[8];
    a1 = a->_[9];
    a2 = a->_[10];
    a3 = a->_[11];
    dst->_[8] =  (fx32)(((fx64)a0  * b0 + (fx64)a1  * b1 + (fx64)a2 * b2  + (fx64)a3 * b3) >> FX32_INT_SHIFT);
    dst->_[9] =  (fx32)(((fx64)a0  * b->_[1] + (fx64)a1  * b->_[5] + (fx64)a2 * b->_[9]  + (fx64)a3 * b->_[13]) >> FX32_INT_SHIFT);
    dst->_[11] = (fx32)(((fx64)a0  * b->_[3] + (fx64)a1  * b->_[7] + (fx64)a2 * b->_[11] + (fx64)a3 * b->_[15]) >> FX32_INT_SHIFT);
    b0 = b->_[2];
    b1 = b->_[6];
    b2 = b->_[10];
    b3 = b->_[14];
    dst->_[10] = (fx32)(((fx64)a0  * b0 + (fx64)a1  * b1 + (fx64)a2 * b2 + (fx64)a3 * b3) >> FX32_INT_SHIFT);
    a0 = a->_[12];
    a1 = a->_[13];
    a2 = a->_[14];
    a3 = a->_[15];
    dst->_[14] = (fx32)(((fx64)a0 * b0 + (fx64)a1 * b1 + (fx64)a2 * b2 + (fx64)a3 * b3) >> FX32_INT_SHIFT);
    dst->_[13] = (fx32)(((fx64)a0 * b->_[1] + (fx64)a1 * b->_[5] + (fx64)a2 * b->_[9]  + (fx64)a3 * b->_[13]) >> FX32_INT_SHIFT);
    dst->_[12] = (fx32)(((fx64)a0 * b->_[0] + (fx64)a1 * b->_[4] + (fx64)a2 * b->_[8]  + (fx64)a3 * b->_[12]) >> FX32_INT_SHIFT);
    dst->_[15] = (fx32)(((fx64)a0 * b->_[3] + (fx64)a1 * b->_[7] + (fx64)a2 * b->_[11] + (fx64)a3 * b->_[15]) >> FX32_INT_SHIFT);
    if (dst == &temp)
        *c = temp;
}
