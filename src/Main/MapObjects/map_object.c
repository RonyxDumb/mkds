#include "Main/MapObjects/map_object.h"
#include "Main/Sound/kart_sound.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "Main/System/init_after_startup.h"

void StartMapObjectKindSound(MapObject *mapObject, SoundSource *soundSource, s32 value, s32 fraction) {
    s32 soundId;
    soundId = mapObject->mKindData->mSoundId;
    if (soundId == -1) {
        return;
    }
    if (mapObject->mDistanceSquaredAndFlags & 0x40000000) {
        return;
    }
    if (mapObject->mSound != NULL) {
        StartSoundVolumeFromFractionIfTwo(&mapObject->mSound->mSoundSource, soundId, fraction, value);
    } else {
        StartSoundVolumeFromFractionIfTwo(soundSource, soundId, fraction, value);
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
