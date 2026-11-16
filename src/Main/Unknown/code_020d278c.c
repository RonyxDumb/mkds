#include "Main/Unknown/code_020d278c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"

void mobj_setScale(MapObject *mapObject, Vec3 *scale) {
    s32 a;
    MapObjectKindData *kindData;
    s32 kindViewRadius;
    mapObject->mScale.x = scale->x;
    mapObject->mScale.y = scale->y;
    mapObject->mScale.z = scale->z;
    mapObject->mExtent.x = (s64) mapObject->mKindData->fieldC * mapObject->mScale.x >> 12;
    if (mapObject->mCollisionSlotIndex >= 0) {
        switch (mapObject->mKindData->mShapeKind) {
            case 3:
            case 4:
            case 5:
                a = VEC_Mag(&mapObject->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = mapObject->mExtent.x;
                break;
        }
        col_setBoundingSphereRadius(mapObject->mCollisionSlotIndex, a);
    }
    mapObject->mExtent.y = (s64) mapObject->mKindData->field10 * mapObject->mScale.y >> 12;
    if (mapObject->mCollisionSlotIndex >= 0) {
        switch (mapObject->mKindData->mShapeKind) {
            case 3:
            case 4:
            case 5:
                a = VEC_Mag(&mapObject->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = mapObject->mExtent.x;
                break;
        }
        col_setBoundingSphereRadius(mapObject->mCollisionSlotIndex, a);
    }
    mapObject->mExtent.z = (s64) mapObject->mKindData->field14 * mapObject->mScale.z >> 12;
    if (mapObject->mCollisionSlotIndex >= 0) {
        switch (mapObject->mKindData->mShapeKind) {
            case 3:
            case 4:
            case 5:
                a = VEC_Mag(&mapObject->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = mapObject->mExtent.x;
                break;
        }
        col_setBoundingSphereRadius(mapObject->mCollisionSlotIndex, a);
    }
    a = mapObject->mScale.x;
    kindData = mapObject->mKindData;
    kindViewRadius = kindData->field2C;
    if (a < mapObject->mScale.y) {
        a = mapObject->mScale.y;
    }
    if (a < mapObject->mScale.z) {
        a = mapObject->mScale.z;
    }
    mapObject->mViewRadius = (s64) kindViewRadius * a >> 12;
}

void mobj_setSizeX(MapObject *mapObject, s32 baseSize) {
    s32 radius;
    mapObject->mExtent.x = (s64) baseSize * mapObject->mScale.x >> 12;
    if (mapObject->mCollisionSlotIndex < 0) {
        return;
    }
    switch (mapObject->mKindData->mShapeKind) {
        case 3:
        case 4:
        case 5:
            radius = VEC_Mag(&mapObject->mExtent);
            break;
        case 0:
        case 1:
        case 2:
        default:
            radius = mapObject->mExtent.x;
            break;
    }
    col_setBoundingSphereRadius(mapObject->mCollisionSlotIndex, radius);
}

void mobj_initSoundEmitterForObjectSfxParam2(MapObject *mapObject) {
    mapObject->mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 2, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSfxParams[2].field20;
    sfx_210CF9C(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
}

SoundDistanceSquaredChange *mobj_initSoundEmitterExForObjectSfxParam2(MapObject *mapObject) {
    mapObject->mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x60);
    InitSoundSource(&mapObject->mSound->mSoundSource, 2, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSfxParams[2].field20;
    sfx_210CF9C(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
    return &mapObject->mSound->field44;
}

void mobj_initSoundEmitterForObjectSfxParam3(MapObject *mapObject) {
    mapObject->mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 3, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSfxParams[3].field20;
    sfx_210CF9C(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
}

void mobj_initSoundEmitterForObjectSfxParam4(MapObject *mapObject) {
    mapObject->mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 4, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSfxParams[4].field20;
    sfx_210CF9C(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
}
