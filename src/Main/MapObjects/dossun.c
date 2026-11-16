#include "Main/MapObjects/dossun.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "matrix_3x3_basic.h"
#include "fixed_arctangent.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "ITCM/kart_motion.h"
#include "fixed_vector_math.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_and_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/map_object_response_and_quaternion_math.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/kuribo.h"
#include "Main/MapObjects/dossun_list_data.h"
#include "Main/System/init_after_startup.h"

const u16 gKuriboFlag = 1;
const MapObjectList gKuriboUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateKuribo, NULL, 0, NULL, 0, NULL};
const struct KuriboDrawList gKuriboDrawListData = {
    {0, 0, 0, 0, 0, 0, 0, 0}, CreateKuribo, SetupDrawKuribo, DrawKuribo, {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
                                                                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const MapObjectKindData gKuriboKindData = {(s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithKuribo,
                                           (s32(*)(MapObject *, void *, void *, void *)) CollideItemObjectWithKuribo,
                                           2,
                                           0x8000,
                                           0xa000,
                                           0,
                                           NULL,
                                           1,
                                           1,
                                           0x184,
                                           0x185,
                                           0,
                                           0,
                                           0,
                                           0,
                                           0};
struct ShadowModel *gDossunShadow;
MapObjectList *gKuriboUpdateList;
struct KuriboDrawList *gKuriboDrawList;
struct DossunDrawList *gDossunDrawList;
NsbmdModel *gKuribo;
struct Nsbmd *gDossun;
MapObjectList *gDossunUpdateList;
MtxFx43 gDossunDrawMatrix;

#pragma thumb off

MapObjectKindData *CreateKuriboKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gKuriboKindData;
    return kindData;
}

KuriboDrawList *CreateKuriboDrawList(void) {
    KuriboDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(KuriboDrawList));
    gKuriboDrawList = drawList;
    *drawList = gKuriboDrawListData;
    SetDrawListSlot(&gKuriboDrawList);
    return gKuriboDrawList;
}

MapObjectList *CreateKuriboUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
    gKuriboUpdateList = updateList;
    *updateList = gKuriboUpdateListData;
    SetUpdateListSlot(&gKuriboUpdateList);
    return gKuriboUpdateList;
}

void SetupDrawKuribo(void) {
    QueueNsbmdModelMaterial(gKuribo);
}

void DrawKuribo(void *unused0, Kuribo *kuribo, void *unused1, u16 maxAlpha) {
    Vec3 scale;
    Quaternion orientation;
    u16 modelAlpha;
    NsbmdModel *model;
    if (kuribo->mFollower.mGroupIndex == GROUP_FOLLOWER_NO_GROUP) {
        QuaternionMultiplyByYawIgnoreY(&kuribo->mOrientation, &gViewYawQuaternion, &orientation);
        Matrix3x3FromQuaternion(&kuribo->mMapObject.mMatrix.mAxes, &orientation);
    } else {
        BuildMatrixFromYAxis(GetGroupFollowerSegmentUp(&kuribo->mFollower), &kuribo->mMapObject.mMatrix);
    }
    scale.z = kuribo->mMapObject.mScale.z;
    scale.y = MUL_FIXED12_NO_ROUND(kuribo->mMapObject.mScale.y, kuribo->mScaleFactorY);
    scale.x =
        MUL_FIXED12_NO_ROUND(kuribo->mMapObject.mScale.x,
                             ((KURIBO_SCALE_FACTOR_Y_REST - kuribo->mScaleFactorY) >> 1) + KURIBO_SCALE_FACTOR_Y_REST);
    kuribo->mMapObject.mMatrix.mRows[3].x = kuribo->mMapObject.mPos.x >> 4;
    kuribo->mMapObject.mMatrix.mRows[3].y = kuribo->mMapObject.mPos.y >> 4;
    kuribo->mMapObject.mMatrix.mRows[3].z = kuribo->mMapObject.mPos.z >> 4;
    if (kuribo->mFrameIndex < KURIBO_WALK_HALF_FRAMES) {
        gKuribo->mFrameIndex = kuribo->mFrameIndex;
    } else {
        scale.x = -scale.x;
        gKuribo->mFrameIndex = kuribo->mFrameIndex - 0x14;
    }
    modelAlpha = kuribo->mModelAlpha;
    model = gKuribo;
    model->mPolygonAttributes &= ~0x1f0000;
    model->mPolygonAttributes |= modelAlpha << 16;
    DrawNsbmdModelWithMatrixAndMaxAlpha(gKuribo, &kuribo->mMapObject.mMatrix, &scale, 0, maxAlpha);
}

void UpdateKuribo(void *unused, Kuribo *kuribo) {
    SoundStartParams soundRequest;
    RandomState64 *random;
    s32 falloffIndex;
    kuribo->mFrameIndex++;
    if (kuribo->mFrameIndex == KURIBO_WALK_HALF_FRAMES || kuribo->mFrameIndex == KURIBO_WALK_CYCLE_FRAMES) {
        if ((kuribo->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
            if (kuribo->mMapObject.mFarDistanceSquared ==
                gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared) {
                falloffIndex = SOUND_FALLOFF_SHORT_RANGE;
            } else if (kuribo->mMapObject.mFarDistanceSquared ==
                       gSoundFalloffs[SOUND_FALLOFF_MEDIUM_RANGE].mFarDistanceSquared) {
                falloffIndex = SOUND_FALLOFF_MEDIUM_RANGE;
            } else {
                falloffIndex = SOUND_FALLOFF_LONG_RANGE;
            }
            soundRequest.mSoundId = KURIBO_STEP_SOUND_ID;
            soundRequest.mPositionSource = &kuribo->mMapObject.mPos;
            soundRequest.mFalloffIndex = falloffIndex;
            soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&kuribo->mMapObject.mPos);
            StartSoundFromParams(&soundRequest);
        }
    }
    if (kuribo->mFrameIndex >= KURIBO_WALK_CYCLE_FRAMES) {
        if (kuribo->mFrameRandomized != 0) {
            kuribo->mFrameIndex = 0;
        } else {
            random = &gRaceProgress->mRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            kuribo->mFrameIndex = ((u64) (u32) (random->mValue >> 32) * 0x28) >> 32;
            kuribo->mFrameRandomized = 1;
        }
    }
    AdvanceStateMachine(&kuribo->mMapObject.mStateMachine);
}

