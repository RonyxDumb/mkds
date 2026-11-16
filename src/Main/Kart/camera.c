#include "Main/Kart/camera.h"
#include "Main/Kart/point_link_cursor.h" // PosCurve

#include "ITCM/kart_motion.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "fixed_vector_math.h"
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
#include "Main/Kart/kart_model_menu.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "ITCM/sphere_collision.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "matrix_3x3_basic.h"
#include "system_state_globals.h"
#include "model_draw_state.h"
#include "Main/Race/kart.h"
#include "Main/Kart/camera_shake.h"
#include "Main/System/init_after_startup.h"

s32 gDefaultLookAtHeight;
struct Camera *g_GlobalHD5;
Camera *g_GlobalHD2;
s32 gFollowHeight;
s32 gChaseCameraUnusedWord;
Camera *g_AnotherGlobalHD;
s32 gCameraEntryChanged;
s32 gEntryCameraUpdateRan;
s32 gDefaultFollowDistance;
Camera *gCurrentChainCamera;
Camera *g_GlobalHD;
MtxFx44 gProjectionMatrix;

MtxFx44 *GetProjectionMatrix(void) {
    return &gProjectionMatrix;
}

static inline s32 CameraNormalizeLengthOrZero(Vec3 *src, Vec3 *dst) {
    if (LENGTH_SQUARED(*src) < 0x10) {
        return 0;
    }
    return Vector3_MaybeNormalize(src, dst);
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
                  camera->mNear, farPlane, 0x1000, 0, &g_GlobalG3.mProjMtx);
    g_GlobalG3.mFlag &= ~0x50;
}

void ApplyCameraLookAt(Camera *camera) {
    Vec3 *viewPos = &camera->mViewPos;
    Vec3 *viewLookAt = &camera->mViewLookAt;

    g_GlobalG3.mCamPos = *viewPos;
    g_GlobalG3.mCamUp = camera->mUp;
    g_GlobalG3.mCamTarget = *viewLookAt;
    G3i_LookAt_(viewPos, &camera->mUp, viewLookAt, 0, &g_GlobalG3.mCameraMtx);
    g_GlobalG3.mFlag &= ~0xe8;
}

// Chase camera only: sets up the camera, then puts it behind the selected Kart.
void SetupCameraBehindKart(void) {
    Kart *kart;
    Camera *chaseCamera;
    MtxFx33 axes;
    Vec3 offset;
    s32 behindDistance;

    kart = GetRacerMQEntry(g_GlobalCO->mEntryIndex);
    StructHD_SomeFn(g_GlobalHD5);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        if (g_GlobalCO->mMissionRunBits & MISSION_RUN_BIT_FLIP_FOLLOW_DIRECTION) {
            g_GlobalHD5->mFollowDirectionSign = -0x1000;
        }
    }
    chaseCamera = g_GlobalHD5;
    Matrix3x3FromQuaternion(&axes, &kart->mHeadingQuaternion);
    behindDistance = MUL_FIXED12_ROUNDED(-gDefaultFollowDistance, chaseCamera->mFollowDirectionSign);
    offset.x = MUL_FIXED12_NO_ROUND(axes.mRows[2].x, behindDistance);
    offset.y = MUL_FIXED12_NO_ROUND(axes.mRows[2].y, behindDistance);
    offset.z = MUL_FIXED12_NO_ROUND(axes.mRows[2].z, behindDistance);
    VecFx32_Add(&kart->mPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + gFollowHeight;
    chaseCamera->mBaseUp = gCameraVec3UnitY;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = TO_FIXED12(1);
    g_GlobalHD5->mHeightHold = 0;
    UpdateViewFrustum(&chaseCamera->mViewMatrix);
    RequestViewTestRefresh();
    g_GlobalHD5->mLookAt.y = kart->mPos.y + g_GlobalHD5->mLookAtHeight;
}

void StructHD_SomeMQFn(Camera *camera, Kart *kart) {
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
        GetMQRacerVector333(kart, &forward);
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
    VecFx32_Subtract(&kart->mPos, &kart->mPrevPos, &kartMovement);
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
    StructMQRacerEntry_GetVec555(kart, &kartUp);
    UpdateChaseCameraLookAt(&camera->mLookAt, &camera->mLookAtOffset, &camera->mLookAtLowering, kart, scaledHopHeight,
                            camera->mLookAtHeight);
    kartPos.y = kartPos.y - scaledHopHeight;
    adjustedKartPos = kartPos;
    StructHD_SomeFn_6(camera, kart, &forward);
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
    StructHD_SomeFn_5(camera, kart, &forward);
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
        StructMQRacerEntry_GetVec555(kart, &targetUp);
    } else {
        targetUp = gCameraVec3UnitY;
    }
    VecFx32_Subtract(&targetUp, &camera->mBaseUp, &upStep);
    upStep.x = MUL_FIXED12_NO_ROUND(upStep.x, 0x800);
    upStep.y = MUL_FIXED12_NO_ROUND(upStep.y, 0x800);
    upStep.z = MUL_FIXED12_NO_ROUND(upStep.z, 0x800);
    VecFx32_Add(&camera->mBaseUp, &upStep, &camera->mBaseUp);
    if (camera->mHeightHold != 0) {
        camera->mLookAtHeight = camera->mLookAtHeight - TO_FIXED12(1);
        if (camera->mLookAtHeight < CAMERA_LOOK_AT_HEIGHT_MIN) {
            camera->mLookAtHeight = CAMERA_LOOK_AT_HEIGHT_MIN;
        }
        if (camera->mHeldHeightEasing == FALSE && kart->mPos.y > camera->mHeldHeight) {
            camera->mHeldHeightEasing = TRUE;
        }
    } else if (camera->mLookAtHeight < gDefaultLookAtHeight) {
        camera->mLookAtHeight = camera->mLookAtHeight + 0x1000;
    } else {
        camera->mLookAtHeight = gDefaultLookAtHeight;
    }
    StructHD_SomeFn_4(camera);
}

void StructHD_SomeFn_5(Camera *camera, Kart *kart, Vec3 *forward) {
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
                    if (VecFx32_CrossProduct_0(&pushOutDirection, &secondNormal) < 0xf5c) {
                        if (VecFx32_CrossProduct_0(&pushOutDirection, forward) > 0xb5c) {
                            camera->mCollisionState = CAMERA_COLLISION_STATE_LENGTH;
                        }
                    }
                }
            }
            camera->mCollisionActive = TRUE;
            value = VecFx32_CrossProduct_0(&turnedForward, &secondNormal);
            collided = TRUE;
            collisionState = camera->mCollisionState;
            if (collisionState == CAMERA_COLLISION_STATE_LENGTH ||
                (collisionState == CAMERA_COLLISION_STATE_NONE && value < -0xd9a &&
                 VecFx32_CrossProduct_0(&turnedForward, forward) < 0)) {
                if (secondNormal.y < -0xe66) {
                    camera->mCollisionState = CAMERA_COLLISION_STATE_NONE;
                    collided = FALSE;
                    camera->mCollisionActive = FALSE;
                } else {
                    camera->mCollisionOffsetLengthGoal = VecFx32_Norm(&pushOut);
                    camera->mCollisionState = CAMERA_COLLISION_STATE_LENGTH;
                }
            } else if (VecFx32_CrossProduct_0(forward, &secondNormal) > 0) {
                camera->mCollisionState = CAMERA_COLLISION_STATE_OFFSET;
            } else {
                camera->mCollisionLatch = TRUE;
                collided = FALSE;
            }
        } else if (flags & 0x1e34ef) {
            if (g_GlobalCO->mMode != MODE_BATTLE || Vector3_DotProduct(&gCameraVec3UnitY, &firstNormal) < 0xfae ||
                camera->mPos.y - kart->mPos.y < gFollowHeight) {
                VecFx32_Add(&pushOut, &camera->mPos, &camera->mPos);
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
        VecFx32_Subtract(&pushOut, &camera->mPosGoalCollisionOffset, &offsetStep);
        offsetStep.x = MUL_FIXED12_NO_ROUND(offsetStep.x, 0x4cd);
        offsetStep.y = MUL_FIXED12_NO_ROUND(offsetStep.y, 0x4cd);
        offsetStep.z = MUL_FIXED12_NO_ROUND(offsetStep.z, 0x4cd);
        VecFx32_Add(&camera->mPosGoalCollisionOffset, &offsetStep, &camera->mPosGoalCollisionOffset);
        camera->mCollisionState = CAMERA_COLLISION_STATE_NONE;
    }
    camera->mCollisionOffsetLength =
        camera->mCollisionOffsetLength +
        MUL_FIXED12_ROUNDED(camera->mCollisionOffsetLengthGoal - camera->mCollisionOffsetLength, 0x11f);
}

void StructHD_SomeFn_6(Camera *camera, Kart *kart, Vec3 *forward) {
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

void StartEntryCameraAngleStart(void) {
    Camera *entryCamera = g_AnotherGlobalHD;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    courseMapCamera = g_GlobalPE->mFirstAngleStartCamera;
    if (courseMapCamera == NULL) {
        return;
    }
    entryCamera->mAngleStartRunning = TRUE;
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        StructVC_SomeFnLinkedRouteRelated(&entryCamera->mPosCurve, courseMapCamera);
        if (g_GlobalCO->mMode == MODE_BATTLE) {
            SetupReversePosCurve(&entryCamera->mReversePosCurve, courseMapCamera);
        }
    }
    if (IsRacerFinishedRace(GetRacerMQEntry(g_GlobalCO->mEntryIndex)->mIndex) != 0) {
        localRandom = &g_GlobalMV->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

// Sets mEntryUpdateHold; with a != 0 and the kind 6 entry still running, also picks the entry at the followed Kart's
// position.
void SetEntryCameraUpdateHold(s32 hold) {
    CourseMapCamera *courseMapCamera;
    Camera *entryCamera = g_AnotherGlobalHD;
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
    if (entryCamera->mAngleStartRunning == FALSE) {
        return;
    }
    entryCamera->mAngleStartRunning = FALSE;
    LoadRacerMQVectorB(&kartPos, entryCamera->mFollowedKartIndex);
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
        StructVC_SomeFnLinkedRouteRelated(&entryCamera->mPosCurve, courseMapCamera);
        if (g_GlobalCO->mMode == MODE_BATTLE) {
            SetupReversePosCurve(&entryCamera->mReversePosCurve, courseMapCamera);
        }
    }
    if (IsRacerFinishedRace(GetRacerMQEntry(g_GlobalCO->mEntryIndex)->mIndex) != 0) {
        localRandom = &g_GlobalMV->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

void DisableEntryCameraUpdate(void) {
    g_AnotherGlobalHD->mEntryUpdateDisabled = 1;
}

static inline void MulVec3Fixed12NoRound(Vec3 *destination, const Vec3 *source, s32 scale) {
    destination->x = MUL_FIXED12_NO_ROUND(source->x, scale);
    destination->y = MUL_FIXED12_NO_ROUND(source->y, scale);
    destination->z = MUL_FIXED12_NO_ROUND(source->z, scale);
}

BOOL StructHD_SomeFn_7(Camera *camera) {
    BOOL result = TRUE;
    CourseMapCamera *courseMapCamera;
    Vec3 kartPos;
    s32 courseMapCameraIndex;

    camera->mPrevPos = camera->mPos;
    gEntryCameraUpdateRan = 1;
    if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
        StructHD_SomeFn_13(camera);
        return TRUE;
    }
    if (camera->mEntryUpdateHold != 0 || camera->mEntryUpdateDisabled != FALSE) {
        return FALSE;
    }
    camera->mPrevPos = camera->mPos;
    if (camera->mMissionRunCameraRunning != FALSE) {
        StructHD_SomeFn_12(camera);
        return TRUE;
    }
    LoadRacerMQVectorB(&kartPos, camera->mFollowedKartIndex);
    courseMapCameraIndex = GetCourseMapCameraIndexAtPos(&kartPos);
    if (camera->mAngleStartRunning != FALSE) {
        if (g_GlobalCO->mMode == MODE_BATTLE) {
            StructHD_SomeFn_1(camera);
            return TRUE;
        }
        camera->mAngleStartFrames = camera->mAngleStartFrames + 1;
        if (camera->mAngleStartFrames >= CAMERA_ANGLE_START_FRAMES) {
            camera->mAngleStartRunning = FALSE;
        }
    }
    if (courseMapCameraIndex == -1) {
        result = FALSE;
    } else {
        RandomState64 *localRandom;

        courseMapCamera = g_GlobalPE->mCameras + (u16) courseMapCameraIndex;
        if (courseMapCameraIndex != camera->mLastCourseMapCameraIndex) {
            camera->mLastCourseMapCameraIndex = courseMapCameraIndex;
            if (camera->mAngleStartRunning == FALSE) {
                camera->mCourseMapCamera = courseMapCamera;
                camera->mFovBlend = 0;
                camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
                camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
                camera->mShakeKind = courseMapCamera->mShakeKind;
                if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
                    StructVC_SomeFnLinkedRouteRelated(&camera->mPosCurve, courseMapCamera);
                    if (g_GlobalCO->mMode == MODE_BATTLE) {
                        SetupReversePosCurve(&camera->mReversePosCurve, courseMapCamera);
                    }
                }
                if (IsRacerFinishedRace(GetRacerMQEntry(g_GlobalCO->mEntryIndex)->mIndex) != 0) {
                    localRandom = &g_GlobalMV->mLocalRandom;
                    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
                }
                gCameraEntryChanged = 1;
            }
        }
        StructHD_SomeFn_1(camera);
    }
    return result;
}

void StructHD_SomeFn_1(Camera *camera) {
    CourseMapCamera *courseMapCamera;
    s32 secondOffset;
    switch (camera->mCourseMapCamera->mKind) {
        case COURSE_MAP_CAMERA_KIND_STATIC_LOOK_AT_KART:
            camera->mPos = camera->mCourseMapCamera->mPosOrParams;
            if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
                camera->mFollowedKartIndex = FROM_FIXED12(camera->mCourseMapCamera->mLookAtEndOrParams.z) - 1;
                LoadRacerMQVectorB(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mLookAtStartOrParams.y;
            } else {
                LoadRacerMQVectorB(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + 0x6000;
            }
            StructHD_SomeLookAt(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_CURVE_LOOK_AT_KART:
            StructHD_SomeFn_3(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_ANGLE:
        case COURSE_MAP_CAMERA_KIND_ANGLE_START:
            StructHD_SomeFn_12(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_STATIC_LOOK_AT_BLEND:
            camera->mPos = camera->mCourseMapCamera->mPosOrParams;
            StructHD_SomeFn_8(camera);
            StructHD_SomeFn_10(camera);
            break;
        case COURSE_MAP_CAMERA_KIND_CURVE_LOOK_AT_BLEND:
            StructHD_SomeFn_9(camera);
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
        if (camera->mFovBlend > TO_FIXED12(1)) {
            camera->mFovBlend = TO_FIXED12(1);
        }
    } else {
        camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
        camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    }
}

void StartEntryCameraMissionRun(void) {
    Camera *entryCamera;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    entryCamera = g_AnotherGlobalHD;
    courseMapCamera = g_GlobalPE->mFirstMissionRunCamera;

    if (courseMapCamera == NULL) {
        return;
    }
    entryCamera->mMissionRunCameraRunning = TRUE;
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        StructVC_SomeFnLinkedRouteRelated(&entryCamera->mPosCurve, courseMapCamera);
        if (g_GlobalCO->mMode == MODE_BATTLE) {
            SetupReversePosCurve(&entryCamera->mReversePosCurve, courseMapCamera);
        }
    }
    if (IsRacerFinishedRace(GetRacerMQEntry(g_GlobalCO->mEntryIndex)->mIndex) != 0) {
        localRandom = &g_GlobalMV->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

static inline void SetNextCourseMapCamera(Camera *camera) {
    CourseMapCamera *nextCourseMapCamera;

    if (camera->mCourseMapCamera->mNextIndex == -1) {
        nextCourseMapCamera = NULL;
    } else {
        nextCourseMapCamera = g_GlobalPE->mCameras + (u16) camera->mCourseMapCamera->mNextIndex;
    }
    if (nextCourseMapCamera == NULL) {
        g_GlobalMV->mCameraChainEnded = 1;
        return;
    }
    camera->mCourseMapCameraFrames = 0;
    camera->mCourseMapCamera = nextCourseMapCamera;
    camera->mLookAtBlend = 0;
    camera->mFovBlend = 0;
    if ((s16) nextCourseMapCamera->mEntryGroupIndex != -1) {
        StructVC_SomeFnLinkedRouteRelated(&camera->mPosCurve, nextCourseMapCamera);
    }
    if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        SetSomeAwardModeProperty(nextCourseMapCamera->mShakeKind != 0);
    }
    gCameraEntryChanged = 1;
}

MtxFx43 *SomeLookAtHD_HD2(void) {
    if (g_GlobalHD2->mCourseMapCamera != NULL) {
        if (g_GlobalHD2->mCourseMapCamera->mKind == COURSE_MAP_CAMERA_KIND_CHAIN_PAIR) {
            g_GlobalHD->mFrustumShift = CAMERA_FRUSTUM_SHIFT_UP;
            g_GlobalHD2->mFrustumShift = CAMERA_FRUSTUM_SHIFT_DOWN;
        } else {
            g_GlobalHD2->mFrustumShift = CAMERA_FRUSTUM_SHIFT_NONE;
            g_GlobalHD->mFrustumShift = g_GlobalHD2->mFrustumShift;
        }
    }
    StructHD_SomeFn_0(g_GlobalHD);
    if (g_GlobalHD2->mFrustumShift == CAMERA_FRUSTUM_SHIFT_DOWN) {
        g_GlobalHD2->mHalfFovPairFirst = g_GlobalHD->mHalfFovPairFirst;
        g_GlobalHD2->mHalfFovPairSecond = g_GlobalHD->mHalfFovPairSecond;
        g_GlobalHD2->mPos = g_GlobalHD->mPos;
        g_GlobalHD2->mLookAt = g_GlobalHD->mLookAt;
    } else {
        StructHD_SomeFn_0(g_GlobalHD2);
    }
    if (GetRaceUpdateFramesMod2() == 0) {
        StructHD_SomeLookAt(g_GlobalHD);
        gCurrentChainCamera = g_GlobalHD;
        return &g_GlobalHD->mViewMatrix;
    }
    StructHD_SomeLookAt(g_GlobalHD2);
    gCurrentChainCamera = g_GlobalHD2;
    return &g_GlobalHD2->mViewMatrix;
}

MtxFx43 *SomeLookAtHD3(void) {
    StructHD_SomeFn_0(g_GlobalHD);
    StructHD_SomeLookAt(g_GlobalHD);
    gCurrentChainCamera = g_GlobalHD;
    return &g_GlobalHD->mViewMatrix;
}

void StructHD_SomeFn_0(Camera *camera) {
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    StructHD_SomeFn_1(camera);
    camera->mCourseMapCameraFrames = camera->mCourseMapCameraFrames + 1;
    if (camera->mCourseMapCameraFrames != camera->mCourseMapCamera->mFrameCount) {
        return;
    }
    SetNextCourseMapCamera(camera);
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    if (camera != g_GlobalHD) {
        return;
    }
    if (camera->mFrustumShift != CAMERA_FRUSTUM_SHIFT_UP) {
        return;
    }
    SetNextCourseMapCamera(g_GlobalHD2);
}

void StructHD_SomeFn_3(Camera *camera) {
    StructHD_SomeFn_11(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = FROM_FIXED12(camera->mCourseMapCamera->mLookAtEndOrParams.z) - 1;
        LoadRacerMQVectorB(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mLookAtStartOrParams.y;
    } else {
        LoadRacerMQVectorB(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    StructHD_SomeLookAt(camera);
}

void StructHD_SomeFn_12(Camera *camera) {
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

    if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = FROM_FIXED12(courseMapCamera->mLookAtEndOrParams.z) - 1;
        LoadRacerMQVectorB(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mLookAtStartOrParams.y;
    } else {
        LoadRacerMQVectorB(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    kart = GetRacerMQEntry(camera->mFollowedKartIndex);
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
    Vector3_Cross(&gCameraVec3UnitY, &baseDirection, &sideAxis);
    Vector3_Cross(&crossInput, &sideAxis, &upAxis);
    MTX_RotAxis33(&yawMatrix, &upAxis, FX_SinIdx(startYaw), FX_CosIdx(startYaw));
    MTX_RotAxis33(&pitchMatrix, &sideAxis, FX_SinIdx(startPitch), FX_CosIdx(startPitch));
    MTX_Concat33(&pitchMatrix, &yawMatrix, &startRotation);
    MTX_MultVec33(&lookDirection, &startRotation, &lookDirection);
    MulVec3Fixed12NoRound(&offset, &lookDirection, courseMapCamera->mLookAtStartOrParams.z);
    VecFx32_Add(&camera->mLookAt, &offset, &camera->mPos);
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
    VecFx32_Add(&camera->mPos, &lookAtOffset, &camera->mLookAt);
    camera->mLookAt.y = camera->mLookAt.y - kart->mHopHeight;
    camera->mPos.y = camera->mPos.y - kart->mHopHeight;
    if (g_GlobalCO->mMode != MODE_MISSION_RUN && g_GlobalCO->mMode != MODE_BATTLE) {
        if (CollideSphereWithCourse(&camera->mPos, &camera->mPrevPos, 0, gCameraCollisionRadius >> 1, 2, -2, &pushOut,
                                    NULL, NULL, NULL, NULL, NULL, NULL, NULL) != 0) {
            kart = GetRacerMQEntry(camera->mFollowedKartIndex);
            axis = &kart->mRotationRow0;
            value = Vector3_DotProduct(axis, &pushOut);
            pushOut.x = MUL_FIXED12_NO_ROUND(kart->mRotationRow0.x, value);
            pushOut.y = MUL_FIXED12_NO_ROUND(axis->y, value);
            pushOut.z = MUL_FIXED12_NO_ROUND(axis->z, value);
            VecFx32_Add(&pushOut, &camera->mPos, &camera->mPos);
        }
    }
    StructHD_SomeLookAt(camera);
}

void StructHD_SomeFn_13(Camera *camera) {
    Kart *kart = GetRacerMQEntry(camera->mFollowedKartIndex);
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    Vec3 newPos;
    Vec3 newLookAt;
    Vec3 offset;
    Vec3 lightDirection;
    MtxFx33 rotation;

    camera->mLookAtOffset = camera->mLookAt;
    newLookAt = kart->mPos;
    VecFx32_AddScale1(courseMapCamera->mPosOrParams.z, &kart->mRotationRow0, &kart->mPos, &newPos);
    newPos.y = 0x1f4000;
    newLookAt.y = 0x1f4000;
    offset = kart->mRotationRow2;
    offset.y = 0;
    if (LENGTH_SQUARED(offset) >= 0x10) {
        Vector3_MaybeNormalize(&offset, &offset);
    }
    MulVec3Fixed12NoRound(&offset, &offset, courseMapCamera->mPosOrParams.x);
    VecFx32_Add(&newPos, &offset, &newPos);
    VecFx32_Add(&newLookAt, &offset, &newLookAt);
    if (GetSomeTimeOrDuration() < courseMapCamera->mFrameCount) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
    } else if (camera->mFactor < TO_FIXED12(1)) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
        camera->mFactor = camera->mFactor + 0x52;
        VecFx32_Subtract(&camera->mPrevPos, &camera->mPos, &camera->mPosOffset);
        VecFx32_Subtract(&camera->mLookAtOffset, &camera->mLookAt, &camera->mLookAtOffset);
        VecFx32_AddScale1(camera->mFactor, &camera->mPosOffset, &newPos, &camera->mPos);
        VecFx32_AddScale1(camera->mFactor, &camera->mLookAtOffset, &newLookAt, &camera->mLookAt);
    }
    StructHD_SomeLookAt(camera);
    VecFx32_Subtract(&newPos, &newLookAt, &lightDirection);
    if (SQUARE_SUM3(lightDirection.x, lightDirection.y, lightDirection.z) >=
        0x10) {
        Vector3_MaybeNormalize(&lightDirection, &lightDirection);
    }
    MTX_RotAxis33(&rotation, &gCameraVec3UnitY, FX_SinIdx(gStaffRollLightRotationAngle),
                  FX_CosIdx(gStaffRollLightRotationAngle));
    MTX_MultVec33(&lightDirection, &rotation, &lightDirection);
    lightDirection.x = MUL_FIXED12_NO_ROUND(lightDirection.x, 0xfae);
    lightDirection.y = MUL_FIXED12_NO_ROUND(lightDirection.y, 0xfae);
    lightDirection.z = MUL_FIXED12_NO_ROUND(lightDirection.z, 0xfae);
    SetSomeTDVector(&lightDirection);
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
        if (camera->mFovBlend > TO_FIXED12(1)) {
            camera->mFovBlend = TO_FIXED12(1);
        }
    } else {
        camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
        camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    }
}

void StructHD_SomeFn_11(Camera *camera, s32 paramPerFrame) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    u16 pointCount = g_GlobalPE->mEntryGroups[courseMapCamera->mEntryGroupIndex].mEntryCount;
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
    firstEntry = GetLoadedNkmPathEntryPOIT(courseMapCamera->mEntryGroupIndex, 0);
    secondEntry = GetLoadedNkmPathEntryPOIT(courseMapCamera->mEntryGroupIndex, 1);
    startPos = firstEntry->mPos;
    VecFx32_Subtract(&secondEntry->mPos, &firstEntry->mPos, &direction);
    if (LENGTH_SQUARED(direction) < 0x10) {
        value = 0;
    } else {
        value = Vector3_MaybeNormalize(&direction, &direction);
    }
    camera->mPosCurve.mParam += paramPerFrame;
    if (camera->mPosCurve.mParam >= TO_FIXED12(1)) {
        camera->mPosCurve.mParam = TO_FIXED12(1);
    }
    value = MUL_FIXED12_NO_ROUND(camera->mPosCurve.mParam, value);
    offset.x = MUL_FIXED12_NO_ROUND(direction.x, value);
    offset.y = MUL_FIXED12_NO_ROUND(direction.y, value);
    offset.z = MUL_FIXED12_NO_ROUND(direction.z, value);
    VecFx32_Add(&startPos, &offset, &camera->mPos);
}

void StructHD_SomeFn_9(Camera *camera) {
    StructHD_SomeFn_11(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    StructHD_SomeFn_8(camera);
    StructHD_SomeFn_10(camera);
}

void StructHD_SomeFn_8(Camera *camera) {
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
        if (camera->mLookAtBlend > TO_FIXED12(1)) {
            camera->mLookAtBlend = TO_FIXED12(1);
        }
    } else {
        camera->mLookAt.x = courseMapCamera->mLookAtStartOrParams.x;
        camera->mLookAt.y = courseMapCamera->mLookAtStartOrParams.y;
        camera->mLookAt.z = courseMapCamera->mLookAtStartOrParams.z;
    }
}

Camera *GetGlobalHD5(void) {
    return g_GlobalHD5;
}

Camera *GetAnotherGlobalHD(void) {
    return g_AnotherGlobalHD;
}

Camera *GetCurrentChainCamera(void) {
    return gCurrentChainCamera;
}

// Chase camera (g_GlobalHD5) only.
void SetCameraHalfFovAngleGoal(u32 halfFovAngleGoal) {
    g_GlobalHD5->mHalfFovAngleGoal = halfFovAngleGoal;
}

// Chase camera (g_GlobalHD5) only.
void ResetCameraHalfFovAngleGoal(void) {
    u32 unused;
    g_GlobalHD5->mHalfFovAngleGoal = gDefaultHalfFovAngle;
}

// Chase camera only: resets the field-of-view angle goal to its default and the angle to default + 5.
void ResetCameraHalfFovAngle(void) {
    s32 defaultHalfFovAngle;

    defaultHalfFovAngle = gDefaultHalfFovAngle;
    g_GlobalHD5->mHalfFovAngleGoal = defaultHalfFovAngle;
    g_GlobalHD5->mHalfFovAngle = defaultHalfFovAngle + 5;
}

// Chase camera (g_GlobalHD5) only.
void SetCameraHeightHold(s32 hold) {
    g_GlobalHD5->mHeightHold = hold;
    if (hold == 0) {
        return;
    }
    g_GlobalHD5->mHeldHeight = g_GlobalHD5->mPos.y;
    g_GlobalHD5->mHeldHeightEasing = FALSE;
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
    VecFx32_AddScale1(lookAtHeight, &kart->mRotationRow1, &targetPos, &targetPos);
    lookAtGoal.y = lookAtGoal.y + (lookAtHeight - scaledHopHeight);
    if (!(kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD)) {
        offsetGoal = gCameraVec3Zero;
    } else {
        VecFx32_Subtract(&targetPos, &lookAtGoal, &offsetGoal);
        VecFx32_AddScale1(0xa000, &kart->mRotationRow1, &offsetGoal, &offsetGoal);
    }
    VecFx32_Subtract(&offsetGoal, lookAtOffset, &offsetStep);
    offsetStep.x = MUL_FIXED12_NO_ROUND(offsetStep.x, 0x266);
    offsetStep.y = MUL_FIXED12_NO_ROUND(offsetStep.y, 0x266);
    offsetStep.z = MUL_FIXED12_NO_ROUND(offsetStep.z, 0x266);
    VecFx32_Add(lookAtOffset, &offsetStep, lookAtOffset);
    VecFx32_Add(&lookAtGoal, lookAtOffset, &lookAtGoal);
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
    StructMQRacerEntry_GetVec555(kart, &kartUp);
    if (followDistance < 500) {
        followDistance = 500;
    }
    VecFx32_Subtract(&kart->mPos, &kart->mPrevPos, &kartMovement);
    if (kart->mDriveFlags & KART_DRIVE_RESPAWN_FALL) {
        if (kart->mEffectFlags & KART_EFFECT_WATER_FALL) {
            return;
        }
        camera->mKartMoveScale = MUL_FIXED12_NO_ROUND(camera->mKartMoveScale, 0xe66);
        VecFx32_AddScale1(camera->mKartMoveScale, &kartMovement, pos, pos);
        return;
    }
    kartMovement.y = 0;
    VecFx32_Add(pos, &kartMovement, pos);
    negatedFollowDistance = -followDistance;
    followOffset.x = MUL_FIXED12_NO_ROUND(forwardCopy.x, negatedFollowDistance);
    followOffset.y = MUL_FIXED12_NO_ROUND(forwardCopy.y, negatedFollowDistance);
    followOffset.z = MUL_FIXED12_NO_ROUND(forwardCopy.z, negatedFollowDistance);
    VecFx32_Add(&followOffset, &camera->mPosGoalKartOffset, &followOffset);
    VecFx32_Add(&followOffset, &camera->mPosGoalCollisionOffset, &followOffset);
    VecFx32_AddScale1(gFollowHeight, &kartUp, &followOffset, &liftedOffset);
    VecFx32_Add(kartPos, &liftedOffset, &heightenedPos);
    followOffset.y = gFollowHeight;
    VecFx32_Add(kartPos, &followOffset, &followPos);
    posGoal = followPos;
    posGoal.y = posGoal.y + camera->mPosGoalYOffset;
    if (!(kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD)) {
        offsetGoal = gCameraVec3Zero;
    } else {
        VecFx32_Subtract(&heightenedPos, &posGoal, &offsetGoal);
        VecFx32_AddScale1(-0x1e000, &kartUp, &offsetGoal, &offsetGoal);
    }
    VecFx32_Subtract(&offsetGoal, posOffset, &offsetStep);
    offsetStep.x = MUL_FIXED12_NO_ROUND(offsetStep.x, 0x19a);
    offsetStep.y = MUL_FIXED12_NO_ROUND(offsetStep.y, 0x19a);
    offsetStep.z = MUL_FIXED12_NO_ROUND(offsetStep.z, 0x19a);
    VecFx32_Add(posOffset, &offsetStep, posOffset);
    VecFx32_Add(&posGoal, posOffset, &posGoal);
    VecFx32_Subtract(&posGoal, pos, &goalDelta);
    goalDeltaY = goalDelta.y;
    length = 0;
    goalDelta.y = 0;
    if (LENGTH_SQUARED(goalDelta) >= 16) {
        length = Vector3_MaybeNormalize(&goalDelta, &goalDelta);
    }
    VecFx32_AddScale1(MUL_FIXED12_NO_ROUND(length, 0x11f), &goalDelta, pos, pos);
    pos->y = pos->y + ((s32) (((s64) goalDeltaY * 0x11f) >> 9) + collisionShorten * 2);
    if (camera->mHeightHold != 0) {
        if (camera->mHeldHeightEasing != FALSE) {
            s32 heightDelta;
            heightDelta = pos->y - camera->mHeldHeight;
            camera->mHeldHeight = camera->mHeldHeight + MUL_FIXED12_ROUNDED(heightDelta, 0x29);
        }
        pos->y = camera->mHeldHeight;
    }
    VecFx32_Subtract(pos, kartPos, &kartToPos);
    kartToPosDirection = kartToPos;
    length = 0;
    if (LENGTH_SQUARED(kartToPosDirection) >= 16) {
        length = Vector3_MaybeNormalize(&kartToPosDirection, &kartToPosDirection);
    }
    if (length == 0) {
        return;
    }
    VecFx32_AddScale1(MUL_FIXED12_NO_ROUND(camera->mFollowDistance, camera->mFollowDistanceScale), &kartToPosDirection,
                kartPos, pos);
}

// Puts the chase camera at a minus mFollowDistance along axis 2 of the matrix b (the kart's).
void ResetCameraBehind(const Vec3 *kartPos, void *quaternion) {
    Camera *chaseCamera;
    MtxFx33 axes;
    Vec3 offset;
    s32 behindDistance;

    chaseCamera = g_GlobalHD5;
    Matrix3x3FromQuaternion(&axes, quaternion);
    behindDistance = MUL_FIXED12_ROUNDED(-gDefaultFollowDistance, chaseCamera->mFollowDirectionSign);
    offset.x = MUL_FIXED12_NO_ROUND(axes.mRows[2].x, behindDistance);
    offset.y = MUL_FIXED12_NO_ROUND(axes.mRows[2].y, behindDistance);
    offset.z = MUL_FIXED12_NO_ROUND(axes.mRows[2].z, behindDistance);
    VecFx32_Add(kartPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + gFollowHeight;
    chaseCamera->mBaseUp = gCameraVec3UnitY;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = TO_FIXED12(1);
    g_GlobalHD5->mHeightHold = 0;
    UpdateViewFrustum(&chaseCamera->mViewMatrix);
    RequestViewTestRefresh();
}

// Chase camera (g_GlobalHD5) only.
void StartCameraWobble(s32 baseAmplitude, u32 distance, s32 scale) {
    Camera *chaseCamera;
    s32 distanceFactor;
    s32 amplitude;

    distanceFactor = 0x1000;
    chaseCamera = g_GlobalHD5;
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
    chaseCamera->mWobblePerFrame = FIXED12_RATIO(1, 2);
    chaseCamera->mWobbleDirection = 1;
    chaseCamera->mWobbleDecay = FIXED12_RATIO(9, 10);
    chaseCamera->mWobbleOffset = 0;
}

void StartCameraWobbleAtDistance(u32 distance, s32 scale) {
    StartCameraWobble(0x2800, distance, scale);
}

void StartCameraWobbleByCourse(void) {
    StartCameraWobble(gCourseWobbleAmplitude, 0, 0x1000);
}

void StructHD_SomeFn_4(Camera *camera) {
    s32 factor;
    BOOL flag;

    if (camera->mWobbling == FALSE) {
        return;
    }
    camera->mFactor = camera->mFactor + camera->mWobblePerFrame * camera->mWobbleDirection;
    factor = camera->mFactor;
    if (factor > TO_FIXED12(1)) {
        camera->mWobbleDirection *= -1;
        camera->mFactor = TO_FIXED12(2) - camera->mFactor;
    } else if (factor < -TO_FIXED12(1)) {
        camera->mWobbleDirection *= -1;
        camera->mFactor = -TO_FIXED12(2) - camera->mFactor;
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
