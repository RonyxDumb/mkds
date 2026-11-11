#include "Main/Unknown/code_020d24d8.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02024000.h"

void StartMapObjectKindSound(MapObject *mapObject, SoundSource *soundSource, s32 d, s32 e) {
    s32 soundId;
    soundId = mapObject->mKindData->mSoundId;
    if (soundId == -1) {
        return;
    }
    if (mapObject->mDistanceSquaredAndFlags & 0x40000000) {
        return;
    }
    if (mapObject->mSound != NULL) {
        StartSoundVolumeFromFractionIfTwo(&mapObject->mSound->mSoundSource, soundId, e, d);
    } else {
        StartSoundVolumeFromFractionIfTwo(soundSource, soundId, e, d);
    }
}

void StartSoundAtPositionIfNear(s32 soundId, Vec3 *position, s32 falloffKind) {
    s32 distanceSquared;
    SoundStartParams request;
    distanceSquared = GetHorizontalCameraDistanceSquared(position);
    if (distanceSquared >=
        (falloffKind == 2 ? gSoundFalloffs[2].mFarDistanceSquared : gSoundFalloffs[4].mFarDistanceSquared)) {
        return;
    }
    request.mSoundId = soundId;
    request.mPositionSource = position;
    request.mFalloffIndex = falloffKind;
    request.mDistanceSquared = distanceSquared;
    StartSoundFromParams(&request);
}

void SetMapObjectExtentY(MapObject *mapObject, s32 baseSize) {
    s32 radius;
    mapObject->mExtent.y = MUL_FIXED12_NO_ROUND(baseSize, mapObject->mScale.y);
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

s32 GetMapObjectCollisionRadius(MapObject *mapObject) {
    switch (mapObject->mKindData->mShapeKind) {
        case 3:
        case 4:
        case 5:
            return VEC_Mag(&mapObject->mExtent);
        case 0:
        case 1:
        case 2:
        default:
            return mapObject->mExtent.x;
    }
}

void SetMapObjectDrawDistance(MapObject *mapObject, s32 drawDistance) {
    s32 maxDistance;
    mapObject->mDrawDistance = drawDistance;
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
        mapObject->mDrawDistance = 0x270f000;
        return;
    }
    maxDistance = gCourseMap->mSettings->mMapObjectDrawDistanceMax;
    if (maxDistance == 0) {
        return;
    }
    if (mapObject->mDrawDistance > maxDistance) {
        mapObject->mDrawDistance = maxDistance;
    }
}
