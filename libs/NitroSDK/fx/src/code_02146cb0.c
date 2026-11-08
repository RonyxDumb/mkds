#include "code_02146cb0.h"

#pragma thumb on
// Sets the four words at dst to the 2x2 rotation matrix (cosVal, sinVal, -sinVal, cosVal).
void MTX_Rot22_(MtxFx22 *dst, s32 sinVal, s32 cosVal) {
    dst->mUnk_00[0] = cosVal;
    dst->mUnk_00[1] = sinVal;
    dst->mUnk_00[2] = -sinVal;
    dst->mUnk_00[3] = cosVal;
}
#pragma thumb off
