#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/Unknown/code_020e5668.h"
#include "Main/MapObjects/send_obj_shadow.h"

void SetShadowPositionXZ(ShadowMatrix *shadow, Vec3 *position) {
    shadow->mMatrix.mRows[3].x = position->x >> 4;
    shadow->mMatrix.mRows[3].z = position->z >> 4;
}

void SetShadowPositionRaised(ShadowMatrix *shadow, Vec3 *position) {
    shadow->mMatrix.mRows[3].x = position->x >> 4;
    shadow->mMatrix.mRows[3].y = (position->y + 0x1999) >> 4;
    shadow->mMatrix.mRows[3].z = position->z >> 4;
}
