#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0207b000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020f9334.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"

static inline s32 func_0206dbf8_inline(Kart *kart) {
    BOOL c;
    BOOL t;
    BOOL u;
    int v;
    u32 bits4c;

    bits4c = kart->mUnk_4c;
    if (bits4c & KART_4C_BLINK_GUARD) {
        c = FALSE;
    } else if (kart->mUnk_7c & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mUnk_48 & 0x1800) && !(bits4c & 0x10000040)) {
            c = TRUE;
        } else {
            c = FALSE;
        }
    } else {
        t = TRUE;
        if (!(bits4c & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
            u = FALSE;
            v = kart->mState;
            if (v != KART_STATE_NORMAL && v != KART_STATE_1 && v != KART_STATE_SPIN) {
                u = TRUE;
            }
            if (u == FALSE) {
                t = FALSE;
            }
        }
        c = t == FALSE;
    }
    return c;
}

BOOL TryStartKartPushFlip(Kart *starKart, Kart *hitKart, const Vec3 *v) {
    BOOL r;
    s32 canStart;
    u32 w;

    r = FALSE;
    canStart = func_0206dbf8_inline(hitKart);
    if (canStart != 0) {
        StartKartState4(hitKart, v, 1);
        StartSound(&hitKart->mSoundSource, 0xe8, 0x7f, 0);
        if (hitKart->mUnk_7c & 0x200) {
            hitKart->mUnk_514->mEventToggleFlags ^= 0x80;
        }
        r = TRUE;
        w = starKart->mUnk_7c & 0x200;
        if (w != 0) {
            switch (hitKart->mIndex) {
                case 0:
                    if (w) {
                        starKart->mUnk_514->mEventToggleFlags ^= 0x200;
                    }
                    break;
                case 1:
                    if (w) {
                        starKart->mUnk_514->mEventToggleFlags ^= 0x400;
                    }
                    break;
                case 2:
                    if (w) {
                        starKart->mUnk_514->mEventToggleFlags ^= 0x800;
                    }
                    break;
                case 3:
                    if (w) {
                        starKart->mUnk_514->mEventToggleFlags ^= 0x1000;
                    }
                    break;
            }
        }
    }
    return r;
}

BOOL TryStartKartPushDoubleFlip(Kart *killerKart, Kart *hitKart) {
    Vec3 a;
    Vec3 b;
    Vec3 v1;
    BOOL r;
    s32 canStart;
    u32 w;

    r = FALSE;
    canStart = func_0206dbf8_inline(hitKart);
    if (canStart != 0) {
        a = killerKart->mUnk_120;
        VEC_Subtract(&hitKart->mPos, &killerKart->mPos, &b);
        VEC_CrossProduct(&killerKart->mUnk_138, &b, &v1);
        if (VEC_DotProduct(&v1, &killerKart->mUnk_12c) < 0) {
            a.x = -a.x;
            a.y = -a.y;
            a.z = -a.z;
        }
        StartKartState5(hitKart, &a, 1);
        StartSound(&hitKart->mSoundSource, 0xe8, 0x7f, 0);
        if (hitKart->mUnk_7c & 0x200) {
            hitKart->mUnk_514->mEventToggleFlags ^= 0x80;
        }
        r = TRUE;
        w = killerKart->mUnk_7c & 0x200;
        if (w != 0) {
            switch (hitKart->mIndex) {
                case 0:
                    if (w) {
                        killerKart->mUnk_514->mEventToggleFlags ^= 0x400000;
                    }
                    break;
                case 1:
                    if (w) {
                        killerKart->mUnk_514->mEventToggleFlags ^= 0x800000;
                    }
                    break;
                case 2:
                    if (w) {
                        killerKart->mUnk_514->mEventToggleFlags ^= 0x1000000;
                    }
                    break;
                case 3:
                    if (w) {
                        killerKart->mUnk_514->mEventToggleFlags ^= 0x2000000;
                    }
                    break;
            }
        }
    }
    return r;
}

void ApplyKartPush(Kart *pushingKart, Kart *pushedKart, const Vec3 *contactDirection, s32 storeDirection,
                   Vec3 *sharedDirection) {
    s32 pushingWeight;
    s32 b;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 t;
    s32 v5 = -1;
    s32 v6;
    s32 v7;
    s32 v8;
    Vec3 scaledPush;
    Vec3 sidewaysPush;
    Vec3 pushedForward;
    Vec3 sidewaysDirection;
    Vec3 pushVector;
    Vec3 v10;

    pushingWeight = pushingKart->mPhysicalParam->mWeight + pushingKart->mCharPhysicalParam[1];
    b = pushedKart->mPhysicalParam->mWeight + pushedKart->mCharPhysicalParam[1];
    v2 = pushingKart->mVelocityLengthRatio;
    if (pushingKart->mUnk_7c & 0x600) {
        if (v2 > 4.8828125e-05f) {
            v2 = 0x333;
        }
    } else if (v2 > 0x800) {
        v2 = 0x1000;
    } else {
        v2 = v2 * 2;
        if (v2 < 0x333) {
            v2 = 0x333;
        }
    }
    t = pushingKart->mUnk_4c & KART_4C_THUNDER_SHRINK;
    if (t) {
        pushingWeight >>= 3;
    }
    if (t) {
        b >>= 3;
    }
    if (pushingKart->mUnk_48 & 0x100000) {
        pushingWeight <<= 1;
    }
    if (pushedKart->mUnk_48 & 0x100000) {
        pushingWeight >>= 2;
    }
    t = FX_Div(pushingWeight, b);
    if (t > 0x5000) {
        t = 0x5000;
    }
    b = MUL_FIXED12_NO_ROUND(pushingWeight, t);
    v2 = MUL_FIXED12_NO_ROUND(b, v2);
    pushedForward = pushedKart->mTurnedForward;
    if (pushedKart->mUnk_44 & KART_44_REVERSING) {
        pushedForward.x = -pushedForward.x;
        pushedForward.y = -pushedForward.y;
        pushedForward.z = -pushedForward.z;
    }
    scaledPush.x = MUL_FIXED12_NO_ROUND(contactDirection->x, v2);
    scaledPush.y = MUL_FIXED12_NO_ROUND(contactDirection->y, v2);
    scaledPush.z = MUL_FIXED12_NO_ROUND(contactDirection->z, v2);
    v3 = VEC_DotProduct(&pushedForward, &scaledPush);
    sidewaysPush.x = scaledPush.x - MUL_FIXED12_NO_ROUND(pushedForward.x, v3);
    sidewaysPush.y = scaledPush.y - MUL_FIXED12_NO_ROUND(pushedForward.y, v3);
    sidewaysPush.z = scaledPush.z - MUL_FIXED12_NO_ROUND(pushedForward.z, v3);
    v4 = 0;
    if (LENGTH_SQUARED(sidewaysPush) >= 16) {
        v4 = Vec3NormalizeAndGetLengthUnchecked(&sidewaysPush, &sidewaysDirection);
    }
    if (v4 <= 0) {
        return;
    }
    if (storeDirection != 0) {
        *sharedDirection = sidewaysDirection;
    } else if (sharedDirection->x != 0 || sharedDirection->y != 0 || sharedDirection->z != 0) {
        if (VEC_DotProduct(&sidewaysDirection, sharedDirection) > 0x19a) {
            sidewaysDirection = data_02154f94;
        }
    }
    pushVector.x = MUL_FIXED12_NO_ROUND(sidewaysDirection.x, v2);
    pushVector.y = MUL_FIXED12_NO_ROUND(sidewaysDirection.y, v2);
    pushVector.z = MUL_FIXED12_NO_ROUND(sidewaysDirection.z, v2);
    if (pushVector.y > 0) {
        pushVector.y = 0;
    }
    v3 = VEC_DotProduct(&pushedKart->mGroundNormal, &pushVector);
    v6 = pushVector.x - MUL_FIXED12_NO_ROUND(pushedKart->mGroundNormal.x, v3);
    v8 = pushVector.y - MUL_FIXED12_NO_ROUND(pushedKart->mGroundNormal.y, v3);
    v7 = pushVector.z - MUL_FIXED12_NO_ROUND(pushedKart->mGroundNormal.z, v3);
    pushedKart->mHitVelocity.x += v6;
    pushedKart->mHitVelocity.z += v7;
    pushedKart->mVerticalSpeed += v8;
    v2 = MUL_FIXED12_ROUNDED(v2, 0xaab);
    if (v2 > 0x1000) {
        v2 = 0x1000;
    }
    VEC_CrossProduct(&sidewaysDirection, &pushedKart->mForward, &v10);
    if (v10.y < 0) {
        v2 = v2 * v5;
    }
    if (pushedKart->mKartModelsEntry->mUnk_058 != 0) {
        return;
    }
    t = pushedKart->mForwardSpeed;
    if (t <= 0) {
        t = -t;
    }
    if (t <= 0x3000) {
        return;
    }
    if (v2 > 0) {
        t = v2;
    } else {
        t = -v2;
    }
    pushedKart->mUnk_4c |= 0x2000000;
    if (t <= pushedKart->mWobbleAmplitude) {
        return;
    }
    pushedKart->mWobbleAmplitude = t;
    if (v2 > 0) {
        t = 1;
    } else {
        t = -1;
    }
    pushedKart->mWobbleDirection = t;
}

void UpdateKartAheadEffect(Kart *kart) {
    s32 distance;
    BOOL aheadFound;
    s32 i;
    Kart *otherKart;
    Vec3 offset;

    distance = 0;
    aheadFound = FALSE;
    ComputeKartPointAlongUp(&kart->mUnk_1f0, kart->mUnk_510, 0x400, kart);
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(kart->mRadius, -0x4000), &kart->mTurnedForward, &kart->mUnk_1f0, &kart->mUnk_1f0);
    if (kart->mIndex == GetRaceUpdateFramesMod8() && !(kart->mUnk_4c & (0x10000000 | KART_4C_AHEAD_BOOST))) {
        if (kart->mVelocityLength > 0x4000 && kart->mState == KART_STATE_NORMAL) {
            for (i = 0; i < gFoundCollisionSlotCount; i++) {
                otherKart = gFoundCollisionSlotObjects[i];
                if (otherKart->mVelocityLength >= 0x2000 && (gFoundCollisionSlotFlags[i] & 0x800) &&
                    otherKart != kart && !(otherKart->mUnk_7c & 0x402000)) {
                    VEC_Subtract(&otherKart->mPos, &kart->mPos, &offset);
                    distance = VEC_Mag(&offset);
                    if (Vec3DotUnrounded(&otherKart->mTurnedForward, &offset) > MUL_FIXED12_NO_ROUND(distance, 0xe7f)) {
                        aheadFound = TRUE;
                        kart->mUnk_538.mAheadCount++;
                        break;
                    }
                }
            }
        }
        if (!(kart->mUnk_7c & 0x400)) {
            if (aheadFound != FALSE) {
                kart->mUnk_4c |= KART_4C_AHEAD_BUILD_UP;
                StartKartAheadEffectIfSelectedEntry(kart);
                if (kart->mUnk_538.mAheadCount > 0xf && distance < 0x3c000) {
                    StartKartAheadBoost(kart);
                }
            } else {
                kart->mUnk_538.mAheadCount = 0;
                kart->mUnk_4c &= ~KART_4C_AHEAD_BUILD_UP;
                if (!(kart->mUnk_4c & KART_4C_AHEAD_BOOST)) {
                    kart->mAheadSpeedLimitFactor = 0x1000;
                }
                StopKartAheadEffect(kart);
            }
        }
    }
    if (kart->mUnk_4c & KART_4C_AHEAD_BUILD_UP) {
        kart->mAheadSpeedLimitFactor += 7;
        if (kart->mAheadSpeedLimitFactor > 0x1333) {
            kart->mAheadSpeedLimitFactor = 0x1333;
        }
    }
}

void ApplyItemObjectHitToKart(Kart *kart) {
    s32 hitResult;
    ItemObject *itemObject;
    Kart *ownerKart;
    u32 kartIndex;
    u32 t;
    u32 ownerBits7c;

    if (kart->mUnk_7c & 0x400400) {
        return;
    }
    if (CollideKartWithItemObjects(kart) == 0) {
        return;
    }
    if (kart->mUnk_7c & 0x402020) {
        return;
    }
    if (kart->mUnk_4c & KART_4C_RESPAWN_DROP) {
        return;
    }
    itemObject = GetCollidedItemObject(0);
    hitResult = 0;
    switch (itemObject->mKind) {
        case 0:
        case 1:
        case 7:
            hitResult = TryStartKartState3(kart);
            break;
        case 2:
            hitResult = TrySpinKart(kart, 1, hitResult);
            if (hitResult != 0 && kart->mKartModelsEntry->mUnk_058 == 0) {
                StartEffect(0xc, &kart->mPos);
                StartEffect(0xd, &kart->mPos);
                StartEffect(0xe, &kart->mPos);
            }
            break;
        case 3:
            // r is still 0 here, KART_BOOST_ITEM_OR_SURFACE.
            StartKartBoost(kart, hitResult, 0x5a);
            kart->mUnk_48 |= 0x100000;
            kart->mUnk_538.mUnk_00 = 0x5a;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                ClearStandingsHitSeenFromKart(kart->mIndex);
            }
            break;
        case 4:
            StartKartStar(kart);
            break;
        case 5:
            if (((ItemKouraW *) itemObject)->mHitSpinsKart != 0) {
                hitResult = TrySpinKart(kart, 2, hitResult);
            } else {
                hitResult = TryStartKartState6(kart);
            }
            break;
        case 9:
            if (((ItemBomb *) itemObject)->mHitSpinsKart != 0) {
                hitResult = TrySpinKart(kart, 2, hitResult);
            } else {
                hitResult = TryStartKartState6(kart);
            }
            break;
        case 6:
            kartIndex = hitResult;
            StartFadeFog();
            StartEffectsAtOtherKarts(kart->mIndex);
            t = kart->mUnk_7c & 0x200;
            if (t) {
                if (t) {
                    kart->mUnk_514->mEventToggleFlags ^= 0x4000;
                }
            } else {
                while (kartIndex < gRaceSetup->mKartCount) {
                    if (kartIndex != kart->mIndex) {
                        StartKartThunderShrink(GetKart(kartIndex));
                    }
                    kartIndex = (u16) (kartIndex + 1);
                }
            }
            break;
        case 8:
            CollideKartWithBouncingItemBox((BouncingItemBox *) itemObject, kart);
            break;
    }
    if (hitResult != 0 && gRaceSetup->mMode == MODE_MISSION_RUN) {
        IncrementEntryKartItemHitCount(kart->mIndex);
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        SetKartHitByKartIndexFromItem(kart->mIndex, itemObject);
    }
    if (DoesItemObjectHurtKart(itemObject) == 0) {
        return;
    }
    if (kart->mUnk_4c & 0x10000040) {
        if (itemObject->mKartSoundMask & (u8) (1 << kart->mIndex)) {
            return;
        }
        itemObject->mKartSoundMask |= (u8) (1 << kart->mIndex);
        StartSound(&kart->mSoundSource, 0xe9, 0x7f, 0);
        return;
    }
    kartIndex = (u16) ((itemObject->mOwnerKartIndexAndFlags & 0x8000) == 0
                           ? (u16) (itemObject->mOwnerKartIndexAndFlags & ~0xff00)
                           : 8);
    if (kartIndex >= gRaceSetup->mKartCount) {
        return;
    }
    ownerKart = GetKart(kartIndex);
    if (ownerKart->mIndex != kart->mIndex && hitResult != 0) {
        if (gRaceSetup->mMode != MODE_MISSION_RUN) {
            IncrementEntryKartItemHitCount(kartIndex);
        }
        if (!(ownerKart->mUnk_48 & 0x840)) {
            StartKartSeqArcSound(ownerKart, ownerKart->mSoundIndex, 8);
        }
        ownerBits7c = ownerKart->mUnk_7c;
        if ((ownerBits7c & 0x10) && !(ownerBits7c & 0x30000)) {
            StartKartCharacterAnimationOnce(ownerKart, 2, 0);
        }
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mUnk_514->mEventToggleFlags &= ~0x60000000;
        kart->mUnk_514->mEventToggleFlags |= (kartIndex & 3) << 0x1d;
    }
}

void StartKartSoundAndCharacterAnimation(Kart *kart) {
    u32 bits7c;

    if (!(kart->mUnk_48 & 0x840)) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 8);
    }
    bits7c = kart->mUnk_7c;
    if (!(bits7c & 0x10)) {
        return;
    }
    if (bits7c & 0x30000) {
        return;
    }
    StartKartCharacterAnimationOnce(kart, 2, 0);
}

void StartKartBoost(Kart *kart, KartBoostKind boostKind, int boostFrames) {
    s32 c;
    u32 d;
    s16 currentTimer;
    enum { K0 } f;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    d = kart->mUnk_48 & 0x1000;
    if (d) {
        return;
    }
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    kart->mUnk_48 |= KART_48_BOOST;
    currentTimer = kart->mBoostTimer;
    if (boostFrames > currentTimer) {
        kart->mBoostTimer = boostFrames;
    }
    if (boostKind != KART_BOOST_MINI_TURBO && boostKind != KART_BOOST_RESPAWN) {
        kart->mUnk_48 |= 0x20000000;
    }
    StopKartSoundWhileRequested(kart);
    c = ~0x8000;
    kart->mUnk_48 &= c;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!boostKind) {
            f = 0;
        } else {
            f = 1;
        }
        StartKartBoostCameraEffect(f, kart);
        SetCameraHalfFovAngleGoal(0x1770);
        StartDispCapBlend(5);
        if (boostKind != KART_BOOST_RESPAWN) {
            return;
        }
        StartSound(&kart->mSoundSource, 0xa2, 0x7f, 0);
        return;
    }
    StartSound(&kart->mSoundSource, 0x9f, 0x7f, 0);
}
