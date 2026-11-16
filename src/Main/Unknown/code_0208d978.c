#include "Main/Unknown/code_0208d978.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0208b000.h"
#include "res_struct_accessor.h"
#include "Main/Unknown/code_020d2b78.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02012b30.h"
#include "code_0201750c.h"
#include "code_02147288.h"
#include "g3imm.h"
#include "code_020172d0.h"
#include "code_021471bc.h"
#include "registers.h"

void trl_updateTrail(PosStrip *posStrip) {
    PosStripPoint *point;
    PosStripPoint *nextPoint;
    PosStripPoint *newPoint;
    u32 expired;

    point = NNS_FndGetNextListObject(&posStrip->mPoints, NULL);
    if (point != NULL) {
        do {
            nextPoint = NNS_FndGetNextListObject(&posStrip->mPoints, point);
            point->mSinceAddedFrames = point->mSinceAddedFrames + 1;
            if (point->mSinceAddedFrames > trl_sMaxAge) {
                expired = 1;
            } else {
                point->mHeight = point->mHeight - trl_sSizeDecreaseSpeed;
                expired = 0;
            }
            if (expired != 0) {
                NNS_FndRemoveListObject(&posStrip->mPoints, point);
                NNS_FndAppendListObject(&trl_sState->mLists[2], point);
                if (nextPoint == NULL) {
                    break;
                }
                point = nextPoint;
            }
            point = NNS_FndGetNextListObject(&posStrip->mPoints, point);
        } while (point != NULL);
    }
    if (posStrip->mStopped == 0) {
        newPoint = NNS_FndGetNthListObject(&trl_sState->mLists[2], 0);
        NNS_FndRemoveListObject(&trl_sState->mLists[2], newPoint);
        NNS_FndAppendListObject(&posStrip->mPoints, newPoint);
        trl_sPointInitFunc(newPoint, posStrip);
        return;
    }
    if (posStrip->mPoints.mCount != 0) {
        return;
    }
    NNS_FndRemoveListObject(&trl_sState->mLists[0], posStrip);
    NNS_FndAppendListObject(&trl_sState->mLists[1], posStrip);
}

void trl_renderSegment(const MtxFx43 *viewMatrix, PosStripPoint *firstPoint, PosStripPoint *secondPoint,
                      PosStripTexture *posStripTexture) {
    MtxFx43 firstMatrix;
    MtxFx43 secondMatrix;

    MTX_Scale43_(&firstMatrix, 0x1000, firstPoint->mHeight, 0x1000);
    MTX_Scale43_(&secondMatrix, 0x1000, secondPoint->mHeight, 0x1000);
    firstMatrix.field0[3].x = firstPoint->mPos.x;
    firstMatrix.field0[3].y = firstPoint->mPos.y;
    firstMatrix.field0[3].z = firstPoint->mPos.z;
    secondMatrix.field0[3].x = secondPoint->mPos.x;
    secondMatrix.field0[3].y = secondPoint->mPos.y;
    secondMatrix.field0[3].z = secondPoint->mPos.z;
    MTX_Concat43(&firstMatrix, viewMatrix, &firstMatrix);
    MTX_Concat43(&secondMatrix, viewMatrix, &secondMatrix);
    reg_G3_BEGIN_VTXS = 1;
    G3_LoadMtx43(&firstMatrix);
    reg_G3_TEXCOORD = (u16) ((posStripTexture->field1C << 8) >> 16);
    reg_G3_VTX_10 = 0x10000;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_10 = 0xf0000;
    G3_LoadMtx43(&secondMatrix);
    reg_G3_TEXCOORD = (u16) ((posStripTexture->field20 << 8) >> 16) << 16;
    reg_G3_VTX_10 = 0xf0000;
    reg_G3_TEXCOORD = (u16) ((posStripTexture->field1C << 8) >> 16) | (u16) ((posStripTexture->field20 << 8) >> 16)
                                                                          << 16;
    reg_G3_VTX_10 = 0x10000;
    reg_G3_END_VTXS = 0;
}

void trl_setVisibleForAward(s32 drawEnabled) {
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        trl_sVisible = drawEnabled;
    }
}

void expl_init(void *heap) {
    u16 kindIndex;
    void *c;
    void *d;
    void *e;
    void *f;
    ModelEffectKind *firstKind;
    ModelEffectKind *secondKind;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        heap = gOverlayData->mExpHeap;
    }
    expl_sState = heap_alloc(heap, 0x60);
    NNS_FndInitList(&expl_sState->mActiveList, 0);
    for (kindIndex = 0; kindIndex < 5; kindIndex++) {
        NNS_FndInitList(&expl_sState->mFreeLists[kindIndex], 0);
    }
    firstKind = expl_sEffectDefs;
    secondKind = &data_021661b8;
    if (gRaceMultiConfig->mMode == 5) {
        firstKind->mObjectCount = 6;
        secondKind->mObjectCount = 4;
    } else {
        firstKind->mObjectCount = 3;
        secondKind->mObjectCount = 1;
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        firstKind->mObjectCount = 0x14;
    }
    expl_initWaterEffect(&data_021661e4, 1);
    expl_initWaterEffect(&data_0216623c, 2);
    expl_initBkWave();
    expl_initEffects(heap);
    c = arc_getMainRaceMainEffectArcFile(aEffectBombcore);
    d = arc_getMainRaceMainEffectArcFile(aEffectBombco_0);
    e = arc_getMainRaceMainEffectArcFile(aEffectBombco_1);
    f = arc_getMainRaceMainEffectArcFile(aEffectBombco_2);
    expl_setModel(heap, 0, c, d, e, f);
    c = arc_getMainRaceMainEffectArcFile(aEffectBombco_7);
    d = arc_getMainRaceMainEffectArcFile(aEffectBombco_3);
    e = arc_getMainRaceMainEffectArcFile(aEffectBombco_4);
    f = arc_getMainRaceMainEffectArcFile(aEffectBombco_5);
    expl_setModel(heap, 1, c, d, e, f);
    expl_setModel(heap, 2, mobj_getWaterEffectNsbmd(), mobj_getWaterEffectNsbca(), mobj_getWaterEffectNsbma(), NULL);
    expl_setModel(heap, 4, mobj_getWaterEffectNsbmd(), mobj_getWaterEffectNsbca(), mobj_getWaterEffectNsbma(), NULL);
    if (gRaceMultiConfig->mCourseId == COURSE_ID_OLD_HYUDORO_64) {
        expl_setModel(heap, 3, mobj_getWaterEffectNsbmd(), arc_getCourseArcFile(aMapobjBk_wav_2),
                             arc_getCourseArcFile(aMapobjBk_wav_0), NULL);
    }
    expl_sState->mNextPolygonId = 10;
}

// Starts a pooled object of the given kind at position; startEffects goes to its start function. NULL if none is free.
ModelEffect *expl_spawnEffect(u32 kind, const Vec3 *position, s32 startEffects) {
    ModelEffect *modelEffect;

    modelEffect = NNS_FndGetNthListObject(&expl_sState->mFreeLists[kind], 0);
    if (modelEffect != NULL) {
        NNS_FndRemoveListObject(&expl_sState->mFreeLists[kind], modelEffect);
        modelEffect->mFinished = 0;
        modelEffect->mPos = *position;
        modelEffect->mSinceStartFrames = 0;
        modelEffect->mFinishFrameCount = 0;
        modelEffect->mPolygonId = expl_sState->mNextPolygonId;
        modelEffect->mVisible = 1;
        modelEffect->mStart(modelEffect, startEffects);
        NNS_FndAppendListObject(&expl_sState->mActiveList, modelEffect);
        expl_sState->mNextPolygonId++;
        if (expl_sState->mNextPolygonId > 0xd) {
            expl_sState->mNextPolygonId = 10;
        }
    }
    return modelEffect;
}

void expl_update(void) {
    ModelEffect *modelEffect;

    modelEffect = NNS_FndGetNextListObject(&expl_sState->mActiveList, NULL);
    if (modelEffect == NULL) {
        return;
    }
    do {
        modelEffect->mUpdate(modelEffect);
        modelEffect->mSinceStartFrames = modelEffect->mSinceStartFrames + 1;
        if (modelEffect->mFinished == 1) {
            NNS_FndRemoveListObject(&expl_sState->mActiveList, modelEffect);
            NNS_FndAppendListObject(&expl_sState->mFreeLists[modelEffect->mKind], modelEffect);
        }
        modelEffect = NNS_FndGetNextListObject(&expl_sState->mActiveList, modelEffect);
    } while (modelEffect != NULL);
}

void expl_render(void) {
    MtxFx43 drawMatrix;
    ModelEffect *modelEffect;

    MTX_Identity43_(&drawMatrix);
    modelEffect = NNS_FndGetNextListObject(&expl_sState->mActiveList, NULL);
    if (modelEffect == NULL) {
        return;
    }
    do {
        if (modelEffect->mVisible != 0) {
            drawMatrix.field0[3].x = modelEffect->mPos.x >> 4;
            drawMatrix.field0[3].y = modelEffect->mPos.y >> 4;
            drawMatrix.field0[3].z = modelEffect->mPos.z >> 4;
            model_setPolygonId(&modelEffect->mNsbmd, modelEffect->mPolygonId);
            model_drawTransformed(&modelEffect->mNsbmd, &drawMatrix, (u32 *) modelEffect->mScale);
        }
        modelEffect = NNS_FndGetNextListObject(&expl_sState->mActiveList, modelEffect);
    } while (modelEffect != NULL);
}

// Row kindRow gets objectCount objects only when the water_efct model exists; its flags say which animations exist.
void expl_initWaterEffect(ModelEffectKind *kindRow, s32 objectCount) {
    void *waterEfctNsbmdFile;
    void *waterEfctNsbcaFile;
    void *waterEfctNsbmaFile;

    waterEfctNsbmdFile = mobj_getWaterEffectNsbmd();
    expl_sIsSplashModelSet = 0;
    if (waterEfctNsbmdFile != 0) {
        waterEfctNsbcaFile = mobj_getWaterEffectNsbca();
        waterEfctNsbmaFile = mobj_getWaterEffectNsbma();
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
        expl_sSplashPtclIds[0] = -1;
        expl_sSplashPtclIds[1] = -1;
    }
}

// Row 3 gets one object only when the water_efct model exists; its animation flags say which bk_wave files exist.
void expl_initBkWave(void) {
    ModelEffectKind *kindRow;
    void *bkWaveNsbcaFile;
    void *bkWaveNsbmaFile;

    kindRow = &data_02166210;
    if (mobj_getWaterEffectNsbmd() != 0) {
        bkWaveNsbcaFile = arc_getCourseArcFile(aMapobjBk_wave_);
        bkWaveNsbmaFile = arc_getCourseArcFile(aMapobjBk_wav_3);
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

void expl_initEffects(void *heap) {
    u16 kindIndex;
    u16 objectIndex;
    ModelEffectKind *kindRow;
    ModelEffect *modelEffect;
    s32 scale;

    for (kindIndex = 0; kindIndex < 5; kindIndex++) {
        kindRow = &expl_sEffectDefs[kindIndex];
        if (kindRow->mObjectCount == 0) {
            continue;
        }
        expl_sState->mObjects[kindIndex] = heap_alloc(heap, kindRow->mObjectCount << 2);
        for (objectIndex = 0; objectIndex < kindRow->mObjectCount; objectIndex++) {
            modelEffect = heap_alloc(heap, kindRow->mObjectSize);
            expl_sState->mObjects[kindIndex][objectIndex] = modelEffect;
            if (kindRow->mUseNsbca == FALSE) {
                modelEffect->mAnimations[0] = NULL;
            } else {
                modelEffect->mAnimations[0] = heap_alloc(heap, 0x38);
            }
            if (kindRow->mUseNsbma == FALSE) {
                modelEffect->mAnimations[1] = NULL;
            } else {
                modelEffect->mAnimations[1] = heap_alloc(heap, 0x38);
            }
            if (kindRow->mUseNsbta == 0) {
                modelEffect->mAnimations[2] = NULL;
            } else {
                modelEffect->mAnimations[2] = heap_alloc(heap, 0x38);
            }
            modelEffect->mKind = kindIndex;
            modelEffect->mStart = kindRow->mStart;
            modelEffect->mUpdate = kindRow->mUpdate;
            NNS_FndAppendListObject(&expl_sState->mFreeLists[kindIndex], modelEffect);
            if (kindIndex == 2) {
                scale = gRaceMultiConfig->mCourseId == COURSE_ID_OLD_KOOPA_AGB ? 0xb33 : 0x1000;
                modelEffect->mScale[0] = scale;
                modelEffect->mScale[1] = scale;
                modelEffect->mScale[2] = scale;
            }
        }
    }
}

// Builds the model and animation objects of every pooled object of the kind from modelFile and the animation files.
void expl_setModel(void *heap, s32 kind, NNSG3dResFileHeader *modelFile, void *nsbcaFile, void *nsbmaFile,
                          void *nsbtaFile) {
    u16 objectIndex;
    u8 *modelSet;
    ModelAnimation *o;
    NNSG3dResMdl *resMdl;
    ModelEffect *modelEffect;
    ModelEffectKind *kindRow;
    u32 fogEnabled;

    kindRow = &expl_sEffectDefs[kind];
    fogEnabled = 1;
    if (gRaceMultiConfig->mCourseId == COURSE_ID_MANSION || gRaceMultiConfig->mCourseId == COURSE_ID_RAINBOW) {
        fogEnabled = 0;
    }
    if (kindRow->mObjectCount == 0) {
        return;
    }
    if (kind != 3) {
        model_resSetNsbmdNsbtx(&kindRow->mResFileEntry, modelFile, modelFile);
    }
    if (kind == 2) {
        expl_sIsSplashModelSet = 1;
    }
    modelSet = (u8 *) NNS_G3dGetMdlSet(modelFile);
    resMdl = OFFSET_PTR(NNSG3dResMdl, modelSet, *OFFSET_PTR(u32, modelSet + *OFFSET_PTR(u16, modelSet, 0xe), 0xc));
    for (objectIndex = 0; objectIndex < kindRow->mObjectCount; objectIndex++) {
        modelEffect = expl_sState->mObjects[kind][objectIndex];
        model_initFromResMdl(&modelEffect->mNsbmd, resMdl);
        NNS_G3dMdlSetMdlFogEnableFlagAll(modelEffect->mNsbmd.mResMdl, fogEnabled);
        o = modelEffect->mAnimations[0];
        if (o != NULL) {
            if (nsbcaFile != NULL) {
                anim_initManager(0, o, &modelEffect->mNsbmd, 1, heap, modelFile);
                anim_registerAllAnims(o, nsbcaFile, heap);
            } else {
                o->mAnmObjCount = 0;
            }
            if (kind == 2) {
                if (anim_getAnimLength(modelEffect->mAnimations[0]) >> 12 == 0x20) {
                    expl_sSplashPtclIds[0] = 0x37;
                    expl_sSplashPtclIds[1] = 0x38;
                } else {
                    expl_sSplashPtclIds[0] = 0x39;
                    expl_sSplashPtclIds[1] = -1;
                }
            }
        }
        o = modelEffect->mAnimations[1];
        if (o != NULL) {
            if (nsbmaFile != NULL) {
                anim_initManager(4, o, &modelEffect->mNsbmd, 1, heap, modelFile);
                anim_registerAllAnims(o, nsbmaFile, heap);
            } else {
                o->mAnmObjCount = 0;
            }
        }
        o = modelEffect->mAnimations[2];
        if (o != NULL) {
            if (nsbtaFile == NULL) {
                o->mAnmObjCount = 0;
            } else {
                anim_initManager(1, o, &modelEffect->mNsbmd, 1, heap, modelFile);
                anim_registerAllAnims(o, nsbtaFile, heap);
            }
        }
    }
}

void expl_initBombcoreInstance(ModelEffect *modelEffect, s32 startEffects) {
    anim_setAnim(modelEffect->mAnimations[0], 0);
    anim_setAnim(modelEffect->mAnimations[1], 0);
    anim_setAnim(modelEffect->mAnimations[2], 0);
    modelEffect->mScale[0] = 0xab8;
    modelEffect->mScale[1] = 0xab8;
    modelEffect->mScale[2] = 0xab8;
    if (startEffects == 0) {
        return;
    }
    ptcm_createEmitter(0x22, &modelEffect->mPos);
    ptcm_createEmitter(1, &modelEffect->mPos);
    ptcm_createEmitter(2, &modelEffect->mPos);
}

void expl_updateBombcoreInstance(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames == 0x26) {
        ptcm_createEmitter(3, &modelEffect->mPos);
        return;
    }
    if (modelEffect->mSinceStartFrames >= 0x37) {
        modelEffect->mFinished = 1;
        return;
    }
    anim_update(modelEffect->mAnimations[0]);
    anim_update(modelEffect->mAnimations[1]);
    anim_update(modelEffect->mAnimations[2]);
}

void expl_initSplashInstance(ModelEffect *modelEffect) {
    u32 animationFrameCount;

    animationFrameCount = (u32) (anim_getAnimLength(modelEffect->mAnimations[0]) << 4) >> 16;
    anim_setAnim(modelEffect->mAnimations[0], 0);
    modelEffect->mFinishFrameCount = animationFrameCount;
    if (modelEffect->mAnimations[1] != NULL) {
        anim_setAnim(modelEffect->mAnimations[1], 0);
    }
}

void expl_initMissionSplashInstance(ModelEffect *modelEffect) {
    modelEffect->mScale[0] = 0x3d9a;
    modelEffect->mScale[1] = 0x3d9a;
    modelEffect->mScale[2] = 0x3d9a;
    anim_setAnim(modelEffect->mAnimations[0], 0);
    modelEffect->mFinishFrameCount = 0x20;
    if (modelEffect->mAnimations[1] != NULL) {
        anim_setAnim(modelEffect->mAnimations[1], 0);
    }
    ptcm_createEmitter(0x424, &modelEffect->mPos);
    ptcm_createEmitter(0x422, &modelEffect->mPos);
}

// Update of kinds 2 and 4: sets mFinished at mFinishFrameCount, else advances animations 0 and 1.
void expl_updateSplashInstance(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= modelEffect->mFinishFrameCount) {
        modelEffect->mFinished = 1;
        return;
    }
    anim_update(modelEffect->mAnimations[0]);
    if (modelEffect->mAnimations[1] != NULL) {
        anim_update(modelEffect->mAnimations[1]);
    }
}

void expl_initBkWaveInstance(ModelEffect *modelEffect, s32 startEffects) {
    anim_setAnim(modelEffect->mAnimations[0], 0);
    modelEffect->mScale[0] = 0x5800;
    modelEffect->mScale[1] = 0x5800;
    modelEffect->mScale[2] = 0x5800;
    modelEffect->mFinishFrameCount = 0x27;
    anim_setAnim(modelEffect->mAnimations[1], 0);
    if (startEffects == 0) {
        return;
    }
    ptcm_createEmitter(0x40, &modelEffect->mPos);
    ptcm_createEmitter(0x41, &modelEffect->mPos);
}

void expl_updateBkWaveInstance(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= modelEffect->mFinishFrameCount) {
        modelEffect->mFinished = 1;
        return;
    }
    anim_update(modelEffect->mAnimations[0]);
    anim_update(modelEffect->mAnimations[1]);
}

void expl_initBombcore2Instance(ModelEffect *modelEffect, s32 startEffects) {
    anim_setAnim(modelEffect->mAnimations[0], 0);
    anim_setAnim(modelEffect->mAnimations[1], 0);
    anim_setAnim(modelEffect->mAnimations[2], 0);
    modelEffect->mScale[0] = 0x1000;
    modelEffect->mScale[1] = 0x1000;
    modelEffect->mScale[2] = 0x1000;
    if (startEffects == 0) {
        return;
    }
    ptcm_createEmitter(8, &modelEffect->mPos);
    ptcm_createEmitter(9, &modelEffect->mPos);
    ptcm_createEmitter(0xa, &modelEffect->mPos);
}

void expl_updateBombcore2Instance(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= 0x37) {
        modelEffect->mFinished = 1;
        return;
    }
    anim_update(modelEffect->mAnimations[0]);
    anim_update(modelEffect->mAnimations[1]);
    anim_update(modelEffect->mAnimations[2]);
}

// Starts a kind 2 object at position when startModel is set, then the particle effects of expl_sSplashPtclIds.
void expl_spawnSplash(const Vec3 *position, s32 startModel) {
    ModelEffect *modelEffect;
    u16 effectIndex;

    if (expl_sEffectDefs[2].mObjectCount == 0) {
        return;
    }
    effectIndex = 0;
    if (startModel != 0) {
        modelEffect = NNS_FndGetNthListObject(OFFSET_PTR(NNSFndList, expl_sState->mFreeLists, 0x18), 0);
        if (modelEffect != NULL) {
            NNS_FndRemoveListObject(OFFSET_PTR(NNSFndList, expl_sState->mFreeLists, 0x18), modelEffect);
            modelEffect->mFinished = 0;
            modelEffect->mPos = *position;
            modelEffect->mSinceStartFrames = 0;
            modelEffect->mFinishFrameCount = 0;
            modelEffect->mPolygonId = expl_sState->mNextPolygonId;
            modelEffect->mVisible = 1;
            modelEffect->mStart(modelEffect, 0);
            NNS_FndAppendListObject(&expl_sState->mActiveList, modelEffect);
            expl_sState->mNextPolygonId++;
            if (expl_sState->mNextPolygonId > 0xd) {
                expl_sState->mNextPolygonId = 10;
            }
        }
    }
    do {
        if (expl_sSplashPtclIds[effectIndex] >= 0) {
            ptcm_createEmitter(expl_sSplashPtclIds[effectIndex], position);
        }
        effectIndex++;
    } while (effectIndex < 2);
}
