#include "Main/Unknown/code_0206dfd0.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206d000.h"
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
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"

static inline BOOL AreKartSpheresOverlapping(Kart *kart, Kart *otherKart, s32 radiusSum) {
    s32 deltaX;
    s32 deltaY;
    s32 deltaZ;
    s32 negativeRadius;

    negativeRadius = -radiusSum;
    deltaZ = kart->mPointAlongUp.z - otherKart->mPointAlongUp.z;
    if (deltaZ > radiusSum || deltaZ < negativeRadius) {
        return FALSE;
    }
    deltaX = kart->mPointAlongUp.x - otherKart->mPointAlongUp.x;
    if (deltaX > radiusSum || deltaX < negativeRadius) {
        return FALSE;
    }
    deltaY = kart->mPointAlongUp.y - otherKart->mPointAlongUp.y;
    if (deltaY > radiusSum || deltaY < negativeRadius) {
        return FALSE;
    }
    if ((s64) deltaX * deltaX + (s64) deltaY * deltaY + (s64) deltaZ * deltaZ < (s64) radiusSum * radiusSum) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 CollideKartsNormalizeLengthOrZero(Vec3 *vector, Vec3 *normalized) {
    if (LENGTH_SQUARED(*vector) < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(vector, normalized);
}

void CollideKartWithKarts(Kart *kart) {
    s32 slotIndex;
    Kart *otherKart;
    s32 radiusSum;
    s32 overlapLength;
    s32 dot;
    s32 callbackValue;
    BOOL pushHandled;
    s32 effectsStarted;
    u32 kartFlags;
    u32 otherKartFlags;
    Vec3 normal;
    Vec3 overlapOffset;
    Vec3 kartShift;
    Vec3 otherShift;
    Vec3 relativeVelocity;
    Vec3 otherRelativeVelocity;
    Vec3 negatedNormal;
    Vec3 otherNegatedNormal;
    Vec3 zeroVector;

    effectsStarted = 0;
    if (kart->mKartCollisionDelayTimer > 0) {
        kart->mKartCollisionDelayTimer--;
        if (kart->mKartCollisionDelayTimer <= 0) {
            kart->mKartCollisionDelayTimer = 0;
        }
    }
    if (kart->mUnk_7c & 0x402000) {
        return;
    }
    if (kart->mUnk_48 & KART_48_SINKING) {
        return;
    }
    for (slotIndex = 0; slotIndex < gFoundCollisionSlotCount; slotIndex++) {
        if (!(gFoundCollisionSlotFlags[slotIndex] & 0x8000)) {
            continue;
        }
        otherKart = gFoundCollisionSlotObjects[slotIndex];
        if (kart->mTestedKartMask & (1 << otherKart->mIndex)) {
            continue;
        }
        if (otherKart->mUnk_7c & 0x402020) {
            continue;
        }
        if (otherKart->mUnk_48 & KART_48_SINKING) {
            continue;
        }
        radiusSum = kart->mRadius + otherKart->mRadius;
        otherKart->mTestedKartMask |= 1 << kart->mIndex;
        kart->mTestedKartMask |= 1 << otherKart->mIndex;
        if (AreKartSpheresOverlapping(kart, otherKart, radiusSum) == FALSE) {
            continue;
        }
        ComputeSphereOverlapOffset(&kart->mPointAlongUp, &otherKart->mPointAlongUp, radiusSum, &overlapOffset);
        overlapLength = CollideKartsNormalizeLengthOrZero(&overlapOffset, &normal);
        if (overlapLength > 0) {
            kartShift.x = overlapOffset.x >> 1;
            kartShift.y = overlapOffset.y >> 1;
            kartShift.z = overlapOffset.z >> 1;
            otherShift.x = -kartShift.x;
            otherShift.y = -kartShift.y;
            otherShift.z = -kartShift.z;
            callbackValue = 0;
            pushHandled = FALSE;
            if (kart->mUnk_44 & KART_44_ON_GROUND) {
                dot = VEC_DotProduct(&kart->mGroundNormal, &kartShift);
                kartShift.x -= MUL_FIXED12_NO_ROUND(kart->mGroundNormal.x, dot);
                kartShift.y -= MUL_FIXED12_NO_ROUND(kart->mGroundNormal.y, dot);
                kartShift.z -= MUL_FIXED12_NO_ROUND(kart->mGroundNormal.z, dot);
            }
            if (kart->mUnk_44 & 0x80) {
                if (VEC_DotProduct(&kart->mGroundNormal, &kartShift) < 0) {
                    dot = VEC_DotProduct(&kart->mCourseContactNormal, &kartShift);
                    kartShift.x -= MUL_FIXED12_NO_ROUND(kart->mCourseContactNormal.x, dot);
                    kartShift.y -= MUL_FIXED12_NO_ROUND(kart->mCourseContactNormal.y, dot);
                    kartShift.z -= MUL_FIXED12_NO_ROUND(kart->mCourseContactNormal.z, dot);
                }
            }
            if (otherKart->mUnk_44 & KART_44_ON_GROUND) {
                dot = VEC_DotProduct(&otherKart->mGroundNormal, &otherShift);
                otherShift.x -= MUL_FIXED12_NO_ROUND(otherKart->mGroundNormal.x, dot);
                otherShift.y -= MUL_FIXED12_NO_ROUND(otherKart->mGroundNormal.y, dot);
                otherShift.z -= MUL_FIXED12_NO_ROUND(otherKart->mGroundNormal.z, dot);
            }
            if (otherKart->mUnk_44 & 0x80) {
                if (VEC_DotProduct(&otherKart->mGroundNormal, &otherShift) < 0) {
                    dot = VEC_DotProduct(&otherKart->mCourseContactNormal, &otherShift);
                    otherShift.x -= MUL_FIXED12_NO_ROUND(otherKart->mCourseContactNormal.x, dot);
                    otherShift.y -= MUL_FIXED12_NO_ROUND(otherKart->mCourseContactNormal.y, dot);
                    otherShift.z -= MUL_FIXED12_NO_ROUND(otherKart->mCourseContactNormal.z, dot);
                }
            }
            VEC_Add(kart->mCollisionPosSource, &kartShift, kart->mCollisionPosSource);
            VEC_Add(otherKart->mCollisionPosSource, &otherShift, otherKart->mCollisionPosSource);
            if (otherKart->mUnk_44 & 0xc0) {
                VEC_Subtract(&otherKart->mVelocity, &kart->mVelocity, &relativeVelocity);
                dot = VEC_DotProduct(&normal, &relativeVelocity);
                relativeVelocity.x = MUL_FIXED12_NO_ROUND(normal.x, dot);
                relativeVelocity.y = MUL_FIXED12_NO_ROUND(normal.y, dot);
                relativeVelocity.z = MUL_FIXED12_NO_ROUND(normal.z, dot);
                kart->mForwardSpeed += VEC_DotProduct(&kart->mTurnedForward, &relativeVelocity);
            }
            if (kart->mUnk_44 & 0xc0) {
                VEC_Subtract(&kart->mVelocity, &otherKart->mVelocity, &otherRelativeVelocity);
                dot = VEC_DotProduct(&normal, &otherRelativeVelocity);
                otherRelativeVelocity.x = MUL_FIXED12_NO_ROUND(normal.x, dot);
                otherRelativeVelocity.y = MUL_FIXED12_NO_ROUND(normal.y, dot);
                otherRelativeVelocity.z = MUL_FIXED12_NO_ROUND(normal.z, dot);
                otherKart->mForwardSpeed += VEC_DotProduct(&otherKart->mTurnedForward, &otherRelativeVelocity);
            }
            if (gRaceSetup->mMode == MODE_BATTLE) {
                callbackValue = CallKartCollisionCallbacks(kart->mIndex, otherKart->mIndex);
            }
            kartFlags = kart->mUnk_4c;
            if (kartFlags & 0x10000000) {
                if (!(otherKart->mUnk_4c & 0x10000040)) {
                    pushHandled = TRUE;
                    TryStartKartPushDoubleFlip(kart, otherKart);
                }
            } else if ((otherKartFlags = otherKart->mUnk_4c) & 0x10000000) {
                if (!(kartFlags & 0x10000040)) {
                    pushHandled = TRUE;
                    TryStartKartPushDoubleFlip(otherKart, kart);
                }
            } else if (kartFlags & 0x40) {
                if (!(otherKartFlags & 0x10000040)) {
                    negatedNormal.x = -normal.x;
                    negatedNormal.y = -normal.y;
                    negatedNormal.z = -normal.z;
                    pushHandled = TRUE;
                    TryStartKartPushFlip(kart, otherKart, &negatedNormal);
                }
            } else if (otherKartFlags & 0x40) {
                if (!(kartFlags & 0x10000040)) {
                    pushHandled = TRUE;
                    TryStartKartPushFlip(otherKart, kart, &normal);
                }
            } else if (kart->mKartCollisionDelayTimer <= 0) {
                if (kart->mVelocityLength > 0x1000 || otherKart->mVelocityLength > 0x1000) {
                    if (gSceneSoundState.mRaceFrames > 0x78) {
                        StartSound(&kart->mSoundSource, 0x80, 0x7f, 0);
                    }
                    if (kart->mVelocityLength > otherKart->mVelocityLength) {
                        otherKart->mKartCollisionTimer = 0x14;
                    } else {
                        kart->mKartCollisionTimer = 0x14;
                    }
                    StartKartModelScaleAnimation(kart, 2);
                    StartKartModelScaleAnimation(otherKart, 2);
                    kart->mKartCollisionDelayTimer = 0xf;
                    if (effectsStarted == 0) {
                        effectsStarted = TryStartKartCollisionEffects(kart, &normal, callbackValue);
                        if (effectsStarted == 0) {
                            otherNegatedNormal.x = -normal.x;
                            otherNegatedNormal.y = -normal.y;
                            otherNegatedNormal.z = -normal.z;
                            effectsStarted =
                                TryStartKartCollisionEffects(otherKart, &otherNegatedNormal, callbackValue);
                        }
                    }
                }
            }
            if (overlapLength > data_021654f4) {
                kart->mUnk_4c |= 0x100000;
                otherKart->mUnk_4c |= 0x100000;
            }
            if (pushHandled == FALSE) {
                zeroVector = gKartVec3Zero;
                ApplyKartPush(otherKart, kart, &normal, 1, &zeroVector);
                normal.x = -normal.x;
                normal.y = -normal.y;
                normal.z = -normal.z;
                ApplyKartPush(kart, otherKart, &normal, 0, &zeroVector);
            }
        }
        kart->mUnk_44 |= KART_44_NEAR_KART;
        otherKart->mUnk_44 |= KART_44_NEAR_KART;
        kart->mNearKartMask |= 1 << otherKart->mIndex;
        otherKart->mNearKartMask |= 1 << kart->mIndex;
    }
}
