#include "Main/Unknown/code_021052f0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020de588.h"

#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_021053d8.h"

void ParkPooledMapObject(ItemBox *pooledMapObject) {
    ParkMapObject(&pooledMapObject->mUnk_000);
}

void SetPooledMapObjectFromItem(ItemBox *object, s32 alpha, Vec3 *scale) {
    object->mUnk_000.mPos = *object->mPositionSource;
    if (alpha < 1) {
        alpha = 1;
    }
    object->mUnk_000.mAlpha = alpha;
    object->mUnk_000.mScale.x = ((s64) scale->x * 0x666) >> 12;
    object->mUnk_000.mScale.y = ((s64) scale->y * 0x666) >> 12;
    object->mUnk_000.mScale.z = ((s64) scale->z * 0x666) >> 12;
}

void AdvancePooledMapObject(ItemBox *object) {
    object->mBoxRotationIndex = object->mBoxRotationIndex + 1;
    if (object->mBoxRotationIndex >= 0x12c) {
        object->mBoxRotationIndex = 0;
    }
    object->mQuestionRotationIndex = object->mQuestionRotationIndex + 1;
    if (object->mQuestionRotationIndex >= 0x82) {
        object->mQuestionRotationIndex = 0;
    }
}

void SetPooledMapObjectCallback(ItemBox *object, UnkFunc *callback, ItemFBox *owner) {
    object->mDrawMatrixCallback = callback;
    object->mDrawMatrixCallbackOwner = owner;
}
