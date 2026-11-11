#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_02036820.h"
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
#include "code_02147cd8.h"

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
    return GetKeyboardValueForKeyId(gKeyboardLayoutKeyIds[0]);
}

#pragma thumb off

void InitIronBall(IronBall *ironBall) {
    Vec3 scale = data_02167974;

    SetMapObjectScale(&ironBall->mMapObject, &scale);
    ironBall->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&ironBall->mMapObject.mSound->mSoundSource, 10, &ironBall->mMapObject.mPos);
    ironBall->mMapObject.mFarDistanceSquared = gSoundFalloffs[10].mFarDistanceSquared;
    ironBall->mSoundOffKind3ShapeListMask =
        DecimalNonZeroDigitsToBitMask(ironBall->mMapObject.mCourseMapRow->mSettings[6]);
}

u32 CollideKartWithIronBall(IronBall *ironBall, void *kart, u8 *b, u8 *c) {
    u32 x = *b;
    u32 y = *c;

    if (x == 1) {
        ironBall->mHeightSpeed = 0xa000;
        return 0;
    }
    return (u8) y;
}

void CreateIronBall(void *a) {
    gIronBall = CreateMapObjectModelNsbmd(a, gIronBallNsbmdName);
    SetMapObjectModelPolygonId(gIronBall, 0x3f);
}

void SetupDrawIronBall(void *a) {
    QueueMapObjectModelMaterial(a, gIronBall);
}

void DrawIronBall(void *a, IronBall *ironBall) {
    u32 v;
    MtxFx33 rotationMatrix;

    v = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&ironBall->mMapObject.mPos), 0xc);
    if (ironBall->mRotateZAngle != 0) {
        MTX_RotZ33_(&rotationMatrix, SIN_OF_ANGLE((u16) ironBall->mRotateZAngle),
                    COS_OF_ANGLE((u16) ironBall->mRotateZAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &ironBall->mMapObject.mScale, 3);
    DrawMapObjectModel(a, gIronBall, ironBall);
}
