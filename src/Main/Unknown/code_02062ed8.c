#include "Main/Unknown/code_02062ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203be88.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_02064000.h"
#include "Main/Unknown/code_02065000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02010c84.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02147000.h"
#include "code_021471bc.h"

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
    record->mUnk_10 = kart->mMotionFlags;
    record->mUnk_10 = record->mUnk_10 | (((recordState->mPushDirection.x >> 6) & 0xff) << 24 |
                                         ((recordState->mPushDirection.y >> 6) & 0xff) << 16 |
                                         ((recordState->mPushDirection.z >> 6) & 0xff) << 8);
    record->mUnk_14 = kart->mDriveFlags;
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
    InitModelAnimationFromFile(2, &data_usa_0217ab04, gCourseModels.mNsbmd, heap, nsbmdFile, animationFile,
                               &gCourseModels.mNsbtpAnmObjCount);
    animationFile = FindCourseFile(gCourseModelNsbtaName);
    InitModelAnimationFromFile(1, &data_0217ab5c, gCourseModels.mNsbmd, heap, nsbmdFile, animationFile,
                               &gCourseModels.mNsbtaAnmObjCount);
    SetNsbmdPolygonIdAll(gCourseModels.mNsbmd, 8);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(resMdl, 1);
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_KOOPA_AGB:
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_02154a00);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlAlpha(resMdl, materialIndex, 0x1e);
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            break;
        case COURSE_ID_BANK:
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_02154990);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_02154a10);
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
        InitModelAnimationFromFile(1, &data_usa_0217ab74, gCourseModels.mVNsbmd, heap, nsbmdFile, animationFile,
                                   &gCourseModels.mVNsbtaAnmObjCount);
    }
    shdwOffMaterialIndices[0] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549f0);
    shdwOffMaterialIndices[1] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549c0);
    shdwOffMaterialIndices[2] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549d0);
    shdwOffMaterialIndices[3] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549e0);
    shdwOffMaterialIndices[4] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549b0);
    shdwOffMaterialIndices[5] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549a0);
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        if (shdwOffMaterialIndices[slotIndex] >= 0) {
            NNS_G3dMdlSetMdlPolygonID(resMdl, shdwOffMaterialIndices[slotIndex], 7);
        }
    }
    MTX_Identity43_(&data_usa_0217abac);
    InitCourseModelsFogEnableFlags();
}

void UpdateCourseModels(void) {
    if (gCourseModels.mNsbtpAnmObjCount != 0) {
        AdvanceModelAnimation(&data_usa_0217ab04);
    }
    if (gCourseModels.mNsbtaAnmObjCount != 0) {
        AdvanceModelAnimation(&data_0217ab5c);
    }
    if (gCourseModels.mVNsbmd != NULL && gCourseModels.mVNsbtaAnmObjCount != 0) {
        AdvanceModelAnimation(&data_usa_0217ab74);
    }
}

void DrawCourseModel(void) {
    DrawNsbmdWithMatrix(gCourseModels.mNsbmd, &data_usa_0217abac, data_usa_02154a20);
}

void DrawCourseModelV(void) {
    if (gCourseModels.mVNsbmd == NULL) {
        return;
    }
    DrawNsbmdWithMatrix(gCourseModels.mVNsbmd, &data_usa_0217abac, data_usa_02154a20);
}

void SetKoopaCourseLight2(void) {
    Vec3s16 lightVector;

    if (gRaceSetup->mCourseId != COURSE_ID_KOOPA) {
        return;
    }
    lightVector = data_usa_021653fc;
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
            gCourseModels.mSavedVFogEnableFlags |= 1 << vMaterialIndex;
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
                    resMdl, vMaterialIndex, (gCourseModels.mSavedVFogEnableFlags & (1 << vMaterialIndex)) != 0 ? 1 : 0);
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
    if (gCourseModels.mNsbtpAnmObjCount != 0) {
        return FROM_FIXED12(gCourseModels.mNsbtpFrameIndex);
    }
    return -1;
}
