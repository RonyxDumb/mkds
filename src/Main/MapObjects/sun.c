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

MapObjectModel *gSun;
MapObjectModel *gSunLOD;

MapObjectKindDescriptor gSunKindDescriptor = {0,
                                             {0, 0},
                                             0xe0,
                                             InitSun,
                                             CreateEmptyMapObjectKindData,
                                             CreateSunDrawList,
                                             0,
                                             0,
                                             CreateSunUpdateList};

void InitSun(Sun *sun) {
    InitGroupFollower(&sun->mFollower, sun->mMapObject.mCourseMapRow, 0);
    CreateParkedMapObjects(MAP_OBJECT_KIND_SUN_FIREBALL, 0x1e, sun);
    sun->mMapObject.mPosStep.x = 0;
    sun->mMapObject.mPosStep.y = 0;
    sun->mMapObject.mPosStep.z = 0;
}

void CreateSunAndSunLOD(void *mapObjectList) {
    gSun = CreateMapObjectModelAnimated(mapObjectList, "sun.nsbmd");
    CreateMapObjectModelNsbcaAnimation(gSun, "sun.nsbca");
    gSunLOD = CreateMapObjectModelAnimated(mapObjectList, "sun_LOD.nsbmd");
    SetMapObjectModelPolygonId(gSun, AllocPolygonId());
}

void SunSetupDrawNop(void) {}

void DrawSun(void *mapObjectList, Sun *sun) {
    s32 gxParam;
    s32 radius;
    s32 angleIndex;
    Vec3 translation;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sun->mMapObject.mPos), 0xc);
    if (sun->mState == SUN_STATE_SHOOT_FIREBALLS || sun->mState == SUN_STATE_SPIN_DOWN) {
        radius = MUL_FIXED12_NO_ROUND(FX_CosIdx((u16) sun->mDrawOffsetRadiusAngle), -0x14000) + 0x14000;
        angleIndex = (sun->mDrawOffsetAngle >> 4) * 2;
        translation.x = MUL_FIXED12_NO_ROUND(radius, FX_SinCosTable_[angleIndex + 1]) >> 4;
        translation.y = MUL_FIXED12_NO_ROUND(radius, FX_SinCosTable_[angleIndex]) >> 4;
        translation.z = 0;
        NNS_G3dGeBufferOP_N(0x1c, &translation, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &sun->mMapObject.mScale, 3);
    if (GetCurrentCameraKind() == 2) {
        QueueMapObjectModelMaterial(mapObjectList, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, sun->mNsbcaFrameIndex);
        DrawMapObjectModel(mapObjectList, gSun, sun);
    } else if ((s32) (sun->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK) < 0x3d0900) {
        QueueMapObjectModelMaterial(mapObjectList, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, sun->mNsbcaFrameIndex);
        DrawMapObjectModel(mapObjectList, gSun, sun);
    } else {
        QueueMapObjectModelMaterial(mapObjectList, gSunLOD);
        DrawMapObjectModel1Mat1Shp(mapObjectList, gSunLOD, sun);
    }
}

static inline u32 CollideKartWithBound_inline(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void InitSunObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    Sun *sun;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0;
         mapObjectIndex < mapObjectList->mMapObjectCount && (sun = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            sun->mTimer = (u16) sun->mMapObject.mCourseMapRow->mSettings[0];
        } else if (gRaceSetup->mMode == MODE_WIFI) {
            sun->mTimer = (u16) sun->mMapObject.mCourseMapRow->mSettings[1];
        }
    }
}

static inline BOOL UpdateSun_inline(void) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        if ((s32) GetKartHighestLap(kartIndex) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL UpdateSun_inline_b(Sun *sun) {
    s32 kartIndex;
    Kart *kart;
    Vec3 *kartPos;
    s32 deltaX;
    s32 deltaZ;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        kart = GetKart((u16) kartIndex);
        kartPos = &kart->mPos;
        deltaX = kartPos->x - sun->mMapObject.mPos.x;
        deltaZ = kartPos->z - sun->mMapObject.mPos.z;
        if (SQUARE_SUM2(deltaX, deltaZ) < 0x15f900000000LL) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateSun(MapObjectList *mapObjectList, Sun *sun) {
    Vec3 position;
    Vec3 direction;
    s32 value;
    s32 mode;

    switch (sun->mState) {
        case SUN_STATE_WAIT_TO_MOVE:
            if (sun->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) {
                if (sun->mTimer-- <= 0) {
                    sun->mState = SUN_STATE_FOLLOW_PATH;
                }
            } else if (UpdateSun_inline()) {
                sun->mState = SUN_STATE_FOLLOW_PATH;
            }
            break;
        case SUN_STATE_FOLLOW_PATH:
            sun->mFollower.mSpeed = SUN_PATH_SPEED;
            sun->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                sun->mFollower.mPath->mSegments[sun->mFollower.mSegmentIndex].mInverseProgressLength, SUN_PATH_SPEED);
            if (AdvanceGroupFollower(&sun->mFollower) != FALSE && (value = sun->mFollower.mFromEntry->mValue) != 0) {
                if (sun->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) {
                    mode = gRaceSetup->mMode;
                    if (mode == MODE_TIME_ATTACK) {
                        sun->mTimer = value;
                    } else if (mode == MODE_WIFI) {
                        sun->mTimer = sun->mFollower.mFromEntry->mExtraValue;
                    }
                }
                sun->mState = SUN_STATE_WAIT_AT_PATH_POINT;
            }
            GetGroupFollowerLinearPosition(&sun->mFollower, &sun->mMapObject.mPos);
            break;
        case SUN_STATE_WAIT_AT_PATH_POINT:
            if (sun->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) {
                if (sun->mTimer-- <= 0) {
                    sun->mDrawOffsetAngle = 0;
                    sun->mDrawOffsetRadiusAngle = sun->mDrawOffsetAngle;
                    sun->mTimer = SUN_FIRST_FIREBALL_DELAY_FRAMES;
                    sun->mState = SUN_STATE_SHOOT_FIREBALLS;
                }
            } else if (UpdateSun_inline_b(sun)) {
                sun->mDrawOffsetAngle = 0;
                sun->mDrawOffsetRadiusAngle = sun->mDrawOffsetAngle;
                sun->mTimer = SUN_FIRST_FIREBALL_DELAY_FRAMES;
                sun->mState = SUN_STATE_SHOOT_FIREBALLS;
            }
            break;
        case SUN_STATE_SHOOT_FIREBALLS:
            sun->mDrawOffsetAngle += 0xe39;
            if (sun->mDrawOffsetRadiusAngle < ANGLE_HALF_TURN) {
                sun->mDrawOffsetRadiusAngle += 0x222;
            }
            if (sun->mTimer-- > 0) {
                break;
            }
            if (sun->mFireballIndex == 0) {
                sun->mFireballAngle = ((u64) CollideKartWithBound_inline(GetMapObjectRandom()) * ANGLE_FULL_TURN) >> 32;
            } else {
                sun->mFireballAngle += ANGLE_HALF_TURN;
            }
            position.x = sun->mMapObject.mPos.x;
            position.y = sun->mMapObject.mPos.y - 0x1e000;
            position.z = sun->mMapObject.mPos.z;
            direction.x = FX_SinIdx(sun->mFireballAngle);
            direction.y = 0;
            direction.z = FX_CosIdx(sun->mFireballAngle);
            StartSunFireball(&position, &direction);
            sun->mFireballIndex += 1;
            if (sun->mFireballIndex >= SUN_SHOOT_FIREBALL_COUNT) {
                sun->mFireballIndex = 0;
                sun->mState = SUN_STATE_SPIN_DOWN;
            } else {
                sun->mTimer = SUN_PAUSE_FRAMES;
            }
            break;
        case SUN_STATE_SPIN_DOWN:
            sun->mDrawOffsetAngle += 0xe39;
            sun->mDrawOffsetRadiusAngle += 0x222;
            if (sun->mDrawOffsetRadiusAngle > ANGLE_FULL_TURN) {
                sun->mTimer = SUN_PAUSE_FRAMES;
                sun->mState = SUN_STATE_WAIT_TO_MOVE;
            }
            break;
    }
    if ((s32) (sun->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK) >= 0x3d0900) {
        return;
    }
    if (sun->mState == SUN_STATE_SHOOT_FIREBALLS) {
        value = sun->mNsbcaFrameIndexPerFrame + 0x19a;
        if (value >= 0x8000) {
            value = 0x8000;
        }
        sun->mNsbcaFrameIndexPerFrame = value;
    } else {
        value = sun->mNsbcaFrameIndexPerFrame - 0x19a;
        if (value <= 0x1000) {
            value = 0x1000;
        }
        sun->mNsbcaFrameIndexPerFrame = value;
    }
    sun->mNsbcaFrameIndex += FROM_FIXED12(sun->mNsbcaFrameIndexPerFrame);
    if (sun->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gSun)) {
        sun->mNsbcaFrameIndex = 0;
    }
}

MapObjectList *CreateSunDrawList(void) {
    return CreateMapObjectDrawList1(CreateSunAndSunLOD, DrawSun, SunSetupDrawNop);
}

MapObjectList *CreateSunUpdateList(void) {
    return CreateMapObjectUpdateList(InitSunObjects, UpdateSun, NULL);
}
