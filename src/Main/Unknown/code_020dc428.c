#include "Main/Unknown/code_020dc428.h"

#include "Main/Unknown/code_020dc448.h"
#include "Main/Unknown/code_020dc474.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dc5dc.h"
#include "Main/System/Heap.h"
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
#include "Main/Ui/ChoisesS.h"
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

MapObjectList *wanwan_sLogicPart = 0;
Unk020dd804 *wanwan_sRenderPart = 0;

const Unk020dd860 data_02158388 = {wanwan_onDriverCollide, wanwan_onItemCollide, 1, 0x1b000, {0}, 1, 1, 0x12e, {0}};
const Unk020dd804 data_0215835c = {{0}, wanwan_loadModels, {0}, wanwan_render, {0}, 1, {0}, 0};
const MapObjectList data_02158334 = {NULL, 0, {0}, NULL, NULL, wanwan_update, NULL, 0, NULL, 0, NULL};

Unk020dd860 *wanwan_setupCollision(void) {
    Unk020dd860 *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_02158388;
    return kindData;
}

Unk020dd804 *wanwan_setupRenderPart(void) {
    Unk020dd804 *drawList;

    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    wanwan_sRenderPart = drawList;
    *drawList = data_0215835c;
    mobj_renderPartSetThisPointer(&wanwan_sRenderPart);
    return wanwan_sRenderPart;
}

MapObjectList *wanwan_setupLogicPart(void) {
    MapObjectList *updateList;

    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    wanwan_sLogicPart = updateList;
    *updateList = data_02158334;
    mobj_logicPartSetThisPointer(&wanwan_sLogicPart);
    return wanwan_sLogicPart;
}

void wanwan_render(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha) {
    MtxFx43 shadowMatrix;

    if (wanwan->field0.mStateMachine.mState == 4) {
        if (rchoi_getIsRacePaused() == 0) {
            wanwan->field0.mPos.x += wanwan->field0.field10.x;
            wanwan->field0.mPos.z += wanwan->field0.field10.z;
        }
    }
    wanwan->field0.mMatrix.field0[3].x = wanwan->field0.mPos.x >> 4;
    wanwan->field0.mMatrix.field0[3].y = wanwan->field0.mPos.y >> 4;
    wanwan->field0.mMatrix.field0[3].z = wanwan->field0.mPos.z >> 4;
    model2_renderModel(wanwan_sModel, &wanwan->field0.mMatrix, &wanwan->field0.mScale, maxAlpha);
    qtrn_toMtx33(&shadowMatrix, &wanwan->fieldD4);
    shadowMatrix.field0[3].x = wanwan->field0.mPos.x >> 4;
    shadowMatrix.field0[3].y = wanwan->field0.mPos.y >> 4;
    shadowMatrix.field0[3].z = wanwan->field0.mPos.z >> 4;
    model2_renderShadowModel(wanwan_sShadowModel, &shadowMatrix, &wanwan->field0.mScale, maxAlpha);
}

void wanwan_update(void *unused, Wanwan *wanwan) {
    u32 surfaceFlags;
    Quaternion targetOrientation;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    Unk0210b7a8 b;
    Unk0210b7a8 c;
    Unk0210b7a8 d;
    s32 h;
    BOOL k;
    s32 x;
    s32 z;
    s32 t;
    s32 y;

    h = wanwan->fieldB0;
    sm_execute(&wanwan->field0.mStateMachine);
    wanwan->field0.field10.y -= 0x400;
    wanwan->field0.mPos.y += wanwan->field0.field10.y;
    k = FALSE;
    probePos.x = wanwan->field0.mPos.x;
    probePos.y = wanwan->field0.mPos.y + wanwan->fieldF4 + 0x5000;
    probePos.z = wanwan->field0.mPos.z;
    if (h == 0) {
        correction.y = wanwan->fieldAC + 0xd000 - probePos.y;
        if (correction.y > 0) {
            k = TRUE;
            correction.x = 0;
            correction.z = 0;
            if (wanwan->fieldFC != 0) {
                if (!(wanwan->field0.mDistanceSquaredAndFlags & 4)) {
                    if (wanwan->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                        y = 2;
                    } else if (wanwan->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                        y = 3;
                    } else {
                        y = 4;
                    }
                    c.mSoundId = 0x1a1;
                    c.mPositionSource = &wanwan->field0.mPos;
                    c.field8 = y;
                    c.mDistanceSquared = mobj_calcXZCamDist(&wanwan->field0.mPos);
                    func_0210b7a8(&c);
                }
            }
        }
    } else {
        if (col_collide(&probePos, NULL, 0, 0xd000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags, NULL,
                          NULL, NULL, NULL) != 0) {
            k = TRUE;
            if (wanwan->fieldFC != 0) {
                if (!(wanwan->field0.mDistanceSquaredAndFlags & 4)) {
                    if (wanwan->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                        y = 2;
                    } else if (wanwan->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                        y = 3;
                    } else {
                        y = 4;
                    }
                    d.mSoundId = 0x1df;
                    d.mPositionSource = &wanwan->field0.mPos;
                    d.field8 = y;
                    d.mDistanceSquared = mobj_calcXZCamDist(&wanwan->field0.mPos);
                    func_0210b7a8(&d);
                }
            }
        }
    }
    if (k != FALSE) {
        k = TRUE;
        if (wanwan->field0.mStateMachine.mState == 2) {
            if (wanwan->field0.mStateMachine.mStateFrames < 0x78) {
                k = FALSE;
            }
        }
        wanwan->field0.mPos.y += correction.y;
        if (wanwan->fieldFC != 0 || k != FALSE) {
            if (wanwan->fieldFC != 0) {
                x = wanwan->mFollower.field0.mToEntry->mPos.x;
                z = wanwan->mFollower.field0.mToEntry->mPos.z;
            } else {
                x = wanwan->mCurvePoints[2]->x - wanwan->field0.mPos.x;
                z = wanwan->mCurvePoints[2]->z - wanwan->field0.mPos.z;
            }
            t = ((s64) (s32) (((s64) wanwan->field0.field10.x * x + (s64) wanwan->field0.field10.z * z) >> 12)
                 << 9) >>
                12;
            if (t > 0x3000) {
                t = 0x3000;
            } else if (t < 0x2800) {
                t = 0x2800;
            }
            wanwan->field0.field10.y = t;
        } else if (wanwan->fieldE8 == 0xd000) {
            wanwan->field0.field10.y = 0x2000;
            wanwan->fieldE8 += 0x1000;
        } else {
            wanwan->field0.field10.y = 0;
        }
        if (h != 0) {
            if (surfaceFlags & 0x1e34ef) {
                t = ((s64) wanwan->field0.field10.x * surfaceNormal.x +
                     (s64) wanwan->field0.field10.z * surfaceNormal.z) >>
                    12;
                if (t < 0) {
                    wanwan->field0.field10.y += (s32) (((s64) -t * 0x14cd) >> 12);
                }
                qrtn_fromForwardVec(&surfaceNormal, &wanwan->fieldC4);
            }
        }
        if (wanwan->fieldFC == 0 && !(wanwan->field0.mDistanceSquaredAndFlags & 4) && k != FALSE) {
            b = data_0216bedc;
            b.mPositionSource = &wanwan->field0.mPos;
            b.mDistanceSquared = wanwan->field0.mDistanceSquaredAndFlags & ~0xc000001f;
            func_0210b7a8(&b);
        }
    }
    if (h != 0) {
        qrtn_20D7938(&wanwan->fieldC4, &wanwan->fieldD4, &targetOrientation);
    }
    wanwan->fieldE4 = wanwan->fieldE4 + ((-wanwan->field0.field10.y >> 1) - wanwan->fieldE4 >> 4);
    if (h != 0) {
        Quaternion_Rotate_20D788C(&targetOrientation, (u16) (wanwan->fieldE8 + wanwan->fieldE4),
                                       &targetOrientation);
    } else {
        Quaternion_Rotate_20D76A8(&wanwan->fieldD4, (u16) (wanwan->fieldE8 + wanwan->fieldE4), &targetOrientation);
    }
    qrtn_slerp(&wanwan->fieldB4, &targetOrientation, &wanwan->fieldB4, wanwan->fieldEC);
    qtrn_normalize(&wanwan->fieldB4, &wanwan->fieldB4);
    qtrn_toMtx33(&wanwan->field0.mMatrix, &wanwan->fieldB4);
    if (wanwan->field0.mPos.y >= 0) {
        return;
    }
    wanwan_20DBF7C(wanwan);
}

u8 wanwan_onDriverCollide(Wanwan *wanwan, void *kart, u8 *b, u8 *c) {
    if (*b == 1) {
        if (wanwan->field0.mStateMachine.mState != 2 || wanwan->field0.field10.y < 0x4000) {
            wanwan->field0.mStateMachine.mNextState = 2;
            wanwan->field0.mStateMachine.mNextStateRequested = 1;
            mobj_tryDestroyByDriver(&wanwan->field0, kart);
        }
    }
    return *c;
}

u8 wanwan_onItemCollide(Wanwan *wanwan, void *kart, u8 *b, u8 *c) {
    if (*b == 1) {
        if (wanwan->field0.mStateMachine.mState != 2 || wanwan->field0.field10.y < 0x4000) {
            wanwan->field0.mStateMachine.mNextState = 2;
            wanwan->field0.mStateMachine.mNextStateRequested = 1;
        }
    }
    return *c;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void wanwan_state0Init(Wanwan *wanwan) {
    Vec3 *savedPoint;

    wanwan->fieldE8 = 0x555;
    wanwan->fieldEC = 0x1c2;
    wanwan->mChainObject->fieldA8 = 0x599;
    savedPoint = wanwan->mCurvePoints[0];
    wanwan->mCurvePoints[0] = NULL;
    *wanwan->mCurvePoints[1] = wanwan->field0.mPos;
    *wanwan->mCurvePoints[2] = *wanwan->mCurvePoints[1];
    wanwan->mCurvePoints[2]->x += (s32) (((s64) wanwan->field0.mMatrix.field0[2].x * wanwan->fieldF0) >> 12);
    wanwan->mCurvePoints[2]->z += (s32) (((s64) wanwan->field0.mMatrix.field0[2].z * wanwan->fieldF0) >> 12);
    *wanwan->mCurvePoints[3] = *wanwan->mCurvePoints[2];
    wanwan->mCurvePoints[3]->x += (s32) (((s64) wanwan->field0.mMatrix.field0[0].x * wanwan->fieldF0) >> 12);
    wanwan->mCurvePoints[3]->z += (s32) (((s64) wanwan->field0.mMatrix.field0[0].z * wanwan->fieldF0) >> 12);
    func_020d7d18(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints, 0x1000);
    wanwan->mCurvePoints[0] = savedPoint;
}

static inline s64 func_020dccc8_inline(const Vec3 *vector) {
    return (s64) vector->x * vector->x + (s64) vector->z * vector->z;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void wanwan_state0Update(Wanwan *wanwan) {
    Vec3 *candidate;
    Vec3 *lastPoint;
    RandomState64 *random;
    Kart *kart;
    s32 attemptCount;
    s32 lastStepZ;
    s32 lastStepX;
    s32 a;
    u32 n;
    s32 v;
    s32 radius;
    s32 offsetX;
    s32 offsetZ;
    s32 dot;
    s32 e;
    u32 angleIndex;
    u16 kartIndex;

    wanwan->field0.field10.x = wanwan->field0.mPos.x;
    wanwan->field0.field10.z = wanwan->field0.mPos.z;
    if (pwex_20D849C(&wanwan->mSegmentProgress) != FALSE) {
        lastStepX = wanwan->mCurvePoints[3]->x - wanwan->mCurvePoints[2]->x;
        lastStepZ = wanwan->mCurvePoints[3]->z - wanwan->mCurvePoints[2]->z;
        do {
            attemptCount = 0;
            candidate = wanwan->mCurvePoints[0];
            while (1) {
                a = wanwan->fieldF8;
                random = mobj_getRng1();
                n = a - 0x2d000;
                if (n == 0) {
                    v = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    if (n == 0) {
                        v = (u32) (random->mValue >> 32);
                    } else {
                        v = (u32) (((u64) (random->mValue >> 32) * (u64) n) >> 32);
                    }
                }
                random = mobj_getRng1();
                radius = v + 0x2d000;
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                angleIndex = (u16) (((random->mValue >> 32) * 0x10000) >> 32) >> 4;
                attemptCount++;
                candidate->x = wanwan->mCenterPos.x + (s32) (((s64) FX_SinCosTable_[angleIndex * 2] * radius) >> 12);
                candidate->z = wanwan->mCenterPos.z + (s32) (((s64) FX_SinCosTable_[angleIndex * 2 + 1] * radius) >> 12);
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
        } while (func_020d7c84(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints) != FALSE);
    }
    pwex_interpolateXZ(&wanwan->mSegmentProgress, &wanwan->field0.mPos);
    if (!(wanwan->field0.mFlags & 0x800)) {
        kartIndex = race_getFrameCounterModuloDriverCount();
        kart = driver_getById(kartIndex);
        if (func_0206c0e0(kart) == FALSE) {
            e = wanwan->field1DC;
            if ((s64) (kart->mPos.x - wanwan->mCenterPos.x) * (kart->mPos.x - wanwan->mCenterPos.x) +
                    (s64) (kart->mPos.z - wanwan->mCenterPos.z) * (kart->mPos.z - wanwan->mCenterPos.z) <
                (s64) e * e) {
                wanwan->mKartPos = &driver_getById(kartIndex)->mPos;
                wanwan->mKartVelocity = &driver_getById(kartIndex)->mVelocity;
                wanwan->field0.mStateMachine.mNextState = 1;
                wanwan->field0.mStateMachine.mNextStateRequested = 1;
            }
        }
    }
    wanwan->field0.field10.x = wanwan->field0.mPos.x - wanwan->field0.field10.x;
    wanwan->field0.field10.z = wanwan->field0.mPos.z - wanwan->field0.field10.z;
    if (func_020dccc8_inline(&wanwan->field0.field10) >= 0x10) {
        qrtn_fromYAngle(
            (u16) (((s64) FX_Atan2(wanwan->field0.field10.x, wanwan->field0.field10.z) * 0x28be60db9391LL +
                    0x80000000000LL) >>
                   44),
            &wanwan->fieldD4);
    }
    if (wanwan->field0.mStateMachine.mStateFrames < 0x40) {
        wanwan->fieldEC += 0x1c;
    }
}

void wanwan_state1Init(Wanwan *wanwan) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;

    wanwan->fieldE8 = 0x2000;
    wanwan->fieldEC = 0x1c2;
    wanwan->field1E0 = wanwan->field0.mPos;
    wanwan->mChainObject->fieldA8 = 0x219;
    wanwan->field1F8 = 0;
    if (wanwan->field0.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (wanwan->field0.mFarDistanceSquared == gSfxParams[2].field20) {
        falloffIndex = 2;
    } else if (wanwan->field0.mFarDistanceSquared == gSfxParams[3].field20) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    soundRequest.mSoundId = 0x12c;
    soundRequest.mPositionSource = &wanwan->field0.mPos;
    soundRequest.field8 = falloffIndex;
    soundRequest.mDistanceSquared = mobj_calcXZCamDist(&wanwan->field0.mPos);
    func_0210b7a8(&soundRequest);
}

void wanwan_state1Update(Wanwan *wanwan) {
    Vec3 a;
    Vec3 predictedPos;
    s32 t;
    s32 k;
    s32 m;

    if (wanwan->field0.mStateMachine.mStateFrames > wanwan->field1F8) {
        VEC_Subtract(wanwan->mKartPos, &wanwan->field0.mPos, &a);
        t = ((s64) wanwan->mKartVelocity->x * a.z - (s64) wanwan->mKartVelocity->z * a.x) >> 12;
        t = -t >> 12;
        if (t < 0) {
            t = -t;
        }
        k = ((s64) t * 0x7a) >> 12;
        predictedPos.x = wanwan->mKartVelocity->x * k;
        predictedPos.z = wanwan->mKartVelocity->z * k;
        VEC_Add(&predictedPos, wanwan->mKartPos, &predictedPos);
        VEC_Subtract(&predictedPos, &wanwan->mCenterPos, &a);
        m = vec_normalizeXZFast(&a, &a);
        if (m > wanwan->fieldF0) {
            m -= wanwan->fieldF0 >> 1;
        }
        if (m > wanwan->mMaxRadius) {
            m = wanwan->mMaxRadius;
        }
        a.x = ((s64) a.x * m) >> 12;
        a.y = ((s64) a.y * m) >> 12;
        a.z = ((s64) a.z * m) >> 12;
        VEC_Add(&a, &wanwan->mCenterPos, &wanwan->field1E0);
        wanwan->field1F8 += 0xb4;
    }
    VEC_Subtract(&wanwan->field1E0, &wanwan->field0.mPos, &a);
    wanwan->field0.field10.x += (s32) (((s64) a.x << 5) >> 12);
    wanwan->field0.field10.z += (s32) (((s64) a.z << 5) >> 12);
    if (func_020dccc8_inline(&wanwan->field0.field10) >= 0x40000000) {
        wanwan->field0.field10.x -= (s32) (((s64) wanwan->field0.field10.x * 0x4cc) >> 12);
        wanwan->field0.field10.z -= (s32) (((s64) wanwan->field0.field10.z * 0x4cc) >> 12);
    }
    if (func_020dccc8_inline(&a) < (s64) (wanwan->fieldF0 >> 1) * (wanwan->fieldF0 >> 1)) {
        wanwan->field0.field10.x >>= 1;
        wanwan->field0.field10.z >>= 1;
    } else {
        qrtn_fromYAngle((u16) (((s64) FX_Atan2(a.x, a.z) * 0x28be60db9391LL + 0x80000000000LL) >> 44),
                                   &wanwan->fieldD4);
    }
    t = ((s64) wanwan->field0.field10.x * a.z) >> 12;
    t -= (s32) (((s64) wanwan->field0.field10.z * a.x) >> 12);
    if (((s64) a.x * a.x + (s64) a.z * a.z) * 10 < (s64) t * t) {
        wanwan->field0.field10.x >>= 1;
        wanwan->field0.field10.z >>= 1;
    }
    wanwan->field0.mPos.x += wanwan->field0.field10.x;
    wanwan->field0.mPos.z += wanwan->field0.field10.z;
    VEC_Subtract(&wanwan->field0.mPos, &wanwan->mCenterPos, &a);
    if ((s64) a.x * a.x + (s64) a.z * a.z >= (s64) wanwan->mMaxRadius * wanwan->mMaxRadius) {
        vec_normalizeXZFast(&a, &a);
        wanwan->field0.mPos.x = wanwan->mCenterPos.x + (s32) (((s64) a.x * wanwan->mMaxRadius) >> 12);
        wanwan->field0.mPos.z = wanwan->mCenterPos.z + (s32) (((s64) a.z * wanwan->mMaxRadius) >> 12);
        k = ((s64) wanwan->field0.field10.x * a.x) >> 12;
        m = ((s64) wanwan->field0.field10.z * a.z) >> 12;
        if (k + m > 0) {
            wanwan->field0.field10.x -= (s32) (((s64) k * a.x) >> 12);
            wanwan->field0.field10.z -= (s32) (((s64) m * a.z) >> 12);
        }
    }
    if (wanwan->field0.mStateMachine.mStateFrames >= 0xb4) {
        wanwan->field0.mStateMachine.mNextState = 3;
        wanwan->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void wanwan_state2Init(Wanwan *wanwan) {
    wanwan->fieldE8 = 0xd000;
    wanwan->fieldEC = 0x1c2;
    if (wanwan->fieldFC == 0) {
        wanwan->mChainObject->fieldA8 = 0x219;
    }
    wanwan->field0.field10.y = 0x8000;
}

void wanwan_state2Update(Wanwan *wanwan) {
    const Vec3 *velocity;

    if (wanwan->fieldFC != 0) {
        wanwan->field0.field10.x = wanwan->field0.mPos.x;
        wanwan->field0.field10.z = wanwan->field0.mPos.z;
        pwex_update(&wanwan->mFollower);
        pw_calcCurrentPointXZ(&wanwan->mFollower.field0, &wanwan->field0.mPos);
        wanwan->field0.field10.x = wanwan->field0.mPos.x - wanwan->field0.field10.x;
        wanwan->field0.field10.z = wanwan->field0.mPos.z - wanwan->field0.field10.z;
        velocity = &wanwan->field0.field10;
        if ((s64) velocity->x * velocity->x + (s64) velocity->z * velocity->z >= 0x10) {
            qrtn_fromYAngle(
                (u16) (((s64) FX_Atan2(wanwan->field0.field10.x, wanwan->field0.field10.z) * 0x28be60db9391LL +
                        0x80000000000LL) >>
                       44),
                &wanwan->fieldD4);
        }
        if (wanwan->field0.mStateMachine.mStateFrames < 0x40) {
            wanwan->fieldEC += 0x1c;
        }
        if (wanwan->field0.mStateMachine.mStateFrames >= 0x28) {
            wanwan->fieldE8 += 0x200;
        } else {
            wanwan->field0.field10.y -= 0x266;
        }
        if (wanwan->fieldE8 > 0x10555) {
            wanwan->field0.mStateMachine.mNextState = 5;
            wanwan->field0.mStateMachine.mNextStateRequested = 1;
        }
    } else {
        if (wanwan->fieldE8 == 0xd000) {
            wanwan->field0.field10.y -= 0x19a;
        }
        if (wanwan->field0.mStateMachine.mStateFrames >= 0x78) {
            wanwan->fieldE8 += 0x100;
        }
        if (wanwan->fieldE8 > 0x10555) {
            wanwan->field0.mStateMachine.mNextState = 3;
            wanwan->field0.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void wanwan_state3Init(Wanwan *wanwan) {
    wanwan->fieldE8 = 0x555;
    wanwan->fieldEC = 0x1c2;
    wanwan->mChainObject->fieldA8 = 0x599;
}

static inline s64 func_020dc474_inline(const Vec3 *vector) {
    return (s64) vector->x * vector->x + (s64) vector->z * vector->z;
}

void wanwan_state3Update(Wanwan *wanwan) {
    Vec3 toCenter;
    s32 radius;

    radius = wanwan->field1FC;
    if ((s64) (wanwan->field0.mPos.x - wanwan->mCenterPos.x) * (wanwan->field0.mPos.x - wanwan->mCenterPos.x) +
            (s64) (wanwan->field0.mPos.z - wanwan->mCenterPos.z) * (wanwan->field0.mPos.z - wanwan->mCenterPos.z) >=
        (s64) radius * radius) {
        VEC_Subtract(&wanwan->mCenterPos, &wanwan->field0.mPos, &toCenter);
        wanwan->field0.field10.x += (s32) (((s64) toCenter.x << 2) >> 12);
        wanwan->field0.field10.z += (s32) (((s64) toCenter.z << 2) >> 12);
        if (func_020dc474_inline(&wanwan->field0.field10) >= 0x1000000) {
            wanwan->field0.field10.x -= (s32) (((s64) wanwan->field0.field10.x * 0x199) >> 12);
            wanwan->field0.field10.z -= (s32) (((s64) wanwan->field0.field10.z * 0x199) >> 12);
        }
        wanwan->field0.mPos.x += wanwan->field0.field10.x;
        wanwan->field0.mPos.z += wanwan->field0.field10.z;
    }
    if (wanwan->field0.mStateMachine.mStateFrames >= 0xb4) {
        wanwan->field0.mStateMachine.mNextState = 0;
        wanwan->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void wanwan_state4Init(Wanwan *wanwan) {
    wanwan->fieldE8 = 0x555;
    wanwan->fieldEC = 0x1c2;
    wanwan->mChainObject->fieldA8 = 0x599;
}

void wanwan_state4Update(Wanwan *wanwan) {}

void wanwan_state5Init(Wanwan *wanwan) {
    wanwan->fieldE8 = 0x555;
    wanwan->fieldEC = 0x1c2;
}
