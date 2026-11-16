#include "Main/Unknown/code_020e48b4.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e48e0.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/code_020e4934.h"
#include "Main/Unknown/code_020e4990.h"
#include "Main/Unknown/code_020e49c0.h"
#include "Main/Unknown/code_020e4a18.h"
#include "Main/Unknown/code_020e4a34.h"
#include "Main/Unknown/code_020df85c.h" // MapObjectFlagsView
#include "Main/Unknown/code_020e4a68.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020e4ab4.h"
#include "Main/Unknown/code_020e4ad0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020e4dec.h"
#include "Main/Unknown/code_020e4df8.h"
#include "Main/Unknown/code_020e4e08.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020e4e9c.h"
#include "Main/Unknown/code_020e4ea8.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0217b000.h"

PukupukuKindData *puku_setupConfig(void) {
    PukupukuKindData *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = *(PukupukuKindData *) data_02159070;
    return kindData;
}

PukupukuDrawList *puku_setupMainRenderPart(void) {
    PukupukuDrawList *drawList;
    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    puku_sMainRenderPart = drawList;
    *drawList = *(PukupukuDrawList *) data_02159044;
    mobj_renderPartSetThisPointer(&puku_sMainRenderPart);
    return puku_sMainRenderPart;
}

PukupukuShadowDrawList *puku_setupShadowRenderPart(void) {
    PukupukuShadowDrawList *shadowDrawList;
    shadowDrawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    puku_sShadowRenderPart = shadowDrawList;
    *shadowDrawList = *(PukupukuShadowDrawList *) data_02159018;
    mobj_renderPartSetThisPointer(&puku_sShadowRenderPart);
    return puku_sShadowRenderPart;
}

PukupukuUpdateList *puku_setupLogicPart(void) {
    PukupukuUpdateList *updateList;
    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    puku_sLogicPart = updateList;
    *updateList = *(PukupukuUpdateList *) data_02158ff0;
    mobj_logicPartSetThisPointer(&puku_sLogicPart);
    return puku_sLogicPart;
}

void puku_applyMainMaterial(void) {
    bbm_applyMaterial(gPukupuku);
}

void puku_renderMain(u32 a, Unk020e43a8 *pukupuku, u32 b, u16 alpha) {
    NsbmdModel *model;
    s32 mirrored;
    u32 v;

    if (pukupuku->field0.mStateMachine.mState == 0) {
        MtxFx43 *matrix;
        mirrored = pukupuku->field0.mCollisionSlotIndex & 1;
        matrix = bbm_getBillboardAtPos(&pukupuku->field0.mPos);
        model = gPukupuku;
        model->field14 = model->field14 | 0xc0;
        gPukupukuDrawScale = pukupuku->field0.mScale;
        if (mirrored) {
            gPukupukuDrawScale.x = -gPukupukuDrawScale.x;
        }
        bbm_renderTransformedScaled(model, matrix, &gPukupukuDrawScale, 0, alpha);
    } else {
        MtxFx43 *matrix;
        mirrored = pukupuku->field0.mCollisionSlotIndex & 1;
        v = *(u16 *) &pukupuku->fieldA0.fieldC.x;
        matrix = bbm_getBillboardAtPos(&pukupuku->field0.mPos);
        model = gPukupuku;
        model->field14 = model->field14 | 0xc0;
        gPukupukuDrawScale = pukupuku->field0.mScale;
        if (mirrored) {
            gPukupukuDrawScale.x = -gPukupukuDrawScale.x;
        }
        bbm_renderTransformedRotatedScaled(model, matrix, v, &gPukupukuDrawScale, 0, alpha);
    }
}

void puku_applyShadowMaterial(void) {
    u32 value12;
    oshd_applyMaterial();
}

void puku_renderShadow(u32 a, Unk020e43a8 *pukupuku, u32 b, u32 alpha) {
    Unk020e4e08 shadowParams;

    if (pukupuku->field0.mStateMachine.mState != 0 && pukupuku->field0.mStateMachine.mState != 1) {
        return;
    }
    shadowParams.field0 = pukupuku->field0.mPos.y - pukupuku->fieldA0.field18.y;
    shadowParams.field0 = 0x1000 - (shadowParams.field0 >> 6);
    shadowParams.field4 = pukupuku->field0.mPos;
    shadowParams.field4.y = pukupuku->fieldF4.z + pukupuku->field100;
    oshd_setPosition((ShadowMatrix *) &pukupuku->fieldC8, &shadowParams.field4);
    oshd_render((ShadowMatrix *) &pukupuku->fieldC8, &shadowParams, 0, alpha);
}

void puku_update(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value0 = (value1) + (0x80u);
    sm_execute((void *) value0);
}

void puku_state0Init(Unk020e4dec *pukupuku) {
    pukupuku->fieldAC = 0x0u;
}

static inline u32 func_020e4ad0_inline(RandomState64 *random, u32 range) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (range == 0) {
        return random->mValue >> 32;
    } else {
        return ((random->mValue >> 32) * range) >> 32;
    }
}

void puku_state0Update(Unk020e43a8 *pukupuku) {
    s32 y;

    pukupuku->field0.field10.y -= 0x385;
    VEC_Add(&pukupuku->field0.mPos, &pukupuku->field0.field10, &pukupuku->field0.mPos);
    y = 0;
    y += (s32) (((s64) pukupuku->field104 * (pukupuku->field0.mPos.x - pukupuku->fieldA0.field18.x)) >> 12);
    y += (s32) (((s64) pukupuku->field108 * (pukupuku->field0.mPos.z - pukupuku->fieldA0.field18.z)) >> 12);
    pukupuku->field100 = y;
    y = pukupuku->fieldA0.field18.y + pukupuku->field100;
    if (pukupuku->field0.mPos.y >= y) {
        return;
    }
    if (!(pukupuku->field0.mDistanceSquaredAndFlags & 4)) {
        Unk0210b7a8 soundRequest;
        u32 falloffIndex;

        if (pukupuku->field0.mFarDistanceSquared == gSfxParams[2].field20) {
            falloffIndex = 2;
        } else if (pukupuku->field0.mFarDistanceSquared == gSfxParams[3].field20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x10b;
        soundRequest.mPositionSource = &pukupuku->field0.mPos;
        soundRequest.field8 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&pukupuku->field0.mPos);
        func_0210b7a8(&soundRequest);
    }
    pukupuku->field0.mPos.y = y;
    pukupuku->fieldC4 = pukupuku->fieldC4 - 1;
    if (pukupuku->fieldC4 == 0) {
        RandomState64 *random;

        pukupuku->field0.field10.y = 0x3199;
        random = mobj_getRng1();
        pukupuku->fieldC4 = (u16) func_020e4ad0_inline(random, 3) + 4;
    } else {
        RandomState64 *random;

        pukupuku->field0.field10.y = 0x2000;
        random = mobj_getRng1();
        pukupuku->field0.field10.y = pukupuku->field0.field10.y + func_020e4ad0_inline(random, 0x800);
    }
    if (pukupuku->field0.mPos.x > pukupuku->fieldA0.field18.x + 0x14000) {
        pukupuku->field0.field10.x = -0xccc;
    } else if (pukupuku->field0.mPos.x < pukupuku->fieldA0.field18.x - 0x14000) {
        pukupuku->field0.field10.x = 0xccc;
    } else {
        RandomState64 *random;

        random = mobj_getRng1();
        pukupuku->field0.field10.x = func_020e4ad0_inline(random, 0x1998) - 0xccc;
    }
    if (pukupuku->field0.mPos.z > pukupuku->fieldA0.field18.z + 0x14000) {
        pukupuku->field0.field10.z = -0xccc;
        return;
    }
    if (pukupuku->field0.mPos.z < pukupuku->fieldA0.field18.z - 0x14000) {
        pukupuku->field0.field10.z = 0xccc;
        return;
    }
    {
        RandomState64 *random;

        random = mobj_getRng1();
        pukupuku->field0.field10.z = func_020e4ad0_inline(random, 0x1998) - 0xccc;
    }
}

void puku_state1Init(Unk020e43a8 *pukupuku) {
    pukupuku->field0.mFlags = (((pukupuku->field0.mFlags)) | ((data_02158fe4)));
}

void puku_state1Update(Unk020e43a8 *pukupuku) {
    if (rdmo_dieUpdate(pukupuku) == FALSE) {
        return;
    }
    if (pukupuku->field0.mCourseMapRow->field28 == 0) {
        pukupuku->field0.mStateMachine.mNextState = 2;
        pukupuku->field0.mStateMachine.mNextStateRequested = 1;
        return;
    }
    mobj_setInvisible(&pukupuku->field0);
}

void puku_state2Init(MapObjectFlagsView *pukupuku) {
    pukupuku->field2 |= data_02158fe8;
    pukupuku->field2 |= data_02158fec;
}

void puku_state2Update(Unk020e43a8 *pukupuku) {
    if (pukupuku->field0.mStateMachine.mStateFrames > 0x12c) {
        pukupuku->field0.mStateMachine.mNextState = 3;
        pukupuku->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void puku_state3Init(Unk020e49c0 *pukupuku) {
    pukupuku->field4 = pukupuku->fieldB8;
    pukupuku->fieldC = pukupuku->fieldC0;
    pukupuku->field10 = 0x0u;
    pukupuku->field14 = 0x3199u;
    pukupuku->field18 = 0x0u;
    pukupuku->field2 = (((pukupuku->field2)) & ~(0x2u));
    pukupuku->field2 = (((pukupuku->field2)) & ~(0x8u));
    pukupuku->field66 = 0x1fu;
    pukupuku->field2 = (((pukupuku->field2)) & ~(0x1u));
}

void puku_state3Update(Unk020e43a8 *pukupuku) {
    pukupuku->field0.mPos.y = pukupuku->field0.mPos.y + pukupuku->field0.field10.y;
    if (pukupuku->field0.mPos.y > pukupuku->fieldA0.field18.y) {
        pukupuku->field0.mStateMachine.mNextState = 0;
        pukupuku->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u8 puku_onDriverCollide(Unk020e43a8 *pukupuku, Unk020ec6e4 *kart, u8 *c, u8 *d) {
    if (*c == 1) {
        rdmo_20EC6E4(pukupuku, kart);
        pukupuku->field0.mStateMachine.mNextState = 1;
        pukupuku->field0.mStateMachine.mNextStateRequested = 1;
        pukupuku->field0.mFlags = pukupuku->field0.mFlags | (data_02158fe4);
        mobj_tryDestroyByDriver((void *) pukupuku, (void *) kart);
    }
    return *d;
}

s32 puku_onItemCollide(Unk020e43a8 *pukupuku, void *itemObject, u8 *b, u8 *c) {
    if (*b == 1) {
        rdmo_20EC538(pukupuku, itemObject);
        pukupuku->field0.mFlags |= data_02158fe4;
        pukupuku->field0.mStateMachine.mNextState = 1;
        pukupuku->field0.mStateMachine.mNextStateRequested = 1;
    }
    return *c;
}

#pragma thumb on

void puku_loadModel(void) {
    void *nsbmdFile;
    nsbmdFile = mobj_getMapObjFile(aPukupuku_nsbmd);
    bbm_createFromNsbmd((NsbmdModel **) (((u32 *) &gPukupuku)), nsbmdFile, 0, 0);
    bbm_setDefaultMatParams(gPukupuku);
}

#pragma thumb off
