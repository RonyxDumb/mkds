#include "Main/MapObjects/bakubaku.h"
#include "Main/Sound/sound_and_ortho_quad_globals.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/Item/item_koura_w.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Graphics/model_effects.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "fixed_vector_math.h"
#include "fixed_arctangent.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

MapObjectModel *gBakubaku;
MapObjectModel *gBakuShadow;

MapObjectKindDescriptor gBakubakuKindDescriptor = {
    0, {0, 0}, 0xb8, 0, CreateEmptyMapObjectKindData, CreateBakubakuDrawList, 0, 0, CreateBakubakuUpdateList};

void CreateBakubakuAndBakuShadow(void *mapObjectList) {
    gBakubaku = CreateMapObjectModelAnimated(mapObjectList, "bakubaku.nsbmd");
    gBakuShadow = CreateMapObjectModelShadow(mapObjectList, "baku_shadow.nsbmd");
    SetMapObjectModelPolygonId(gBakubaku, 0x3f);
    SetMapObjectModelPolygonId(gBakuShadow, 0x3f);
}

void DrawBakubaku(void *mapObjectList, Bakubaku *bakubaku) {
    s32 gxParam;
    MtxFx33 rotation;
    s32 angle;

    if (bakubaku->mState != BAKUBAKU_STATE_ARC_OVER_SURFACE) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    bakubaku->mMapObject.mMatrix.mRows[3].x = bakubaku->mMapObject.mPos.x >> 4;
    bakubaku->mMapObject.mMatrix.mRows[3].y = bakubaku->mMapObject.mPos.y >> 4;
    bakubaku->mMapObject.mMatrix.mRows[3].z = bakubaku->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bakubaku->mMapObject.mMatrix, 12);
    NNS_G3dGeBufferOP_N(0x1b, &bakubaku->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gBakuShadow, bakubaku);
    angle = (u16) (u32) FX_Atan2Idx(-bakubaku->mMapObject.mPosStep.y, 0xc000);
    MTX_RotX33_(&rotation, SIN_OF_ANGLE(angle), COS_OF_ANGLE(angle));
    NNS_G3dGeBufferOP_N(0x1a, &rotation, 9);
    DrawMapObjectModel(mapObjectList, gBakubaku, bakubaku);
}

void InitBakubakuObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    Bakubaku *bakubaku;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (bakubaku = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        VEC_MultAdd(0x320000, &bakubaku->mMapObject.mMatrix.mRows[2], &bakubaku->mMapObject.mCourseMapRow->mPosition,
                    &bakubaku->mDistanceCheckPos);
    }
}

void UpdateBakubaku(void *mapObjectList, Bakubaku *bakubaku) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    Kart *kart;
    Vec3 *kartPos;
    s64 distanceSquared;
    s32 deltaZ;
    s32 deltaX;

    switch (bakubaku->mState) {
        case BAKUBAKU_STATE_WAIT_FOR_KART:
            if (GetCurrentCameraKind() != 2) {
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                kartPos = &kart->mPos;
                deltaX = kartPos->x - bakubaku->mDistanceCheckPos.x;
                deltaZ = kartPos->z - bakubaku->mDistanceCheckPos.z;
                distanceSquared = SQUARE_SUM2(deltaX, deltaZ);
                if (distanceSquared >= (s64) 0x9c4 << 32) {
                    return;
                }
            }
            bakubaku->mMapObject.mPos.x = bakubaku->mMapObject.mCourseMapRow->mPosition.x;
            bakubaku->mMapObject.mPos.y = bakubaku->mMapObject.mCourseMapRow->mPosition.y - 0x32000;
            bakubaku->mMapObject.mPos.z = bakubaku->mMapObject.mCourseMapRow->mPosition.z;
            bakubaku->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(bakubaku->mMapObject.mMatrix.mRows[2].x, 0xc000);
            bakubaku->mMapObject.mPosStep.y = 0xc000;
            bakubaku->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(bakubaku->mMapObject.mMatrix.mRows[2].z, 0xc000);
            bakubaku->mState = BAKUBAKU_STATE_RISE_TO_SURFACE;
            break;
        case BAKUBAKU_STATE_RISE_TO_SURFACE:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y < bakubaku->mMapObject.mCourseMapRow->mPosition.y) {
                return;
            }
            StartModelEffect(MODEL_EFFECT_BK_WAVE, &bakubaku->mMapObject.mPos, 1);
            firstSoundParams.mSoundId = BAKUBAKU_RISE_TO_SURFACE_SOUND_ID;
            firstSoundParams.mPositionSource = &bakubaku->mMapObject.mPos;
            firstSoundParams.mFalloffIndex = SOUND_FALLOFF_LONG_RANGE;
            firstSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bakubaku->mMapObject.mPos);
            StartSoundFromParams(&firstSoundParams);
            bakubaku->mState = BAKUBAKU_STATE_ARC_OVER_SURFACE;
            break;
        case BAKUBAKU_STATE_ARC_OVER_SURFACE:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y > bakubaku->mMapObject.mCourseMapRow->mPosition.y) {
                return;
            }
            StartModelEffect(MODEL_EFFECT_BK_WAVE, &bakubaku->mMapObject.mPos, 1);
            secondSoundParams.mSoundId = BAKUBAKU_ARC_OVER_SURFACE_SOUND_ID;
            secondSoundParams.mPositionSource = &bakubaku->mMapObject.mPos;
            secondSoundParams.mFalloffIndex = SOUND_FALLOFF_SHORT_RANGE;
            secondSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bakubaku->mMapObject.mPos);
            StartSoundFromParams(&secondSoundParams);
            bakubaku->mState = BAKUBAKU_STATE_SINK_BELOW_SURFACE;
            break;
        case BAKUBAKU_STATE_SINK_BELOW_SURFACE:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y <= bakubaku->mMapObject.mCourseMapRow->mPosition.y - 0x32000) {
                bakubaku->mWaitToResetTimer = BAKUBAKU_WAIT_TO_RESET_FRAMES;
                bakubaku->mState = BAKUBAKU_STATE_WAIT_TO_RESET;
            }
            break;
        case BAKUBAKU_STATE_WAIT_TO_RESET:
            if (bakubaku->mWaitToResetTimer-- <= 0) {
                bakubaku->mState = BAKUBAKU_STATE_WAIT_FOR_KART;
            }
            break;
    }
}

MapObjectList *CreateBakubakuDrawList(void) {
    return CreateMapObjectDrawList1(CreateBakubakuAndBakuShadow, DrawBakubaku, NULL);
}

MapObjectList *CreateBakubakuUpdateList(void) {
    return CreateMapObjectUpdateList(InitBakubakuObjects, UpdateBakubaku, NULL);
}
