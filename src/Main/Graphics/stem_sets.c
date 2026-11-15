#include "Main/Graphics/stem_sets.h"

#include "Main/MapObjects/data_0217b000.h"
#include "Main/Graphics/code_02089d70.h"
#include "registers.h"
#include "Main/MapObjects/data_02155000.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Graphics/code_02089fa0.h"
#include "Main/System/heap.h"
#include "ITCM/code_01ff8000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/System/result_archive_path.h"
#include "code_02012b30.h"
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
#include "data_02170000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02134398.h"
#include "fx_mtx33.h"
#include "g3imm.h"
#include "code_0214a748.h"
#include "fx_mtx43.h"
#include "Main/Graphics/data_02087000.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/stem_names.h"

const StemSetParams gCountStartStems[3] = {{1, 1, 1, 2, {gStemNameCount, gStemNameCountD}},
                                           {1, 1, 1, 0, {gStemNameStart, NULL}},
                                           {0, 0, 0, 0, {gStemNameEmpty, NULL}}};

const u16 gTimedQuadVertices[12] = {0xf000, 0x1000, 0, 0xf000, 0xf000, 0, 0x1000, 0xf000, 0, 0x1000, 0x1000, 0};
void (*const gTimedQuadUpdateFunctions[1])(TimedQuad *a) = {UpdateTimedQuad};
void (*const gTimedQuadStartFunctions[1])(TimedQuad *a) = {StartTimedQuad};
StemSets *gStemSets;

void InitStemSets(void *heap) {
    TimedQuad *timedQuad;

    gStemSets = HeapAlloc(heap, sizeof(StemSets));
    InitStemSetArray(heap);
    gStemSets->mShownIndex = STEM_SET_NONE;
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x200, 1, &gStemSets->mOrthoMtx);
    timedQuad = &gStemSets->mTimedQuad;
    gStemSets->mTimedQuad.mTimer = 0;
    timedQuad->mAlpha = 0;
    timedQuad->mColor = 0x7fff;
    timedQuad->mEnabled = FALSE;
}

void InitNsbmdNsbcaNsbmaNsbtp(void *heap, StemSet *stemSet, const StemSetParams *stemSetParams, u16 setIndex) {
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
        stemSet->mNsbmds = HeapAlloc(heap, stemSetParams->mNsbmdCount * sizeof(Nsbmd));
    }
    if (stemSetParams->mNsbcaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[0] = HeapAlloc(heap, stemSetParams->mNsbcaCount * sizeof(ModelAnimation));
    }
    if (stemSetParams->mNsbmaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[1] = HeapAlloc(heap, stemSetParams->mNsbmaCount * sizeof(ModelAnimation));
    }
    if (stemSetParams->mNsbmdCount == 1 && stemSetParams->mNsbtpCount > 1) {
        stemSet->mNsbcaNsbmaNsbtp[2] = HeapAlloc(heap, sizeof(ModelAnimation));
        useOneNsbtpAnimation = TRUE;
    } else if (stemSetParams->mNsbtpCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[2] = HeapAlloc(heap, stemSetParams->mNsbtpCount * sizeof(ModelAnimation));
    }
    for (nsbmdIndex = 0; nsbmdIndex < stemSetParams->mNsbmdCount; nsbmdIndex++) {
        nsbmd = &stemSet->mNsbmds[nsbmdIndex];
        snprintf(fileName, 0x80, "%s.nsbmd", stemSetParams->mStems[nsbmdIndex]);
        lastNsbmdFile = FindSceneFile(fileName);
        InitNsbmdWithoutCullSwap(nsbmd, lastNsbmdFile);
    }
    for (nsbcaIndex = 0; nsbcaIndex < stemSetParams->mNsbcaCount; nsbcaIndex++) {
        nsbcaModel = &stemSet->mNsbmds[nsbcaIndex];
        nsbcaAnimation = &stemSet->mNsbcaNsbmaNsbtp[0][nsbcaIndex];
        snprintf(fileName, 0x80, "%s.nsbca", stemSetParams->mStems[nsbcaIndex]);
        InitModelAnimation(0, nsbcaAnimation, nsbcaModel, 1, heap, NULL);
        InitModelAnimationEntries(nsbcaAnimation, FindSceneFile(fileName), heap);
        SetModelAnimation(nsbcaAnimation, 0);
    }
    for (nsbmaIndex = 0; nsbmaIndex < stemSetParams->mNsbmaCount; nsbmaIndex++) {
        nsbmaModel = &stemSet->mNsbmds[nsbmaIndex];
        nsbmaAnimation = &stemSet->mNsbcaNsbmaNsbtp[1][nsbmaIndex];
        snprintf(fileName, 0x80, "%s.nsbma", stemSetParams->mStems[nsbmaIndex]);
        InitModelAnimation(4, nsbmaAnimation, nsbmaModel, 1, heap, NULL);
        InitModelAnimationEntries(nsbmaAnimation, FindSceneFile(fileName), heap);
        SetModelAnimation(nsbmaAnimation, 0);
    }
    if (useOneNsbtpAnimation != FALSE) {
        nsbcaAnimation = stemSet->mNsbcaNsbmaNsbtp[2];
        InitModelAnimation(2, nsbcaAnimation, stemSet->mNsbmds, stemSetParams->mNsbtpCount, heap, lastNsbmdFile);
        for (nsbtpIndex = 0; nsbtpIndex < stemSetParams->mNsbtpCount; nsbtpIndex++) {
            snprintf(fileName, 0x80, "%s.nsbtp", stemSetParams->mStems[nsbtpIndex]);
            InitModelAnimationEntry(nsbcaAnimation, nsbtpIndex,
                                    NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(FindSceneFile(fileName)), 0), 0,
                                    heap);
        }
        SetModelAnimation(nsbcaAnimation, 0);
    }
}

void InitStemSetArray(void *heap) {
    s16 setIndex;
    StemSet *sourceSet;
    StemSet *copiedSet;

    for (setIndex = 0; setIndex < STEM_SET_FAILED + 1; setIndex++) {
        gStemSets->mSets[setIndex] = NULL;
    }
    if (IsRaceAwardOrStaffRoll() != 0) {
        return;
    }
    for (setIndex = 0; setIndex <= STEM_SET_COUNT_COPY; setIndex++) {
        if (setIndex == STEM_SET_COUNT_COPY) {
            gStemSets->mSets[setIndex] = HeapAlloc(heap, sizeof(StemSet));
            sourceSet = gStemSets->mSets[STEM_SET_COUNT];
            copiedSet = gStemSets->mSets[STEM_SET_COUNT_COPY];
            copiedSet->mNsbmds = sourceSet->mNsbmds;
            copiedSet->mNsbcaNsbmaNsbtp[0] = NULL;
            copiedSet->mNsbcaNsbmaNsbtp[1] = sourceSet->mNsbcaNsbmaNsbtp[1];
            copiedSet->mNsbcaNsbmaNsbtp[2] = sourceSet->mNsbcaNsbmaNsbtp[2];
            copiedSet->mNsbmdCount = sourceSet->mNsbmdCount;
        } else {
            gStemSets->mSets[setIndex] = HeapAlloc(heap, sizeof(StemSet));
            InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[setIndex], GetCountStartStem(setIndex), setIndex);
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mRuleKind == RULE_KIND_WIN_COUNT) {
        gStemSets->mSets[STEM_SET_WIN] = HeapAlloc(heap, sizeof(StemSet));
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[STEM_SET_WIN], &gWinStems, STEM_SET_WIN);
        gStemSets->mSets[STEM_SET_LOSE] = HeapAlloc(heap, sizeof(StemSet));
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[STEM_SET_LOSE], &gLoseStems, STEM_SET_LOSE);
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        gStemSets->mSets[STEM_SET_COMPLETE] = HeapAlloc(heap, sizeof(StemSet));
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[STEM_SET_COMPLETE], &gCompleteStems, STEM_SET_COMPLETE);
        gStemSets->mSets[STEM_SET_FAILED] = HeapAlloc(heap, sizeof(StemSet));
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[STEM_SET_FAILED], &gFailedStems, STEM_SET_FAILED);
    } else {
        gStemSets->mSets[STEM_SET_GOAL] = HeapAlloc(heap, sizeof(StemSet));
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[STEM_SET_GOAL], &gGoalStems, STEM_SET_GOAL);
    }
}

void StartStemSet(s32 setIndex) {
    StemSet *stemSet;
    ModelAnimation *animations;
    u16 nsbmdIndex;
    s32 animationIndex;
    s32 loopCount;

    gStemSets->mSets[STEM_SET_CURRENT] = gStemSets->mSets[setIndex];
    stemSet = gStemSets->mSets[STEM_SET_CURRENT];
    if (stemSet == NULL) {
        gStemSets->mShownIndex = STEM_SET_NONE;
        return;
    }
    gStemSets->mShownIndex = setIndex;
    for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
        if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
            SetModelAnimation(&stemSet->mNsbcaNsbmaNsbtp[0][nsbmdIndex], 0);
        }
        if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
            SetModelAnimation(&stemSet->mNsbcaNsbmaNsbtp[1][nsbmdIndex], 0);
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
            SetModelAnimation(stemSet->mNsbcaNsbmaNsbtp[2], (u16) animationIndex);
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

    if (gStemSets->mShownIndex == STEM_SET_START || gStemSets->mShownIndex == STEM_SET_GOAL) {
        gStemSets->mShownFrames++;
        if (gStemSets->mShownFrames > gStemSets->mShownFrameCount) {
            gStemSets->mShownIndex = STEM_SET_NONE;
        }
    }
    if (gStemSets->mShownIndex != STEM_SET_NONE) {
        stemSet = gStemSets->mSets[STEM_SET_CURRENT];
        for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
            if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
                AdvanceModelAnimation(stemSet->mNsbcaNsbmaNsbtp[0]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
                AdvanceModelAnimation(stemSet->mNsbcaNsbmaNsbtp[1]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[2] != NULL) {
                AdvanceModelAnimation(stemSet->mNsbcaNsbmaNsbtp[2]);
            }
        }
    }
    if (gStemSets->mTimedQuad.mEnabled != FALSE) {
        gStemSets->mUpdateFunction(&gStemSets->mTimedQuad);
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
    NNS_G3dGlb.mCameraMtx = identityMatrix;
    if (gRaceSetup->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (gStemSets->mShownIndex != STEM_SET_NONE) {
        baseTranslation = &baseTransform.mRows[3];
        baseTranslation->x = 0;
        baseTranslation->y = 0;
        baseTranslation->z = 0;
        baseScale = gStemBaseScale;
        baseTransform.mRows[3].y = gStemBaseTranslationY;
        if (gStemSets->mShownIndex == STEM_SET_COUNT_COPY) {
            baseTransform.mRows[3].y = 0x50000;
        }
        MTX_Identity33_(&baseTransform.mAxes);
        for (nsbmdIndex = 0; nsbmdIndex < gStemSets->mSets[STEM_SET_CURRENT]->mNsbmdCount; nsbmdIndex++) {
            nsbmd = &gStemSets->mSets[STEM_SET_CURRENT]->mNsbmds[nsbmdIndex];
            G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x1f6, 0, &NNS_G3dGlb.mProjMtx);
            NNS_G3dGlb.mFlag &= ~0x50;
            NNS_G3dGlbSetBaseScale(&baseScale);
            MI_Copy36B(&baseTransform, &NNS_G3dGlb.mPrmBaseRot);
            NNS_G3dGlb.mFlag &= ~0xa4;
            NNS_G3dGlbSetBaseTrans(&baseTransform.mRows[3]);
            NNS_G3dGlbFlushP();
            NNS_G3dDraw(&nsbmd->mRenderObj);
        }
    }
    if (gStemSets->mTimedQuad.mEnabled != FALSE) {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 8;
        reg_G3_SPE_EMI = 0x4210;
        reg_G3_DIF_AMB = 0x42100000;
        reg_G3_MTX_MODE = 0;
        G3_LoadMtx44(&gStemSets->mOrthoMtx);
        reg_G3_TEXIMAGE_PARAM = 0x20000000;
        reg_G3_MTX_MODE = 2;
        reg_G3_MTX_IDENTITY = 0;
        DrawTimedQuad(&gStemSets->mTimedQuad);
    }
}

void Nop(void) {}

void SetStemSet(s32 setIndex) {
    if (setIndex == STEM_SET_NONE) {
        gStemSets->mShownIndex = setIndex;
        return;
    }
    if (gStemSets->mShownIndex != setIndex || setIndex == STEM_SET_COUNT_COPY) {
        StartStemSet(setIndex);
    }
    gStemSets->mShownFrames = 0;
    if (gStemSets->mShownIndex == STEM_SET_START || gStemSets->mShownIndex == STEM_SET_GOAL) {
        gStemSets->mShownFrameCount =
            FROM_FIXED12(GetModelAnimationFrameCountFixed(gStemSets->mSets[STEM_SET_CURRENT]->mNsbcaNsbmaNsbtp[0]));
    }
}

void StartTimedQuad(TimedQuad *timedQuad) {
    timedQuad->mTimer = 0xau;
    timedQuad->mAlpha = 0xcu;
    timedQuad->mColor = 0x7fffu;
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
    gStemSets->mStartFunction = gTimedQuadStartFunctions[tableIndex];
    gStemSets->mUpdateFunction = gTimedQuadUpdateFunctions[tableIndex];
    gStemSets->mStartFunction(&gStemSets->mTimedQuad);
}
