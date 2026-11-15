#include "Main/Kart/course_models.h"
#include "Main/System/heap.h"
#include "Main/Menu/title_scene.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Kart/kart_peer.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/Kart/kart_draw_state.h"
#include "Main/Kart/kart_start_placement.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02010c84.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "fx_mtx43.h"
#include "Main/Kart/kart_call.h"
#include "Main/Save/ghost_record_file.h"

char gCourseModelNsbtpName[20] = "/course_model.nsbtp";
Vec3s16 gKoopaCourseLight2Vector = {0, -4095, 0};
const u32 gCourseModelShdwOff1MaterialName[4] = {0x77646853, 0x3166664f, 0, 0};
const u32 gCourseModelShdwOff2MaterialName[4] = {0x77646853, 0x3266664f, 0, 0};
char gCourseModelNsbmdName[20] = "/course_model.nsbmd";
const u32 gCourseModelShdwOff4MaterialName[4] = {0x77646853, 0x3466664f, 0, 0};
char gCourseModelVNsbmdName[22] = "/course_model_V.nsbmd";
char gCourseModelVNsbtxName[22] = "/course_model_V.nsbtx";
const u32 gCourseModelFalls02MaterialName[4] = {0x6c6c6166, 0x32305f73, 0, 0};
const u32 gCourseModelYoganMaterialName[4] = {0x61676f79, 0x6e, 0, 0};
const u32 gCourseModelShdwOffMaterialName[4] = {0x77646853, 0x66664f, 0, 0};
char gCourseModelNsbtaName[20] = "/course_model.nsbta";
Vec3 gKartAwardStartPositions[3] = {
    {-5795840, 0x305000, 0}, {-6082560, 0x305000, -286720}, {-6082560, 0x305000, 0x46000}};
const u32 gCourseModelFalls01MaterialName[4] = {0x6c6c6166, 0x31305f73, 0, 0};
char gCourseModelVNsbtaName[22] = "/course_model_V.nsbta";
const u32 gCourseModelShdwOff5MaterialName[4] = {0x77646853, 0x3566664f, 0, 0};
const u32 gCourseModelShdwOff3MaterialName[4] = {0x77646853, 0x3366664f, 0, 0};
char gCourseModelNsbtxName[20] = "/course_model.nsbtx";
CourseModels gCourseModels;

static inline void InitModelAnimationFromFile(u32 animationKind, ModelAnimation *animation, Nsbmd *nsbmd, void *heap,
                                              void *modelFile, const char *animationFile, u16 *animationCount) {
    if (animationFile == NULL) {
        *animationCount = 0;
    } else {
        InitModelAnimation(animationKind, animation, nsbmd, 1, heap, modelFile);
        InitModelAnimationEntries(animation, animationFile, heap);
        SetModelAnimationEntryLoopMode(animation, 0, 1);
        SetModelAnimation(animation, 0);
    }
}

void AdvanceLocalKartCollisionSlot(Kart *kart) {
    AdvanceKartCollision(kart);
    if ((gWiFiRaceSync->mFlags & 2) != 0) {
        WriteKartToParticipantRecord(kart);
    }
    AdvanceKartDrawState(kart);
}

void AdvanceLocalKartMotionSlot(Kart *kart) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        FinishKartInCourseMapKind2Shape(&kart->mPos, kart->mIndex);
    }
    if ((kart->mEffectFlags & KART_EFFECT_START_SOUND_PENDING) != 0) {
        StartKartSoundAndCharacterAnimation(kart);
    }
    kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_START_SOUND_PENDING;
    AdvanceKartMotion(kart);
}

void AdvancePeerKartMotionSlot(Kart *kart) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        FinishKartInCourseMapKind2Shape(&kart->mPos, kart->mIndex);
    }
    if ((kart->mEffectFlags & KART_EFFECT_START_SOUND_PENDING) != 0) {
        StartKartSoundAndCharacterAnimation(kart);
    }
    kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_START_SOUND_PENDING;
    AdvancePeerKartMotion(kart);
}

void AdvancePeerKartCollisionSlot(Kart *kart) {
    AdvancePeerKartCollision(kart);
    AdvanceKartDrawState(kart);
}

void WriteKartToParticipantRecord(Kart *kart) {
    ParticipantKartRecordState *recordState;
    WiFiRaceSyncRecord *recordBase;
    ParticipantKartRecord *record;

    recordBase = &gWiFiRaceSync->mSendBuffer->mRecord;
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

// Also sets the matrix and the per-course flags (CreateCourseModels would be the verb for just finding and building).
void InitCourseModels(void *heap) {
    NNSG3dResFileHeader *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    const char *animationFile;
    NNSG3dResMdl *resMdl;
    s32 materialIndex;
    s32 shdwOffMaterialIndices[6];
    s32 slotIndex;

    nsbmdFile = FindCourseFile(gCourseModelNsbmdName);
    nsbtxFile = FindCourseFile(gCourseModelNsbtxName);
    gCourseModels.mNsbmd = HeapAlloc(heap, 0x6c);
    resMdl = InitNsbmdWithTextureInfoCopy(heap, gCourseModels.mNsbmd, nsbmdFile, nsbtxFile);
    animationFile = FindCourseFile(gCourseModelNsbtpName);
    InitModelAnimationFromFile(2, &gCourseModels.mNsbtpAnimation, gCourseModels.mNsbmd, heap, nsbmdFile, animationFile,
                               &gCourseModels.mNsbtpAnimation.mAnmObjCount);
    animationFile = FindCourseFile(gCourseModelNsbtaName);
    InitModelAnimationFromFile(1, &gCourseModels.mNsbtaAnimation, gCourseModels.mNsbmd, heap, nsbmdFile, animationFile,
                               &gCourseModels.mNsbtaAnimation.mAnmObjCount);
    SetNsbmdPolygonIdAll(gCourseModels.mNsbmd, 8);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(resMdl, 1);
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_KOOPA_AGB:
            materialIndex =
                NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelYoganMaterialName);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlAlpha(resMdl, materialIndex, 0x1e);
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            break;
        case COURSE_ID_BANK:
            materialIndex =
                NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelFalls01MaterialName);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            materialIndex =
                NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelFalls02MaterialName);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            break;
    }
    gCourseModels.mVNsbmd = NULL;
    nsbmdFile = FindCourseFile(gCourseModelVNsbmdName);
    nsbtxFile = FindCourseFile(gCourseModelVNsbtxName);
    if (nsbmdFile != NULL) {
        gCourseModels.mVNsbmd = HeapAlloc(heap, 0x6c);
        InitNsbmdWithTextureInfoCopy(heap, gCourseModels.mVNsbmd, nsbmdFile, nsbtxFile);
        SetNsbmdPolygonIdAll(gCourseModels.mVNsbmd, 8);
        animationFile = FindCourseFile(gCourseModelVNsbtaName);
        InitModelAnimationFromFile(1, &gCourseModels.mVNsbtaAnimation, gCourseModels.mVNsbmd, heap, nsbmdFile,
                                   animationFile, &gCourseModels.mVNsbtaAnimation.mAnmObjCount);
    }
    shdwOffMaterialIndices[0] =
        NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelShdwOffMaterialName);
    shdwOffMaterialIndices[1] =
        NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelShdwOff1MaterialName);
    shdwOffMaterialIndices[2] =
        NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelShdwOff2MaterialName);
    shdwOffMaterialIndices[3] =
        NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelShdwOff3MaterialName);
    shdwOffMaterialIndices[4] =
        NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelShdwOff4MaterialName);
    shdwOffMaterialIndices[5] =
        NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, gCourseModelShdwOff5MaterialName);
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        if (shdwOffMaterialIndices[slotIndex] >= 0) {
            NNS_G3dMdlSetMdlPolygonID(resMdl, shdwOffMaterialIndices[slotIndex], 7);
        }
    }
    MTX_Identity43_(&gCourseModels.mMatrix);
    InitCourseModelsFogEnableFlags();
}

void UpdateCourseModels(void) {
    if (gCourseModels.mNsbtpAnimation.mAnmObjCount != 0) {
        AdvanceModelAnimation(&gCourseModels.mNsbtpAnimation);
    }
    if (gCourseModels.mNsbtaAnimation.mAnmObjCount != 0) {
        AdvanceModelAnimation(&gCourseModels.mNsbtaAnimation);
    }
    if (gCourseModels.mVNsbmd != NULL && gCourseModels.mVNsbtaAnimation.mAnmObjCount != 0) {
        AdvanceModelAnimation(&gCourseModels.mVNsbtaAnimation);
    }
}

void DrawCourseModel(void) {
    DrawNsbmdWithMatrix(gCourseModels.mNsbmd, &gCourseModels.mMatrix, &gCourseModelDrawScale);
}

void DrawCourseModelV(void) {
    if (gCourseModels.mVNsbmd == NULL) {
        return;
    }
    DrawNsbmdWithMatrix(gCourseModels.mVNsbmd, &gCourseModels.mMatrix, &gCourseModelDrawScale);
}

void SetKoopaCourseLight2(void) {
    Vec3s16 lightVector;

    if (gRaceSetup->mCourseId != COURSE_ID_KOOPA) {
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

    gCourseModels.mRestoreFogEnableFlags = FALSE;
    gCourseModels.mSavedFogEnableFlags = 0;
    gCourseModels.mRestoreVFogEnableFlags = FALSE;
    gCourseModels.mSavedVFogEnableFlags = 0;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_DESERT:
        case COURSE_ID_MINI_STAGE2:
            gCourseModels.mRestoreFogEnableFlags = TRUE;
            break;
        case COURSE_ID_RAINBOW:
            gCourseModels.mRestoreVFogEnableFlags = TRUE;
            break;
    }
    if (gCourseModels.mRestoreFogEnableFlags != FALSE) {
        courseResMdl = gCourseModels.mNsbmd->mResMdl;
        for (materialIndex = 0; materialIndex < courseResMdl->mInfo.mNumMat; materialIndex++) {
            if (NNS_G3dMdlGetMdlFogEnableFlag(courseResMdl, materialIndex) != 0) {
                gCourseModels.mSavedFogEnableFlags |= (s64) (1 << materialIndex);
            }
        }
    } else {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mNsbmd->mResMdl, 1);
    }
    if (gCourseModels.mVNsbmd == NULL) {
        return;
    }
    if (gCourseModels.mRestoreVFogEnableFlags == FALSE) {
        return;
    }
    vResMdl = gCourseModels.mVNsbmd->mResMdl;
    for (vMaterialIndex = 0; vMaterialIndex < vResMdl->mInfo.mNumMat; vMaterialIndex++) {
        if (NNS_G3dMdlGetMdlFogEnableFlag(vResMdl, vMaterialIndex) != 0) {
            BIT_SET(gCourseModels.mSavedVFogEnableFlags, vMaterialIndex);
        }
    }
}

void SetCourseModelsFogEnableFlags(u32 flag) {
    u32 vMaterialIndex;
    NNSG3dResMdl *resMdl;
    u32 materialIndex;

    if (gCourseModels.mVNsbmd != NULL) {
        if (gCourseModels.mRestoreVFogEnableFlags != FALSE && flag == 0) {
            resMdl = gCourseModels.mVNsbmd->mResMdl;
            for (vMaterialIndex = 0; vMaterialIndex < resMdl->mInfo.mNumMat; vMaterialIndex++) {
                NNS_G3dMdlSetMdlFogEnableFlag(
                    resMdl, vMaterialIndex, BIT_IS_SET(gCourseModels.mSavedVFogEnableFlags, vMaterialIndex) ? 1 : 0);
            }
        } else {
            NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mVNsbmd->mResMdl, flag);
        }
    }
    if (gCourseModels.mRestoreFogEnableFlags == FALSE) {
        return;
    }
    if (flag != 0) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mNsbmd->mResMdl, 1);
        return;
    }
    resMdl = gCourseModels.mNsbmd->mResMdl;
    for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
        if ((gCourseModels.mSavedFogEnableFlags & (s64) (1 << materialIndex)) == 0) {
            NNS_G3dMdlSetMdlFogEnableFlag(resMdl, materialIndex, 0);
        }
    }
}

s32 GetCourseModelNsbtpFrame(void) {
    if (gCourseModels.mNsbtpAnimation.mAnmObjCount != 0) {
        return FROM_FIXED12(gCourseModels.mNsbtpAnimation.mHead.mFrameIndex);
    }
    return -1;
}
