#include "Main/Unknown/code_020a2e74.h"
#include "code_02147cd8.h"

void blln_addVelocity(Balloon *balloon, const Vec3 *addend) {
    VEC_Add(&balloon->field0.field10, addend, &balloon->field0.field10);
}
