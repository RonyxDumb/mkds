#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020e516c.h"

void oshd_setPosition(ShadowMatrix *shadow, Vec3 *position) {
    shadow->field0[9] = position->x >> 4;
    shadow->field0[10] = (position->y + 0x1999) >> 4;
    shadow->field0[11] = position->z >> 4;
}
