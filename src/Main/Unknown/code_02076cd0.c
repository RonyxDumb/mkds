#include "Main/Unknown/code_02076cd0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_02073904.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020d4a20.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02133048.h"
#include "code_02147cd8.h"
#include "code_0214a748.h"
#include "code_021471bc.h"
#include "registers.h"

#pragma thumb on

void SPM_2077B3C(void) {
    if (gCharKartSelectState->mCharacterRequested != 0 || gCharKartSelectState->mKartRequested != 0) {
        gCharKartSelectState->mFiles[gCharKartSelectState->mLoadSlotIndex].mLoadRequested = TRUE;
        gCharKartSelectState->mLoadSlot->mCharacterIndex = gCharKartSelectState->mView.mCharacterIndex;
        gCharKartSelectState->mLoadSlot->mKartIndex = gCharKartSelectState->mView.mKartIndex;
        gCharKartSelectState->mLoadSlot->mKartOffsetData =
            gCharKartSelectState->mKartOffsetTable + gCharKartSelectState->mView.mKartIndex;
        bgwkr_enqueueTask(SPM_2077D68);
        gBgWkrState->mRunRequested = 1;
    }
}

void ClearKartModelMenuRequests(void) {
    gCharKartSelectState->mKartRequested = 0;
    gCharKartSelectState->mCharacterRequested = gCharKartSelectState->mKartRequested;
}

BOOL func_02077a70(s32 *characterIndex, u32 kartIndex) {
    u32 n;
    enum { K0 } i;

    *characterIndex = _s32_div_f((u16) kartIndex, 3);
    if (*characterIndex >= 8) {
        switch (*characterIndex) {
            case 8:
                n = 0x14;
                break;
            case 9:
                n = 0x15;
                break;
            case 10:
                n = 0x16;
                break;
            case 11:
                n = 0x17;
                break;
        }
        if (savd_isUnlockBitSet(n) == 0) {
            *characterIndex = -1;
            for (i = 0; i < 8; i++) {
                if (IsKartAppearWithinLimit(gCharKartSelectState->mKartAppear, i, kartIndex) != 0) {
                    *characterIndex = i;
                    break;
                }
            }
            if (*characterIndex != -1) {
                return 1;
            }
            return 0;
        }
    }
    return IsKartAppearWithinLimit(gCharKartSelectState->mKartAppear, *characterIndex, kartIndex);
}

u16 func_02077a5c(void) {
    return gCharKartSelectState->mKartListPos + 1;
}

u16 GetKartListCount(void) {
    return gCharKartSelectState->mKartListCount;
}

void LoadEmblemSBNclr(void *a) {
    void *nclrFile;

    LoadFileInKartModelMenuFolder(a, aEmblem_s_b_ncl, &nclrFile);
    g2du_unpackPaletteData(&gEmblemSBNclr, nclrFile);
}

void cam_setupRaceParams(void) {
    u32 i;

    *(u32 *) 0x4000580 = 0xbfff0000;
    gCameraEntryChanged = 1;
    i = gEntryCameraUpdateRan = 0;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        i = gRaceMultiConfig->mUnk_036;
        i = (u16) i;
    } else {
        i = (u16) i;
        i = (u16) i;
    }
    cam_sCameraDistance = cam_sCamParams[i][0];
    cam_sCameraElevation = data_02154fa4[i][0];
    cam_sMaxTargetElevation = data_02154fa8[i][0];
    if (gRaceMultiConfig->mCourseId == COURSE_ID_AIRSHIP) {
        cam_sCannonShakeAmount = 0xa000;
    } else {
        cam_sCannonShakeAmount = 0x5000;
    }
}

void cam_setupPlayerCamera(void) {
    Kart *kart = driver_getById(gRaceMultiConfig->mEntryIndex);

    cam_sPlayerCamera = heap_alloc(proc_getHeap(proc_getCurrent()), 0x270);
    cam_resetPlayerCamera();
    driver_getShadowZDirection(kart, &cam_sPlayerCamera->mSavedKartForward);
    cam_updateFrustum(cam_sPlayerCamera);
}

void cam_20777AC(u32 followedKartIndex) {
    void *heap = proc_getHeap(proc_getCurrent());
    u16 i;
    u16 kind7EntryCount;
    CourseMapCamera *courseMapCamera;
    u16 m;
    u16 listIndex;
    s32 nextIndex;

    cam_sReplayCamera = heap_alloc(heap, 0x270);
    cam_init(cam_sReplayCamera);
    cam_sReplayCamera->mFollowedKartIndex = followedKartIndex;
    cam_sReplayCamera->mCourseMapCamera = NULL;
    cam_sReplayCamera->mFrustumShift = 0;
    cam_sReplayCamera->mKind = 1;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        cam_sReplayCamera->mCourseMapCamera = gMapData->mCameras;
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        cam_sReplayCamera->mCourseMapCamera = gMapData->mFirstKind7EntryInMode2;
        if (cam_sReplayCamera->mCourseMapCamera != NULL) {
            kind7EntryCount = 0;
            nextIndex = -1;
            for (i = 0; i < gMapData->mCameraCount; i++) {
                if (gMapData->mCameras[i].mKind == 7) {
                    kind7EntryCount++;
                }
            }
            cam_sMgIntroCamCount = kind7EntryCount;
            cam_sReplayCamera->mUnk_21c = heap_alloc(heap, kind7EntryCount * 0x88);
            courseMapCamera = cam_sReplayCamera->mCourseMapCamera;
            m = 0;
            listIndex = 0;
            for (; m < gMapData->mCameraCount; m++) {
                if (nextIndex != -1) {
                    courseMapCamera = &gMapData->mCameras[(u16) nextIndex];
                    if (courseMapCamera == cam_sReplayCamera->mCourseMapCamera) {
                        break;
                    }
                }
                if (courseMapCamera->mKind == 7) {
                    cam_2077750(&cam_sReplayCamera->mUnk_21c[listIndex], courseMapCamera);
                    listIndex++;
                    nextIndex = courseMapCamera->mNextIndex;
                }
            }
            cam_sReplayCamera->mUnk_220 = cam_sReplayCamera->mUnk_21c;
            cam_sReplayCamera->mUnk_224 = 0;
            cam_sReplayCamera->mKind = 3;
            gCameraEntryChanged = 1;
        }
    }
}

void cam_2077750(Unk02077750 *a, CourseMapCamera *courseMapCamera) {
    CourseMapEntryGroup *entryGroup = &gMapData->mEntryGroups[courseMapCamera->mEntryGroupIndex];

    a->mUnk_7c = courseMapCamera->mPosCurvePerFrame;
    a->mUnk_7e = 2;
    a->mUnk_00 = courseMapCamera;
    a->mUnk_80 = 0;
    a->mUnk_84 = 0;
    if (entryGroup->mEntryCount >= 4) {
        camr_initRouteStat(&a->mUnk_04, courseMapCamera);
        camr_initRouteStatReversed(&a->mUnk_40, courseMapCamera);
    }
}

void cam_setupIntroCamDouble(void) {
    void *heap = proc_getHeap(proc_getCurrent());

    cam_sIntroCameraTop = heap_alloc(heap, 0x270);
    cam_sIntroCameraBottom = heap_alloc(heap, 0x270);
    cam_init(cam_sIntroCameraTop);
    cam_init(cam_sIntroCameraBottom);
    cam_sIntroCameraTop->mCourseMapCamera = gMapData->mFirstChainStartEntry;
    cam_sIntroCameraBottom->mCourseMapCamera = gMapData->mSecondChainStartEntry;
    cam_sIntroCameraTop->mKind = 2;
    cam_sIntroCameraBottom->mKind = 2;
    if (cam_sIntroCameraTop->mCourseMapCamera == NULL) {
        gRaceStatus->mCameraChainEnded = 1;
        return;
    }
    if ((s16) cam_sIntroCameraTop->mCourseMapCamera->mEntryGroupIndex != -1) {
        camr_initRouteStat(&cam_sIntroCameraTop->mPosCurve, cam_sIntroCameraTop->mCourseMapCamera);
    }
    if ((s16) cam_sIntroCameraBottom->mCourseMapCamera->mEntryGroupIndex != -1) {
        camr_initRouteStat(&cam_sIntroCameraBottom->mPosCurve, cam_sIntroCameraBottom->mCourseMapCamera);
    }
}

void cam_setupIntroCamSingle(void) {
    cam_sIntroCameraTop = heap_alloc(proc_getHeap(proc_getCurrent()), 0x270);
    cam_sIntroCameraBottom = NULL;
    cam_init(cam_sIntroCameraTop);
    cam_sIntroCameraTop->mCourseMapCamera = gMapData->mFirstChainStartEntry;
    cam_sIntroCameraTop->mKind = 2;
    cam_sIntroCameraTop->mFrustumShift = 0;
    if (cam_sIntroCameraTop->mCourseMapCamera == NULL) {
        gRaceStatus->mCameraChainEnded = 1;
        return;
    }
    if ((s16) cam_sIntroCameraTop->mCourseMapCamera->mEntryGroupIndex != -1) {
        camr_initRouteStat(&cam_sIntroCameraTop->mPosCurve, cam_sIntroCameraTop->mCourseMapCamera);
    }
}

#pragma thumb off

// Writes the default values of 76 members; re-run by cam_resetPlayerCamera when a kart is placed.
void cam_init(Camera *camera) {
    Vec3 worldUp;
    Vec3 initialLookAt;
    Vec3 zero;

    camera->mPos.x = 0x1e3000;
    camera->mPos.y = 0x4bd000;
    camera->mPos.z = 0xc6b000;
    initialLookAt = *(volatile Vec3 *) &cam_sVecNull;
    camera->mLookAt = initialLookAt;
    worldUp = *(volatile Vec3 *) &cam_sVecUp;
    camera->mUp = cam_sVecUp;
    camera->mSide = cam_sVecRight;
    MTX_Identity43_(&camera->mViewMatrix);
    camera->mForward = cam_sVecForward;
    camera->mPosGoalYOffset = 0;
    camera->mHalfFovAngleGoal = cam_sDefaultFov;
    camera->mHalfFovAngle = cam_sDefaultFov + 5;
    camera->mHalfFovPairFirst = FX_SinCosTable_[((u16) camera->mHalfFovAngle >> 4) * 2];
    camera->mHalfFovPairSecond = FX_SinCosTable_[((u16) camera->mHalfFovAngle >> 4) * 2 + 1];
    camera->mAspectRatio = 0x1555;
    camera->mNear = 0x400;
    camera->mUnk_08c = 0x640000;
    camera->mFar = gMapData->mSettings->mCameraFar;
    if (camera->mFar < 0x1000) {
        camera->mFar = 0x640000;
    }
    camera->mFrustumTop = 0;
    camera->mFrustumBottom = 0;
    camera->mFrustumLeft = 0;
    camera->mFrustumRight = 0;
    zero = cam_sVecNull;
    camera->mViewPos = zero;
    camera->mViewLookAt = zero;
    camera->mBaseUp = worldUp;
    camera->mHeldHeight = 0;
    camera->mLookAtHeight = cam_sMaxTargetElevation;
    camera->mUnk_0d8 = 1;
    camera->mFollowDistance = cam_sCameraDistance;
    camera->mUnk_0e0 = camera->mFollowDistance;
    camera->mLookAtLowering = 0;
    camera->mFollowDistanceScale = 0x1000;
    camera->mUnk_0ec = 0;
    camera->mFollowDirectionSign = 0x1000;
    camera->mShakeLookAtOffsetGoal = zero;
    camera->mShakePosOffsetGoal = zero;
    camera->mShakeLookAtOffset = zero;
    camera->mShakePosOffset = zero;
    camera->mShakeKind = 0;
    camera->mShakeLookAtCounterOffset = zero;
    camera->mFovBlend = 0;
    camera->mLookAtBlend = 0;
    camera->mHeightHold = 0;
    camera->mPosGoalKartOffsetScale = 0;
    camera->mCollisionOffsetLengthGoal = 0;
    camera->mCollisionOffsetLength = 0;
    camera->mViewPosYOffset = 0;
    camera->mWobbling = FALSE;
    camera->mUnk_144 = 0;
    camera->mWobblePerFrame = 0;
    camera->mWobbleDirection = 1;
    camera->mWobbleDecay = 0;
    camera->mWobbleOffset = 0;
    camera->mWobbleAmplitude = 0;
    camera->mFollowedKartIndex = 0;
    camera->mLastCourseMapCameraIndex = -1;
    camera->mCourseMapCameraFrames = 0;
    camera->mKind6EntryRunning = FALSE;
    camera->mKind6EntryFrames = 0;
    camera->mEntryUpdateHold = 0;
    camera->mEntryUpdateDisabled = FALSE;
    camera->mKind8EntryRunning = FALSE;
    camera->mFrustumShift = 0;
    camera->mKind = 0;
    camera->mPosGoalKartOffset = zero;
    camera->mPosGoalCollisionOffset = zero;
    camera->mUnk_254 = 3;
    camera->mUnk_258 = FALSE;
    camera->mUnk_25c = FALSE;
    camera->mSavedKartForward = zero;
    camera->mUnk_0a8 = zero;
    camera->mUnk_0b4 = zero;
    camera->mSideDistanceSign = gRaceMultiConfig->mMirrorMode ? -1 : 1;
    camera->mUnk_21c = NULL;
    camera->mUnk_220 = NULL;
    camera->mUnk_20c = 0;
    camera->mUnk_20e = 0;
    camera->mUnk_224 = 0;
    camera->mKartMoveScale = 0x1000;
}

void cam_updateFrustum(Camera *camera) {
    s32 top;
    s32 bottom;
    s32 staffRollShift;
    s32 d;

    if (camera == cam_sPlayerCamera) {
        if (camera->mHalfFovAngle == camera->mHalfFovAngleGoal && gEntryCameraUpdateRan == 0) {
            return;
        }
        if (math_abs(camera->mHalfFovAngle - camera->mHalfFovAngleGoal) < 10) {
            camera->mHalfFovAngle = camera->mHalfFovAngleGoal;
        }
    }
    camera->mFrustumTop = ((s64) camera->mNear * FX_Div(camera->mHalfFovPairFirst, camera->mHalfFovPairSecond)) >> 12;
    camera->mFrustumBottom = -camera->mFrustumTop;
    camera->mFrustumLeft = ((s64) -camera->mFrustumTop * camera->mAspectRatio) >> 12;
    top = camera->mFrustumTop;
    bottom = camera->mFrustumBottom;
    switch (camera->mFrustumShift) {
        case 1:
            top <<= 1;
            bottom = -top;
            camera->mFrustumTop = ((s64) top * (data_021656b8 + 0x1000)) >> 12;
            camera->mFrustumBottom = ((s64) top * data_021656b8) >> 12;
            break;
        case 2:
            bottom <<= 1;
            top = -bottom;
            camera->mFrustumBottom = ((s64) bottom * (data_021656b8 + 0x1000)) >> 12;
            camera->mFrustumTop = ((s64) bottom * data_021656b8) >> 12;
            break;
    }
    if (gRaceMultiConfig->mMirrorMode != 0) {
        camera->mFrustumLeft = -camera->mFrustumLeft;
    }
    camera->mFrustumRight = -camera->mFrustumLeft;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL && camera->mCourseMapCamera != NULL) {
        staffRollShift = ((s64) camera->mFrustumTop * camera->mCourseMapCamera->mUnk_00.y + 0x800) >> 12;
        camera->mFrustumBottom += staffRollShift;
        camera->mFrustumTop += staffRollShift;
    }
    mobj_setFrustum(top, bottom, camera->mFrustumLeft, camera->mFrustumRight, camera->mNear,
                                     camera->mFar);
    reg_G3_MTX_MODE = 0;
    G3i_FrustumW_(camera->mFrustumTop, camera->mFrustumBottom, camera->mFrustumLeft, camera->mFrustumRight,
                  camera->mNear, camera->mFar, 0x1000, 1, (Unk0214ad4c *) cam_sProjectionMtx);
}

void cam_updateLookAt(Camera *camera) {
    Vec3 side;
    Vec3 forward;
    Vec3 worldUp;
    Vec3 eyePos;
    Vec3 lookAtPos;

    worldUp = cam_sVecUp;
    VEC_Subtract(&camera->mLookAt, &camera->mPos, &forward);
    if ((s64) forward.x * forward.x + (s64) forward.y * forward.y + (s64) forward.z * forward.z >= 0x10) {
        vec_normalize(&forward, &forward);
    }
    camera->mForward = forward;
    vec_crossProduct(&worldUp, &forward, &side);
    vec_crossProduct(&forward, &side, &camera->mUp);
    if (camera->mUp.x == 0 && camera->mUp.y == 0 && camera->mUp.z == 0) {
        camera->mUp.x = 0x1000;
        camera->mUp.y = 0x1000;
        camera->mUp.z = 0x1000;
        if ((s64) camera->mUp.x * camera->mUp.x + (s64) camera->mUp.y * camera->mUp.y +
                (s64) camera->mUp.z * camera->mUp.z >=
            0x10) {
            vec_normalize(&camera->mUp, &camera->mUp);
        }
    }
    reg_G3_MTX_MODE = 2;
    eyePos.x = camera->mPos.x >> 4;
    eyePos.y = (camera->mPos.y + camera->mViewPosYOffset) >> 4;
    eyePos.z = camera->mPos.z >> 4;
    lookAtPos.x = camera->mLookAt.x >> 4;
    lookAtPos.y = camera->mLookAt.y >> 4;
    lookAtPos.z = camera->mLookAt.z >> 4;
    G3i_LookAt_(&eyePos, &camera->mUp, &lookAtPos, 1, &camera->mViewMatrix);
}

// Per frame for each camera in use: axes, shake, view position and look-at in 1/16 scale, loads the view matrix.
void cam_updateLookAtEx(Camera *camera) {
    Vec3 forward;
    Vec3 baseUp;
    Vec3 eyePos;
    Vec3 lookAtPos;

    baseUp = camera->mBaseUp;
    eyePos = camera->mPos;
    lookAtPos = camera->mLookAt;
    lookAtPos.y += camera->mWobbleOffset;
    VEC_Subtract(&lookAtPos, &eyePos, &forward);
    if ((s64) forward.x * forward.x + (s64) forward.y * forward.y + (s64) forward.z * forward.z >= 0x10) {
        vec_normalize(&forward, &forward);
    }
    camera->mForward = forward;
    vec_crossProduct(&baseUp, &forward, &camera->mSide);
    vec_crossProduct(&forward, &camera->mSide, &camera->mUp);
    if (camera->mUp.x == 0 && camera->mUp.y == 0 && camera->mUp.z == 0) {
        camera->mUp.x = 0x1000;
        camera->mUp.y = 0x1000;
        camera->mUp.z = 0x1000;
        if ((s64) camera->mUp.x * camera->mUp.x + (s64) camera->mUp.y * camera->mUp.y +
                (s64) camera->mUp.z * camera->mUp.z >=
            0x10) {
            vec_normalize(&camera->mUp, &camera->mUp);
        }
    }
    if (camera->mShakeKind != 0) {
        cam_2073904(camera);
        VEC_Add(&eyePos, &camera->mShakePosOffset, &eyePos);
        VEC_Add(&lookAtPos, &camera->mShakeLookAtOffset, &lookAtPos);
        VEC_Add(&camera->mShakeLookAtCounterOffset, &lookAtPos, &lookAtPos);
    }
    camera->mViewPos.x = eyePos.x >> 4;
    camera->mViewPos.y = eyePos.y >> 4;
    camera->mViewPos.z = eyePos.z >> 4;
    camera->mViewPos.y += camera->mViewPosYOffset >> 4;
    camera->mViewLookAt.x = lookAtPos.x >> 4;
    camera->mViewLookAt.y = lookAtPos.y >> 4;
    camera->mViewLookAt.z = lookAtPos.z >> 4;
    reg_G3_MTX_MODE = 2;
    G3i_LookAt_(&camera->mViewPos, &camera->mUp, &camera->mViewLookAt, 1, &camera->mViewMatrix);
}
