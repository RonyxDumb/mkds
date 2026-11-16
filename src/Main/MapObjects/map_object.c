#include "Main/MapObjects/map_object.h"
#include "Main/Sound/kart_sound.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_and_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "fixed_vector_math.h"
#include "Main/System/init_after_startup.h"

void StartMapObjectKindSound(MapObject *mapObject, SoundSource *soundSource, s32 value, s32 fraction) {
    s32 soundId;
    soundId = mapObject->mKindData->mSoundId;
    if (soundId == -1) {
        return;
    }
    if (mapObject->mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_SKIP_KIND_SOUND) {
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
    if (distanceSquared >= (falloffKind == 2 ? gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared
                                             : gSoundFalloffs[SOUND_FALLOFF_LONG_RANGE].mFarDistanceSquared)) {
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
        case MAP_OBJECT_SHAPE_ROTATED_CYLINDER:
        case MAP_OBJECT_SHAPE_ROTATED_BOX:
        case MAP_OBJECT_SHAPE_CUSTOM_HIT_TEST:
            radius = VEC_Mag(&mapObject->mExtent);
            break;
        case MAP_OBJECT_SHAPE_NONE:
        case MAP_OBJECT_SHAPE_SPHERE:
        case MAP_OBJECT_SHAPE_CYLINDER:
        default:
            radius = mapObject->mExtent.x;
            break;
    }
    SetCollisionSlotRadius(mapObject->mCollisionSlotIndex, radius);
}

s32 GetMapObjectCollisionRadius(MapObject *mapObject) {
    switch (mapObject->mKindData->mShapeKind) {
        case MAP_OBJECT_SHAPE_ROTATED_CYLINDER:
        case MAP_OBJECT_SHAPE_ROTATED_BOX:
        case MAP_OBJECT_SHAPE_CUSTOM_HIT_TEST:
            return VEC_Mag(&mapObject->mExtent);
        case MAP_OBJECT_SHAPE_NONE:
        case MAP_OBJECT_SHAPE_SPHERE:
        case MAP_OBJECT_SHAPE_CYLINDER:
        default:
            return mapObject->mExtent.x;
    }
}

void SetMapObjectDrawDistance(MapObject *mapObject, s32 drawDistance) {
    s32 maxDistance;
    mapObject->mDrawDistance = drawDistance;
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
        mapObject->mDrawDistance = MAP_OBJECT_FAR_VALUE;
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
