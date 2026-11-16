#include "Main/Kart/kart_model_menu.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Save/backup_reset.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Kart/kart_nop_and_absolute_value.h"
#include "Main/Kart/camera_shake.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/kart_scale_surface_tables.h"
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
#include "signed_int_divide.h"
#include "fixed_vector_math.h"
#include "geometry_engine_setup.h"
#include "matrix_4x3_basic.h"
#include "registers.h"
#include "Main/Kart/camera.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

NNSG3dResMatData *gSpecialKartBodyMaterial;
Nclr *g_EmblemPalettte;
KartModels *g_GlobalAD00;
KartModelMenuData *g_GlobalCE;

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
char g_str_emblem_s_b_NCLR[16] = "emblem_s_b.NCLR";
char g_str_charmenuparam_bin[20] = "charmenuparam.bin";
char g_str_kartmenuparam_bin[20] = "kartmenuparam.bin";
char g_str_kartoffsetdata_bin_0[20] = "kartoffsetdata.bin";
char g_str_kart_select_select_nsbmd[28] = "kart/select/select.nsbmd";
char g_str_kart_select_select_nsbtx[28] = "kart/select/select.nsbtx";

void QueueKartModelMenuLoad(void) {
    if (g_GlobalCE->mCharacterRequested != 0 || g_GlobalCE->mKartRequested != 0) {
        g_GlobalCE->mFiles[g_GlobalCE->mLoadSlotIndex].mLoadRequested = TRUE;
        g_GlobalCE->mLoadSlot->mCharacterIndex = g_GlobalCE->mView.mCharacterIndex;
        g_GlobalCE->mLoadSlot->mKartIndex = g_GlobalCE->mView.mKartIndex;
        g_GlobalCE->mLoadSlot->mKartOffsetData =
            g_GlobalCE->mKartOffsetTable + g_GlobalCE->mView.mKartIndex;
        WorkerInsertTask(LoadKartAndCharacterFiles);
        g_WorkerContext->mRunRequested = 1;
    }
}

void ClearKartModelMenuRequests(void) {
    g_GlobalCE->mKartRequested = 0;
    g_GlobalCE->mCharacterRequested = g_GlobalCE->mKartRequested;
}

BOOL FindKartModelMenuCharacter(s32 *characterIndex, u32 kartIndex) {
    u32 backupFlagIndex;
    enum { CHARACTER_FIRST } candidateCharacter;

    *characterIndex = _s32_div_f((u16) kartIndex, 3);
    if (*characterIndex >= 8) {
        switch (*characterIndex) {
            case CHARACTER_KARON:
                backupFlagIndex = 0x14;
                break;
            case CHARACTER_DAISY:
                backupFlagIndex = 0x15;
                break;
            case CHARACTER_WALUIGI:
                backupFlagIndex = 0x16;
                break;
            case CHARACTER_ROBO:
                backupFlagIndex = 0x17;
                break;
        }
        if (CheckSavedSecretFlag_from_thumb(backupFlagIndex) == 0) {
            *characterIndex = -1;
            for (candidateCharacter = 0; candidateCharacter < 8; candidateCharacter++) {
                if (IsKartAppearWithinLimit(g_GlobalCE->mKartAppear, candidateCharacter, kartIndex) != 0) {
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
    return IsKartAppearWithinLimit(g_GlobalCE->mKartAppear, *characterIndex, kartIndex);
}

u16 GetKartListNumber(void) {
    return g_GlobalCE->mKartListPos + 1;
}

u16 GetKartListCount(void) {
    return g_GlobalCE->mKartListCount;
}

void ReadEmblemPalette_from_thumb(void *section) {
    void *nclrFile;

    ReadKartModelMenuFile_from_thumb(section, g_str_emblem_s_b_NCLR, &nclrFile);
    Gfx_ReadPalette(&g_EmblemPalettte, nclrFile);
}

void InitCameraGlobals(void) {
    u32 tableIndex;

    *(u32 *) 0x4000580 = 0xbfff0000;
    gCameraEntryChanged = 1;
    tableIndex = gEntryCameraUpdateRan = 0;
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        tableIndex = g_GlobalCO->mMissionCameraTableIndex;
        tableIndex = (u16) tableIndex;
    } else {
        tableIndex = (u16) tableIndex;
        tableIndex = (u16) tableIndex;
    }
    gDefaultFollowDistance = gCameraDefaultRows[tableIndex][0];
    gFollowHeight = gCameraDefaultRows[tableIndex][1];
    gDefaultLookAtHeight = gCameraDefaultRows[tableIndex][2];
    if (g_GlobalCO->mCourseId == COURSE_ID_AIRSHIP) {
        gCourseWobbleAmplitude = 0xa000;
    } else {
        gCourseWobbleAmplitude = 0x5000;
    }
}

void CreateGlobalHD5_from_thumb(void) {
    Kart *kart = GetRacerMQEntry(g_GlobalCO->mEntryIndex);

    g_GlobalHD5 = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*g_GlobalHD5));
    SetupCameraBehindKart();
    GetMQRacerVector333(kart, &g_GlobalHD5->mSavedKartForward);
    StructHD_SomeFn_2(g_GlobalHD5);
}

void CreateAnotherGlobalHD_from_thumb(u32 followedKartIndex) {
    void *heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    u16 cameraIndex;
    u16 kind7EntryCount;
    CourseMapCamera *courseMapCamera;
    u16 index;
    u16 listIndex;
    s32 nextIndex;

    g_AnotherGlobalHD = Mem_AllocateHeap(heap, sizeof(Camera));
    StructHD_SomeFn(g_AnotherGlobalHD);
    g_AnotherGlobalHD->mFollowedKartIndex = followedKartIndex;
    g_AnotherGlobalHD->mCourseMapCamera = NULL;
    g_AnotherGlobalHD->mFrustumShift = CAMERA_FRUSTUM_SHIFT_NONE;
    g_AnotherGlobalHD->mKind = CAMERA_KIND_ENTRY;
    if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
        g_AnotherGlobalHD->mCourseMapCamera = g_GlobalPE->mCameras;
    }
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        g_AnotherGlobalHD->mCourseMapCamera = g_GlobalPE->mFirstBattleSequenceCamera;
        if (g_AnotherGlobalHD->mCourseMapCamera != NULL) {
            kind7EntryCount = 0;
            nextIndex = -1;
            for (cameraIndex = 0; cameraIndex < g_GlobalPE->mCameraCount; cameraIndex++) {
                if (g_GlobalPE->mCameras[cameraIndex].mKind == COURSE_MAP_CAMERA_KIND_SEQUENCE) {
                    kind7EntryCount++;
                }
            }
            gSequenceEntryCount = kind7EntryCount;
            g_AnotherGlobalHD->mSequenceEntries = Mem_AllocateHeap(heap, kind7EntryCount * 0x88);
            courseMapCamera = g_AnotherGlobalHD->mCourseMapCamera;
            index = 0;
            listIndex = 0;
            for (; index < g_GlobalPE->mCameraCount; index++) {
                if (nextIndex != -1) {
                    courseMapCamera = GetCourseMapCamera(nextIndex);
                    if (courseMapCamera == g_AnotherGlobalHD->mCourseMapCamera) {
                        break;
                    }
                }
                if (courseMapCamera->mKind == COURSE_MAP_CAMERA_KIND_SEQUENCE) {
                    InitSequenceCameraEntry(&g_AnotherGlobalHD->mSequenceEntries[listIndex], courseMapCamera);
                    listIndex++;
                    nextIndex = courseMapCamera->mNextIndex;
                }
            }
            g_AnotherGlobalHD->mCurrentSequenceEntry = g_AnotherGlobalHD->mSequenceEntries;
            g_AnotherGlobalHD->mUnk_224 = 0;
            g_AnotherGlobalHD->mKind = CAMERA_KIND_ENTRY_SEQUENCE;
            gCameraEntryChanged = 1;
        }
    }
}

void InitSequenceCameraEntry(SequenceCameraEntry *kind7Entry, CourseMapCamera *courseMapCamera) {
    CourseMapEntryGroup *entryGroup = &g_GlobalPE->mEntryGroups[courseMapCamera->mEntryGroupIndex];

    kind7Entry->mPosCurveStep = courseMapCamera->mPosCurvePerFrame;
    kind7Entry->mUnk_7e = 2;
    kind7Entry->mCourseMapCamera = courseMapCamera;
    kind7Entry->mUnk_80 = 0;
    kind7Entry->mUnk_84 = 0;
    if (entryGroup->mEntryCount >= 4) {
        StructVC_SomeFnLinkedRouteRelated(&kind7Entry->mPosCurve, courseMapCamera);
        SetupReversePosCurve(&kind7Entry->mReversePosCurve, courseMapCamera);
    }
}

void CreateGlobalHD_HD2_V2_from_thumb(void) {
    void *heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());

    g_GlobalHD = Mem_AllocateHeap(heap, sizeof(Camera));
    g_GlobalHD2 = Mem_AllocateHeap(heap, sizeof(Camera));
    StructHD_SomeFn(g_GlobalHD);
    StructHD_SomeFn(g_GlobalHD2);
    g_GlobalHD->mCourseMapCamera = g_GlobalPE->mFirstChainStartEntry;
    g_GlobalHD2->mCourseMapCamera = g_GlobalPE->mSecondChainStartEntry;
    g_GlobalHD->mKind = CAMERA_KIND_CHAIN;
    g_GlobalHD2->mKind = CAMERA_KIND_CHAIN;
    if (g_GlobalHD->mCourseMapCamera == NULL) {
        g_GlobalMV->mCameraChainEnded = 1;
        return;
    }
    if ((s16) g_GlobalHD->mCourseMapCamera->mEntryGroupIndex != -1) {
        StructVC_SomeFnLinkedRouteRelated(&g_GlobalHD->mPosCurve, g_GlobalHD->mCourseMapCamera);
    }
    if ((s16) g_GlobalHD2->mCourseMapCamera->mEntryGroupIndex != -1) {
        StructVC_SomeFnLinkedRouteRelated(&g_GlobalHD2->mPosCurve, g_GlobalHD2->mCourseMapCamera);
    }
}

void CreateGlobalHD_HD2_from_thumb(void) {
    g_GlobalHD = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(Camera));
    g_GlobalHD2 = NULL;
    StructHD_SomeFn(g_GlobalHD);
    g_GlobalHD->mCourseMapCamera = g_GlobalPE->mFirstChainStartEntry;
    g_GlobalHD->mKind = CAMERA_KIND_CHAIN;
    g_GlobalHD->mFrustumShift = CAMERA_FRUSTUM_SHIFT_NONE;
    if (g_GlobalHD->mCourseMapCamera == NULL) {
        g_GlobalMV->mCameraChainEnded = 1;
        return;
    }
    if ((s16) g_GlobalHD->mCourseMapCamera->mEntryGroupIndex != -1) {
        StructVC_SomeFnLinkedRouteRelated(&g_GlobalHD->mPosCurve, g_GlobalHD->mCourseMapCamera);
    }
}

#pragma thumb off

// Writes the default values of 76 members; re-run by SetupCameraBehindKart when a kart is placed.
void StructHD_SomeFn(Camera *camera) {
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
    camera->mAspectRatio = FIXED12_RATIO(4, 3);
    camera->mNear = FIXED12_RATIO(1, 4);
    camera->mSecondFar = CAMERA_DEFAULT_FAR;
    camera->mFar = g_GlobalPE->mSettings->mCameraFar;
    if (camera->mFar < TO_FIXED12(1)) {
        camera->mFar = CAMERA_DEFAULT_FAR;
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
    camera->mFollowDistanceScale = TO_FIXED12(1);
    camera->mUnk_0ec = 0;
    camera->mFollowDirectionSign = TO_FIXED12(1);
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
    camera->mSideDistanceSign = g_GlobalCO->mMirrorMode ? -1 : 1;
    camera->mSequenceEntries = NULL;
    camera->mCurrentSequenceEntry = NULL;
    camera->mUnk_20c = 0;
    camera->mUnk_20e = 0;
    camera->mUnk_224 = 0;
    camera->mKartMoveScale = TO_FIXED12(1);
}

void StructHD_SomeFn_2(Camera *camera) {
    s32 top;
    s32 bottom;
    s32 staffRollShift;
    s32 unused;

    if (camera == g_GlobalHD5) {
        if (camera->mHalfFovAngle == camera->mHalfFovAngleGoal && gEntryCameraUpdateRan == 0) {
            return;
        }
        if (AbsValue(camera->mHalfFovAngle - camera->mHalfFovAngleGoal) < 10) {
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
    if (g_GlobalCO->mMirrorMode != 0) {
        camera->mFrustumLeft = -camera->mFrustumLeft;
    }
    camera->mFrustumRight = -camera->mFrustumLeft;
    if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL && camera->mCourseMapCamera != NULL) {
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

void StructHD_SomeFn_10(Camera *camera) {
    Vec3 side;
    Vec3 forward;
    Vec3 worldUp;
    Vec3 eyePos;
    Vec3 lookAtPos;

    worldUp = gCameraVec3UnitY;
    VecFx32_Subtract(&camera->mLookAt, &camera->mPos, &forward);
    if (LENGTH_SQUARED(forward) >= 0x10) {
        Vector3_MaybeNormalize(&forward, &forward);
    }
    camera->mForward = forward;
    Vector3_Cross(&worldUp, &forward, &side);
    Vector3_Cross(&forward, &side, &camera->mUp);
    if (camera->mUp.x == 0 && camera->mUp.y == 0 && camera->mUp.z == 0) {
        camera->mUp.x = 0x1000;
        camera->mUp.y = 0x1000;
        camera->mUp.z = 0x1000;
        if (SQUARE_SUM3(camera->mUp.x, camera->mUp.y, camera->mUp.z) >=
            0x10) {
            Vector3_MaybeNormalize(&camera->mUp, &camera->mUp);
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
void StructHD_SomeLookAt(Camera *camera) {
    Vec3 forward;
    Vec3 baseUp;
    Vec3 eyePos;
    Vec3 lookAtPos;

    baseUp = camera->mBaseUp;
    eyePos = camera->mPos;
    lookAtPos = camera->mLookAt;
    lookAtPos.y += camera->mWobbleOffset;
    VecFx32_Subtract(&lookAtPos, &eyePos, &forward);
    if (LENGTH_SQUARED(forward) >= 0x10) {
        Vector3_MaybeNormalize(&forward, &forward);
    }
    camera->mForward = forward;
    Vector3_Cross(&baseUp, &forward, &camera->mSide);
    Vector3_Cross(&forward, &camera->mSide, &camera->mUp);
    if (camera->mUp.x == 0 && camera->mUp.y == 0 && camera->mUp.z == 0) {
        camera->mUp.x = 0x1000;
        camera->mUp.y = 0x1000;
        camera->mUp.z = 0x1000;
        if (SQUARE_SUM3(camera->mUp.x, camera->mUp.y, camera->mUp.z) >=
            0x10) {
            Vector3_MaybeNormalize(&camera->mUp, &camera->mUp);
        }
    }
    if (camera->mShakeKind != 0) {
        UpdateCameraShake(camera);
        VecFx32_Add(&eyePos, &camera->mShakePosOffset, &eyePos);
        VecFx32_Add(&lookAtPos, &camera->mShakeLookAtOffset, &lookAtPos);
        VecFx32_Add(&camera->mShakeLookAtCounterOffset, &lookAtPos, &lookAtPos);
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
