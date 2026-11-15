#include "Main/Item/pooled_map_object.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/data_0217b000.h"


void ParkPooledMapObject(ItemBox *pooledMapObject) {
    ParkMapObject(&pooledMapObject->mMapObject);
}

void SetPooledMapObjectFromItem(ItemBox *object, s32 alpha, Vec3 *scale) {
    object->mMapObject.mPos = *object->mPositionSource;
    if (alpha < 1) {
        alpha = 1;
    }
    object->mMapObject.mAlpha = alpha;
    object->mMapObject.mScale.x = MUL_FIXED12_NO_ROUND(scale->x, 0x666);
    object->mMapObject.mScale.y = MUL_FIXED12_NO_ROUND(scale->y, 0x666);
    object->mMapObject.mScale.z = MUL_FIXED12_NO_ROUND(scale->z, 0x666);
}

void AdvancePooledMapObject(ItemBox *object) {
    object->mBoxRotationIndex = object->mBoxRotationIndex + 1;
    if (object->mBoxRotationIndex >= BOX_ROTATION_COUNT) {
        object->mBoxRotationIndex = 0;
    }
    object->mQuestionRotationIndex = object->mQuestionRotationIndex + 1;
    if (object->mQuestionRotationIndex >= QUESTION_ROTATION_COUNT) {
        object->mQuestionRotationIndex = 0;
    }
}

void SetPooledMapObjectCallback(ItemBox *object, void (*callback)(ItemFBox *owner, MtxFx43 *out), ItemFBox *owner) {
    object->mDrawMatrixCallback = callback;
    object->mDrawMatrixCallbackOwner = owner;
}
