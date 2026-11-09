#include "Main/Unknown/code_020dc428.h"

#include "Main/Unknown/code_020dc448.h"
#include "Main/Unknown/code_020dc474.h"
#include "Main/Unknown/code_020dda38.h" // WanwanChainObject
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dc5dc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d2000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffdee4.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020db000.h"
#include "Main/Unknown/code_020dc000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dbf7c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02077bc0.h"

MapObjectList *gWanwanUpdateList = 0;
Unk020dd804 *gWanwanDrawList = 0;

const Unk020dd860 data_02158388 = {
    CollideKartWithWanwan, CollideItemObjectWithWanwan, 1, 0x1b000, {0}, 1, 1, 0x12e, {0}};
const Unk020dd804 data_0215835c = {{0}, CreateWanwanAndRockShadow, {0}, DrawWanwan, {0}, 1, {0}, 0};
const MapObjectList data_02158334 = {NULL, 0, {0}, NULL, NULL, UpdateWanwan, NULL, 0, NULL, 0, NULL};

Unk020dd860 *CreateWanwanKindData(void) {
    Unk020dd860 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158388;
    return kindData;
}

Unk020dd804 *CreateWanwanDrawList(void) {
    Unk020dd804 *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gWanwanDrawList = drawList;
    *drawList = data_0215835c;
    SetDrawListSlot(&gWanwanDrawList);
    return gWanwanDrawList;
}

MapObjectList *CreateWanwanUpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gWanwanUpdateList = updateList;
    *updateList = data_02158334;
    SetUpdateListSlot(&gWanwanUpdateList);
    return gWanwanUpdateList;
}

void DrawWanwan(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha) {
    MtxFx43 shadowMatrix;

    if (wanwan->mMapObject.mStateMachine.mState == 4) {
        if (GetChoisesSOpenDuringRace() == 0) {
            wanwan->mMapObject.mPos.x += wanwan->mMapObject.mUnk_10.x;
            wanwan->mMapObject.mPos.z += wanwan->mMapObject.mUnk_10.z;
        }
    }
    wanwan->mMapObject.mMatrix.mUnk_00[3].x = wanwan->mMapObject.mPos.x >> 4;
    wanwan->mMapObject.mMatrix.mUnk_00[3].y = wanwan->mMapObject.mPos.y >> 4;
    wanwan->mMapObject.mMatrix.mUnk_00[3].z = wanwan->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gWanwan, &wanwan->mMapObject.mMatrix, &wanwan->mMapObject.mScale, maxAlpha);
    Matrix3x3FromQuaternion(&shadowMatrix.mUnk_00_m, &wanwan->mYawQuaternion);
    shadowMatrix.mUnk_00[3].x = wanwan->mMapObject.mPos.x >> 4;
    shadowMatrix.mUnk_00[3].y = wanwan->mMapObject.mPos.y >> 4;
    shadowMatrix.mUnk_00[3].z = wanwan->mMapObject.mPos.z >> 4;
    DrawShadowWithMaxAlpha(gWanwanRockShadow, &shadowMatrix, &wanwan->mMapObject.mScale, maxAlpha);
}

void UpdateWanwan(void *unused, Wanwan *wanwan) {
    u32 surfaceFlags;
    Quaternion targetOrientation;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    SoundStartParams b;
    SoundStartParams c;
    SoundStartParams d;
    s32 h;
    BOOL touchesGround;
    s32 x;
    s32 z;
    s32 t;
    s32 falloffIndex;

    h = wanwan->mUnk_b0;
    AdvanceStateMachine(&wanwan->mMapObject.mStateMachine);
    wanwan->mMapObject.mUnk_10.y -= 0x400;
    wanwan->mMapObject.mPos.y += wanwan->mMapObject.mUnk_10.y;
    touchesGround = FALSE;
    probePos.x = wanwan->mMapObject.mPos.x;
    probePos.y = wanwan->mMapObject.mPos.y + wanwan->mUnk_f4 + 0x5000;
    probePos.z = wanwan->mMapObject.mPos.z;
    if (h == 0) {
        correction.y = wanwan->mUnk_ac + 0xd000 - probePos.y;
        if (correction.y > 0) {
            touchesGround = TRUE;
            correction.x = 0;
            correction.z = 0;
            if (wanwan->mFollowsPath != 0) {
                if (!(wanwan->mMapObject.mDistanceSquaredAndFlags & 4)) {
                    if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        falloffIndex = 2;
                    } else if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    c.mSoundId = 0x1a1;
                    c.mPositionSource = &wanwan->mMapObject.mPos;
                    c.mFalloffIndex = falloffIndex;
                    c.mDistanceSquared = GetHorizontalCameraDistanceSquared(&wanwan->mMapObject.mPos);
                    StartSoundFromParams(&c);
                }
            }
        }
    } else {
        if (CollideSphereWithCourse(&probePos, NULL, 0, 0xd000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags,
                                    NULL, NULL, NULL, NULL) != 0) {
            touchesGround = TRUE;
            if (wanwan->mFollowsPath != 0) {
                if (!(wanwan->mMapObject.mDistanceSquaredAndFlags & 4)) {
                    if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        falloffIndex = 2;
                    } else if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    d.mSoundId = 0x1df;
                    d.mPositionSource = &wanwan->mMapObject.mPos;
                    d.mFalloffIndex = falloffIndex;
                    d.mDistanceSquared = GetHorizontalCameraDistanceSquared(&wanwan->mMapObject.mPos);
                    StartSoundFromParams(&d);
                }
            }
        }
    }
    if (touchesGround != FALSE) {
        touchesGround = TRUE;
        if (wanwan->mMapObject.mStateMachine.mState == 2) {
            if (wanwan->mMapObject.mStateMachine.mStateFrames < 0x78) {
                touchesGround = FALSE;
            }
        }
        wanwan->mMapObject.mPos.y += correction.y;
        if (wanwan->mFollowsPath != 0 || touchesGround != FALSE) {
            if (wanwan->mFollowsPath != 0) {
                x = wanwan->mFollower.mUnk_00.mToEntry->mPos.x;
                z = wanwan->mFollower.mUnk_00.mToEntry->mPos.z;
            } else {
                x = wanwan->mCurvePoints[2]->x - wanwan->mMapObject.mPos.x;
                z = wanwan->mCurvePoints[2]->z - wanwan->mMapObject.mPos.z;
            }
            t = ((s64) (s32) (((s64) wanwan->mMapObject.mUnk_10.x * x + (s64) wanwan->mMapObject.mUnk_10.z * z) >> 12)
                 << 9) >>
                12;
            if (t > 0x3000) {
                t = 0x3000;
            } else if (t < 0x2800) {
                t = 0x2800;
            }
            wanwan->mMapObject.mUnk_10.y = t;
        } else if (wanwan->mUnk_e8 == 0xd000) {
            wanwan->mMapObject.mUnk_10.y = 0x2000;
            wanwan->mUnk_e8 += 0x1000;
        } else {
            wanwan->mMapObject.mUnk_10.y = 0;
        }
        if (h != 0) {
            if (surfaceFlags & 0x1e34ef) {
                t = ((s64) wanwan->mMapObject.mUnk_10.x * surfaceNormal.x +
                     (s64) wanwan->mMapObject.mUnk_10.z * surfaceNormal.z) >>
                    12;
                if (t < 0) {
                    wanwan->mMapObject.mUnk_10.y += MUL_FIXED12_NO_ROUND(-t, 0x14cd);
                }
                QuaternionFromYAxisToVec3(&surfaceNormal, &wanwan->mSurfaceOrientation);
            }
        }
        if (wanwan->mFollowsPath == 0 && !(wanwan->mMapObject.mDistanceSquaredAndFlags & 4) && touchesGround != FALSE) {
            b = data_0216bedc;
            b.mPositionSource = &wanwan->mMapObject.mPos;
            b.mDistanceSquared = wanwan->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f;
            StartSoundFromParams(&b);
        }
    }
    if (h != 0) {
        QuaternionMultiplyByYawIgnoreY(&wanwan->mSurfaceOrientation, &wanwan->mYawQuaternion, &targetOrientation);
    }
    wanwan->mUnk_e4 = wanwan->mUnk_e4 + ((-wanwan->mMapObject.mUnk_10.y >> 1) - wanwan->mUnk_e4 >> 4);
    if (h != 0) {
        QuaternionMultiplyAngleAroundX(&targetOrientation, (u16) (wanwan->mUnk_e8 + wanwan->mUnk_e4),
                                       &targetOrientation);
    } else {
        QuaternionMultiplyAngleAroundXIgnoreXZ(&wanwan->mYawQuaternion, (u16) (wanwan->mUnk_e8 + wanwan->mUnk_e4),
                                               &targetOrientation);
    }
    QuaternionBlendTowardNearerSign(&wanwan->mOrientation, &targetOrientation, &wanwan->mOrientation,
                                    wanwan->mOrientationBlendAmount);
    QuaternionNormalizeUnlessNearOne(&wanwan->mOrientation, &wanwan->mOrientation);
    Matrix3x3FromQuaternion(&wanwan->mMapObject.mMatrix.mUnk_00_m, &wanwan->mOrientation);
    if (wanwan->mMapObject.mPos.y >= 0) {
        return;
    }
    ResetWanwan(wanwan);
}

u8 CollideKartWithWanwan(Wanwan *wanwan, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        if (wanwan->mMapObject.mStateMachine.mState != 2 || wanwan->mMapObject.mUnk_10.y < 0x4000) {
            wanwan->mMapObject.mStateMachine.mNextState = 2;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
            StartSoundIfKartStarOrKiller(&wanwan->mMapObject, kart);
        }
    }
    return *secondResponsePtr;
}

u8 CollideItemObjectWithWanwan(Wanwan *wanwan, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        if (wanwan->mMapObject.mStateMachine.mState != 2 || wanwan->mMapObject.mUnk_10.y < 0x4000) {
            wanwan->mMapObject.mStateMachine.mNextState = 2;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
    return *secondResponsePtr;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void EnterWanwanState0(Wanwan *wanwan) {
    Vec3 *savedPoint;

    wanwan->mUnk_e8 = 0x555;
    wanwan->mOrientationBlendAmount = 0x1c2;
    wanwan->mChainObject->mChain.mDownwardStep = 0x599;
    savedPoint = wanwan->mCurvePoints[0];
    wanwan->mCurvePoints[0] = NULL;
    *wanwan->mCurvePoints[1] = wanwan->mMapObject.mPos;
    *wanwan->mCurvePoints[2] = *wanwan->mCurvePoints[1];
    wanwan->mCurvePoints[2]->x += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mUnk_00[2].x, wanwan->mUnk_f0);
    wanwan->mCurvePoints[2]->z += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mUnk_00[2].z, wanwan->mUnk_f0);
    *wanwan->mCurvePoints[3] = *wanwan->mCurvePoints[2];
    wanwan->mCurvePoints[3]->x += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mUnk_00[0].x, wanwan->mUnk_f0);
    wanwan->mCurvePoints[3]->z += MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mMatrix.mUnk_00[0].z, wanwan->mUnk_f0);
    InitSegmentProgress(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints, 0x1000);
    wanwan->mCurvePoints[0] = savedPoint;
}

static inline s64 func_020dccc8_inline(const Vec3 *vector) {
    return (s64) vector->x * vector->x + (s64) vector->z * vector->z;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void UpdateWanwanState0(Wanwan *wanwan) {
    Vec3 *candidate;
    Vec3 *lastPoint;
    RandomState64 *random;
    Kart *kart;
    s32 attemptCount;
    s32 lastStepZ;
    s32 lastStepX;
    s32 radiusLimit;
    u32 radiusRange;
    s32 radiusExtra;
    s32 radius;
    s32 offsetX;
    s32 offsetZ;
    s32 dot;
    s32 e;
    u32 angleIndex;
    u16 kartIndex;

    wanwan->mMapObject.mUnk_10.x = wanwan->mMapObject.mPos.x;
    wanwan->mMapObject.mUnk_10.z = wanwan->mMapObject.mPos.z;
    if (AdvanceSegmentProgress(&wanwan->mSegmentProgress) != FALSE) {
        lastStepX = wanwan->mCurvePoints[3]->x - wanwan->mCurvePoints[2]->x;
        lastStepZ = wanwan->mCurvePoints[3]->z - wanwan->mCurvePoints[2]->z;
        do {
            attemptCount = 0;
            candidate = wanwan->mCurvePoints[0];
            while (1) {
                radiusLimit = wanwan->mUnk_f8;
                random = GetMapObjectRandom();
                radiusRange = radiusLimit - 0x2d000;
                if (radiusRange == 0) {
                    radiusExtra = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    if (radiusRange == 0) {
                        radiusExtra = (u32) (random->mValue >> 32);
                    } else {
                        radiusExtra = (u32) (((u64) (random->mValue >> 32) * (u64) radiusRange) >> 32);
                    }
                }
                random = GetMapObjectRandom();
                radius = radiusExtra + 0x2d000;
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                angleIndex = (u16) (((random->mValue >> 32) * 0x10000) >> 32) >> 4;
                attemptCount++;
                candidate->x = wanwan->mCenterPos.x + MUL_FIXED12_NO_ROUND(gPairsByAngle[angleIndex * 2], radius);
                candidate->z =
                    wanwan->mCenterPos.z + MUL_FIXED12_NO_ROUND(gPairsByAngle[angleIndex * 2 + 1], radius);
                if (attemptCount > 5) {
                    break;
                }
                lastPoint = wanwan->mCurvePoints[3];
                offsetX = candidate->x - lastPoint->x;
                offsetZ = candidate->z - lastPoint->z;
                if ((s64) (s32) offsetX * offsetX + (s64) (s32) offsetZ * offsetZ < 0x7e9000000LL) {
                    continue;
                }
                dot = ((s64) offsetX * lastStepX + (s64) offsetZ * lastStepZ) >> 12;
                if (dot < 0) {
                    dot = -dot;
                    e = (-(s64) offsetX * lastStepZ + (s64) offsetZ * lastStepX) >> 12;
                    if (e < 0) {
                        e = -e;
                    }
                    if (dot >> 2 >= e) {
                        continue;
                    }
                }
                break;
            }
            wanwan->mCurvePoints[0] = wanwan->mCurvePoints[1];
            wanwan->mCurvePoints[1] = wanwan->mCurvePoints[2];
            wanwan->mCurvePoints[2] = wanwan->mCurvePoints[3];
            wanwan->mCurvePoints[3] = candidate;
        } while (BuildNextSegmentProgress(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints) != FALSE);
    }
    GetSegmentProgressPointXz(&wanwan->mSegmentProgress, &wanwan->mMapObject.mPos);
    if (!(wanwan->mMapObject.mFlags & 0x800)) {
        kartIndex = GetRaceUpdateFramesModKartCount();
        kart = GetKart(kartIndex);
        if (func_0206c0e0(kart) == FALSE) {
            e = wanwan->mUnk_1dc;
            if ((s64) (kart->mPos.x - wanwan->mCenterPos.x) * (kart->mPos.x - wanwan->mCenterPos.x) +
                    (s64) (kart->mPos.z - wanwan->mCenterPos.z) * (kart->mPos.z - wanwan->mCenterPos.z) <
                (s64) e * e) {
                wanwan->mKartPos = &GetKart(kartIndex)->mPos;
                wanwan->mKartVelocity = &GetKart(kartIndex)->mVelocity;
                wanwan->mMapObject.mStateMachine.mNextState = 1;
                wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
            }
        }
    }
    wanwan->mMapObject.mUnk_10.x = wanwan->mMapObject.mPos.x - wanwan->mMapObject.mUnk_10.x;
    wanwan->mMapObject.mUnk_10.z = wanwan->mMapObject.mPos.z - wanwan->mMapObject.mUnk_10.z;
    if (func_020dccc8_inline(&wanwan->mMapObject.mUnk_10) >= 0x10) {
        QuaternionFromAngleAroundY(
            (u16) (((s64) FX_Atan2(wanwan->mMapObject.mUnk_10.x, wanwan->mMapObject.mUnk_10.z) * 0x28be60db9391LL +
                    0x80000000000LL) >>
                   44),
            &wanwan->mYawQuaternion);
    }
    if (wanwan->mMapObject.mStateMachine.mStateFrames < 0x40) {
        wanwan->mOrientationBlendAmount += 0x1c;
    }
}

void EnterWanwanState1(Wanwan *wanwan) {
    SoundStartParams soundRequest;
    s32 falloffIndex;

    wanwan->mUnk_e8 = 0x2000;
    wanwan->mOrientationBlendAmount = 0x1c2;
    wanwan->mUnk_1e0 = wanwan->mMapObject.mPos;
    wanwan->mChainObject->mChain.mDownwardStep = 0x219;
    wanwan->mUnk_1f8 = 0;
    if (wanwan->mMapObject.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        falloffIndex = 2;
    } else if (wanwan->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    soundRequest.mSoundId = 0x12c;
    soundRequest.mPositionSource = &wanwan->mMapObject.mPos;
    soundRequest.mFalloffIndex = falloffIndex;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&wanwan->mMapObject.mPos);
    StartSoundFromParams(&soundRequest);
}

void UpdateWanwanState1(Wanwan *wanwan) {
    Vec3 a;
    Vec3 predictedPos;
    s32 t;
    s32 k;
    s32 m;

    if (wanwan->mMapObject.mStateMachine.mStateFrames > wanwan->mUnk_1f8) {
        VEC_Subtract(wanwan->mKartPos, &wanwan->mMapObject.mPos, &a);
        t = ((s64) wanwan->mKartVelocity->x * a.z - (s64) wanwan->mKartVelocity->z * a.x) >> 12;
        t = -t >> 12;
        if (t < 0) {
            t = -t;
        }
        k = MUL_FIXED12_NO_ROUND(t, 0x7a);
        predictedPos.x = wanwan->mKartVelocity->x * k;
        predictedPos.z = wanwan->mKartVelocity->z * k;
        VEC_Add(&predictedPos, wanwan->mKartPos, &predictedPos);
        VEC_Subtract(&predictedPos, &wanwan->mCenterPos, &a);
        m = Vec3NormalizeXZAndGetLengthOrZero(&a, &a);
        if (m > wanwan->mUnk_f0) {
            m -= wanwan->mUnk_f0 >> 1;
        }
        if (m > wanwan->mMaxRadius) {
            m = wanwan->mMaxRadius;
        }
        a.x = MUL_FIXED12_NO_ROUND(a.x, m);
        a.y = MUL_FIXED12_NO_ROUND(a.y, m);
        a.z = MUL_FIXED12_NO_ROUND(a.z, m);
        VEC_Add(&a, &wanwan->mCenterPos, &wanwan->mUnk_1e0);
        wanwan->mUnk_1f8 += 0xb4;
    }
    VEC_Subtract(&wanwan->mUnk_1e0, &wanwan->mMapObject.mPos, &a);
    wanwan->mMapObject.mUnk_10.x += (s32) (((s64) a.x << 5) >> 12);
    wanwan->mMapObject.mUnk_10.z += (s32) (((s64) a.z << 5) >> 12);
    if (func_020dccc8_inline(&wanwan->mMapObject.mUnk_10) >= 0x40000000) {
        wanwan->mMapObject.mUnk_10.x -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.x, 0x4cc);
        wanwan->mMapObject.mUnk_10.z -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.z, 0x4cc);
    }
    if (func_020dccc8_inline(&a) < (s64) (wanwan->mUnk_f0 >> 1) * (wanwan->mUnk_f0 >> 1)) {
        wanwan->mMapObject.mUnk_10.x >>= 1;
        wanwan->mMapObject.mUnk_10.z >>= 1;
    } else {
        QuaternionFromAngleAroundY((u16) (((s64) FX_Atan2(a.x, a.z) * 0x28be60db9391LL + 0x80000000000LL) >> 44),
                                   &wanwan->mYawQuaternion);
    }
    t = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.x, a.z);
    t -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.z, a.x);
    if (((s64) a.x * a.x + (s64) a.z * a.z) * 10 < (s64) t * t) {
        wanwan->mMapObject.mUnk_10.x >>= 1;
        wanwan->mMapObject.mUnk_10.z >>= 1;
    }
    wanwan->mMapObject.mPos.x += wanwan->mMapObject.mUnk_10.x;
    wanwan->mMapObject.mPos.z += wanwan->mMapObject.mUnk_10.z;
    VEC_Subtract(&wanwan->mMapObject.mPos, &wanwan->mCenterPos, &a);
    if ((s64) a.x * a.x + (s64) a.z * a.z >= (s64) wanwan->mMaxRadius * wanwan->mMaxRadius) {
        Vec3NormalizeXZAndGetLengthOrZero(&a, &a);
        wanwan->mMapObject.mPos.x = wanwan->mCenterPos.x + MUL_FIXED12_NO_ROUND(a.x, wanwan->mMaxRadius);
        wanwan->mMapObject.mPos.z = wanwan->mCenterPos.z + MUL_FIXED12_NO_ROUND(a.z, wanwan->mMaxRadius);
        k = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.x, a.x);
        m = MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.z, a.z);
        if (k + m > 0) {
            wanwan->mMapObject.mUnk_10.x -= MUL_FIXED12_NO_ROUND(k, a.x);
            wanwan->mMapObject.mUnk_10.z -= MUL_FIXED12_NO_ROUND(m, a.z);
        }
    }
    if (wanwan->mMapObject.mStateMachine.mStateFrames >= 0xb4) {
        wanwan->mMapObject.mStateMachine.mNextState = 3;
        wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanState2(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0xd000;
    wanwan->mOrientationBlendAmount = 0x1c2;
    if (wanwan->mFollowsPath == 0) {
        wanwan->mChainObject->mChain.mDownwardStep = 0x219;
    }
    wanwan->mMapObject.mUnk_10.y = 0x8000;
}

void UpdateWanwanState2(Wanwan *wanwan) {
    const Vec3 *velocity;

    if (wanwan->mFollowsPath != 0) {
        wanwan->mMapObject.mUnk_10.x = wanwan->mMapObject.mPos.x;
        wanwan->mMapObject.mUnk_10.z = wanwan->mMapObject.mPos.z;
        AdvanceGroupFollowerWithSpeeds(&wanwan->mFollower);
        GetGroupFollowerCurveXz(&wanwan->mFollower.mUnk_00, &wanwan->mMapObject.mPos);
        wanwan->mMapObject.mUnk_10.x = wanwan->mMapObject.mPos.x - wanwan->mMapObject.mUnk_10.x;
        wanwan->mMapObject.mUnk_10.z = wanwan->mMapObject.mPos.z - wanwan->mMapObject.mUnk_10.z;
        velocity = &wanwan->mMapObject.mUnk_10;
        if ((s64) velocity->x * velocity->x + (s64) velocity->z * velocity->z >= 0x10) {
            QuaternionFromAngleAroundY(
                (u16) (((s64) FX_Atan2(wanwan->mMapObject.mUnk_10.x, wanwan->mMapObject.mUnk_10.z) * 0x28be60db9391LL +
                        0x80000000000LL) >>
                       44),
                &wanwan->mYawQuaternion);
        }
        if (wanwan->mMapObject.mStateMachine.mStateFrames < 0x40) {
            wanwan->mOrientationBlendAmount += 0x1c;
        }
        if (wanwan->mMapObject.mStateMachine.mStateFrames >= 0x28) {
            wanwan->mUnk_e8 += 0x200;
        } else {
            wanwan->mMapObject.mUnk_10.y -= 0x266;
        }
        if (wanwan->mUnk_e8 > 0x10555) {
            wanwan->mMapObject.mStateMachine.mNextState = 5;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    } else {
        if (wanwan->mUnk_e8 == 0xd000) {
            wanwan->mMapObject.mUnk_10.y -= 0x19a;
        }
        if (wanwan->mMapObject.mStateMachine.mStateFrames >= 0x78) {
            wanwan->mUnk_e8 += 0x100;
        }
        if (wanwan->mUnk_e8 > 0x10555) {
            wanwan->mMapObject.mStateMachine.mNextState = 3;
            wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterWanwanState3(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0x555;
    wanwan->mOrientationBlendAmount = 0x1c2;
    wanwan->mChainObject->mChain.mDownwardStep = 0x599;
}

static inline s64 func_020dc474_inline(const Vec3 *vector) {
    return (s64) vector->x * vector->x + (s64) vector->z * vector->z;
}

void UpdateWanwanState3(Wanwan *wanwan) {
    Vec3 toCenter;
    s32 radius;

    radius = wanwan->mUnk_1fc;
    if ((s64) (wanwan->mMapObject.mPos.x - wanwan->mCenterPos.x) * (wanwan->mMapObject.mPos.x - wanwan->mCenterPos.x) +
            (s64) (wanwan->mMapObject.mPos.z - wanwan->mCenterPos.z) *
                (wanwan->mMapObject.mPos.z - wanwan->mCenterPos.z) >=
        (s64) radius * radius) {
        VEC_Subtract(&wanwan->mCenterPos, &wanwan->mMapObject.mPos, &toCenter);
        wanwan->mMapObject.mUnk_10.x += (s32) (((s64) toCenter.x << 2) >> 12);
        wanwan->mMapObject.mUnk_10.z += (s32) (((s64) toCenter.z << 2) >> 12);
        if (func_020dc474_inline(&wanwan->mMapObject.mUnk_10) >= 0x1000000) {
            wanwan->mMapObject.mUnk_10.x -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.x, 0x199);
            wanwan->mMapObject.mUnk_10.z -= MUL_FIXED12_NO_ROUND(wanwan->mMapObject.mUnk_10.z, 0x199);
        }
        wanwan->mMapObject.mPos.x += wanwan->mMapObject.mUnk_10.x;
        wanwan->mMapObject.mPos.z += wanwan->mMapObject.mUnk_10.z;
    }
    if (wanwan->mMapObject.mStateMachine.mStateFrames >= 0xb4) {
        wanwan->mMapObject.mStateMachine.mNextState = 0;
        wanwan->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanState4(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0x555;
    wanwan->mOrientationBlendAmount = 0x1c2;
    wanwan->mChainObject->mChain.mDownwardStep = 0x599;
}

void UpdateWanwanState4Nop(Wanwan *wanwan) {}

void EnterWanwanState5(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0x555;
    wanwan->mOrientationBlendAmount = 0x1c2;
}
