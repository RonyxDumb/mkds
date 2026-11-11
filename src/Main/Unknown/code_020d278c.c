#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"

void SetMapObjectScale(MapObject *mapObject, Vec3 *scale) {
    s32 value;
    MapObjectKindData *kindData;
    s32 kindViewRadius;
    mapObject->mScale.x = scale->x;
    mapObject->mScale.y = scale->y;
    mapObject->mScale.z = scale->z;
    mapObject->mExtent.x = MUL_FIXED12_NO_ROUND(mapObject->mKindData->mExtentX, mapObject->mScale.x);
    if (mapObject->mCollisionSlotIndex >= 0) {
        switch (mapObject->mKindData->mShapeKind) {
            case 3:
            case 4:
            case 5:
                value = VEC_Mag(&mapObject->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                value = mapObject->mExtent.x;
                break;
        }
        SetCollisionSlotRadius(mapObject->mCollisionSlotIndex, value);
    }
    mapObject->mExtent.y = MUL_FIXED12_NO_ROUND(mapObject->mKindData->mExtentY, mapObject->mScale.y);
    if (mapObject->mCollisionSlotIndex >= 0) {
        switch (mapObject->mKindData->mShapeKind) {
            case 3:
            case 4:
            case 5:
                value = VEC_Mag(&mapObject->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                value = mapObject->mExtent.x;
                break;
        }
        SetCollisionSlotRadius(mapObject->mCollisionSlotIndex, value);
    }
    mapObject->mExtent.z = MUL_FIXED12_NO_ROUND(mapObject->mKindData->mExtentZ, mapObject->mScale.z);
    if (mapObject->mCollisionSlotIndex >= 0) {
        switch (mapObject->mKindData->mShapeKind) {
            case 3:
            case 4:
            case 5:
                value = VEC_Mag(&mapObject->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                value = mapObject->mExtent.x;
                break;
        }
        SetCollisionSlotRadius(mapObject->mCollisionSlotIndex, value);
    }
    value = mapObject->mScale.x;
    kindData = mapObject->mKindData;
    kindViewRadius = kindData->mViewRadius;
    if (value < mapObject->mScale.y) {
        value = mapObject->mScale.y;
    }
    if (value < mapObject->mScale.z) {
        value = mapObject->mScale.z;
    }
    mapObject->mViewRadius = MUL_FIXED12_NO_ROUND(kindViewRadius, value);
}

void SetMapObjectExtentX(MapObject *mapObject, s32 baseSize) {
    s32 radius;
    mapObject->mExtent.x = MUL_FIXED12_NO_ROUND(baseSize, mapObject->mScale.x);
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
    SetCollisionSlotRadius(mapObject->mCollisionSlotIndex, radius);
}

void CreateMapObjectSoundSourceFalloff2(MapObject *mapObject) {
    mapObject->mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 2, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSoundFalloffs[2].mFarDistanceSquared;
    SetSoundSourceEnabled(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
}

SoundDistanceSquaredChange *CreateVehicleSoundSource(MapObject *mapObject) {
    mapObject->mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x60);
    InitSoundSource(&mapObject->mSound->mSoundSource, 2, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSoundFalloffs[2].mFarDistanceSquared;
    SetSoundSourceEnabled(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
    return &mapObject->mSound->mSoundDistanceSquaredChange;
}

void CreateMapObjectSoundSourceFalloff3(MapObject *mapObject) {
    mapObject->mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 3, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSoundFalloffs[3].mFarDistanceSquared;
    SetSoundSourceEnabled(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
}

void CreateMapObjectSoundSourceFalloff4(MapObject *mapObject) {
    mapObject->mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 4, &mapObject->mPos);
    mapObject->mFarDistanceSquared = gSoundFalloffs[4].mFarDistanceSquared;
    SetSoundSourceEnabled(&mapObject->mSound->mSoundSource, 0);
    if (mapObject->mSound->mSoundSource.mSourceFlags & 1) {
        SetSoundSourceFlagBit(&mapObject->mSound->mSoundSource, 2, 1);
    }
}
