#include "ITCM/collision_slots.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "fixed_vector_math.h"
#include "registers.h"

void UpdateCollisionSlotBounds(void) {
    s32 i = 0;
    s32 j = 0;
    s32 endIndex;
    s32 scanIndex;
    CollisionSlot *slot;
    Vec3 *center;
    s32 radius;
    u16 flags;
    CollisionSlotEnd *currentEnd;
    CollisionSlotEnd *previousEnd;
    u32 swapTemp;
    CollisionSlotEnd *lowEnds;
    CollisionSlotEnd *currentOtherEnd;
    CollisionSlotEnd *previousOtherEnd;
    if (gCollisionSlotCount > 0) {
        do {
            slot = &gCollisionSlots[i];
            center = slot->mCenterPos;
            radius = slot->mRadius;
            if (center != NULL) {
                flags = slot->mFlags;
                if (flags & 0x600) {
                    if (flags & COLLISION_SLOT_FLAG_RADIUS_CHANGED) {
                        slot->mFlags = flags & ~COLLISION_SLOT_FLAG_RADIUS_CHANGED;
                    } else {
                        j++;
                        goto next;
                    }
                }
                j++;
                slot->mHighZ = center->z + radius;
                slot->mLowZ = center->z - radius;
                gCollisionSlotHighEnds[slot->mHighEndIndex].mEndX = (center->x + radius) >> 11;
                gCollisionSlotLowEnds[slot->mLowEndIndex].mEndX = (center->x - radius) >> 11;
            }
        next:
            i++;
        } while (j < gCollisionSlotCount);
    }
    for (i = 1; i < gCollisionSlotCount; i++) {
        j = i;
        while ((currentEnd = &gCollisionSlotHighEnds[j],
                previousEnd = &gCollisionSlotHighEnds[j - 1], previousEnd->mEndX > currentEnd->mEndX) &&
               j >= 1) {
            swapTemp = *(u32 *) currentEnd;
            *(u32 *) currentEnd = *(u32 *) previousEnd;
            *(u32 *) previousEnd = swapTemp;
            lowEnds = gCollisionSlotLowEnds;
            currentOtherEnd = &lowEnds[currentEnd->mOtherEndIndex];
            previousOtherEnd = &lowEnds[previousEnd->mOtherEndIndex];
            currentOtherEnd->mOtherEndIndex++;
            previousOtherEnd->mOtherEndIndex--;
            gCollisionSlots[currentOtherEnd->mSlotIndexOrScanLimit].mHighEndIndex++;
            gCollisionSlots[previousOtherEnd->mSlotIndexOrScanLimit].mHighEndIndex--;
            if (currentEnd->mSlotIndexOrScanLimit == previousEnd->mOtherEndIndex) {
                scanIndex = currentEnd->mSlotIndexOrScanLimit;
                do {
                    scanIndex++;
                } while (gCollisionSlotLowEnds[scanIndex].mOtherEndIndex < j);
                currentEnd->mSlotIndexOrScanLimit = scanIndex;
            }
            if (previousEnd->mSlotIndexOrScanLimit > currentEnd->mOtherEndIndex) {
                previousEnd->mSlotIndexOrScanLimit = currentEnd->mOtherEndIndex;
            }
            j--;
        }
    }
    for (i = 1; i < gCollisionSlotCount; i++) {
        j = i;
        while ((currentEnd = &gCollisionSlotLowEnds[j], previousEnd = &gCollisionSlotLowEnds[j - 1],
                previousEnd->mEndX > currentEnd->mEndX) &&
               j >= 1) {
            swapTemp = *(u32 *) currentEnd;
            *(u32 *) currentEnd = *(u32 *) previousEnd;
            *(u32 *) previousEnd = swapTemp;
            gCollisionSlotHighEnds[currentEnd->mOtherEndIndex].mOtherEndIndex++;
            gCollisionSlotHighEnds[previousEnd->mOtherEndIndex].mOtherEndIndex--;
            gCollisionSlots[currentEnd->mSlotIndexOrScanLimit].mLowEndIndex++;
            gCollisionSlots[previousEnd->mSlotIndexOrScanLimit].mLowEndIndex--;
            if (currentEnd->mOtherEndIndex > previousEnd->mOtherEndIndex) {
                for (endIndex = currentEnd->mOtherEndIndex;
                     endIndex > previousEnd->mOtherEndIndex &&
                     gCollisionSlotHighEnds[endIndex].mSlotIndexOrScanLimit == j - 1;
                     endIndex--) {
                    gCollisionSlotHighEnds[endIndex].mSlotIndexOrScanLimit++;
                }
            } else {
                endIndex = previousEnd->mOtherEndIndex;
                while (endIndex > currentEnd->mOtherEndIndex &&
                       gCollisionSlotHighEnds[endIndex].mSlotIndexOrScanLimit == j) {
                    gCollisionSlotHighEnds[endIndex--].mSlotIndexOrScanLimit--;
                }
            }
            j--;
        }
    }
}

void FindCollisionSlotsOverlappingSlot(s32 slotId, s32 flagMask) {
    CollisionSlot *slot;
    s32 highX;
    s32 lowX;
    s32 lowScan;
    s32 lowEndIndex;
    s32 lastIndex;
    s32 highZ;
    s32 lowZ;
    CollisionSlotEnd *lowEnds;
    s32 highScan;
    CollisionSlotEnd *highEnds;
    s32 bigStepLimit;
    s32 scanIndex;
    s16 minIndex;
    u32 scanLimit;
    CollisionSlot *otherSlot;
    u16 otherFlags;
    if (slotId < 0 || slotId >= COLLISION_SLOT_COUNT) {
        return;
    }
    slot = GetCollisionSlot(slotId);
    highScan = slot->mHighEndIndex;
    lowEndIndex = slot->mLowEndIndex;
    lowScan = lowEndIndex;
    highEnds = gCollisionSlotHighEnds;
    lowEnds = gCollisionSlotLowEnds;
    lastIndex = gCollisionSlotCount - 1;
    highX = highEnds[highScan].mEndX;
    lowX = lowEnds[lowEndIndex].mEndX;
    highZ = slot->mHighZ;
    lowZ = slot->mLowZ;
    if (slot->mCenterPos == NULL) {
        gFoundCollisionSlotCount = 0;
        return;
    }
    gFoundCollisionSlotCount = 0;
    while (highScan > 7 && highEnds[highScan - 8].mEndX >= lowX) {
        highScan -= 8;
    }
    while (highScan > 0 && highEnds[highScan - 1].mEndX >= lowX) {
        highScan--;
    }
    bigStepLimit = lastIndex - 7;
    while (lowScan < bigStepLimit && lowEnds[lowScan + 8].mEndX <= highX) {
        lowScan += 8;
    }
    while (lowScan < lastIndex && lowEnds[lowScan + 1].mEndX <= highX) {
        lowScan++;
    }
    scanIndex = (s16) lowScan;
    scanLimit = highEnds[highScan].mSlotIndexOrScanLimit;
    minIndex = scanLimit;
    if (scanIndex < minIndex) {
        return;
    }
    for (;;) {
        if (gCollisionSlotLowEnds[scanIndex].mOtherEndIndex >= highScan && scanIndex != lowEndIndex) {
            otherSlot = &gCollisionSlots[gCollisionSlotLowEnds[scanIndex].mSlotIndexOrScanLimit];
            otherFlags = otherSlot->mFlags;
            if (otherSlot->mHighZ < lowZ || otherSlot->mLowZ > highZ || !(otherFlags & flagMask) ||
                (otherFlags & COLLISION_SLOT_FLAG_DISABLED)) {
                goto next;
            }
            gFoundCollisionSlotIndices[gFoundCollisionSlotCount] =
                gCollisionSlotLowEnds[scanIndex].mSlotIndexOrScanLimit;
            gFoundCollisionSlotFlags[gFoundCollisionSlotCount] = otherFlags;
            gFoundCollisionSlotObjects[gFoundCollisionSlotCount] = otherSlot->mObject;
            gFoundCollisionSlotCount++;
            if (gFoundCollisionSlotCount == FOUND_COLLISION_SLOT_CAPACITY) {
                return;
            }
        }
        if (scanIndex == 0) {
            return;
        }
    next:
        scanIndex--;
        if (scanIndex < minIndex) {
            break;
        }
    }
}

s32 ComputeViewTest(Vec3 *pos, s32 radius, s32 maxDistance, s32 farDistanceSquared, u16 alpha) {
    s32 result;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    s32 horizontalDistanceSquared;
    s32 xSquared;
    s32 bottomDotX;
    maxDistance = FROM_FIXED12(maxDistance + radius);
    offsetZ = FROM_FIXED12(pos->z - gViewFrustum.mCameraPos.z);
    offsetX = FROM_FIXED12(pos->x - gViewFrustum.mCameraPos.x);
    xSquared = offsetX * offsetX;
    horizontalDistanceSquared = offsetZ * offsetZ + xSquared;
    result = horizontalDistanceSquared & MAP_OBJECT_VIEW_DISTANCE_MASK;
    if (horizontalDistanceSquared > farDistanceSquared) {
        result |= gViewTestDistanceLimitFlag;
    }
    if (horizontalDistanceSquared > maxDistance * maxDistance) {
        if (alpha <= 1) {
            return result | MAP_OBJECT_VIEW_OUT_OF_SIGHT;
        }
        result |= gViewTestMaxDistanceFlag;
    }
    offsetY = FROM_FIXED12(pos->y - gViewFrustum.mCameraPos.y);
    if (offsetX * gViewFrustum.mViewDirection.x + offsetY * gViewFrustum.mViewDirection.y +
            offsetZ * gViewFrustum.mViewDirection.z <
        gViewFrustum.mNear - radius) {
        return result | MAP_OBJECT_VIEW_OUTSIDE_PLANES;
    }
    if (offsetX * gViewFrustum.mLeftPlaneNormal.x + offsetY * gViewFrustum.mLeftPlaneNormal.y +
            offsetZ * gViewFrustum.mLeftPlaneNormal.z >
        radius) {
        return result | MAP_OBJECT_VIEW_OUTSIDE_PLANES;
    }
    if (offsetX * gViewFrustum.mRightPlaneNormal.x + offsetY * gViewFrustum.mRightPlaneNormal.y +
            offsetZ * gViewFrustum.mRightPlaneNormal.z >
        radius) {
        return result | MAP_OBJECT_VIEW_OUTSIDE_PLANES;
    }
    if (offsetX * gViewFrustum.mTopPlaneNormal.x + offsetY * gViewFrustum.mTopPlaneNormal.y +
            offsetZ * gViewFrustum.mTopPlaneNormal.z >
        radius) {
        return result | MAP_OBJECT_VIEW_OUTSIDE_PLANES;
    }
    bottomDotX = offsetX * gViewFrustum.mBottomPlaneNormal.x;
    if (offsetZ * gViewFrustum.mBottomPlaneNormal.z + (offsetY * gViewFrustum.mBottomPlaneNormal.y + bottomDotX) >
        radius) {
        result |= MAP_OBJECT_VIEW_OUTSIDE_PLANES;
    }
    return result;
}

static inline s32 GetFrustumLeftPlaneNormalY(ViewFrustum *viewFrustum) {
    return viewFrustum->mLeftPlaneNormal.y;
}

s32 ComputeTwoPlaneViewTest(Vec3 *pos, s32 radius, s32 maxDistance, s32 farDistanceSquared, u16 alpha) {
    Vec3 offset;
    s32 result;
    s32 horizontalDistanceSquared;
    s32 offsetX;
    maxDistance = FROM_FIXED12(maxDistance + radius);
    VEC_Subtract(pos, &gViewFrustum.mCameraPos, &offset);
    offset.x = FROM_FIXED12(pos->x - gViewFrustum.mCameraPos.x);
    offset.z = FROM_FIXED12(pos->z - gViewFrustum.mCameraPos.z);
    horizontalDistanceSquared = offset.x * offset.x + offset.z * offset.z;
    result = horizontalDistanceSquared & MAP_OBJECT_VIEW_DISTANCE_MASK;
    if (horizontalDistanceSquared > farDistanceSquared) {
        result |= gViewTestDistanceLimitFlag;
    }
    if (horizontalDistanceSquared > maxDistance * maxDistance) {
        if (alpha <= 1) {
            return result | MAP_OBJECT_VIEW_OUT_OF_SIGHT;
        }
        result |= gViewTestMaxDistanceFlag;
    }
    offset.y = FROM_FIXED12(pos->y - gViewFrustum.mCameraPos.y);
    offsetX = ((const Vec3 *) &offset)->x;
    if (offset.y * GetFrustumLeftPlaneNormalY(&gViewFrustum) + offset.x * gViewFrustum.mLeftPlaneNormal.x +
            offset.z * gViewFrustum.mLeftPlaneNormal.z >
        radius) {
        return result | MAP_OBJECT_VIEW_OUTSIDE_PLANES;
    }
    if (offsetX * gViewFrustum.mRightPlaneNormal.x + offset.y * gViewFrustum.mRightPlaneNormal.y +
            offset.z * gViewFrustum.mRightPlaneNormal.z >
        radius) {
        result |= MAP_OBJECT_VIEW_OUTSIDE_PLANES;
    }
    return result;
}

void AdvanceKartAiHeading(struct KartAi *kartAi, Vec3 *toTarget, Vec3 *kartForward) {
    Kart *kart = kartAi->mKart;
    Vec3 linkPos;
    Vec3 linkDir;
    Vec3 contactLinkPos;
    Vec3 contactLinkDir;
    Vec3 kartUp;
    Vec3 turnCross;
    Vec3 flatTarget;
    Vec3 flatLinkDir;
    Vec3 contactUp;
    Vec3 contactCross;
    Vec3 flatContactLinkDir;
    Vec3 offsetFromLink;
    s32 dot;
    s32 speedFactor;
    s32 unused;
    s32 turnSign;
    BOOL steered;
    Vec3 *kartUpRow;
    Kart *aiKart;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    steered = FALSE;
    CallKartAiLinkPosAndDirection(&linkPos, &linkDir, kartAi);
    if (kartAi->mContactStage == KART_AI_CONTACT_STEER_FLAT) {
        kartUpRow = &kart->mRotationRow1;
        dot = VEC_DotProduct(kartUpRow, &linkDir);
        flatLinkDir.x = linkDir.x - MUL_FIXED12_NO_ROUND(kartUpRow->x, dot);
        flatLinkDir.y = linkDir.y - MUL_FIXED12_NO_ROUND(kartUpRow->y, dot);
        flatLinkDir.z = linkDir.z - MUL_FIXED12_NO_ROUND(kartUpRow->z, dot);
        if (Vec3DotUnrounded(&kart->mRotationRow2, &flatLinkDir) > -0x333) {
            CallKartAiLinkPosAndDirection(&contactLinkPos, &contactLinkDir, kartAi);
            aiKart = kartAi->mKart;
            steered = TRUE;
            VEC_Subtract(&aiKart->mPos, &contactLinkPos, &offsetFromLink);
            offsetFromLink.y = 0;
            GetKartUp(aiKart, &contactUp);
            dot = VEC_DotProduct(&contactUp, &contactLinkDir);
            flatContactLinkDir.x = contactLinkDir.x - MUL_FIXED12_NO_ROUND(contactUp.x, dot);
            flatContactLinkDir.y = contactLinkDir.y - MUL_FIXED12_NO_ROUND(contactUp.y, dot);
            flatContactLinkDir.z = contactLinkDir.z - MUL_FIXED12_NO_ROUND(contactUp.z, dot);
            Vec3CrossUnrounded(&offsetFromLink, &flatContactLinkDir, &contactCross);
            turnSign = Vec3DotUnrounded(&contactUp, &contactCross) > 0 ? 1 : -1;
            kart->mHeadingAngle += turnSign * 200;
            goto end;
        }
    }
    if (kartAi->mTurnAngleDegrees > KART_AI_STEER_MIN_TURN_ANGLE) {
        speedFactor = MUL_FIXED12_NO_ROUND(kart->mVelocityLength, *gKartAiVelocityFactorScale);
        if (speedFactor > 0x1000) {
            speedFactor = 0x1000;
        }
        GetKartUp(kart, &kartUp);
        dot = VEC_DotProduct(&kartUp, toTarget);
        flatTarget.x = toTarget->x - MUL_FIXED12_NO_ROUND(kartUp.x, dot);
        flatTarget.y = toTarget->y - MUL_FIXED12_NO_ROUND(kartUp.y, dot);
        flatTarget.z = toTarget->z - MUL_FIXED12_NO_ROUND(kartUp.z, dot);
        Vec3CrossUnrounded(kartForward, &flatTarget, &turnCross);
        kart->mHeadingAngle +=
            (turnSign = Vec3DotUnrounded(&kartUp, &turnCross) > 0 ? 1 : -1) *
            (MUL_FIXED12_NO_ROUND((s32) (((s64) kartAi->mTurnAngleDegrees * 0xB60B60B60BLL + 0x80000000LL) >> 32),
                                  MUL_FIXED12_NO_ROUND(speedFactor, 0xa4)) >>
             12);
        steered = TRUE;
    }
    if ((kart->mEffectFlags & KART_EFFECT_GESSO) && kartAi->mTurnAngleDegrees < KART_AI_GESSO_SWING_MAX_TURN_ANGLE &&
        (kart->mMotionFlags & KART_MOTION_ON_GROUND) &&
        !(kart->mDriveFlags & (KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST)) &&
        kart->mVelocityLength > KART_AI_GESSO_SWING_MIN_SPEED && kartAi->mDriftState != KART_AI_DRIFT_HOLDING &&
        kartAi->mContactStage == KART_AI_CONTACT_NONE) {
        kartAi->mHeadingSwingPhase += 0x44c;
        kartAi->mHeadingSwingOffset = MUL_FIXED12_ROUNDED(FX_SinIdx(kartAi->mHeadingSwingPhase), 0xfa);
        kart->mHeadingAngle += (s16) kartAi->mHeadingSwingOffset * kartAi->mHeadingSwingSign;
        steered = TRUE;
    } else {
        kartAi->mHeadingSwingOffset = 0;
        kartAi->mHeadingSwingPhase = 0;
    }
end:
    if (steered == FALSE) {
        return;
    }
    if (turnSign > 0) {
        kart->mDriveFlags |= KART_DRIVE_TURN_LEFT;
    } else {
        kart->mDriveFlags |= KART_DRIVE_TURN_RIGHT;
    }
}

void QuaternionFromAxisAngle(const Vec3 *axis, u16 angle, Vec4 *result) {
    s32 halfAngle = (s32) ((u32) (angle << 15) >> 16);
    s32 sinHalf = SIN_OF_ANGLE(halfAngle);
    result->x = MUL_FIXED12_ROUNDED(axis->x, sinHalf);
    result->y = MUL_FIXED12_ROUNDED(axis->y, sinHalf);
    result->z = MUL_FIXED12_ROUNDED(axis->z, sinHalf);
    result->wComponent = COS_OF_ANGLE(halfAngle);
}

s32 TryQuaternionFromVectors(Vec4 *result, const Vec3 *source, const Vec3 *target) {
    Vec3 cross;
    s32 sqrtValue;
    BOOL success = TRUE;
    VEC_CrossProduct(source, target, &cross);
    sqrtValue = FX_Sqrt((VEC_DotProduct(source, target) + 0x1000) << 1);
    *result = gQuaternionIdentity;
    if (sqrtValue <= 0) {
        success = FALSE;
    } else {
        result->x = FX_Div(cross.x, sqrtValue);
        result->y = FX_Div(cross.y, sqrtValue);
        result->z = FX_Div(cross.z, sqrtValue);
        result->wComponent = sqrtValue >> 1;
    }
    return success;
}

void QuaternionNormalize(const Vec4 *input, Vec4 *output) {
    s64 lengthSquared;
    s32 sqrtResult;
    s64 divResult;
    s64 scale;
    lengthSquared = (s64) input->x * input->x;
    lengthSquared += (s64) input->y * input->y;
    lengthSquared += (s64) input->z * input->z;
    lengthSquared += (s64) input->wComponent * input->wComponent;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
    sqrtResult = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
    }
    divResult = reg_CP_DIV_RESULT;
    scale = divResult * sqrtResult;
    output->x = (scale * input->x + 0x100000000000LL) >> 45;
    output->y = (scale * input->y + 0x100000000000LL) >> 45;
    output->z = (scale * input->z + 0x100000000000LL) >> 45;
    output->wComponent = (scale * input->wComponent + 0x100000000000LL) >> 45;
}
