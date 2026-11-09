#include "Main/Unknown/code_020a3f2c.h"

#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a3fa8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2e4c.h"
#include "Main/Unknown/code_020a2e74.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020a2e88.h"
#include "Main/Unknown/code_020a2f0c.h"
#include "Main/Unknown/code_020a3000.h"
#include "Main/Unknown/code_020a683c.h"
#include "Main/Unknown/code_020a69a0.h"
#include "Main/Unknown/code_020a69b4.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020a6cb4.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_02039860.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_0210bae8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020a6000.h"
#include "Main/Unknown/code_020a0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/code_020a6c64.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02077bc0.h"

void InitShine16(MapObject *mapObject) {
    ParkMapObject(mapObject);
    mapObject->mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mSound->mSoundSource, 0xb, &mapObject->mPos);
    func_0210bae8(&mapObject->mSound->mSoundSource);
    mapObject->mFarDistanceSquared = gSoundFalloffs[0xb].mUnk_20;
}

u32 CollideKartWithShine16(Shine16 *shine16, Kart *kart, u8 *a, u8 *b) {
    u8 v1;
    u8 v2;
    s32 isEntryKart;
    u16 highestBalloonOrShineCount;
    s32 balloonOrShineCount;

    v1 = *a;
    v2 = *b;
    if (kart->mState != KART_STATE_NORMAL || (kart->mUnk_48 & 0x200) != 0 || IsKartEliminated(kart->mIndex) != FALSE) {
        return 0;
    }
    if (v1 == 1) {
        if ((kart->mUnk_4c & 0x400000) != 0) {
            return v2;
        }
        if (shine16->mPickupTimer > 0) {
            return v2;
        }
        shine16->mUnk_00.mFlags |= data_021567a0;
        shine16->mPickupTimer = 0x19;
        shine16->mUnk_00.mPos.x = kart->mPos.x;
        shine16->mUnk_00.mPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) + 0x7800;
        shine16->mUnk_00.mPos.z = kart->mPos.z;
        shine16->mHeightAboveKart = 0;
        shine16->mUnk_00.mUnk_10.x = 0;
        shine16->mUnk_00.mUnk_10.y = 0x3000;
        shine16->mUnk_00.mUnk_10.z = 0;
        shine16->mDrawScale = 0;
        shine16->mState = 2;
        shine16->mKartIndex = kart->mIndex;
        shine16->mHitByKartIndex = kart->mIndex;
        AddBalloonsLeftToMake(kart->mIndex, 1);
        AddBalloonOrShineCountAndMoveRank(kart->mIndex, 1);
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex ? 1 : 0;
        highestBalloonOrShineCount = GetHighestBalloonOrShineCount();
        balloonOrShineCount = GetBalloonOrShineCount(kart->mIndex);
        func_0210b98c(shine16->mUnk_00.mSound,
                      func_02024974(0, isEntryKart, highestBalloonOrShineCount, balloonOrShineCount));
        shine16->mEffect = StartEffect(0x7d, &shine16->mUnk_00.mPos);
        shine16->mEffectTimer = 0xe;
    }
    return v2;
}

void CreateShine16(void *a) {
    gShine16 = CreateMapObjectModelNsbmdNsbtp(a, gShine16NsbmdName, gShine16NsbtpName);
    SetMapObjectModelPolygonId(gShine16, 0x3f);
}

void SetupDrawShine16(void *a) {
    QueueMapObjectModelMaterial(a, gShine16);
}

void DrawShine16(void *a, Shine16 *shine16) {
    s32 t;
    Vec3 scaleVector;
    s32 drawScale;

    if (shine16->mDrawScale <= 0) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shine16->mUnk_00.mPos), 0xc);
    drawScale = shine16->mDrawScale;
    if (drawScale != 0x1000) {
        scaleVector.x = drawScale;
        scaleVector.y = drawScale;
        scaleVector.z = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, &scaleVector, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &shine16->mUnk_00.mScale, 3);
    SetMapObjectModelMirror(gShine16, shine16->mMirror, 0);
    SetMapObjectModelNsbtpFrameIndex(gShine16, shine16->mNsbtpFrameIndex);
    DrawMapObjectModel(a, gShine16, shine16);
}

u16 *ResetShine16ShadowAngleIndex(void) {
    gShine16ShadowAngleIndex = 0;
    return &gShine16ShadowAngleIndex;
}

void AdvanceShine16ShadowAngleIndex(void) {
    s32 nextAngleIndex;

    nextAngleIndex = gShine16ShadowAngleIndex + 1;
    if (nextAngleIndex >= 3) {
        nextAngleIndex = 0;
    }
    gShine16ShadowAngleIndex = nextAngleIndex;
}

void DrawShine16Shadow(void *a, Shine16 *shine16, void *b, s32 c) {
    s32 t;
    MtxFx33 rotateYMatrix;
    Vec3 drawScaleVector;
    Vec3 shadowScaleVector;
    s32 drawScale;
    s32 pairIndex;

    if (shine16->mDrawScale <= 0) {
        return;
    }
    if (shine16->mState == 2) {
        return;
    }
    if (shine16->mState == 3) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shine16->mUnk_00.mPos), 0xc);
    drawScale = shine16->mDrawScale;
    if (drawScale < 0x1000) {
        drawScaleVector.x = drawScale;
        drawScaleVector.y = drawScale;
        drawScaleVector.z = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, &drawScaleVector, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &shine16->mUnk_00.mScale, 3);
    pairIndex = gShine16ShadowAngles[gShine16ShadowAngleIndex] >> 4;
    MTX_RotY33_(&rotateYMatrix, gPairsByAngle[pairIndex * 2 + 1], gPairsByAngle[pairIndex * 2]);
    NNS_G3dGeBufferOP_N(0x1a, &rotateYMatrix, 9);
    shadowScaleVector.x = 0x2000;
    shadowScaleVector.y = 0x2000;
    shadowScaleVector.z = 0x2000;
    NNS_G3dGeBufferOP_N(0x1b, &shadowScaleVector, 3);
    func_020e5348(8, c);
}

void UpdateShine16(void *a, Shine16 *shine16) {
    Vec3 c;
    Vec3 b;
    Vec3 d;
    Vec3 e;
    u32 f;
    Kart *kart;
    s32 i;
    CourseMapPoint *forwardBattlePoint;
    s32 n;
    s32 x;
    s32 z;
    s32 t;
    u16 r;
    s32 s;
    RandomState64 *randomState;

    switch (shine16->mState) {
        case 0:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            shine16->mUnk_00.mUnk_10.y -= 0x19a;
            VEC_Add(&shine16->mUnk_00.mPos, &shine16->mUnk_00.mUnk_10, &shine16->mUnk_00.mPos);
            if (shine16->mUnk_00.mPos.y > shine16->mFloorY) {
                return;
            }
            shine16->mUnk_00.mPos.y = shine16->mFloorY;
            shine16->mUnk_00.mUnk_10.y = ((s64) shine16->mUnk_00.mUnk_10.y * -0x333) >> 12;
            if (shine16->mUnk_00.mUnk_10.y < 0x1000) {
                shine16->mUnk_00.mUnk_10.y = 0;
                shine16->mState = 1;
            }
            func_0210b98c(shine16->mUnk_00.mSound, 0x139);
            return;
        case 1:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            func_0210ba38(shine16->mUnk_00.mSound, 0x14e);
            return;
        case 6:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale -= 0x19a;
            if (shine16->mDrawScale > 0) {
                return;
            }
            shine16->mDrawScale = 0;
            ParkMapObject(&shine16->mUnk_00);
            AddShineCount(-1);
            if (shine16->mSpawnObjectIndex < 0) {
                return;
            }
            ClearShineBattleObjectShine(shine16->mSpawnObjectIndex);
            return;
        case 2:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            kart = GetKart(shine16->mKartIndex);
            shine16->mHeightAboveKart += shine16->mUnk_00.mUnk_10.y;
            shine16->mUnk_00.mPos = *GetKartStandingPos(shine16->mKartIndex);
            shine16->mUnk_00.mPos.y += shine16->mHeightAboveKart + (GetKartBalloonOrShineHeight(kart) + 0x7800);
            shine16->mUnk_00.mUnk_10.y -= 0x333;
            if (shine16->mPickupTimer-- <= 0) {
                shine16->mPickupTimer = 0;
                shine16->mDrawScale -= 0x19a;
                if (shine16->mDrawScale <= 0) {
                    shine16->mDrawScale = 0;
                    ParkMapObject(&shine16->mUnk_00);
                    AddShineCount(-1);
                    if (shine16->mSpawnObjectIndex >= 0) {
                        ClearShineBattleObjectShine(shine16->mSpawnObjectIndex);
                    }
                }
                if (shine16->mDrawScale <= 0) {
                    SetupKartFollowEffect(StartEffect(0x7c, &kart->mPos), kart->mIndex, 0x16);
                }
            } else {
                shine16->mDrawScale += 0x19a;
                if (shine16->mDrawScale >= 0x1000) {
                    shine16->mDrawScale = 0x1000;
                }
            }
            if (shine16->mEffect == NULL) {
                return;
            }
            PlaceEffect(shine16->mEffect, &shine16->mUnk_00.mPos);
            shine16->mEffectTimer--;
            if (shine16->mEffectTimer >= 0) {
                return;
            }
            func_0208b6b0(&shine16->mEffect);
            return;
        case 3:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            for (i = 0; i < 2; i++) {
                forwardBattlePoint = MoveToRandomForwardBattlePoint();
                n = forwardBattlePoint->mPos.y - GetKartStandingPos(shine16->mKartIndex)->y;
                if (n <= 0) {
                    n = -n;
                }
                if (n < 0x14000) {
                    x = (forwardBattlePoint->mPos.x - GetKartStandingPos(shine16->mHitByKartIndex)->x) >> 12;
                    z = (forwardBattlePoint->mPos.z - GetKartStandingPos(shine16->mHitByKartIndex)->z) >> 12;
                    n = x * x + z * z;
                    if (shine16->mHitByKartIndex == shine16->mKartIndex) {
                        if (n < 0x9c400 && n > shine16->mTargetDistanceSquared) {
                            shine16->mTargetDistanceSquared = n;
                            shine16->mTargetPos.x = forwardBattlePoint->mPos.x;
                            shine16->mTargetPos.y = forwardBattlePoint->mPos.y;
                            shine16->mTargetPos.z = forwardBattlePoint->mPos.z;
                            shine16->mTargetPickCount++;
                        }
                    } else {
                        if (n < 0x9c400 && n < shine16->mTargetDistanceSquared) {
                            shine16->mTargetDistanceSquared = n;
                            shine16->mTargetPos.x = forwardBattlePoint->mPos.x;
                            shine16->mTargetPos.y = forwardBattlePoint->mPos.y;
                            shine16->mTargetPos.z = forwardBattlePoint->mPos.z;
                            shine16->mTargetPickCount++;
                        }
                    }
                }
            }
            shine16->mHeightAboveKart += shine16->mUnk_00.mUnk_10.y;
            shine16->mUnk_00.mPos = *GetKartStandingPos(shine16->mKartIndex);
            shine16->mUnk_00.mPos.y +=
                shine16->mHeightAboveKart + (GetKartBalloonOrShineHeight(GetKart(shine16->mKartIndex)) + 0x7800);
            shine16->mUnk_00.mUnk_10.y -= 0x52;
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            if (shine16->mUnk_00.mUnk_10.y > 0) {
                return;
            }
            if (shine16->mTargetPickCount > 0) {
                randomState = &gRaceProgress->mRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                r = ((u64) (u32) (randomState->mValue >> 32) * 0x10000) >> 32;
                randomState = &gRaceProgress->mRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                s = ((u64) (u32) (randomState->mValue >> 32) * 0x14000) >> 32;
                x = shine16->mTargetPos.x + (s32) (((s64) s * gPairsByAngle[(r >> 4) * 2]) >> 12) -
                    shine16->mUnk_00.mPos.x;
                z = shine16->mTargetPos.z + (s32) (((s64) s * gPairsByAngle[(r >> 4) * 2 + 1]) >> 12) -
                    shine16->mUnk_00.mPos.z;
                shine16->mState = 4;
                shine16->mUnk_00.mUnk_10.x = ((s64) x * 0x25) >> 12;
                shine16->mUnk_00.mUnk_10.y = 0x5000;
                shine16->mUnk_00.mUnk_10.z = ((s64) z * 0x25) >> 12;
                shine16->mDrawScale = 0x1000;
                shine16->mUnk_00.mFlags &= ~1;
                return;
            }
            shine16->mState = 5;
            shine16->mUnk_00.mUnk_10.x = 0;
            shine16->mUnk_00.mUnk_10.y = 0x5000;
            shine16->mUnk_00.mUnk_10.z = 0;
            shine16->mDrawScale = 0x1000;
            shine16->mUnk_00.mFlags &= ~1;
            return;
        case 5:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            shine16->mUnk_00.mUnk_10.y -= 0x19a;
            VEC_Add(&shine16->mUnk_00.mPos, &shine16->mUnk_00.mUnk_10, &shine16->mUnk_00.mPos);
            if (shine16->mUnk_00.mUnk_10.y >= 0) {
                return;
            }
            shine16->mState = 6;
            shine16->mUnk_00.mFlags |= data_021567a0;
            return;
        case 4:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= 3) {
                shine16->mNsbtpFrameStepProgress -= 3;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= 8) {
                    shine16->mNsbtpFramesSinceMirror -= 8;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += 0x19a;
            if (shine16->mDrawScale >= 0x1000) {
                shine16->mDrawScale = 0x1000;
            }
            shine16->mUnk_00.mUnk_10.y -= 0x19a;
            VEC_Add(&shine16->mUnk_00.mPos, &shine16->mUnk_00.mUnk_10, &shine16->mUnk_00.mPos);
            if (shine16->mUnk_00.mUnk_10.y < 0 &&
                shine16->mUnk_00.mPos.y <= shine16->mTargetPos.y + shine16->mUnk_00.mExtent.x) {
                if (GetMapObjectHitResponse(&shine16->mUnk_00, 0, &b)) {
                    t = shine16->mUnk_00.mUnk_10.y;
                    VEC_Add(&shine16->mUnk_00.mPos, &b, &shine16->mUnk_00.mPos);
                    func_020ea94c(&shine16->mUnk_00.mUnk_10, &b, 0x1000, 0x1000, 0x800, &shine16->mUnk_00.mUnk_10);
                    shine16->mUnk_00.mUnk_10.y = 0;
                    if ((s64) shine16->mUnk_00.mUnk_10.x * shine16->mUnk_00.mUnk_10.x +
                            (s64) shine16->mUnk_00.mUnk_10.y * shine16->mUnk_00.mUnk_10.y +
                            (s64) shine16->mUnk_00.mUnk_10.z * shine16->mUnk_00.mUnk_10.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&shine16->mUnk_00.mUnk_10, &shine16->mUnk_00.mUnk_10);
                    }
                    shine16->mUnk_00.mUnk_10.x = ((s64) shine16->mUnk_00.mUnk_10.x * 0x1000) >> 12;
                    shine16->mUnk_00.mUnk_10.y = ((s64) shine16->mUnk_00.mUnk_10.y * 0x1000) >> 12;
                    shine16->mUnk_00.mUnk_10.z = ((s64) shine16->mUnk_00.mUnk_10.z * 0x1000) >> 12;
                    shine16->mUnk_00.mUnk_10.y = t;
                }
                c.x = shine16->mUnk_00.mPos.x;
                c.y = shine16->mUnk_00.mExtent.x + (shine16->mUnk_00.mPos.y - 0x14000);
                c.z = shine16->mUnk_00.mPos.z;
                if (CollideSphereWithCourse(&c, NULL, 0, shine16->mUnk_00.mExtent.x, 8, -2, &b, &d, &e, &f, NULL, NULL,
                                            NULL, NULL)) {
                    VEC_Add(&shine16->mUnk_00.mPos, &b, &shine16->mUnk_00.mPos);
                    if (f & 0x214300) {
                        t = shine16->mUnk_00.mUnk_10.y;
                        BounceVelocityOffSurface(&shine16->mUnk_00.mUnk_10, &e, 0x1000, 0x1000, 0x800,
                                                 &shine16->mUnk_00.mUnk_10);
                        shine16->mUnk_00.mUnk_10.y = 0;
                        if ((s64) shine16->mUnk_00.mUnk_10.x * shine16->mUnk_00.mUnk_10.x +
                                (s64) shine16->mUnk_00.mUnk_10.y * shine16->mUnk_00.mUnk_10.y +
                                (s64) shine16->mUnk_00.mUnk_10.z * shine16->mUnk_00.mUnk_10.z >=
                            0x10) {
                            Vec3NormalizeAndGetLengthUnchecked(&shine16->mUnk_00.mUnk_10, &shine16->mUnk_00.mUnk_10);
                        }
                        shine16->mUnk_00.mUnk_10.x = ((s64) shine16->mUnk_00.mUnk_10.x * 0x1000) >> 12;
                        shine16->mUnk_00.mUnk_10.y = ((s64) shine16->mUnk_00.mUnk_10.y * 0x1000) >> 12;
                        shine16->mUnk_00.mUnk_10.z = ((s64) shine16->mUnk_00.mUnk_10.z * 0x1000) >> 12;
                        shine16->mUnk_00.mUnk_10.y = t;
                    }
                    if (f & 0x1e34ef) {
                        shine16->mUnk_00.mUnk_10.x = ((s64) shine16->mUnk_00.mUnk_10.x * 0x19a) >> 12;
                        shine16->mUnk_00.mUnk_10.y = ((s64) shine16->mUnk_00.mUnk_10.y * -0x333) >> 12;
                        shine16->mUnk_00.mUnk_10.z = ((s64) shine16->mUnk_00.mUnk_10.z * 0x19a) >> 12;
                        if (shine16->mUnk_00.mUnk_10.y < 0x1000) {
                            shine16->mUnk_00.mUnk_10.y = 0;
                            shine16->mState = 1;
                        }
                        func_0210b98c(shine16->mUnk_00.mSound, 0x139);
                    }
                    if (f & 0x1000000) {
                        shine16->mUnk_00.mFlags |= data_021567ac;
                    } else {
                        shine16->mUnk_00.mFlags &= ~0x20;
                    }
                }
            }
            if (shine16->mUnk_00.mPos.y >= 0) {
                return;
            }
            shine16->mState = 6;
            shine16->mUnk_00.mFlags |= data_021567a0;
            return;
    }
}

void CreateShine16KindData(void) {
    MapObjectKindData *mapObjectKindData;

    mapObjectKindData = CreateMapObjectKindData(CollideKartWithShine16, NULL, NULL, 1, 0);
    mapObjectKindData->mUnk_38 = 0x190000;
    mapObjectKindData->mUnk_3c = -0x190000;
}

void *CreateShine16DrawList(void) {
    return CreateMapObjectDrawList2(CreateShine16, DrawShine16, SetupDrawShine16);
}

void *CreateShine16ShadowDrawList(void) {
    return CreateMapObjectDrawList1(ResetShine16ShadowAngleIndex, DrawShine16Shadow, AdvanceShine16ShadowAngleIndex);
}

void *CreateShine16UpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateShine16, NULL);
}

// Parks each map object of kind 0x6a (Shine16) that is not already parked.
void ParkShine16Objects(void) {
    s32 i;
    MapObject *mapObject;
    MapObjectList *mapObjectList;

    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16);
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if ((mapObject->mFlags & 0x100) == 0) {
            ParkMapObject(mapObject);
        }
    }
}

// Unparks a Shine16 at the position; a nonzero last argument drops it from above, zero leaves it resting.
void StartShine16(Vec3 *position, s32 spawnObjectIndex, s32 dropFromAbove) {
    Shine16 *shine16;

    shine16 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16));
    if (shine16 == NULL) {
        return;
    }
    if (dropFromAbove != 0) {
        shine16->mUnk_00.mPos.x = position->x;
        shine16->mUnk_00.mPos.y = position->y + 0x32000;
        shine16->mUnk_00.mPos.z = position->z;
        shine16->mUnk_00.mUnk_10.x = 0;
        shine16->mUnk_00.mUnk_10.y = 0x2800;
        shine16->mUnk_00.mUnk_10.z = 0;
        shine16->mHeightAboveKart = 0;
        shine16->mFloorY = position->y + 0x14000;
        shine16->mState = 0;
    } else {
        shine16->mUnk_00.mPos.x = position->x;
        shine16->mUnk_00.mPos.y = position->y + 0x14000;
        shine16->mUnk_00.mPos.z = position->z;
        shine16->mUnk_00.mUnk_10.x = 0;
        shine16->mUnk_00.mUnk_10.y = 0;
        shine16->mUnk_00.mUnk_10.z = 0;
        shine16->mHeightAboveKart = 0;
        shine16->mFloorY = 0;
        shine16->mState = 1;
    }
    shine16->mDrawScale = 0;
    shine16->mPickupTimer = 0;
    shine16->mSpawnObjectIndex = spawnObjectIndex;
    shine16->mUnk_00.mFlags &= ~1;
    shine16->mUnk_00.mFlags &= ~0x20;
    AddShineCount(1);
    func_0210b98c(shine16->mUnk_00.mSound, 0x138);
}

void StartShine16FromKart(Kart *hitKart, Kart *hitByKart) {
    Shine16 *shine16;
    s32 isEntryKart;
    u16 highestBalloonOrShineCount;
    s32 balloonOrShineCount;

    shine16 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16));
    if (shine16 == NULL) {
        return;
    }
    shine16->mUnk_00.mFlags = shine16->mUnk_00.mFlags | data_021567a0;
    shine16->mUnk_00.mFlags &= ~0x20;
    shine16->mUnk_00.mPos.x = hitKart->mPos.x;
    shine16->mUnk_00.mPos.y = hitKart->mPos.y;
    shine16->mUnk_00.mPos.z = hitKart->mPos.z;
    shine16->mUnk_00.mUnk_10.x = 0;
    shine16->mUnk_00.mUnk_10.y = 0x1000;
    shine16->mUnk_00.mUnk_10.z = 0;
    shine16->mKartIndex = hitKart->mIndex;
    shine16->mHitByKartIndex = hitByKart->mIndex;
    shine16->mHeightAboveKart = 0;
    shine16->mFloorY = 0;
    shine16->mDrawScale = 0;
    shine16->mPickupTimer = 0;
    shine16->mState = 3;
    shine16->mTargetPos = hitByKart->mPos;
    if (hitByKart == hitKart) {
        shine16->mTargetDistanceSquared = 0;
    } else {
        shine16->mTargetDistanceSquared = 0x9c400;
    }
    shine16->mTargetPickCount = 0;
    shine16->mSpawnObjectIndex = -1;
    AddShineCount(1);
    isEntryKart = hitKart->mIndex == gRaceSetup->mEntryIndex ? 1 : 0;
    highestBalloonOrShineCount = GetHighestBalloonOrShineCount();
    balloonOrShineCount = GetBalloonOrShineCount(hitKart->mIndex);
    func_0210b98c(shine16->mUnk_00.mSound,
                  func_02024974(1, isEntryKart, highestBalloonOrShineCount, balloonOrShineCount));
}

BOOL BalloonKartHitByKartCallback(u16 hitKartIndex, u16 hitByKartIndex) {
    Kart *kart;
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;
    Vec3 balloonPos;
    s32 balloonOrShineCount;

    kart = GetKart(hitKartIndex);
    GetStandingsKartBalloons();
    if (GetBalloonOrShineCount(hitByKartIndex) >= 3 || GetBalloonOrShineCount(hitKartIndex) == 0) {
        kartBalloons = GetStandingsKartBalloons() + hitKartIndex;
        inflatingBalloon = IsKartInflatingBalloon(hitKartIndex) != 0
                               ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)]
                               : 0;
        lastBalloon = GetBalloonOrShineCount(hitKartIndex) != 0
                          ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex) - 1]
                          : 0;
        if (GetBalloonOrShineCount(hitKartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(hitKartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            if (hitKartIndex == gRaceSetup->mEntryIndex) {
                StartBalloonWithoutKart(lastBalloon, NULL);
            } else {
                balloonPos.x = kart->mPos.x;
                balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
                balloonPos.z = kart->mPos.z;
                lastBalloon->mUnk_00.mFlags &= ~4;
                lastBalloon->mUnk_00.mFlags &= ~2;
                lastBalloon->mUnk_00.mFlags &= ~8;
                lastBalloon->mUnk_00.mAlpha = 0x1f;
                StartBalloonWithoutKart(lastBalloon, &balloonPos);
            }
            func_020d26ec(kart, 0x153);
            if (GetBalloonOrShineCount(hitKartIndex) == 0) {
                EliminateKartAndCheckWinner(hitKartIndex);
            }
            return FALSE;
        }
    } else {
        kartBalloons = GetStandingsKartBalloons() + hitKartIndex;
        inflatingBalloon = IsKartInflatingBalloon(hitKartIndex) != 0
                               ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)]
                               : 0;
        lastBalloon = GetBalloonOrShineCount(hitKartIndex) != 0
                          ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex) - 1]
                          : 0;
        if (GetBalloonOrShineCount(hitKartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(hitKartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            kartBalloons = GetStandingsKartBalloons() + hitByKartIndex;
            balloonOrShineCount = GetBalloonOrShineCount(hitByKartIndex);
            kartBalloons->mBalloons[balloonOrShineCount + 1] =
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitByKartIndex)];
            kartBalloons->mBalloons[GetBalloonOrShineCount(hitByKartIndex)] = lastBalloon;
            AddBalloonOrShineCountAndMoveRank(hitByKartIndex, 1);
            func_020a2e68(lastBalloon);
            SetBalloonKartIndex(lastBalloon, hitByKartIndex);
            if (GetBalloonOrShineCount(hitByKartIndex) >= 2 && IsKartInflatingBalloon(hitByKartIndex) != 0) {
                kartBalloons->mState = 4;
            }
            SetupKartFollowEffect(StartEffect(0x7a, &kart->mPos), kart->mIndex, 0x20);
            SetupKartFollowEffect(StartEffect(0x7b, &kart->mPos), kart->mIndex, 0x20);
            func_020d26ec(GetKart(hitByKartIndex), 0x14f);
            if (GetBalloonOrShineCount(hitKartIndex) == 0) {
                EliminateKartAndCheckWinner(hitKartIndex);
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 BalloonKartsHitEachOtherCallback(u16 firstKartIndex, u16 secondKartIndex) {
    KartBalloons *firstKartBalloons;
    KartBalloons *secondKartBalloons;
    Balloon *firstInflatingBalloon;
    Balloon *firstLastBalloon;
    Balloon *secondInflatingBalloon;
    Balloon *secondLastBalloon;
    SoundStartParams soundStartParams;
    s32 balloonOrShineCount;

    firstKartBalloons = GetStandingsKartBalloons();
    firstKartBalloons += firstKartIndex;
    firstInflatingBalloon = IsKartInflatingBalloon(firstKartIndex) != 0
                                ? firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)]
                                : 0;
    firstLastBalloon = GetBalloonOrShineCount(firstKartIndex) != 0
                           ? firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex) - 1]
                           : 0;
    if (GetBalloonOrShineCount(firstKartIndex) != 0 && firstLastBalloon != NULL) {
        if (IsKartInflatingBalloon(firstKartIndex) != 0 && firstInflatingBalloon != NULL) {
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = firstLastBalloon;
            AddBalloonOrShineCountAndMoveRank(firstKartIndex, -1);
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = firstInflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(firstKartIndex, -1);
        }
    }
    secondKartBalloons = GetStandingsKartBalloons();
    secondKartBalloons += secondKartIndex;
    secondInflatingBalloon = IsKartInflatingBalloon(secondKartIndex) != 0
                                 ? secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)]
                                 : 0;
    secondLastBalloon = GetBalloonOrShineCount(secondKartIndex) != 0
                            ? secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex) - 1]
                            : 0;
    if (GetBalloonOrShineCount(secondKartIndex) != 0 && secondLastBalloon != NULL) {
        if (IsKartInflatingBalloon(secondKartIndex) != 0 && secondInflatingBalloon != NULL) {
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = secondLastBalloon;
            AddBalloonOrShineCountAndMoveRank(secondKartIndex, -1);
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = secondInflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(secondKartIndex, -1);
        }
    }
    if (firstLastBalloon != NULL) {
        secondKartBalloons = GetStandingsKartBalloons();
        secondKartBalloons += secondKartIndex;
        balloonOrShineCount = GetBalloonOrShineCount(secondKartIndex);
        secondKartBalloons->mBalloons[balloonOrShineCount + 1] =
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)];
        secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = firstLastBalloon;
        AddBalloonOrShineCountAndMoveRank(secondKartIndex, 1);
        func_020a2e68(firstLastBalloon);
        SetBalloonKartIndex(firstLastBalloon, secondKartIndex);
        if (GetBalloonOrShineCount(secondKartIndex) >= 2 && IsKartInflatingBalloon(secondKartIndex) != 0) {
            secondKartBalloons->mState = 4;
        }
    }
    if (secondLastBalloon != NULL) {
        firstKartBalloons = GetStandingsKartBalloons();
        firstKartBalloons += firstKartIndex;
        balloonOrShineCount = GetBalloonOrShineCount(firstKartIndex);
        firstKartBalloons->mBalloons[balloonOrShineCount + 1] =
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)];
        firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = secondLastBalloon;
        AddBalloonOrShineCountAndMoveRank(firstKartIndex, 1);
        func_020a2e68(secondLastBalloon);
        SetBalloonKartIndex(secondLastBalloon, firstKartIndex);
        if (GetBalloonOrShineCount(firstKartIndex) >= 2 && IsKartInflatingBalloon(firstKartIndex) != 0) {
            firstKartBalloons->mState = 4;
        }
    }
    if (firstKartIndex == gRaceSetup->mEntryIndex || secondKartIndex == gRaceSetup->mEntryIndex) {
        soundStartParams.mSoundId = 0x14f;
        soundStartParams.mPositionSource = NULL;
        soundStartParams.mFalloffIndex = 2;
        soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        StartSoundFromParams(&soundStartParams);
    }
    return 1;
}

BOOL BalloonKartHitCallback(u16 kartIndex, u16 hitByKartIndex) {
    Kart *kart;
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;
    Vec3 balloonPos;

    kartBalloons = GetStandingsKartBalloons() + kartIndex;
    inflatingBalloon =
        IsKartInflatingBalloon(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] : 0;
    lastBalloon =
        GetBalloonOrShineCount(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex) - 1] : 0;
    if (GetBalloonOrShineCount(kartIndex) != 0 && lastBalloon != NULL) {
        if (IsKartInflatingBalloon(kartIndex) != 0 && inflatingBalloon != NULL) {
            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = lastBalloon;
            AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = inflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
        }
    }
    if (lastBalloon != NULL) {
        kart = GetKart(kartIndex);
        GetStandingsKartBalloons();
        if (kartIndex == gRaceSetup->mEntryIndex) {
            StartBalloonWithoutKart(lastBalloon, NULL);
        } else {
            balloonPos.x = kart->mPos.x;
            balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
            balloonPos.z = kart->mPos.z;
            lastBalloon->mUnk_00.mFlags &= ~4;
            lastBalloon->mUnk_00.mFlags &= ~2;
            lastBalloon->mUnk_00.mFlags &= ~8;
            lastBalloon->mUnk_00.mAlpha = 0x1f;
            StartBalloonWithoutKart(lastBalloon, &balloonPos);
        }
        func_020d26ec(kart, 0x153);
        if (GetBalloonOrShineCount(kartIndex) == 0) {
            EliminateKartAndCheckWinner(kartIndex);
        }
        return TRUE;
    }
    return FALSE;
}

void BalloonKartEliminatedCallback(u16 kartIndex) {
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;

    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    BalloonKartHitCallback(kartIndex, kartIndex);
    if (GetBalloonOrShineCount(kartIndex) == 0) {
        return;
    }
    do {
        kartBalloons = GetStandingsKartBalloons() + kartIndex;
        inflatingBalloon =
            IsKartInflatingBalloon(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] : 0;
        lastBalloon =
            GetBalloonOrShineCount(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex) - 1] : 0;
        if (GetBalloonOrShineCount(kartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(kartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            ParkBalloon(lastBalloon, kartIndex);
        }
    } while (GetBalloonOrShineCount(kartIndex) != 0);
}

void BalloonEndCallback(void) {
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    ResetBalloons();
}

void BalloonKartOffsetCallback(u16 kartIndex, Vec3 *offset) {
    KartBalloons *kartBalloons;
    Balloon *balloon;
    s32 i;
    s32 balloonCount;

    kartBalloons = GetStandingsKartBalloons() + kartIndex;
    if (offset == NULL) {
        return;
    }
    balloonCount = (IsKartInflatingBalloon(kartIndex) != 0 ? 1 : 0) + GetBalloonOrShineCount(kartIndex);
    i = 0;
    if (balloonCount <= 0) {
        return;
    }
    do {
        balloon = kartBalloons->mBalloons[i];
        balloon->mUnk_00.mPos.x += offset->x;
        balloon->mUnk_00.mPos.y += offset->y;
        balloon->mUnk_00.mPos.z += offset->z;
        i++;
    } while (i < balloonCount);
}

// Init of the kind 0x69 object: creates and parks the kind 0x6c balloon objects (0x20 in mode 2, else 4), fills the
// frame indices, offsets and start timer, sets Standings.mKartBalloons and registers the callbacks in Standings (four
// hit callbacks, the kart-eliminated and the end callback). If kind 0x6c already exists it parks itself instead.
void InitKartBalloons(KartBalloonsObject *kartBalloonsObject) {
    RaceSetup *raceSetup;
    s32 kartCount;
    s32 i;
    KartBalloons *kartBalloons;
    s32 j;
    s32 rowOffset;
    s32 offset;

    if (CountMapObjectsOfKind(MAP_OBJECT_KIND_BALLOON) == 0) {
        raceSetup = gRaceSetup;
        kartCount = raceSetup->mKartCount;
        if (raceSetup->mMode == MODE_BATTLE) {
            CreateParkedMapObjects(MAP_OBJECT_KIND_BALLOON, 0x20, kartBalloonsObject);
        } else {
            CreateParkedMapObjects(MAP_OBJECT_KIND_BALLOON, 4, kartBalloonsObject);
        }
        for (i = 0; i < kartCount; i++) {
            kartBalloons = &kartBalloonsObject->mKartBalloons[i];
            if (kartBalloonsObject->mUnk_000.mCourseMapRow->mUnk_2c != 0) {
                kartBalloons->mBalloonNsbtpFrameIndex = kartBalloonsObject->mUnk_000.mCourseMapRow->mUnk_2c;
            } else {
                switch (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex) {
                    case 0:
                        kartBalloons->mBalloonNsbtpFrameIndex = 1;
                        break;
                    case 1:
                        kartBalloons->mBalloonNsbtpFrameIndex = 3;
                        break;
                    default:
                        kartBalloons->mBalloonNsbtpFrameIndex = i;
                        break;
                }
            }
        }
        for (i = 0, rowOffset = 0; i < 8; i++, rowOffset -= 0x600) {
            for (j = 0, offset = rowOffset; j < 8; j++, offset += 0xc00) {
                kartBalloonsObject->mBalloonOffsets[i][j] = offset;
            }
        }
        if (GetRaceUseChainCameras() != 0) {
            kartBalloonsObject->mStartTimer = 0xffff;
        } else {
            kartBalloonsObject->mStartTimer = 0x3c;
        }
        SetStandingsKartBalloons(kartBalloonsObject->mKartBalloons);
        SetStandingsKartHitByKartCallback((s32(*)(s32, s32)) BalloonKartHitByKartCallback);
        SetStandingsKartsHitEachOtherCallback((void (*)(s32, s32)) BalloonKartsHitEachOtherCallback);
        SetStandingsKartHitCallback(BalloonKartHitCallback);
        SetStandingsKartEliminatedCallback(BalloonKartEliminatedCallback);
        SetStandingsEndCallback(BalloonEndCallback);
        SetStandingsKartOffsetCallback(BalloonKartOffsetCallback);
    } else {
        ParkMapObject(&kartBalloonsObject->mUnk_000);
    }
}

// Per-frame step of the kind 0x69 object: after mStartTimer runs out it steps every kart's KartBalloons (makes,
// inflates, holds and deflates its balloons), updates the kart's count and hands each balloon its kart index, target
// position and velocity.
void UpdateKartBalloons(void *mapObjectList, KartBalloonsObject *kartBalloonsObject) {
    Balloon *balloon;
    s32 i;
    s32 j;
    s32 kartCount;
    s32 balloonCount;
    s32 sideOffset;
    s32 swingStep;
    s32 swingPerFrameDecrement;
    Vec3 balloonPos;
    Vec3 addend;
    Vec3 oddBalloonAddend;
    Vec3 *kartVector;

    kartCount = gRaceSetup->mKartCount;
    if (kartBalloonsObject->mStartTimer > 0) {
        kartBalloonsObject->mStartTimer--;
        if (kartBalloonsObject->mStartTimer > 0) {
            return;
        }
        for (i = 0; i < kartCount; i++) {
            KartBalloons *kartBalloons = &kartBalloonsObject->mKartBalloons[i];
            GetKart((u16) i);
            kartBalloons->mState = 1;
            if (kartBalloonsObject->mUnk_000.mCourseMapRow->mUnk_28 != 0 ||
                kartBalloonsObject->mUnk_000.mCourseMapRow->mUnk_2a != 0) {
                kartBalloons->mRemainingSpawnCount = kartBalloonsObject->mUnk_000.mCourseMapRow->mUnk_28;
                AddBalloonsLeftToMake(i, kartBalloonsObject->mUnk_000.mCourseMapRow->mUnk_28 +
                                             kartBalloonsObject->mUnk_000.mCourseMapRow->mUnk_2a);
            } else {
                kartBalloons->mRemainingSpawnCount = 1;
                AddBalloonsLeftToMake(i, 5);
            }
        }
        return;
    }
    for (i = 0; i < kartCount; i++) {
        Kart *kart;
        KartBalloons *kartBalloons = &kartBalloonsObject->mKartBalloons[i];
        GetChaseCamera();
        kart = GetKart((u16) i);
        balloonPos.x = kart->mPos.x;
        balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
        balloonPos.z = kart->mPos.z;
        switch (kartBalloons->mState) {
            case 0:
                if (kartBalloons->mSpawnTimer > 0) {
                    kartBalloons->mSpawnTimer--;
                    break;
                }
                if (GetBalloonsLeftToMake(i) == 0) {
                    break;
                }
                if (GetBalloonOrShineCount(i) >= 3) {
                    break;
                }
                if (func_020a2264(i) <= 0 && func_020a223c(i) <= 0) {
                    break;
                }
                balloon = StartBalloon(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                if (balloon == NULL) {
                    break;
                }
                kartBalloons->mBalloons[GetBalloonOrShineCount(i)] = balloon;
                UpdateBalloonInflating(balloon, i, 0xcd);
                kartBalloons->mState = 2;
                SetKartInflatingBalloon(i, 1);
                AddBalloonsLeftToMake(i, -1);
                break;
            case 1:
                if (IsKartInflatingBalloon(i) != 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(i)], i, 0x266);
                    break;
                }
                if (GetBalloonsLeftToMake(i) != 0 && GetBalloonOrShineCount(i) < 3) {
                    if (kartBalloons->mRemainingSpawnCount > 0) {
                        balloon = StartBalloon(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                        if (balloon != NULL) {
                            kartBalloons->mBalloons[GetBalloonOrShineCount(i)] = balloon;
                            UpdateBalloonInflating(balloon, i, 0x266);
                            SetKartInflatingBalloon(i, 1);
                            AddBalloonsLeftToMake(i, -1);
                            kartBalloons->mRemainingSpawnCount--;
                        }
                    }
                } else {
                    kartBalloons->mState = 0;
                }
                break;
            case 2:
                if (func_020a2264(i) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(i)];
                UpdateBalloonInflating(balloon, i, 0xcd);
                if (GetBalloonScaleFactor(balloon) >= 0x800) {
                    kartBalloons->mState = 3;
                }
                break;
            case 3:
                if (func_020a2264(i) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                if (func_020a223c(i) > 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(i)], i, 0x10);
                } else if (func_020a2264(i) > 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(i)], i, 0x29);
                } else {
                    balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(i)];
                    UpdateBalloonShrinking(balloon, i, 0xe);
                    if (GetBalloonScaleFactor(balloon) <= 0x400) {
                        kartBalloons->mState = 4;
                    }
                }
                break;
            case 4:
                UpdateBalloonShrinking(kartBalloons->mBalloons[GetBalloonOrShineCount(i)], i, 0x19a);
                break;
        }
        if (IsKartInflatingBalloon(i) != 0) {
            balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(i)];
            if (GetBalloonScaleFactor(balloon) <= 0) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(i)] = NULL;
                SetKartInflatingBalloon(i, 0);
                AddBalloonsLeftToMake(i, 1);
                kartBalloons->mSpawnTimer = 0;
                kartBalloons->mState = 0;
            } else if (GetBalloonScaleFactor(balloon) >= 0x1000) {
                SetKartInflatingBalloon(i, 0);
                AddBalloonOrShineCountAndMoveRank(i, 1);
                if (kartBalloons->mRemainingSpawnCount <= 0) {
                    kartBalloons->mSpawnTimer = 30;
                    kartBalloons->mState = 0;
                }
                func_020d26ec(GetKart((u16) i), 0x152);
            }
        } else if (kartBalloons->mRemainingSpawnCount <= 0) {
            kartBalloons->mState = 0;
        }
        if (i == gRaceSetup->mEntryIndex) {
            if (func_020a2264(i) > 0 || func_020a223c(i) > 0) {
                swingStep = GetBalloonOrShineCount(i) >= 3 ? 600 : 300;
                swingPerFrameDecrement = GetBalloonOrShineCount(i) >= 3 ? 200 : 100;
                kartBalloons->mSwing += kartBalloons->mSwingPerFrame;
                if (kartBalloons->mSwing >= 0) {
                    if (kartBalloons->mSwingPerFrame < 0) {
                        kartBalloons->mSwingPerFrame = -swingStep;
                    } else {
                        kartBalloons->mSwingPerFrame -= swingPerFrameDecrement;
                    }
                } else {
                    if (kartBalloons->mSwingPerFrame >= 0) {
                        kartBalloons->mSwingPerFrame = swingStep;
                    } else {
                        kartBalloons->mSwingPerFrame += swingPerFrameDecrement;
                    }
                }
            } else {
                swingStep = GetBalloonOrShineCount(i) >= 3 ? 600 : 300;
                if (kartBalloons->mSwing >= 0) {
                    kartBalloons->mSwing = kartBalloons->mSwing < swingStep ? 0 : kartBalloons->mSwing - swingStep;
                } else {
                    kartBalloons->mSwing = kartBalloons->mSwing > -swingStep ? 0 : kartBalloons->mSwing + swingStep;
                }
            }
            balloonCount = GetBalloonOrShineCount(i) + (IsKartInflatingBalloon(i) != 0 ? 1 : 0);
            for (j = 0; j < balloonCount; j++) {
                Balloon *balloon = kartBalloons->mBalloons[j];
                sideOffset = kartBalloons->mSwing + kartBalloonsObject->mBalloonOffsets[balloonCount - 1][j];
                if (sideOffset != 0) {
                    kartVector = &kart->mUnk_150;
                    addend.x = ((s64) kartVector->x * sideOffset) >> 12;
                    addend.y = ((s64) kartVector->y * sideOffset) >> 12;
                    addend.z = ((s64) kartVector->z * sideOffset) >> 12;
                    AddBalloonVelocity(balloon, &addend);
                }
                if ((j & 1) == 1) {
                    kartVector = &kart->mUnk_168;
                    oddBalloonAddend.x = ((s64) kartVector->x * -0xcd) >> 12;
                    oddBalloonAddend.y = ((s64) kartVector->y * -0xcd) >> 12;
                    oddBalloonAddend.z = ((s64) kartVector->z * -0xcd) >> 12;
                    AddBalloonVelocity(balloon, &oddBalloonAddend);
                }
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                SetBalloonKartIndex(balloon, i);
                SetBalloonDrawCountAndList(balloon, 1, NULL);
                balloon->mUnk_00.mFlags &= ~4;
                balloon->mUnk_00.mFlags &= ~2;
                balloon->mUnk_00.mFlags &= ~8;
                balloon->mUnk_00.mAlpha = 0x1f;
            }
        } else {
            balloonCount = GetBalloonOrShineCount(i) + (IsKartInflatingBalloon(i) != 0 ? 1 : 0);
            for (j = 0; j < balloonCount; j++) {
                balloon = kartBalloons->mBalloons[j];
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                SetBalloonKartIndex(balloon, i);
                if (j == 0) {
                    SetBalloonDrawCountAndList(balloon, balloonCount, kartBalloons->mBalloons);
                    balloon->mUnk_00.mFlags &= ~4;
                    balloon->mUnk_00.mFlags &= ~2;
                    balloon->mUnk_00.mFlags &= ~8;
                    balloon->mUnk_00.mAlpha = 0x1f;
                } else {
                    SetBalloonDrawCountAndList(balloon, 0, NULL);
                    balloon->mUnk_00.mFlags |= data_02156794;
                    balloon->mUnk_00.mFlags |= data_02156798;
                    balloon->mUnk_00.mFlags |= data_0215679c;
                }
            }
        }
    }
}

MapObjectKindData *CreateKartBalloonsKindData(void) {
    RaceSetup *raceSetup;
    s32 mode;

    raceSetup = gRaceSetup;
    mode = raceSetup->mMode;
    if (mode == MODE_BATTLE && raceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        return CreateEmptyMapObjectKindData();
    }
    if (mode != MODE_MISSION_RUN) {
        return 0;
    }
    return CreateEmptyMapObjectKindData();
}

void *CreateKartBalloonsUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateKartBalloons, NULL);
}
