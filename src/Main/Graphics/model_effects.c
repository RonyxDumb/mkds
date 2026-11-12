#include "Main/Graphics/model_effects.h"
#include "Main/System/heap.h"
#include "Main/Graphics/effects.h"
#include "Main/Unknown/code_0208b000.h"
#include "res_struct_accessor.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02012b30.h"
#include "code_0201750c.h"
#include "fx_mtx43.h"
#include "g3imm.h"
#include "code_020172d0.h"
#include "registers.h"

void UpdatePosStrip(PosStrip *posStrip) {
    PosStripPoint *point;
    PosStripPoint *nextPoint;
    PosStripPoint *newPoint;
    u32 expired;

    point = NNS_FndGetNextListObject(&posStrip->mPoints, NULL);
    if (point != NULL) {
        do {
            nextPoint = NNS_FndGetNextListObject(&posStrip->mPoints, point);
            point->mSinceAddedFrames = point->mSinceAddedFrames + 1;
            if (point->mSinceAddedFrames > gPosStripMaxAgeFrames) {
                expired = 1;
            } else {
                point->mHeight = point->mHeight - gPosStripHeightDecreasePerFrame;
                expired = 0;
            }
            if (expired != 0) {
                NNS_FndRemoveListObject(&posStrip->mPoints, point);
                NNS_FndAppendListObject(&gPosStrips->mLists[2], point);
                if (nextPoint == NULL) {
                    break;
                }
                point = nextPoint;
            }
            point = NNS_FndGetNextListObject(&posStrip->mPoints, point);
        } while (point != NULL);
    }
    if (posStrip->mStopped == 0) {
        newPoint = NNS_FndGetNthListObject(&gPosStrips->mLists[2], 0);
        NNS_FndRemoveListObject(&gPosStrips->mLists[2], newPoint);
        NNS_FndAppendListObject(&posStrip->mPoints, newPoint);
        gSetPosStripPointFunction(newPoint, posStrip);
        return;
    }
    if (posStrip->mPoints.mCount != 0) {
        return;
    }
    NNS_FndRemoveListObject(&gPosStrips->mLists[0], posStrip);
    NNS_FndAppendListObject(&gPosStrips->mLists[1], posStrip);
}

void DrawPosStripQuad(const MtxFx43 *viewMatrix, PosStripPoint *firstPoint, PosStripPoint *secondPoint,
                      PosStripTexture *posStripTexture) {
    MtxFx43 firstMatrix;
    MtxFx43 secondMatrix;

    MTX_Scale43_(&firstMatrix, 0x1000, firstPoint->mHeight, 0x1000);
    MTX_Scale43_(&secondMatrix, 0x1000, secondPoint->mHeight, 0x1000);
    firstMatrix.mRows[3].x = firstPoint->mPos.x;
    firstMatrix.mRows[3].y = firstPoint->mPos.y;
    firstMatrix.mRows[3].z = firstPoint->mPos.z;
    secondMatrix.mRows[3].x = secondPoint->mPos.x;
    secondMatrix.mRows[3].y = secondPoint->mPos.y;
    secondMatrix.mRows[3].z = secondPoint->mPos.z;
    MTX_Concat43(&firstMatrix, viewMatrix, &firstMatrix);
    MTX_Concat43(&secondMatrix, viewMatrix, &secondMatrix);
    reg_G3_BEGIN_VTXS = 1;
    G3_LoadMtx43(&firstMatrix);
    reg_G3_TEXCOORD = (u16) ((posStripTexture->mLowHalfTexCoord << 8) >> 16);
    reg_G3_VTX_10 = 0x10000;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_10 = 0xf0000;
    G3_LoadMtx43(&secondMatrix);
    reg_G3_TEXCOORD = (u16) ((posStripTexture->mHighHalfTexCoord << 8) >> 16) << 16;
    reg_G3_VTX_10 = 0xf0000;
    reg_G3_TEXCOORD = (u16) ((posStripTexture->mLowHalfTexCoord << 8) >> 16) |
                      (u16) ((posStripTexture->mHighHalfTexCoord << 8) >> 16) << 16;
    reg_G3_VTX_10 = 0x10000;
    reg_G3_END_VTXS = 0;
}

void SetAwardPosStripDrawEnabled(s32 drawEnabled) {
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gPosStripDrawEnabled = drawEnabled;
    }
}

void InitModelEffects(void *heap) {
    u16 kindIndex;
    void *modelFile;
    void *nsbcaFile;
    void *nsbmaFile;
    void *nsbtaFile;
    ModelEffectKind *firstKind;
    ModelEffectKind *secondKind;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        heap = gOverlayLoader->mExpHeap;
    }
    gModelEffects = HeapAlloc(heap, 0x60);
    NNS_FndInitList(&gModelEffects->mActiveList, 0);
    for (kindIndex = 0; kindIndex < 5; kindIndex++) {
        NNS_FndInitList(&gModelEffects->mFreeLists[kindIndex], 0);
    }
    firstKind = gModelEffectKinds;
    secondKind = &data_021661b8;
    if (gRaceSetup->mMode == MODE_WIFI) {
        firstKind->mObjectCount = 6;
        secondKind->mObjectCount = 4;
    } else {
        firstKind->mObjectCount = 3;
        secondKind->mObjectCount = 1;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstKind->mObjectCount = 0x14;
    }
    SetupWaterEfctKindRow(&data_021661e4, 1);
    SetupWaterEfctKindRow(&data_0216623c, 2);
    SetupBkWaveKind();
    InitModelEffectObjects(heap);
    modelFile = FindMainRaceOrMainEffectFile(gBombcoreNsbmdName);
    nsbcaFile = FindMainRaceOrMainEffectFile(gBombcoreNsbcaName);
    nsbmaFile = FindMainRaceOrMainEffectFile(gBombcoreNsbmaName);
    nsbtaFile = FindMainRaceOrMainEffectFile(gBombcoreNsbtaName);
    SetupModelEffectKind(heap, 0, modelFile, nsbcaFile, nsbmaFile, nsbtaFile);
    modelFile = FindMainRaceOrMainEffectFile(gBombcore2NsbmdName);
    nsbcaFile = FindMainRaceOrMainEffectFile(gBombcore2NsbcaName);
    nsbmaFile = FindMainRaceOrMainEffectFile(gBombcore2NsbmaName);
    nsbtaFile = FindMainRaceOrMainEffectFile(gBombcore2NsbtaName);
    SetupModelEffectKind(heap, 1, modelFile, nsbcaFile, nsbmaFile, nsbtaFile);
    SetupModelEffectKind(heap, 2, GetWaterEfctNsbmdFile(), GetWaterEfctNsbcaFile(), GetWaterEfctNsbmaFile(), NULL);
    SetupModelEffectKind(heap, 4, GetWaterEfctNsbmdFile(), GetWaterEfctNsbcaFile(), GetWaterEfctNsbmaFile(), NULL);
    if (gRaceSetup->mCourseId == COURSE_ID_OLD_HYUDORO_64) {
        SetupModelEffectKind(heap, 3, GetWaterEfctNsbmdFile(), FindCourseFile(data_021663a8),
                             FindCourseFile(data_021663c0), NULL);
    }
    gModelEffects->mNextPolygonId = 10;
}

// Starts a pooled object of the given kind at position; startEffects goes to its start function. NULL if none is free.
ModelEffect *StartModelEffect(u32 kind, const Vec3 *position, s32 startEffects) {
    ModelEffect *modelEffect;

    modelEffect = NNS_FndGetNthListObject(&gModelEffects->mFreeLists[kind], 0);
    if (modelEffect != NULL) {
        NNS_FndRemoveListObject(&gModelEffects->mFreeLists[kind], modelEffect);
        modelEffect->mFinished = 0;
        modelEffect->mPos = *position;
        modelEffect->mSinceStartFrames = 0;
        modelEffect->mFinishFrameCount = 0;
        modelEffect->mPolygonId = gModelEffects->mNextPolygonId;
        modelEffect->mVisible = 1;
        modelEffect->mStart(modelEffect, startEffects);
        NNS_FndAppendListObject(&gModelEffects->mActiveList, modelEffect);
        gModelEffects->mNextPolygonId++;
        if (gModelEffects->mNextPolygonId > 0xd) {
            gModelEffects->mNextPolygonId = 10;
        }
    }
    return modelEffect;
}

void UpdateModelEffects(void) {
    ModelEffect *modelEffect;

    modelEffect = NNS_FndGetNextListObject(&gModelEffects->mActiveList, NULL);
    if (modelEffect == NULL) {
        return;
    }
    do {
        modelEffect->mUpdate(modelEffect);
        modelEffect->mSinceStartFrames = modelEffect->mSinceStartFrames + 1;
        if (modelEffect->mFinished == 1) {
            NNS_FndRemoveListObject(&gModelEffects->mActiveList, modelEffect);
            NNS_FndAppendListObject(&gModelEffects->mFreeLists[modelEffect->mKind], modelEffect);
        }
        modelEffect = NNS_FndGetNextListObject(&gModelEffects->mActiveList, modelEffect);
    } while (modelEffect != NULL);
}

void DrawModelEffects(void) {
    MtxFx43 drawMatrix;
    ModelEffect *modelEffect;

    MTX_Identity43_(&drawMatrix);
    modelEffect = NNS_FndGetNextListObject(&gModelEffects->mActiveList, NULL);
    if (modelEffect == NULL) {
        return;
    }
    do {
        if (modelEffect->mVisible != 0) {
            drawMatrix.mRows[3].x = modelEffect->mPos.x >> 4;
            drawMatrix.mRows[3].y = modelEffect->mPos.y >> 4;
            drawMatrix.mRows[3].z = modelEffect->mPos.z >> 4;
            SetNsbmdPolygonIdAll(&modelEffect->mNsbmd, modelEffect->mPolygonId);
            DrawNsbmdWithMatrix(&modelEffect->mNsbmd, &drawMatrix, (u32 *) modelEffect->mScale);
        }
        modelEffect = NNS_FndGetNextListObject(&gModelEffects->mActiveList, modelEffect);
    } while (modelEffect != NULL);
}

// Row kindRow gets objectCount objects only when the water_efct model exists; its flags say which animations exist.
void SetupWaterEfctKindRow(ModelEffectKind *kindRow, s32 objectCount) {
    void *waterEfctNsbmdFile;
    void *waterEfctNsbcaFile;
    void *waterEfctNsbmaFile;

    waterEfctNsbmdFile = GetWaterEfctNsbmdFile();
    data_0217b07c = 0;
    if (waterEfctNsbmdFile != 0) {
        waterEfctNsbcaFile = GetWaterEfctNsbcaFile();
        waterEfctNsbmaFile = GetWaterEfctNsbmaFile();
        kindRow->mObjectCount = objectCount;
        if (waterEfctNsbcaFile != 0) {
            kindRow->mUseNsbca = TRUE;
        } else {
            kindRow->mUseNsbca = FALSE;
        }
        if (waterEfctNsbmaFile != 0) {
            kindRow->mUseNsbma = TRUE;
        } else {
            kindRow->mUseNsbma = FALSE;
        }
    } else {
        kindRow->mObjectCount = 0;
        kindRow->mUseNsbca = FALSE;
        kindRow->mUseNsbma = FALSE;
        gKind2EffectIds[0] = -1;
        gKind2EffectIds[1] = -1;
    }
}

// Row 3 gets one object only when the water_efct model exists; its animation flags say which bk_wave files exist.
void SetupBkWaveKind(void) {
    ModelEffectKind *kindRow;
    void *bkWaveNsbcaFile;
    void *bkWaveNsbmaFile;

    kindRow = &data_02166210;
    if (GetWaterEfctNsbmdFile() != 0) {
        bkWaveNsbcaFile = FindCourseFile(gBkWaveNsbcaName);
        bkWaveNsbmaFile = FindCourseFile(gBkWaveNsbmaName);
        kindRow->mObjectCount = 1;
        if (bkWaveNsbcaFile != NULL) {
            kindRow->mUseNsbca = TRUE;
        } else {
            kindRow->mUseNsbca = FALSE;
        }
        if (bkWaveNsbmaFile != NULL) {
            kindRow->mUseNsbma = TRUE;
        } else {
            kindRow->mUseNsbma = FALSE;
        }
    } else {
        kindRow->mObjectCount = 0;
        kindRow->mUseNsbca = FALSE;
        kindRow->mUseNsbma = FALSE;
    }
}

void InitModelEffectObjects(void *heap) {
    u16 kindIndex;
    u16 objectIndex;
    ModelEffectKind *kindRow;
    ModelEffect *modelEffect;
    s32 scale;

    for (kindIndex = 0; kindIndex < 5; kindIndex++) {
        kindRow = &gModelEffectKinds[kindIndex];
        if (kindRow->mObjectCount == 0) {
            continue;
        }
        gModelEffects->mObjects[kindIndex] = HeapAlloc(heap, kindRow->mObjectCount << 2);
        for (objectIndex = 0; objectIndex < kindRow->mObjectCount; objectIndex++) {
            modelEffect = HeapAlloc(heap, kindRow->mObjectSize);
            gModelEffects->mObjects[kindIndex][objectIndex] = modelEffect;
            if (kindRow->mUseNsbca == FALSE) {
                modelEffect->mAnimations[0] = NULL;
            } else {
                modelEffect->mAnimations[0] = HeapAlloc(heap, 0x38);
            }
            if (kindRow->mUseNsbma == FALSE) {
                modelEffect->mAnimations[1] = NULL;
            } else {
                modelEffect->mAnimations[1] = HeapAlloc(heap, 0x38);
            }
            if (kindRow->mUseNsbta == 0) {
                modelEffect->mAnimations[2] = NULL;
            } else {
                modelEffect->mAnimations[2] = HeapAlloc(heap, 0x38);
            }
            modelEffect->mKind = kindIndex;
            modelEffect->mStart = kindRow->mStart;
            modelEffect->mUpdate = kindRow->mUpdate;
            NNS_FndAppendListObject(&gModelEffects->mFreeLists[kindIndex], modelEffect);
            if (kindIndex == 2) {
                scale = gRaceSetup->mCourseId == COURSE_ID_OLD_KOOPA_AGB ? 0xb33 : 0x1000;
                modelEffect->mScale[0] = scale;
                modelEffect->mScale[1] = scale;
                modelEffect->mScale[2] = scale;
            }
        }
    }
}

// Builds the model and animation objects of every pooled object of the kind from modelFile and the animation files.
void SetupModelEffectKind(void *heap, s32 kind, NNSG3dResFileHeader *modelFile, void *nsbcaFile, void *nsbmaFile,
                          void *nsbtaFile) {
    u16 objectIndex;
    u8 *modelSet;
    ModelAnimation *animation;
    NNSG3dResMdl *resMdl;
    ModelEffect *modelEffect;
    ModelEffectKind *kindRow;
    u32 fogEnabled;

    kindRow = &gModelEffectKinds[kind];
    fogEnabled = 1;
    if (gRaceSetup->mCourseId == COURSE_ID_MANSION || gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        fogEnabled = 0;
    }
    if (kindRow->mObjectCount == 0) {
        return;
    }
    if (kind != 3) {
        AddResFileEntry(&kindRow->mResFileEntry, modelFile, modelFile);
    }
    if (kind == 2) {
        data_0217b07c = 1;
    }
    modelSet = (u8 *) NNS_G3dGetMdlSet(modelFile);
    resMdl = OFFSET_PTR(NNSG3dResMdl, modelSet, *OFFSET_PTR(u32, modelSet + *OFFSET_PTR(u16, modelSet, 0xe), 0xc));
    for (objectIndex = 0; objectIndex < kindRow->mObjectCount; objectIndex++) {
        modelEffect = gModelEffects->mObjects[kind][objectIndex];
        InitNsbmdRenderObjWrapper(&modelEffect->mNsbmd, resMdl);
        NNS_G3dMdlSetMdlFogEnableFlagAll(modelEffect->mNsbmd.mResMdl, fogEnabled);
        animation = modelEffect->mAnimations[0];
        if (animation != NULL) {
            if (nsbcaFile != NULL) {
                InitModelAnimation(0, animation, &modelEffect->mNsbmd, 1, heap, modelFile);
                InitModelAnimationEntries(animation, nsbcaFile, heap);
            } else {
                animation->mAnmObjCount = 0;
            }
            if (kind == 2) {
                if (FROM_FIXED12(GetModelAnimationFrameCountFixed(modelEffect->mAnimations[0])) == 0x20) {
                    gKind2EffectIds[0] = 0x37;
                    gKind2EffectIds[1] = 0x38;
                } else {
                    gKind2EffectIds[0] = 0x39;
                    gKind2EffectIds[1] = -1;
                }
            }
        }
        animation = modelEffect->mAnimations[1];
        if (animation != NULL) {
            if (nsbmaFile != NULL) {
                InitModelAnimation(4, animation, &modelEffect->mNsbmd, 1, heap, modelFile);
                InitModelAnimationEntries(animation, nsbmaFile, heap);
            } else {
                animation->mAnmObjCount = 0;
            }
        }
        animation = modelEffect->mAnimations[2];
        if (animation != NULL) {
            if (nsbtaFile == NULL) {
                animation->mAnmObjCount = 0;
            } else {
                InitModelAnimation(1, animation, &modelEffect->mNsbmd, 1, heap, modelFile);
                InitModelAnimationEntries(animation, nsbtaFile, heap);
            }
        }
    }
}

void StartModelEffectBombcore(ModelEffect *modelEffect, s32 startEffects) {
    SetModelAnimation(modelEffect->mAnimations[0], 0);
    SetModelAnimation(modelEffect->mAnimations[1], 0);
    SetModelAnimation(modelEffect->mAnimations[2], 0);
    modelEffect->mScale[0] = 0xab8;
    modelEffect->mScale[1] = 0xab8;
    modelEffect->mScale[2] = 0xab8;
    if (startEffects == 0) {
        return;
    }
    StartEffect(0x22, &modelEffect->mPos);
    StartEffect(1, &modelEffect->mPos);
    StartEffect(2, &modelEffect->mPos);
}

void UpdateModelEffectBombcore(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames == 0x26) {
        StartEffect(3, &modelEffect->mPos);
        return;
    }
    if (modelEffect->mSinceStartFrames >= 0x37) {
        modelEffect->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(modelEffect->mAnimations[0]);
    AdvanceModelAnimation(modelEffect->mAnimations[1]);
    AdvanceModelAnimation(modelEffect->mAnimations[2]);
}

void StartWaterEfctKind2(ModelEffect *modelEffect) {
    u32 animationFrameCount;

    animationFrameCount = (u32) (GetModelAnimationFrameCountFixed(modelEffect->mAnimations[0]) << 4) >> 16;
    SetModelAnimation(modelEffect->mAnimations[0], 0);
    modelEffect->mFinishFrameCount = animationFrameCount;
    if (modelEffect->mAnimations[1] != NULL) {
        SetModelAnimation(modelEffect->mAnimations[1], 0);
    }
}

void StartWaterEfctKind4(ModelEffect *modelEffect) {
    modelEffect->mScale[0] = 0x3d9a;
    modelEffect->mScale[1] = 0x3d9a;
    modelEffect->mScale[2] = 0x3d9a;
    SetModelAnimation(modelEffect->mAnimations[0], 0);
    modelEffect->mFinishFrameCount = 0x20;
    if (modelEffect->mAnimations[1] != NULL) {
        SetModelAnimation(modelEffect->mAnimations[1], 0);
    }
    StartEffect(0x424, &modelEffect->mPos);
    StartEffect(0x422, &modelEffect->mPos);
}

// Update of kinds 2 and 4: sets mFinished at mFinishFrameCount, else advances animations 0 and 1.
void UpdateWaterEfctKinds(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= modelEffect->mFinishFrameCount) {
        modelEffect->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(modelEffect->mAnimations[0]);
    if (modelEffect->mAnimations[1] != NULL) {
        AdvanceModelAnimation(modelEffect->mAnimations[1]);
    }
}

void StartModelEffectBkWave(ModelEffect *modelEffect, s32 startEffects) {
    SetModelAnimation(modelEffect->mAnimations[0], 0);
    modelEffect->mScale[0] = 0x5800;
    modelEffect->mScale[1] = 0x5800;
    modelEffect->mScale[2] = 0x5800;
    modelEffect->mFinishFrameCount = 0x27;
    SetModelAnimation(modelEffect->mAnimations[1], 0);
    if (startEffects == 0) {
        return;
    }
    StartEffect(0x40, &modelEffect->mPos);
    StartEffect(0x41, &modelEffect->mPos);
}

void UpdateModelEffectBkWave(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= modelEffect->mFinishFrameCount) {
        modelEffect->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(modelEffect->mAnimations[0]);
    AdvanceModelAnimation(modelEffect->mAnimations[1]);
}

void StartModelEffectBombcore2(ModelEffect *modelEffect, s32 startEffects) {
    SetModelAnimation(modelEffect->mAnimations[0], 0);
    SetModelAnimation(modelEffect->mAnimations[1], 0);
    SetModelAnimation(modelEffect->mAnimations[2], 0);
    modelEffect->mScale[0] = 0x1000;
    modelEffect->mScale[1] = 0x1000;
    modelEffect->mScale[2] = 0x1000;
    if (startEffects == 0) {
        return;
    }
    StartEffect(8, &modelEffect->mPos);
    StartEffect(9, &modelEffect->mPos);
    StartEffect(0xa, &modelEffect->mPos);
}

void UpdateModelEffectBombcore2(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= 0x37) {
        modelEffect->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(modelEffect->mAnimations[0]);
    AdvanceModelAnimation(modelEffect->mAnimations[1]);
    AdvanceModelAnimation(modelEffect->mAnimations[2]);
}

// Starts a kind 2 object at position when startModel is set, then the particle effects of gKind2EffectIds.
void StartWaterEfctKind2Effects(const Vec3 *position, s32 startModel) {
    ModelEffect *modelEffect;
    u16 effectIndex;

    if (gModelEffectKinds[2].mObjectCount == 0) {
        return;
    }
    effectIndex = 0;
    if (startModel != 0) {
        modelEffect = NNS_FndGetNthListObject(OFFSET_PTR(NNSFndList, gModelEffects->mFreeLists, 0x18), 0);
        if (modelEffect != NULL) {
            NNS_FndRemoveListObject(OFFSET_PTR(NNSFndList, gModelEffects->mFreeLists, 0x18), modelEffect);
            modelEffect->mFinished = 0;
            modelEffect->mPos = *position;
            modelEffect->mSinceStartFrames = 0;
            modelEffect->mFinishFrameCount = 0;
            modelEffect->mPolygonId = gModelEffects->mNextPolygonId;
            modelEffect->mVisible = 1;
            modelEffect->mStart(modelEffect, 0);
            NNS_FndAppendListObject(&gModelEffects->mActiveList, modelEffect);
            gModelEffects->mNextPolygonId++;
            if (gModelEffects->mNextPolygonId > 0xd) {
                gModelEffects->mNextPolygonId = 10;
            }
        }
    }
    do {
        if (gKind2EffectIds[effectIndex] >= 0) {
            StartEffect(gKind2EffectIds[effectIndex], position);
        }
        effectIndex++;
    } while (effectIndex < 2);
}
