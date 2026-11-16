#include "Main/Unknown/code_021052f0.h"
#include "Main/Unknown/code_020d22c0.h"

#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_021053d8.h"

void ParkPooledMapObject(u32 pooledMapObject) {
    u32 parkedObject = pooledMapObject;
    u32 value12;
    mobj_setInvisible((void *) parkedObject);
}

void SetPooledMapObjectFromItem(PooledMapObject *object, s32 alpha, Vec3 *scale) {
    object->field0.mPos = *object->fieldFC;
    if (alpha < 1) {
        alpha = 1;
    }
    object->field0.mAlpha = alpha;
    object->field0.mScale.x = ((s64) scale->x * 0x666) >> 12;
    object->field0.mScale.y = ((s64) scale->y * 0x666) >> 12;
    object->field0.mScale.z = ((s64) scale->z * 0x666) >> 12;
}

void AdvancePooledMapObject(PooledMapObject *object) {
    object->fieldA0 = object->fieldA0 + 1;
    if (object->fieldA0 >= 0x12c) {
        object->fieldA0 = 0;
    }
    object->fieldA2 = object->fieldA2 + 1;
    if (object->fieldA2 >= 0x82) {
        object->fieldA2 = 0;
    }
}

void SetPooledMapObjectCallback(PooledMapObject *object, void *callback, ItemFBox *owner) {
    object->field100 = callback;
    object->field104 = owner;
}
