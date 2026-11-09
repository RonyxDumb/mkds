#include "Main/Unknown/code_020da5f0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020da414.h"

#include "Main/Unknown/code_020da628.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ebef8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dab98.h"
#include "Main/Unknown/code_020dab9c.h"
#include "Main/Unknown/code_020dabfc.h"
#include "Main/Unknown/code_020dac00.h"
#include "Main/Unknown/code_020dac58.h"
#include "Main/Unknown/code_020dac74.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020dade8.h"
#include "Main/Unknown/code_020dadfc.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020daf0c.h"

void EnterKuriboState0(Kuribo *kuribo) {
    kuribo->mScaleFactorY = 0x1000u;
    kuribo->mUnk_c8 = 0x0u;
}

void UpdateKuriboState0(Kuribo *kuribo) {
    if (kuribo->mFrameIndex >= 0xa && (kuribo->mFrameIndex < 0x14 || kuribo->mFrameIndex >= 0x1e)) {
        AdvanceGroupFollower(&kuribo->mFollower);
    }
    GetGroupFollowerCurvePosition(&kuribo->mFollower, &kuribo->mMapObject.mPos);
    if (kuribo->mScaleFactorY == 0x1000 && kuribo->mUnk_c8 == 0) {
        return;
    }
    kuribo->mUnk_c8 += (s32) (((s64) (0x1000 - kuribo->mScaleFactorY) * 0x200) >> 12);
    kuribo->mUnk_c8 = ((s64) kuribo->mUnk_c8 * 0xd99) >> 12;
    kuribo->mScaleFactorY += kuribo->mUnk_c8;
    if (kuribo->mScaleFactorY > 0xfd7 && kuribo->mScaleFactorY < 0x1029 && kuribo->mUnk_c8 > -0x29 &&
        kuribo->mUnk_c8 < 0x29) {
        kuribo->mScaleFactorY = 0x1000;
        kuribo->mUnk_c8 = 0;
    }
}

void EnterKuriboState1(Kuribo *kuribo) {
    kuribo->mScaleFactorY = 0x1000u;
    kuribo->mUnk_c8 = 0x0u;
}

void UpdateKuriboState1(Kuribo *kuribo) {
    u32 surfaceFlags;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    if (kuribo->mFrameIndex < 0xa || (kuribo->mFrameIndex >= 0x14 && kuribo->mFrameIndex < 0x1e)) {
        if (kuribo->mFrameIndex == 0 || kuribo->mFrameIndex == 0x14) {
            kuribo->mUnk_102--;
            if (kuribo->mUnk_102 < 0) {
                kuribo->mUnk_102 = 3;
                kuribo->mUnk_104 = kuribo->mUnk_104 == 0;
            }
        }
    }
    kuribo->mMapObject.mUnk_10.y -= 0x400;
    kuribo->mMapObject.mPos.y += kuribo->mMapObject.mUnk_10.y;
    probePos = kuribo->mMapObject.mPos;
    probePos.y += 0xa000;
    if (func_01ffdee4(&probePos, NULL, 0, 0xa000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags, NULL, NULL,
                      NULL, NULL) != 0) {
        VEC_Add(&kuribo->mMapObject.mPos, &correction, &kuribo->mMapObject.mPos);
        kuribo->mMapObject.mUnk_10.y = 0;
        if ((surfaceFlags & 0x1e34ef) != 0) {
            QuaternionFromYAxisToVec3(&surfaceNormal, &kuribo->mTargetOrientation);
            kuribo->mMapObject.mFlags &= ~1;
        }
    }
    QuaternionBlendTowardNearerSign(&kuribo->mOrientation, &kuribo->mTargetOrientation, &kuribo->mOrientation,
                                    kuribo->mOrientationBlendAmount);
    if (kuribo->mOrientationBlendAmount > 0xb4) {
        kuribo->mOrientationBlendAmount = 0xb4;
    }
}

void EnterKuriboState2(Kuribo *kuribo) {
    kuribo->mMapObject.mFlags = (((kuribo->mMapObject.mFlags)) | ((data_02158160)));
}

void UpdateKuriboState2(Kuribo *kuribo) {
    kuribo->mScaleFactorY = ((s64) kuribo->mScaleFactorY * 0x1266) >> 12;
    if (kuribo->mScaleFactorY > 0x1800) {
        kuribo->mMapObject.mStateMachine.mNextState = 3;
        kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020dabfc(u32 value) {
    return value;
}

void UpdateKuriboState3(Kuribo *kuribo) {
    kuribo->mScaleFactorY = ((s64) kuribo->mScaleFactorY * 0xd99) >> 12;
    if (kuribo->mScaleFactorY < 0x333) {
        kuribo->mMapObject.mStateMachine.mNextState = 4;
        kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020dab98(u32 value) {
    return value;
}

void UpdateKuriboState4(Kuribo *kuribo) {
    if (kuribo->mUnk_fc != 0) {
        if (kuribo->mMapObject.mStateMachine.mStateFrames > 0x12c) {
            kuribo->mMapObject.mStateMachine.mNextState = 5;
            kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
        return;
    }
    kuribo->mModelAlpha--;
    if (kuribo->mModelAlpha == 0) {
        ParkMapObject(&kuribo->mMapObject);
    }
}

void EnterKuriboState5(Kuribo *kuribo) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;
    if ((kuribo->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
        if (kuribo->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
            falloffIndex = 2;
        } else if (kuribo->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x183;
        soundRequest.mPositionSource = &kuribo->mMapObject.mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&kuribo->mMapObject.mPos);
        func_0210b7a8(&soundRequest);
    }
    kuribo->mMapObject.mFlags &= ~1;
    kuribo->mUnk_c8 = 0;
}

void UpdateKuriboState5(Kuribo *kuribo) {
    kuribo->mUnk_c8 += (s32) (((s64) (0x1000 - kuribo->mScaleFactorY) * 0x200) >> 12);
    kuribo->mUnk_c8 = ((s64) kuribo->mUnk_c8 * 0xd99) >> 12;
    kuribo->mScaleFactorY += kuribo->mUnk_c8;
    if (kuribo->mMapObject.mStateMachine.mStateFrames > 0x3c) {
        kuribo->mMapObject.mStateMachine.mNextState = 0;
        kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void func_020da820(Kuribo *kuribo, Vec3 *hitVector) {
    Vec3 launchDirection;
    ItemObject *itemObject;
    s32 d;
    if (kuribo->mMapObject.mCourseMapRow == NULL || kuribo->mMapObject.mCourseMapRow->mUnk_2c != 0) {
        return;
    }
    VEC_Subtract(&kuribo->mFollower.mFromEntry->mPos, &kuribo->mFollower.mToEntry->mPos, &launchDirection);
    if ((s64) launchDirection.x * launchDirection.x + (s64) launchDirection.y * launchDirection.y +
            (s64) launchDirection.z * launchDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&launchDirection, &launchDirection);
    }
    {
        Vec3 t = {0, 0, 0};
        t.x = hitVector->x;
        t.z = hitVector->z;
        d = VEC_DotProduct(&launchDirection, &t);
        launchDirection.x = t.x - (s32) (((s64) launchDirection.x * d) >> 12);
        launchDirection.y = t.y - (s32) (((s64) launchDirection.y * d) >> 12);
        launchDirection.z = t.z - (s32) (((s64) launchDirection.z * d) >> 12);
    }
    if ((s64) launchDirection.x * launchDirection.x + (s64) launchDirection.y * launchDirection.y +
            (s64) launchDirection.z * launchDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&launchDirection, &launchDirection);
    }
    itemObject = StartItemObjectOrZero(3, 8, &kuribo->mMapObject.mPos, &data_021581f8);
    if (itemObject == NULL) {
        return;
    }
    itemObject->mScale.x = 0xcd;
    itemObject->mScale.y = 0xcd;
    itemObject->mScale.z = 0xcd;
    d = VEC_Mag(hitVector) + 0x5000;
    itemObject->mVelocity.x = ((s64) launchDirection.x * d) >> 12;
    itemObject->mVelocity.y = ((s64) launchDirection.y * d) >> 12;
    itemObject->mVelocity.z = ((s64) launchDirection.z * d) >> 12;
    itemObject->mVelocity.y += 0xf000;
    VEC_Add(&itemObject->mPos, &itemObject->mVelocity, &itemObject->mPos);
    func_020f6630(itemObject, 0, &kuribo->mMapObject.mPos, hitVector, &data_021581f8);
}

u32 func_020da73c(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (kuribo->mScaleFactorY == 0x1000) {
                if (kuribo->mUnk_c8 == 0) {
                    kuribo->mUnk_c8 = ((s64) kart->mVelocityLength * 0x52) >> 12;
                }
            }
            break;
        case 1:
            if (kuribo->mMapObject.mStateMachine.mState == 0 || kuribo->mMapObject.mStateMachine.mState == 5 ||
                kuribo->mMapObject.mStateMachine.mState == 1) {
                kuribo->mMapObject.mStateMachine.mNextState = 2;
                kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
                func_020d26ec(&kart->mSoundSource, 0x185);
                StartSoundIfKartStarOrKiller(&kuribo->mMapObject, kart);
                func_020da820(kuribo, &kart->mVelocity);
                kuribo->mMapObject.mFlags = kuribo->mMapObject.mFlags | data_02158160;
            }
            break;
    }
    return *c;
}

u32 func_020da684(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (kuribo->mScaleFactorY == 0x1000) {
                if (kuribo->mUnk_c8 == 0) {
                    kuribo->mUnk_c8 = 0x19a;
                }
            }
            break;
        case 1:
            if (kuribo->mMapObject.mStateMachine.mState == 0 || kuribo->mMapObject.mStateMachine.mState == 5 ||
                kuribo->mMapObject.mStateMachine.mState == 1) {
                kuribo->mMapObject.mStateMachine.mNextState = 2;
                kuribo->mMapObject.mStateMachine.mNextStateRequested = 1;
                func_020f8ddc(kart);
                if (kart != NULL) {
                    func_020da820(kuribo, &kart->mSignedTurnedForward);
                }
                kuribo->mMapObject.mFlags = kuribo->mMapObject.mFlags | data_02158160;
            }
            break;
    }
    return *c;
}

void func_020da628(Kuribo *kuribo) {
    kuribo->mOrientationBlendAmount = 0x1000;
    kuribo->mOrientation = data_02158140;
    kuribo->mTargetOrientation = data_02158150;
    SetStateMachineState(&kuribo->mMapObject.mStateMachine, 1);
    kuribo->mMapObject.mUnk_10.x = 0;
    kuribo->mMapObject.mUnk_10.y = 0;
    kuribo->mMapObject.mUnk_10.z = 0;
}

#pragma thumb on

void CreateKuribo(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile(gKuriboNsbmdName);
    nsbtpFile = FindCourseMapObjFile(gKuriboNsbtpName);
    func_020e6488(&gKuribo, nsbmdFile, nsbtpFile, 0);
    func_020e6ab8(gKuribo);
}

#pragma thumb off
