#include "Main/MapObjects/wanwan.h"

#include "Main/MapObjects/wanwan_chain_object.h" // WanwanChainObject
#include "code_02147cd8.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/dossun.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "code_02148538.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/segment_progress_point.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "ITCM/kart_motion.h"
#include "ITCM/sphere_collision.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Menu/choises_s.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/wanwan_reset.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Kart/karts.h"

MapObjectList *gWanwanUpdateList = 0;
WanwanDrawList *gWanwanDrawList = 0;

const WanwanKindData gWanwanKindData = {
    CollideKartWithWanwan, CollideItemObjectWithWanwan, 1, 0x1b000, {0}, 1, 1, 0x12e, {0}};
const WanwanDrawList gWanwanDrawListData = {{0}, CreateWanwanAndRockShadow, {0}, DrawWanwan, {0}, 1, {0}, 0};
const MapObjectList gWanwanUpdateListData = {NULL, 0, {0}, NULL, NULL, UpdateWanwan, NULL, 0, NULL, 0, NULL};

WanwanKindData *CreateWanwanKindData(void) {
    WanwanKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(WanwanKindData));
    *kindData = gWanwanKindData;
    return kindData;
}

WanwanDrawList *CreateWanwanDrawList(void) {
    WanwanDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(WanwanDrawList));
    gWanwanDrawList = drawList;
    *drawList = gWanwanDrawListData;
    SetDrawListSlot(&gWanwanDrawList);
    return gWanwanDrawList;
}

MapObjectList *CreateWanwanUpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
    gWanwanUpdateList = updateList;
    *updateList = gWanwanUpdateListData;
    SetUpdateListSlot(&gWanwanUpdateList);
    return gWanwanUpdateList;
}

void DrawWanwan(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha) {
    MtxFx43 shadowMatrix;

    if (wanwan->mMapObject.mStateMachine.mState == WANWAN_STATE_REST) {
        if (GetChoisesSOpenDuringRace() == 0) {
            wanwan->mMapObject.mPos.x += wanwan->mMapObject.mPosStep.x;
            wanwan->mMapObject.mPos.z += wanwan->mMapObject.mPosStep.z;
        }
    }
    wanwan->mMapObject.mMatrix.mRows[3].x = wanwan->mMapObject.mPos.x >> 4;
    wanwan->mMapObject.mMatrix.mRows[3].y = wanwan->mMapObject.mPos.y >> 4;
    wanwan->mMapObject.mMatrix.mRows[3].z = wanwan->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gWanwan, &wanwan->mMapObject.mMatrix, &wanwan->mMapObject.mScale, maxAlpha);
    Matrix3x3FromQuaternion(&shadowMatrix.mAxes, &wanwan->mYawQuaternion);
    shadowMatrix.mRows[3].x = wanwan->mMapObject.mPos.x >> 4;
    shadowMatrix.mRows[3].y = wanwan->mMapObject.mPos.y >> 4;
    shadowMatrix.mRows[3].z = wanwan->mMapObject.mPos.z >> 4;
    DrawShadowWithMaxAlpha(gWanwanRockShadow, &shadowMatrix, &wanwan->mMapObject.mScale, maxAlpha);
}

void UpdateWanwan(void *unused, Wanwan *wanwan) {
    u32 surfaceFlags;
    Quaternion targetOrientation;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    SoundStartParams thirdSoundParams;
    s32 usesCourseCollision;
    BOOL touchesGround;
    s32 directionX;
    s32 directionZ;
    s32 value;
    s32 falloffIndex;

    usesCourseCollision = wanwan->mUsesCourseCollision;
    AdvanceStateMachine(&wanwan->mMapObject.mStateMachine);
    wanwan->mMapObject.mPosStep.y -= 0x400;
    wanwan->mMapObject.mPos.y += wanwan->mMapObject.mPosStep.y;
    touchesGround = FALSE;
    probePos.x = wanwan->mMapObject.mPos.x;
    probePos.y = wanwan->mMapObject.mPos.y + wanwan->mProbeOffsetY + 0x5000;
    probePos.z = wanwan->mMapObject.mPos.z;
    if (usesCourseCollision == 0) {
        correction.y = wanwan->mBaseY + 0xd000 - probePos.y;
        if (correction.y > 0) {
            touchesGround = TRUE;
            correction.x = 0;
            correction.z = 0;
            if (wanwan->mFollowsPath != 0) {
                if (!(wanwan->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE)) {
                    if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                        falloffIndex = 2;
                    } else if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    secondSoundParams.mSoundId = WANWAN_PATH_BASE_LAND_SOUND_ID;
                    secondSoundParams.mPositionSource = &wanwan->mMapObject.mPos;
                    secondSoundParams.mFalloffIndex = falloffIndex;
                    secondSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&wanwan->mMapObject.mPos);
                    StartSoundFromParams(&secondSoundParams);
                }
            }
        }
    } else {
        if (CollideSphereWithCourse(&probePos, NULL, 0, 0xd000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags,
                                    NULL, NULL, NULL, NULL) != 0) {
            touchesGround = TRUE;
            if (wanwan->mFollowsPath != 0) {
                if (!(wanwan->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE)) {
                    if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                        falloffIndex = 2;
                    } else if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    thirdSoundParams.mSoundId = WANWAN_PATH_COURSE_LAND_SOUND_ID;
                    thirdSoundParams.mPositionSource = &wanwan->mMapObject.mPos;
                    thirdSoundParams.mFalloffIndex = falloffIndex;
                    thirdSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&wanwan->mMapObject.mPos);
                    StartSoundFromParams(&thirdSoundParams);
                }
            }
        }
    }
    if (touchesGround != FALSE) {
        touchesGround = TRUE;
        if (wanwan->mMapObject.mStateMachine.mState == WANWAN_STATE_HIT) {
            if (wanwan->mMapObject.mStateMachine.mStateFrames < WANWAN_HIT_FRAMES) {
                touchesGround = FALSE;
            }
        }
        wanwan->mMapObject.mPos.y += correction.y;
        if (wanwan->mFollowsPath != 0 || touchesGround != FALSE) {
            if (wanwan->mFollowsPath != 0) {
                directionX = wanwan->mFollower.mGroupFollower.mToEntry->mPos.x;
                directionZ = wanwan->mFollower.mGroupFollower.mToEntry->mPos.z;
            } else {
                directionX = wanwan->mCurvePoints[2]->x - wanwan->mMapObject.mPos.x;
                directionZ = wanwan->mCurvePoints[2]->z - wanwan->mMapObject.mPos.z;
            }
            value = ((s64) (s32) DOT2_FIXED12(wanwan->mMapObject.mPosStep.x, directionX, wanwan->mMapObject.mPosStep.z,
                                              directionZ)
                     << 9) >>
                    12;
            if (value > 0x3000) {
                value = 0x3000;
            } else if (value < 0x2800) {
                value = 0x2800;
            }
            wanwan->mMapObject.mPosStep.y = value;
        } else if (wanwan->mAngleAroundX == WANWAN_ANGLE_AROUND_X_HIT) {
            wanwan->mMapObject.mPosStep.y = 0x2000;
            wanwan->mAngleAroundX += 0x1000;
        } else {
            wanwan->mMapObject.mPosStep.y = 0;
        }
        if (usesCourseCollision != 0) {
            if (surfaceFlags & 0x1e34ef) {
                value = DOT2_FIXED12(wanwan->mMapObject.mPosStep.x, surfaceNormal.x, wanwan->mMapObject.mPosStep.z,
                                     surfaceNormal.z);
                if (value < 0) {
                    wanwan->mMapObject.mPosStep.y += MUL_FIXED12_NO_ROUND(-value, 0x14cd);
                }
                QuaternionFromYAxisToVec3(&surfaceNormal, &wanwan->mSurfaceOrientation);
            }
        }
        if (wanwan->mFollowsPath == 0 &&
            !(wanwan->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) &&
            touchesGround != FALSE) {
            firstSoundParams = gWanwanTouchGroundSoundParams;
            firstSoundParams.mPositionSource = &wanwan->mMapObject.mPos;
            firstSoundParams.mDistanceSquared = wanwan->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f;
            StartSoundFromParams(&firstSoundParams);
        }
    }
    if (usesCourseCollision != 0) {
        QuaternionMultiplyByYawIgnoreY(&wanwan->mSurfaceOrientation, &wanwan->mYawQuaternion, &targetOrientation);
    }
    wanwan->mAngleAroundXOffset =
        wanwan->mAngleAroundXOffset + ((-wanwan->mMapObject.mPosStep.y >> 1) - wanwan->mAngleAroundXOffset >> 4);
    if (usesCourseCollision != 0) {
        QuaternionMultiplyAngleAroundX(&targetOrientation, (u16) (wanwan->mAngleAroundX + wanwan->mAngleAroundXOffset),
                                       &targetOrientation);
    } else {
        QuaternionMultiplyAngleAroundXIgnoreXZ(
            &wanwan->mYawQuaternion, (u16) (wanwan->mAngleAroundX + wanwan->mAngleAroundXOffset), &targetOrientation);
    }
    QuaternionBlendTowardNearerSign(&wanwan->mOrientation, &targetOrientation, &wanwan->mOrientation,
                                    wanwan->mOrientationBlendAmount);
    QuaternionNormalizeUnlessNearOne(&wanwan->mOrientation, &wanwan->mOrientation);
    Matrix3x3FromQuaternion(&wanwan->mMapObject.mMatrix.mAxes, &wanwan->mOrientation);
    if (wanwan->mMapObject.mPos.y >= 0) {
        return;
    }
    ResetWanwan(wanwan);
}

u8 CollideKartWithWanwan(Wanwan *wanwan, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        if (wanwan->mMapObject.mStateMachine.mState != WANWAN_STATE_HIT || wanwan->mMapObject.mPosStep.y < 0x4000) {
            wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_HIT;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
            StartSoundIfKartStarOrKiller(&wanwan->mMapObject, kart);
        }
    }
    return *secondResponsePtr;
}

u8 CollideItemObjectWithWanwan(Wanwan *wanwan, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        if (wanwan->mMapObject.mStateMachine.mState != WANWAN_STATE_HIT || wanwan->mMapObject.mPosStep.y < 0x4000) {
            wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_HIT;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
    return *secondResponsePtr;
}

// Kind 0x196 only (kind 0x1a5 never reaches ROAM).
void EnterWanwanRoam(void *stateObject) {
    Wanwan *wanwan = stateObject;
    Vec3 *savedPoint;

    wanwan->mAngleAroundX = WANWAN_ANGLE_AROUND_X_LEVEL;
    wanwan->mOrientationBlendAmount = WANWAN_ORIENTATION_BLEND_AMOUNT_START;
    wanwan->mChainObject->mChain.mDownwardStep = WANWAN_CHAIN_DOWNWARD_STEP_INITIAL;
    savedPoint = wanwan->mCurvePoints[0];
    wanwan->mCurvePoints[0] = NULL;
    *wanwan->mCurvePoints[1] = wanwan->mMapObject.mPos;
    *wanwan->mCurvePoints[2] = *wanwan->mCurvePoints[1];
    wanwan->mCurvePoints[2]->x += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mRows[2].x, wanwan->mScaledLength);
    wanwan->mCurvePoints[2]->z += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mRows[2].z, wanwan->mScaledLength);
    *wanwan->mCurvePoints[3] = *wanwan->mCurvePoints[2];
    wanwan->mCurvePoints[3]->x += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mRows[0].x, wanwan->mScaledLength);
    wanwan->mCurvePoints[3]->z += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mRows[0].z, wanwan->mScaledLength);
    InitSegmentProgress(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints, 0x1000);
    wanwan->mCurvePoints[0] = savedPoint;
}

static inline s64 WanwanGetHorizontalLengthSquared(const Vec3 *vector) {
    return HORIZONTAL_LENGTH_SQUARED(*vector);
}

// Kind 0x196 only (kind 0x1a5 never reaches ROAM).
void UpdateWanwanRoam(void *stateObject) {
    Wanwan *wanwan = stateObject;
    Vec3 *candidate;
    Vec3 *lastPoint;
    RandomState64 *random;
    Kart *kart;
    s32 attemptCount;
    s32 lastStepZ;
    s32 lastStepX;
    s32 radiusLimit;
    u32 radiusRange;
    s32 radiusExtra;
    s32 radius;
    s32 offsetX;
    s32 offsetZ;
    s32 dot;
    s32 value;
    u32 angleIndex;
    u16 kartIndex;

    wanwan->mMapObject.mPosStep.x = wanwan->mMapObject.mPos.x;
    wanwan->mMapObject.mPosStep.z = wanwan->mMapObject.mPos.z;
    if (AdvanceSegmentProgress(&wanwan->mSegmentProgress) != FALSE) {
        lastStepX = wanwan->mCurvePoints[3]->x - wanwan->mCurvePoints[2]->x;
        lastStepZ = wanwan->mCurvePoints[3]->z - wanwan->mCurvePoints[2]->z;
        do {
            attemptCount = 0;
            candidate = wanwan->mCurvePoints[0];
            while (1) {
                radiusLimit = wanwan->mRadiusLimit;
                random = GetMapObjectRandom();
                radiusRange = radiusLimit - 0x2d000;
                if (radiusRange == 0) {
                    radiusExtra = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    if (radiusRange == 0) {
                        radiusExtra = (u32) (random->mValue >> 32);
                    } else {
                        radiusExtra = (u32) (((u64) (random->mValue >> 32) * (u64) radiusRange) >> 32);
                    }
                }
                random = GetMapObjectRandom();
                radius = radiusExtra + 0x2d000;
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                angleIndex = (u16) (((random->mValue >> 32) * 0x10000) >> 32) >> 4;
                attemptCount++;
                candidate->x = wanwan->mCenterPos.x + MUL_FIXED12_NO_ROUND(FX_SinCosTable_[angleIndex * 2], radius);
                candidate->z = wanwan->mCenterPos.z + MUL_FIXED12_NO_ROUND(FX_SinCosTable_[angleIndex * 2 + 1], radius);
                if (attemptCount > 5) {
                    break;
                }
                lastPoint = wanwan->mCurvePoints[3];
                offsetX = candidate->x - lastPoint->x;
                offsetZ = candidate->z - lastPoint->z;
                if ((s64) (s32) offsetX * offsetX + (s64) (s32) offsetZ * offsetZ < 0x7e9000000LL) {
                    continue;
                }
                dot = DOT2_FIXED12(offsetX, lastStepX, offsetZ, lastStepZ);
                if (dot < 0) {
                    dot = -dot;
                    value = (-(s64) offsetX * lastStepZ + (s64) offsetZ * lastStepX) >> 12;
                    if (value < 0) {
                        value = -value;
                    }
                    if (dot >> 2 >= value) {
                        continue;
                    }
                }
                break;
            }
            wanwan->mCurvePoints[0] = wanwan->mCurvePoints[1];
            wanwan->mCurvePoints[1] = wanwan->mCurvePoints[2];
            wanwan->mCurvePoints[2] = wanwan->mCurvePoints[3];
            wanwan->mCurvePoints[3] = candidate;
        } while (BuildNextSegmentProgress(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints) != FALSE);
    }
    GetSegmentProgressPointXz(&wanwan->mSegmentProgress, &wanwan->mMapObject.mPos);
    if (!(wanwan->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI)) {
        kartIndex = GetRaceUpdateFramesModKartCount();
        kart = GetKart(kartIndex);
        if (IsKartNotNormal(kart) == FALSE) {
            value = wanwan->mKartDetectRadius;
            if ((s64) (kart->mPos.x - wanwan->mCenterPos.x) * (kart->mPos.x - wanwan->mCenterPos.x) +
                    (s64) (kart->mPos.z - wanwan->mCenterPos.z) * (kart->mPos.z - wanwan->mCenterPos.z) <
                (s64) value * value) {
                wanwan->mKartPos = &GetKart(kartIndex)->mPos;
                wanwan->mKartVelocity = &GetKart(kartIndex)->mVelocity;
                wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_LUNGE;
                wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
            }
        }
    }
    wanwan->mMapObject.mPosStep.x = wanwan->mMapObject.mPos.x - wanwan->mMapObject.mPosStep.x;
    wanwan->mMapObject.mPosStep.z = wanwan->mMapObject.mPos.z - wanwan->mMapObject.mPosStep.z;
    if (WanwanGetHorizontalLengthSquared(&wanwan->mMapObject.mPosStep) >= 0x10) {
        QuaternionFromAngleAroundY(
            (u16) (((s64) FX_Atan2(wanwan->mMapObject.mPosStep.x, wanwan->mMapObject.mPosStep.z) * 0x28be60db9391LL +
                    0x80000000000LL) >>
                   44),
            &wanwan->mYawQuaternion);
    }
    if (wanwan->mMapObject.mStateMachine.mStateFrames < WANWAN_ROAM_START_FRAMES) {
        wanwan->mOrientationBlendAmount += WANWAN_ORIENTATION_BLEND_AMOUNT_STEP;
    }
}

void EnterWanwanLunge(void *stateObject) {
    Wanwan *wanwan = stateObject;
    SoundStartParams soundRequest;
    s32 falloffIndex;

    wanwan->mAngleAroundX = WANWAN_ANGLE_AROUND_X_LUNGE;
    wanwan->mOrientationBlendAmount = WANWAN_ORIENTATION_BLEND_AMOUNT_START;
    wanwan->mTargetPos = wanwan->mMapObject.mPos;
    wanwan->mChainObject->mChain.mDownwardStep = WANWAN_CHAIN_DOWNWARD_STEP_HIT;
    wanwan->mTargetFrame = 0;
    if (wanwan->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) {
        return;
    }
    if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
        falloffIndex = 2;
    } else if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    soundRequest.mSoundId = WANWAN_LUNGE_SOUND_ID;
    soundRequest.mPositionSource = &wanwan->mMapObject.mPos;
    soundRequest.mFalloffIndex = falloffIndex;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&wanwan->mMapObject.mPos);
    StartSoundFromParams(&soundRequest);
}

void UpdateWanwanLunge(void *stateObject) {
    Wanwan *wanwan = stateObject;
    Vec3 offset;
    Vec3 predictedPos;
    s32 value;
    s32 scale;
    s32 length;

    if (wanwan->mMapObject.mStateMachine.mStateFrames > wanwan->mTargetFrame) {
        VEC_Subtract(wanwan->mKartPos, &wanwan->mMapObject.mPos, &offset);
        value = CROSS2_FIXED12(wanwan->mKartVelocity->x, offset.z, wanwan->mKartVelocity->z, offset.x);
        value = -value >> 12;
        if (value < 0) {
            value = -value;
        }
        scale = MUL_FIXED12_NO_ROUND(value, 0x7a);
        predictedPos.x = wanwan->mKartVelocity->x * scale;
        predictedPos.z = wanwan->mKartVelocity->z * scale;
        VEC_Add(&predictedPos, wanwan->mKartPos, &predictedPos);
        VEC_Subtract(&predictedPos, &wanwan->mCenterPos, &offset);
        length = Vec3NormalizeXZAndGetLengthOrZero(&offset, &offset);
        if (length > wanwan->mScaledLength) {
            length -= wanwan->mScaledLength >> 1;
        }
        if (length > wanwan->mMaxRadius) {
            length = wanwan->mMaxRadius;
        }
        offset.x = MUL_FIXED12_NO_ROUND(offset.x, length);
        offset.y = MUL_FIXED12_NO_ROUND(offset.y, length);
        offset.z = MUL_FIXED12_NO_ROUND(offset.z, length);
        VEC_Add(&offset, &wanwan->mCenterPos, &wanwan->mTargetPos);
        wanwan->mTargetFrame += 0xb4;
    }
    VEC_Subtract(&wanwan->mTargetPos, &wanwan->mMapObject.mPos, &offset);
    wanwan->mMapObject.mPosStep.x += (s32) (((s64) offset.x << 5) >> 12);
    wanwan->mMapObject.mPosStep.z += (s32) (((s64) offset.z << 5) >> 12);
    if (WanwanGetHorizontalLengthSquared(&wanwan->mMapObject.mPosStep) >= 0x40000000) {
        wanwan->mMapObject.mPosStep.x -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.x, 0x4cc);
        wanwan->mMapObject.mPosStep.z -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.z, 0x4cc);
    }
    if (WanwanGetHorizontalLengthSquared(&offset) < (s64) (wanwan->mScaledLength >> 1) * (wanwan->mScaledLength >> 1)) {
        wanwan->mMapObject.mPosStep.x >>= 1;
        wanwan->mMapObject.mPosStep.z >>= 1;
    } else {
        QuaternionFromAngleAroundY(
            (u16) (((s64) FX_Atan2(offset.x, offset.z) * 0x28be60db9391LL + 0x80000000000LL) >> 44),
            &wanwan->mYawQuaternion);
    }
    value = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.x, offset.z);
    value -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.z, offset.x);
    if ((HORIZONTAL_LENGTH_SQUARED(offset)) * 10 < (s64) value * value) {
        wanwan->mMapObject.mPosStep.x >>= 1;
        wanwan->mMapObject.mPosStep.z >>= 1;
    }
    wanwan->mMapObject.mPos.x += wanwan->mMapObject.mPosStep.x;
    wanwan->mMapObject.mPos.z += wanwan->mMapObject.mPosStep.z;
    VEC_Subtract(&wanwan->mMapObject.mPos, &wanwan->mCenterPos, &offset);
    if (HORIZONTAL_LENGTH_SQUARED(offset) >= (s64) wanwan->mMaxRadius * wanwan->mMaxRadius) {
        Vec3NormalizeXZAndGetLengthOrZero(&offset, &offset);
        wanwan->mMapObject.mPos.x = wanwan->mCenterPos.x + MUL_FIXED12_NO_ROUND(offset.x, wanwan->mMaxRadius);
        wanwan->mMapObject.mPos.z = wanwan->mCenterPos.z + MUL_FIXED12_NO_ROUND(offset.z, wanwan->mMaxRadius);
        scale = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.x, offset.x);
        length = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.z, offset.z);
        if (scale + length > 0) {
            wanwan->mMapObject.mPosStep.x -= MUL_FIXED12_NO_ROUND(scale, offset.x);
            wanwan->mMapObject.mPosStep.z -= MUL_FIXED12_NO_ROUND(length, offset.z);
        }
    }
    if (wanwan->mMapObject.mStateMachine.mStateFrames >= WANWAN_LUNGE_FRAMES) {
        wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_PULL_BACK;
        wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanHit(void *stateObject) {
    Wanwan *wanwan = stateObject;
    wanwan->mAngleAroundX = WANWAN_ANGLE_AROUND_X_HIT;
    wanwan->mOrientationBlendAmount = WANWAN_ORIENTATION_BLEND_AMOUNT_START;
    if (wanwan->mFollowsPath == 0) {
        wanwan->mChainObject->mChain.mDownwardStep = WANWAN_CHAIN_DOWNWARD_STEP_HIT;
    }
    wanwan->mMapObject.mPosStep.y = 0x8000;
}

void UpdateWanwanHit(void *stateObject) {
    Wanwan *wanwan = stateObject;
    const Vec3 *velocity;

    if (wanwan->mFollowsPath != 0) {
        wanwan->mMapObject.mPosStep.x = wanwan->mMapObject.mPos.x;
        wanwan->mMapObject.mPosStep.z = wanwan->mMapObject.mPos.z;
        AdvanceGroupFollowerWithSpeeds(&wanwan->mFollower);
        GetGroupFollowerCurveXz(&wanwan->mFollower.mGroupFollower, &wanwan->mMapObject.mPos);
        wanwan->mMapObject.mPosStep.x = wanwan->mMapObject.mPos.x - wanwan->mMapObject.mPosStep.x;
        wanwan->mMapObject.mPosStep.z = wanwan->mMapObject.mPos.z - wanwan->mMapObject.mPosStep.z;
        velocity = &wanwan->mMapObject.mPosStep;
        if (HORIZONTAL_LENGTH_SQUARED(*velocity) >= 0x10) {
            QuaternionFromAngleAroundY(
                (u16) (((s64) FX_Atan2(wanwan->mMapObject.mPosStep.x, wanwan->mMapObject.mPosStep.z) *
                            0x28be60db9391LL +
                        0x80000000000LL) >>
                       44),
                &wanwan->mYawQuaternion);
        }
        if (wanwan->mMapObject.mStateMachine.mStateFrames < WANWAN_HIT_SHAKE_FRAMES) {
            wanwan->mOrientationBlendAmount += WANWAN_ORIENTATION_BLEND_AMOUNT_STEP;
        }
        if (wanwan->mMapObject.mStateMachine.mStateFrames >= WANWAN_HIT_PHASE_END_FRAMES) {
            wanwan->mAngleAroundX += 0x200;
        } else {
            wanwan->mMapObject.mPosStep.y -= 0x266;
        }
        if (wanwan->mAngleAroundX > WANWAN_ANGLE_AROUND_X_HIT_END) {
            wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_FOLLOW_PATH;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    } else {
        if (wanwan->mAngleAroundX == WANWAN_ANGLE_AROUND_X_HIT) {
            wanwan->mMapObject.mPosStep.y -= 0x19a;
        }
        if (wanwan->mMapObject.mStateMachine.mStateFrames >= WANWAN_HIT_FRAMES) {
            wanwan->mAngleAroundX += 0x100;
        }
        if (wanwan->mAngleAroundX > WANWAN_ANGLE_AROUND_X_HIT_END) {
            wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_PULL_BACK;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterWanwanPullBack(void *stateObject) {
    Wanwan *wanwan = stateObject;
    wanwan->mAngleAroundX = WANWAN_ANGLE_AROUND_X_LEVEL;
    wanwan->mOrientationBlendAmount = WANWAN_ORIENTATION_BLEND_AMOUNT_START;
    wanwan->mChainObject->mChain.mDownwardStep = WANWAN_CHAIN_DOWNWARD_STEP_INITIAL;
}

static inline s64 XzLengthSquared(const Vec3 *vector) {
    return HORIZONTAL_LENGTH_SQUARED(*vector);
}

void UpdateWanwanPullBack(void *stateObject) {
    Wanwan *wanwan = stateObject;
    Vec3 toCenter;
    s32 radius;

    radius = wanwan->mPullBackRadius;
    if ((s64) (wanwan->mMapObject.mPos.x - wanwan->mCenterPos.x) * (wanwan->mMapObject.mPos.x - wanwan->mCenterPos.x) +
            (s64) (wanwan->mMapObject.mPos.z - wanwan->mCenterPos.z) *
                (wanwan->mMapObject.mPos.z - wanwan->mCenterPos.z) >=
        (s64) radius * radius) {
        VEC_Subtract(&wanwan->mCenterPos, &wanwan->mMapObject.mPos, &toCenter);
        wanwan->mMapObject.mPosStep.x += (s32) (((s64) toCenter.x << 2) >> 12);
        wanwan->mMapObject.mPosStep.z += (s32) (((s64) toCenter.z << 2) >> 12);
        if (XzLengthSquared(&wanwan->mMapObject.mPosStep) >= 0x1000000) {
            wanwan->mMapObject.mPosStep.x -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.x, 0x199);
            wanwan->mMapObject.mPosStep.z -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mPosStep.z, 0x199);
        }
        wanwan->mMapObject.mPos.x += wanwan->mMapObject.mPosStep.x;
        wanwan->mMapObject.mPos.z += wanwan->mMapObject.mPosStep.z;
    }
    if (wanwan->mMapObject.mStateMachine.mStateFrames >= WANWAN_PULL_BACK_FRAMES) {
        wanwan->mMapObject.mStateMachine.mNextState = WANWAN_STATE_ROAM;
        wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanRest(void *stateObject) {
    Wanwan *wanwan = stateObject;
    wanwan->mAngleAroundX = WANWAN_ANGLE_AROUND_X_LEVEL;
    wanwan->mOrientationBlendAmount = WANWAN_ORIENTATION_BLEND_AMOUNT_START;
    wanwan->mChainObject->mChain.mDownwardStep = WANWAN_CHAIN_DOWNWARD_STEP_INITIAL;
}

void UpdateWanwanRestNop(void *stateObject) {}

void EnterWanwanFollowPath(void *stateObject) {
    Wanwan *wanwan = stateObject;
    wanwan->mAngleAroundX = WANWAN_ANGLE_AROUND_X_LEVEL;
    wanwan->mOrientationBlendAmount = WANWAN_ORIENTATION_BLEND_AMOUNT_START;
}
