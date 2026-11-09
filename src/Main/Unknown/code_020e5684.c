#include "Main/Unknown/code_020e5684.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020e57f4.h"
#include "Main/Unknown/code_020e57fc.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e5850.h"
#include "Main/Unknown/code_020e5854.h"
#include "Main/Unknown/code_020e58b8.h"
#include "Main/Unknown/code_020e58c4.h"
#include "Main/Unknown/code_020e58fc.h"
#include "Main/Unknown/code_020e5900.h"
#include "Main/Unknown/code_020e5950.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ec000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5b88.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e5c6c.h"

void DrawObPakkunSf(u32 a, ObPakkunSf *obPakkunSf, u32 c, u16 alpha) {
    MtxFx43 *matrix;
    gObPakkunSf->mFrameIndex = ((obPakkunSf->mFramesSinceInit & 0x10) >> 4);
    if (obPakkunSf->mPushedObject.mMapObject.mStateMachine.mState == 0) {
        matrix = SetViewRotatedMatrixPos(&obPakkunSf->mPushedObject.mMapObject.mPos);
        DrawNsbmdModelWithMatrixAndMaxAlpha(gObPakkunSf, matrix, &obPakkunSf->mPushedObject.mMapObject.mScale, 0,
                                            alpha);
        return;
    }
    matrix = SetViewRotatedMatrixPos(&obPakkunSf->mPushedObject.mMapObject.mPos);
    DrawNsbmdModelWithMatrixAndAngle(gObPakkunSf, matrix, obPakkunSf->mPushedObject.mMotion.mAngle,
                                     &obPakkunSf->mPushedObject.mMapObject.mScale, 0, alpha);
}

void UpdateObPakkunSf(u32 a, ObPakkunSf *obPakkunSf) {
    SoundStartParams soundRequest;
    s32 falloffIndex;

    obPakkunSf->mFramesSinceInit = obPakkunSf->mFramesSinceInit + 1;
    if ((obPakkunSf->mFramesSinceInit & 0x1f) == 0 &&
        (obPakkunSf->mPushedObject.mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
        if (obPakkunSf->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
            falloffIndex = 2;
        } else if (obPakkunSf->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x163;
        soundRequest.mPositionSource = &obPakkunSf->mPushedObject.mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&obPakkunSf->mPushedObject.mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    AdvanceStateMachine(&obPakkunSf->mPushedObject.mMapObject.mStateMachine);
}

u8 CollideKartWithObPakkunSf(ObPakkunSf *obPakkunSf, void *kart, u8 *firstResponse, u8 *response) {
    if (HitPushedObjectByKart(&obPakkunSf->mPushedObject, kart, firstResponse) != FALSE) {
        StartSoundIfKartStarOrKiller(&obPakkunSf->mPushedObject.mMapObject, kart);
    }
    return *response;
}

u8 CollideItemObjectWithObPakkunSf(ObPakkunSf *obPakkunSf, void *itemObject, u8 *firstResponse, u8 *response) {
    HitPushedObjectByItemObject(&obPakkunSf->mPushedObject, itemObject, firstResponse);
    return *response;
}

#pragma thumb on

void CreateObPakkunSf(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile(gObPakkunSfNsbmdName);
    nsbtpFile = FindCourseMapObjFile(gObPakkunSfNsbtpName);
    CreateNsbmdModel(&gObPakkunSf, nsbmdFile, nsbtpFile, 0);
    SetNsbmdModelFixedAttributes(gObPakkunSf);
}

#pragma thumb off

#pragma thumb on

void InitObPakkunSf(ObPakkunSf *obPakkunSf) {
    obPakkunSf->mPushedObject.mMapObject.mPos.y =
        obPakkunSf->mPushedObject.mMapObject.mPos.y +
        MUL_FIXED12_NO_ROUND(obPakkunSf->mPushedObject.mMapObject.mScale.y, 0xa000);
    obPakkunSf->mFramesSinceInit = 0;
    InitPushedMotion(&obPakkunSf->mPushedObject, obPakkunSf->mPushedObject.mMapObject.mPos.y - 0x18000, 0x400, 0x800,
                     0x4000, 0x1800);
    InitPushedObjectStates(&obPakkunSf->mPushedObject);
}

#pragma thumb off

MapObjectKindData *CreateSecondHandKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02159140;
    return kindData;
}

MapObjectDrawList *CreateSecondHandDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gSecondHandDrawList = drawList;
    *drawList = data_02159114;
    SetDrawListSlot(&gSecondHandDrawList);
    return gSecondHandDrawList;
}

MapObjectList *CreateSecondHandUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gSecondHandUpdateList = updateList;
    *updateList = data_021590ec;
    SetUpdateListSlot(&gSecondHandUpdateList);
    return gSecondHandUpdateList;
}

void DrawSecondHand(u32 a, SecondHand *secondHand, u32 b, u32 alpha) {
    secondHand->mMapObject.mMatrix.mUnk_00[3].x = secondHand->mMapObject.mPos.x >> 4;
    secondHand->mMapObject.mMatrix.mUnk_00[3].y = secondHand->mMapObject.mPos.y >> 4;
    secondHand->mMapObject.mMatrix.mUnk_00[3].z = secondHand->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gSecondHand, &secondHand->mMapObject.mMatrix, &secondHand->mMapObject.mScale, alpha);
}

void UpdateSecondHand(u32 a, SecondHand *secondHand) {
    AdvanceStateMachine(&secondHand->mMapObject.mStateMachine);
    QuaternionMultiplyAngleAroundY(&secondHand->mInitialRotationQuaternion, secondHand->mMapObject.mAngle,
                                   &secondHand->mRotationQuaternion);
    Matrix3x3FromQuaternion(&secondHand->mMapObject.mMatrix.mUnk_00_m, &secondHand->mRotationQuaternion);
}

void EnterSecondHandState0(SecondHand *secondHand) {
    secondHand->mSpeedFraction = 0x0u;
}

void UpdateSecondHandState0(SecondHand *secondHand) {
    secondHand->mSpeedFraction = secondHand->mSpeedFraction + secondHand->mSpeedFractionPerFrame;
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle +
                                    (s16) MUL_FIXED12_NO_ROUND(secondHand->mSpeedFraction, secondHand->mAnglePerFrame);
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mRampFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = 1;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 SecondHandState1ReturnArgument(u32 value) {
    return value;
}

void UpdateSecondHandState1(SecondHand *secondHand) {
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle + secondHand->mAnglePerFrame;
    if (secondHand->mSteadyFrameCount == 0) {
        return;
    }
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mSteadyFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = 2;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterSecondHandState2(SecondHand *secondHand) {
    secondHand->mSpeedFraction = 0x4000u;
}

void UpdateSecondHandState2(SecondHand *secondHand) {
    secondHand->mSpeedFraction = secondHand->mSpeedFraction - secondHand->mSpeedFractionPerFrame;
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle +
                                    (s16) MUL_FIXED12_NO_ROUND(secondHand->mSpeedFraction, secondHand->mAnglePerFrame);
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mRampFrameCount) {
        secondHand->mAnglePerFrame = -secondHand->mAnglePerFrame;
        secondHand->mMapObject.mStateMachine.mNextState = 3;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 SecondHandState3ReturnArgument(u32 value) {
    return value;
}

void UpdateSecondHandState3(SecondHand *secondHand) {
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mPauseFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = 0;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

s32 CollideKartWithSecondHand(SecondHand *secondHand, Kart *kart, s32 a, u8 *response) {
    u32 itemEffect;

    itemEffect = kart->mItemEffect;
    if (itemEffect == 1 || itemEffect == 3) {
        secondHand->mMapObject.mDistanceSquaredAndFlags |= data_021590e8;
    }
    return *response;
}

u32 CollideItemObjectWithSecondHand(u32 secondHand, u32 itemObject, u32 firstResponse, u32 response) {
    return (*OFFSET_PTR(const u8, response, 0));
}

void ComputeSphereHitOnSecondHand(SecondHand *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 halfSizesNegative;
    s32 extentY;

    extentY = secondHand->mMapObject.mExtent.y;
    halfSizesNegative.x = secondHand->mMapObject.mExtent.x;
    halfSizesNegative.y = extentY;
    halfSizesNegative.z = 0;
    ComputeSphereHitOnRotatedBox(sphereCenter, &secondHand->mMapObject.mPos, &secondHand->mMapObject.mMatrix.mUnk_00[0],
                                 &secondHand->mMapObject.mExtent, &halfSizesNegative, sphereRadius, overlapOffset);
}

#pragma thumb on

void CreateSecondHand(void) {
    CreateNsbmd(&gSecondHand, FindCourseMapObjFile(gSecondHandNsbmdName), NULL);
    SetNsbmdPolygonIdLightEmiAll(gSecondHand, 0x3f, 2, 0x294a);
}

void InitSecondHand(SecondHand *secondHand, Unk020e5684 *courseRow) {
    secondHand->mMapObject.mExtent.y = MUL_FIXED12_NO_ROUND(secondHand->mMapObject.mScale.x, 0x4b000);
    InitStateMachine(&secondHand->mMapObject.mStateMachine, data_0216c240, 4, secondHand);
    QuaternionFromVec3Degrees(&courseRow->mUnk_0c, &secondHand->mRotationQuaternion);
    secondHand->mInitialRotationQuaternion = secondHand->mRotationQuaternion;
    secondHand->mRampFrameCount = courseRow->mUnk_2c;
    secondHand->mSteadyFrameCount = courseRow->mUnk_2a;
    secondHand->mPauseFrameCount = courseRow->mUnk_2e;
    secondHand->mAnglePerFrame = (courseRow->mUnk_28 << 7) / 0x64;
    if (courseRow->mUnk_30 != 0) {
        secondHand->mAnglePerFrame = -secondHand->mAnglePerFrame;
    }
    secondHand->mMapObject.mAngle = 0;
    if (secondHand->mRampFrameCount != 0) {
        secondHand->mSpeedFractionPerFrame = 0x1000 / secondHand->mRampFrameCount;
    } else {
        secondHand->mSpeedFractionPerFrame = 0;
    }
    secondHand->mSpeedFraction = 0;
    secondHand->mMapObject.mStateMachine.mNextState = 0;
    secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    secondHand->mMapObject.mFlags |= data_021590b0;
}

#pragma thumb off
