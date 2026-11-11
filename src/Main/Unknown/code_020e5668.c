#include "Main/Unknown/code_020e5668.h"
#include "Main/Unknown/code_020e516c.h"

void SetShadowPositionXZ(ShadowMatrix *shadow, Vec3 *position) {
    shadow->mMatrix.mRows[3].x = position->x >> 4;
    shadow->mMatrix.mRows[3].z = position->z >> 4;
}
