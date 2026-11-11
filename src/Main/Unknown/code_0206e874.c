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

static inline s32 KartMapObjectNormalizeLengthOrZero(Vec3 *vector, Vec3 *normalized) {
    if (LENGTH_SQUARED(*vector) < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(vector, normalized);
}

void ApplyKartLanding(Kart *kart, Vec3 *groundNormal) {
    Vec3 normalVelocity;
    s32 soundQueueIndex;
    s32 dotProduct;
    s32 speedLimit;
    s32 normalSpeed;
    u32 bits7c;
    s32 sortKeyOffset;
    s32 distanceSquared;

    if (kart->mUnk_44 & 0x40000010) {
        return;
    }
    kart->mUnk_44 |= KART_44_LANDED;
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
        kart->mRespawnLandRaceFrame = GetRaceUpdateFrames();
        ResetRaceTaKartPositions(kart->mIndex);
        return;
    }
    if ((!(kart->mUnk_4c & 0x10000000) && kart->mVelocity.y < 0 &&
         (kart->mAirborneFrames > 0x19 || kart->mLastGroundY - kart->mPos.y > 0x1e000)) ||
        kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
        dotProduct = VEC_DotProduct(groundNormal, &kart->mVelocity);
        normalVelocity.x = MUL_FIXED12_NO_ROUND(groundNormal->x, dotProduct);
        normalVelocity.y = MUL_FIXED12_NO_ROUND(groundNormal->y, dotProduct);
        normalVelocity.z = MUL_FIXED12_NO_ROUND(groundNormal->z, dotProduct);
        if (VEC_Mag(&normalVelocity) > 0x2000) {
            speedLimit = MUL_FIXED12_NO_ROUND(kart->mSpeedLimitFactor, 0x1800);
            normalSpeed = normalVelocity.y;
            if (normalSpeed <= 0) {
                normalSpeed = -normalSpeed;
            }
            kart->mVerticalSpeed = MUL_FIXED12_NO_ROUND(normalSpeed, 0x99a);
            if (kart->mVerticalSpeed > speedLimit) {
                kart->mVerticalSpeed = speedLimit;
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
    dotProduct = Vec3DotUnrounded(&kart->mUnk_138, groundNormal);
    if (dotProduct >= 0) {
        return;
    }
    if (kart->mAirTiltAngle <= 0x3e8) {
        return;
    }
    kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, dotProduct + 0x1000);
}

void CollideKartWithMapObjects(Kart *kart) {
    MapObject *touchedMapObjects[2] = {0};
    s32 foundIndex;
    MapObject *mapObject;
    Vec3 positionOffset;
    Vec3 contactNormal;
    Vec3 mapObjectVector;
    Vec3 zeroVector;
    Vec3 *foundMapObjectVector;
    Vec3 *mapObjectStep;
    s32 handlerOutput;
    BOOL contactRequested;
    u16 touchedCount;
    BOOL touchedBefore;
    s32 flagBits;
    s32 handlerIndex;
    s32 foundCount;
    s32 handlerResult;
    s32 factor;
    s32 vectorLength;
    s32 value;
    s32 hitVelocityX;
    s32 hitVerticalSpeed;
    s32 hitVelocityZ;
    u16 slotIndex;

    contactRequested = FALSE;
    mapObject = NULL;
    touchedCount = 0;
    kart->mMapObjectVectorForwardDot = kart->mMapObjectVectorLength = 0;
    foundCount = FindMapObjectsTouchingKart(kart, &kart->mCollisionCenter, &positionOffset);
    if (foundCount != 0) {
        if (!(kart->mUnk_48 & KART_48_SINKING)) {
            foundIndex = foundCount - 1;
            kart->mUnk_44 |= 0x40000;
            if (foundIndex >= 0) {
                zeroVector = gKartVec3Zero;
                do {
                    factor = 0;
                    touchedBefore = FALSE;
                    mapObject = GetFoundMapObject(foundIndex);
                    handlerIndex = CollideKartWithMapObject(kart, mapObject);
                    handlerResult =
                        ((s32(*)(Kart *, s32 *, MapObject *)) gCollideKartWithMapObjectResponses[handlerIndex])(
                            kart, &handlerOutput, mapObject);
                    if (handlerResult != 0) {
                        contactNormal = zeroVector;
                        mapObjectStep = &mapObject->mPosStep;
                        foundMapObjectVector = GetFoundMapObjectVector(foundIndex);
                        vectorLength = KartMapObjectNormalizeLengthOrZero(foundMapObjectVector, &contactNormal);
                        if (vectorLength != 0) {
                            if (handlerOutput != 2) {
                                ((void (*)(Kart *, Vec3 *, MapObject *)) gKartMapObjectSecondResponses[handlerIndex])(
                                    kart, &contactNormal, mapObject);
                            }
                            if (handlerResult & 8) {
                                ApplyKartContact(kart, &contactNormal, (kart->mUnk_44 & 0x40) ? 1 : 0, 0x1000, -1, -1,
                                                 handlerOutput);
                            } else if (handlerResult & 2) {
                                factor = Vec3DotUnrounded(&kart->mTurnedForward, &contactNormal) + 0x1000;
                                if (factor > 0x1000) {
                                    factor = 0x1000;
                                } else if (factor < 0x29) {
                                    factor = 0x29;
                                }
                                kart->mSpeedLimitHitFactor = MUL_FIXED12_NO_ROUND(kart->mSpeedLimitHitFactor, factor);
                            }
                        }
                        if (handlerResult & 1) {
                            if (mapObjectStep->x != 0 || mapObjectStep->y != 0 || mapObjectStep->z != 0) {
                                mapObjectVector = zeroVector;
                                value = 1;
                                if (handlerResult & 4) {
                                    mapObjectVector = *mapObjectStep;
                                } else {
                                    if (vectorLength != 0) {
                                        factor = VEC_DotProduct(&contactNormal, mapObjectStep);
                                        mapObjectVector.x = MUL_FIXED12_NO_ROUND(contactNormal.x, factor);
                                        mapObjectVector.y = MUL_FIXED12_NO_ROUND(contactNormal.y, factor);
                                        mapObjectVector.z = MUL_FIXED12_NO_ROUND(contactNormal.z, factor);
                                    }
                                    if (Vec3DotUnrounded(&contactNormal, &mapObjectVector) < 0) {
                                        value = 0;
                                    }
                                }
                                kart->mMapObjectVectorLength = VEC_Mag(&mapObjectVector);
                                if (kart->mMapObjectVectorLength > 0x1000 && value != 0) {
                                    kart->mMapObjectVectorForwardDot =
                                        Vec3DotUnrounded(&kart->mTurnedForward, &mapObjectVector);
                                    factor = VEC_DotProduct(&kart->mTurnedForward, &mapObjectVector);
                                    hitVerticalSpeed =
                                        mapObjectVector.y - MUL_FIXED12_NO_ROUND(kart->mTurnedForward.y, factor);
                                    hitVelocityZ =
                                        mapObjectVector.z - MUL_FIXED12_NO_ROUND(kart->mTurnedForward.z, factor);
                                    hitVelocityX =
                                        mapObjectVector.x - MUL_FIXED12_NO_ROUND(kart->mTurnedForward.x, factor);
                                    kart->mHitVelocity.x += hitVelocityX;
                                    kart->mHitVelocity.z += hitVelocityZ;
                                    kart->mVerticalSpeed += hitVerticalSpeed;
                                }
                            }
                        }
                        factor = kart->mSpeedLimitHitFactor;
                        if (handlerResult & 8) {
                            contactRequested = TRUE;
                        }
                    }
                    flagBits = mapObject->mFlags & 0x200;
                    if (flagBits != 0) {
                        value = 0x1000;
                    } else {
                        value = MUL_FIXED12_NO_ROUND(0x1000 - factor,
                                                     MUL_FIXED12_NO_ROUND(kart->mVelocityLength, data_usa_021654ec));
                    }
                    if (kart->mVelocityLength > 0x2000 || flagBits != 0) {
                        if (touchedCount < 2) {
                            for (slotIndex = 0; slotIndex < 2; slotIndex++) {
                                if (mapObject == kart->mPrevTouchingMapObjects[slotIndex]) {
                                    touchedBefore = TRUE;
                                    break;
                                }
                            }
                            if (touchedBefore == FALSE) {
                                for (slotIndex = 0; slotIndex < 2; slotIndex++) {
                                    if (mapObject == kart->mPrevTouchingMapObjects[slotIndex] ||
                                        kart->mMapObjectSoundPlayed[slotIndex] != 0) {
                                        continue;
                                    }
                                    StartMapObjectKindSound(mapObject, &kart->mSoundSource, handlerOutput, value);
                                    kart->mMapObjectSoundPlayed[slotIndex] = 1;
                                    break;
                                }
                            }
                            touchedMapObjects[touchedCount] = mapObject;
                            touchedCount++;
                        }
                    }
                    if (handlerIndex == 0xb) {
                        kart->mScaleEffectMapObject = mapObject;
                    }
                } while (--foundIndex >= 0);
            }
        }
        if (kart->mUnk_48 & 0x4000000) {
            if (kart->mScaleEffectMapObject == mapObject) {
                positionOffset.z = 0;
                positionOffset.x = 0;
            }
        }
        VEC_Add(&kart->mPos, &positionOffset, &kart->mPos);
    }
    for (slotIndex = 0; slotIndex < 2; slotIndex++) {
        kart->mPrevTouchingMapObjects[slotIndex] = touchedMapObjects[slotIndex];
        if (kart->mMapObjectSoundPlayed[slotIndex] != 0) {
            kart->mMapObjectSoundFrames[slotIndex]++;
            if (kart->mMapObjectSoundFrames[slotIndex] > 10) {
                kart->mMapObjectSoundPlayed[slotIndex] = 0;
                kart->mMapObjectSoundFrames[slotIndex] = 0;
            }
        }
    }
    if (contactRequested != FALSE) {
        kart->mUnk_44 |= 0x40;
    } else {
        kart->mUnk_44 &= ~0x40;
    }
}
