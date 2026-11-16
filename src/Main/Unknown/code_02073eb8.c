#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207b960.h" // PosCurve

#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_02010c84.h"
#include "Main/Kart/KartTimes.h"

MtxFx43 *cam_getProjectionMtx(void) {
    return (MtxFx43 *) cam_sProjectionMtx;
}

static inline s32 func_020760ec_inline(Vec3 *src, Vec3 *dst) {
    if ((s64) src->x * src->x + (s64) src->y * src->y + (s64) src->z * src->z < 0x10) {
        return 0;
    }
    return vec_normalize(src, dst);
}

static inline void func_02076528_inline(Vec3 *vec, s32 scale) {
    vec->x = ((s64) vec->x * scale) >> 12;
    vec->y = ((s64) vec->y * scale) >> 12;
    vec->z = ((s64) vec->z * scale) >> 12;
}

// b selects the far plane: non-zero uses the second far value (field8C).
void cam_applyFrustum(Camera *camera, s32 useSecondFar) {
    s32 farPlane;

    if (useSecondFar != 0) {
        farPlane = camera->field8C;
    } else {
        farPlane = camera->mFar;
    }
    G3i_FrustumW_(camera->mFrustumTop, camera->mFrustumBottom, camera->mFrustumLeft, camera->mFrustumRight,
                  camera->mNear, farPlane, 0x1000, 0, &data_021702a4);
    NNS_G3dGlb.mFlag &= ~0x50;
}

void cam_applyLookAt(Camera *camera) {
    Vec3 *viewPos = &camera->mViewPos;
    Vec3 *viewLookAt = &camera->mViewLookAt;

    data_021704dc[0] = *viewPos;
    data_021704dc[1] = *(Vec3 *) camera;
    data_021704dc[2] = *viewLookAt;
    G3i_LookAt_(viewPos, (Vec3 *) camera, viewLookAt, 0, &data_021702e8);
    NNS_G3dGlb.mFlag &= ~0xe8;
}

// Chase camera only: sets up the camera, then puts it behind the selected Kart.
void cam_resetPlayerCamera(void) {
    Kart *kart;
    Camera *chaseCamera;
    Vec3 axes[3];
    Vec3 offset;
    s32 behindDistance;

    kart = driver_getById(gRaceMultiConfig->mEntryIndex);
    cam_init(cam_sPlayerCamera);
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        if (gRaceMultiConfig->field44 & 0x20) {
            cam_sPlayerCamera->mFollowDirectionSign = -0x1000;
        }
    }
    chaseCamera = cam_sPlayerCamera;
    qtrn_toMtx33(&axes, &kart->fieldE0);
    behindDistance = ((s64) -cam_sCameraDistance * chaseCamera->mFollowDirectionSign + 0x800) >> 12;
    offset.x = ((s64) axes[2].x * behindDistance) >> 12;
    offset.y = ((s64) axes[2].y * behindDistance) >> 12;
    offset.z = ((s64) axes[2].z * behindDistance) >> 12;
    VEC_Add(&kart->mPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + cam_sCameraElevation;
    chaseCamera->mBaseUp = cam_sVecUp;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = 0x1000;
    cam_sPlayerCamera->mHeightHold = 0;
    mobj_updateCameraVectors((Unk020d4f94 *) &chaseCamera->mViewMatrix);
    mobj_20D50C4();
    cam_sPlayerCamera->mLookAt.y = kart->mPos.y + cam_sPlayerCamera->mLookAtHeight;
}

void cam_updatePlayerCamera(Camera *camera, Kart *kart) {
    Vec3 kartPos = kart->mPos;
    Vec3 g;
    Vec3 kartMovement;
    Vec3 kartUp;
    Vec3 forward;
    Vec3 targetUp;
    Vec3 upStep;
    s32 scaledHopHeight;
    s32 fovEaseRate;
    s32 t;
    s32 kartOffsetScale;
    Vec3 *p;

    scaledHopHeight = ((s64) kart->mHopHeight * 0xcd0) >> 12;
    if (camera->field258 == FALSE) {
        camera->mPrevPos = camera->mPos;
    }
    if (kart->field4C & KART_4C_HEADING_SWING) {
        forward = camera->mSavedKartForward;
        func_02076528_inline(&forward, camera->mFollowDirectionSign);
    } else {
        driver_getShadowZDirection(kart, &forward);
        func_02076528_inline(&forward, camera->mFollowDirectionSign);
    }
    if (kart->field7C & 0x20) {
        if (mobj_getHasWater() == FALSE) {
            return;
        }
        t = mobj_getWaterPlaneDistance2(camera->mPos.y - 0x5000);
        if (t < 0) {
            camera->mViewPosYOffset = -t;
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
    t = camera->mHalfFovAngleGoal - camera->mHalfFovAngle;
    camera->mHalfFovAngle = camera->mHalfFovAngle + (s32) (((s64) t * fovEaseRate + 0x800) >> 12);
    camera->mHalfFovPairFirst = FX_SinCosTable_[((u16) camera->mHalfFovAngle >> 4) * 2];
    camera->mHalfFovPairSecond = FX_SinCosTable_[((u16) camera->mHalfFovAngle >> 4) * 2 + 1];
    if (kart->field48 & 0x10000) {
        camera->mFollowDistanceScale =
            camera->mFollowDistanceScale + (s32) (((s64) (0x14cd - camera->mFollowDistanceScale) * 0xcd + 0x800) >> 12);
    } else {
        camera->mFollowDistanceScale = camera->mFollowDistanceScale +
                                       (s32) (((s64) (0x1000 - camera->mFollowDistanceScale) * 0x19a + 0x800) >> 12);
    }
    kartMovement.y = 0;
    driver_getShadowYDirection(kart, &kartUp);
    cam_20745D4(&camera->mLookAt, &camera->fieldB4, &camera->mLookAtLowering, kart, scaledHopHeight,
                            camera->mLookAtHeight);
    kartPos.y = kartPos.y - scaledHopHeight;
    g = kartPos;
    cam_2075FE0(camera, kart, &forward);
    cam_20741A0(&camera->mPos, &camera->fieldA8, camera, kart, &g, &forward,
                         ((s64) camera->mCollisionOffsetLength * 0x3000) >> 12);
    if (mobj_getHasWater() != FALSE) {
        t = mobj_getWaterPlaneDistance2(camera->mPos.y - 0x5000);
        if (t < 0) {
            camera->mViewPosYOffset = -t;
        } else {
            camera->mViewPosYOffset = 0;
        }
    }
    cam_applyPlayerCamCollision(camera, kart, &forward);
    p = &kart->field120;
    t = 0;
    if (kart->field44 & KART_44_DRIFTING) {
        t = data_021656c4;
        if (kart->mTurnDirection > 0) {
            t *= -1;
        }
    }
    camera->mPosGoalKartOffsetScale =
        camera->mPosGoalKartOffsetScale + (s32) (((s64) (t - camera->mPosGoalKartOffsetScale) * 0xcd + 0x800) >> 12);
    kartOffsetScale = camera->mPosGoalKartOffsetScale;
    camera->mPosGoalKartOffset.x = ((s64) p->x * kartOffsetScale) >> 12;
    camera->mPosGoalKartOffset.y = ((s64) p->y * kartOffsetScale) >> 12;
    camera->mPosGoalKartOffset.z = ((s64) p->z * kartOffsetScale) >> 12;
    if (kart->field48 & 0x40000000) {
        driver_getShadowYDirection(kart, &targetUp);
    } else {
        targetUp = cam_sVecUp;
    }
    VEC_Subtract(&targetUp, &camera->mBaseUp, &upStep);
    upStep.x = ((s64) upStep.x * 0x800) >> 12;
    upStep.y = ((s64) upStep.y * 0x800) >> 12;
    upStep.z = ((s64) upStep.z * 0x800) >> 12;
    VEC_Add(&camera->mBaseUp, &upStep, &camera->mBaseUp);
    if (camera->mHeightHold != 0) {
        camera->mLookAtHeight = camera->mLookAtHeight - 0x1000;
        if (camera->mLookAtHeight < 0x5000) {
            camera->mLookAtHeight = 0x5000;
        }
        if (camera->mHeldHeightEasing == FALSE && kart->mPos.y > camera->mHeldHeight) {
            camera->mHeldHeightEasing = TRUE;
        }
    } else if (camera->mLookAtHeight < cam_sMaxTargetElevation) {
        camera->mLookAtHeight = camera->mLookAtHeight + 0x1000;
    } else {
        camera->mLookAtHeight = cam_sMaxTargetElevation;
    }
    cam_updateShake(camera);
}

void cam_applyPlayerCamCollision(Camera *camera, Kart *kart, Vec3 *forward) {
    Vec3 pushOut = cam_sVecNull;
    Vec3 w;
    Vec3 x;
    Vec3 y;
    Vec3 z;
    Vec3 t;
    u32 j;
    BOOL m = FALSE;
    s32 k;
    s32 l;

    data_0217aca0 = 0;
    camera->field258 = FALSE;
    if (col_collide(&camera->mPos, (u32 *) &camera->mPrevPos, 0, cam_sColSphereSize, 2, -2, &pushOut, &w, (s32 *) &x,
                      &j, NULL, NULL, NULL, NULL) != 0 &&
        (j & 0xc00) == 0) {
        if (j & 0x214300) {
            y = kart->mTurnedForward;
            if (kart->mForwardSpeed <= 0) {
                y.x = -y.x;
                y.y = -y.y;
                y.z = -y.z;
                k = func_020760ec_inline(&pushOut, &z);
                if (k != 0) {
                    if (vec_dotProduct(&z, &x) < 0xf5c) {
                        if (vec_dotProduct(&z, forward) > 0xb5c) {
                            camera->field254 = 1;
                        }
                    }
                }
            }
            camera->field258 = TRUE;
            k = vec_dotProduct(&y, &x);
            m = TRUE;
            l = camera->field254;
            if (l == 1 || (l == 3 && k < -0xd9a && vec_dotProduct(&y, forward) < 0)) {
                if (x.y < -0xe66) {
                    camera->field254 = 3;
                    m = FALSE;
                    camera->field258 = FALSE;
                } else {
                    camera->mCollisionOffsetLengthGoal = VEC_Mag(&pushOut);
                    camera->field254 = 1;
                }
            } else if (vec_dotProduct(forward, &x) > 0) {
                camera->field254 = 0;
            } else {
                camera->field25C = TRUE;
                m = FALSE;
            }
        } else if (j & 0x1e34ef) {
            if (gRaceMultiConfig->mMode != MODE_BATTLE || VEC_DotProduct(&cam_sVecUp, &w) < 0xfae ||
                camera->mPos.y - kart->mPos.y < cam_sCameraElevation) {
                VEC_Add(&pushOut, &camera->mPos, &camera->mPos);
            }
        }
    }
    if (camera->field258 == FALSE) {
        camera->field25C = FALSE;
    }
    if (m != FALSE && camera->field25C == FALSE) {
        if (camera->field254 == 0) {
            k = (s32) (((s64) (0x1000 - kart->mVelocityLengthRatio) * 0x5000) >> 12) + 0x3000;
            pushOut.x = ((s64) pushOut.x * k) >> 12;
            pushOut.y = ((s64) pushOut.y * k) >> 12;
            pushOut.z = ((s64) pushOut.z * k) >> 12;
            camera->mPosGoalCollisionOffset = pushOut;
            camera->mCollisionOffsetLengthGoal = 0;
        }
    } else {
        camera->mCollisionOffsetLengthGoal = 0;
        VEC_Subtract(&pushOut, &camera->mPosGoalCollisionOffset, &t);
        t.x = ((s64) t.x * 0x4cd) >> 12;
        t.y = ((s64) t.y * 0x4cd) >> 12;
        t.z = ((s64) t.z * 0x4cd) >> 12;
        VEC_Add(&camera->mPosGoalCollisionOffset, &t, &camera->mPosGoalCollisionOffset);
        camera->field254 = 3;
    }
    camera->mCollisionOffsetLength =
        camera->mCollisionOffsetLength +
        (s32) (((s64) (camera->mCollisionOffsetLengthGoal - camera->mCollisionOffsetLength) * 0x11f + 0x800) >> 12);
}

void cam_2075FE0(Camera *camera, Kart *kart, Vec3 *forward) {
    s32 e = -0x2d000;
    s32 j;
    s32 goalYOffset = 0;
    s32 easeRate = 0x11f;
    u32 d = kart->field48;
    s32 forwardY;

    if (d & 0x10000) {
        e = -0x3c000;
    }
    if (kart->field3E8 > 0) {
        easeRate = 0x52;
    }
    if ((kart->field44 & KART_44_ON_GROUND) || (d & 0x10000)) {
        if ((forwardY = forward->y) > 0) {
            goalYOffset = ((s64) forwardY * e) >> 12;
        } else if (forwardY + 0x4cd < 0) {
            goalYOffset = ((s64) forwardY * -0xf000) >> 12;
        }
    }
    if (d & 0x40000000) {
        camera->mPosGoalYOffset =
            camera->mPosGoalYOffset + (s32) (((s64) -camera->mPosGoalYOffset * easeRate + 0x800) >> 12);
        return;
    }
    j = goalYOffset - camera->mPosGoalYOffset;
    camera->mPosGoalYOffset = camera->mPosGoalYOffset + (s32) (((s64) j * easeRate + 0x800) >> 12);
}

void cam_2075EB8(void) {
    Camera *entryCamera = cam_sReplayCamera;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    courseMapCamera = gMapData->mFirstKind6Entry;
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
        camr_initRouteStat(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceMultiConfig->mMode == MODE_BATTLE) {
            camr_initRouteStatReversed(&entryCamera->field1D0, courseMapCamera);
        }
    }
    if (rstat_hasDriverFinished(driver_getById(gRaceMultiConfig->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceStatus->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

// Sets mEntryUpdateHold; with a != 0 and the kind 6 entry still running, also picks the entry at the followed Kart's
// position.
void cam_2075D08(s32 hold) {
    CourseMapCamera *courseMapCamera;
    Camera *entryCamera = cam_sReplayCamera;
    RandomState64 *localRandom;
    Vec3 kartPos;
    s32 courseMapCameraIndex;

    if (entryCamera->mCourseMapCamera == NULL) {
        return;
    }
    if (hold != 0 && entryCamera->mCourseMapCamera->mKind != 5 && entryCamera->mCourseMapCamera->mKind != 6) {
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
    driver_getPosition(&kartPos, entryCamera->mFollowedKartIndex);
    courseMapCameraIndex = mdat_findCameraId(&kartPos);
    if (courseMapCameraIndex < 0) {
        return;
    }
    courseMapCamera = &gMapData->mCameras[(u16) courseMapCameraIndex];
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        camr_initRouteStat(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceMultiConfig->mMode == MODE_BATTLE) {
            camr_initRouteStatReversed(&entryCamera->field1D0, courseMapCamera);
        }
    }
    if (rstat_hasDriverFinished(driver_getById(gRaceMultiConfig->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceStatus->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

u32 cam_2075CF0(void) {
    u32 value0;
    u32 disabled;
    value0 = (u32) &cam_sReplayCamera;
    disabled = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (564)) = disabled;
    return value0;
}

static inline void func_02074b00_inline(Vec3 *v, const Vec3 *u, s32 s) {
    v->x = ((s64) u->x * s) >> 12;
    v->y = ((s64) u->y * s) >> 12;
    v->z = ((s64) u->z * s) >> 12;
}

BOOL cam_updateReplayCamera(Camera *camera) {
    BOOL r = TRUE;
    CourseMapCamera *courseMapCamera;
    Vec3 kartPos;
    s32 courseMapCameraIndex;

    camera->mPrevPos = camera->mPos;
    gEntryCameraUpdateRan = 1;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        cam_updateStaffRollCamera(camera);
        return TRUE;
    }
    if (camera->mEntryUpdateHold != 0 || camera->mEntryUpdateDisabled != FALSE) {
        return FALSE;
    }
    camera->mPrevPos = camera->mPos;
    if (camera->mKind8EntryRunning != FALSE) {
        cam_2074E6C(camera);
        return TRUE;
    }
    driver_getPosition(&kartPos, camera->mFollowedKartIndex);
    courseMapCameraIndex = mdat_findCameraId(&kartPos);
    if (camera->mKind6EntryRunning != FALSE) {
        if (gRaceMultiConfig->mMode == MODE_BATTLE) {
            cam_updateCame(camera);
            return TRUE;
        }
        camera->mKind6EntryFrames = camera->mKind6EntryFrames + 1;
        if (camera->mKind6EntryFrames >= 300) {
            camera->mKind6EntryRunning = FALSE;
        }
    }
    if (courseMapCameraIndex == -1) {
        r = FALSE;
    } else {
        RandomState64 *localRandom;

        courseMapCamera = gMapData->mCameras + (u16) courseMapCameraIndex;
        if (courseMapCameraIndex != camera->mLastCourseMapCameraIndex) {
            camera->mLastCourseMapCameraIndex = courseMapCameraIndex;
            if (camera->mKind6EntryRunning == FALSE) {
                camera->mCourseMapCamera = courseMapCamera;
                camera->mFovBlend = 0;
                camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
                camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
                camera->mShakeKind = courseMapCamera->mShakeKind;
                if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
                    camr_initRouteStat(&camera->mPosCurve, courseMapCamera);
                    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
                        camr_initRouteStatReversed(&camera->field1D0, courseMapCamera);
                    }
                }
                if (rstat_hasDriverFinished(driver_getById(gRaceMultiConfig->mEntryIndex)->mIndex) != 0) {
                    localRandom = &gRaceStatus->mLocalRandom;
                    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
                }
                gCameraEntryChanged = 1;
            }
        }
        cam_updateCame(camera);
    }
    return r;
}

void cam_updateCame(Camera *camera) {
    CourseMapCamera *courseMapCamera;
    s32 secondOffset;
    switch (camera->mCourseMapCamera->mKind) {
        case 0:
            camera->mPos = camera->mCourseMapCamera->field0;
            if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
                camera->mFollowedKartIndex = (camera->mCourseMapCamera->field24.z >> 12) - 1;
                driver_getPosition(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->field18.y;
            } else {
                driver_getPosition(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + 0x6000;
            }
            cam_updateLookAtEx(camera);
            break;
        case 1:
            cam_updateCameByRouteAndDriver(camera);
            break;
        case 5:
        case 6:
            cam_2074E6C(camera);
            break;
        case 2:
            camera->mPos = camera->mCourseMapCamera->field0;
            cam_updateCameTarget(camera);
            cam_updateLookAt(camera);
            break;
        case 3:
            cam_updateCameByRoute(camera);
            break;
    }
    courseMapCamera = camera->mCourseMapCamera;
    if (courseMapCamera->mFovBlendPerFrame != 0) {
        enum { K0 } t = camera->mFovBlend;
        CourseMapCamera *q = courseMapCamera;

        s32 firstStart = q->mHalfFovPairFirst;
        s32 secondStart = q->mHalfFovPairSecond;
        s32 secondEnd = q->mHalfFovPairSecondEnd;
        s32 firstEnd = q->mHalfFovPairFirstEnd;
        s32 firstDelta = firstEnd - firstStart;
        s32 secondDelta = secondEnd - secondStart;

        secondOffset = ((s64) secondDelta * t) >> 12;
        camera->mHalfFovPairFirst = firstStart + (s32) (((s64) firstDelta * t) >> 12);
        camera->mHalfFovPairSecond = secondStart + secondOffset;
        camera->mFovBlend += q->mFovBlendPerFrame;
        if (camera->mFovBlend > 0x1000) {
            camera->mFovBlend = 0x1000;
        }
    } else {
        camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
        camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    }
}

void cam_setupMissionFinishCamera(void) {
    Camera *entryCamera;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    entryCamera = cam_sReplayCamera;
    courseMapCamera = gMapData->mFirstKind8EntryInMode4;

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
        camr_initRouteStat(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceMultiConfig->mMode == MODE_BATTLE) {
            camr_initRouteStatReversed(&entryCamera->field1D0, courseMapCamera);
        }
    }
    if (rstat_hasDriverFinished(driver_getById(gRaceMultiConfig->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceStatus->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

static inline void func_02075424_inline(Camera *camera) {
    CourseMapCamera *nextCourseMapCamera;

    if (camera->mCourseMapCamera->mNextIndex == -1) {
        nextCourseMapCamera = NULL;
    } else {
        nextCourseMapCamera = gMapData->mCameras + (u16) camera->mCourseMapCamera->mNextIndex;
    }
    if (nextCourseMapCamera == NULL) {
        gRaceStatus->mCameraChainEnded = 1;
        return;
    }
    camera->mCourseMapCameraFrames = 0;
    camera->mCourseMapCamera = nextCourseMapCamera;
    camera->mLookAtBlend = 0;
    camera->mFovBlend = 0;
    if ((s16) nextCourseMapCamera->mEntryGroupIndex != -1) {
        camr_initRouteStat(&camera->mPosCurve, nextCourseMapCamera);
    }
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        trl_setVisibleForAward(nextCourseMapCamera->mShakeKind != 0);
    }
    gCameraEntryChanged = 1;
}

MtxFx43 *cam_updateIntroCamDouble(void) {
    if (cam_sIntroCameraBottom->mCourseMapCamera != NULL) {
        if (cam_sIntroCameraBottom->mCourseMapCamera->mKind == 4) {
            cam_sIntroCameraTop->mFrustumShift = 1;
            cam_sIntroCameraBottom->mFrustumShift = 2;
        } else {
            cam_sIntroCameraBottom->mFrustumShift = 0;
            cam_sIntroCameraTop->mFrustumShift = cam_sIntroCameraBottom->mFrustumShift;
        }
    }
    cam_updateIntroCam(cam_sIntroCameraTop);
    if (cam_sIntroCameraBottom->mFrustumShift == 2) {
        cam_sIntroCameraBottom->mHalfFovPairFirst = cam_sIntroCameraTop->mHalfFovPairFirst;
        cam_sIntroCameraBottom->mHalfFovPairSecond = cam_sIntroCameraTop->mHalfFovPairSecond;
        cam_sIntroCameraBottom->mPos = cam_sIntroCameraTop->mPos;
        cam_sIntroCameraBottom->mLookAt = cam_sIntroCameraTop->mLookAt;
    } else {
        cam_updateIntroCam(cam_sIntroCameraBottom);
    }
    if (race_getIsOddFrame() == 0) {
        cam_updateLookAtEx(cam_sIntroCameraTop);
        cam_sIntroCamera = cam_sIntroCameraTop;
        return &cam_sIntroCameraTop->mViewMatrix;
    }
    cam_updateLookAtEx(cam_sIntroCameraBottom);
    cam_sIntroCamera = cam_sIntroCameraBottom;
    return &cam_sIntroCameraBottom->mViewMatrix;
}

MtxFx43 *cam_updateIntroCamSingle(void) {
    cam_updateIntroCam(cam_sIntroCameraTop);
    cam_updateLookAtEx(cam_sIntroCameraTop);
    cam_sIntroCamera = cam_sIntroCameraTop;
    return &cam_sIntroCameraTop->mViewMatrix;
}

void cam_updateIntroCam(Camera *camera) {
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    cam_updateCame(camera);
    camera->mCourseMapCameraFrames = camera->mCourseMapCameraFrames + 1;
    if (camera->mCourseMapCameraFrames != camera->mCourseMapCamera->mFrameCount) {
        return;
    }
    func_02075424_inline(camera);
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    if (camera != cam_sIntroCameraTop) {
        return;
    }
    if (camera->mFrustumShift != 1) {
        return;
    }
    func_02075424_inline(cam_sIntroCameraBottom);
}

void cam_updateCameByRouteAndDriver(Camera *camera) {
    cam_updateCameRoutePos(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = (camera->mCourseMapCamera->field24.z >> 12) - 1;
        driver_getPosition(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->field18.y;
    } else {
        driver_getPosition(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    cam_updateLookAtEx(camera);
}

void cam_2074E6C(Camera *camera) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    Kart *kart;
    Vec3 *v;
    Vec3 a;
    Vec3 d;
    Vec3 t;
    s32 m3[9];
    s32 m2[9];
    s32 m4[9];
    s32 m0[9];
    s32 m6[9];
    s32 m5[9];
    s32 m7[9];
    Vec3 f;
    Vec3 g;
    Vec3 c;
    Vec3 n;
    Vec3 pushOut;
    Vec3 b;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = (courseMapCamera->field24.z >> 12) - 1;
        driver_getPosition(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->field18.y;
    } else {
        driver_getPosition(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    kart = driver_getById(camera->mFollowedKartIndex);
    a = kart->field138;
    i = (u16) ((s32) (((s64) courseMapCamera->field18.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    j = (u16) ((s32) (((s64) courseMapCamera->field18.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    k = (u16) ((s32) (((s64) courseMapCamera->field24.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    l = (u16) ((s32) (((s64) courseMapCamera->field24.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    MTX_RotAxis33((MtxFx43 *) m0, &kart->field120, FX_SinCosTable_[(kart->mHopTiltAngle >> 4) * 2],
                  FX_SinCosTable_[(kart->mHopTiltAngle >> 4) * 2 + 1]);
    MTX_MultVec33(&a, m0, &a);
    b = a;
    c = b;
    d = b;
    func_02074b00_inline(&n, &d, -courseMapCamera->field18.z);
    vec_crossProduct(&cam_sVecUp, &a, &f);
    vec_crossProduct(&c, &f, &g);
    MTX_RotAxis33((MtxFx43 *) m2, &g, FX_SinCosTable_[(i >> 4) * 2], FX_SinCosTable_[(i >> 4) * 2 + 1]);
    MTX_RotAxis33((MtxFx43 *) m3, &f, FX_SinCosTable_[(j >> 4) * 2], FX_SinCosTable_[(j >> 4) * 2 + 1]);
    MTX_Concat33(m3, m2, m4);
    MTX_MultVec33(&d, m4, &d);
    func_02074b00_inline(&t, &d, courseMapCamera->field18.z);
    VEC_Add(&camera->mLookAt, &t, &camera->mPos);
    f.x = -f.x;
    f.y = -f.y;
    f.z = -f.z;
    g.x = -g.x;
    g.y = -g.y;
    g.z = -g.z;
    MTX_RotAxis33((MtxFx43 *) m5, &g, FX_SinCosTable_[(k >> 4) * 2], FX_SinCosTable_[(k >> 4) * 2 + 1]);
    MTX_RotAxis33((MtxFx43 *) m6, &f, FX_SinCosTable_[(l >> 4) * 2], FX_SinCosTable_[(l >> 4) * 2 + 1]);
    MTX_Concat33(m5, m2, m5);
    MTX_Concat33(m6, m3, m6);
    MTX_Concat33(m6, m5, m7);
    MTX_MultVec33(&n, m7, &n);
    VEC_Add(&camera->mPos, &n, &camera->mLookAt);
    camera->mLookAt.y = camera->mLookAt.y - kart->mHopHeight;
    camera->mPos.y = camera->mPos.y - kart->mHopHeight;
    if (gRaceMultiConfig->mMode != MODE_MISSION_RUN && gRaceMultiConfig->mMode != MODE_BATTLE) {
        if (col_collide(&camera->mPos, (u32 *) &camera->mPrevPos, 0, cam_sColSphereSize >> 1, 2, -2, &pushOut, NULL,
                          NULL, NULL, NULL, NULL, NULL, NULL) != 0) {
            kart = driver_getById(camera->mFollowedKartIndex);
            v = &kart->field120;
            k = VEC_DotProduct(v, &pushOut);
            pushOut.x = ((s64) kart->field120.x * k) >> 12;
            pushOut.y = ((s64) v->y * k) >> 12;
            pushOut.z = ((s64) v->z * k) >> 12;
            VEC_Add(&pushOut, &camera->mPos, &camera->mPos);
        }
    }
    cam_updateLookAtEx(camera);
}

void cam_updateStaffRollCamera(Camera *camera) {
    Kart *kart = driver_getById(camera->mFollowedKartIndex);
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    Vec3 newPos;
    Vec3 newLookAt;
    Vec3 offset;
    Vec3 lightDirection;
    s32 m[9];

    camera->fieldB4 = camera->mLookAt;
    newLookAt = kart->mPos;
    VEC_MultAdd(courseMapCamera->field0.z, &kart->field120, &kart->mPos, &newPos);
    newPos.y = 0x1f4000;
    newLookAt.y = 0x1f4000;
    offset = kart->field138;
    offset.y = 0;
    if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >= 0x10) {
        vec_normalize(&offset, &offset);
    }
    func_02074b00_inline(&offset, &offset, courseMapCamera->field0.x);
    VEC_Add(&newPos, &offset, &newPos);
    VEC_Add(&newLookAt, &offset, &newLookAt);
    if (race_getFrameCounter() < courseMapCamera->mFrameCount) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
    } else if (camera->field144 < 0x1000) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
        camera->field144 = camera->field144 + 0x52;
        VEC_Subtract(&camera->mPrevPos, &camera->mPos, &camera->fieldA8);
        VEC_Subtract(&camera->fieldB4, &camera->mLookAt, &camera->fieldB4);
        VEC_MultAdd(camera->field144, &camera->fieldA8, &newPos, &camera->mPos);
        VEC_MultAdd(camera->field144, &camera->fieldB4, &newLookAt, &camera->mLookAt);
    }
    cam_updateLookAtEx(camera);
    VEC_Subtract(&newPos, &newLookAt, &lightDirection);
    if ((s64) lightDirection.x * lightDirection.x + (s64) lightDirection.y * lightDirection.y +
            (s64) lightDirection.z * lightDirection.z >=
        0x10) {
        vec_normalize(&lightDirection, &lightDirection);
    }
    MTX_RotAxis33((MtxFx43 *) m, &cam_sVecUp, FX_SinCosTable_[(data_021656a0 >> 4) * 2],
                  FX_SinCosTable_[(data_021656a0 >> 4) * 2 + 1]);
    MTX_MultVec33(&lightDirection, m, &lightDirection);
    lightDirection.x = ((s64) lightDirection.x * 0xfae) >> 12;
    lightDirection.y = ((s64) lightDirection.y * 0xfae) >> 12;
    lightDirection.z = ((s64) lightDirection.z * 0xfae) >> 12;
    race_setLight0Direction(&lightDirection);
    courseMapCamera = camera->mCourseMapCamera;
    if (courseMapCamera->mFovBlendPerFrame != 0) {
        s32 secondOffset;
        enum { K0 } t = camera->mFovBlend;
        s32 firstStart = courseMapCamera->mHalfFovPairFirst;
        s32 secondStart = courseMapCamera->mHalfFovPairSecond;
        s32 secondEnd = courseMapCamera->mHalfFovPairSecondEnd;
        s32 firstEnd = courseMapCamera->mHalfFovPairFirstEnd;
        s32 firstDelta = firstEnd - firstStart;
        s32 secondDelta = secondEnd - secondStart;

        secondOffset = ((s64) secondDelta * t) >> 12;
        camera->mHalfFovPairFirst = firstStart + (s32) (((s64) firstDelta * t) >> 12);
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

void cam_updateCameRoutePos(Camera *camera, s32 paramPerFrame) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    u16 pointCount = gMapData->mEntryGroups[courseMapCamera->mEntryGroupIndex].mEntryCount;
    CourseMapGroupEntry *firstEntry;
    CourseMapGroupEntry *secondEntry;
    Vec3 startPos;
    Vec3 direction;
    Vec3 offset;
    s32 m;

    if (pointCount >= 4) {
        camr_updateRoute(&camera->mPos, &camera->mPosCurve, courseMapCamera, paramPerFrame);
        return;
    }
    if (pointCount < 2) {
        return;
    }
    firstEntry = mdat_getPathPoint(courseMapCamera->mEntryGroupIndex, 0);
    secondEntry = mdat_getPathPoint(courseMapCamera->mEntryGroupIndex, 1);
    startPos = firstEntry->mPos;
    VEC_Subtract(&secondEntry->mPos, &firstEntry->mPos, &direction);
    if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z < 0x10) {
        m = 0;
    } else {
        m = vec_normalize(&direction, &direction);
    }
    camera->mPosCurve.mParam += paramPerFrame;
    if (camera->mPosCurve.mParam >= 0x1000) {
        camera->mPosCurve.mParam = 0x1000;
    }
    m = ((s64) camera->mPosCurve.mParam * m) >> 12;
    offset.x = ((s64) direction.x * m) >> 12;
    offset.y = ((s64) direction.y * m) >> 12;
    offset.z = ((s64) direction.z * m) >> 12;
    VEC_Add(&startPos, &offset, &camera->mPos);
}

void cam_updateCameByRoute(Camera *camera) {
    cam_updateCameRoutePos(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    cam_updateCameTarget(camera);
    cam_updateLookAt(camera);
}

void cam_updateCameTarget(Camera *camera) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    s32 startX, startY, startZ;
    s32 deltaX, deltaY, deltaZ;
    s32 scaledDeltaX, scaledDeltaY, scaledDeltaZ;
    s64 blend;

    if (courseMapCamera->mLookAtBlendPerFrame != 0) {
        blend = camera->mLookAtBlend;
        startX = courseMapCamera->field18.x;
        deltaX = courseMapCamera->field24.x - startX;
        scaledDeltaX = (deltaX * blend) >> 12;
        startY = courseMapCamera->field18.y;
        deltaY = courseMapCamera->field24.y - startY;
        scaledDeltaY = (deltaY * blend) >> 12;
        startZ = courseMapCamera->field18.z;
        deltaZ = courseMapCamera->field24.z - startZ;
        scaledDeltaZ = (deltaZ * blend) >> 12;
        camera->mLookAt.x = startX + scaledDeltaX;
        camera->mLookAt.y = startY + scaledDeltaY;
        camera->mLookAt.z = startZ + scaledDeltaZ;
        camera->mLookAtBlend += courseMapCamera->mLookAtBlendPerFrame;
        if (camera->mLookAtBlend > 0x1000) {
            camera->mLookAtBlend = 0x1000;
        }
    } else {
        camera->mLookAt.x = courseMapCamera->field18.x;
        camera->mLookAt.y = courseMapCamera->field18.y;
        camera->mLookAt.z = courseMapCamera->field18.z;
    }
}

Camera *cam_getPlayerCamera(void) {
    return cam_sPlayerCamera;
}

Camera *cam_getReplayCamera(void) {
    return cam_sReplayCamera;
}

Camera *cam_getIntroCamera(void) {
    return cam_sIntroCamera;
}

// Chase camera (cam_sPlayerCamera) only.
void cam_setPlayerCameraTargetFov(u32 halfFovAngleGoal) {
    cam_sPlayerCamera->mHalfFovAngleGoal = halfFovAngleGoal;
}

// Chase camera (cam_sPlayerCamera) only.
void cam_resetPlayerCameraTargetFov(void) {
    u32 value0;
    u32 value1;
    value1 = (u32) &cam_sDefaultFov;
    value1 = *(const u16 *) ((value1) + (0));
    cam_sPlayerCamera->mHalfFovAngleGoal = value1;
}

// Chase camera only: resets the field-of-view angle goal to its default and the angle to default + 5.
void cam_resetPlayerCameraFov(void) {
    s32 defaultHalfFovAngle;

    defaultHalfFovAngle = cam_sDefaultFov;
    cam_sPlayerCamera->mHalfFovAngleGoal = defaultHalfFovAngle;
    cam_sPlayerCamera->mHalfFovAngle = defaultHalfFovAngle + 5;
}

// Chase camera (cam_sPlayerCamera) only.
void cam_20747F4(s32 hold) {
    cam_sPlayerCamera->mHeightHold = hold;
    if (hold == 0) {
        return;
    }
    cam_sPlayerCamera->mHeldHeight = cam_sPlayerCamera->mPos.y;
    cam_sPlayerCamera->mHeldHeightEasing = FALSE;
}

void cam_20745D4(Vec3 *lookAt, Vec3 *lookAtOffset, s32 *lookAtLowering, Kart *kart, s32 scaledHopHeight,
                             s32 lookAtHeight) {
    Vec3 lookAtGoal;
    Vec3 v10;
    Vec3 offsetGoal;
    Vec3 offsetStep;
    s32 t;

    lookAtGoal = kart->mPos;
    v10 = kart->mPos;
    v10.y = v10.y - scaledHopHeight;
    VEC_MultAdd(lookAtHeight, &kart->field12C, &v10, &v10);
    lookAtGoal.y = lookAtGoal.y + (lookAtHeight - scaledHopHeight);
    if (!(kart->field48 & 0x40000000)) {
        offsetGoal = cam_sVecNull;
    } else {
        VEC_Subtract(&v10, &lookAtGoal, &offsetGoal);
        VEC_MultAdd(0xa000, &kart->field12C, &offsetGoal, &offsetGoal);
    }
    VEC_Subtract(&offsetGoal, lookAtOffset, &offsetStep);
    offsetStep.x = ((s64) offsetStep.x * 0x266) >> 12;
    offsetStep.y = ((s64) offsetStep.y * 0x266) >> 12;
    offsetStep.z = ((s64) offsetStep.z * 0x266) >> 12;
    VEC_Add(lookAtOffset, &offsetStep, lookAtOffset);
    VEC_Add(&lookAtGoal, lookAtOffset, &lookAtGoal);
    lookAt->x = lookAtGoal.x;
    lookAt->z = lookAtGoal.z;
    if (kart->field48 & 0x10000) {
        *lookAtLowering = *lookAtLowering + 0x1000;
        if (*lookAtLowering > 0xa000) {
            *lookAtLowering = 0xa000;
        }
    } else {
        t = *lookAtLowering;
        *lookAtLowering = t + (s32) (((s64) -t * 0x29 + 0x800) >> 12);
    }
    lookAtGoal.y = lookAtGoal.y - *lookAtLowering;
    t = lookAt->y;
    lookAt->y = t + (s32) (((s64) (lookAtGoal.y - t) * 0xccd + 0x800) >> 12);
}

void cam_20741A0(Vec3 *pos, Vec3 *posOffset, Camera *camera, Kart *kart, Vec3 *kartPos, const Vec3 *forward,
                          s32 collisionShorten) {
    Vec3 kartMovement;
    Vec3 kartUp;
    Vec3 forwardCopy;
    Vec3 v28;
    Vec3 v34;
    Vec3 posGoal;
    Vec3 v2;
    Vec3 v58;
    Vec3 v64;
    Vec3 v70;
    Vec3 v3;
    Vec3 offsetGoal;
    Vec3 offsetStep;
    s32 followDistance;
    s32 i;
    s32 j;
    s32 k;

    forwardCopy = *forward;
    followDistance = camera->mFollowDistance - collisionShorten;
    driver_getShadowYDirection(kart, &kartUp);
    if (followDistance < 500) {
        followDistance = 500;
    }
    VEC_Subtract(&kart->mPos, &kart->mPrevPos, &kartMovement);
    if (kart->field48 & 0x1000) {
        if (kart->field4C & 0x4000000) {
            return;
        }
        camera->mKartMoveScale = ((s64) camera->mKartMoveScale * 0xe66) >> 12;
        VEC_MultAdd(camera->mKartMoveScale, &kartMovement, pos, pos);
        return;
    }
    kartMovement.y = 0;
    VEC_Add(pos, &kartMovement, pos);
    i = -followDistance;
    v2.x = ((s64) forwardCopy.x * i) >> 12;
    v2.y = ((s64) forwardCopy.y * i) >> 12;
    v2.z = ((s64) forwardCopy.z * i) >> 12;
    VEC_Add(&v2, &camera->mPosGoalKartOffset, &v2);
    VEC_Add(&v2, &camera->mPosGoalCollisionOffset, &v2);
    VEC_MultAdd(cam_sCameraElevation, &kartUp, &v2, &v3);
    VEC_Add(kartPos, &v3, &v70);
    v2.y = cam_sCameraElevation;
    VEC_Add(kartPos, &v2, &v64);
    posGoal = v64;
    posGoal.y = posGoal.y + camera->mPosGoalYOffset;
    if (!(kart->field48 & 0x40000000)) {
        offsetGoal = cam_sVecNull;
    } else {
        VEC_Subtract(&v70, &posGoal, &offsetGoal);
        VEC_MultAdd(-0x1e000, &kartUp, &offsetGoal, &offsetGoal);
    }
    VEC_Subtract(&offsetGoal, posOffset, &offsetStep);
    offsetStep.x = ((s64) offsetStep.x * 0x19a) >> 12;
    offsetStep.y = ((s64) offsetStep.y * 0x19a) >> 12;
    offsetStep.z = ((s64) offsetStep.z * 0x19a) >> 12;
    VEC_Add(posOffset, &offsetStep, posOffset);
    VEC_Add(&posGoal, posOffset, &posGoal);
    VEC_Subtract(&posGoal, pos, &v58);
    j = v58.y;
    k = 0;
    v58.y = 0;
    if ((s64) v58.x * v58.x + (s64) v58.y * v58.y + (s64) v58.z * v58.z >= 16) {
        k = vec_normalize(&v58, &v58);
    }
    VEC_MultAdd(((s64) k * 0x11f) >> 12, &v58, pos, pos);
    pos->y = pos->y + ((s32) (((s64) j * 0x11f) >> 9) + collisionShorten * 2);
    if (camera->mHeightHold != 0) {
        if (camera->mHeldHeightEasing != FALSE) {
            s32 l;
            l = pos->y - camera->mHeldHeight;
            camera->mHeldHeight = camera->mHeldHeight + (s32) (((s64) l * 0x29 + 0x800) >> 12);
        }
        pos->y = camera->mHeldHeight;
    }
    VEC_Subtract(pos, kartPos, &v28);
    v34 = v28;
    k = 0;
    if ((s64) v34.x * v34.x + (s64) v34.y * v34.y + (s64) v34.z * v34.z >= 16) {
        k = vec_normalize(&v34, &v34);
    }
    if (k == 0) {
        return;
    }
    VEC_MultAdd(((s64) camera->mFollowDistance * camera->mFollowDistanceScale) >> 12, &v34, kartPos, pos);
}

// Puts the chase camera at a minus mFollowDistance along axis 2 of the matrix b (the kart's).
void cam_setPlayerCameraPosRot(const Vec3 *kartPos, void *quaternion) {
    Camera *chaseCamera;
    Vec3 axes[3];
    Vec3 offset;
    s32 behindDistance;

    chaseCamera = cam_sPlayerCamera;
    qtrn_toMtx33(axes, quaternion);
    behindDistance = ((s64) -cam_sCameraDistance * chaseCamera->mFollowDirectionSign + 0x800) >> 12;
    offset.x = ((s64) axes[2].x * behindDistance) >> 12;
    offset.y = ((s64) axes[2].y * behindDistance) >> 12;
    offset.z = ((s64) axes[2].z * behindDistance) >> 12;
    VEC_Add(kartPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + cam_sCameraElevation;
    chaseCamera->mBaseUp = cam_sVecUp;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = 0x1000;
    cam_sPlayerCamera->mHeightHold = 0;
    mobj_updateCameraVectors((Unk020d4f94 *) &chaseCamera->mViewMatrix);
    mobj_20D50C4();
}

// Chase camera (cam_sPlayerCamera) only.
void cam_tryShakePlayerCamera(s32 baseAmplitude, u32 distance, s32 scale) {
    Camera *chaseCamera;
    s32 distanceFactor;
    s32 amplitude;

    distanceFactor = 0x1000;
    chaseCamera = cam_sPlayerCamera;
    if (distance > 1000000) {
        return;
    }
    if (distance > 0x57e40) {
        distanceFactor = 0x4cd;
    } else if (distance > 0x15f90) {
        distanceFactor = 0x99a;
    }
    amplitude = ((s64) baseAmplitude * (s32) (((s64) scale * distanceFactor) >> 12)) >> 12;
    if (chaseCamera->mWobbling != FALSE && chaseCamera->mWobbleAmplitude > amplitude) {
        return;
    }
    chaseCamera->mWobbleAmplitude = amplitude;
    chaseCamera->mWobbling = TRUE;
    chaseCamera->field144 = 0;
    chaseCamera->mWobblePerFrame = 0x800;
    chaseCamera->mWobbleDirection = 1;
    chaseCamera->mWobbleDecay = 0xe66;
    chaseCamera->mWobbleOffset = 0;
}

void cam_tryImpactShakePlayerCamera(u32 distance, s32 scale) {
    cam_tryShakePlayerCamera(0x2800, distance, scale);
}

void cam_tryCannonShakePlayerCamera(void) {
    cam_tryShakePlayerCamera(cam_sCannonShakeAmount, 0, 0x1000);
}

void cam_updateShake(Camera *camera) {
    s32 t;
    BOOL u;

    if (camera->mWobbling == FALSE) {
        return;
    }
    camera->field144 = camera->field144 + camera->mWobblePerFrame * camera->mWobbleDirection;
    t = camera->field144;
    if (t > 0x1000) {
        camera->mWobbleDirection *= -1;
        camera->field144 = 0x2000 - camera->field144;
    } else if (t < -0x1000) {
        camera->mWobbleDirection *= -1;
        camera->field144 = -0x2000 - camera->field144;
    }
    camera->mWobbleAmplitude = ((s64) camera->mWobbleAmplitude * camera->mWobbleDecay) >> 12;
    camera->mWobbleAmplitude = camera->mWobbleAmplitude - 0x14;
    camera->mWobbleOffset = ((s64) camera->field144 * camera->mWobbleAmplitude) >> 12;
    if (camera->mWobbleAmplitude <= 0) {
        u = FALSE;
        camera->mWobbleOffset = u;
        camera->mWobbling = u;
    }
}
