#include "Main/Graphics/model_effects.h"
#include "Main/System/heap.h"
#include "Main/Graphics/effects.h"
#include "model_set_resource_lookup.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "model_material_set.h"
#include "model_texture_bind.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "linked_list_init.h"
#include "matrix_4x3_basic.h"
#include "geometry_matrix_commands.h"
#include "linked_list_ops.h"
#include "registers.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "Main/Save/ghost_record_file.h"

char g_str_RaceEffect_spa[15] = "RaceEffect.spa";
char g_path_effect_RaceEffectFogOff_spa[29] = "/effect/RaceEffectFogOff.spa";
char g_path_data_MissionRun_MissionEffect_spa[35] = "/data/MissionRun/MissionEffect.spa";
ModelEffectKind g_ExplosionManagers[MODEL_EFFECT_KIND_COUNT] = {
    {BOMBCORE_OBJECT_COUNT,
     1,
     1,
     1,
     ExplosionKind_Bombcore_CreateFn,
     ExplosionKind_Bombcore_UpdateFn,
     0xb8,
     {NULL, NULL, NULL, NULL}},
    {BOMBCORE2_OBJECT_COUNT,
     1,
     1,
     1,
     ExplosionKind_Bombcore2_CreateFn,
     ExplosionKind_Bombcore2_UpdateFn,
     0xb8,
     {NULL, NULL, NULL, NULL}},
    {0,
     1,
     0,
     0,
     (void (*)(ModelEffect *, s32)) ExplosionKind_Splash_CreateFn,
     ExplosionKind_Splash_MissionSplash_UpdateFn,
     0xb8,
     {NULL, NULL, NULL, NULL}},
    {0, 1, 0, 0, ExplosionKind_BakubakuWave_CreateFn, ExplosionKind_BakubakuWave_UpdateFn, 0xb8, {NULL, NULL, NULL, NULL}},
    {0,
     1,
     0,
     0,
     (void (*)(ModelEffect *, s32)) ExplosionKind_MissionSplash_CreateFn,
     ExplosionKind_Splash_MissionSplash_UpdateFn,
     0xb8,
     {NULL, NULL, NULL, NULL}}};
s32 gKartWaterSplashCreated;
ModelEffects *g_GlobalRT;
s32 gKartWaterSplashEffectIds[2];

void UpdatePosStrip(PosStrip *posStrip) {
    PosStripPoint *point;
    PosStripPoint *nextPoint;
    PosStripPoint *newPoint;
    u32 expired;

    point = IntrusiveListWrapper_NextItem(&posStrip->mPoints, NULL);
    if (point != NULL) {
        do {
            nextPoint = IntrusiveListWrapper_NextItem(&posStrip->mPoints, point);
            point->mSinceAddedFrames = point->mSinceAddedFrames + 1;
            if (point->mSinceAddedFrames > gPosStripMaxAgeFrames) {
                expired = 1;
            } else {
                point->mHeight = point->mHeight - gPosStripHeightDecreasePerFrame;
                expired = 0;
            }
            if (expired != 0) {
                IntrusiveListWrapper_RemoveItem(&posStrip->mPoints, point);
                IntrusiveListWrapper_InsertLast(&gPosStrips->mLists[2], point);
                if (nextPoint == NULL) {
                    break;
                }
                point = nextPoint;
            }
            point = IntrusiveListWrapper_NextItem(&posStrip->mPoints, point);
        } while (point != NULL);
    }
    if (posStrip->mStopped == 0) {
        newPoint = IntrusiveListWrapper_GetAtIndex(&gPosStrips->mLists[2], 0);
        IntrusiveListWrapper_RemoveItem(&gPosStrips->mLists[2], newPoint);
        IntrusiveListWrapper_InsertLast(&posStrip->mPoints, newPoint);
        gSetPosStripPointFunction(newPoint, posStrip);
        return;
    }
    if (posStrip->mPoints.mCount != 0) {
        return;
    }
    IntrusiveListWrapper_RemoveItem(&gPosStrips->mLists[0], posStrip);
    IntrusiveListWrapper_InsertLast(&gPosStrips->mLists[1], posStrip);
}

void DrawPosStripQuad(const MtxFx43 *viewMatrix, PosStripPoint *firstPoint, PosStripPoint *secondPoint,
                      PosStripTexture *posStripTexture) {
    MtxFx43 firstMatrix;
    MtxFx43 secondMatrix;

    MTX_Scale43__from_thumb(&firstMatrix, 0x1000, firstPoint->mHeight, 0x1000);
    MTX_Scale43__from_thumb(&secondMatrix, 0x1000, secondPoint->mHeight, 0x1000);
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

void SetSomeAwardModeProperty(s32 drawEnabled) {
    if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        gPosStripDrawEnabled = drawEnabled;
    }
}

void LoadEffectMapObjModels(void *heap) {
    u16 kindIndex;
    void *modelFile;
    void *nsbcaFile;
    void *nsbmaFile;
    void *nsbtaFile;
    ModelEffectKind *firstKind;
    ModelEffectKind *secondKind;

    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        heap = g_OverlayManager->mExpHeap;
    }
    g_GlobalRT = Mem_AllocateHeap(heap, sizeof(ModelEffects));
    IntrusiveListWrapper_InitializeEmpty(&g_GlobalRT->mActiveList, 0);
    for (kindIndex = 0; kindIndex < MODEL_EFFECT_KIND_COUNT; kindIndex++) {
        IntrusiveListWrapper_InitializeEmpty(&g_GlobalRT->mFreeLists[kindIndex], 0);
    }
    firstKind = g_ExplosionManagers;
    secondKind = &g_ExplosionManagers[MODEL_EFFECT_BOMBCORE2];
    if (g_GlobalCO->mMode == MODE_WIFI) {
        firstKind->mObjectCount = BOMBCORE_OBJECT_COUNT_WIFI;
        secondKind->mObjectCount = BOMBCORE2_OBJECT_COUNT_WIFI;
    } else {
        firstKind->mObjectCount = BOMBCORE_OBJECT_COUNT;
        secondKind->mObjectCount = BOMBCORE2_OBJECT_COUNT;
    }
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        firstKind->mObjectCount = BOMBCORE_OBJECT_COUNT_MISSION_RUN;
    }
    MaybeLoadExplosionManager(&g_ExplosionManagers[MODEL_EFFECT_KART_WATER_SPLASH], KART_WATER_SPLASH_OBJECT_COUNT);
    MaybeLoadExplosionManager(&g_ExplosionManagers[MODEL_EFFECT_DONKETU_WATER_SPLASH], DONKETU_WATER_SPLASH_OBJECT_COUNT);
    MaybeCheckMapObjBkWaveNsbcaNsbma();
    CreateExplosionInstances(heap);
    modelFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore/bombcore.nsbmd");
    nsbcaFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore/bombcore.nsbca");
    nsbmaFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore/bombcore.nsbma");
    nsbtaFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore/bombcore.nsbta");
    MaybeLoadSomeExplosion(heap, MODEL_EFFECT_BOMBCORE, modelFile, nsbcaFile, nsbmaFile, nsbtaFile);
    modelFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore2/bombcore2.nsbmd");
    nsbcaFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore2/bombcore2.nsbca");
    nsbmaFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore2/bombcore2.nsbma");
    nsbtaFile = FindFileBuffer_MAR_EFT_from_thumb("/effect/bombcore2/bombcore2.nsbta");
    MaybeLoadSomeExplosion(heap, MODEL_EFFECT_BOMBCORE2, modelFile, nsbcaFile, nsbmaFile, nsbtaFile);
    MaybeLoadSomeExplosion(heap, MODEL_EFFECT_KART_WATER_SPLASH, GetExplosionSplashWaveNsbmd_from_thumb(), GetExplosionSplashWaveNsbca_from_thumb(),
                         GetExplosionSplashWaveNsbma_from_thumb(), NULL);
    MaybeLoadSomeExplosion(heap, MODEL_EFFECT_DONKETU_WATER_SPLASH, GetExplosionSplashWaveNsbmd_from_thumb(), GetExplosionSplashWaveNsbca_from_thumb(),
                         GetExplosionSplashWaveNsbma_from_thumb(), NULL);
    if (g_GlobalCO->mCourseId == COURSE_ID_OLD_HYUDORO_64) {
        MaybeLoadSomeExplosion(heap, MODEL_EFFECT_BK_WAVE, GetExplosionSplashWaveNsbmd_from_thumb(),
                             FindFileBuffer_CRS_CST_from_thumb("/MapObj/bk_wave.nsbca"), FindFileBuffer_CRS_CST_from_thumb("/MapObj/bk_wave.nsbma"), NULL);
    }
    g_GlobalRT->mNextPolygonId = MODEL_EFFECT_POLYGON_ID_FIRST;
}

// Starts a pooled object of the given kind at position; startEffects goes to its start function. NULL if none is free.
ModelEffect *MaybeRecreateExplosionInstance(u32 kind, const Vec3 *position, s32 startEffects) {
    ModelEffect *modelEffect;

    modelEffect = IntrusiveListWrapper_GetAtIndex(&g_GlobalRT->mFreeLists[kind], 0);
    if (modelEffect != NULL) {
        IntrusiveListWrapper_RemoveItem(&g_GlobalRT->mFreeLists[kind], modelEffect);
        modelEffect->mFinished = 0;
        modelEffect->mPos = *position;
        modelEffect->mSinceStartFrames = 0;
        modelEffect->mFinishFrameCount = 0;
        modelEffect->mPolygonId = g_GlobalRT->mNextPolygonId;
        modelEffect->mVisible = 1;
        modelEffect->mStart(modelEffect, startEffects);
        IntrusiveListWrapper_InsertLast(&g_GlobalRT->mActiveList, modelEffect);
        g_GlobalRT->mNextPolygonId++;
        if (g_GlobalRT->mNextPolygonId > MODEL_EFFECT_POLYGON_ID_LAST) {
            g_GlobalRT->mNextPolygonId = MODEL_EFFECT_POLYGON_ID_FIRST;
        }
    }
    return modelEffect;
}

void UpdateExplosionInstances(void) {
    ModelEffect *modelEffect;

    modelEffect = IntrusiveListWrapper_NextItem(&g_GlobalRT->mActiveList, NULL);
    if (modelEffect == NULL) {
        return;
    }
    do {
        modelEffect->mUpdate(modelEffect);
        modelEffect->mSinceStartFrames = modelEffect->mSinceStartFrames + 1;
        if (modelEffect->mFinished == 1) {
            IntrusiveListWrapper_RemoveItem(&g_GlobalRT->mActiveList, modelEffect);
            IntrusiveListWrapper_InsertLast(&g_GlobalRT->mFreeLists[modelEffect->mKind], modelEffect);
        }
        modelEffect = IntrusiveListWrapper_NextItem(&g_GlobalRT->mActiveList, modelEffect);
    } while (modelEffect != NULL);
}

void DrawModelEffects(void) {
    MtxFx43 drawMatrix;
    ModelEffect *modelEffect;

    MTX_Identity43_(&drawMatrix);
    modelEffect = IntrusiveListWrapper_NextItem(&g_GlobalRT->mActiveList, NULL);
    if (modelEffect == NULL) {
        return;
    }
    do {
        if (modelEffect->mVisible != 0) {
            drawMatrix.mRows[3].x = modelEffect->mPos.x >> 4;
            drawMatrix.mRows[3].y = modelEffect->mPos.y >> 4;
            drawMatrix.mRows[3].z = modelEffect->mPos.z >> 4;
            StructML_MaybeProcessModelAnimations(&modelEffect->mNsbmd, modelEffect->mPolygonId);
            DrawNsbmdWithMatrix(&modelEffect->mNsbmd, &drawMatrix, &modelEffect->mScale);
        }
        modelEffect = IntrusiveListWrapper_NextItem(&g_GlobalRT->mActiveList, modelEffect);
    } while (modelEffect != NULL);
}

// Row kindRow gets objectCount objects only when the water_efct model exists; its flags say which animations exist.
void MaybeLoadExplosionManager(ModelEffectKind *kindRow, s32 objectCount) {
    void *waterEfctNsbmdFile;
    void *waterEfctNsbcaFile;
    void *waterEfctNsbmaFile;

    waterEfctNsbmdFile = GetExplosionSplashWaveNsbmd_from_thumb();
    gKartWaterSplashCreated = 0;
    if (waterEfctNsbmdFile != 0) {
        waterEfctNsbcaFile = GetExplosionSplashWaveNsbca_from_thumb();
        waterEfctNsbmaFile = GetExplosionSplashWaveNsbma_from_thumb();
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
        gKartWaterSplashEffectIds[0] = -1;
        gKartWaterSplashEffectIds[1] = -1;
    }
}

// The bk_wave row gets one object only when the water_efct model exists; its animation flags say which bk_wave files
// exist.
void MaybeCheckMapObjBkWaveNsbcaNsbma(void) {
    ModelEffectKind *kindRow;
    void *bkWaveNsbcaFile;
    void *bkWaveNsbmaFile;

    kindRow = &g_ExplosionManagers[MODEL_EFFECT_BK_WAVE];
    if (GetExplosionSplashWaveNsbmd_from_thumb() != 0) {
        bkWaveNsbcaFile = FindFileBuffer_CRS_CST_from_thumb("/MapObj/bk_wave.nsbca");
        bkWaveNsbmaFile = FindFileBuffer_CRS_CST_from_thumb("/MapObj/bk_wave.nsbma");
        kindRow->mObjectCount = BK_WAVE_OBJECT_COUNT;
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

void CreateExplosionInstances(void *heap) {
    u16 kindIndex;
    u16 objectIndex;
    ModelEffectKind *kindRow;
    ModelEffect *modelEffect;
    s32 scale;

    for (kindIndex = 0; kindIndex < MODEL_EFFECT_KIND_COUNT; kindIndex++) {
        kindRow = &g_ExplosionManagers[kindIndex];
        if (kindRow->mObjectCount == 0) {
            continue;
        }
        g_GlobalRT->mObjects[kindIndex] = Mem_AllocateHeap(heap, kindRow->mObjectCount << 2);
        for (objectIndex = 0; objectIndex < kindRow->mObjectCount; objectIndex++) {
            modelEffect = Mem_AllocateHeap(heap, kindRow->mObjectSize);
            g_GlobalRT->mObjects[kindIndex][objectIndex] = modelEffect;
            if (kindRow->mUseNsbca == FALSE) {
                modelEffect->mAnimations[0] = NULL;
            } else {
                modelEffect->mAnimations[0] = Mem_AllocateHeap(heap, sizeof(ModelAnimation));
            }
            if (kindRow->mUseNsbma == FALSE) {
                modelEffect->mAnimations[1] = NULL;
            } else {
                modelEffect->mAnimations[1] = Mem_AllocateHeap(heap, sizeof(ModelAnimation));
            }
            if (kindRow->mUseNsbta == 0) {
                modelEffect->mAnimations[2] = NULL;
            } else {
                modelEffect->mAnimations[2] = Mem_AllocateHeap(heap, sizeof(ModelAnimation));
            }
            modelEffect->mKind = kindIndex;
            modelEffect->mStart = kindRow->mStart;
            modelEffect->mUpdate = kindRow->mUpdate;
            IntrusiveListWrapper_InsertLast(&g_GlobalRT->mFreeLists[kindIndex], modelEffect);
            if (kindIndex == 2) {
                scale = g_GlobalCO->mCourseId == COURSE_ID_OLD_KOOPA_AGB ? 0xb33 : 0x1000;
                modelEffect->mScale.x = scale;
                modelEffect->mScale.y = scale;
                modelEffect->mScale.z = scale;
            }
        }
    }
}

// Builds the model and animation objects of every pooled object of the kind from modelFile and the animation files.
void MaybeLoadSomeExplosion(void *heap, s32 kind, NNSG3dResFileHeader *modelFile, void *nsbcaFile, void *nsbmaFile,
                          void *nsbtaFile) {
    u16 objectIndex;
    NNSG3dResMdlSet *modelSet;
    NNSG3dResDictEntryHeader *entries;
    ModelAnimation *animation;
    NNSG3dResMdl *resMdl;
    ModelEffect *modelEffect;
    ModelEffectKind *kindRow;
    u32 fogEnabled;

    kindRow = &g_ExplosionManagers[kind];
    fogEnabled = 1;
    if (g_GlobalCO->mCourseId == COURSE_ID_MANSION || g_GlobalCO->mCourseId == COURSE_ID_RAINBOW) {
        fogEnabled = 0;
    }
    if (kindRow->mObjectCount == 0) {
        return;
    }
    if (kind != MODEL_EFFECT_BK_WAVE) {
        LoadedModelTexture_SomeFn(&kindRow->mResFileEntry, modelFile, modelFile);
    }
    if (kind == MODEL_EFFECT_KART_WATER_SPLASH) {
        gKartWaterSplashCreated = 1;
    }
    modelSet = Nsbmd_GetMDL0Block(modelFile);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &modelSet->mDict, modelSet->mDict.mOfsEntry);
    resMdl = OFFSET_PTR(NNSG3dResMdl, modelSet, *DICT_ENTRY(u32, entries, 0));
    for (objectIndex = 0; objectIndex < kindRow->mObjectCount; objectIndex++) {
        modelEffect = g_GlobalRT->mObjects[kind][objectIndex];
        StructML_SomeFn(&modelEffect->mNsbmd, resMdl);
        NNS_G3dMdlSetMdlFogEnableFlagAll(modelEffect->mNsbmd.mResMdl, fogEnabled);
        animation = modelEffect->mAnimations[0];
        if (animation != NULL) {
            if (nsbcaFile != NULL) {
                StructAM_CreateFrom(0, animation, &modelEffect->mNsbmd, 1, heap, modelFile);
                StructAM_MaybeLoadAnimation(animation, nsbcaFile, heap);
            } else {
                animation->mAnmObjCount = 0;
            }
            if (kind == MODEL_EFFECT_KART_WATER_SPLASH) {
                if (FROM_FIXED12(StructAM_GetFrameCount_Times4096(modelEffect->mAnimations[0])) == 0x20) {
                    gKartWaterSplashEffectIds[0] = 0x37;
                    gKartWaterSplashEffectIds[1] = 0x38;
                } else {
                    gKartWaterSplashEffectIds[0] = 0x39;
                    gKartWaterSplashEffectIds[1] = -1;
                }
            }
        }
        animation = modelEffect->mAnimations[1];
        if (animation != NULL) {
            if (nsbmaFile != NULL) {
                StructAM_CreateFrom(4, animation, &modelEffect->mNsbmd, 1, heap, modelFile);
                StructAM_MaybeLoadAnimation(animation, nsbmaFile, heap);
            } else {
                animation->mAnmObjCount = 0;
            }
        }
        animation = modelEffect->mAnimations[2];
        if (animation != NULL) {
            if (nsbtaFile == NULL) {
                animation->mAnmObjCount = 0;
            } else {
                StructAM_CreateFrom(1, animation, &modelEffect->mNsbmd, 1, heap, modelFile);
                StructAM_MaybeLoadAnimation(animation, nsbtaFile, heap);
            }
        }
    }
}

void ExplosionKind_Bombcore_CreateFn(ModelEffect *modelEffect, s32 startEffects) {
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[0], 0);
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[1], 0);
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[2], 0);
    modelEffect->mScale.x = 0xab8;
    modelEffect->mScale.y = 0xab8;
    modelEffect->mScale.z = 0xab8;
    if (startEffects == 0) {
        return;
    }
    StartEffect(0x22, &modelEffect->mPos);
    StartEffect(1, &modelEffect->mPos);
    StartEffect(2, &modelEffect->mPos);
}

void ExplosionKind_Bombcore_UpdateFn(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames == MODEL_EFFECT_BOMBCORE_PARTICLE_FRAME) {
        StartEffect(3, &modelEffect->mPos);
        return;
    }
    if (modelEffect->mSinceStartFrames >= MODEL_EFFECT_BOMBCORE_END_FRAME) {
        modelEffect->mFinished = 1;
        return;
    }
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[0]);
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[1]);
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[2]);
}

void ExplosionKind_Splash_CreateFn(ModelEffect *modelEffect) {
    u32 animationFrameCount;

    animationFrameCount = (u32) (StructAM_GetFrameCount_Times4096(modelEffect->mAnimations[0]) << 4) >> 16;
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[0], 0);
    modelEffect->mFinishFrameCount = animationFrameCount;
    if (modelEffect->mAnimations[1] != NULL) {
        StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[1], 0);
    }
}

void ExplosionKind_MissionSplash_CreateFn(ModelEffect *modelEffect) {
    modelEffect->mScale.x = 0x3d9a;
    modelEffect->mScale.y = 0x3d9a;
    modelEffect->mScale.z = 0x3d9a;
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[0], 0);
    modelEffect->mFinishFrameCount = MODEL_EFFECT_DONKETU_SPLASH_FINISH_FRAMES;
    if (modelEffect->mAnimations[1] != NULL) {
        StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[1], 0);
    }
    StartEffect(0x424, &modelEffect->mPos);
    StartEffect(0x422, &modelEffect->mPos);
}

// Update of the kart and Donketu splash kinds: sets mFinished at mFinishFrameCount, else advances animations 0 and 1.
void ExplosionKind_Splash_MissionSplash_UpdateFn(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= modelEffect->mFinishFrameCount) {
        modelEffect->mFinished = 1;
        return;
    }
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[0]);
    if (modelEffect->mAnimations[1] != NULL) {
        StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[1]);
    }
}

void ExplosionKind_BakubakuWave_CreateFn(ModelEffect *modelEffect, s32 startEffects) {
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[0], 0);
    modelEffect->mScale.x = 0x5800;
    modelEffect->mScale.y = 0x5800;
    modelEffect->mScale.z = 0x5800;
    modelEffect->mFinishFrameCount = MODEL_EFFECT_BK_WAVE_FINISH_FRAMES;
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[1], 0);
    if (startEffects == 0) {
        return;
    }
    StartEffect(0x40, &modelEffect->mPos);
    StartEffect(0x41, &modelEffect->mPos);
}

void ExplosionKind_BakubakuWave_UpdateFn(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= modelEffect->mFinishFrameCount) {
        modelEffect->mFinished = 1;
        return;
    }
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[0]);
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[1]);
}

void ExplosionKind_Bombcore2_CreateFn(ModelEffect *modelEffect, s32 startEffects) {
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[0], 0);
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[1], 0);
    StructAM_SomeFn_MaybeLoadFrame(modelEffect->mAnimations[2], 0);
    modelEffect->mScale.x = 0x1000;
    modelEffect->mScale.y = 0x1000;
    modelEffect->mScale.z = 0x1000;
    if (startEffects == 0) {
        return;
    }
    StartEffect(8, &modelEffect->mPos);
    StartEffect(9, &modelEffect->mPos);
    StartEffect(0xa, &modelEffect->mPos);
}

void ExplosionKind_Bombcore2_UpdateFn(ModelEffect *modelEffect) {
    if (modelEffect->mSinceStartFrames >= MODEL_EFFECT_BOMBCORE_END_FRAME) {
        modelEffect->mFinished = 1;
        return;
    }
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[0]);
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[1]);
    StructAM_SomeFn_MaybeMoveNextFrame(modelEffect->mAnimations[2]);
}

// Starts a kart splash object at position when startModel is set, then the particle effects of
// gKartWaterSplashEffectIds.
void StartKartWaterSplashEffects(const Vec3 *position, s32 startModel) {
    ModelEffect *modelEffect;
    u16 effectIndex;

    if (g_ExplosionManagers[MODEL_EFFECT_KART_WATER_SPLASH].mObjectCount == 0) {
        return;
    }
    effectIndex = 0;
    if (startModel != 0) {
        modelEffect = IntrusiveListWrapper_GetAtIndex(
            OFFSET_PTR(NNSFndList, g_GlobalRT->mFreeLists, MODEL_EFFECT_KART_WATER_SPLASH * sizeof(NNSFndList)), 0);
        if (modelEffect != NULL) {
            IntrusiveListWrapper_RemoveItem(
                OFFSET_PTR(NNSFndList, g_GlobalRT->mFreeLists, MODEL_EFFECT_KART_WATER_SPLASH * sizeof(NNSFndList)),
                modelEffect);
            modelEffect->mFinished = 0;
            modelEffect->mPos = *position;
            modelEffect->mSinceStartFrames = 0;
            modelEffect->mFinishFrameCount = 0;
            modelEffect->mPolygonId = g_GlobalRT->mNextPolygonId;
            modelEffect->mVisible = 1;
            modelEffect->mStart(modelEffect, 0);
            IntrusiveListWrapper_InsertLast(&g_GlobalRT->mActiveList, modelEffect);
            g_GlobalRT->mNextPolygonId++;
            if (g_GlobalRT->mNextPolygonId > MODEL_EFFECT_POLYGON_ID_LAST) {
                g_GlobalRT->mNextPolygonId = MODEL_EFFECT_POLYGON_ID_FIRST;
            }
        }
    }
    do {
        if (gKartWaterSplashEffectIds[effectIndex] >= 0) {
            StartEffect(gKartWaterSplashEffectIds[effectIndex], position);
        }
        effectIndex++;
    } while (effectIndex < 2);
}
