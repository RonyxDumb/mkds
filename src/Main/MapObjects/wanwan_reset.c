#include "Main/MapObjects/wanwan_reset.h"

#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "fx_mtx33.h"
#include "code_02148538.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "ITCM/kart_motion.h"
#include "code_02147cd8.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/quaternion_math.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/wanwan.h"
#include "Main/MapObjects/vehicle_kind_descriptor.h"

#pragma thumb off

const MapObjectKindDescriptor gWanwanOnChainKindDescriptor = {
    0,
    {0, 0},
    0x20c,
    InitWanwanOnChain,
    (MapObjectKindData *(*)(void)) CreateWanwanKindData,
    (MapObjectList *(*)(void)) CreateWanwanDrawList,
    NULL,
    NULL,
    CreateWanwanUpdateList,
    NULL,
    {NULL, NULL, NULL, NULL}};
const MapObjectKindDescriptor gWanwanOnPathKindDescriptor = {
    0,
    {0, 0},
    0x20c,
    InitWanwanOnPath,
    (MapObjectKindData *(*)(void)) CreateWanwanKindData,
    (MapObjectList *(*)(void)) CreateWanwanDrawList,
    NULL,
    NULL,
    CreateWanwanUpdateList,
    NULL,
    {NULL, NULL, NULL, NULL}};
StateCallbacks gWanwanStateTable[] = {
    {EnterWanwanRoam, UpdateWanwanRoam},    {EnterWanwanLunge, UpdateWanwanLunge},
    {EnterWanwanHit, UpdateWanwanHit},    {EnterWanwanPullBack, UpdateWanwanPullBack},
    {EnterWanwanRest, UpdateWanwanRestNop}, {EnterWanwanFollowPath, UpdateWanwanFollowPath},
};
Quaternion gWanwanResetSurfaceOrientation = {{0, 0, 0, 0x1000}};
SoundStartParams gWanwanTouchGroundSoundParams = {0x12d, NULL, 2, 0};
struct ShadowModel *gWanwanRockShadow;
struct Nsbmd *gWanwan;

static inline s64 WanwanXzLengthSquared(const Vec3 *vector) {
    return HORIZONTAL_LENGTH_SQUARED(*vector);
}

void UpdateWanwanFollowPath(void *stateObject) {
    Wanwan *wanwan = stateObject;
    wanwan->mMapObject.mPosStep.x = wanwan->mMapObject.mPos.x;
    wanwan->mMapObject.mPosStep.z = wanwan->mMapObject.mPos.z;
    AdvanceGroupFollowerWithSpeeds(&wanwan->mFollower);
    GetGroupFollowerCurveXz(&wanwan->mFollower.mGroupFollower, &wanwan->mMapObject.mPos);
    wanwan->mMapObject.mPosStep.x = wanwan->mMapObject.mPos.x - wanwan->mMapObject.mPosStep.x;
    wanwan->mMapObject.mPosStep.z = wanwan->mMapObject.mPos.z - wanwan->mMapObject.mPosStep.z;
    if (WanwanXzLengthSquared(&wanwan->mMapObject.mPosStep) >= 0x10) {
        QuaternionFromAngleAroundY(
            (u16) ((((s64) FX_Atan2(wanwan->mMapObject.mPosStep.x, wanwan->mMapObject.mPosStep.z) * 0x28be60db9391LL) +
                    0x80000000000LL) >>
                   44),
            &wanwan->mYawQuaternion);
    }
    if (wanwan->mMapObject.mStateMachine.mStateFrames < WANWAN_FOLLOW_PATH_FRAMES) {
        wanwan->mOrientationBlendAmount = wanwan->mOrientationBlendAmount + WANWAN_ORIENTATION_BLEND_AMOUNT_STEP;
    }
}

#pragma thumb on
void CreateWanwanAndRockShadow(void) {
    CreateNsbmd(&gWanwan, FindCourseMapObjFile("wanwan.nsbmd"), NULL);
    CreateShadowModel(&gWanwanRockShadow, FindCourseMapObjFile("rock_shadow.nsbmd"), 0x3f);
    SetNsbmdPolygonIdLightEmiAll(gWanwan, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void InitWanwanOnChain(Wanwan *wanwan, CourseMapRow *row) {
    wanwan->mCenterPos = row->mPosition;
    wanwan->mScaledLength = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mScale.y, 0x1e000);
    wanwan->mProbeOffsetY = WANWAN_PROBE_OFFSET_Y - wanwan->mScaledLength;
    wanwan->mRadiusLimit = (row->mSettings[0] * 0x3000) >> 2;
    wanwan->mKartDetectRadius = TO_FIXED12(row->mSettings[1]);
    wanwan->mMaxRadius = TO_FIXED12(row->mSettings[0]);
    wanwan->mPullBackRadius = wanwan->mRadiusLimit - (wanwan->mScaledLength << 1);
    wanwan->mFollowsPath = 0;
    wanwan->mUsesCourseCollision = 0;
    wanwan->mChainObject = (WanwanChainObject *) CreateMapObjectFromObject(&wanwan->mMapObject, 0x197);
    wanwan->mBaseY = wanwan->mCenterPos.y;
    wanwan->mCenterPos.y = wanwan->mCenterPos.y + wanwan->mScaledLength;
    InitStateMachine(&wanwan->mMapObject.mStateMachine, gWanwanStateTable, 6, wanwan);
    SetStateMachineState(&wanwan->mMapObject.mStateMachine, 0);
    wanwan->mForward = wanwan->mMapObject.mMatrix.mRows[2];
    ResetWanwan(wanwan);
    wanwan->mCollisionSlot = CreateCollisionSlot(&wanwan->mMapObject.mPos, wanwan->mMaxRadius, 0x400, wanwan);
    wanwan->mMapObject.mFarDistanceSquared = gSoundFalloffs[4].mFarDistanceSquared;
}
#pragma thumb off

#pragma thumb on
void InitWanwanOnPath(Wanwan *wanwan, CourseMapRow *row) {
    wanwan->mCenterPos = row->mPosition;
    wanwan->mScaledLength = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mScale.y, 0x1e000);
    wanwan->mProbeOffsetY = WANWAN_PROBE_OFFSET_Y - wanwan->mScaledLength;
    wanwan->mFollowsPath = 1;
    wanwan->mUsesCourseCollision = row->mSettings[1];
    wanwan->mBaseY = wanwan->mCenterPos.y;
    wanwan->mCenterPos.y = wanwan->mCenterPos.y + wanwan->mScaledLength;
    InitStateMachine(&wanwan->mMapObject.mStateMachine, gWanwanStateTable, 6, wanwan);
    SetStateMachineState(&wanwan->mMapObject.mStateMachine, 5);
    InitGroupFollowerWithSpeeds(&wanwan->mFollower, row, gGroupFollowerSpeed, row->mSettings[0]);
    ResetWanwan(wanwan);
}
#pragma thumb off

#pragma thumb on
void ResetWanwan(Wanwan *wanwan) {
    wanwan->mMapObject.mPos = wanwan->mCenterPos;
    wanwan->mMapObject.mPosStep.x = 0;
    wanwan->mMapObject.mPosStep.y = 0;
    wanwan->mMapObject.mPosStep.z = 0;
    wanwan->mSurfaceOrientation = gWanwanResetSurfaceOrientation;
    QuaternionFromAngleAroundY(
        (u16) ((((s64) FX_Atan2(wanwan->mMapObject.mPosStep.x, wanwan->mMapObject.mPosStep.z) * 0x28be60db9391LL) +
                0x80000000000LL) >>
               44),
        &wanwan->mYawQuaternion);
    QuaternionMultiplyByYawIgnoreY(&wanwan->mSurfaceOrientation, &wanwan->mYawQuaternion, &wanwan->mOrientation);
    Matrix3x3FromQuaternion(&wanwan->mMapObject.mMatrix.mAxes, &wanwan->mOrientation);
    wanwan->mAngleAroundXOffset = 0;
    if (wanwan->mFollowsPath == 0) {
        ResetWanwanChainPoints(wanwan->mChainObject);
    }
    if (wanwan->mFollowsPath == 0) {
        wanwan->mCurvePoints[0] = &wanwan->mCurvePointValues[0];
        wanwan->mCurvePoints[1] = &wanwan->mCurvePointValues[1];
        wanwan->mCurvePoints[2] = &wanwan->mCurvePointValues[2];
        wanwan->mCurvePoints[3] = &wanwan->mCurvePointValues[3];
        if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
            VEC_MultAdd(0xf000, &wanwan->mForward, &wanwan->mMapObject.mPos, &wanwan->mMapObject.mPos);
            wanwan->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(wanwan->mForward.x, 0x400);
            wanwan->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(wanwan->mForward.y, 0x400);
            wanwan->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(wanwan->mForward.z, 0x400);
            QuaternionFromAngleAroundY(
                (u16) ((((s64) FX_Atan2(wanwan->mMapObject.mPosStep.x, wanwan->mMapObject.mPosStep.z) *
                         0x28be60db9391LL) +
                        0x80000000000LL) >>
                       44),
                &wanwan->mYawQuaternion);
            wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_REST;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        } else {
            wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_ROAM;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
}
#pragma thumb off

// Shared by kinds 0x196 and 0x1a5 (class Wanwan). Only kind 0x196 objects reach states 0, 1, 3 and 4;
// a kind 0x1a5 object starts in state 5 and moves between states 2 and 5.
// State 4 has no update step.
