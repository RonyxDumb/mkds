#include "Main/Unknown/code_020ffc08.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020ea670.h"

#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Unknown/code_020ffcf8.h"
#include "Main/Unknown/code_020ffd04.h"
#include "Main/Unknown/code_020ffd3c.h"
#include "Main/Unknown/code_020ffd40.h"
#include "Main/Unknown/code_020ffd94.h"
#include "Main/Unknown/code_020ffda0.h"
#include "Main/Unknown/code_020ffdc0.h"
#include "Main/Unknown/code_020ffdc4.h"
#include "Main/Unknown/code_020ffdd4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"
#include "code_02146cbc.h"

Unk02100004 *dram_setupConfig(void) {
    Unk02100004 *block;

    block = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    {
        Unk02100004 zeroBlock = {0};

        *block = zeroBlock;
    }
    return block;
}

Unk020fffa8 *dram_setupLogicPart(void) {
    Unk020fffa8 *block;

    block = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    dram_sLogicPart = block;
    *block = dram_logicPartData;
    mobj_logicPartSetThisPointer(&dram_sLogicPart);
    return dram_sLogicPart;
}

Unk020fff4c *dram_setupRenderPart(void) {
    Unk020fff4c *block;

    block = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    dram_sRenderPart = block;
    *block = dram_renderPartData;
    mobj_renderPartSetThisPointer(&dram_sRenderPart);
    return dram_sRenderPart;
}

void dram_render(void *a, Dram *dram, void *c, s32 maxAlpha) {
    MtxFx43 *matrix;
    s32 angleIndex;

    matrix = &dram->mUnk_00.mMatrix;
    angleIndex = (u16) (-(s32) dram->mUnk_a6) >> 4;
    MTX_RotX33_((s32 *) matrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    matrix->mUnk_00[3].x = dram->mUnk_00.mPos.x >> 4;
    matrix->mUnk_00[3].y = dram->mUnk_00.mPos.y >> 4;
    matrix->mUnk_00[3].z = dram->mUnk_00.mPos.z >> 4;
    model2_renderModel(dram_sModel, matrix, &dram->mUnk_00.mScale, maxAlpha);
}

void dram_globalPreUpdate(MapObjectList *list) {
    RandomState64 *random;
    void **dramObjects;
    Dram *dram;
    u16 *row;
    s32 count, index;
    u16 rowIndex;

    count = list->mMapObjectCount;
    dramObjects = list->mMapObjects;
    for (index = 0; index < count; index++) {
        dram = dramObjects[index];
        if (dram->mUnk_00.mStateMachine.mState != 1) {
            return;
        }
    }
    random = mobj_getRng1();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    rowIndex = ((u64) (u32) (random->mValue >> 32) * 6) >> 32;
    for (index = 0; index < count; index++) {
        dram = dramObjects[index];
        row = (u16 *) dram_sSpeedPermutationTable[rowIndex];
        dram->mUnk_a8 = dram->mUnk_b4[row[index]];
        dram->mUnk_00.mStateMachine.mNextState = 0;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void dram_update(u32 arg0, u32 dram) {
    u32 value0;
    u32 dramAddress = dram;
    u32 value12;
    value0 = (dramAddress) + (0x80u);
    sm_execute((void *) value0);
}

u32 dram_waitStateInit(u32 value) {
    return value;
}

void dram_waitStateUpdate(Dram *dram) {
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a4) {
        dram->mUnk_00.mStateMachine.mNextState = 2;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void dram_spinStartStateInit(Unk020ffd94 *dram) {
    dram->mUnk_ac = 0x0u;
}

void dram_spinStartStateUpdate(Dram *dram) {
    dram->mUnk_ac += dram->mUnk_b0;
    dram->mUnk_a6 += (s16) ((s32) (((s64) dram->mUnk_ac * dram->mUnk_a8) >> 12));
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a0) {
        dram->mUnk_00.mStateMachine.mNextState = 3;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 dram_spinningStateInit(u32 value) {
    return value;
}

void dram_spinningStateUpdate(Dram *dram) {
    dram->mUnk_a6 += dram->mUnk_a8;
    if (dram->mUnk_a2 == 0) {
        return;
    }
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a2) {
        dram->mUnk_00.mStateMachine.mNextState = 4;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void dram_spinStopStateInit(Unk020ffcf8 *dram) {
    dram->mUnk_ac = 0x1000u;
}

void dram_spinStopStateUpdate(Dram *dram) {
    s16 angleStep;

    dram->mUnk_ac -= dram->mUnk_b0;
    angleStep = (s32) (((s64) dram->mUnk_ac * dram->mUnk_a8) >> 12);
    if (angleStep <= 0x96) {
        angleStep = 0x96;
    }
    dram->mUnk_a6 += angleStep;
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a0) {
        dram->mUnk_00.mStateMachine.mNextState = 5;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void dram_alignStateInit(Dram *dram) {
    s32 angle;

    angle = dram->mUnk_a6;
    dram->mUnk_bc = 0x1999 - angle % 0x1999;
}

// Raw stores of 1 at +0x90 and +0x92 are mNextState and mNextStateRequested (MapObject +0x80 + 0x10 / 0x12): it asks
// for state 1.
void dram_alignStateUpdate(u32 dram) {
    u32 dramAddress = dram;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 anglePointer;
    s32 compareLeft0;
    s32 zero;
    value1 = *(const u16 *) ((dramAddress) + (166));
    anglePointer = (dramAddress) + (0xa6u);
    value1 = (value1) + (0x96u);
    *(u16 *) ((dramAddress) + (166)) = value1;
    value1 = *(const u32 *) ((dramAddress) + (188));
    value1 = (value1) - (0x96u);
    *(u32 *) ((dramAddress) + (188)) = value1;
    value3 = *(const u32 *) ((dramAddress) + (188));
    compareLeft0 = value3;
    zero = 0u;
    if (compareLeft0 >= zero) {
        return;
    }
    value2 = *(const u16 *) ((anglePointer) + (0));
    value1 = 1u;
    value2 = (value2) + (value3);
    *(u16 *) ((anglePointer) + (0)) = value2;
    *(u16 *) ((dramAddress) + (144)) = value1;
    *(u16 *) ((dramAddress) + (146)) = value1;
}
