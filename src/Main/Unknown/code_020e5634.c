#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020e516c.h"

void SetShadowPositionRaised(ShadowMatrix *shadow, Vec3 *position) {
    shadow->mMatrix[9] = position->x >> 4;
    shadow->mMatrix[10] = (position->y + 0x1999) >> 4;
    shadow->mMatrix[11] = position->z >> 4;
}
