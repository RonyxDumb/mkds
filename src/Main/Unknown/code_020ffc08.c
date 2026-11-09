#include "Main/Unknown/code_020ffc08.h"
#include "Main/Unknown/code_02036820.h"
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

Unk02100004 *func_02100004(void) {
    Unk02100004 *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    {
        Unk02100004 zeroBlock = {0};

        *block = zeroBlock;
    }
    return block;
}

Unk020fffa8 *func_020fffa8(void) {
    Unk020fffa8 *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217c624 = block;
    *block = data_0215a12c;
    SetUpdateListSlot(&data_0217c624);
    return data_0217c624;
}

Unk020fff4c *func_020fff4c(void) {
    Unk020fff4c *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217c62c = block;
    *block = data_0215a100;
    SetDrawListSlot(&data_0217c62c);
    return data_0217c62c;
}

void DrawDram(void *a, Dram *dram, void *c, s32 maxAlpha) {
    MtxFx43 *matrix;
    s32 angleIndex;

    matrix = &dram->mMapObject.mMatrix;
    angleIndex = (u16) (-(s32) dram->mAngleX) >> 4;
    MTX_RotX33_(&matrix->mUnk_00_m, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
    matrix->mUnk_00[3].x = dram->mMapObject.mPos.x >> 4;
    matrix->mUnk_00[3].y = dram->mMapObject.mPos.y >> 4;
    matrix->mUnk_00[3].z = dram->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gDram, matrix, &dram->mMapObject.mScale, maxAlpha);
}

void func_020ffdd4(MapObjectList *list) {
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
        if (dram->mMapObject.mStateMachine.mState != 1) {
            return;
        }
    }
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    rowIndex = ((u64) (u32) (random->mValue >> 32) * 6) >> 32;
    for (index = 0; index < count; index++) {
        dram = dramObjects[index];
        row = data_0215a0a8[rowIndex];
        dram->mAnglePerFrame = dram->mAnglePerFrameChoices[row[index]];
        dram->mMapObject.mStateMachine.mNextState = 0;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void UpdateDram(u32 arg0, Dram *dram) {
    AdvanceStateMachine(&dram->mMapObject.mStateMachine);
}

u32 func_020ffdc0(u32 value) {
    return value;
}

void UpdateDramState0(Dram *dram) {
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mDelayFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 2;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState2(Dram *dram) {
    dram->mRamp = 0x0u;
}

void UpdateDramState2(Dram *dram) {
    dram->mRamp += dram->mRampPerFrame;
    dram->mAngleX += (s16) (MUL_FIXED12_NO_ROUND(dram->mRamp, dram->mAnglePerFrame));
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mRampFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 3;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020ffd3c(u32 value) {
    return value;
}

void UpdateDramState3(Dram *dram) {
    dram->mAngleX += dram->mAnglePerFrame;
    if (dram->mSteadyFrameCount == 0) {
        return;
    }
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mSteadyFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 4;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState4(Dram *dram) {
    dram->mRamp = 0x1000u;
}

void UpdateDramState4(Dram *dram) {
    s16 angleStep;

    dram->mRamp -= dram->mRampPerFrame;
    angleStep = MUL_FIXED12_NO_ROUND(dram->mRamp, dram->mAnglePerFrame);
    if (angleStep <= 0x96) {
        angleStep = 0x96;
    }
    dram->mAngleX += angleStep;
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mRampFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 5;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState5(Dram *dram) {
    s32 angle;

    angle = dram->mAngleX;
    dram->mAngleRemaining = 0x1999 - angle % 0x1999;
}

// Asks for state 1 once mUnk_bc has run out.
void UpdateDramState5(Dram *dram) {
    dram->mAngleX += 0x96;
    dram->mAngleRemaining -= 0x96;
    if (dram->mAngleRemaining >= 0) {
        return;
    }
    dram->mAngleX += dram->mAngleRemaining;
    dram->mMapObject.mStateMachine.mNextState = 1;
    dram->mMapObject.mStateMachine.mNextStateRequested = 1;
}
