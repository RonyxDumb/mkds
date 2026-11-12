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
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
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
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/wanwan.h"

StateCallbacks gWanwanStateTable[] = {
    {EnterWanwanState0, UpdateWanwanState0},    {EnterWanwanState1, UpdateWanwanState1},
    {EnterWanwanState2, UpdateWanwanState2},    {EnterWanwanState3, UpdateWanwanState3},
    {EnterWanwanState4, UpdateWanwanState4Nop}, {EnterWanwanState5, UpdateWanwanState5},
};
Quaternion data_0216beec = {{0, 0, 0, 0x1000}};
SoundStartParams data_0216bedc = {0x12d, NULL, 2, 0};
struct ShadowModel *gWanwanRockShadow;
struct Nsbmd *gWanwan;

#pragma thumb off

static inline s64 WanwanXzLengthSquared(const Vec3 *vector) {
    return HORIZONTAL_LENGTH_SQUARED(*vector);
}

void UpdateWanwanState5(Wanwan *wanwan) {
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
    if (wanwan->mMapObject.mStateMachine.mStateFrames < 0x40) {
        wanwan->mOrientationBlendAmount = wanwan->mOrientationBlendAmount + 0x1c;
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
    wanwan->mUnk_f0 = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mScale.y, 0x1e000);
    wanwan->mUnk_f4 = 0xf000 - wanwan->mUnk_f0;
    wanwan->mUnk_f8 = (row->mSettings[0] * 0x3000) >> 2;
    wanwan->mUnk_1dc = TO_FIXED12(row->mSettings[1]);
    wanwan->mMaxRadius = TO_FIXED12(row->mSettings[0]);
    wanwan->mUnk_1fc = wanwan->mUnk_f8 - (wanwan->mUnk_f0 << 1);
    wanwan->mFollowsPath = 0;
    wanwan->mUsesCourseCollision = 0;
    wanwan->mChainObject = (WanwanChainObject *) CreateMapObjectFromObject(&wanwan->mMapObject, 0x197);
    wanwan->mUnk_ac = wanwan->mCenterPos.y;
    wanwan->mCenterPos.y = wanwan->mCenterPos.y + wanwan->mUnk_f0;
    InitStateMachine(&wanwan->mMapObject.mStateMachine, gWanwanStateTable, 6, wanwan);
    SetStateMachineState(&wanwan->mMapObject.mStateMachine, 0);
    wanwan->mUnk_200 = wanwan->mMapObject.mMatrix.mRows[2];
    ResetWanwan(wanwan);
    wanwan->mCollisionSlot = CreateCollisionSlot(&wanwan->mMapObject.mPos, wanwan->mMaxRadius, 0x400, wanwan);
    wanwan->mMapObject.mFarDistanceSquared = gSoundFalloffs[4].mFarDistanceSquared;
}
#pragma thumb off

#pragma thumb on
void InitWanwanOnPath(Wanwan *wanwan, CourseMapRow *row) {
    wanwan->mCenterPos = row->mPosition;
    wanwan->mUnk_f0 = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mScale.y, 0x1e000);
    wanwan->mUnk_f4 = 0xf000 - wanwan->mUnk_f0;
    wanwan->mFollowsPath = 1;
    wanwan->mUsesCourseCollision = row->mSettings[1];
    wanwan->mUnk_ac = wanwan->mCenterPos.y;
    wanwan->mCenterPos.y = wanwan->mCenterPos.y + wanwan->mUnk_f0;
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
    wanwan->mSurfaceOrientation = data_0216beec;
    QuaternionFromAngleAroundY(
        (u16) ((((s64) FX_Atan2(wanwan->mMapObject.mPosStep.x, wanwan->mMapObject.mPosStep.z) * 0x28be60db9391LL) +
                0x80000000000LL) >>
               44),
        &wanwan->mYawQuaternion);
    QuaternionMultiplyByYawIgnoreY(&wanwan->mSurfaceOrientation, &wanwan->mYawQuaternion, &wanwan->mOrientation);
    Matrix3x3FromQuaternion(&wanwan->mMapObject.mMatrix.mAxes, &wanwan->mOrientation);
    wanwan->mUnk_e4 = 0;
    if (wanwan->mFollowsPath == 0) {
        ResetWanwanChainPoints(wanwan->mChainObject);
    }
    if (wanwan->mFollowsPath == 0) {
        wanwan->mCurvePoints[0] = &wanwan->mCurvePointValues[0];
        wanwan->mCurvePoints[1] = &wanwan->mCurvePointValues[1];
        wanwan->mCurvePoints[2] = &wanwan->mCurvePointValues[2];
        wanwan->mCurvePoints[3] = &wanwan->mCurvePointValues[3];
        if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
            VEC_MultAdd(0xf000, &wanwan->mUnk_200, &wanwan->mMapObject.mPos, &wanwan->mMapObject.mPos);
            wanwan->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(wanwan->mUnk_200.x, 0x400);
            wanwan->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(wanwan->mUnk_200.y, 0x400);
            wanwan->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(wanwan->mUnk_200.z, 0x400);
            QuaternionFromAngleAroundY(
                (u16) ((((s64) FX_Atan2(wanwan->mMapObject.mPosStep.x, wanwan->mMapObject.mPosStep.z) *
                         0x28be60db9391LL) +
                        0x80000000000LL) >>
                       44),
                &wanwan->mYawQuaternion);
            wanwan->mMapObject.mStateMachine.mNextState = 4;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        } else {
            wanwan->mMapObject.mStateMachine.mNextState = 0;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
}
#pragma thumb off

// Shared by kinds 0x196 and 0x1a5 (class Wanwan). Only kind 0x196 objects reach states 0, 1, 3 and 4;
// a kind 0x1a5 object starts in state 5 and moves between states 2 and 5.
// State 4 has no update step.
