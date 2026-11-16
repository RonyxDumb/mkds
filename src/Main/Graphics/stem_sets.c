#include "Main/Graphics/stem_sets.h"

#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Graphics/timed_quad.h"
#include "registers.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Graphics/stem_set_array.h"
#include "Main/System/heap.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/System/result_archive_path.h"
#include "model_material_set.h"
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
#include "system_state_globals.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "model_draw_state.h"
#include "animation_lookup.h"
#include "print_memory_multibyte_write.h"
#include "matrix_3x3_basic.h"
#include "geometry_matrix_commands.h"
#include "geometry_engine_setup.h"
#include "matrix_4x3_basic.h"
#include "Main/Graphics/model_animation_loop_modes.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/stem_names.h"

const StemSetParams gCountStartStems[3] = {{1, 1, 1, 2, {gStemNameCount, gStemNameCountD}},
                                           {1, 1, 1, 0, {gStemNameStart, NULL}},
                                           {0, 0, 0, 0, {gStemNameEmpty, NULL}}};

const u16 gTimedQuadVertices[12] = {0xf000, 0x1000, 0, 0xf000, 0xf000, 0, 0x1000, 0xf000, 0, 0x1000, 0x1000, 0};
void (*const gTimedQuadUpdateFunctions[1])(TimedQuad *timedQuad) = {UpdateTimedQuad};
void (*const gTimedQuadStartFunctions[1])(TimedQuad *timedQuad) = {StartTimedQuad};
StemSets *g_GlobalBO;

void CreateGlobalBO(void *heap) {
    TimedQuad *timedQuad;

    g_GlobalBO = Mem_AllocateHeap(heap, sizeof(StemSets));
    LoadSeveralBMModels(heap);
    g_GlobalBO->mShownIndex = STEM_SET_NONE;
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x200, 1, &g_GlobalBO->mOrthoMtx);
    timedQuad = &g_GlobalBO->mTimedQuad;
    g_GlobalBO->mTimedQuad.mTimer = 0;
    timedQuad->mAlpha = 0;
    timedQuad->mColor = TIMED_QUAD_COLOR_WHITE;
    timedQuad->mEnabled = FALSE;
}

void LoadModelBMFromMD(void *heap, StemSet *stemSet, const StemSetParams *stemSetParams, u16 setIndex) {
    char fileName[0x80];
    void *lastNsbmdFile;
    u16 nsbmdIndex;
    Nsbmd *nsbmd;
    Nsbmd *nsbcaModel;
    ModelAnimation *nsbcaAnimation;
    u16 nsbcaIndex;
    Nsbmd *nsbmaModel;
    ModelAnimation *nsbmaAnimation;
    u16 nsbmaIndex;
    u16 nsbtpIndex;
    BOOL useOneNsbtpAnimation;

    lastNsbmdFile = NULL;
    stemSet->mNsbmdCount = stemSetParams->mNsbmdCount;
    stemSet->mNsbmds = NULL;
    stemSet->mNsbcaNsbmaNsbtp[0] = stemSet->mNsbcaNsbmaNsbtp[1] = stemSet->mNsbcaNsbmaNsbtp[2] = NULL;
    useOneNsbtpAnimation = FALSE;
    if (stemSetParams->mNsbmdCount != 0) {
        stemSet->mNsbmds = Mem_AllocateHeap(heap, stemSetParams->mNsbmdCount * sizeof(Nsbmd));
    }
    if (stemSetParams->mNsbcaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[0] = Mem_AllocateHeap(heap, stemSetParams->mNsbcaCount * sizeof(ModelAnimation));
    }
    if (stemSetParams->mNsbmaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[1] = Mem_AllocateHeap(heap, stemSetParams->mNsbmaCount * sizeof(ModelAnimation));
    }
    if (stemSetParams->mNsbmdCount == 1 && stemSetParams->mNsbtpCount > 1) {
        stemSet->mNsbcaNsbmaNsbtp[2] = Mem_AllocateHeap(heap, sizeof(ModelAnimation));
        useOneNsbtpAnimation = TRUE;
    } else if (stemSetParams->mNsbtpCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[2] = Mem_AllocateHeap(heap, stemSetParams->mNsbtpCount * sizeof(ModelAnimation));
    }
    for (nsbmdIndex = 0; nsbmdIndex < stemSetParams->mNsbmdCount; nsbmdIndex++) {
        nsbmd = &stemSet->mNsbmds[nsbmdIndex];
        _snprintf(fileName, 0x80, "%s.nsbmd", stemSetParams->mStems[nsbmdIndex]);
        lastNsbmdFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(fileName);
        StructML_LoadModel(nsbmd, lastNsbmdFile);
    }
    for (nsbcaIndex = 0; nsbcaIndex < stemSetParams->mNsbcaCount; nsbcaIndex++) {
        nsbcaModel = &stemSet->mNsbmds[nsbcaIndex];
        nsbcaAnimation = &stemSet->mNsbcaNsbmaNsbtp[0][nsbcaIndex];
        _snprintf(fileName, 0x80, "%s.nsbca", stemSetParams->mStems[nsbcaIndex]);
        StructAM_CreateFrom(0, nsbcaAnimation, nsbcaModel, 1, heap, NULL);
        StructAM_MaybeLoadAnimation(nsbcaAnimation, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(fileName), heap);
        StructAM_SomeFn_MaybeLoadFrame(nsbcaAnimation, 0);
    }
    for (nsbmaIndex = 0; nsbmaIndex < stemSetParams->mNsbmaCount; nsbmaIndex++) {
        nsbmaModel = &stemSet->mNsbmds[nsbmaIndex];
        nsbmaAnimation = &stemSet->mNsbcaNsbmaNsbtp[1][nsbmaIndex];
        _snprintf(fileName, 0x80, "%s.nsbma", stemSetParams->mStems[nsbmaIndex]);
        StructAM_CreateFrom(4, nsbmaAnimation, nsbmaModel, 1, heap, NULL);
        StructAM_MaybeLoadAnimation(nsbmaAnimation, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(fileName), heap);
        StructAM_SomeFn_MaybeLoadFrame(nsbmaAnimation, 0);
    }
    if (useOneNsbtpAnimation != FALSE) {
        nsbcaAnimation = stemSet->mNsbcaNsbmaNsbtp[2];
        StructAM_CreateFrom(2, nsbcaAnimation, stemSet->mNsbmds, stemSetParams->mNsbtpCount, heap, lastNsbmdFile);
        for (nsbtpIndex = 0; nsbtpIndex < stemSetParams->mNsbtpCount; nsbtpIndex++) {
            _snprintf(fileName, 0x80, "%s.nsbtp", stemSetParams->mStems[nsbtpIndex]);
            StructAM_SomeFn_2(nsbcaAnimation, nsbtpIndex,
                                    BTP0_LoadRawData(MaybeLoadBTP0Format(FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(fileName)), 0), 0,
                                    heap);
        }
        StructAM_SomeFn_MaybeLoadFrame(nsbcaAnimation, 0);
    }
}

void LoadSeveralBMModels(void *heap) {
    s16 setIndex;
    StemSet *sourceSet;
    StemSet *copiedSet;

    for (setIndex = 0; setIndex < STEM_SET_FAILED + 1; setIndex++) {
        g_GlobalBO->mSets[setIndex] = NULL;
    }
    if (IsAwardOrStaffRoll_0() != 0) {
        return;
    }
    for (setIndex = 0; setIndex <= STEM_SET_COUNT_COPY; setIndex++) {
        if (setIndex == STEM_SET_COUNT_COPY) {
            g_GlobalBO->mSets[setIndex] = Mem_AllocateHeap(heap, sizeof(StemSet));
            sourceSet = g_GlobalBO->mSets[STEM_SET_COUNT];
            copiedSet = g_GlobalBO->mSets[STEM_SET_COUNT_COPY];
            copiedSet->mNsbmds = sourceSet->mNsbmds;
            copiedSet->mNsbcaNsbmaNsbtp[0] = NULL;
            copiedSet->mNsbcaNsbmaNsbtp[1] = sourceSet->mNsbcaNsbmaNsbtp[1];
            copiedSet->mNsbcaNsbmaNsbtp[2] = sourceSet->mNsbcaNsbmaNsbtp[2];
            copiedSet->mNsbmdCount = sourceSet->mNsbmdCount;
        } else {
            g_GlobalBO->mSets[setIndex] = Mem_AllocateHeap(heap, sizeof(StemSet));
            LoadModelBMFromMD(heap, g_GlobalBO->mSets[setIndex], GetCountStartStem(setIndex), setIndex);
        }
    }
    if (g_GlobalCO->mMode == MODE_BATTLE || g_GlobalCO->mRuleKind == RULE_KIND_WIN_COUNT) {
        g_GlobalBO->mSets[STEM_SET_WIN] = Mem_AllocateHeap(heap, sizeof(StemSet));
        LoadModelBMFromMD(heap, g_GlobalBO->mSets[STEM_SET_WIN], &g_WinModelMD, STEM_SET_WIN);
        g_GlobalBO->mSets[STEM_SET_LOSE] = Mem_AllocateHeap(heap, sizeof(StemSet));
        LoadModelBMFromMD(heap, g_GlobalBO->mSets[STEM_SET_LOSE], &g_LoseModelMD, STEM_SET_LOSE);
    } else if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        g_GlobalBO->mSets[STEM_SET_COMPLETE] = Mem_AllocateHeap(heap, sizeof(StemSet));
        LoadModelBMFromMD(heap, g_GlobalBO->mSets[STEM_SET_COMPLETE], &g_CompleteModelMD, STEM_SET_COMPLETE);
        g_GlobalBO->mSets[STEM_SET_FAILED] = Mem_AllocateHeap(heap, sizeof(StemSet));
        LoadModelBMFromMD(heap, g_GlobalBO->mSets[STEM_SET_FAILED], &g_FailedModelMD, STEM_SET_FAILED);
    } else {
        g_GlobalBO->mSets[STEM_SET_GOAL] = Mem_AllocateHeap(heap, sizeof(StemSet));
        LoadModelBMFromMD(heap, g_GlobalBO->mSets[STEM_SET_GOAL], &g_GoalModelMD, STEM_SET_GOAL);
    }
}

void StartStemSet(s32 setIndex) {
    StemSet *stemSet;
    ModelAnimation *animations;
    u16 nsbmdIndex;
    s32 animationIndex;
    s32 loopCount;

    g_GlobalBO->mSets[STEM_SET_CURRENT] = g_GlobalBO->mSets[setIndex];
    stemSet = g_GlobalBO->mSets[STEM_SET_CURRENT];
    if (stemSet == NULL) {
        g_GlobalBO->mShownIndex = STEM_SET_NONE;
        return;
    }
    g_GlobalBO->mShownIndex = setIndex;
    for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
        if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
            StructAM_SomeFn_MaybeLoadFrame(&stemSet->mNsbcaNsbmaNsbtp[0][nsbmdIndex], 0);
        }
        if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
            StructAM_SomeFn_MaybeLoadFrame(&stemSet->mNsbcaNsbmaNsbtp[1][nsbmdIndex], 0);
        }
        if (setIndex == STEM_SET_COUNT || setIndex == STEM_SET_COUNT_COPY) {
            if (setIndex == STEM_SET_COUNT_COPY) {
                animationIndex = 1;
            } else {
                animationIndex = 0;
            }
            if (setIndex == STEM_SET_COUNT_COPY) {
                loopCount = 5;
            } else {
                loopCount = 3;
            }
            StructAM_SomeFn_MaybeLoadFrame(stemSet->mNsbcaNsbmaNsbtp[2], (u16) animationIndex);
            animations = stemSet->mNsbcaNsbmaNsbtp[0];
            if (animations != NULL) {
                animations[nsbmdIndex].mHead.mLoopMode = MODEL_ANIMATION_LOOP_MODE_LOOP_COUNT;
                animations[nsbmdIndex].mHead.mLoopCount = loopCount;
            }
            animations = stemSet->mNsbcaNsbmaNsbtp[1];
            if (animations != NULL) {
                animations[nsbmdIndex].mHead.mLoopMode = MODEL_ANIMATION_LOOP_MODE_LOOP_COUNT;
                animations[nsbmdIndex].mHead.mLoopCount = loopCount;
            }
        }
    }
}

void UpdateStemSets(void) {
    StemSet *stemSet;
    u16 nsbmdIndex;

    if (g_GlobalBO->mShownIndex == STEM_SET_START || g_GlobalBO->mShownIndex == STEM_SET_GOAL) {
        g_GlobalBO->mShownFrames++;
        if (g_GlobalBO->mShownFrames > g_GlobalBO->mShownFrameCount) {
            g_GlobalBO->mShownIndex = STEM_SET_NONE;
        }
    }
    if (g_GlobalBO->mShownIndex != STEM_SET_NONE) {
        stemSet = g_GlobalBO->mSets[STEM_SET_CURRENT];
        for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
            if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
                StructAM_SomeFn_MaybeMoveNextFrame(stemSet->mNsbcaNsbmaNsbtp[0]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
                StructAM_SomeFn_MaybeMoveNextFrame(stemSet->mNsbcaNsbmaNsbtp[1]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[2] != NULL) {
                StructAM_SomeFn_MaybeMoveNextFrame(stemSet->mNsbcaNsbmaNsbtp[2]);
            }
        }
    }
    if (g_GlobalBO->mTimedQuad.mEnabled != FALSE) {
        g_GlobalBO->mUpdateFunction(&g_GlobalBO->mTimedQuad);
    }
}

void DrawStemSets(void) {
    MtxFx43 identityMatrix;
    MtxFx43 baseTransform;
    Vec3 baseScale;
    Vec3 *baseTranslation;
    u16 nsbmdIndex;
    Nsbmd *nsbmd;

    MTX_Identity43_(&identityMatrix);
    g_GlobalG3.mCameraMtx = identityMatrix;
    if (g_GlobalCO->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (g_GlobalBO->mShownIndex != STEM_SET_NONE) {
        baseTranslation = &baseTransform.mRows[3];
        baseTranslation->x = 0;
        baseTranslation->y = 0;
        baseTranslation->z = 0;
        baseScale = gStemBaseScale;
        baseTransform.mRows[3].y = gStemBaseTranslationY;
        if (g_GlobalBO->mShownIndex == STEM_SET_COUNT_COPY) {
            baseTransform.mRows[3].y = 0x50000;
        }
        MTX_Identity33_(&baseTransform.mAxes);
        for (nsbmdIndex = 0; nsbmdIndex < g_GlobalBO->mSets[STEM_SET_CURRENT]->mNsbmdCount; nsbmdIndex++) {
            nsbmd = &g_GlobalBO->mSets[STEM_SET_CURRENT]->mNsbmds[nsbmdIndex];
            G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x1f6, 0, &g_GlobalG3.mProjMtx);
            g_GlobalG3.mFlag &= ~0x50;
            NNS_G3dGlbSetBaseScale(&baseScale);
            asm_MI_Copy36B(&baseTransform, &g_GlobalG3.mPrmBaseRot);
            g_GlobalG3.mFlag &= ~0xa4;
            NNS_G3dGlbSetBaseTrans(&baseTransform.mRows[3]);
            NNS_G3dGlbFlushP();
            NNS_G3dDraw(&nsbmd->mRenderObj);
        }
    }
    if (g_GlobalBO->mTimedQuad.mEnabled != FALSE) {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 8;
        reg_G3_SPE_EMI = 0x4210;
        reg_G3_DIF_AMB = 0x42100000;
        reg_G3_MTX_MODE = 0;
        G3_LoadMtx44(&g_GlobalBO->mOrthoMtx);
        reg_G3_TEXIMAGE_PARAM = 0x20000000;
        reg_G3_MTX_MODE = 2;
        reg_G3_MTX_IDENTITY = 0;
        DrawTimedQuad(&g_GlobalBO->mTimedQuad);
    }
}

void nullsub_7(void) {}

void SetStemSet(s32 setIndex) {
    if (setIndex == STEM_SET_NONE) {
        g_GlobalBO->mShownIndex = setIndex;
        return;
    }
    if (g_GlobalBO->mShownIndex != setIndex || setIndex == STEM_SET_COUNT_COPY) {
        StartStemSet(setIndex);
    }
    g_GlobalBO->mShownFrames = 0;
    if (g_GlobalBO->mShownIndex == STEM_SET_START || g_GlobalBO->mShownIndex == STEM_SET_GOAL) {
        g_GlobalBO->mShownFrameCount =
            FROM_FIXED12(StructAM_GetFrameCount_Times4096(g_GlobalBO->mSets[STEM_SET_CURRENT]->mNsbcaNsbmaNsbtp[0]));
    }
}

void StartTimedQuad(TimedQuad *timedQuad) {
    timedQuad->mTimer = 0xau;
    timedQuad->mAlpha = 0xcu;
    timedQuad->mColor = TIMED_QUAD_COLOR_WHITE;
    timedQuad->mEnabled = 0x1u;
}

void UpdateTimedQuad(TimedQuad *timedQuad) {
    timedQuad->mAlpha = FROM_FIXED12(MUL_FIXED12_ROUNDED((s32) timedQuad->mTimer << 12, 0x1333));
    timedQuad->mTimer = timedQuad->mTimer - 1;
    if (timedQuad->mTimer <= 0) {
        timedQuad->mEnabled = 0;
    }
}

void WriteQuadVertex(int vertexIndex) {
    reg_G3_VTX_16 = gTimedQuadVertices[vertexIndex * 3] | gTimedQuadVertices[vertexIndex * 3 + 1] << 16;
    reg_G3_VTX_16 = gTimedQuadVertices[vertexIndex * 3 + 2];
}

void DrawTimedQuad(TimedQuad *timedQuad) {
    u32 *scaleRegister;
    u32 *beginVtxsRegister;
    scaleRegister = ((u32 *) &reg_G3_MTX_SCALE);
    reg_G3_POLYGON_ATTR = (0x090000c0u) | timedQuad->mAlpha << 0x10;
    *scaleRegister = 0x8c000;
    *scaleRegister = 0x6e000;
    beginVtxsRegister = ((u32 *) &reg_G3_BEGIN_VTXS);
    *scaleRegister = 0xa000;
    *beginVtxsRegister = 1;
    reg_G3_COLOR = timedQuad->mColor;
    WriteQuadVertex(0);
    WriteQuadVertex(1);
    WriteQuadVertex(2);
    WriteQuadVertex(3);
    reg_G3_END_VTXS = 0;
}

void StartTimedQuadFromTable(u32 tableIndex) {
    g_GlobalBO->mStartFunction = gTimedQuadStartFunctions[tableIndex];
    g_GlobalBO->mUpdateFunction = gTimedQuadUpdateFunctions[tableIndex];
    g_GlobalBO->mStartFunction(&g_GlobalBO->mTimedQuad);
}
