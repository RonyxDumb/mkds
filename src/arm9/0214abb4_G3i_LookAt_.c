/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_Normalize VecFx32_Normalize
#define VEC_CrossProduct VecFx32_CrossProduct
#define VEC_DotProduct Vector3_DotProduct
#include "nitro/types.h"
#include "registers.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G3i_LookAt_(const struct Vecx32 *a, const struct Vecx32 *b, const struct Vecx32 *c, BOOL load, struct Mtx43 *mtx){
    struct Vecx32 temp, temp1, temp2;
    fx32 c1, c2, c3;
    vu32 *reg_ptr;
    temp.x = a->x - c->x;
    temp.y = a->y - c->y;
    temp.z = a->z - c->z;
    VEC_Normalize(&temp, &temp);
    VEC_CrossProduct(b, &temp, &temp1);
    VEC_Normalize(&temp1, &temp1);
    VEC_CrossProduct(&temp, &temp1, &temp2);
    if (load)
    {
        reg_G3_MTX_MODE = 0x2;
        reg_ptr = (vu32 *)&reg_G3_MTX_LOAD_4x3;
        *reg_ptr = (vu32)temp1.x;
        *reg_ptr = (vu32)temp2.x;
        *reg_ptr = (vu32)temp.x;
        *reg_ptr = (vu32)temp1.y;
        *reg_ptr = (vu32)temp2.y;
        *reg_ptr = (vu32)temp.y;
        *reg_ptr = (vu32)temp1.z;
        *reg_ptr = (vu32)temp2.z;
        *reg_ptr = (vu32)temp.z;
    }
    c1 = -VEC_DotProduct(a, &temp1);
    c2 = -VEC_DotProduct(a, &temp2);
    c3 = -VEC_DotProduct(a, &temp);
    if (load)
    {
        *reg_ptr = (vu32)c1;
        *reg_ptr = (vu32)c2;
        *reg_ptr = (vu32)c3;
    }
    if (mtx)
    {
        mtx->_[0] = temp1.x;
        mtx->_[1] = temp2.x;
        mtx->_[2] = temp.x;
        mtx->_[3] = temp1.y;
        mtx->_[4] = temp2.y;
        mtx->_[5] = temp.y;
        mtx->_[6] = temp1.z;
        mtx->_[7] = temp2.z;
        mtx->_[8] = temp.z;
        mtx->_[9] = c1;
        mtx->_[10] = c2;
        mtx->_[11] = c3;
    }
}
