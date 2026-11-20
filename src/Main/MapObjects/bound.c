#include "Main/MapObjects/bound.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/sun.h"
#include "Main/MapObjects/sun_fireball.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const u32 gBoundHitDistanceFlag = 0x80000000;
MapObjectModel *gBound;
MapObjectModel *gCream;
MapObjectModel *gBerry;

MapObjectKindDescriptor gBoundKindDescriptor = {0,
                                             {0, 0},
                                             0x140,
                                             InitBound,
                                             CreateBoundKindData,
                                             CreateBoundDrawList,
                                             0,
                                             0,
                                             CreateBoundUpdateList};
MapObjectKindDescriptor gCreamKindDescriptor = {0,
                                             {0, 0},
                                             0x140,
                                             InitBound,
                                             CreateCreamKindData,
                                             CreateCreamDrawList,
                                             0,
                                             0,
                                             CreateBoundUpdateList};
MapObjectKindDescriptor gBerryKindDescriptor = {0,
                                             {0, 0},
                                             0x140,
                                             InitBound,
                                             CreateBerryKindData,
                                             CreateBerryDrawList,
                                             0,
                                             0,
                                             CreateBoundUpdateList};

static inline u32 CollideKartWithBound_inline(RandomState64 *randomState64) {
    RANDOM_ADVANCE(randomState64);
    return RANDOM_HIGH32(randomState64);
}

void InitBound(Bound *bound) {
    bound->mMapObject.mFlags |= gBoundInitMapObjectFlag;
    RefreshMapObjectMatrixFromHitNormal(&bound->mMapObject);
    bound->mInitialScaleX = bound->mMapObject.mScale.x;
}

// Shared by Bound, Cream and Berry: sets the object's motion from the Kart, starts the wobble and plays a sound.
s32 CollideKartWithBound(Bound *bound, Kart *kart, u8 *firstResponse, u8 *response) {
    Vec3 component;
    Vec3 remainder;
    Vec3 offset;
    Vec3 contactPos;
    Vec3 *kartVector;
    u8 responseValue;
    s32 dot;
    u32 firstResponseValue;

    firstResponseValue = *firstResponse;
    responseValue = *response;
    if (firstResponseValue == 3 || firstResponseValue == 4) {
        if (bound->mKartTimers[kart->mIndex] == 0) {
            VEC_Subtract(&kart->mPos, &bound->mMapObject.mPos, &offset);
            dot = VEC_DotProduct(&kart->mVelocityDirection, &offset);
            component.x = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.x, dot);
            component.y = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.y, dot);
            component.z = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.z, dot);
            remainder.x = offset.x - component.x;
            remainder.y = offset.y - component.y;
            remainder.z = offset.z - component.z;
            dot = VEC_DotProduct(&bound->mMapObject.mMatrix.mRows[1], &remainder);
            component.x = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].x, dot);
            component.y = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].y, dot);
            component.z = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].z, dot);
            remainder.x -= component.x;
            remainder.y -= component.y;
            remainder.z -= component.z;
            if (LENGTH_SQUARED(remainder) < 0x10) {
                kartVector = &kart->mRotationRow0;
                bound->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(kart->mRotationRow0.x, 0xc000);
                bound->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(kartVector->y, 0xc000);
                bound->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(kartVector->z, 0xc000);
            } else {
                Vec3NormalizeAndGetLengthUnchecked(&remainder, &remainder);
                bound->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(remainder.x, 0xc000);
                bound->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(remainder.y, 0xc000);
                bound->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(remainder.z, 0xc000);
            }
            VEC_Subtract(&component, &bound->mMapObject.mMatrix.mRows[1], &component);
            VEC_MultAdd(0x19a, &component, &bound->mMapObject.mPosStep, &bound->mMapObject.mPosStep);
            bound->mKartTimers[kart->mIndex] = BOUND_KART_HIT_FRAMES;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                CallStandingsKartOffsetCallback(kart->mIndex, &bound->mMapObject.mPosStep);
            }
        } else {
            bound->mMapObject.mPosStep.x = 0;
            bound->mMapObject.mPosStep.y = 0;
            bound->mMapObject.mPosStep.z = 0;
        }
        if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST && bound->mWobbling == FALSE) {
            bound->mWobbleXAngle = BOUND_WOBBLE_X_ANGLE_START;
            bound->mWobbleXMid = BOUND_WOBBLE_MID;
            bound->mWobbleXAmplitude = BOUND_WOBBLE_AMPLITUDE_LARGE;
            bound->mWobbleXAmplitudePerFrame = BOUND_WOBBLE_AMPLITUDE_STEP_LARGE;
            bound->mWobbleXAnglePerFrame = BOUND_WOBBLE_ANGLE_PER_FRAME;
            bound->mWobbleXAnglePerFrameChange = 0;
            bound->mWobbleYAngle = BOUND_WOBBLE_Y_ANGLE_START;
            bound->mWobbleYMid = BOUND_WOBBLE_MID;
            bound->mWobbleYAmplitude = BOUND_WOBBLE_AMPLITUDE_LARGE;
            bound->mWobbleYAmplitudePerFrame = BOUND_WOBBLE_AMPLITUDE_STEP_LARGE;
            bound->mWobbleYAnglePerFrame = BOUND_WOBBLE_ANGLE_PER_FRAME;
            bound->mWobbleYAnglePerFrameChange = 0;
            bound->mWobbling = TRUE;
            switch (bound->mMapObject.mKind) {
                case MAP_OBJECT_KIND_CREAM:
                    StartSoundFullVolumeWrapper(kart, CREAM_ITEM_HIT_SOUND_ID);
                    break;
                case MAP_OBJECT_KIND_BERRY:
                    StartSoundFullVolumeWrapper(kart, BERRY_ITEM_HIT_SOUND_ID);
                    break;
                case MAP_OBJECT_KIND_BOUND:
                    StartSoundFullVolumeWrapper(kart, BOUND_ITEM_HIT_SOUND_ID);
                    break;
            }
            if ((u16) (bound->mMapObject.mKind + 0xfe4c) <= 1) {
                StartOrthoQuadsCreamEffect(
                    kart->mIndex,
                    (u16) (((u64) CollideKartWithBound_inline(&gRaceProgress->mLocalRandom) * 3) >> 32) + 1);
                VEC_Subtract(&bound->mMapObject.mPos, &kart->mCollisionCenter, &contactPos);
                if (!(LENGTH_SQUARED(contactPos) < 0x10)) {
                    Vec3NormalizeAndGetLengthUnchecked(&contactPos, &contactPos);
                }
                VEC_MultAdd(kart->mRadius, &contactPos, &kart->mCollisionCenter, &contactPos);
                if (kart->mIndex == gRaceSetup->mEntryIndex) {
                    StartEffect(0x74, &contactPos);
                } else {
                    StartEffect(0x75, &contactPos);
                }
            }
        }
        return responseValue;
    }
    bound->mMapObject.mPosStep.x = 0;
    bound->mMapObject.mPosStep.y = 0;
    bound->mMapObject.mPosStep.z = 0;
    return 2;
}

// Shared by Bound, Cream and Berry: when *b is 2, starts a smaller wobble; returns *c.
u8 CollideItemObjectWithBound(Bound *bound, void *itemObject, u8 *firstResponse, u8 *response) {
    u32 responseValue;

    responseValue = *response;
    if (*firstResponse == 2 && bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = BOUND_WOBBLE_X_ANGLE_START;
        bound->mWobbleXMid = BOUND_WOBBLE_MID;
        bound->mWobbleXAmplitude = BOUND_WOBBLE_AMPLITUDE_SMALL;
        bound->mWobbleXAmplitudePerFrame = BOUND_WOBBLE_AMPLITUDE_STEP_SMALL;
        bound->mWobbleXAnglePerFrame = BOUND_WOBBLE_ANGLE_PER_FRAME;
        bound->mWobbleXAnglePerFrameChange = 0;
        bound->mWobbleYAngle = BOUND_WOBBLE_Y_ANGLE_START;
        bound->mWobbleYMid = BOUND_WOBBLE_MID;
        bound->mWobbleYAmplitude = BOUND_WOBBLE_AMPLITUDE_SMALL;
        bound->mWobbleYAmplitudePerFrame = BOUND_WOBBLE_AMPLITUDE_STEP_SMALL;
        bound->mWobbleYAnglePerFrame = BOUND_WOBBLE_ANGLE_PER_FRAME;
        bound->mWobbleYAnglePerFrameChange = 0;
        bound->mWobbling = TRUE;
        bound->mMapObject.mDistanceSquaredAndFlags |= gBoundHitDistanceFlag;
    }
    return responseValue;
}

BOOL ComputeSphereHitOnBound(Bound *bound, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut) {
    if ((bound->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) == 0 && bound->mWobbling == TRUE) {
        bound->mSphereHit = ComputeSphereHitOnRotatedCylinder(
            sphereCenter, &bound->mMapObject.mPos, &bound->mMapObject.mMatrix.mRows[0],
            MUL_FIXED12_NO_ROUND(bound->mMapObject.mExtent.x, bound->mWobbleScaleX), bound->mMapObject.mExtent.y, 0,
            sphereRadius, pushOut);
    } else {
        bound->mSphereHit = ComputeSphereHitOnRotatedCylinder(
            sphereCenter, &bound->mMapObject.mPos, &bound->mMapObject.mMatrix.mRows[0], bound->mMapObject.mExtent.x,
            bound->mMapObject.mExtent.y, 0, sphereRadius, pushOut);
    }
    return bound->mSphereHit != 0;
}

void CreateBound(void *mapObjectList) {
    gBound = CreateMapObjectModelAnimated(mapObjectList, "bound.nsbmd");
    CreateMapObjectModelNsbtpAnimation(gBound, "bound.nsbtp");
}

void DrawBound(MapObjectList *mapObjectList, Bound *bound) {
    s32 gxParams[4];
    s32 scaleX;
    s32 scaleY;

    gxParams[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParams[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        scaleX = bound->mWobbleScaleX;
        scaleY = bound->mWobbleScaleY;
        gxParams[1] = scaleX;
        gxParams[2] = scaleY;
        gxParams[3] = scaleX;
        NNS_G3dGeBufferOP_N(0x1b, &gxParams[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBound, bound->mNsbtpFrameIndex);
    DrawMapObjectModel(mapObjectList, gBound, bound);
}

void CreateCream(void *mapObjectList) {
    gCream = CreateMapObjectModelAnimated(mapObjectList, "cream.nsbmd");
    CreateOrthoQuadCreamEffect("cream_effect.nsbmd");
}

void CreateBerry(void *mapObjectList) {
    gBerry = CreateMapObjectModelAnimated(mapObjectList, "berry.nsbmd");
    CreateOrthoQuadCreamEffect("cream_effect.nsbmd");
}

void DrawCream(MapObjectList *mapObjectList, Bound *bound) {
    s32 gxParams[4];
    s32 scaleX;
    s32 scaleY;

    gxParams[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParams[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        scaleX = bound->mWobbleScaleX;
        scaleY = bound->mWobbleScaleY;
        gxParams[1] = scaleX;
        gxParams[2] = scaleY;
        gxParams[3] = scaleX;
        NNS_G3dGeBufferOP_N(0x1b, &gxParams[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gCream, bound);
}

void DrawBerry(MapObjectList *mapObjectList, Bound *bound) {
    s32 gxParams[4];
    s32 scaleX;
    s32 scaleY;

    gxParams[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParams[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        scaleX = bound->mWobbleScaleX;
        scaleY = bound->mWobbleScaleY;
        gxParams[1] = scaleX;
        gxParams[2] = scaleY;
        gxParams[3] = scaleX;
        NNS_G3dGeBufferOP_N(0x1b, &gxParams[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gBerry, bound);
}

void InitBoundAndCreamAndBerryObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    Bound *bound;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (bound = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (bound->mMapObject.mCourseMapRow->mGroupIndex >= 0) {
            InitGroupFollower(&bound->mFollower, bound->mMapObject.mCourseMapRow, 0);
            bound->mFollower.mSpeed = BOUND_PATH_SPEED;
            bound->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                bound->mFollower.mPath->mSegments[bound->mFollower.mSegmentIndex].mInverseProgressLength,
                BOUND_PATH_SPEED);
        } else {
            bound->mFollower.mGroupIndex = GROUP_FOLLOWER_NO_GROUP;
        }
    }
}

s16 BoundFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 BoundFX_MulInline(s32 value, s32 scale) {
    return MUL_FIXED12_ROUNDED(value, scale);
}

void UpdateBoundAndCreamAndBerry(MapObjectList *mapObjectList, Bound *bound) {
    u16 nsbtpFrameCount;
    s32 value;
    s32 kartIndex;
    s32 kartCount;

    if (bound->mFollower.mGroupIndex != GROUP_FOLLOWER_NO_GROUP) {
        AdvanceGroupFollower(&bound->mFollower);
        GetGroupFollowerCurvePosStep(&bound->mFollower, &bound->mMapObject.mPos, &bound->mMapObject.mPosStep);
        nsbtpFrameCount = GetMapObjectModelNsbtpFrameCount(gBound);
        bound->mNsbtpFrameIndex += 1;
        if (bound->mNsbtpFrameIndex >= nsbtpFrameCount) {
            bound->mNsbtpFrameIndex = 1;
        }
    } else {
        bound->mMapObject.mPosStep.x = 0;
        bound->mMapObject.mPosStep.y = 0;
        bound->mMapObject.mPosStep.z = 0;
        bound->mNsbtpFrameIndex = 0;
    }
    if (bound->mWobbling == TRUE) {
        bound->mWobbleXAngle += bound->mWobbleXAnglePerFrame;
        value = BoundFX_MulInline(bound->mWobbleXAmplitude, BoundFX_SinIdx(bound->mWobbleXAngle));
        bound->mWobbleScaleXDelta = bound->mWobbleXMid + value - bound->mWobbleScaleX;
        bound->mWobbleScaleX += bound->mWobbleScaleXDelta;
        if (bound->mWobbleXAmplitude > 0) {
            value = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleXAmplitude = value;
        } else if (bound->mWobbleXAmplitude < 0) {
            value = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleXAmplitude = value;
        }
        if (bound->mWobbleXAnglePerFrame > 0) {
            value = bound->mWobbleXAnglePerFrame + bound->mWobbleXAnglePerFrameChange;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleXAnglePerFrame = value;
        } else if (bound->mWobbleXAnglePerFrame < 0) {
            value = bound->mWobbleXAnglePerFrame + bound->mWobbleXAnglePerFrameChange;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleXAnglePerFrame = value;
        }
        bound->mWobbleYAngle += bound->mWobbleYAnglePerFrame;
        value = BoundFX_MulInline(bound->mWobbleYAmplitude, BoundFX_SinIdx(bound->mWobbleYAngle));
        bound->mWobbleScaleYDelta = bound->mWobbleYMid + value - bound->mWobbleScaleY;
        bound->mWobbleScaleY += bound->mWobbleScaleYDelta;
        if (bound->mWobbleYAmplitude > 0) {
            value = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleYAmplitude = value;
        } else if (bound->mWobbleYAmplitude < 0) {
            value = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleYAmplitude = value;
        }
        if (bound->mWobbleYAnglePerFrame > 0) {
            value = bound->mWobbleYAnglePerFrame + bound->mWobbleYAnglePerFrameChange;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleYAnglePerFrame = value;
        } else if (bound->mWobbleYAnglePerFrame < 0) {
            value = bound->mWobbleYAnglePerFrame + bound->mWobbleYAnglePerFrameChange;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleYAnglePerFrame = value;
        }
        if (bound->mWobbleXAmplitude == 0 && bound->mWobbleYAmplitude == 0) {
            bound->mWobbling = FALSE;
            bound->mMapObject.mScale.x = bound->mInitialScaleX;
        } else {
            bound->mMapObject.mScale.x = MUL_FIXED12_NO_ROUND(bound->mInitialScaleX, bound->mWobbleScaleX);
        }
    } else {
        bound->mMapObject.mScale.x = bound->mInitialScaleX;
    }
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        if (bound->mKartTimers[kartIndex] > 0) {
            bound->mKartTimers[kartIndex] -= 1;
        }
    }
}

MapObjectKindData *CreateBoundKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = BOUND_ITEM_HIT_SOUND_ID;
    return kindData;
}

MapObjectKindData *CreateCreamKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = CREAM_ITEM_HIT_SOUND_ID;
    return kindData;
}

MapObjectKindData *CreateBerryKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = BERRY_ITEM_HIT_SOUND_ID;
    return kindData;
}

MapObjectList *CreateBoundDrawList(void) {
    return CreateMapObjectDrawList1(CreateBound, DrawBound, NULL);
}

MapObjectList *CreateCreamDrawList(void) {
    return CreateMapObjectDrawList1(CreateCream, DrawCream, NULL);
}

MapObjectList *CreateBerryDrawList(void) {
    return CreateMapObjectDrawList1(CreateBerry, DrawBerry, NULL);
}

MapObjectList *CreateBoundUpdateList(void) {
    return CreateMapObjectUpdateList(InitBoundAndCreamAndBerryObjects, UpdateBoundAndCreamAndBerry, NULL);
}

// Starts the wobble of object a of the 0x1a8 list, with a sound unless the object is far; FALSE if already wobbling.
BOOL StartBoundWobble(s32 mapObjectIndex) {
    Bound *bound;
    SoundStartParams soundParams;
    s32 falloffIndex;

    bound = GetMapObjectFromList(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BOUND), mapObjectIndex);
    if (bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = BOUND_WOBBLE_X_ANGLE_START;
        bound->mWobbleXMid = BOUND_WOBBLE_MID;
        bound->mWobbleXAmplitude = BOUND_WOBBLE_AMPLITUDE_LARGE;
        bound->mWobbleXAmplitudePerFrame = BOUND_WOBBLE_AMPLITUDE_STEP_LARGE;
        bound->mWobbleXAnglePerFrame = BOUND_WOBBLE_ANGLE_PER_FRAME;
        bound->mWobbleXAnglePerFrameChange = 0;
        bound->mWobbleYAngle = BOUND_WOBBLE_Y_ANGLE_START;
        bound->mWobbleYMid = BOUND_WOBBLE_MID;
        bound->mWobbleYAmplitude = BOUND_WOBBLE_AMPLITUDE_LARGE;
        bound->mWobbleYAmplitudePerFrame = BOUND_WOBBLE_AMPLITUDE_STEP_LARGE;
        bound->mWobbleYAnglePerFrame = BOUND_WOBBLE_ANGLE_PER_FRAME;
        bound->mWobbleYAnglePerFrameChange = 0;
        bound->mWobbling = TRUE;
        if ((bound->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
            if (bound->mMapObject.mFarDistanceSquared ==
                gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared) {
                falloffIndex = SOUND_FALLOFF_SHORT_RANGE;
            } else if (bound->mMapObject.mFarDistanceSquared ==
                       gSoundFalloffs[SOUND_FALLOFF_MEDIUM_RANGE].mFarDistanceSquared) {
                falloffIndex = SOUND_FALLOFF_MEDIUM_RANGE;
            } else {
                falloffIndex = SOUND_FALLOFF_LONG_RANGE;
            }
            soundParams.mSoundId = BOUND_ITEM_HIT_SOUND_ID;
            soundParams.mPositionSource = &bound->mMapObject.mPos;
            soundParams.mFalloffIndex = falloffIndex;
            soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bound->mMapObject.mPos);
            StartSoundFromParams(&soundParams);
        }
        return TRUE;
    }
    return FALSE;
}

#pragma thumb on

void *CreateMapObjectKindData(void *collideKartCallback, void *collideItemObjectCallback, void *sphereHitCallback,
                              u32 wordValue, u16 halfValue) {
    MapObjectKindData *kindData;

    GetHeap(GetCurrentHeapCall());
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*kindData));
    kindData->mCollideKartCallback = collideKartCallback;
    kindData->mCollideItemObjectCallback = collideItemObjectCallback;
    kindData->mPosStepMode = wordValue;
    kindData->mCollidable = halfValue;
    kindData->mSphereHitTest = sphereHitCallback;
    return kindData;
}

MapObjectKindData *CreateEmptyMapObjectKindData(void) {
    return CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

MapObjectKindData *CreateMapObjectKindDataWithSound(void *collideKartCallback, void *collideItemObjectCallback,
                                                    void *sphereHitCallback, u32 wordValue, u16 halfValue,
                                                    u16 soundId) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(collideKartCallback, collideItemObjectCallback, sphereHitCallback, wordValue,
                                       halfValue);
    kindData->mSoundId = soundId;
    return kindData;
}

#pragma thumb off
