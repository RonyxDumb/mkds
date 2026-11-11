#include "Main/Unknown/code_0206e874.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020d24d8.h"
#include "Main/Unknown/code_020d4104.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"

static inline s32 func_0206e874_inline(Vec3 *vector, Vec3 *normalized) {
    if (LENGTH_SQUARED(*vector) < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(vector, normalized);
}

void ApplyKartLanding(Kart *kart, Vec3 *groundNormal) {
    Vec3 normalVelocity;
    s32 soundQueueIndex;
    s32 s;
    s32 m;
    s32 n;
    u32 bits7c;
    s32 sortKeyOffset;
    s32 distanceSquared;

    if (kart->mUnk_44 & 0x40000010) {
        return;
    }
    kart->mUnk_44 |= 0x10000;
    if (kart->mLandingTimer <= 0) {
        soundQueueIndex = (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 3 : 2;
        sortKeyOffset = gKartSurfaceSoundSortOffsets[2];
        distanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
        AddSoundRequest(gSoundRequestQueues + soundQueueIndex, distanceSquared + sortKeyOffset,
                        (void (*)(void *, int)) StartSurfaceSoundFromKart, kart, 2);
        StartKartModelScaleAnimation(kart, 0);
    }
    kart->mLandingTimer = 7;
    if (kart->mUnk_48 & 0x2000000) {
        kart->mUnk_4c &= ~KART_4C_RESPAWN_DROP;
        kart->mUnk_48 &= ~0x2000000;
        kart->mUnk_40c = GetRaceUpdateFrames();
        ResetRaceTaKartPositions(kart->mIndex);
        return;
    }
    if ((!(kart->mUnk_4c & 0x10000000) && kart->mVelocity.y < 0 &&
         (kart->mAirborneFrames > 0x19 || kart->mLastGroundY - kart->mPos.y > 0x1e000)) ||
        kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
        s = VEC_DotProduct(groundNormal, &kart->mVelocity);
        normalVelocity.x = MUL_FIXED12_NO_ROUND(groundNormal->x, s);
        normalVelocity.y = MUL_FIXED12_NO_ROUND(groundNormal->y, s);
        normalVelocity.z = MUL_FIXED12_NO_ROUND(groundNormal->z, s);
        if (VEC_Mag(&normalVelocity) > 0x2000) {
            m = MUL_FIXED12_NO_ROUND(kart->mSpeedLimitFactor, 0x1800);
            n = normalVelocity.y;
            if (n <= 0) {
                n = -n;
            }
            kart->mVerticalSpeed = MUL_FIXED12_NO_ROUND(n, 0x99a);
            if (kart->mVerticalSpeed > m) {
                kart->mVerticalSpeed = m;
            }
            bits7c = kart->mUnk_7c;
            if ((bits7c & 0x10) && kart->mKartModelsEntry->mKartModelHidden == 0) {
                if ((bits7c & 1) || !(bits7c & 0x402000)) {
                    StartEffectWithCallback(0x4e, &kart->mPos, kart, SetEffectFlatVelocityFromKart);
                }
            }
        }
    }
    if (kart->mAirborneFrames <= 0x14) {
        return;
    }
    s = Vec3DotUnrounded(&kart->mUnk_138, groundNormal);
    if (s >= 0) {
        return;
    }
    if (kart->mAirTiltAngle <= 0x3e8) {
        return;
    }
    kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, s + 0x1000);
}

void CollideKartWithMapObjects(Kart *kart) {
    MapObject *touchedMapObjects[2] = {0};
    s32 i;
    MapObject *mapObject;
    Vec3 positionOffset;
    Vec3 v;
    Vec3 w;
    Vec3 z;
    Vec3 *foundMapObjectVector;
    Vec3 *u;
    s32 v2;
    BOOL v3;
    u16 touchedCount;
    BOOL touchedBefore;
    s32 g;
    s32 handlerIndex;
    s32 foundCount;
    s32 handlerResult;
    s32 s;
    s32 d;
    s32 m;
    s32 v5;
    s32 v6;
    s32 v7;
    u16 j;

    v3 = FALSE;
    mapObject = NULL;
    touchedCount = 0;
    kart->mMapObjectVectorForwardDot = kart->mMapObjectVectorLength = 0;
    foundCount = FindMapObjectsTouchingKart(kart, &kart->mCollisionCenter, &positionOffset);
    if (foundCount != 0) {
        if (!(kart->mUnk_48 & 0x40)) {
            i = foundCount - 1;
            kart->mUnk_44 |= 0x40000;
            if (i >= 0) {
                z = data_02154f94;
                do {
                    s = 0;
                    touchedBefore = FALSE;
                    mapObject = GetFoundMapObject(i);
                    handlerIndex = CollideKartWithMapObject(kart, mapObject);
                    handlerResult =
                        ((s32(*)(Kart *, s32 *, MapObject *)) gCollideKartWithMapObjectResponses[handlerIndex])(
                            kart, &v2, mapObject);
                    if (handlerResult != 0) {
                        v = z;
                        u = &mapObject->mPosStep;
                        foundMapObjectVector = GetFoundMapObjectVector(i);
                        d = func_0206e874_inline(foundMapObjectVector, &v);
                        if (d != 0) {
                            if (v2 != 2) {
                                ((void (*)(Kart *, Vec3 *, MapObject *)) gKartMapObjectSecondResponses[handlerIndex])(
                                    kart, &v, mapObject);
                            }
                            if (handlerResult & 8) {
                                ApplyKartContact(kart, &v, (kart->mUnk_44 & 0x40) ? 1 : 0, 0x1000, -1, -1, v2);
                            } else if (handlerResult & 2) {
                                s = Vec3DotUnrounded(&kart->mTurnedForward, &v) + 0x1000;
                                if (s > 0x1000) {
                                    s = 0x1000;
                                } else if (s < 0x29) {
                                    s = 0x29;
                                }
                                kart->mSpeedLimitHitFactor = MUL_FIXED12_NO_ROUND(kart->mSpeedLimitHitFactor, s);
                            }
                        }
                        if (handlerResult & 1) {
                            if (u->x != 0 || u->y != 0 || u->z != 0) {
                                w = z;
                                m = 1;
                                if (handlerResult & 4) {
                                    w = *u;
                                } else {
                                    if (d != 0) {
                                        s = VEC_DotProduct(&v, u);
                                        w.x = MUL_FIXED12_NO_ROUND(v.x, s);
                                        w.y = MUL_FIXED12_NO_ROUND(v.y, s);
                                        w.z = MUL_FIXED12_NO_ROUND(v.z, s);
                                    }
                                    if (Vec3DotUnrounded(&v, &w) < 0) {
                                        m = 0;
                                    }
                                }
                                kart->mMapObjectVectorLength = VEC_Mag(&w);
                                if (kart->mMapObjectVectorLength > 0x1000 && m != 0) {
                                    kart->mMapObjectVectorForwardDot = Vec3DotUnrounded(&kart->mTurnedForward, &w);
                                    s = VEC_DotProduct(&kart->mTurnedForward, &w);
                                    v6 = w.y - MUL_FIXED12_NO_ROUND(kart->mTurnedForward.y, s);
                                    v7 = w.z - MUL_FIXED12_NO_ROUND(kart->mTurnedForward.z, s);
                                    v5 = w.x - MUL_FIXED12_NO_ROUND(kart->mTurnedForward.x, s);
                                    kart->mHitVelocity.x += v5;
                                    kart->mHitVelocity.z += v7;
                                    kart->mVerticalSpeed += v6;
                                }
                            }
                        }
                        s = kart->mSpeedLimitHitFactor;
                        if (handlerResult & 8) {
                            v3 = TRUE;
                        }
                    }
                    g = mapObject->mFlags & 0x200;
                    if (g != 0) {
                        m = 0x1000;
                    } else {
                        m = MUL_FIXED12_NO_ROUND(0x1000 - s,
                                                 MUL_FIXED12_NO_ROUND(kart->mVelocityLength, data_usa_021654ec));
                    }
                    if (kart->mVelocityLength > 0x2000 || g != 0) {
                        if (touchedCount < 2) {
                            for (j = 0; j < 2; j++) {
                                if (mapObject == kart->mPrevTouchingMapObjects[j]) {
                                    touchedBefore = TRUE;
                                    break;
                                }
                            }
                            if (touchedBefore == FALSE) {
                                for (j = 0; j < 2; j++) {
                                    if (mapObject == kart->mPrevTouchingMapObjects[j] || kart->mUnk_444[j] != 0) {
                                        continue;
                                    }
                                    StartMapObjectKindSound(mapObject, &kart->mSoundSource, v2, m);
                                    kart->mUnk_444[j] = 1;
                                    break;
                                }
                            }
                            touchedMapObjects[touchedCount] = mapObject;
                            touchedCount++;
                        }
                    }
                    if (handlerIndex == 0xb) {
                        kart->mUnk_44c = mapObject;
                    }
                } while (--i >= 0);
            }
        }
        if (kart->mUnk_48 & 0x4000000) {
            if (kart->mUnk_44c == mapObject) {
                positionOffset.z = 0;
                positionOffset.x = 0;
            }
        }
        VEC_Add(&kart->mPos, &positionOffset, &kart->mPos);
    }
    for (j = 0; j < 2; j++) {
        kart->mPrevTouchingMapObjects[j] = touchedMapObjects[j];
        if (kart->mUnk_444[j] != 0) {
            kart->mUnk_440[j]++;
            if (kart->mUnk_440[j] > 10) {
                kart->mUnk_444[j] = 0;
                kart->mUnk_440[j] = 0;
            }
        }
    }
    if (v3 != FALSE) {
        kart->mUnk_44 |= 0x40;
    } else {
        kart->mUnk_44 &= ~0x40;
    }
}
