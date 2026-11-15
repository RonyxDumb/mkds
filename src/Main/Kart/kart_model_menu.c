#include "Main/Kart/kart_model_menu.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Save/backup_reset.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Kart/kart_state0_return.h"
#include "Main/Kart/camera_shake.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_02154000.h"
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
#include "code_02133048.h"
#include "code_02147cd8.h"
#include "code_0214a748.h"
#include "fx_mtx43.h"
#include "registers.h"
#include "Main/Kart/camera.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

NNSG3dResMatData *gSpecialKartBodyMaterial;
Nclr *gEmblemSBNclr;
KartModels *gKartModels;
KartModelMenuData *gKartModelMenu;

const s32 gCameraDefaultRows[2][3] = {{0x3a000, 0x22000, 0x14000}, {0x62000, 0x37000, 0x22000}};
u16 gKartModelMenuTiltAngleOffset = 0xd12;
u16 gKartModelMenuLightLevel = 0x1f;
s32 gKartModelMenuLookAtYOffset = 0x10f4;
s32 gKartModelMenuScaleFactor = 0x18fb;
s32 gKartModelMenuMaxScale = 0x14cd;
u32 gKartModelMenuSpinStep = 0x19a;
Vec3 gKartModelMenuLookAtTarget = {0, -685, 0x4c};
Vec3 gKartModelMenuCameraPosition = {0, -2665, 0x5000};
Vec3 gKartModelMenuLightDirection = {-1051, -1565, -1873};
char gEmblemSBNclrName[16] = "emblem_s_b.NCLR";
char gCharMenuParamBinName[20] = "charmenuparam.bin";
char gKartMenuParamBinName[20] = "kartmenuparam.bin";
char gKartOffsetDataBinName[20] = "kartoffsetdata.bin";
char gKartSelectNsbmdName[28] = "kart/select/select.nsbmd";
char gKartSelectNsbtxName[28] = "kart/select/select.nsbtx";

void QueueKartModelMenuLoad(void) {
    if (gKartModelMenu->mCharacterRequested != 0 || gKartModelMenu->mKartRequested != 0) {
        gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested = TRUE;
        gKartModelMenu->mLoadSlot->mCharacterIndex = gKartModelMenu->mView.mCharacterIndex;
        gKartModelMenu->mLoadSlot->mKartIndex = gKartModelMenu->mView.mKartIndex;
        gKartModelMenu->mLoadSlot->mKartOffsetData =
            gKartModelMenu->mKartOffsetTable + gKartModelMenu->mView.mKartIndex;
        QueueThreadFunction(LoadKartAndCharacterFiles);
        gThreadFunctionQueue->mRunRequested = 1;
    }
}

void ClearKartModelMenuRequests(void) {
    gKartModelMenu->mKartRequested = 0;
    gKartModelMenu->mCharacterRequested = gKartModelMenu->mKartRequested;
}

BOOL FindKartModelMenuCharacter(s32 *characterIndex, u32 kartIndex) {
    u32 backupFlagIndex;
    enum { CHARACTER_FIRST } candidateCharacter;

    *characterIndex = _s32_div_f((u16) kartIndex, 3);
    if (*characterIndex >= 8) {
        switch (*characterIndex) {
            case 8:
                backupFlagIndex = 0x14;
                break;
            case 9:
                backupFlagIndex = 0x15;
                break;
            case 10:
                backupFlagIndex = 0x16;
                break;
            case 11:
                backupFlagIndex = 0x17;
                break;
        }
        if (IsBackupFlagSet(backupFlagIndex) == 0) {
            *characterIndex = -1;
            for (candidateCharacter = 0; candidateCharacter < 8; candidateCharacter++) {
                if (IsKartAppearWithinLimit(gKartModelMenu->mKartAppear, candidateCharacter, kartIndex) != 0) {
                    *characterIndex = candidateCharacter;
                    break;
                }
            }
            if (*characterIndex != -1) {
                return 1;
            }
            return 0;
        }
    }
    return IsKartAppearWithinLimit(gKartModelMenu->mKartAppear, *characterIndex, kartIndex);
}

u16 GetKartListNumber(void) {
    return gKartModelMenu->mKartListPos + 1;
}

u16 GetKartListCount(void) {
    return gKartModelMenu->mKartListCount;
}

void LoadEmblemSBNclr(void *section) {
    void *nclrFile;

    LoadKartModelMenuFile(section, gEmblemSBNclrName, &nclrFile);
    LoadNclrData(&gEmblemSBNclr, nclrFile);
}

void InitCameraGlobals(void) {
    u32 tableIndex;

    *(u32 *) 0x4000580 = 0xbfff0000;
    gCameraEntryChanged = 1;
    tableIndex = gEntryCameraUpdateRan = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        tableIndex = gRaceSetup->mMissionCameraTableIndex;
        tableIndex = (u16) tableIndex;
    } else {
        tableIndex = (u16) tableIndex;
        tableIndex = (u16) tableIndex;
    }
    gDefaultFollowDistance = gCameraDefaultRows[tableIndex][0];
    gFollowHeight = gCameraDefaultRows[tableIndex][1];
    gDefaultLookAtHeight = gCameraDefaultRows[tableIndex][2];
    if (gRaceSetup->mCourseId == COURSE_ID_AIRSHIP) {
        gCourseWobbleAmplitude = 0xa000;
    } else {
        gCourseWobbleAmplitude = 0x5000;
    }
}

void CreateChaseCamera(void) {
    Kart *kart = GetKart(gRaceSetup->mEntryIndex);

    gChaseCamera = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x270);
    SetupCameraBehindKart();
    GetKartForward(kart, &gChaseCamera->mSavedKartForward);
    RefreshCameraProjection(gChaseCamera);
}

void CreateEntryCamera(u32 followedKartIndex) {
    void *heap = GetHeap(GetCurrentHeapCall());
    u16 cameraIndex;
    u16 kind7EntryCount;
    CourseMapCamera *courseMapCamera;
    u16 index;
    u16 listIndex;
    s32 nextIndex;

    gEntryCamera = HeapAlloc(heap, sizeof(Camera));
    SetupCamera(gEntryCamera);
    gEntryCamera->mFollowedKartIndex = followedKartIndex;
    gEntryCamera->mCourseMapCamera = NULL;
    gEntryCamera->mFrustumShift = CAMERA_FRUSTUM_SHIFT_NONE;
    gEntryCamera->mKind = CAMERA_KIND_ENTRY;
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        gEntryCamera->mCourseMapCamera = gCourseMap->mCameras;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        gEntryCamera->mCourseMapCamera = gCourseMap->mFirstBattleSequenceCamera;
        if (gEntryCamera->mCourseMapCamera != NULL) {
            kind7EntryCount = 0;
            nextIndex = -1;
            for (cameraIndex = 0; cameraIndex < gCourseMap->mCameraCount; cameraIndex++) {
                if (gCourseMap->mCameras[cameraIndex].mKind == COURSE_MAP_CAMERA_KIND_SEQUENCE) {
                    kind7EntryCount++;
                }
            }
            gSequenceEntryCount = kind7EntryCount;
            gEntryCamera->mSequenceEntries = HeapAlloc(heap, kind7EntryCount * 0x88);
            courseMapCamera = gEntryCamera->mCourseMapCamera;
            index = 0;
            listIndex = 0;
            for (; index < gCourseMap->mCameraCount; index++) {
                if (nextIndex != -1) {
                    courseMapCamera = GetCourseMapCamera(nextIndex);
                    if (courseMapCamera == gEntryCamera->mCourseMapCamera) {
                        break;
                    }
                }
                if (courseMapCamera->mKind == COURSE_MAP_CAMERA_KIND_SEQUENCE) {
                    InitSequenceCameraEntry(&gEntryCamera->mSequenceEntries[listIndex], courseMapCamera);
                    listIndex++;
                    nextIndex = courseMapCamera->mNextIndex;
                }
            }
            gEntryCamera->mCurrentSequenceEntry = gEntryCamera->mSequenceEntries;
            gEntryCamera->mUnk_224 = 0;
            gEntryCamera->mKind = CAMERA_KIND_ENTRY_SEQUENCE;
            gCameraEntryChanged = 1;
        }
    }
}

void InitSequenceCameraEntry(SequenceCameraEntry *kind7Entry, CourseMapCamera *courseMapCamera) {
    CourseMapEntryGroup *entryGroup = &gCourseMap->mEntryGroups[courseMapCamera->mEntryGroupIndex];

    kind7Entry->mPosCurveStep = courseMapCamera->mPosCurvePerFrame;
    kind7Entry->mUnk_7e = 2;
    kind7Entry->mCourseMapCamera = courseMapCamera;
    kind7Entry->mUnk_80 = 0;
    kind7Entry->mUnk_84 = 0;
    if (entryGroup->mEntryCount >= 4) {
        SetupPosCurve(&kind7Entry->mPosCurve, courseMapCamera);
        SetupReversePosCurve(&kind7Entry->mReversePosCurve, courseMapCamera);
    }
}

void CreateChainCameraPair(void) {
    void *heap = GetHeap(GetCurrentHeapCall());

    gFirstChainCamera = HeapAlloc(heap, sizeof(Camera));
    gSecondChainCamera = HeapAlloc(heap, sizeof(Camera));
    SetupCamera(gFirstChainCamera);
    SetupCamera(gSecondChainCamera);
    gFirstChainCamera->mCourseMapCamera = gCourseMap->mFirstChainStartEntry;
    gSecondChainCamera->mCourseMapCamera = gCourseMap->mSecondChainStartEntry;
    gFirstChainCamera->mKind = CAMERA_KIND_CHAIN;
    gSecondChainCamera->mKind = CAMERA_KIND_CHAIN;
    if (gFirstChainCamera->mCourseMapCamera == NULL) {
        gRaceProgress->mCameraChainEnded = 1;
        return;
    }
    if ((s16) gFirstChainCamera->mCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&gFirstChainCamera->mPosCurve, gFirstChainCamera->mCourseMapCamera);
    }
    if ((s16) gSecondChainCamera->mCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&gSecondChainCamera->mPosCurve, gSecondChainCamera->mCourseMapCamera);
    }
}

void CreateFirstChainCamera(void) {
    gFirstChainCamera = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(Camera));
    gSecondChainCamera = NULL;
    SetupCamera(gFirstChainCamera);
    gFirstChainCamera->mCourseMapCamera = gCourseMap->mFirstChainStartEntry;
    gFirstChainCamera->mKind = CAMERA_KIND_CHAIN;
    gFirstChainCamera->mFrustumShift = CAMERA_FRUSTUM_SHIFT_NONE;
    if (gFirstChainCamera->mCourseMapCamera == NULL) {
        gRaceProgress->mCameraChainEnded = 1;
        return;
    }
    if ((s16) gFirstChainCamera->mCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&gFirstChainCamera->mPosCurve, gFirstChainCamera->mCourseMapCamera);
    }
}

#pragma thumb off

// Writes the default values of 76 members; re-run by SetupCameraBehindKart when a kart is placed.
void SetupCamera(Camera *camera) {
    Vec3 worldUp;
    volatile Vec3 initialLookAt;
    Vec3 zero;

    camera->mPos.x = 0x1e3000;
    camera->mPos.y = 0x4bd000;
    camera->mPos.z = 0xc6b000;
    initialLookAt = gCameraVec3Zero;
    camera->mLookAt = initialLookAt;
    worldUp = *(volatile Vec3 *) &gCameraVec3UnitY;
    camera->mUp = gCameraVec3UnitY;
    camera->mSide = gCameraVec3UnitX;
    MTX_Identity43_(&camera->mViewMatrix);
    camera->mForward = gCameraVec3UnitZ;
    camera->mPosGoalYOffset = 0;
    camera->mHalfFovAngleGoal = gDefaultHalfFovAngle;
    camera->mHalfFovAngle = gDefaultHalfFovAngle + 5;
    camera->mHalfFovPairFirst = FX_SinIdx((u16) camera->mHalfFovAngle);
    camera->mHalfFovPairSecond = FX_CosIdx((u16) camera->mHalfFovAngle);
    camera->mAspectRatio = 0x1555;
    camera->mNear = 0x400;
    camera->mSecondFar = 0x640000;
    camera->mFar = gCourseMap->mSettings->mCameraFar;
    if (camera->mFar < 0x1000) {
        camera->mFar = 0x640000;
    }
    camera->mFrustumTop = 0;
    camera->mFrustumBottom = 0;
    camera->mFrustumLeft = 0;
    camera->mFrustumRight = 0;
    zero = gCameraVec3Zero;
    camera->mViewPos = zero;
    camera->mViewLookAt = zero;
    camera->mBaseUp = worldUp;
    camera->mHeldHeight = 0;
    camera->mLookAtHeight = gDefaultLookAtHeight;
    camera->mUnk_0d8 = 1;
    camera->mFollowDistance = gDefaultFollowDistance;
    camera->mInitialFollowDistance = camera->mFollowDistance;
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
    camera->mFactor = 0;
    camera->mWobblePerFrame = 0;
    camera->mWobbleDirection = 1;
    camera->mWobbleDecay = 0;
    camera->mWobbleOffset = 0;
    camera->mWobbleAmplitude = 0;
    camera->mFollowedKartIndex = 0;
    camera->mLastCourseMapCameraIndex = -1;
    camera->mCourseMapCameraFrames = 0;
    camera->mAngleStartRunning = FALSE;
    camera->mAngleStartFrames = 0;
    camera->mEntryUpdateHold = 0;
    camera->mEntryUpdateDisabled = FALSE;
    camera->mMissionRunCameraRunning = FALSE;
    camera->mFrustumShift = CAMERA_FRUSTUM_SHIFT_NONE;
    camera->mKind = CAMERA_KIND_CHASE;
    camera->mPosGoalKartOffset = zero;
    camera->mPosGoalCollisionOffset = zero;
    camera->mCollisionState = CAMERA_COLLISION_STATE_NONE;
    camera->mCollisionActive = FALSE;
    camera->mCollisionLatch = FALSE;
    camera->mSavedKartForward = zero;
    camera->mPosOffset = zero;
    camera->mLookAtOffset = zero;
    camera->mSideDistanceSign = gRaceSetup->mMirrorMode ? -1 : 1;
    camera->mSequenceEntries = NULL;
    camera->mCurrentSequenceEntry = NULL;
    camera->mUnk_20c = 0;
    camera->mUnk_20e = 0;
    camera->mUnk_224 = 0;
    camera->mKartMoveScale = TO_FIXED12(1);
}

void RefreshCameraProjection(Camera *camera) {
    s32 top;
    s32 bottom;
    s32 staffRollShift;
    s32 unused;

    if (camera == gChaseCamera) {
        if (camera->mHalfFovAngle == camera->mHalfFovAngleGoal && gEntryCameraUpdateRan == 0) {
            return;
        }
        if (GetAbsoluteValue(camera->mHalfFovAngle - camera->mHalfFovAngleGoal) < 10) {
            camera->mHalfFovAngle = camera->mHalfFovAngleGoal;
        }
    }
    camera->mFrustumTop =
        MUL_FIXED12_NO_ROUND(camera->mNear, FX_Div(camera->mHalfFovPairFirst, camera->mHalfFovPairSecond));
    camera->mFrustumBottom = -camera->mFrustumTop;
    camera->mFrustumLeft = MUL_FIXED12_NO_ROUND(-camera->mFrustumTop, camera->mAspectRatio);
    top = camera->mFrustumTop;
    bottom = camera->mFrustumBottom;
    switch (camera->mFrustumShift) {
        case CAMERA_FRUSTUM_SHIFT_UP:
            top <<= 1;
            bottom = -top;
            camera->mFrustumTop = MUL_FIXED12_NO_ROUND(top, gCameraFrustumShiftScale + 0x1000);
            camera->mFrustumBottom = MUL_FIXED12_NO_ROUND(top, gCameraFrustumShiftScale);
            break;
        case CAMERA_FRUSTUM_SHIFT_DOWN:
            bottom <<= 1;
            top = -bottom;
            camera->mFrustumBottom = MUL_FIXED12_NO_ROUND(bottom, gCameraFrustumShiftScale + 0x1000);
            camera->mFrustumTop = MUL_FIXED12_NO_ROUND(bottom, gCameraFrustumShiftScale);
            break;
    }
    if (gRaceSetup->mMirrorMode != 0) {
        camera->mFrustumLeft = -camera->mFrustumLeft;
    }
    camera->mFrustumRight = -camera->mFrustumLeft;
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL && camera->mCourseMapCamera != NULL) {
        staffRollShift = MUL_FIXED12_ROUNDED(camera->mFrustumTop, camera->mCourseMapCamera->mPosOrParams.y);
        camera->mFrustumBottom += staffRollShift;
        camera->mFrustumTop += staffRollShift;
    }
    RefreshViewFrustumFromProjection(top, bottom, camera->mFrustumLeft, camera->mFrustumRight, camera->mNear,
                                     camera->mFar);
    reg_G3_MTX_MODE = 0;
    G3i_FrustumW_(camera->mFrustumTop, camera->mFrustumBottom, camera->mFrustumLeft, camera->mFrustumRight,
                  camera->mNear, camera->mFar, 0x1000, 1, &gProjectionMatrix);
}

void UpdateCameraViewWithWorldUp(Camera *camera) {
    Vec3 side;
    Vec3 forward;
    Vec3 worldUp;
    Vec3 eyePos;
    Vec3 lookAtPos;

    worldUp = gCameraVec3UnitY;
    VEC_Subtract(&camera->mLookAt, &camera->mPos, &forward);
    if (LENGTH_SQUARED(forward) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&forward, &forward);
    }
    camera->mForward = forward;
    Vec3CrossUnrounded(&worldUp, &forward, &side);
    Vec3CrossUnrounded(&forward, &side, &camera->mUp);
    if (camera->mUp.x == 0 && camera->mUp.y == 0 && camera->mUp.z == 0) {
        camera->mUp.x = 0x1000;
        camera->mUp.y = 0x1000;
        camera->mUp.z = 0x1000;
        if (SQUARE_SUM3(camera->mUp.x, camera->mUp.y, camera->mUp.z) >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&camera->mUp, &camera->mUp);
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
void UpdateCameraView(Camera *camera) {
    Vec3 forward;
    Vec3 baseUp;
    Vec3 eyePos;
    Vec3 lookAtPos;

    baseUp = camera->mBaseUp;
    eyePos = camera->mPos;
    lookAtPos = camera->mLookAt;
    lookAtPos.y += camera->mWobbleOffset;
    VEC_Subtract(&lookAtPos, &eyePos, &forward);
    if (LENGTH_SQUARED(forward) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&forward, &forward);
    }
    camera->mForward = forward;
    Vec3CrossUnrounded(&baseUp, &forward, &camera->mSide);
    Vec3CrossUnrounded(&forward, &camera->mSide, &camera->mUp);
    if (camera->mUp.x == 0 && camera->mUp.y == 0 && camera->mUp.z == 0) {
        camera->mUp.x = 0x1000;
        camera->mUp.y = 0x1000;
        camera->mUp.z = 0x1000;
        if (SQUARE_SUM3(camera->mUp.x, camera->mUp.y, camera->mUp.z) >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&camera->mUp, &camera->mUp);
        }
    }
    if (camera->mShakeKind != 0) {
        UpdateCameraShake(camera);
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
