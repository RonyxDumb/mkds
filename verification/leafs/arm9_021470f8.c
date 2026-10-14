/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MTX_ScaleApply33 func_021470f8
#include "nitro/types.h"
#include "fx.h"
#include "code32.h"

#include "code16.h" //following funcs are thumb

#pragma thumb off
void MTX_ScaleApply33(struct Mtx33 *mtx, struct Mtx33 *dst, fx32 x, fx32 y, fx32 z){
    dst->_[0] = (fx32)(((fx64)x * mtx->_[0]) >> FX32_INT_SHIFT);
    dst->_[1] = (fx32)(((fx64)x * mtx->_[1]) >> FX32_INT_SHIFT);
    dst->_[2] = (fx32)(((fx64)x * mtx->_[2]) >> FX32_INT_SHIFT);
    dst->_[3] = (fx32)(((fx64)y * mtx->_[3]) >> FX32_INT_SHIFT);
    dst->_[4] = (fx32)(((fx64)y * mtx->_[4]) >> FX32_INT_SHIFT);
    dst->_[5] = (fx32)(((fx64)y * mtx->_[5]) >> FX32_INT_SHIFT);
    dst->_[6] = (fx32)(((fx64)z * mtx->_[6]) >> FX32_INT_SHIFT);
    dst->_[7] = (fx32)(((fx64)z * mtx->_[7]) >> FX32_INT_SHIFT);
    dst->_[8] = (fx32)(((fx64)z * mtx->_[8]) >> FX32_INT_SHIFT);
}
