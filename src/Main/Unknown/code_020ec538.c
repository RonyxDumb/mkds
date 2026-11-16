#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020e43a8.h"

#include "Main/Unknown/code_020d6000.h"
#include "code_02147cd8.h"

const Vec3 data_02159588 = {0x1000, 0, 0};
const Vec3 gVec3UnitX = {0x1000, 0, 0};
const Vec3 data_02159594 = {0, 0, 0};

void rdmo_initParams(Unk020e43a8 *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed) {
    object->fieldA0 = lowestY;
    object->fieldA4 = gravity;
    object->fieldA8 = 1;
    object->fieldAC = 0;
    object->fieldAE = angleStep;
    object->fieldB0 = upwardSpeed;
    object->fieldB4 = pushSpeed;
}

BOOL rdmo_dieUpdate(Unk020e43a8 *object) {
    if (object->fieldA8) {
        object->fieldAC = object->fieldAC + object->fieldAE;
    } else {
        object->fieldAC = object->fieldAC - object->fieldAE;
    }
    object->field0.field10.y = object->field0.field10.y - object->fieldA4;
    VEC_Add(&object->field0.mPos, &object->field0.field10, &object->field0.mPos);
    return object->field0.mPos.y < object->fieldA0;
}

void rdmo_20EC6E4(Unk020e43a8 *object, Unk020ec6e4 *other) {
    Vec3 offset;
    s32 pushSpeed;

    VEC_Subtract(&object->field0.mPos, &other->field80, &offset);
    if ((s64) offset.z * other->fieldA4 - (s64) offset.x * other->fieldAC < 0) {
        s32 x = other->field50.x;
        s32 z = other->field50.z;
        offset.z = -x;
        offset.x = z;
        offset.y = 0;
        object->fieldA8 = 1;
    } else {
        s32 x = other->field50.x;
        s32 z = -other->field50.z;
        offset.z = x;
        offset.x = z;
        offset.y = 0;
        object->fieldA8 = 0;
    }
    pushSpeed = object->fieldB4;
    object->field0.field10.x = ((s64) offset.x * pushSpeed) >> 12;
    object->field0.field10.y = ((s64) offset.y * pushSpeed) >> 12;
    object->field0.field10.z = ((s64) offset.z * pushSpeed) >> 12;
    object->field0.field10.x = object->field0.field10.x + (other->fieldA4 >> 1);
    object->field0.field10.z = object->field0.field10.z + (other->fieldAC >> 1);
    object->field0.field10.y = object->fieldB0;
}

void rdmo_20EC538(Unk020e43a8 *object, const Unk020ec6e4 *other) {
    Vec3 out;
    Vec3 otherPoint;
    Vec3 otherVector;
    s32 pushSpeed;

    otherPoint = other ? other->field50 : object->field0.mPos;
    otherVector = other ? other->field5C : data_02159594;
    VEC_Subtract(&object->field0.mPos, &otherPoint, &out);
    if ((s64) out.z * otherVector.x - (s64) out.x * otherVector.z < 0) {
        if (vec_normalizeXZFast(&otherVector, &out) == 0) {
            out = gVec3UnitX;
        } else {
            s32 x = out.x;
            s32 z = out.z;
            out.z = -x;
            out.x = z;
            out.y = 0;
        }
        object->fieldA8 = 1;
    } else {
        if (vec_normalizeXZFast(&otherVector, &out) == 0) {
            out = data_02159588;
        } else {
            s32 x = out.x;
            s32 z = -out.z;
            out.z = x;
            out.x = z;
            out.y = 0;
        }
        object->fieldA8 = 0;
    }
    pushSpeed = object->fieldB4;
    object->field0.field10.x = ((s64) out.x * pushSpeed) >> 12;
    object->field0.field10.y = ((s64) out.y * pushSpeed) >> 12;
    object->field0.field10.z = ((s64) out.z * pushSpeed) >> 12;
    object->field0.field10.x = object->field0.field10.x + (otherVector.x >> 1);
    object->field0.field10.z = object->field0.field10.z + (otherVector.z >> 1);
    object->field0.field10.y = object->fieldB0;
}
