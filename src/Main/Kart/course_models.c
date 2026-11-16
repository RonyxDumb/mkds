#include "Main/Kart/course_models.h"
#include "Main/System/heap.h"
#include "Main/Menu/title_scene.h"
#include "ITCM/kart_motion.h"
#include "Main/Kart/kart_peer.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/Kart/kart_draw_state.h"
#include "Main/Kart/kart_start_placement.h"
#include "Main/Kart/karts.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "model_draw_state.h"
#include "model_material_set.h"
#include "animation_lookup.h"
#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "matrix_4x3_basic.h"
#include "Main/Kart/kart_call.h"
#include "Main/Save/ghost_record_file.h"

char g_str_course_model_nsbtp[20] = "/course_model.nsbtp";
Vec3s16 gKoopaCourseLight2Vector = {0, -4095, 0};
const u32 g_str_ShdwOff1[4] = {0x77646853, 0x3166664f, 0, 0};
const u32 g_str_ShdwOff2[4] = {0x77646853, 0x3266664f, 0, 0};
char g_str_course_model_nsbmd[20] = "/course_model.nsbmd";
const u32 g_str_ShdwOff4[4] = {0x77646853, 0x3466664f, 0, 0};
char g_str_course_model_V_nsbmd[22] = "/course_model_V.nsbmd";
char g_str_course_model_V_nsbtx[22] = "/course_model_V.nsbtx";
const u32 g_str_falls_02[4] = {0x6c6c6166, 0x32305f73, 0, 0};
const u32 g_str_yogan[4] = {0x61676f79, 0x6e, 0, 0};
const u32 g_str_ShdwOff[4] = {0x77646853, 0x66664f, 0, 0};
char g_str_course_model_nsbta[20] = "/course_model.nsbta";
Vec3 g_MaybeAwardPositionTable[3] = {
    {-5795840, 0x305000, 0}, {-6082560, 0x305000, -286720}, {-6082560, 0x305000, 0x46000}};
const u32 g_str_falls_01[4] = {0x6c6c6166, 0x31305f73, 0, 0};
char g_str_course_model_V_nsbta[22] = "/course_model_V.nsbta";
const u32 g_str_ShdwOff5[4] = {0x77646853, 0x3566664f, 0, 0};
const u32 g_str_ShdwOff3[4] = {0x77646853, 0x3366664f, 0, 0};
char g_str_course_model_nsbtx[20] = "/course_model.nsbtx";
CourseModels g_CourseHolder;

static inline void InitModelAnimationFromFile(u32 animationKind, ModelAnimation *animation, Nsbmd *nsbmd, void *heap,
                                              void *modelFile, const char *animationFile, u16 *animationCount) {
    if (animationFile == NULL) {
        *animationCount = 0;
    } else {
        StructAM_CreateFrom(animationKind, animation, nsbmd, 1, heap, modelFile);
        StructAM_MaybeLoadAnimation(animation, animationFile, heap);
        StructAM_SetSomeValueAt(animation, 0, 1);
        StructAM_SomeFn_MaybeLoadFrame(animation, 0);
    }
}

void MQ_FnPtr4_Net_Not3(Kart *kart) {
    AdvanceKartCollision(kart);
    if ((g_GlobalAA->mFlags & WIFI_RACE_SYNC_FLAG_IN_RACE) != 0) {
        WriteKartToParticipantRecord(kart);
    }
    AdvanceKartDrawState(kart);
}

void MQ_FnPtr3_Net_Not3(Kart *kart) {
    if (IsMissionRunWithEndShapes() != 0) {
        FinishKartInCourseMapMissionEndShape(&kart->mPos, kart->mIndex);
    }
    if ((kart->mEffectFlags & KART_EFFECT_START_SOUND_PENDING) != 0) {
        StructMQRacerEntry_SomeFn_89(kart);
    }
    kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_START_SOUND_PENDING;
    AdvanceKartMotion(kart);
}

void MQ_FnPtr3_Net_3(Kart *kart) {
    if (IsMissionRunWithEndShapes() != 0) {
        FinishKartInCourseMapMissionEndShape(&kart->mPos, kart->mIndex);
    }
    if ((kart->mEffectFlags & KART_EFFECT_START_SOUND_PENDING) != 0) {
        StructMQRacerEntry_SomeFn_89(kart);
    }
    kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_START_SOUND_PENDING;
    StructMQRacerEntry_SomeFn_90(kart);
}

void MQ_FnPtr4_Net_3(Kart *kart) {
    AdvancePeerKartCollision(kart);
    AdvanceKartDrawState(kart);
}

void WriteKartToParticipantRecord(Kart *kart) {
    ParticipantKartRecordState *recordState;
    WiFiRaceSyncRecord *recordBase;
    ParticipantKartRecord *record;

    recordBase = &g_GlobalAA->mSendBuffer->mRecord;
    record = OFFSET_PTR(ParticipantKartRecord, recordBase, 8);
    recordState = kart->mParticipantRecordData;
    record->mPosX = kart->mPos.x >> 10;
    record->mPosY = (kart->mPos.y - kart->mHopHeight) >> 10;
    record->mPosZ = kart->mPos.z >> 10;
    record->mForwardSpeed = kart->mForwardSpeed >> 2;
    record->mHeadingAngle = kart->mHeadingAngle;
    record->mMotionFlagsAndPush = kart->mMotionFlags;
    record->mMotionFlagsAndPush = record->mMotionFlagsAndPush | (((recordState->mPushDirection.x >> 6) & 0xff) << 24 |
                                         ((recordState->mPushDirection.y >> 6) & 0xff) << 16 |
                                         ((recordState->mPushDirection.z >> 6) & 0xff) << 8);
    record->mDriveFlags = kart->mDriveFlags;
    record->mFlags = recordState->mEventToggleFlags;
    record->mTurnAngle = kart->mTurnAngle;
}

// Finds and builds the course models, and also sets the matrix and the per-course flags.
void LoadCourseModelsAnimations(void *heap) {
    NNSG3dResFileHeader *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    const char *animationFile;
    NNSG3dResMdl *resMdl;
    s32 materialIndex;
    s32 shdwOffMaterialIndices[6];
    s32 slotIndex;

    nsbmdFile = FindFileBuffer_CRS_CST_from_thumb(g_str_course_model_nsbmd);
    nsbtxFile = FindFileBuffer_CRS_CST_from_thumb(g_str_course_model_nsbtx);
    g_CourseHolder.mNsbmd = Mem_AllocateHeap(heap, sizeof(*g_CourseHolder.mNsbmd));
    resMdl = StructML_LoadModelAndTextures(heap, g_CourseHolder.mNsbmd, nsbmdFile, nsbtxFile);
    animationFile = FindFileBuffer_CRS_CST_from_thumb(g_str_course_model_nsbtp);
    InitModelAnimationFromFile(2, &g_CourseHolder.mNsbtpAnimation, g_CourseHolder.mNsbmd, heap, nsbmdFile, animationFile,
                               &g_CourseHolder.mNsbtpAnimation.mAnmObjCount);
    animationFile = FindFileBuffer_CRS_CST_from_thumb(g_str_course_model_nsbta);
    InitModelAnimationFromFile(1, &g_CourseHolder.mNsbtaAnimation, g_CourseHolder.mNsbmd, heap, nsbmdFile, animationFile,
                               &g_CourseHolder.mNsbtaAnimation.mAnmObjCount);
    StructML_MaybeProcessModelAnimations(g_CourseHolder.mNsbmd, 8);
    ModelBlock_SetSomethingToAllMaterials(resMdl, 1);
    switch (g_GlobalCO->mCourseId) {
        case COURSE_ID_OLD_KOOPA_AGB:
            materialIndex =
                Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_yogan);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlAlpha(resMdl, materialIndex, 0x1e);
                ModelBlock_SomeTexPltFn(resMdl, materialIndex, 0);
            }
            break;
        case COURSE_ID_BANK:
            materialIndex =
                Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_falls_01);
            if (materialIndex >= 0) {
                ModelBlock_SomeTexPltFn(resMdl, materialIndex, 0);
            }
            materialIndex =
                Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_falls_02);
            if (materialIndex >= 0) {
                ModelBlock_SomeTexPltFn(resMdl, materialIndex, 0);
            }
            break;
    }
    g_CourseHolder.mVNsbmd = NULL;
    nsbmdFile = FindFileBuffer_CRS_CST_from_thumb(g_str_course_model_V_nsbmd);
    nsbtxFile = FindFileBuffer_CRS_CST_from_thumb(g_str_course_model_V_nsbtx);
    if (nsbmdFile != NULL) {
        g_CourseHolder.mVNsbmd = Mem_AllocateHeap(heap, sizeof(*g_CourseHolder.mVNsbmd));
        StructML_LoadModelAndTextures(heap, g_CourseHolder.mVNsbmd, nsbmdFile, nsbtxFile);
        StructML_MaybeProcessModelAnimations(g_CourseHolder.mVNsbmd, 8);
        animationFile = FindFileBuffer_CRS_CST_from_thumb(g_str_course_model_V_nsbta);
        InitModelAnimationFromFile(1, &g_CourseHolder.mVNsbtaAnimation, g_CourseHolder.mVNsbmd, heap, nsbmdFile,
                                   animationFile, &g_CourseHolder.mVNsbtaAnimation.mAnmObjCount);
    }
    shdwOffMaterialIndices[0] =
        Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_ShdwOff);
    shdwOffMaterialIndices[1] =
        Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_ShdwOff1);
    shdwOffMaterialIndices[2] =
        Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_ShdwOff2);
    shdwOffMaterialIndices[3] =
        Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_ShdwOff3);
    shdwOffMaterialIndices[4] =
        Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_ShdwOff4);
    shdwOffMaterialIndices[5] =
        Dict_SomeFn_0((u8 *) resMdl + resMdl->mOfsMat + 4, g_str_ShdwOff5);
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        if (shdwOffMaterialIndices[slotIndex] >= 0) {
            ModelBlock_SomeTexPltFn_3(resMdl, shdwOffMaterialIndices[slotIndex], 7);
        }
    }
    MTX_Identity43_(&g_CourseHolder.mMatrix);
    InitCourseModelsFogEnableFlags();
}

void HandleCourseAnim(void) {
    if (g_CourseHolder.mNsbtpAnimation.mAnmObjCount != 0) {
        StructAM_SomeFn_MaybeMoveNextFrame(&g_CourseHolder.mNsbtpAnimation);
    }
    if (g_CourseHolder.mNsbtaAnimation.mAnmObjCount != 0) {
        StructAM_SomeFn_MaybeMoveNextFrame(&g_CourseHolder.mNsbtaAnimation);
    }
    if (g_CourseHolder.mVNsbmd != NULL && g_CourseHolder.mVNsbtaAnimation.mAnmObjCount != 0) {
        StructAM_SomeFn_MaybeMoveNextFrame(&g_CourseHolder.mVNsbtaAnimation);
    }
}

void DrawCourseModel(void) {
    DrawNsbmdWithMatrix(g_CourseHolder.mNsbmd, &g_CourseHolder.mMatrix, &gCourseModelDrawScale);
}

void DrawCourseModelV(void) {
    if (g_CourseHolder.mVNsbmd == NULL) {
        return;
    }
    DrawNsbmdWithMatrix(g_CourseHolder.mVNsbmd, &g_CourseHolder.mMatrix, &gCourseModelDrawScale);
}

void SetKoopaCourseLight2(void) {
    Vec3s16 lightVector;

    if (g_GlobalCO->mCourseId != COURSE_ID_KOOPA) {
        return;
    }
    lightVector = gKoopaCourseLight2Vector;
    NNS_G3dGlbLightVector(2, lightVector.x, lightVector.y, lightVector.z);
    NNS_G3dGlbLightColor(2, 0x7fff);
}

void InitCourseModelsFogEnableFlags(void) {
    u32 materialIndex;
    NNSG3dResMdl *courseResMdl;
    u32 vMaterialIndex;
    NNSG3dResMdl *vResMdl;

    g_CourseHolder.mRestoreFogEnableFlags = FALSE;
    g_CourseHolder.mSavedFogEnableFlags = 0;
    g_CourseHolder.mRestoreVFogEnableFlags = FALSE;
    g_CourseHolder.mSavedVFogEnableFlags = 0;
    switch (g_GlobalCO->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_DESERT:
        case COURSE_ID_MINI_STAGE2:
            g_CourseHolder.mRestoreFogEnableFlags = TRUE;
            break;
        case COURSE_ID_RAINBOW:
            g_CourseHolder.mRestoreVFogEnableFlags = TRUE;
            break;
    }
    if (g_CourseHolder.mRestoreFogEnableFlags != FALSE) {
        courseResMdl = g_CourseHolder.mNsbmd->mResMdl;
        for (materialIndex = 0; materialIndex < courseResMdl->mInfo.mNumMat; materialIndex++) {
            if (NNS_G3dMdlGetMdlFogEnableFlag(courseResMdl, materialIndex) != 0) {
                g_CourseHolder.mSavedFogEnableFlags |= (s64) (1 << materialIndex);
            }
        }
    } else {
        NNS_G3dMdlSetMdlFogEnableFlagAll(g_CourseHolder.mNsbmd->mResMdl, 1);
    }
    if (g_CourseHolder.mVNsbmd == NULL) {
        return;
    }
    if (g_CourseHolder.mRestoreVFogEnableFlags == FALSE) {
        return;
    }
    vResMdl = g_CourseHolder.mVNsbmd->mResMdl;
    for (vMaterialIndex = 0; vMaterialIndex < vResMdl->mInfo.mNumMat; vMaterialIndex++) {
        if (NNS_G3dMdlGetMdlFogEnableFlag(vResMdl, vMaterialIndex) != 0) {
            BIT_SET(g_CourseHolder.mSavedVFogEnableFlags, vMaterialIndex);
        }
    }
}

void SetCourseModelsFogEnableFlags(u32 flag) {
    u32 vMaterialIndex;
    NNSG3dResMdl *resMdl;
    u32 materialIndex;

    if (g_CourseHolder.mVNsbmd != NULL) {
        if (g_CourseHolder.mRestoreVFogEnableFlags != FALSE && flag == 0) {
            resMdl = g_CourseHolder.mVNsbmd->mResMdl;
            for (vMaterialIndex = 0; vMaterialIndex < resMdl->mInfo.mNumMat; vMaterialIndex++) {
                NNS_G3dMdlSetMdlFogEnableFlag(
                    resMdl, vMaterialIndex, BIT_IS_SET(g_CourseHolder.mSavedVFogEnableFlags, vMaterialIndex) ? 1 : 0);
            }
        } else {
            NNS_G3dMdlSetMdlFogEnableFlagAll(g_CourseHolder.mVNsbmd->mResMdl, flag);
        }
    }
    if (g_CourseHolder.mRestoreFogEnableFlags == FALSE) {
        return;
    }
    if (flag != 0) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(g_CourseHolder.mNsbmd->mResMdl, 1);
        return;
    }
    resMdl = g_CourseHolder.mNsbmd->mResMdl;
    for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
        if ((g_CourseHolder.mSavedFogEnableFlags & (s64) (1 << materialIndex)) == 0) {
            NNS_G3dMdlSetMdlFogEnableFlag(resMdl, materialIndex, 0);
        }
    }
}

s32 GetCourseAnimNsbtpSomeValue(void) {
    if (g_CourseHolder.mNsbtpAnimation.mAnmObjCount != 0) {
        return FROM_FIXED12(g_CourseHolder.mNsbtpAnimation.mHead.mFrameIndex);
    }
    return -1;
}
