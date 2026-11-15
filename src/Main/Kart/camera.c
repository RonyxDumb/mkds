#include "Main/Kart/camera.h"
#include "Main/Kart/point_link_cursor.h" // PosCurve

#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/data_02154000.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Kart/kart_model_menu.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "ITCM/sphere_collision.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Race/data_020f36d8.h"
#include "fx_mtx33.h"
#include "data_02170000.h"
#include "code_02010c84.h"
#include "Main/Race/kart.h"
#include "Main/Kart/camera_shake.h"
#include "Main/System/init_after_startup.h"

s32 gDefaultLookAtHeight;
struct Camera *gChaseCamera;
Camera *gSecondChainCamera;
s32 gFollowHeight;
s32 gChaseCameraUnusedWord;
Camera *gEntryCamera;
s32 gCameraEntryChanged;
s32 gEntryCameraUpdateRan;
s32 gDefaultFollowDistance;
Camera *gCurrentChainCamera;
Camera *gFirstChainCamera;
MtxFx44 gProjectionMatrix;

MtxFx44 *GetProjectionMatrix(void) {
    return &gProjectionMatrix;
}

static inline s32 CameraNormalizeLengthOrZero(Vec3 *src, Vec3 *dst) {
    if (LENGTH_SQUARED(*src) < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(src, dst);
}

static inline void MulVec3Fixed12NoRoundInPlace(Vec3 *vec, s32 scale) {
    vec->x = MUL_FIXED12_NO_ROUND(vec->x, scale);
    vec->y = MUL_FIXED12_NO_ROUND(vec->y, scale);
    vec->z = MUL_FIXED12_NO_ROUND(vec->z, scale);
}

// b selects the far plane: non-zero uses the second far value (mUnk_08c).
void ApplyCameraFrustum(Camera *camera, s32 useSecondFar) {
    s32 farPlane;

    if (useSecondFar != 0) {
        farPlane = camera->mSecondFar;
    } else {
        farPlane = camera->mFar;
    }
    G3i_FrustumW_(camera->mFrustumTop, camera->mFrustumBottom, camera->mFrustumLeft, camera->mFrustumRight,
                  camera->mNear, farPlane, 0x1000, 0, &NNS_G3dGlb.mProjMtx);
    NNS_G3dGlb.mFlag &= ~0x50;
}

void ApplyCameraLookAt(Camera *camera) {
    Vec3 *viewPos = &camera->mViewPos;
    Vec3 *viewLookAt = &camera->mViewLookAt;

    NNS_G3dGlb.mCamPos = *viewPos;
    NNS_G3dGlb.mCamUp = camera->mUp;
    NNS_G3dGlb.mCamTarget = *viewLookAt;
    G3i_LookAt_(viewPos, &camera->mUp, viewLookAt, 0, &NNS_G3dGlb.mCameraMtx);
    NNS_G3dGlb.mFlag &= ~0xe8;
}

// Chase camera only: sets up the camera, then puts it behind the selected Kart.
void SetupCameraBehindKart(void) {
    Kart *kart;
    Camera *chaseCamera;
    MtxFx33 axes;
    Vec3 offset;
    s32 behindDistance;

    kart = GetKart(gRaceSetup->mEntryIndex);
    SetupCamera(gChaseCamera);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gRaceSetup->mMissionRunBits & MISSION_RUN_BIT_FLIP_FOLLOW_DIRECTION) {
            gChaseCamera->mFollowDirectionSign = -0x1000;
        }
    }
    chaseCamera = gChaseCamera;
    Matrix3x3FromQuaternion(&axes, &kart->mHeadingQuaternion);
    behindDistance = MUL_FIXED12_ROUNDED(-gDefaultFollowDistance, chaseCamera->mFollowDirectionSign);
    offset.x = MUL_FIXED12_NO_ROUND(axes.mRows[2].x, behindDistance);
    offset.y = MUL_FIXED12_NO_ROUND(axes.mRows[2].y, behindDistance);
    offset.z = MUL_FIXED12_NO_ROUND(axes.mRows[2].z, behindDistance);
    VEC_Add(&kart->mPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + gFollowHeight;
    chaseCamera->mBaseUp = gCameraVec3UnitY;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = TO_FIXED12(1);
    gChaseCamera->mHeightHold = 0;
    UpdateViewFrustum(&chaseCamera->mViewMatrix);
    RequestViewTestRefresh();
    gChaseCamera->mLookAt.y = kart->mPos.y + gChaseCamera->mLookAtHeight;
}

void UpdateChaseCamera(Camera *camera, Kart *kart) {
    Vec3 kartPos = kart->mPos;
    Vec3 adjustedKartPos;
    Vec3 kartMovement;
    Vec3 kartUp;
    Vec3 forward;
    Vec3 targetUp;
    Vec3 upStep;
    s32 scaledHopHeight;
    s32 fovEaseRate;
    s32 value;
    s32 kartOffsetScale;
    Vec3 *kartMatrixRow;

    scaledHopHeight = MUL_FIXED12_NO_ROUND(kart->mHopHeight, 0xcd0);
    if (camera->mCollisionActive == FALSE) {
        camera->mPrevPos = camera->mPos;
    }
    if (kart->mEffectFlags & KART_EFFECT_HEADING_SWING) {
        forward = camera->mSavedKartForward;
        MulVec3Fixed12NoRoundInPlace(&forward, camera->mFollowDirectionSign);
    } else {
        GetKartForward(kart, &forward);
        MulVec3Fixed12NoRoundInPlace(&forward, camera->mFollowDirectionSign);
    }
    if (kart->mEntryFlags & KART_ENTRY_REMOVED) {
        if (IsWaterPresent() == FALSE) {
            return;
        }
        value = GetHeightAboveWater(camera->mPos.y - 0x5000);
        if (value < 0) {
            camera->mViewPosYOffset = -value;
        } else {
            camera->mViewPosYOffset = 0;
        }
        return;
    }
    VEC_Subtract(&kart->mPos, &kart->mPrevPos, &kartMovement);
    fovEaseRate = 0x19a;
    if (camera->mHalfFovAngle > camera->mHalfFovAngleGoal) {
        fovEaseRate = 0xcd;
    }
    value = camera->mHalfFovAngleGoal - camera->mHalfFovAngle;
    camera->mHalfFovAngle = camera->mHalfFovAngle + MUL_FIXED12_ROUNDED(value, fovEaseRate);
    camera->mHalfFovPairFirst = FX_SinIdx((u16) camera->mHalfFovAngle);
    camera->mHalfFovPairSecond = FX_CosIdx((u16) camera->mHalfFovAngle);
    if (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) {
        camera->mFollowDistanceScale =
            camera->mFollowDistanceScale + MUL_FIXED12_ROUNDED(0x14cd - camera->mFollowDistanceScale, 0xcd);
    } else {
        camera->mFollowDistanceScale =
            camera->mFollowDistanceScale + MUL_FIXED12_ROUNDED(0x1000 - camera->mFollowDistanceScale, 0x19a);
    }
    kartMovement.y = 0;
    GetKartUp(kart, &kartUp);
    UpdateChaseCameraLookAt(&camera->mLookAt, &camera->mLookAtOffset, &camera->mLookAtLowering, kart, scaledHopHeight,
                            camera->mLookAtHeight);
    kartPos.y = kartPos.y - scaledHopHeight;
    adjustedKartPos = kartPos;
    UpdateChaseCameraPosGoalYOffset(camera, kart, &forward);
    UpdateChaseCameraPos(&camera->mPos, &camera->mPosOffset, camera, kart, &adjustedKartPos, &forward,
                         MUL_FIXED12_NO_ROUND(camera->mCollisionOffsetLength, 0x3000));
    if (IsWaterPresent() != FALSE) {
        value = GetHeightAboveWater(camera->mPos.y - 0x5000);
        if (value < 0) {
            camera->mViewPosYOffset = -value;
        } else {
            camera->mViewPosYOffset = 0;
        }
    }
    UpdateChaseCameraCollision(camera, kart, &forward);
    kartMatrixRow = &kart->mRotationRow0;
    value = 0;
    if (kart->mMotionFlags & KART_MOTION_DRIFTING) {
        value = gChaseCameraDriftOffsetScale;
        if (kart->mTurnDirection > 0) {
            value *= -1;
        }
    }
    camera->mPosGoalKartOffsetScale =
        camera->mPosGoalKartOffsetScale + MUL_FIXED12_ROUNDED(value - camera->mPosGoalKartOffsetScale, 0xcd);
    kartOffsetScale = camera->mPosGoalKartOffsetScale;
    camera->mPosGoalKartOffset.x = MUL_FIXED12_NO_ROUND(kartMatrixRow->x, kartOffsetScale);
    camera->mPosGoalKartOffset.y = MUL_FIXED12_NO_ROUND(kartMatrixRow->y, kartOffsetScale);
    camera->mPosGoalKartOffset.z = MUL_FIXED12_NO_ROUND(kartMatrixRow->z, kartOffsetScale);
    if (kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD) {
        GetKartUp(kart, &targetUp);
    } else {
        targetUp = gCameraVec3UnitY;
    }
    VEC_Subtract(&targetUp, &camera->mBaseUp, &upStep);
    upStep.x = MUL_FIXED12_NO_ROUND(upStep.x, 0x800);
    upStep.y = MUL_FIXED12_NO_ROUND(upStep.y, 0x800);
    upStep.z = MUL_FIXED12_NO_ROUND(upStep.z, 0x800);
    VEC_Add(&camera->mBaseUp, &upStep, &camera->mBaseUp);
    if (camera->mHeightHold != 0) {
        camera->mLookAtHeight = camera->mLookAtHeight - 0x1000;
        if (camera->mLookAtHeight < 0x5000) {
            camera->mLookAtHeight = 0x5000;
        }
        if (camera->mHeldHeightEasing == FALSE && kart->mPos.y > camera->mHeldHeight) {
            camera->mHeldHeightEasing = TRUE;
        }
    } else if (camera->mLookAtHeight < gDefaultLookAtHeight) {
        camera->mLookAtHeight = camera->mLookAtHeight + 0x1000;
    } else {
        camera->mLookAtHeight = gDefaultLookAtHeight;
    }
    UpdateCameraWobble(camera);
}

void UpdateChaseCameraCollision(Camera *camera, Kart *kart, Vec3 *forward) {
    Vec3 pushOut = gCameraVec3Zero;
    Vec3 firstNormal;
    Vec3 secondNormal;
    Vec3 turnedForward;
    Vec3 pushOutDirection;
    Vec3 offsetStep;
    u32 flags;
    BOOL collided = FALSE;
    s32 value;
    s32 collisionState;

    gChaseCameraUnusedWord = 0;
    camera->mCollisionActive = FALSE;
    if (CollideSphereWithCourse(&camera->mPos, &camera->mPrevPos, 0, gCameraCollisionRadius, 2, -2, &pushOut,
                                &firstNormal, &secondNormal, &flags, NULL, NULL, NULL, NULL) != 0 &&
        (flags & 0xc00) == 0) {
        if (flags & 0x214300) {
            turnedForward = kart->mTurnedForward;
            if (kart->mForwardSpeed <= 0) {
                turnedForward.x = -turnedForward.x;
                turnedForward.y = -turnedForward.y;
                turnedForward.z = -turnedForward.z;
                value = CameraNormalizeLengthOrZero(&pushOut, &pushOutDirection);
                if (value != 0) {
                    if (Vec3DotUnrounded(&pushOutDirection, &secondNormal) < 0xf5c) {
                        if (Vec3DotUnrounded(&pushOutDirection, forward) > 0xb5c) {
                            camera->mCollisionState = CAMERA_COLLISION_STATE_LENGTH;
                        }
                    }
                }
            }
            camera->mCollisionActive = TRUE;
            value = Vec3DotUnrounded(&turnedForward, &secondNormal);
            collided = TRUE;
            collisionState = camera->mCollisionState;
            if (collisionState == CAMERA_COLLISION_STATE_LENGTH ||
                (collisionState == CAMERA_COLLISION_STATE_NONE && value < -0xd9a &&
                 Vec3DotUnrounded(&turnedForward, forward) < 0)) {
                if (secondNormal.y < -0xe66) {
                    camera->mCollisionState = CAMERA_COLLISION_STATE_NONE;
                    collided = FALSE;
                    camera->mCollisionActive = FALSE;
                } else {
                    camera->mCollisionOffsetLengthGoal = VEC_Mag(&pushOut);
                    camera->mCollisionState = CAMERA_COLLISION_STATE_LENGTH;
                }
            } else if (Vec3DotUnrounded(forward, &secondNormal) > 0) {
                camera->mCollisionState = CAMERA_COLLISION_STATE_OFFSET;
            } else {
                camera->mCollisionLatch = TRUE;
                collided = FALSE;
            }
        } else if (flags & 0x1e34ef) {
            if (gRaceSetup->mMode != MODE_BATTLE || VEC_DotProduct(&gCameraVec3UnitY, &firstNormal) < 0xfae ||
                camera->mPos.y - kart->mPos.y < gFollowHeight) {
                VEC_Add(&pushOut, &camera->mPos, &camera->mPos);
            }
        }
    }
    if (camera->mCollisionActive == FALSE) {
        camera->mCollisionLatch = FALSE;
    }
    if (collided != FALSE && camera->mCollisionLatch == FALSE) {
        if (camera->mCollisionState == CAMERA_COLLISION_STATE_OFFSET) {
            value = MUL_FIXED12_NO_ROUND(0x1000 - kart->mVelocityLengthRatio, 0x5000) + 0x3000;
            pushOut.x = MUL_FIXED12_NO_ROUND(pushOut.x, value);
            pushOut.y = MUL_FIXED12_NO_ROUND(pushOut.y, value);
            pushOut.z = MUL_FIXED12_NO_ROUND(pushOut.z, value);
            camera->mPosGoalCollisionOffset = pushOut;
            camera->mCollisionOffsetLengthGoal = 0;
        }
    } else {
        camera->mCollisionOffsetLengthGoal = 0;
        VEC_Subtract(&pushOut, &camera->mPosGoalCollisionOffset, &offsetStep);
        offsetStep.x = MUL_FIXED12_NO_ROUND(offsetStep.x, 0x4cd);
        offsetStep.y = MUL_FIXED12_NO_ROUND(offsetStep.y, 0x4cd);
        offsetStep.z = MUL_FIXED12_NO_ROUND(offsetStep.z, 0x4cd);
        VEC_Add(&camera->mPosGoalCollisionOffset, &offsetStep, &camera->mPosGoalCollisionOffset);
        camera->mCollisionState = CAMERA_COLLISION_STATE_NONE;
    }
    camera->mCollisionOffsetLength =
        camera->mCollisionOffsetLength +
        MUL_FIXED12_ROUNDED(camera->mCollisionOffsetLengthGoal - camera->mCollisionOffsetLength, 0x11f);
}

void UpdateChaseCameraPosGoalYOffset(Camera *camera, Kart *kart, Vec3 *forward) {
    s32 forwardYScale = -0x2d000;
    s32 offsetDelta;
    s32 goalYOffset = 0;
    s32 easeRate = 0x11f;
    u32 kartFlags = kart->mDriveFlags;
    s32 forwardY;

    if (kartFlags & KART_DRIVE_KEYED_PLACEMENT) {
        forwardYScale = -0x3c000;
    }
    if (kart->mAirTiltAngleOffset > 0) {
        easeRate = 0x52;
    }
    if ((kart->mMotionFlags & KART_MOTION_ON_GROUND) || (kartFlags & KART_DRIVE_KEYED_PLACEMENT)) {
        if ((forwardY = forward->y) > 0) {
            goalYOffset = MUL_FIXED12_NO_ROUND(forwardY, forwardYScale);
        } else if (forwardY + 0x4cd < 0) {
            goalYOffset = MUL_FIXED12_NO_ROUND(forwardY, -0xf000);
        }
    }
    if (kartFlags & KART_DRIVE_BOOST_SURFACE_HELD) {
        camera->mPosGoalYOffset = camera->mPosGoalYOffset + MUL_FIXED12_ROUNDED(-camera->mPosGoalYOffset, easeRate);
        return;
    }
    offsetDelta = goalYOffset - camera->mPosGoalYOffset;
    camera->mPosGoalYOffset = camera->mPosGoalYOffset + MUL_FIXED12_ROUNDED(offsetDelta, easeRate);
}

void StartEntryCameraKind6Entry(void) {
    Camera *entryCamera = gEntryCamera;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    courseMapCamera = gCourseMap->mFirstKind6Entry;
    if (courseMapCamera == NULL) {
        return;
    }
    entryCamera->mKind6EntryRunning = TRUE;
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceSetup->mMode == MODE_BATTLE) {
            SetupReversePosCurve(&entryCamera->mReversePosCurve, courseMapCamera);
        }
    }
    if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceProgress->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

// Sets mEntryUpdateHold; with a != 0 and the kind 6 entry still running, also picks the entry at the followed Kart's
// position.
void SetEntryCameraUpdateHold(s32 hold) {
    CourseMapCamera *courseMapCamera;
    Camera *entryCamera = gEntryCamera;
    RandomState64 *localRandom;
    Vec3 kartPos;
    s32 courseMapCameraIndex;

    if (entryCamera->mCourseMapCamera == NULL) {
        return;
    }
    if (hold != 0 && entryCamera->mCourseMapCamera->mKind != COURSE_MAP_CAMERA_KIND_ANGLE &&
        entryCamera->mCourseMapCamera->mKind != COURSE_MAP_CAMERA_KIND_ANGLE_START) {
        return;
    }
    entryCamera->mEntryUpdateHold = hold;
    if (hold == 0) {
        return;
    }
    if (entryCamera->mKind6EntryRunning == FALSE) {
        return;
    }
    entryCamera->mKind6EntryRunning = FALSE;
    GetKartPos(&kartPos, entryCamera->mFollowedKartIndex);
    courseMapCameraIndex = GetCourseMapCameraIndexAtPos(&kartPos);
    if (courseMapCameraIndex < 0) {
        return;
    }
    courseMapCamera = GetCourseMapCamera(courseMapCameraIndex);
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceSetup->mMode == MODE_BATTLE) {
            SetupReversePosCurve(&entryCamera->mReversePosCurve, courseMapCamera);
        }
    }
    if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceProgress->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

void DisableEntryCameraUpdate(void) {
    gEntryCamera->mEntryUpdateDisabled = 1;
}

static inline void MulVec3Fixed12NoRound(Vec3 *destination, const Vec3 *source, s32 scale) {
    destination->x = MUL_FIXED12_NO_ROUND(source->x, scale);
    destination->y = MUL_FIXED12_NO_ROUND(source->y, scale);
    destination->z = MUL_FIXED12_NO_ROUND(source->z, scale);
}

BOOL TryUpdateEntryCamera(Camera *camera) {
    BOOL result = TRUE;
    CourseMapCamera *courseMapCamera;
    Vec3 kartPos;
    s32 courseMapCameraIndex;

    camera->mPrevPos = camera->mPos;
    gEntryCameraUpdateRan = 1;
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        UpdateStaffRollCameraAndLight(camera);
        return TRUE;
    }
    if (camera->mEntryUpdateHold != 0 || camera->mEntryUpdateDisabled != FALSE) {
        return FALSE;
    }
    camera->mPrevPos = camera->mPos;
    if (camera->mKind8EntryRunning != FALSE) {
        UpdateCameraAngleEntry(camera);
        return TRUE;
    }
    GetKartPos(&kartPos, camera->mFollowedKartIndex);
    courseMapCameraIndex = GetCourseMapCameraIndexAtPos(&kartPos);
    if (camera->mKind6EntryRunning != FALSE) {
        if (gRaceSetup->mMode == MODE_BATTLE) {
            UpdateCameraByEntryKind(camera);
            return TRUE;
        }
        camera->mKind6EntryFrames = camera->mKind6EntryFrames + 1;
        if (camera->mKind6EntryFrames >= 300) {
            camera->mKind6EntryRunning = FALSE;
        }
    }
    if (courseMapCameraIndex == -1) {
        result = FALSE;
    } else {
        RandomState64 *localRandom;

        courseMapCamera = gCourseMap->mCameras + (u16) courseMapCameraIndex;
        if (courseMapCameraIndex != camera->mLastCourseMapCameraIndex) {
            camera->mLastCourseMapCameraIndex = courseMapCameraIndex;
            if (camera->mKind6EntryRunning == FALSE) {
                camera->mCourseMapCamera = courseMapCamera;
                camera->mFovBlend = 0;
                camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
                camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
                camera->mShakeKind = courseMapCamera->mShakeKind;
                if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
                    SetupPosCurve(&camera->mPosCurve, courseMapCamera);
                    if (gRaceSetup->mMode == MODE_BATTLE) {
                        SetupReversePosCurve(&camera->mReversePosCurve, courseMapCamera);
                    }
                }
                if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
                    localRandom = &gRaceProgress->mLocalRandom;
                    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
                }
                gCameraEntryChanged = 1;
            }
        }
        UpdateCameraByEntryKind(camera);
    }
    return result;
}

void UpdateCameraByEntryKind(Camera *camera) {
    CourseMapCamera *courseMapCamera;
    s32 secondOffset;
    switch (camera->mCourseMapCamera->mKind) {
        case COURSE_MAP_CAMERA_KIND_STATIC_LOOK_AT_KART:
            camera->mPos = camera->mCourseMapCamera->mPosOrParams;
            if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
                camera->mFollowedKartIndex = FROM_FIXED12(camera->mCourseMapCamera->mLookAtEndOrParams.z) - 1;
                GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mLookAtStartOrParams.y;
            } else {
                GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + 0x6000;
            }
            UpdateCameraView(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_CURVE_LOOK_AT_KART:
            UpdateCameraPosCurveLookAtKart(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_ANGLE:
        case COURSE_MAP_CAMERA_KIND_ANGLE_START:
            UpdateCameraAngleEntry(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_STATIC_LOOK_AT_BLEND:
            camera->mPos = camera->mCourseMapCamera->mPosOrParams;
            UpdateCameraLookAtBlend(camera);
            UpdateCameraViewWithWorldUp(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_CURVE_LOOK_AT_BLEND:
            UpdateCameraPosCurveLookAtBlend(camera);
            break;
    }
    courseMapCamera = camera->mCourseMapCamera;
    if (courseMapCamera->mFovBlendPerFrame != 0) {
        enum { FOV_BLEND_NONE } fovBlend = camera->mFovBlend;
        CourseMapCamera *blendCamera = courseMapCamera;

        s32 firstStart = blendCamera->mHalfFovPairFirst;
        s32 secondStart = blendCamera->mHalfFovPairSecond;
        s32 secondEnd = blendCamera->mHalfFovPairSecondEnd;
        s32 firstEnd = blendCamera->mHalfFovPairFirstEnd;
        s32 firstDelta = firstEnd - firstStart;
        s32 secondDelta = secondEnd - secondStart;

        secondOffset = MUL_FIXED12_NO_ROUND(secondDelta, fovBlend);
        camera->mHalfFovPairFirst = firstStart + MUL_FIXED12_NO_ROUND(firstDelta, fovBlend);
        camera->mHalfFovPairSecond = secondStart + secondOffset;
        camera->mFovBlend += blendCamera->mFovBlendPerFrame;
        if (camera->mFovBlend > 0x1000) {
            camera->mFovBlend = 0x1000;
        }
    } else {
        camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
        camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    }
}

void StartEntryCameraKind8Entry(void) {
    Camera *entryCamera;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    entryCamera = gEntryCamera;
    courseMapCamera = gCourseMap->mFirstKind8EntryInMode4;

    if (courseMapCamera == NULL) {
        return;
    }
    entryCamera->mKind8EntryRunning = TRUE;
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceSetup->mMode == MODE_BATTLE) {
            SetupReversePosCurve(&entryCamera->mReversePosCurve, courseMapCamera);
        }
    }
    if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceProgress->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

static inline void SetNextCourseMapCamera(Camera *camera) {
    CourseMapCamera *nextCourseMapCamera;

    if (camera->mCourseMapCamera->mNextIndex == -1) {
        nextCourseMapCamera = NULL;
    } else {
        nextCourseMapCamera = gCourseMap->mCameras + (u16) camera->mCourseMapCamera->mNextIndex;
    }
    if (nextCourseMapCamera == NULL) {
        gRaceProgress->mCameraChainEnded = 1;
        return;
    }
    camera->mCourseMapCameraFrames = 0;
    camera->mCourseMapCamera = nextCourseMapCamera;
    camera->mLookAtBlend = 0;
    camera->mFovBlend = 0;
    if ((s16) nextCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&camera->mPosCurve, nextCourseMapCamera);
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        SetAwardPosStripDrawEnabled(nextCourseMapCamera->mShakeKind != 0);
    }
    gCameraEntryChanged = 1;
}

MtxFx43 *UpdateChainCameraPair(void) {
    if (gSecondChainCamera->mCourseMapCamera != NULL) {
        if (gSecondChainCamera->mCourseMapCamera->mKind == COURSE_MAP_CAMERA_KIND_CHAIN_PAIR) {
            gFirstChainCamera->mFrustumShift = CAMERA_FRUSTUM_SHIFT_UP;
            gSecondChainCamera->mFrustumShift = CAMERA_FRUSTUM_SHIFT_DOWN;
        } else {
            gSecondChainCamera->mFrustumShift = CAMERA_FRUSTUM_SHIFT_NONE;
            gFirstChainCamera->mFrustumShift = gSecondChainCamera->mFrustumShift;
        }
    }
    UpdateCameraEntry(gFirstChainCamera);
    if (gSecondChainCamera->mFrustumShift == CAMERA_FRUSTUM_SHIFT_DOWN) {
        gSecondChainCamera->mHalfFovPairFirst = gFirstChainCamera->mHalfFovPairFirst;
        gSecondChainCamera->mHalfFovPairSecond = gFirstChainCamera->mHalfFovPairSecond;
        gSecondChainCamera->mPos = gFirstChainCamera->mPos;
        gSecondChainCamera->mLookAt = gFirstChainCamera->mLookAt;
    } else {
        UpdateCameraEntry(gSecondChainCamera);
    }
    if (GetRaceUpdateFramesMod2() == 0) {
        UpdateCameraView(gFirstChainCamera);
        gCurrentChainCamera = gFirstChainCamera;
        return &gFirstChainCamera->mViewMatrix;
    }
    UpdateCameraView(gSecondChainCamera);
    gCurrentChainCamera = gSecondChainCamera;
    return &gSecondChainCamera->mViewMatrix;
}

MtxFx43 *UpdateFirstChainCamera(void) {
    UpdateCameraEntry(gFirstChainCamera);
    UpdateCameraView(gFirstChainCamera);
    gCurrentChainCamera = gFirstChainCamera;
    return &gFirstChainCamera->mViewMatrix;
}

void UpdateCameraEntry(Camera *camera) {
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    UpdateCameraByEntryKind(camera);
    camera->mCourseMapCameraFrames = camera->mCourseMapCameraFrames + 1;
    if (camera->mCourseMapCameraFrames != camera->mCourseMapCamera->mFrameCount) {
        return;
    }
    SetNextCourseMapCamera(camera);
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    if (camera != gFirstChainCamera) {
        return;
    }
    if (camera->mFrustumShift != CAMERA_FRUSTUM_SHIFT_UP) {
        return;
    }
    SetNextCourseMapCamera(gSecondChainCamera);
}

void UpdateCameraPosCurveLookAtKart(Camera *camera) {
    UpdateCameraPosCurve(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = FROM_FIXED12(camera->mCourseMapCamera->mLookAtEndOrParams.z) - 1;
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mLookAtStartOrParams.y;
    } else {
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    UpdateCameraView(camera);
}

void UpdateCameraAngleEntry(Camera *camera) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    Kart *kart;
    Vec3 *axis;
    Vec3 baseDirection;
    Vec3 lookDirection;
    Vec3 offset;
    MtxFx33 pitchMatrix;
    MtxFx33 yawMatrix;
    MtxFx33 startRotation;
    MtxFx33 tiltMatrix;
    MtxFx33 endPitchMatrix;
    MtxFx33 endYawMatrix;
    MtxFx33 endRotation;
    Vec3 sideAxis;
    Vec3 upAxis;
    Vec3 crossInput;
    Vec3 lookAtOffset;
    Vec3 pushOut;
    Vec3 directionCopy;
    s32 startYaw;
    s32 startPitch;
    s32 value;
    s32 endPitch;

    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = FROM_FIXED12(courseMapCamera->mLookAtEndOrParams.z) - 1;
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mLookAtStartOrParams.y;
    } else {
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    kart = GetKart(camera->mFollowedKartIndex);
    baseDirection = kart->mRotationRow2;
    startYaw = DEG_TO_ANGLE_TRUNCATED(courseMapCamera->mLookAtStartOrParams.x);
    startPitch = DEG_TO_ANGLE_TRUNCATED(courseMapCamera->mLookAtStartOrParams.y);
    value = DEG_TO_ANGLE_TRUNCATED(courseMapCamera->mLookAtEndOrParams.x);
    endPitch = DEG_TO_ANGLE_TRUNCATED(courseMapCamera->mLookAtEndOrParams.y);
    MTX_RotAxis33(&tiltMatrix, &kart->mRotationRow0, FX_SinIdx(kart->mHopTiltAngle), FX_CosIdx(kart->mHopTiltAngle));
    MTX_MultVec33(&baseDirection, &tiltMatrix, &baseDirection);
    directionCopy = baseDirection;
    crossInput = directionCopy;
    lookDirection = directionCopy;
    MulVec3Fixed12NoRound(&lookAtOffset, &lookDirection, -courseMapCamera->mLookAtStartOrParams.z);
    Vec3CrossUnrounded(&gCameraVec3UnitY, &baseDirection, &sideAxis);
    Vec3CrossUnrounded(&crossInput, &sideAxis, &upAxis);
    MTX_RotAxis33(&yawMatrix, &upAxis, FX_SinIdx(startYaw), FX_CosIdx(startYaw));
    MTX_RotAxis33(&pitchMatrix, &sideAxis, FX_SinIdx(startPitch), FX_CosIdx(startPitch));
    MTX_Concat33(&pitchMatrix, &yawMatrix, &startRotation);
    MTX_MultVec33(&lookDirection, &startRotation, &lookDirection);
    MulVec3Fixed12NoRound(&offset, &lookDirection, courseMapCamera->mLookAtStartOrParams.z);
    VEC_Add(&camera->mLookAt, &offset, &camera->mPos);
    sideAxis.x = -sideAxis.x;
    sideAxis.y = -sideAxis.y;
    sideAxis.z = -sideAxis.z;
    upAxis.x = -upAxis.x;
    upAxis.y = -upAxis.y;
    upAxis.z = -upAxis.z;
    MTX_RotAxis33(&endYawMatrix, &upAxis, FX_SinIdx(value), FX_CosIdx(value));
    MTX_RotAxis33(&endPitchMatrix, &sideAxis, FX_SinIdx(endPitch), FX_CosIdx(endPitch));
    MTX_Concat33(&endYawMatrix, &yawMatrix, &endYawMatrix);
    MTX_Concat33(&endPitchMatrix, &pitchMatrix, &endPitchMatrix);
    MTX_Concat33(&endPitchMatrix, &endYawMatrix, &endRotation);
    MTX_MultVec33(&lookAtOffset, &endRotation, &lookAtOffset);
    VEC_Add(&camera->mPos, &lookAtOffset, &camera->mLookAt);
    camera->mLookAt.y = camera->mLookAt.y - kart->mHopHeight;
    camera->mPos.y = camera->mPos.y - kart->mHopHeight;
    if (gRaceSetup->mMode != MODE_MISSION_RUN && gRaceSetup->mMode != MODE_BATTLE) {
        if (CollideSphereWithCourse(&camera->mPos, &camera->mPrevPos, 0, gCameraCollisionRadius >> 1, 2, -2, &pushOut,
                                    NULL, NULL, NULL, NULL, NULL, NULL, NULL) != 0) {
            kart = GetKart(camera->mFollowedKartIndex);
            axis = &kart->mRotationRow0;
            value = VEC_DotProduct(axis, &pushOut);
            pushOut.x = MUL_FIXED12_NO_ROUND(kart->mRotationRow0.x, value);
            pushOut.y = MUL_FIXED12_NO_ROUND(axis->y, value);
            pushOut.z = MUL_FIXED12_NO_ROUND(axis->z, value);
            VEC_Add(&pushOut, &camera->mPos, &camera->mPos);
        }
    }
    UpdateCameraView(camera);
}

void UpdateStaffRollCameraAndLight(Camera *camera) {
    Kart *kart = GetKart(camera->mFollowedKartIndex);
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    Vec3 newPos;
    Vec3 newLookAt;
    Vec3 offset;
    Vec3 lightDirection;
    MtxFx33 rotation;

    camera->mLookAtOffset = camera->mLookAt;
    newLookAt = kart->mPos;
    VEC_MultAdd(courseMapCamera->mPosOrParams.z, &kart->mRotationRow0, &kart->mPos, &newPos);
    newPos.y = 0x1f4000;
    newLookAt.y = 0x1f4000;
    offset = kart->mRotationRow2;
    offset.y = 0;
    if (LENGTH_SQUARED(offset) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
    }
    MulVec3Fixed12NoRound(&offset, &offset, courseMapCamera->mPosOrParams.x);
    VEC_Add(&newPos, &offset, &newPos);
    VEC_Add(&newLookAt, &offset, &newLookAt);
    if (GetRaceUpdateFrames() < courseMapCamera->mFrameCount) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
    } else if (camera->mFactor < 0x1000) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
        camera->mFactor = camera->mFactor + 0x52;
        VEC_Subtract(&camera->mPrevPos, &camera->mPos, &camera->mPosOffset);
        VEC_Subtract(&camera->mLookAtOffset, &camera->mLookAt, &camera->mLookAtOffset);
        VEC_MultAdd(camera->mFactor, &camera->mPosOffset, &newPos, &camera->mPos);
        VEC_MultAdd(camera->mFactor, &camera->mLookAtOffset, &newLookAt, &camera->mLookAt);
    }
    UpdateCameraView(camera);
    VEC_Subtract(&newPos, &newLookAt, &lightDirection);
    if (SQUARE_SUM3(lightDirection.x, lightDirection.y, lightDirection.z) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&lightDirection, &lightDirection);
    }
    MTX_RotAxis33(&rotation, &gCameraVec3UnitY, FX_SinIdx(gStaffRollLightRotationAngle),
                  FX_CosIdx(gStaffRollLightRotationAngle));
    MTX_MultVec33(&lightDirection, &rotation, &lightDirection);
    lightDirection.x = MUL_FIXED12_NO_ROUND(lightDirection.x, 0xfae);
    lightDirection.y = MUL_FIXED12_NO_ROUND(lightDirection.y, 0xfae);
    lightDirection.z = MUL_FIXED12_NO_ROUND(lightDirection.z, 0xfae);
    SetRaceLightVector(&lightDirection);
    courseMapCamera = camera->mCourseMapCamera;
    if (courseMapCamera->mFovBlendPerFrame != 0) {
        s32 secondOffset;
        enum { FOV_BLEND_NONE } fovBlend = camera->mFovBlend;
        s32 firstStart = courseMapCamera->mHalfFovPairFirst;
        s32 secondStart = courseMapCamera->mHalfFovPairSecond;
        s32 secondEnd = courseMapCamera->mHalfFovPairSecondEnd;
        s32 firstEnd = courseMapCamera->mHalfFovPairFirstEnd;
        s32 firstDelta = firstEnd - firstStart;
        s32 secondDelta = secondEnd - secondStart;

        secondOffset = MUL_FIXED12_NO_ROUND(secondDelta, fovBlend);
        camera->mHalfFovPairFirst = firstStart + MUL_FIXED12_NO_ROUND(firstDelta, fovBlend);
        camera->mHalfFovPairSecond = secondStart + secondOffset;
        camera->mFovBlend += courseMapCamera->mFovBlendPerFrame;
        if (camera->mFovBlend > 0x1000) {
            camera->mFovBlend = 0x1000;
        }
    } else {
        camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
        camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    }
}

void UpdateCameraPosCurve(Camera *camera, s32 paramPerFrame) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    u16 pointCount = gCourseMap->mEntryGroups[courseMapCamera->mEntryGroupIndex].mEntryCount;
    CourseMapGroupEntry *firstEntry;
    CourseMapGroupEntry *secondEntry;
    Vec3 startPos;
    Vec3 direction;
    Vec3 offset;
    s32 value;

    if (pointCount >= 4) {
        UpdatePosCurve(&camera->mPos, &camera->mPosCurve, courseMapCamera, paramPerFrame);
        return;
    }
    if (pointCount < 2) {
        return;
    }
    firstEntry = GetCourseMapGroupEntry(courseMapCamera->mEntryGroupIndex, 0);
    secondEntry = GetCourseMapGroupEntry(courseMapCamera->mEntryGroupIndex, 1);
    startPos = firstEntry->mPos;
    VEC_Subtract(&secondEntry->mPos, &firstEntry->mPos, &direction);
    if (LENGTH_SQUARED(direction) < 0x10) {
        value = 0;
    } else {
        value = Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
    }
    camera->mPosCurve.mParam += paramPerFrame;
    if (camera->mPosCurve.mParam >= 0x1000) {
        camera->mPosCurve.mParam = 0x1000;
    }
    value = MUL_FIXED12_NO_ROUND(camera->mPosCurve.mParam, value);
    offset.x = MUL_FIXED12_NO_ROUND(direction.x, value);
    offset.y = MUL_FIXED12_NO_ROUND(direction.y, value);
    offset.z = MUL_FIXED12_NO_ROUND(direction.z, value);
    VEC_Add(&startPos, &offset, &camera->mPos);
}

void UpdateCameraPosCurveLookAtBlend(Camera *camera) {
    UpdateCameraPosCurve(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    UpdateCameraLookAtBlend(camera);
    UpdateCameraViewWithWorldUp(camera);
}

void UpdateCameraLookAtBlend(Camera *camera) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    s32 startX, startY, startZ;
    s32 deltaX, deltaY, deltaZ;
    s32 scaledDeltaX, scaledDeltaY, scaledDeltaZ;
    s64 blend;

    if (courseMapCamera->mLookAtBlendPerFrame != 0) {
        blend = camera->mLookAtBlend;
        startX = courseMapCamera->mLookAtStartOrParams.x;
        deltaX = courseMapCamera->mLookAtEndOrParams.x - startX;
        scaledDeltaX = (deltaX * blend) >> 12;
        startY = courseMapCamera->mLookAtStartOrParams.y;
        deltaY = courseMapCamera->mLookAtEndOrParams.y - startY;
        scaledDeltaY = (deltaY * blend) >> 12;
        startZ = courseMapCamera->mLookAtStartOrParams.z;
        deltaZ = courseMapCamera->mLookAtEndOrParams.z - startZ;
        scaledDeltaZ = (deltaZ * blend) >> 12;
        camera->mLookAt.x = startX + scaledDeltaX;
        camera->mLookAt.y = startY + scaledDeltaY;
        camera->mLookAt.z = startZ + scaledDeltaZ;
        camera->mLookAtBlend += courseMapCamera->mLookAtBlendPerFrame;
        if (camera->mLookAtBlend > 0x1000) {
            camera->mLookAtBlend = 0x1000;
        }
    } else {
        camera->mLookAt.x = courseMapCamera->mLookAtStartOrParams.x;
        camera->mLookAt.y = courseMapCamera->mLookAtStartOrParams.y;
        camera->mLookAt.z = courseMapCamera->mLookAtStartOrParams.z;
    }
}

Camera *GetChaseCamera(void) {
    return gChaseCamera;
}

Camera *GetEntryCamera(void) {
    return gEntryCamera;
}

Camera *GetCurrentChainCamera(void) {
    return gCurrentChainCamera;
}

// Chase camera (gChaseCamera) only.
void SetCameraHalfFovAngleGoal(u32 halfFovAngleGoal) {
    gChaseCamera->mHalfFovAngleGoal = halfFovAngleGoal;
}

// Chase camera (gChaseCamera) only.
void ResetCameraHalfFovAngleGoal(void) {
    u32 unused;
    gChaseCamera->mHalfFovAngleGoal = gDefaultHalfFovAngle;
}

// Chase camera only: resets the field-of-view angle goal to its default and the angle to default + 5.
void ResetCameraHalfFovAngle(void) {
    s32 defaultHalfFovAngle;

    defaultHalfFovAngle = gDefaultHalfFovAngle;
    gChaseCamera->mHalfFovAngleGoal = defaultHalfFovAngle;
    gChaseCamera->mHalfFovAngle = defaultHalfFovAngle + 5;
}

// Chase camera (gChaseCamera) only.
void SetCameraHeightHold(s32 hold) {
    gChaseCamera->mHeightHold = hold;
    if (hold == 0) {
        return;
    }
    gChaseCamera->mHeldHeight = gChaseCamera->mPos.y;
    gChaseCamera->mHeldHeightEasing = FALSE;
}

void UpdateChaseCameraLookAt(Vec3 *lookAt, Vec3 *lookAtOffset, s32 *lookAtLowering, Kart *kart, s32 scaledHopHeight,
                             s32 lookAtHeight) {
    Vec3 lookAtGoal;
    Vec3 targetPos;
    Vec3 offsetGoal;
    Vec3 offsetStep;
    s32 value;

    lookAtGoal = kart->mPos;
    targetPos = kart->mPos;
    targetPos.y = targetPos.y - scaledHopHeight;
    VEC_MultAdd(lookAtHeight, &kart->mRotationRow1, &targetPos, &targetPos);
    lookAtGoal.y = lookAtGoal.y + (lookAtHeight - scaledHopHeight);
    if (!(kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD)) {
        offsetGoal = gCameraVec3Zero;
    } else {
        VEC_Subtract(&targetPos, &lookAtGoal, &offsetGoal);
        VEC_MultAdd(0xa000, &kart->mRotationRow1, &offsetGoal, &offsetGoal);
    }
    VEC_Subtract(&offsetGoal, lookAtOffset, &offsetStep);
    offsetStep.x = MUL_FIXED12_NO_ROUND(offsetStep.x, 0x266);
    offsetStep.y = MUL_FIXED12_NO_ROUND(offsetStep.y, 0x266);
    offsetStep.z = MUL_FIXED12_NO_ROUND(offsetStep.z, 0x266);
    VEC_Add(lookAtOffset, &offsetStep, lookAtOffset);
    VEC_Add(&lookAtGoal, lookAtOffset, &lookAtGoal);
    lookAt->x = lookAtGoal.x;
    lookAt->z = lookAtGoal.z;
    if (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) {
        *lookAtLowering = *lookAtLowering + 0x1000;
        if (*lookAtLowering > 0xa000) {
            *lookAtLowering = 0xa000;
        }
    } else {
        value = *lookAtLowering;
        *lookAtLowering = value + MUL_FIXED12_ROUNDED(-value, 0x29);
    }
    lookAtGoal.y = lookAtGoal.y - *lookAtLowering;
    value = lookAt->y;
    lookAt->y = value + MUL_FIXED12_ROUNDED(lookAtGoal.y - value, 0xccd);
}

void UpdateChaseCameraPos(Vec3 *pos, Vec3 *posOffset, Camera *camera, Kart *kart, Vec3 *kartPos, const Vec3 *forward,
                          s32 collisionShorten) {
    Vec3 kartMovement;
    Vec3 kartUp;
    Vec3 forwardCopy;
    Vec3 kartToPos;
    Vec3 kartToPosDirection;
    Vec3 posGoal;
    Vec3 followOffset;
    Vec3 goalDelta;
    Vec3 followPos;
    Vec3 heightenedPos;
    Vec3 liftedOffset;
    Vec3 offsetGoal;
    Vec3 offsetStep;
    s32 followDistance;
    s32 negatedFollowDistance;
    s32 goalDeltaY;
    s32 length;

    forwardCopy = *forward;
    followDistance = camera->mFollowDistance - collisionShorten;
    GetKartUp(kart, &kartUp);
    if (followDistance < 500) {
        followDistance = 500;
    }
    VEC_Subtract(&kart->mPos, &kart->mPrevPos, &kartMovement);
    if (kart->mDriveFlags & KART_DRIVE_RESPAWN_FALL) {
        if (kart->mEffectFlags & KART_EFFECT_WATER_FALL) {
            return;
        }
        camera->mKartMoveScale = MUL_FIXED12_NO_ROUND(camera->mKartMoveScale, 0xe66);
        VEC_MultAdd(camera->mKartMoveScale, &kartMovement, pos, pos);
        return;
    }
    kartMovement.y = 0;
    VEC_Add(pos, &kartMovement, pos);
    negatedFollowDistance = -followDistance;
    followOffset.x = MUL_FIXED12_NO_ROUND(forwardCopy.x, negatedFollowDistance);
    followOffset.y = MUL_FIXED12_NO_ROUND(forwardCopy.y, negatedFollowDistance);
    followOffset.z = MUL_FIXED12_NO_ROUND(forwardCopy.z, negatedFollowDistance);
    VEC_Add(&followOffset, &camera->mPosGoalKartOffset, &followOffset);
    VEC_Add(&followOffset, &camera->mPosGoalCollisionOffset, &followOffset);
    VEC_MultAdd(gFollowHeight, &kartUp, &followOffset, &liftedOffset);
    VEC_Add(kartPos, &liftedOffset, &heightenedPos);
    followOffset.y = gFollowHeight;
    VEC_Add(kartPos, &followOffset, &followPos);
    posGoal = followPos;
    posGoal.y = posGoal.y + camera->mPosGoalYOffset;
    if (!(kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD)) {
        offsetGoal = gCameraVec3Zero;
    } else {
        VEC_Subtract(&heightenedPos, &posGoal, &offsetGoal);
        VEC_MultAdd(-0x1e000, &kartUp, &offsetGoal, &offsetGoal);
    }
    VEC_Subtract(&offsetGoal, posOffset, &offsetStep);
    offsetStep.x = MUL_FIXED12_NO_ROUND(offsetStep.x, 0x19a);
    offsetStep.y = MUL_FIXED12_NO_ROUND(offsetStep.y, 0x19a);
    offsetStep.z = MUL_FIXED12_NO_ROUND(offsetStep.z, 0x19a);
    VEC_Add(posOffset, &offsetStep, posOffset);
    VEC_Add(&posGoal, posOffset, &posGoal);
    VEC_Subtract(&posGoal, pos, &goalDelta);
    goalDeltaY = goalDelta.y;
    length = 0;
    goalDelta.y = 0;
    if (LENGTH_SQUARED(goalDelta) >= 16) {
        length = Vec3NormalizeAndGetLengthUnchecked(&goalDelta, &goalDelta);
    }
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(length, 0x11f), &goalDelta, pos, pos);
    pos->y = pos->y + ((s32) (((s64) goalDeltaY * 0x11f) >> 9) + collisionShorten * 2);
    if (camera->mHeightHold != 0) {
        if (camera->mHeldHeightEasing != FALSE) {
            s32 heightDelta;
            heightDelta = pos->y - camera->mHeldHeight;
            camera->mHeldHeight = camera->mHeldHeight + MUL_FIXED12_ROUNDED(heightDelta, 0x29);
        }
        pos->y = camera->mHeldHeight;
    }
    VEC_Subtract(pos, kartPos, &kartToPos);
    kartToPosDirection = kartToPos;
    length = 0;
    if (LENGTH_SQUARED(kartToPosDirection) >= 16) {
        length = Vec3NormalizeAndGetLengthUnchecked(&kartToPosDirection, &kartToPosDirection);
    }
    if (length == 0) {
        return;
    }
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(camera->mFollowDistance, camera->mFollowDistanceScale), &kartToPosDirection,
                kartPos, pos);
}

// Puts the chase camera at a minus mFollowDistance along axis 2 of the matrix b (the kart's).
void ResetCameraBehind(const Vec3 *kartPos, void *quaternion) {
    Camera *chaseCamera;
    MtxFx33 axes;
    Vec3 offset;
    s32 behindDistance;

    chaseCamera = gChaseCamera;
    Matrix3x3FromQuaternion(&axes, quaternion);
    behindDistance = MUL_FIXED12_ROUNDED(-gDefaultFollowDistance, chaseCamera->mFollowDirectionSign);
    offset.x = MUL_FIXED12_NO_ROUND(axes.mRows[2].x, behindDistance);
    offset.y = MUL_FIXED12_NO_ROUND(axes.mRows[2].y, behindDistance);
    offset.z = MUL_FIXED12_NO_ROUND(axes.mRows[2].z, behindDistance);
    VEC_Add(kartPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + gFollowHeight;
    chaseCamera->mBaseUp = gCameraVec3UnitY;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = TO_FIXED12(1);
    gChaseCamera->mHeightHold = 0;
    UpdateViewFrustum(&chaseCamera->mViewMatrix);
    RequestViewTestRefresh();
}

// Chase camera (gChaseCamera) only.
void StartCameraWobble(s32 baseAmplitude, u32 distance, s32 scale) {
    Camera *chaseCamera;
    s32 distanceFactor;
    s32 amplitude;

    distanceFactor = 0x1000;
    chaseCamera = gChaseCamera;
    if (distance > 1000000) {
        return;
    }
    if (distance > 0x57e40) {
        distanceFactor = 0x4cd;
    } else if (distance > 0x15f90) {
        distanceFactor = 0x99a;
    }
    amplitude = MUL_FIXED12_NO_ROUND(baseAmplitude, MUL_FIXED12_NO_ROUND(scale, distanceFactor));
    if (chaseCamera->mWobbling != FALSE && chaseCamera->mWobbleAmplitude > amplitude) {
        return;
    }
    chaseCamera->mWobbleAmplitude = amplitude;
    chaseCamera->mWobbling = TRUE;
    chaseCamera->mFactor = 0;
    chaseCamera->mWobblePerFrame = 0x800;
    chaseCamera->mWobbleDirection = 1;
    chaseCamera->mWobbleDecay = 0xe66;
    chaseCamera->mWobbleOffset = 0;
}

void StartCameraWobbleAtDistance(u32 distance, s32 scale) {
    StartCameraWobble(0x2800, distance, scale);
}

void StartCameraWobbleByCourse(void) {
    StartCameraWobble(gCourseWobbleAmplitude, 0, 0x1000);
}

void UpdateCameraWobble(Camera *camera) {
    s32 factor;
    BOOL flag;

    if (camera->mWobbling == FALSE) {
        return;
    }
    camera->mFactor = camera->mFactor + camera->mWobblePerFrame * camera->mWobbleDirection;
    factor = camera->mFactor;
    if (factor > 0x1000) {
        camera->mWobbleDirection *= -1;
        camera->mFactor = 0x2000 - camera->mFactor;
    } else if (factor < -0x1000) {
        camera->mWobbleDirection *= -1;
        camera->mFactor = -0x2000 - camera->mFactor;
    }
    camera->mWobbleAmplitude = MUL_FIXED12_NO_ROUND(camera->mWobbleAmplitude, camera->mWobbleDecay);
    camera->mWobbleAmplitude = camera->mWobbleAmplitude - 0x14;
    camera->mWobbleOffset = MUL_FIXED12_NO_ROUND(camera->mFactor, camera->mWobbleAmplitude);
    if (camera->mWobbleAmplitude <= 0) {
        flag = FALSE;
        camera->mWobbleOffset = flag;
        camera->mWobbling = flag;
    }
}
