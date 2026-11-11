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

static inline s32 IsKartPushFlipAllowed(Kart *kart) {
    BOOL canStart;
    BOOL value;
    BOOL check;
    int kartState;
    u32 bits4c;

    bits4c = kart->mEffectFlags;
    if (bits4c & KART_EFFECT_BLINK_GUARD) {
        canStart = FALSE;
    } else if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING) &&
            !(bits4c & KART_EFFECT_STAR_OR_KILLER)) {
            canStart = TRUE;
        } else {
            canStart = FALSE;
        }
    } else {
        value = TRUE;
        if (!(bits4c & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
            check = FALSE;
            kartState = kart->mState;
            if (kartState != KART_STATE_NORMAL && kartState != KART_STATE_1 && kartState != KART_STATE_SPIN) {
                check = TRUE;
            }
            if (check == FALSE) {
                value = FALSE;
            }
        }
        canStart = value == FALSE;
    }
    return canStart;
}

BOOL TryStartKartPushFlip(Kart *starKart, Kart *hitKart, const Vec3 *pushDirection) {
    BOOL started;
    s32 canStart;
    u32 flagBits;

    started = FALSE;
    canStart = IsKartPushFlipAllowed(hitKart);
    if (canStart != 0) {
        StartKartState4(hitKart, pushDirection, 1);
        StartSound(&hitKart->mSoundSource, 0xe8, 0x7f, 0);
        if (hitKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            hitKart->mParticipantRecordData->mEventToggleFlags ^= 0x80;
        }
        started = TRUE;
        flagBits = starKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL;
        if (flagBits != 0) {
            switch (hitKart->mIndex) {
                case 0:
                    if (flagBits) {
                        starKart->mParticipantRecordData->mEventToggleFlags ^= 0x200;
                    }
                    break;
                case 1:
                    if (flagBits) {
                        starKart->mParticipantRecordData->mEventToggleFlags ^= 0x400;
                    }
                    break;
                case 2:
                    if (flagBits) {
                        starKart->mParticipantRecordData->mEventToggleFlags ^= 0x800;
                    }
                    break;
                case 3:
                    if (flagBits) {
                        starKart->mParticipantRecordData->mEventToggleFlags ^= 0x1000;
                    }
                    break;
            }
        }
    }
    return started;
}

BOOL TryStartKartPushDoubleFlip(Kart *killerKart, Kart *hitKart) {
    Vec3 flipAxis;
    Vec3 offsetToHit;
    Vec3 crossProduct;
    BOOL started;
    s32 canStart;
    u32 flagBits;

    started = FALSE;
    canStart = IsKartPushFlipAllowed(hitKart);
    if (canStart != 0) {
        flipAxis = killerKart->mUnk_120;
        VEC_Subtract(&hitKart->mPos, &killerKart->mPos, &offsetToHit);
        VEC_CrossProduct(&killerKart->mUnk_138, &offsetToHit, &crossProduct);
        if (VEC_DotProduct(&crossProduct, &killerKart->mUnk_12c) < 0) {
            flipAxis.x = -flipAxis.x;
            flipAxis.y = -flipAxis.y;
            flipAxis.z = -flipAxis.z;
        }
        StartKartState5(hitKart, &flipAxis, 1);
        StartSound(&hitKart->mSoundSource, 0xe8, 0x7f, 0);
        if (hitKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            hitKart->mParticipantRecordData->mEventToggleFlags ^= 0x80;
        }
        started = TRUE;
        flagBits = killerKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL;
        if (flagBits != 0) {
            switch (hitKart->mIndex) {
                case 0:
                    if (flagBits) {
                        killerKart->mParticipantRecordData->mEventToggleFlags ^= 0x400000;
                    }
                    break;
                case 1:
                    if (flagBits) {
                        killerKart->mParticipantRecordData->mEventToggleFlags ^= 0x800000;
                    }
                    break;
                case 2:
                    if (flagBits) {
                        killerKart->mParticipantRecordData->mEventToggleFlags ^= 0x1000000;
                    }
                    break;
                case 3:
                    if (flagBits) {
                        killerKart->mParticipantRecordData->mEventToggleFlags ^= 0x2000000;
                    }
                    break;
            }
        }
    }
    return started;
}

void ApplyKartPush(Kart *pushingKart, Kart *pushedKart, const Vec3 *contactDirection, s32 storeDirection,
                   Vec3 *sharedDirection) {
    s32 pushingWeight;
    s32 weight;
    s32 pushScale;
    s32 dotProduct;
    s32 sidewaysLength;
    s32 value;
    s32 sign = -1;
    s32 slideX;
    s32 slideZ;
    s32 slideY;
    Vec3 scaledPush;
    Vec3 sidewaysPush;
    Vec3 pushedForward;
    Vec3 sidewaysDirection;
    Vec3 pushVector;
    Vec3 crossDirection;

    pushingWeight = pushingKart->mPhysicalParam->mWeight + pushingKart->mCharPhysicalParam[1];
    weight = pushedKart->mPhysicalParam->mWeight + pushedKart->mCharPhysicalParam[1];
    pushScale = pushingKart->mVelocityLengthRatio;
    if (pushingKart->mEntryFlags & KART_ENTRY_WIFI_ANY) {
        if (pushScale > 4.8828125e-05f) {
            pushScale = 0x333;
        }
    } else if (pushScale > 0x800) {
        pushScale = 0x1000;
    } else {
        pushScale = pushScale * 2;
        if (pushScale < 0x333) {
            pushScale = 0x333;
        }
    }
    value = pushingKart->mEffectFlags & KART_EFFECT_THUNDER_SHRINK;
    if (value) {
        pushingWeight >>= 3;
    }
    if (value) {
        weight >>= 3;
    }
    if (pushingKart->mDriveFlags & KART_DRIVE_KINOKO_BOOST) {
        pushingWeight <<= 1;
    }
    if (pushedKart->mDriveFlags & KART_DRIVE_KINOKO_BOOST) {
        pushingWeight >>= 2;
    }
    value = FX_Div(pushingWeight, weight);
    if (value > 0x5000) {
        value = 0x5000;
    }
    weight = MUL_FIXED12_NO_ROUND(pushingWeight, value);
    pushScale = MUL_FIXED12_NO_ROUND(weight, pushScale);
    pushedForward = pushedKart->mTurnedForward;
    if (pushedKart->mMotionFlags & KART_MOTION_REVERSING) {
        pushedForward.x = -pushedForward.x;
        pushedForward.y = -pushedForward.y;
        pushedForward.z = -pushedForward.z;
    }
    scaledPush.x = MUL_FIXED12_NO_ROUND(contactDirection->x, pushScale);
    scaledPush.y = MUL_FIXED12_NO_ROUND(contactDirection->y, pushScale);
    scaledPush.z = MUL_FIXED12_NO_ROUND(contactDirection->z, pushScale);
    dotProduct = VEC_DotProduct(&pushedForward, &scaledPush);
    sidewaysPush.x = scaledPush.x - MUL_FIXED12_NO_ROUND(pushedForward.x, dotProduct);
    sidewaysPush.y = scaledPush.y - MUL_FIXED12_NO_ROUND(pushedForward.y, dotProduct);
    sidewaysPush.z = scaledPush.z - MUL_FIXED12_NO_ROUND(pushedForward.z, dotProduct);
    sidewaysLength = 0;
    if (LENGTH_SQUARED(sidewaysPush) >= 16) {
        sidewaysLength = Vec3NormalizeAndGetLengthUnchecked(&sidewaysPush, &sidewaysDirection);
    }
    if (sidewaysLength <= 0) {
        return;
    }
    if (storeDirection != 0) {
        *sharedDirection = sidewaysDirection;
    } else if (sharedDirection->x != 0 || sharedDirection->y != 0 || sharedDirection->z != 0) {
        if (VEC_DotProduct(&sidewaysDirection, sharedDirection) > 0x19a) {
            sidewaysDirection = gKartVec3Zero;
        }
    }
    pushVector.x = MUL_FIXED12_NO_ROUND(sidewaysDirection.x, pushScale);
    pushVector.y = MUL_FIXED12_NO_ROUND(sidewaysDirection.y, pushScale);
    pushVector.z = MUL_FIXED12_NO_ROUND(sidewaysDirection.z, pushScale);
    if (pushVector.y > 0) {
        pushVector.y = 0;
    }
    dotProduct = VEC_DotProduct(&pushedKart->mGroundNormal, &pushVector);
    slideX = pushVector.x - MUL_FIXED12_NO_ROUND(pushedKart->mGroundNormal.x, dotProduct);
    slideY = pushVector.y - MUL_FIXED12_NO_ROUND(pushedKart->mGroundNormal.y, dotProduct);
    slideZ = pushVector.z - MUL_FIXED12_NO_ROUND(pushedKart->mGroundNormal.z, dotProduct);
    pushedKart->mHitVelocity.x += slideX;
    pushedKart->mHitVelocity.z += slideZ;
    pushedKart->mVerticalSpeed += slideY;
    pushScale = MUL_FIXED12_ROUNDED(pushScale, 0xaab);
    if (pushScale > 0x1000) {
        pushScale = 0x1000;
    }
    VEC_CrossProduct(&sidewaysDirection, &pushedKart->mForward, &crossDirection);
    if (crossDirection.y < 0) {
        pushScale = pushScale * sign;
    }
    if (pushedKart->mKartModelsEntry->mKartModelHidden != 0) {
        return;
    }
    value = pushedKart->mForwardSpeed;
    if (value <= 0) {
        value = -value;
    }
    if (value <= 0x3000) {
        return;
    }
    if (pushScale > 0) {
        value = pushScale;
    } else {
        value = -pushScale;
    }
    pushedKart->mEffectFlags |= KART_EFFECT_WOBBLE;
    if (value <= pushedKart->mWobbleAmplitude) {
        return;
    }
    pushedKart->mWobbleAmplitude = value;
    if (pushScale > 0) {
        value = 1;
    } else {
        value = -1;
    }
    pushedKart->mWobbleDirection = value;
}

void UpdateKartAheadEffect(Kart *kart) {
    s32 distance;
    BOOL aheadFound;
    s32 slotIndex;
    Kart *otherKart;
    Vec3 offset;

    distance = 0;
    aheadFound = FALSE;
    ComputeKartPointAlongUp(&kart->mSecondCollisionCenter, kart->mCollisionPosSource, 0x400, kart);
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(kart->mRadius, -0x4000), &kart->mTurnedForward, &kart->mSecondCollisionCenter,
                &kart->mSecondCollisionCenter);
    if (kart->mIndex == GetRaceUpdateFramesMod8() &&
        !(kart->mEffectFlags & (KART_EFFECT_KILLER | KART_EFFECT_AHEAD_BOOST))) {
        if (kart->mVelocityLength > 0x4000 && kart->mState == KART_STATE_NORMAL) {
            for (slotIndex = 0; slotIndex < gFoundCollisionSlotCount; slotIndex++) {
                otherKart = gFoundCollisionSlotObjects[slotIndex];
                if (otherKart->mVelocityLength >= 0x2000 && (gFoundCollisionSlotFlags[slotIndex] & 0x800) &&
                    otherKart != kart && !(otherKart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED)) {
                    VEC_Subtract(&otherKart->mPos, &kart->mPos, &offset);
                    distance = VEC_Mag(&offset);
                    if (Vec3DotUnrounded(&otherKart->mTurnedForward, &offset) > MUL_FIXED12_NO_ROUND(distance, 0xe7f)) {
                        aheadFound = TRUE;
                        kart->mItemEffectData.mAheadCount++;
                        break;
                    }
                }
            }
        }
        if (!(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
            if (aheadFound != FALSE) {
                kart->mEffectFlags |= KART_EFFECT_AHEAD_BUILD_UP;
                StartKartAheadEffectIfSelectedEntry(kart);
                if (kart->mItemEffectData.mAheadCount > 0xf && distance < 0x3c000) {
                    StartKartAheadBoost(kart);
                }
            } else {
                kart->mItemEffectData.mAheadCount = 0;
                kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BUILD_UP;
                if (!(kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST)) {
                    kart->mAheadSpeedLimitFactor = 0x1000;
                }
                StopKartAheadEffect(kart);
            }
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BUILD_UP) {
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
    u32 flagBits;
    u32 ownerBits7c;

    if (kart->mEntryFlags & (KART_ENTRY_WIFI_PEER | KART_ENTRY_PARKED)) {
        return;
    }
    if (CollideKartWithItemObjects(kart) == 0) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP) {
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
            if (hitResult != 0 && kart->mKartModelsEntry->mKartModelHidden == 0) {
                StartEffect(0xc, &kart->mPos);
                StartEffect(0xd, &kart->mPos);
                StartEffect(0xe, &kart->mPos);
            }
            break;
        case 3:
            // r is still 0 here, KART_BOOST_ITEM_OR_SURFACE.
            StartKartBoost(kart, hitResult, 0x5a);
            kart->mDriveFlags |= KART_DRIVE_KINOKO_BOOST;
            kart->mItemEffectData.mKinokoBoostTimer = 0x5a;
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
            flagBits = kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL;
            if (flagBits) {
                if (flagBits) {
                    kart->mParticipantRecordData->mEventToggleFlags ^= 0x4000;
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
    if (kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) {
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
        if (!(ownerKart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
            StartKartSeqArcSound(ownerKart, ownerKart->mSoundIndex, 8);
        }
        ownerBits7c = ownerKart->mEntryFlags;
        if ((ownerBits7c & KART_ENTRY_HAS_CHARACTER_ANIMATION) &&
            !(ownerBits7c & (KART_ENTRY_RESULT_WON | KART_ENTRY_RESULT_LOST))) {
            StartKartCharacterAnimationOnce(ownerKart, 2, 0);
        }
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags &= ~0x60000000;
        kart->mParticipantRecordData->mEventToggleFlags |= (kartIndex & 3) << 0x1d;
    }
}

void StartKartSoundAndCharacterAnimation(Kart *kart) {
    u32 bits7c;

    if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 8);
    }
    bits7c = kart->mEntryFlags;
    if (!(bits7c & KART_ENTRY_HAS_CHARACTER_ANIMATION)) {
        return;
    }
    if (bits7c & (KART_ENTRY_RESULT_WON | KART_ENTRY_RESULT_LOST)) {
        return;
    }
    StartKartCharacterAnimationOnce(kart, 2, 0);
}

void StartKartBoost(Kart *kart, KartBoostKind boostKind, int boostFrames) {
    s32 clearMask;
    u32 flagBits;
    s16 currentTimer;
    enum { K0 } value;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    flagBits = kart->mDriveFlags & KART_DRIVE_RESPAWN_FALL;
    if (flagBits) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    kart->mDriveFlags |= KART_DRIVE_BOOST;
    currentTimer = kart->mBoostTimer;
    if (boostFrames > currentTimer) {
        kart->mBoostTimer = boostFrames;
    }
    if (boostKind != KART_BOOST_MINI_TURBO && boostKind != KART_BOOST_RESPAWN) {
        kart->mDriveFlags |= KART_DRIVE_ITEM_BOOST;
    }
    StopKartSoundWhileRequested(kart);
    clearMask = ~0x8000;
    kart->mDriveFlags &= clearMask;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        if (!boostKind) {
            value = 0;
        } else {
            value = 1;
        }
        StartKartBoostCameraEffect(value, kart);
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
