#include "Main/Kart/kart_drift.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_contact.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_goal_m.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/Item/item_in_use.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/MapObjects/data_02154000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "code_02147cd8.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Sound/sound_start.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Sound/sound_falloffs.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Kart/camera.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Sound/code_0210ab48.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_bomb.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/data_0206a000.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Item/code_020f9334.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Kart/code_02080cd0.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/code_020e01f0.h"
#include "01/Race/mission_run_state.h"
#include "code_0201c528.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/Kart/kart_level.h"
#include "Main/Kart/kart_resources.h"
#include "Main/Kart/kart_slot8_return.h"
#include "Main/Kart/kart_state0_return.h"
#include "Main/Sound/map_object_sound_counter.h"
#include "Main/System/init_after_startup.h"

const int gKartCollisionSingleEffectIds[1] = {0x3a};
const Vec4 gKartResetSecondQuaternion = {0, 0, 0, 0x1000};
const Vec4 gKartResetThirdQuaternion = {0, 0, 0, 0x1000};
const Vec4 gKartResetHeadingQuaternion = {0, 0, 0, 0x1000};
const Vec4 gKartResetFourthQuaternion = {0, 0, 0, 0x1000};
const Vec4 gKartResetRotationQuaternion = {0, 0, 0, 0x1000};
s32 gKartAheadSpeedLimitStartFactor = 0x14cd;
Vec3 gFixedPositionSelectedEffectIds = {0x48, 0x49, 0x4a};
Vec4 gKartState6TargetQuaternion = {0, 0, 0, 0x1000};
Vec3 gKartPointMotionDecayFactors = {0xf33, 0xe66, 0xf33};
KartKillerEndRankOffsets gKartKillerEndRankOffsets = {{1, 1, 1, 1, 2, 2, 3, 3}};
s16 gKartState3EndFrameCount = 0x1e;
s32 gKartWobbleEaseFactor = 0x4cd;
s16 gTurnHeadingReductionAtSpeedLimit = 0x96;
s32 gSpeedReductionAtFullTurnRatio = 0x1ec;
void (*gKartDefaultSlotFunctions[9])(Kart *a) = {InitKartResources,
                                                 ResetKart,
                                                 NULL,
                                                 NULL,
                                                 NULL,
                                                 NULL,
                                                 ResetKartToRespawnPoint,
                                                 ResetKartToStartPlacement,
                                                 (void (*)(Kart *a)) KartSlot8ReturnArgument};
Vec3 gParticipantRecordHeadingAxis = {0, 0x1000, 0};
void (*gKartStateFunctions[8])(struct Kart *) = {(void (*)(struct Kart *)) KartState0ReturnArgument,
                                                 AdvanceKartState1And2,
                                                 AdvanceKartState1And2,
                                                 AdvanceKartState3,
                                                 AdvanceKartState4,
                                                 AdvanceKartState5,
                                                 AdvanceKartState6,
                                                 NULL};
s32 gKartPushFlipAngleDecay = 5;
s32 gKartWobbleAmplitudeDecay = 0xfae;
s32 gKartPushFlipStartVerticalSpeed = 0x3000;
s32 gKartState3SecondLandVerticalSpeed = 0x1000;
Vec3 gFixedPositionEffectPos = {-5652480, 0x2f8000, -24412160};
s32 gKartState5StartAnglePerFrame = 0x898;
s32 gKartSurfaceKind12VerticalSpeeds[5] = {0x1800, 0x2000, 0x3000, 0x800, 0x4000};
s32 gKartRespawnOffsetScale = 0x1e000;
s32 gKartState3StartVerticalSpeed = 0x24cd;
s32 gKartSurfaceKind12SpeedLimitGoals[5] = {0x7000, 0x6400, 0x4000, 0x6800, 0x3c00};
s32 gFirstBaseSpeedLimitReciprocal = 0x6000;
Vec3 gKartPlacementHeadingAxis = {0, 0x1000, 0};
s32 gKartState4StartAnglePerFrame = 0x708;
s32 gKartState5LandVerticalSpeed = 0x2000;
KartEffectScales gKartRaceStartEffectOffsets = {{-2458, -2458, -3482, -2458, -2253, -5325, -2458, -1843, -3482, -2458,
                                                 -3277, -3277, -2458, -2048, -3891, -2458, -3891, -3686, -2458, -2662,
                                                 -5530, -2458, -2458, -4301, -2458, -3482, -3277, -2458, -2048, -2867,
                                                 -2458, -3277, -5530, -2458, -2458, -2867, -2458}};
s32 gTurnHeadingEaseFactor = 0x666;
KartFollowEffectIds gKartFollowEffectIds = {{0x61, 0x60, 0x62}};
KartSurfaceSoundIds gKartSurfaceSoundIds = {{0x1b8, 0x1c9, 0x1c8}};
u16 gKartWobbleAnglePerCall = 0x984;
s32 gKartState3FirstLandVerticalSpeed = 0x1ccd;
s32 gFixedPositionOtherEffectIds[2] = {0x51, 0x50};
s32 gKartWobbleAngleFactor = 0x2328;
s32 gKartOverlapLengthLimit = 0x3000;

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

    if (kart->mMotionFlags & (KART_MOTION_ON_GROUND | KART_MOTION_VERTICAL_CONTACT)) {
        return;
    }
    kart->mMotionFlags |= KART_MOTION_LANDED;
    if (kart->mLandingTimer <= 0) {
        soundQueueIndex = (kart->mEntryFlags & KART_ENTRY_SELECTED) ? 3 : 2;
        sortKeyOffset = gKartSurfaceSoundSortOffsets[2];
        distanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
        AddSoundRequest(gSoundRequestQueues + soundQueueIndex, distanceSquared + sortKeyOffset,
                        (void (*)(void *, int)) StartSurfaceSoundFromKart, kart, 2);
        StartKartModelScaleAnimation(kart, 0);
    }
    kart->mLandingTimer = 7;
    if (kart->mDriveFlags & KART_DRIVE_RESPAWN_LANDING) {
        kart->mEffectFlags &= ~KART_EFFECT_RESPAWN_DROP;
        kart->mDriveFlags &= ~KART_DRIVE_RESPAWN_LANDING;
        kart->mRespawnLandRaceFrame = GetRaceUpdateFrames();
        ResetRaceTaKartPositions(kart->mIndex);
        return;
    }
    if ((!(kart->mEffectFlags & KART_EFFECT_KILLER) && kart->mVelocity.y < 0 &&
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
            bits7c = kart->mEntryFlags;
            if ((bits7c & KART_ENTRY_HAS_CHARACTER_ANIMATION) && kart->mKartModelsEntry->mKartModelHidden == 0) {
                if ((bits7c & KART_ENTRY_SELECTED) || !(bits7c & KART_ENTRY_TERESA_OR_PARKED)) {
                    StartEffectWithCallback(0x4e, &kart->mPos, kart, SetEffectFlatVelocityFromKart);
                }
            }
        }
    }
    if (kart->mAirborneFrames <= 0x14) {
        return;
    }
    dotProduct = Vec3DotUnrounded(&kart->mRotationRow2, groundNormal);
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
        if (!(kart->mDriveFlags & KART_DRIVE_SINKING)) {
            foundIndex = foundCount - 1;
            kart->mMotionFlags |= KART_MOTION_MOVED_BY_OBJECT;
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
                                ApplyKartContact(kart, &contactNormal,
                                                 (kart->mMotionFlags & KART_MOTION_OBJECT_CONTACT) ? 1 : 0, 0x1000, -1,
                                                 -1, handlerOutput);
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
                        value =
                            MUL_FIXED12_NO_ROUND(0x1000 - factor, MUL_FIXED12_NO_ROUND(kart->mVelocityLength,
                                                                                       gFirstBaseSpeedLimitReciprocal));
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
        if (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) {
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
        kart->mMotionFlags |= KART_MOTION_OBJECT_CONTACT;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_OBJECT_CONTACT;
    }
}

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
    if (kart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) {
        return;
    }
    if (kart->mDriveFlags & KART_DRIVE_SINKING) {
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
        if (otherKart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) {
            continue;
        }
        if (otherKart->mDriveFlags & KART_DRIVE_SINKING) {
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
            if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
                dot = VEC_DotProduct(&kart->mGroundNormal, &kartShift);
                kartShift.x -= MUL_FIXED12_NO_ROUND(kart->mGroundNormal.x, dot);
                kartShift.y -= MUL_FIXED12_NO_ROUND(kart->mGroundNormal.y, dot);
                kartShift.z -= MUL_FIXED12_NO_ROUND(kart->mGroundNormal.z, dot);
            }
            if (kart->mMotionFlags & KART_MOTION_COURSE_CONTACT) {
                if (VEC_DotProduct(&kart->mGroundNormal, &kartShift) < 0) {
                    dot = VEC_DotProduct(&kart->mCourseContactNormal, &kartShift);
                    kartShift.x -= MUL_FIXED12_NO_ROUND(kart->mCourseContactNormal.x, dot);
                    kartShift.y -= MUL_FIXED12_NO_ROUND(kart->mCourseContactNormal.y, dot);
                    kartShift.z -= MUL_FIXED12_NO_ROUND(kart->mCourseContactNormal.z, dot);
                }
            }
            if (otherKart->mMotionFlags & KART_MOTION_ON_GROUND) {
                dot = VEC_DotProduct(&otherKart->mGroundNormal, &otherShift);
                otherShift.x -= MUL_FIXED12_NO_ROUND(otherKart->mGroundNormal.x, dot);
                otherShift.y -= MUL_FIXED12_NO_ROUND(otherKart->mGroundNormal.y, dot);
                otherShift.z -= MUL_FIXED12_NO_ROUND(otherKart->mGroundNormal.z, dot);
            }
            if (otherKart->mMotionFlags & KART_MOTION_COURSE_CONTACT) {
                if (VEC_DotProduct(&otherKart->mGroundNormal, &otherShift) < 0) {
                    dot = VEC_DotProduct(&otherKart->mCourseContactNormal, &otherShift);
                    otherShift.x -= MUL_FIXED12_NO_ROUND(otherKart->mCourseContactNormal.x, dot);
                    otherShift.y -= MUL_FIXED12_NO_ROUND(otherKart->mCourseContactNormal.y, dot);
                    otherShift.z -= MUL_FIXED12_NO_ROUND(otherKart->mCourseContactNormal.z, dot);
                }
            }
            VEC_Add(kart->mCollisionPosSource, &kartShift, kart->mCollisionPosSource);
            VEC_Add(otherKart->mCollisionPosSource, &otherShift, otherKart->mCollisionPosSource);
            if (otherKart->mMotionFlags & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT)) {
                VEC_Subtract(&otherKart->mVelocity, &kart->mVelocity, &relativeVelocity);
                dot = VEC_DotProduct(&normal, &relativeVelocity);
                relativeVelocity.x = MUL_FIXED12_NO_ROUND(normal.x, dot);
                relativeVelocity.y = MUL_FIXED12_NO_ROUND(normal.y, dot);
                relativeVelocity.z = MUL_FIXED12_NO_ROUND(normal.z, dot);
                kart->mForwardSpeed += VEC_DotProduct(&kart->mTurnedForward, &relativeVelocity);
            }
            if (kart->mMotionFlags & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT)) {
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
            kartFlags = kart->mEffectFlags;
            if (kartFlags & KART_EFFECT_KILLER) {
                if (!(otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER)) {
                    pushHandled = TRUE;
                    TryStartKartPushDoubleFlip(kart, otherKart);
                }
            } else if ((otherKartFlags = otherKart->mEffectFlags) & KART_EFFECT_KILLER) {
                if (!(kartFlags & KART_EFFECT_STAR_OR_KILLER)) {
                    pushHandled = TRUE;
                    TryStartKartPushDoubleFlip(otherKart, kart);
                }
            } else if (kartFlags & KART_EFFECT_STAR) {
                if (!(otherKartFlags & KART_EFFECT_STAR_OR_KILLER)) {
                    negatedNormal.x = -normal.x;
                    negatedNormal.y = -normal.y;
                    negatedNormal.z = -normal.z;
                    pushHandled = TRUE;
                    TryStartKartPushFlip(kart, otherKart, &negatedNormal);
                }
            } else if (otherKartFlags & KART_EFFECT_STAR) {
                if (!(kartFlags & KART_EFFECT_STAR_OR_KILLER)) {
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
            if (overlapLength > gKartOverlapLengthLimit) {
                kart->mEffectFlags |= KART_EFFECT_KART_OVERLAP;
                otherKart->mEffectFlags |= KART_EFFECT_KART_OVERLAP;
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
        kart->mMotionFlags |= KART_MOTION_NEAR_KART;
        otherKart->mMotionFlags |= KART_MOTION_NEAR_KART;
        kart->mNearKartMask |= 1 << otherKart->mIndex;
        otherKart->mNearKartMask |= 1 << kart->mIndex;
    }
}

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
        flipAxis = killerKart->mRotationRow0;
        VEC_Subtract(&hitKart->mPos, &killerKart->mPos, &offsetToHit);
        VEC_CrossProduct(&killerKart->mRotationRow2, &offsetToHit, &crossProduct);
        if (VEC_DotProduct(&crossProduct, &killerKart->mRotationRow1) < 0) {
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
                    kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
                }
                StopKartAheadEffect(kart);
            }
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BUILD_UP) {
        kart->mAheadSpeedLimitFactor += 7;
        if (kart->mAheadSpeedLimitFactor > FIXED12_RATIO(6, 5)) {
            kart->mAheadSpeedLimitFactor = FIXED12_RATIO(6, 5);
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
        case ITEM_OBJECT_KIND_KOURA_G:
        case ITEM_OBJECT_KIND_KOURA_R:
        case ITEM_OBJECT_KIND_F_BOX:
            hitResult = TryStartKartState3(kart);
            break;
        case ITEM_OBJECT_KIND_BANANA:
            hitResult = TrySpinKart(kart, 1, hitResult);
            if (hitResult != 0 && kart->mKartModelsEntry->mKartModelHidden == 0) {
                StartEffect(0xc, &kart->mPos);
                StartEffect(0xd, &kart->mPos);
                StartEffect(0xe, &kart->mPos);
            }
            break;
        case ITEM_OBJECT_KIND_KINOKO:
            // r is still 0 here, KART_BOOST_ITEM_OR_SURFACE.
            StartKartBoost(kart, hitResult, 0x5a);
            kart->mDriveFlags |= KART_DRIVE_KINOKO_BOOST;
            kart->mItemEffectData.mKinokoBoostTimer = 0x5a;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                ClearStandingsHitSeenFromKart(kart->mIndex);
            }
            break;
        case ITEM_OBJECT_KIND_STAR:
            StartKartStar(kart);
            break;
        case ITEM_OBJECT_KIND_KOURA_W:
            if (((ItemKouraW *) itemObject)->mHitSpinsKart != 0) {
                hitResult = TrySpinKart(kart, 2, hitResult);
            } else {
                hitResult = TryStartKartState6(kart);
            }
            break;
        case ITEM_OBJECT_KIND_BOMB:
            if (((ItemBomb *) itemObject)->mHitSpinsKart != 0) {
                hitResult = TrySpinKart(kart, 2, hitResult);
            } else {
                hitResult = TryStartKartState6(kart);
            }
            break;
        case ITEM_OBJECT_KIND_THUNDER:
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
        case ITEM_OBJECT_KIND_BOUNCING_ITEM_BOX:
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

void AdvanceKartBoost(s32 *acceleration, Kart *kart) {
    int secondArgument;
    u32 flags;
    KartItemEffectState *itemEffectState;
    u16 diffColor;
    u16 emiColor;
    u16 ambColor;

    kart->mBoostTimer = kart->mBoostTimer - 1;
    if (kart->mBoostTimer <= 0) {
        kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_ITEM_BOOST);
        kart->mBoostTimer = 0;
        if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
            return;
        }
        if (!(kart->mEffectFlags & KART_EFFECT_KILLER)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
        return;
    }
    *acceleration = 0x1000;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        secondArgument = (kart->mDriveFlags & KART_DRIVE_RACE_START_BOOST) ? 0xa0 : 0x9e;
        AddSoundRequest(gSoundRequestQueues, GetKartCameraDistanceSquared(kart->mIndex), RequestKartSound, kart,
                        secondArgument);
    }
    if (!(kart->mDriveFlags & KART_DRIVE_ITEM_BOOST)) {
        return;
    }
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);
    flags = kart->mEffectFlags;
    if (flags & KART_EFFECT_COURSE_COLORED) {
        return;
    }
    if (!(flags & KART_EFFECT_GESSO)) {
        return;
    }
    itemEffectState = &kart->mItemEffectData;
    if (itemEffectState->mGessoFrames > KART_GESSO_COLORED_FRAME) {
        return;
    }
    itemEffectState->mGessoFrames = KART_GESSO_COLORED_FRAME;
    kart->mEffectFlags |= KART_EFFECT_COURSE_COLORED;
    diffColor = GetKartCourseDiffColor();
    emiColor = GetKartCourseEmiColor();
    ambColor = GetKartCourseAmbColor();
    StartKartModelColorBlend(kart->mKartModelsEntry, diffColor, emiColor, ambColor);
}

void EndKartDrift(Kart *kart) {
    if (!(kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        kart->mMotionFlags |= KART_MOTION_DRIFT_ENDED_IN_AIR;
    }
    if (kart->mDriftCharge == KART_DRIFT_CHARGE_MINI_TURBO_READY) {
        StartKartBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->mMiniTurboFrames);
        kart->mDriveFlags |= KART_DRIVE_MINI_TURBO;
        kart->mMiniTurboTimer = kart->mPhysicalParam->mMiniTurboFrames;
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            GetEntryKartCounters()->mMiniTurboCount++;
            if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunCountForKind4();
            }
        }
    }
    kart->mMotionFlags &=
        ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
    kart->mTurnDirection = 0;
    kart->mDriftCharge = KART_DRIFT_CHARGE_NONE;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
}

void AdvanceKartDriftTurnAngle(Kart *kart, int fromLowSpeedTurn) {
    if (kart->mTurnDirection > 0) {
        if (kart->mTurnAngle > 11000) {
            kart->mTurnAngle = kart->mTurnAngle - 200;
            if (kart->mTurnAngle < 11000) {
                kart->mTurnAngle = 11000;
            }
        } else if (kart->mTurnAngle < 11000) {
            kart->mTurnAngle += 375;
            if (kart->mTurnAngle > 11000) {
                kart->mTurnAngle = 11000;
            }
        }
    } else {
        if (kart->mTurnAngle < -11000) {
            kart->mTurnAngle = kart->mTurnAngle + 200;
            if (kart->mTurnAngle > -11000) {
                kart->mTurnAngle = -11000;
            }
        } else if (kart->mTurnAngle > -11000) {
            kart->mTurnAngle -= 375;
            if (kart->mTurnAngle < -11000) {
                kart->mTurnAngle = -11000;
            }
        }
    }
    if (fromLowSpeedTurn != 0) {
        return;
    }
    if (kart->mDriftHeadingAnglePerFrame <= 50) {
        kart->mDriftHeadingAnglePerFrame = 50;
    } else {
        kart->mDriftHeadingAnglePerFrame = MUL_FIXED12_NO_ROUND(kart->mDriftHeadingAnglePerFrame, 0xf33);
    }
    AdvanceKartDriftCharge(kart);
    if (!(kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        return;
    }
    AddKartSurfaceSoundRequest(kart, 1);
    kart->mEffectFlags |= KART_EFFECT_GROUND_SOUND_STEP;
    if (kart->mDriftCharge < KART_DRIFT_CHARGE_LEVEL_3) {
        return;
    }
    if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        return;
    }
    StartSoundWhileRequested(&kart->mSoundSource, 0xd1, 0x7f, 0);
}

// Drift step: the hop, the turn held after it, the charge, and the release with the mini-turbo.
void AdvanceKartDrift(Kart *kart) {
    u32 bits44 = kart->mMotionFlags;
    BOOL hasB = (bits44 & KART_MOTION_HOPPING) != 0;
    u32 value;
    KartTurnEffects *turnEffects;
    int distanceSquared;
    enum { K0 } entryIndex;

    if (kart->mEntryFlags & KART_ENTRY_WIFI_PEER) {
        return;
    }
    if (kart->mAirborneFrames >= 5 &&
        !(bits44 & (KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_ON_GROUND))) {
        entryIndex = kart->mEntryIndex;
        if ((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_R)) {
            if (bits44 & KART_MOTION_DRIFT_ARMED) {
                goto recheck;
            }
            if (kart->mTurnDirection != 0) {
                goto recheck;
            }
            value = kart->mDriveFlags;
            if (value & KART_DRIVE_TURN_RIGHT) {
                kart->mTurnDirection = 1;
                kart->mMotionFlags |= KART_MOTION_DRIFT_ARMED;
            } else if (value & KART_DRIVE_TURN_LEFT) {
                kart->mTurnDirection = -1;
                kart->mMotionFlags |= KART_MOTION_DRIFT_ARMED;
            }
        } else {
            kart->mMotionFlags &= ~KART_MOTION_DRIFT_ARMED;
        }
    }
recheck:
    if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        if (kart->mTurnDirection == 0) {
            value = kart->mDriveFlags;
            if (value & KART_DRIVE_TURN_RIGHT) {
                kart->mTurnDirection = 1;
            } else if (value & KART_DRIVE_TURN_LEFT) {
                kart->mTurnDirection = -1;
            }
        }
    }
    bits44 = kart->mMotionFlags;
    value = kart->mTurnDirection;
    if (!(bits44 & KART_MOTION_DRIFTING) && (bits44 & KART_MOTION_ON_GROUND)) {
        if ((bits44 & (KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING)) &&
            kart->mVelocityLength > MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, 0x8cd) && value != 0 &&
            (u16) (gInputSlots[entryIndex = kart->mEntryIndex].mBits & PAD_KEY_R)) {
            kart->mMotionFlags |= KART_MOTION_DRIFTING;
            kart->mDriftCharge = KART_DRIFT_CHARGE_STARTED;
            if (kart->mTurnDirection > 0) {
                kart->mAwayTurnCounter = &kart->mLeftTurnCount;
                kart->mTowardTurnCounter = &kart->mRightTurnCount;
            } else {
                kart->mAwayTurnCounter = &kart->mRightTurnCount;
                kart->mTowardTurnCounter = &kart->mLeftTurnCount;
            }
            if (kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) {
                turnEffects = GetKartTurnEffects(kart->mIndex);
                ResetKartLevel4Effects(turnEffects);
                StartKartTurnStartEffects(turnEffects);
            }
        } else {
            kart->mTurnDirection = 0;
        }
        kart->mMotionFlags &= ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_HOP_STEER);
    }
    bits44 = kart->mMotionFlags;
    if (bits44 & KART_MOTION_DRIFTING) {
        entryIndex = kart->mEntryIndex;
        if (!((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_R) && (kart->mDriveFlags & KART_DRIVE_ACCEL_HELD) &&
              kart->mVelocityLength >= kart->mPhysicalParam->mBaseSpeedLimit / 2 &&
              !(bits44 & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT | KART_MOTION_DRIFT_BREAK)))) {
            if (!(bits44 & KART_MOTION_ON_GROUND)) {
                kart->mMotionFlags |= KART_MOTION_DRIFT_ENDED_IN_AIR;
            }
            if (kart->mDriftCharge == KART_DRIFT_CHARGE_MINI_TURBO_READY) {
                StartKartBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->mMiniTurboFrames);
                kart->mDriveFlags |= KART_DRIVE_MINI_TURBO;
                kart->mMiniTurboTimer = kart->mPhysicalParam->mMiniTurboFrames;
                if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                    GetEntryKartCounters()->mMiniTurboCount++;
                    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
                        AddMissionRunCountForKind4();
                    }
                }
            }
            kart->mMotionFlags &=
                ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
            kart->mTurnDirection = 0;
            kart->mDriftCharge = KART_DRIFT_CHARGE_NONE;
            kart->mRightTurnCount = 0;
            kart->mLeftTurnCount = kart->mRightTurnCount;
            kart->mTurnCountTimer = 0;
            StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else if (bits44 & KART_MOTION_ON_GROUND) {
            AdvanceKartDriftTurnAngle(kart, 0);
        }
    }
    if (hasB && (kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        int turn = 0;
        int dot;
        int ang;
        int len;
        Vec3 projectedForward;
        Vec3 crossVector;
        Vec3 *forward = &kart->mRotationRow2;

        dot = VEC_DotProduct(&kart->mHopStartUp, forward);
        projectedForward.x = kart->mRotationRow2.x - MUL_FIXED12_NO_ROUND(kart->mHopStartUp.x, dot);
        projectedForward.y = forward->y - MUL_FIXED12_NO_ROUND(kart->mHopStartUp.y, dot);
        projectedForward.z = forward->z - MUL_FIXED12_NO_ROUND(kart->mHopStartUp.z, dot);
        if (LENGTH_SQUARED(projectedForward) >= 16
                ? Vec3NormalizeAndGetLengthUnchecked(&projectedForward, &projectedForward)
                : 0) {
            Vec3CrossUnrounded(&kart->mHopStartForward, &projectedForward, &crossVector);
            len = VEC_Mag(&crossVector);
            ang = FX_Atan2(len, Vec3DotUnrounded(&kart->mHopStartForward, &projectedForward));
            turn = (s16) (((s64) ang * 0x28be60db9391LL + 0x80000000LL) >> 44);
        }
        if (kart->mForwardSpeed < 0) {
            value = -value;
        }
        kart->mTurnAngle += (s16) (turn * value);
        if (kart->mTurnAngle > 0x2af8) {
            kart->mTurnAngle = 0x2af8;
        } else if (kart->mTurnAngle < -0x2af8) {
            kart->mTurnAngle = -0x2af8;
        }
        if (!(kart->mMotionFlags & KART_MOTION_DRIFTING)) {
            return;
        }
        kart->mDriftHeadingAnglePerFrame = MUL_FIXED12_NO_ROUND(kart->mVelocityLength, 0x1a);
        return;
    }
    entryIndex = kart->mEntryIndex;
    if (!(u16) (gInputSlots[entryIndex].mPressedBits & PAD_KEY_R)) {
        if (!(kart->mMotionFlags & KART_MOTION_AI_DRIFT_REQUEST)) {
            return;
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    if (!(kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        distanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
        AddSoundRequest(&gSoundRequestQueues[3], distanceSquared + GetKartFullVolumeSoundSortOffset(),
                        KartStartSoundFullVolume, kart, 0xcf);
    }
    kart->mMotionFlags |= KART_MOTION_HOPPING | KART_MOTION_HOP_ACTIVE | KART_MOTION_HOP_STEER;
    kart->mMotionFlags &= ~(KART_MOTION_DRIFTING | KART_MOTION_DRIFT_ENDED_IN_AIR);
    kart->mHopSpeed = 0x1405;
    kart->mVerticalSpeed += 0x21a2;
    kart->mHopHeight = 0;
    kart->mTurnDirection = 0;
    kart->mDriftHeadingAnglePerFrame = 0;
    kart->mDriftCharge = KART_DRIFT_CHARGE_NONE;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    GetKartForward(kart, &kart->mHopStartForward);
    GetKartUp(kart, &kart->mHopStartUp);
    if (kart->mCollisionHitLink->mObject != NULL) {
        kart->mCollisionHitLink->mObject = NULL;
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x1;
    }
}

// At low speed, with the A and B keys held and no boost running, steers the kart with the left and right keys; TRUE
// when it acts.
int TryTurnKartAtLowSpeed(Kart *kart) {
    BOOL result = FALSE;
    BOOL pending = TRUE;
    BOOL dir = FALSE;
    int delta;
    u16 bits;
    KartTurnEffects *turnEffects;
    enum { K0 } entryIndex;

    if (kart->mVelocityLength < 0x1800 && (kart->mDriveFlags & KART_DRIVE_BRAKING)) {
        kart->mTurnDirection = 0;
        result = TRUE;
        pending = FALSE;
        entryIndex = kart->mEntryIndex;
        bits = gInputSlots[entryIndex].mBits;
        if ((u16) (bits & PAD_KEY_LEFT)) {
            dir = TRUE;
            kart->mTurnDirection = -1;
            delta = 500;
        } else if ((u16) (bits & PAD_KEY_RIGHT)) {
            dir = TRUE;
            kart->mTurnDirection = 1;
            delta = -500;
        }
        if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
            if (GetKartTurnEffects(kart->mIndex)->mTurnStartPresent == 0 &&
                (kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK)) {
                turnEffects = GetKartTurnEffects(kart->mIndex);
                ResetKartLevel4Effects(turnEffects);
                StartKartTurnStartEffects(turnEffects);
            }
            kart->mDriveFlags |= KART_DRIVE_LOW_SPEED_TURN;
            if (kart->mTurnDirection != 0) {
                kart->mMotionFlags |= KART_MOTION_LOW_SPEED_TURN;
                kart->mHeadingAngle += delta;
                AdvanceKartDriftTurnAngle(kart, 1);
            }
        }
        StartKartLowSpeedTurnSound(kart, dir, kart->mSurfaceKind, kart->mSurfaceVariant);
    }
    if (pending) {
        StopKartTurnStartEffects(GetKartTurnEffects(kart->mIndex));
    }
    return result;
}

void SetEffectScaleFromKart(ParticleEmitter *emitter, Kart *kart) {
    SetEffectScaleFromKartScaleZ(emitter, kart);
}

void SetEffectVelocityFromKart(ParticleEmitter *emitter, Kart *kart) {
    emitter->mVelocity = kart->mEffectVelocity;
    SetEffectScaleFromKartScaleZ(emitter, kart);
}

// Starts the effects of a kart-kart hit at the contact point; flag picks the four-effect set.
BOOL TryStartKartCollisionEffects(Kart *kart, const Vec3 *overlapDirection, int flag) {
    if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
        int fourEffectIds[4] = {0x77, 0x76, 0x78, 0x79};
        u16 effectIndex = 0;
        u32 effectCount = 1;
        const int *effectIds = gKartCollisionSingleEffectIds;
        Vec3 contactPoint;

        if (flag) {
            effectIds = fourEffectIds;
            effectCount = 4;
        }
        VEC_MultAdd(-kart->mRadius, overlapDirection, &kart->mPos, &contactPoint);
        VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mScale.y, 0x8000), &kart->mRotationRow1, &contactPoint, &contactPoint);
        for (; effectIndex < effectCount; effectIndex++) {
            StartEffectWithCallback(effectIds[effectIndex], &contactPoint, kart, SetEffectVelocityFromKart);
        }
        return TRUE;
    }
    return FALSE;
}

void SetEffectFlatVelocityFromKart(ParticleEmitter *emitter, Kart *kart) {
    Vec3 velocity = kart->mEffectVelocity;

    velocity.y = 0;
    velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, 0xe66);
    velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, 0xe66);
    velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, 0xe66);
    emitter->mVelocity = velocity;
}

void PlaceEffectBehindKart(ParticleEmitter *emitter, Kart *kart) {
    Vec3 position = kart->mPos;
    Vec3s16 rot;
    Vec3 *forward;

    VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mRadius, -0x1333), &kart->mRotationRow2, &position, &position);
    position.x >>= 4;
    position.y >>= 4;
    position.z >>= 4;
    emitter->mPosition.x = emitter->mResource->mHeader->mPositionOffset.x + position.x;
    emitter->mPosition.y = position.y + emitter->mResource->mHeader->mPositionOffset.y;
    emitter->mPosition.z = position.z + emitter->mResource->mHeader->mPositionOffset.z;
    forward = &kart->mRotationRow2;
    rot.x = forward->x;
    rot.y = forward->y;
    rot.z = forward->z;
    emitter->mDirection = rot;
}

void StartKartBlink(Kart *kart) {
    if (kart->mEntryFlags & KART_ENTRY_BATTLE_REMOVAL) {
        return;
    }
    kart->mEffectFlags |= KART_EFFECT_BLINK_GUARD;
    kart->mBlinkCycleFrames = 0;
    kart->mBlinkFrames = kart->mBlinkCycleFrames;
}

void SetupKartAiHeldItemEntry(Kart *kart) {
    if (kart->mEntryFlags & KART_ENTRY_CPU) {
        CallKartAiSetupHeldItemEntry(kart->mAi);
    }
}

void SetupKartAiItemInUseEntry(Kart *kart) {
    if (kart->mEntryFlags & KART_ENTRY_CPU) {
        CallKartAiSetupItemInUseEntry(kart->mAi);
    }
}

// TRUE for a removed, Boo or respawning kart, or any state but normal driving.
BOOL IsKartNotNormal(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) || (kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP) ||
        kart->mState != KART_STATE_NORMAL) {
        return TRUE;
    }
    return FALSE;
}

// TRUE for a removed kart or one in the respawn drop.
BOOL IsKartRemovedOrRespawning(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED_OR_PARKED) || (kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP)) {
        return TRUE;
    }
    return FALSE;
}

int GetKartCourseHitAttributeBit(Kart *kart) {
    return kart->mCourseHitAttributeBit;
}

BOOL IsKartOutOfView(Kart *kart) {
    return (kart->mEffectFlags & KART_EFFECT_OUT_OF_VIEW) != 0;
}

void StartKartState(Kart *kart, KartState mode) {
    kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_MINI_TURBO |
                           KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        if (!(kart->mEffectFlags & KART_EFFECT_KILLER) && !(kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    SetKartCharacterAnimation(kart, 1, 0);
    kart->mState = mode;
    kart->mMotionFlags &=
        ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
    kart->mTurnDirection = 0;
    kart->mDriftCharge = KART_DRIFT_CHARGE_NONE;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BOOST;
        kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
        if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
            ResetKartModelsCourseColors(kart);
        }
        StopKartNearRankEffect(kart);
    }
}

BOOL TryStartKartState(Kart *kart, KartState newState) {
    BOOL ok;
    BOOL res;
    BOOL flag;
    int currentState;
    u32 bits4c = kart->mEffectFlags;

    if (bits4c & KART_EFFECT_BLINK_GUARD) {
        ok = FALSE;
    } else if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING) &&
            !(bits4c & KART_EFFECT_STAR_OR_KILLER)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        switch (newState) {
            case KART_STATE_1:
            case KART_STATE_SPIN:
                res = TRUE;
                if (!(bits4c & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
                    currentState = kart->mState;
                    flag = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        flag = TRUE;
                    }
                    if (flag == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
            default:
                res = TRUE;
                if (!(bits4c & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
                    currentState = kart->mState;
                    flag = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        flag = TRUE;
                    }
                    if (flag == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
        }
    }
    if (!ok) {
        return FALSE;
    }
    StartKartState(kart, newState);
    return TRUE;
}

// Starts a spin, or adds a turn to the spin already running.
BOOL TrySpinKart(Kart *kart, int rotationCount, int skipSound) {
    int currentState = kart->mState;
    BOOL notSpinning;
    BOOL ok;
    BOOL res;
    BOOL flag;
    int state;
    u32 bits4c;

    notSpinning = currentState != KART_STATE_1 && currentState != KART_STATE_SPIN;
    if (notSpinning == FALSE) {
        if (kart->mYRotationCount * 0xffff - kart->mYRotationAngleSum > 0xffff ||
            (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL)) {
            return FALSE;
        }
    }
    bits4c = kart->mEffectFlags;
    if (bits4c & KART_EFFECT_BLINK_GUARD) {
        ok = FALSE;
    } else if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING) &&
            !(bits4c & KART_EFFECT_STAR_OR_KILLER)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        res = TRUE;
        if (!(bits4c & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
            state = kart->mState;
            flag = FALSE;
            if (state != KART_STATE_NORMAL && currentState != KART_STATE_1 && currentState != KART_STATE_SPIN) {
                flag = TRUE;
            }
            if (flag == FALSE) {
                res = FALSE;
            }
        }
        ok = res == FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (notSpinning) {
        StartKartState2(kart, rotationCount, skipSound);
        if (skipSound == 0) {
            if (rotationCount == 1) {
                if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
                    kart->mParticipantRecordData->mEventToggleFlags ^= 0x4;
                }
            } else if (rotationCount == 2) {
                if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
                    kart->mParticipantRecordData->mEventToggleFlags ^= 0x8;
                }
            }
        }
    } else {
        kart->mYRotationCount++;
    }
    return TRUE;
}
