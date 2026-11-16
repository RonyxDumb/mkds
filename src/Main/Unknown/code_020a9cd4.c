#include "Main/Unknown/code_020a9cd4.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"

#pragma opt_propagation off

#pragma thumb on

void MoveKeyboardCursorToValue(u16 value) {
    KeyboardRect *foundRect;
    u16 callbackValue;

    foundRect = FindKeyboardRectByValue(value);
    if (foundRect != NULL) {
        gKeyboardKeys.mCursorRect = foundRect;
        if (gKeyboardKeys.mCursorCallback != NULL) {
            callbackValue = gKeyboardKeys.mCursorCallback(GetKeyboardRectValue(foundRect), 0);
            if (callbackValue != 0) {
                gKeyboardKeys.mCursorRect = FindKeyboardRectByValue(callbackValue);
            }
        }
    }
}

s32 GetKeyboardCursorValue(void) {
    return GetKeyboardRectValue(gKeyboardKeys.mCursorRect);
}

s32 GetKeyboardChosenKeyValue(void) {
    return GetKeyboardValueForKeyId(data_0217b2b8[0]);
}

#pragma thumb off

void ibal_init(IronBall *ironBall) {
    Vec3 scale = data_02167974;

    mobj_setScale(&ironBall->field0, &scale);
    ironBall->field0.mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&ironBall->field0.mSound->mSoundSource, 10, &ironBall->field0.mPos);
    ironBall->field0.mFarDistanceSquared = gSfxParams[10].field20;
    ironBall->field128 = mobj_parseDecimalBits(ironBall->field0.mCourseMapRow->field34);
}

u32 ibal_onDriverCollide(IronBall *ironBall, void *kart, u8 *b, u8 *c) {
    u32 x = *b;
    u32 y = *c;

    if (x == 1) {
        ironBall->mHeightSpeed = 0xa000;
        return 0;
    }
    return (u8) y;
}

void iball_loadBallModel(void *a) {
    iball_sModel = mobj_loadBillboardModel(a, aIronball_nsbmd);
    mobj_setModelPolygonIdAll(iball_sModel, 0x3f);
}

void iball_applyBallMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, iball_sModel);
}

void iball_renderBall(void *a, IronBall *ironBall) {
    u32 v;
    u8 rotationMatrix[0x28];
    s32 pairIndex;

    v = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&ironBall->field0.mPos), 0xc);
    if (ironBall->mRotateZAngle != 0) {
        pairIndex = (u16) ironBall->mRotateZAngle >> 4;
        MTX_RotZ33_((s32 *) rotationMatrix, FX_SinCosTable_[pairIndex * 2], FX_SinCosTable_[pairIndex * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &ironBall->field0.mScale, 3);
    mobj_renderModel(a, iball_sModel, ironBall);
}
