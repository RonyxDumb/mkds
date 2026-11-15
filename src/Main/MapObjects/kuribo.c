#include "Main/MapObjects/kuribo.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/water.h"
#include "Main/MapObjects/kuribo_init.h"

#include "Main/Race/data_020f36d8.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/code_020ebef8.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/mission_run_koura_effects.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "ITCM/sphere_collision.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/dossun.h"
#include "Main/MapObjects/dossun_kind_descriptor.h"

StateCallbacks gKuriboStateTable[6] = {{EnterKuriboWalkPath, UpdateKuriboWalkPath},
                                       {EnterKuriboFallToSurface, UpdateKuriboFallToSurface},
                                       {EnterKuriboStretch, UpdateKuriboStretch},
                                       {(StateCallback) EnterKuriboShrink, UpdateKuriboShrink},
                                       {(StateCallback) EnterKuriboFlatWait, UpdateKuriboFlatWait},
                                       {EnterKuriboSpringBack, UpdateKuriboSpringBack}};

const struct Quaternion gKuriboBombResetOrientation = {{0, 0, 0, 0x1000}};
const struct Quaternion gKuriboBombResetTargetOrientation = {{0, 0, 0, 0x1000}};

void EnterKuriboWalkPath(void *stateObject) {
    Kuribo *kuribo = stateObject;
    kuribo->mScaleFactorY = KURIBO_SCALE_FACTOR_Y_REST;
    kuribo->mScaleFactorYSpeed = 0x0u;
}

void UpdateKuriboWalkPath(void *stateObject) {
    Kuribo *kuribo = stateObject;
    if (kuribo->mFrameIndex >= KURIBO_WALK_QUARTER_FRAMES &&
        (kuribo->mFrameIndex < KURIBO_WALK_HALF_FRAMES || kuribo->mFrameIndex >= KURIBO_WALK_THREE_QUARTER_FRAMES)) {
        AdvanceGroupFollower(&kuribo->mFollower);
    }
    GetGroupFollowerCurvePosition(&kuribo->mFollower, &kuribo->mMapObject.mPos);
    if (kuribo->mScaleFactorY == KURIBO_SCALE_FACTOR_Y_REST && kuribo->mScaleFactorYSpeed == 0) {
        return;
    }
    kuribo->mScaleFactorYSpeed +=
        MUL_FIXED12_NO_ROUND(KURIBO_SCALE_FACTOR_Y_REST - kuribo->mScaleFactorY, KURIBO_SCALE_SPRING_STIFFNESS);
    kuribo->mScaleFactorYSpeed = MUL_FIXED12_NO_ROUND(kuribo->mScaleFactorYSpeed, KURIBO_SCALE_DAMPING);
    kuribo->mScaleFactorY += kuribo->mScaleFactorYSpeed;
    if (kuribo->mScaleFactorY > KURIBO_SCALE_FACTOR_Y_REST - KURIBO_SCALE_SETTLE_RANGE &&
        kuribo->mScaleFactorY < KURIBO_SCALE_FACTOR_Y_REST + KURIBO_SCALE_SETTLE_RANGE &&
        kuribo->mScaleFactorYSpeed > -KURIBO_SCALE_SETTLE_RANGE &&
        kuribo->mScaleFactorYSpeed < KURIBO_SCALE_SETTLE_RANGE) {
        kuribo->mScaleFactorY = KURIBO_SCALE_FACTOR_Y_REST;
        kuribo->mScaleFactorYSpeed = 0;
    }
}

void EnterKuriboFallToSurface(void *stateObject) {
    Kuribo *kuribo = stateObject;
    kuribo->mScaleFactorY = KURIBO_SCALE_FACTOR_Y_REST;
    kuribo->mScaleFactorYSpeed = 0x0u;
}

void UpdateKuriboFallToSurface(void *stateObject) {
    Kuribo *kuribo = stateObject;
    u32 surfaceFlags;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    if (kuribo->mFrameIndex < KURIBO_WALK_QUARTER_FRAMES ||
        (kuribo->mFrameIndex >= KURIBO_WALK_HALF_FRAMES && kuribo->mFrameIndex < KURIBO_WALK_THREE_QUARTER_FRAMES)) {
        if (kuribo->mFrameIndex == 0 || kuribo->mFrameIndex == KURIBO_WALK_HALF_FRAMES) {
            kuribo->mToggleCountdown--;
            if (kuribo->mToggleCountdown < 0) {
                kuribo->mToggleCountdown = 3;
                kuribo->mToggleState = kuribo->mToggleState == 0;
            }
        }
    }
    kuribo->mMapObject.mPosStep.y -= 0x400;
    kuribo->mMapObject.mPos.y += kuribo->mMapObject.mPosStep.y;
    probePos = kuribo->mMapObject.mPos;
    probePos.y += 0xa000;
    if (CollideSphereWithCourse(&probePos, NULL, 0, 0xa000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags,
                                NULL, NULL, NULL, NULL) != 0) {
        VEC_Add(&kuribo->mMapObject.mPos, &correction, &kuribo->mMapObject.mPos);
        kuribo->mMapObject.mPosStep.y = 0;
        if ((surfaceFlags & 0x1e34ef) != 0) {
            QuaternionFromYAxisToVec3(&surfaceNormal, &kuribo->mTargetOrientation);
            kuribo->mMapObject.mFlags &= ~1;
        }
    }
    QuaternionBlendTowardNearerSign(&kuribo->mOrientation, &kuribo->mTargetOrientation, &kuribo->mOrientation,
                                    kuribo->mOrientationBlendAmount);
    if (kuribo->mOrientationBlendAmount > 0xb4) {
        kuribo->mOrientationBlendAmount = 0xb4;
    }
}

void EnterKuriboStretch(void *stateObject) {
    Kuribo *kuribo = stateObject;
    kuribo->mMapObject.mFlags = (((kuribo->mMapObject.mFlags)) | ((gKuriboFlag)));
}

void UpdateKuriboStretch(void *stateObject) {
    Kuribo *kuribo = stateObject;
    kuribo->mScaleFactorY = MUL_FIXED12_NO_ROUND(kuribo->mScaleFactorY, 0x1266);
    if (kuribo->mScaleFactorY > 0x1800) {
        kuribo->mMapObject.mStateMachine.mNextState = KURIBO_STATE_SHRINK;
        kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 EnterKuriboShrink(u32 value) {
    return value;
}

void UpdateKuriboShrink(void *stateObject) {
    Kuribo *kuribo = stateObject;
    kuribo->mScaleFactorY = MUL_FIXED12_NO_ROUND(kuribo->mScaleFactorY, KURIBO_SCALE_SHRINK_FACTOR);
    if (kuribo->mScaleFactorY < 0x333) {
        kuribo->mMapObject.mStateMachine.mNextState = KURIBO_STATE_FLAT_WAIT;
        kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 EnterKuriboFlatWait(u32 value) {
    return value;
}

void UpdateKuriboFlatWait(void *stateObject) {
    Kuribo *kuribo = stateObject;
    if (kuribo->mReturnsAfterWait != 0) {
        if (kuribo->mMapObject.mStateMachine.mStateFrames > 0x12c) {
            kuribo->mMapObject.mStateMachine.mNextState = KURIBO_STATE_SPRING_BACK;
            kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
        return;
    }
    kuribo->mModelAlpha--;
    if (kuribo->mModelAlpha == 0) {
        ParkMapObject(&kuribo->mMapObject);
    }
}

void EnterKuriboSpringBack(void *stateObject) {
    Kuribo *kuribo = stateObject;
    SoundStartParams soundRequest;
    s32 falloffIndex;
    if ((kuribo->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
        if (kuribo->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
            falloffIndex = 2;
        } else if (kuribo->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = KURIBO_SPRING_BACK_SOUND_ID;
        soundRequest.mPositionSource = &kuribo->mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&kuribo->mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    kuribo->mMapObject.mFlags &= ~1;
    kuribo->mScaleFactorYSpeed = 0;
}

void UpdateKuriboSpringBack(void *stateObject) {
    Kuribo *kuribo = stateObject;
    kuribo->mScaleFactorYSpeed +=
        MUL_FIXED12_NO_ROUND(KURIBO_SCALE_FACTOR_Y_REST - kuribo->mScaleFactorY, KURIBO_SCALE_SPRING_STIFFNESS);
    kuribo->mScaleFactorYSpeed = MUL_FIXED12_NO_ROUND(kuribo->mScaleFactorYSpeed, KURIBO_SCALE_DAMPING);
    kuribo->mScaleFactorY += kuribo->mScaleFactorYSpeed;
    if (kuribo->mMapObject.mStateMachine.mStateFrames > 0x3c) {
        kuribo->mMapObject.mStateMachine.mNextState = KURIBO_STATE_WALK_PATH;
        kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void StartItemKinokoFromKuribo(Kuribo *kuribo, Vec3 *hitVector) {
    Vec3 launchDirection;
    ItemObject *itemObject;
    s32 value;
    if (kuribo->mMapObject.mCourseMapRow == NULL || kuribo->mMapObject.mCourseMapRow->mSettings[2] != 0) {
        return;
    }
    VEC_Subtract(&kuribo->mFollower.mFromEntry->mPos, &kuribo->mFollower.mToEntry->mPos, &launchDirection);
    if (SQUARE_SUM3(launchDirection.x, launchDirection.y, launchDirection.z) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&launchDirection, &launchDirection);
    }
    {
        Vec3 flatHitVector = {0, 0, 0};
        flatHitVector.x = hitVector->x;
        flatHitVector.z = hitVector->z;
        value = VEC_DotProduct(&launchDirection, &flatHitVector);
        launchDirection.x = flatHitVector.x - MUL_FIXED12_NO_ROUND(launchDirection.x, value);
        launchDirection.y = flatHitVector.y - MUL_FIXED12_NO_ROUND(launchDirection.y, value);
        launchDirection.z = flatHitVector.z - MUL_FIXED12_NO_ROUND(launchDirection.z, value);
    }
    if (SQUARE_SUM3(launchDirection.x, launchDirection.y, launchDirection.z) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&launchDirection, &launchDirection);
    }
    itemObject = StartItemObjectOrZero(ITEM_OBJECT_KIND_KINOKO, 8, &kuribo->mMapObject.mPos, &gKuriboItemNormal);
    if (itemObject == NULL) {
        return;
    }
    itemObject->mScale.x = 0xcd;
    itemObject->mScale.y = 0xcd;
    itemObject->mScale.z = 0xcd;
    value = VEC_Mag(hitVector) + 0x5000;
    itemObject->mVelocity.x = MUL_FIXED12_NO_ROUND(launchDirection.x, value);
    itemObject->mVelocity.y = MUL_FIXED12_NO_ROUND(launchDirection.y, value);
    itemObject->mVelocity.z = MUL_FIXED12_NO_ROUND(launchDirection.z, value);
    itemObject->mVelocity.y += 0xf000;
    VEC_Add(&itemObject->mPos, &itemObject->mVelocity, &itemObject->mPos);
    LaunchItemObjectFromPos(itemObject, 0, &kuribo->mMapObject.mPos, hitVector, &gKuriboItemNormal);
}

u32 CollideKartWithKuribo(Kuribo *kuribo, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    switch (*firstResponsePtr) {
        case 0:
            if (kuribo->mScaleFactorY == KURIBO_SCALE_FACTOR_Y_REST) {
                if (kuribo->mScaleFactorYSpeed == 0) {
                    kuribo->mScaleFactorYSpeed = MUL_FIXED12_NO_ROUND(kart->mVelocityLength, 0x52);
                }
            }
            break;
        case 1:
            if (kuribo->mMapObject.mStateMachine.mState == KURIBO_STATE_WALK_PATH ||
                kuribo->mMapObject.mStateMachine.mState == KURIBO_STATE_SPRING_BACK ||
                kuribo->mMapObject.mStateMachine.mState == KURIBO_STATE_FALL_TO_SURFACE) {
                kuribo->mMapObject.mStateMachine.mNextState = KURIBO_STATE_STRETCH;
                kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
                StartSoundFullVolumeWrapper(&kart->mSoundSource, 0x185);
                StartSoundIfKartStarOrKiller(&kuribo->mMapObject, kart);
                StartItemKinokoFromKuribo(kuribo, &kart->mVelocity);
                kuribo->mMapObject.mFlags = kuribo->mMapObject.mFlags | gKuriboFlag;
            }
            break;
    }
    return *secondResponsePtr;
}

u32 CollideItemObjectWithKuribo(Kuribo *kuribo, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    switch (*firstResponsePtr) {
        case 0:
            if (kuribo->mScaleFactorY == KURIBO_SCALE_FACTOR_Y_REST) {
                if (kuribo->mScaleFactorYSpeed == 0) {
                    kuribo->mScaleFactorYSpeed = 0x19a;
                }
            }
            break;
        case 1:
            if (kuribo->mMapObject.mStateMachine.mState == KURIBO_STATE_WALK_PATH ||
                kuribo->mMapObject.mStateMachine.mState == KURIBO_STATE_SPRING_BACK ||
                kuribo->mMapObject.mStateMachine.mState == KURIBO_STATE_FALL_TO_SURFACE) {
                kuribo->mMapObject.mStateMachine.mNextState = KURIBO_STATE_STRETCH;
                kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
                StartMissionRunKouraEffects(itemObject);
                if (itemObject != NULL) {
                    StartItemKinokoFromKuribo(kuribo, &itemObject->mVelocity);
                }
                kuribo->mMapObject.mFlags = kuribo->mMapObject.mFlags | gKuriboFlag;
            }
            break;
    }
    return *secondResponsePtr;
}

void ResetKuriboForItemBomb(Kuribo *kuribo) {
    kuribo->mOrientationBlendAmount = FIXED12_ONE;
    kuribo->mOrientation = gKuriboBombResetOrientation;
    kuribo->mTargetOrientation = gKuriboBombResetTargetOrientation;
    SetStateMachineState(&kuribo->mMapObject.mStateMachine, KURIBO_STATE_FALL_TO_SURFACE);
    kuribo->mMapObject.mPosStep.x = 0;
    kuribo->mMapObject.mPosStep.y = 0;
    kuribo->mMapObject.mPosStep.z = 0;
}

#pragma thumb on

void CreateKuribo(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile("kuribo.nsbmd");
    nsbtpFile = FindCourseMapObjFile("kuribo.nsbtp");
    CreateNsbmdModel(&gKuribo, nsbmdFile, nsbtpFile, 0);
    SetNsbmdModelFixedAttributes(gKuribo);
}

#pragma thumb off
