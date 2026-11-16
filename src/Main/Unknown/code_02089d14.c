#include "Main/Unknown/code_02089d14.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02089d70.h"
#include "Main/Unknown/code_02089e10.h"
#include "registers.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02089ecc.h"
#include "Main/Unknown/code_02089ef4.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/System/Heap.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02134398.h"
#include "code_02146cbc.h"
#include "g3imm.h"
#include "code_0214a748.h"
#include "code_021471bc.h"

void rwrd_init(void *heap) {
    TimedQuad *timedQuad;

    rwrd_sState = heap_alloc(heap, 0x79c);
    rwrd_loadWords(heap);
    rwrd_sState->mShownIndex = 9;
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x200, 1, &rwrd_sState->mOrthoMtx);
    timedQuad = &rwrd_sState->mTimedQuad;
    rwrd_sState->mTimedQuad.mTimer = 0;
    timedQuad->field2 = 0;
    timedQuad->mColor = 0x7fff;
    timedQuad->mEnabled = FALSE;
}

void rwrd_loadWord(void *heap, StemSet *stemSet, const StemSetParams *stemSetParams, u16 setIndex) {
    char fileName[0x80];
    void *lastNsbmdFile;
    u16 nsbmdIndex;
    Nsbmd *nsbmd;
    Nsbmd *nsbcaModel;
    ModelAnimation *g;
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
        stemSet->mNsbmds = heap_alloc(heap, stemSetParams->mNsbmdCount * 0x6c);
    }
    if (stemSetParams->mNsbcaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[0] = heap_alloc(heap, stemSetParams->mNsbcaCount * 0x38);
    }
    if (stemSetParams->mNsbmaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[1] = heap_alloc(heap, stemSetParams->mNsbmaCount * 0x38);
    }
    if (stemSetParams->mNsbmdCount == 1 && stemSetParams->mNsbtpCount > 1) {
        stemSet->mNsbcaNsbmaNsbtp[2] = heap_alloc(heap, 0x38);
        useOneNsbtpAnimation = TRUE;
    } else if (stemSetParams->mNsbtpCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[2] = heap_alloc(heap, stemSetParams->mNsbtpCount * 0x38);
    }
    for (nsbmdIndex = 0; nsbmdIndex < stemSetParams->mNsbmdCount; nsbmdIndex++) {
        nsbmd = &stemSet->mNsbmds[nsbmdIndex];
        snprintf(fileName, 0x80, "%s.nsbmd", stemSetParams->mStems[nsbmdIndex]);
        lastNsbmdFile = arc_getSceneArcFile(fileName);
        model_initFromNsbmdNoCullFix(nsbmd, lastNsbmdFile);
    }
    for (nsbcaIndex = 0; nsbcaIndex < stemSetParams->mNsbcaCount; nsbcaIndex++) {
        nsbcaModel = &stemSet->mNsbmds[nsbcaIndex];
        g = &stemSet->mNsbcaNsbmaNsbtp[0][nsbcaIndex];
        snprintf(fileName, 0x80, "%s.nsbca", stemSetParams->mStems[nsbcaIndex]);
        anim_initManager(0, g, nsbcaModel, 1, heap, NULL);
        anim_registerAllAnims(g, arc_getSceneArcFile(fileName), heap);
        anim_setAnim(g, 0);
    }
    for (nsbmaIndex = 0; nsbmaIndex < stemSetParams->mNsbmaCount; nsbmaIndex++) {
        nsbmaModel = &stemSet->mNsbmds[nsbmaIndex];
        nsbmaAnimation = &stemSet->mNsbcaNsbmaNsbtp[1][nsbmaIndex];
        snprintf(fileName, 0x80, "%s.nsbma", stemSetParams->mStems[nsbmaIndex]);
        anim_initManager(4, nsbmaAnimation, nsbmaModel, 1, heap, NULL);
        anim_registerAllAnims(nsbmaAnimation, arc_getSceneArcFile(fileName), heap);
        anim_setAnim(nsbmaAnimation, 0);
    }
    if (useOneNsbtpAnimation != FALSE) {
        g = stemSet->mNsbcaNsbmaNsbtp[2];
        anim_initManager(2, g, stemSet->mNsbmds, stemSetParams->mNsbtpCount, heap, lastNsbmdFile);
        for (nsbtpIndex = 0; nsbtpIndex < stemSetParams->mNsbtpCount; nsbtpIndex++) {
            snprintf(fileName, 0x80, "%s.nsbtp", stemSetParams->mStems[nsbtpIndex]);
            anim_registerAnim(
                g, nsbtpIndex, NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(arc_getSceneArcFile(fileName)), 0), 0, heap);
        }
        anim_setAnim(g, 0);
    }
}

void rwrd_loadWords(void *heap) {
    s16 setIndex;
    StemSet *sourceSet;
    StemSet *copiedSet;

    for (setIndex = 0; setIndex < 8; setIndex++) {
        rwrd_sState->mSets[setIndex] = NULL;
    }
    if (race_isAwardStaffRoll() != 0) {
        return;
    }
    for (setIndex = 0; setIndex <= 2; setIndex++) {
        if (setIndex == 2) {
            rwrd_sState->mSets[setIndex] = heap_alloc(heap, 0x14);
            sourceSet = rwrd_sState->mSets[0];
            copiedSet = rwrd_sState->mSets[2];
            copiedSet->mNsbmds = sourceSet->mNsbmds;
            copiedSet->mNsbcaNsbmaNsbtp[0] = NULL;
            copiedSet->mNsbcaNsbmaNsbtp[1] = sourceSet->mNsbcaNsbmaNsbtp[1];
            copiedSet->mNsbcaNsbmaNsbtp[2] = sourceSet->mNsbcaNsbmaNsbtp[2];
            copiedSet->mNsbmdCount = sourceSet->mNsbmdCount;
        } else {
            rwrd_sState->mSets[setIndex] = heap_alloc(heap, 0x14);
            rwrd_loadWord(heap, rwrd_sState->mSets[setIndex], &gCountStartStems[(u32) setIndex], setIndex);
        }
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE || gRaceMultiConfig->mRuleKind == 1) {
        rwrd_sState->mSets[4] = heap_alloc(heap, 0x14);
        rwrd_loadWord(heap, rwrd_sState->mSets[4], &gWinStems, 4);
        rwrd_sState->mSets[5] = heap_alloc(heap, 0x14);
        rwrd_loadWord(heap, rwrd_sState->mSets[5], &gLoseStems, 5);
    } else if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        rwrd_sState->mSets[6] = heap_alloc(heap, 0x14);
        rwrd_loadWord(heap, rwrd_sState->mSets[6], &gCompleteStems, 6);
        rwrd_sState->mSets[7] = heap_alloc(heap, 0x14);
        rwrd_loadWord(heap, rwrd_sState->mSets[7], &gFailedStems, 7);
    } else {
        rwrd_sState->mSets[3] = heap_alloc(heap, 0x14);
        rwrd_loadWord(heap, rwrd_sState->mSets[3], &gGoalStems, 3);
    }
}

void StartStemSet(s32 setIndex) {
    StemSet *stemSet;
    ModelAnimation *e;
    u16 nsbmdIndex;
    s32 animationIndex;
    s32 loopCount;

    rwrd_sState->mSets[8] = rwrd_sState->mSets[setIndex];
    stemSet = rwrd_sState->mSets[8];
    if (stemSet == NULL) {
        rwrd_sState->mShownIndex = 9;
        return;
    }
    rwrd_sState->mShownIndex = setIndex;
    for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
        if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
            anim_setAnim(&stemSet->mNsbcaNsbmaNsbtp[0][nsbmdIndex], 0);
        }
        if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
            anim_setAnim(&stemSet->mNsbcaNsbmaNsbtp[1][nsbmdIndex], 0);
        }
        if (setIndex == 0 || setIndex == 2) {
            if (setIndex == 2) {
                animationIndex = 1;
            } else {
                animationIndex = 0;
            }
            if (setIndex == 2) {
                loopCount = 5;
            } else {
                loopCount = 3;
            }
            anim_setAnim(stemSet->mNsbcaNsbmaNsbtp[2], (u16) animationIndex);
            e = stemSet->mNsbcaNsbmaNsbtp[0];
            if (e != NULL) {
                e[nsbmdIndex].mLoopMode = 2;
                e[nsbmdIndex].mLoopCount = loopCount;
            }
            e = stemSet->mNsbcaNsbmaNsbtp[1];
            if (e != NULL) {
                e[nsbmdIndex].mLoopMode = 2;
                e[nsbmdIndex].mLoopCount = loopCount;
            }
        }
    }
}

void rwrd_update(void) {
    StemSet *stemSet;
    u16 nsbmdIndex;

    if (rwrd_sState->mShownIndex == 1 || rwrd_sState->mShownIndex == 3) {
        rwrd_sState->mShownFrames++;
        if (rwrd_sState->mShownFrames > rwrd_sState->mShownFrameCount) {
            rwrd_sState->mShownIndex = 9;
        }
    }
    if (rwrd_sState->mShownIndex != 9) {
        stemSet = rwrd_sState->mSets[8];
        for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
            if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
                anim_update(stemSet->mNsbcaNsbmaNsbtp[0]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
                anim_update(stemSet->mNsbcaNsbmaNsbtp[1]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[2] != NULL) {
                anim_update(stemSet->mNsbcaNsbmaNsbtp[2]);
            }
        }
    }
    if (rwrd_sState->mTimedQuad.mEnabled != FALSE) {
        rwrd_sState->mUpdateFunction(&rwrd_sState->mTimedQuad);
    }
}

void rwrd_render(void) {
    MtxFx43 identityMatrix;
    MtxFx43 baseTransform;
    Vec3 baseScale;
    Vec3 *baseTranslation;
    u16 nsbmdIndex;
    Nsbmd *nsbmd;

    MTX_Identity43_(&identityMatrix);
    NNS_G3dGlb.mCameraMtx = identityMatrix;
    if (gRaceMultiConfig->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (rwrd_sState->mShownIndex != 9) {
        baseTranslation = &baseTransform.field0[3];
        baseTranslation->x = 0;
        baseTranslation->y = 0;
        baseTranslation->z = 0;
        baseScale = data_0216608c;
        baseTransform.field0[3].y = data_02166048;
        if (rwrd_sState->mShownIndex == 2) {
            baseTransform.field0[3].y = 0x50000;
        }
        MTX_Identity33_(&baseTransform);
        for (nsbmdIndex = 0; nsbmdIndex < rwrd_sState->mSets[8]->mNsbmdCount; nsbmdIndex++) {
            nsbmd = &rwrd_sState->mSets[8]->mNsbmds[nsbmdIndex];
            G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x1f6, 0,
                        (Unk0214ad4c *) NNS_G3dGlb.mProjMtx);
            NNS_G3dGlb.mFlag &= ~0x50;
            NNS_G3dGlbSetBaseScale(&baseScale);
            MI_Copy36B(&baseTransform, NNS_G3dGlb.mPrmBaseRot);
            NNS_G3dGlb.mFlag &= ~0xa4;
            NNS_G3dGlbSetBaseTrans(&baseTransform.field0[3]);
            NNS_G3dGlbFlushP();
            NNS_G3dDraw(nsbmd);
        }
    }
    if (rwrd_sState->mTimedQuad.mEnabled != FALSE) {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G3_SPE_EMI = 0x4210;
        reg_G3_DIF_AMB = 0x42100000;
        reg_G3_MTX_MODE = 0;
        G3_LoadMtx44(&rwrd_sState->mOrthoMtx);
        reg_G3_TEXIMAGE_PARAM = 0x20000000;
        reg_G3_MTX_MODE = 2;
        reg_G3_MTX_IDENTITY = 0;
        DrawTimedQuad(&rwrd_sState->mTimedQuad);
    }
}

u32 func_02089f9c(u32 value) {
    return value;
}

void SetStemSet(s32 setIndex) {
    if (setIndex == 9) {
        rwrd_sState->mShownIndex = setIndex;
        return;
    }
    if (rwrd_sState->mShownIndex != setIndex || setIndex == 2) {
        StartStemSet(setIndex);
    }
    rwrd_sState->mShownFrames = 0;
    if (rwrd_sState->mShownIndex == 1 || rwrd_sState->mShownIndex == 3) {
        rwrd_sState->mShownFrameCount = anim_getAnimLength(rwrd_sState->mSets[8]->mNsbcaNsbmaNsbtp[0]) >> 12;
    }
}

void StartTimedQuad(Unk02089ecc *timedQuad) {
    timedQuad->mTimer = 0xau;
    timedQuad->field2 = 0xcu;
    timedQuad->mColor = 0x7fffu;
    timedQuad->mEnabled = 0x1u;
}

void UpdateTimedQuad(Unk02089e68 *timedQuad) {
    timedQuad->field2 = (s32) (((s64) ((s32) timedQuad->mTimer << 12) * 0x1333 + 0x800) >> 12) >> 12;
    timedQuad->mTimer = timedQuad->mTimer - 1;
    if (timedQuad->mTimer <= 0) {
        timedQuad->mEnabled = 0;
    }
}

void WriteQuadVertex(int vertexIndex) {
    reg_G3_VTX_16 = data_02155ed0[vertexIndex * 3] | data_02155ed0[vertexIndex * 3 + 1] << 16;
    reg_G3_VTX_16 = data_02155ed0[vertexIndex * 3 + 2];
}

void DrawTimedQuad(TimedQuad *timedQuad) {
    u32 *scaleRegister;
    u32 *beginVtxsRegister;
    scaleRegister = ((u32 *) &reg_G3_MTX_SCALE);
    reg_G3_POLYGON_ATTR = (0x090000c0u) | timedQuad->field2 << 0x10;
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

void rwrd_2089D14(u32 tableIndex) {
    rwrd_sState->mStartFunction = data_02155ec8[tableIndex];
    rwrd_sState->mUpdateFunction = data_02155ecc[tableIndex];
    rwrd_sState->mStartFunction(&rwrd_sState->mTimedQuad);
}
