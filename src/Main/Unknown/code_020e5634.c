#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020e516c.h"

void SetShadowPositionRaised(ShadowMatrix *shadow, Vec3 *position) {
    shadow->mMatrix.mUnk_00[3].x = position->x >> 4;
    shadow->mMatrix.mUnk_00[3].y = (position->y + 0x1999) >> 4;
    shadow->mMatrix.mUnk_00[3].z = position->z >> 4;
}
