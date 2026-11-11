#include "ITCM/code_01ffcf7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "registers.h"

void UpdateCollisionSlotBounds(void) {
    s32 slotIndex = 0;
    s32 activeCount = 0;
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
    CollisionSlotEnd *otherEndA;
    CollisionSlotEnd *otherEndB;
    if (gCollisionSlotCount > 0) {
        do {
            slot = &gCollisionSlots[slotIndex];
            center = slot->mCenterPos;
            radius = slot->mRadius;
            if (center != NULL) {
                flags = slot->mFlags;
                if (flags & 0x600) {
                    if (flags & 0x100) {
                        slot->mFlags = flags & ~0x100;
                    } else {
                        activeCount++;
                        goto next;
                    }
                }
                activeCount++;
                slot->mHighZ = center->z + radius;
                slot->mLowZ = center->z - radius;
                gCollisionSlotHighEnds[slot->mHighEndIndex].mEndX = (center->x + radius) >> 11;
                gCollisionSlotLowEnds[slot->mLowEndIndex].mEndX = (center->x - radius) >> 11;
            }
        next:
            slotIndex++;
        } while (activeCount < gCollisionSlotCount);
    }
    for (slotIndex = 1; slotIndex < gCollisionSlotCount; slotIndex++) {
        activeCount = slotIndex;
        while ((currentEnd = &gCollisionSlotHighEnds[activeCount],
                previousEnd = &gCollisionSlotHighEnds[activeCount - 1], previousEnd->mEndX > currentEnd->mEndX) &&
               activeCount >= 1) {
            swapTemp = *(u32 *) currentEnd;
            *(u32 *) currentEnd = *(u32 *) previousEnd;
            *(u32 *) previousEnd = swapTemp;
            lowEnds = gCollisionSlotLowEnds;
            otherEndA = &lowEnds[currentEnd->mOtherEndIndex];
            otherEndB = &lowEnds[previousEnd->mOtherEndIndex];
            otherEndA->mOtherEndIndex++;
            otherEndB->mOtherEndIndex--;
            gCollisionSlots[otherEndA->mUnk_01].mHighEndIndex++;
            gCollisionSlots[otherEndB->mUnk_01].mHighEndIndex--;
            if (currentEnd->mUnk_01 == previousEnd->mOtherEndIndex) {
                scanIndex = currentEnd->mUnk_01;
                do {
                    scanIndex++;
                } while (gCollisionSlotLowEnds[scanIndex].mOtherEndIndex < activeCount);
                currentEnd->mUnk_01 = scanIndex;
            }
            if (previousEnd->mUnk_01 > currentEnd->mOtherEndIndex) {
                previousEnd->mUnk_01 = currentEnd->mOtherEndIndex;
            }
            activeCount--;
        }
    }
    for (slotIndex = 1; slotIndex < gCollisionSlotCount; slotIndex++) {
        activeCount = slotIndex;
        while ((currentEnd = &gCollisionSlotLowEnds[activeCount], previousEnd = &gCollisionSlotLowEnds[activeCount - 1],
                previousEnd->mEndX > currentEnd->mEndX) &&
               activeCount >= 1) {
            swapTemp = *(u32 *) currentEnd;
            *(u32 *) currentEnd = *(u32 *) previousEnd;
            *(u32 *) previousEnd = swapTemp;
            gCollisionSlotHighEnds[currentEnd->mOtherEndIndex].mOtherEndIndex++;
            gCollisionSlotHighEnds[previousEnd->mOtherEndIndex].mOtherEndIndex--;
            gCollisionSlots[currentEnd->mUnk_01].mLowEndIndex++;
            gCollisionSlots[previousEnd->mUnk_01].mLowEndIndex--;
            if (currentEnd->mOtherEndIndex > previousEnd->mOtherEndIndex) {
                for (endIndex = currentEnd->mOtherEndIndex; endIndex > previousEnd->mOtherEndIndex &&
                                                            gCollisionSlotHighEnds[endIndex].mUnk_01 == activeCount - 1;
                     endIndex--) {
                    gCollisionSlotHighEnds[endIndex].mUnk_01++;
                }
            } else {
                endIndex = previousEnd->mOtherEndIndex;
                while (endIndex > currentEnd->mOtherEndIndex &&
                       gCollisionSlotHighEnds[endIndex].mUnk_01 == activeCount) {
                    gCollisionSlotHighEnds[endIndex--].mUnk_01--;
                }
            }
            activeCount--;
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
    s32 lowScanLimit;
    s32 scanIndex;
    s16 minIndex;
    u32 firstIndex;
    CollisionSlot *otherSlot;
    u16 otherFlags;
    if (slotId < 0 || slotId >= 0x100) {
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
    lowScanLimit = lastIndex - 7;
    while (lowScan < lowScanLimit && lowEnds[lowScan + 8].mEndX <= highX) {
        lowScan += 8;
    }
    while (lowScan < lastIndex && lowEnds[lowScan + 1].mEndX <= highX) {
        lowScan++;
    }
    scanIndex = (s16) lowScan;
    firstIndex = highEnds[highScan].mUnk_01;
    minIndex = firstIndex;
    if (scanIndex < minIndex) {
        return;
    }
    for (;;) {
        if (gCollisionSlotLowEnds[scanIndex].mOtherEndIndex >= highScan && scanIndex != lowEndIndex) {
            otherSlot = &gCollisionSlots[gCollisionSlotLowEnds[scanIndex].mUnk_01];
            otherFlags = otherSlot->mFlags;
            if (otherSlot->mHighZ < lowZ || otherSlot->mLowZ > highZ || !(otherFlags & flagMask) ||
                (otherFlags & 0x200)) {
                goto next;
            }
            gFoundCollisionSlotIndices[gFoundCollisionSlotCount] = gCollisionSlotLowEnds[scanIndex].mUnk_01;
            gFoundCollisionSlotFlags[gFoundCollisionSlotCount] = otherFlags;
            gFoundCollisionSlotObjects[gFoundCollisionSlotCount] = otherSlot->mObject;
            gFoundCollisionSlotCount++;
            if (gFoundCollisionSlotCount == 0x80) {
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

s32 ComputeViewTest(Vec3 *pos, s32 radius, s32 maxDistance, s32 nearDistSq, u16 level) {
    s32 result;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    s32 distSq;
    s32 xSquared;
    s32 bottomDot;
    maxDistance = (maxDistance + radius) >> 12;
    offsetZ = (pos->z - gViewFrustum.mCameraPos.z) >> 12;
    offsetX = (pos->x - gViewFrustum.mCameraPos.x) >> 12;
    xSquared = offsetX * offsetX;
    distSq = offsetZ * offsetZ + xSquared;
    result = distSq & ~0xc000001f;
    if (distSq > nearDistSq) {
        result |= data_021568f4;
    }
    if (distSq > maxDistance * maxDistance) {
        if (level <= 1) {
            return result | 3;
        }
        result |= data_usa_021568f8;
    }
    offsetY = (pos->y - gViewFrustum.mCameraPos.y) >> 12;
    if (offsetX * gViewFrustum.mViewDirection.x + offsetY * gViewFrustum.mViewDirection.y +
            offsetZ * gViewFrustum.mViewDirection.z <
        gViewFrustum.mNear - radius) {
        return result | 2;
    }
    if (offsetX * gViewFrustum.mLeftPlaneNormal.x + offsetY * gViewFrustum.mLeftPlaneNormal.y +
            offsetZ * gViewFrustum.mLeftPlaneNormal.z >
        radius) {
        return result | 2;
    }
    if (offsetX * gViewFrustum.mRightPlaneNormal.x + offsetY * gViewFrustum.mRightPlaneNormal.y +
            offsetZ * gViewFrustum.mRightPlaneNormal.z >
        radius) {
        return result | 2;
    }
    if (offsetX * gViewFrustum.mTopPlaneNormal.x + offsetY * gViewFrustum.mTopPlaneNormal.y +
            offsetZ * gViewFrustum.mTopPlaneNormal.z >
        radius) {
        return result | 2;
    }
    bottomDot = offsetX * gViewFrustum.mBottomPlaneNormal.x;
    if (offsetZ * gViewFrustum.mBottomPlaneNormal.z + (offsetY * gViewFrustum.mBottomPlaneNormal.y + bottomDot) >
        radius) {
        result |= 2;
    }
    return result;
}

static inline s32 GetFrustumLeftPlaneNormalY(ViewFrustum *viewFrustum) {
    return viewFrustum->mLeftPlaneNormal.y;
}

s32 ComputeTwoPlaneViewTest(Vec3 *pos, s32 radius, s32 maxDistance, s32 nearDistSq, u16 level) {
    Vec3 offset;
    s32 result;
    s32 distSq;
    s32 offsetX;
    maxDistance = (maxDistance + radius) >> 12;
    VEC_Subtract(pos, &gViewFrustum.mCameraPos, &offset);
    offset.x = (pos->x - gViewFrustum.mCameraPos.x) >> 12;
    offset.z = (pos->z - gViewFrustum.mCameraPos.z) >> 12;
    distSq = offset.x * offset.x + offset.z * offset.z;
    result = distSq & ~0xc000001f;
    if (distSq > nearDistSq) {
        result |= data_021568f4;
    }
    if (distSq > maxDistance * maxDistance) {
        if (level <= 1) {
            return result | 3;
        }
        result |= data_usa_021568f8;
    }
    offset.y = (pos->y - gViewFrustum.mCameraPos.y) >> 12;
    offsetX = ((const Vec3 *) &offset)->x;
    if (offset.y * GetFrustumLeftPlaneNormalY(&gViewFrustum) + offset.x * gViewFrustum.mLeftPlaneNormal.x +
            offset.z * gViewFrustum.mLeftPlaneNormal.z >
        radius) {
        return result | 2;
    }
    if (offsetX * gViewFrustum.mRightPlaneNormal.x + offset.y * gViewFrustum.mRightPlaneNormal.y +
            offset.z * gViewFrustum.mRightPlaneNormal.z >
        radius) {
        result |= 2;
    }
    return result;
}

void AdvanceKartAiHeading(struct KartAi *kartAi, Vec3 *directionA, Vec3 *directionB) {
    Kart *kart = kartAi->mKart;
    Vec3 linkPos;
    Vec3 linkDir;
    Vec3 nextLinkPos;
    Vec3 nextLinkDir;
    Vec3 kartUp;
    Vec3 turnCross;
    Vec3 flatTarget;
    Vec3 flatLinkDir;
    Vec3 contactUp;
    Vec3 contactCross;
    Vec3 flatNextDir;
    Vec3 offsetToLink;
    s32 dot;
    s32 speedFactor;
    s32 unused;
    s32 turnSign;
    BOOL steered;
    Vec3 *surfaceNormal;
    Kart *aiKart;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    if (kart->mUnk_44 & 2) {
        return;
    }
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    steered = FALSE;
    CallKartAiLinkPosAndDirection(&linkPos, &linkDir, kartAi);
    if (kartAi->mContactStage == 1) {
        surfaceNormal = &kart->mUnk_12c;
        dot = VEC_DotProduct(surfaceNormal, &linkDir);
        flatLinkDir.x = linkDir.x - MUL_FIXED12_NO_ROUND(surfaceNormal->x, dot);
        flatLinkDir.y = linkDir.y - MUL_FIXED12_NO_ROUND(surfaceNormal->y, dot);
        flatLinkDir.z = linkDir.z - MUL_FIXED12_NO_ROUND(surfaceNormal->z, dot);
        if (Vec3DotUnrounded(&kart->mUnk_138, &flatLinkDir) > -0x333) {
            CallKartAiLinkPosAndDirection(&nextLinkPos, &nextLinkDir, kartAi);
            aiKart = kartAi->mKart;
            steered = TRUE;
            VEC_Subtract(&aiKart->mPos, &nextLinkPos, &offsetToLink);
            offsetToLink.y = 0;
            GetKartUp(aiKart, &contactUp);
            dot = VEC_DotProduct(&contactUp, &nextLinkDir);
            flatNextDir.x = nextLinkDir.x - MUL_FIXED12_NO_ROUND(contactUp.x, dot);
            flatNextDir.y = nextLinkDir.y - MUL_FIXED12_NO_ROUND(contactUp.y, dot);
            flatNextDir.z = nextLinkDir.z - MUL_FIXED12_NO_ROUND(contactUp.z, dot);
            Vec3CrossUnrounded(&offsetToLink, &flatNextDir, &contactCross);
            turnSign = Vec3DotUnrounded(&contactUp, &contactCross) > 0 ? 1 : -1;
            kart->mHeadingAngle += turnSign * 200;
            goto end;
        }
    }
    if (kartAi->mTurnAngleDegrees > 0x2000) {
        speedFactor = MUL_FIXED12_NO_ROUND(kart->mVelocityLength, *data_usa_0217ae40);
        if (speedFactor > 0x1000) {
            speedFactor = 0x1000;
        }
        GetKartUp(kart, &kartUp);
        dot = VEC_DotProduct(&kartUp, directionA);
        flatTarget.x = directionA->x - MUL_FIXED12_NO_ROUND(kartUp.x, dot);
        flatTarget.y = directionA->y - MUL_FIXED12_NO_ROUND(kartUp.y, dot);
        flatTarget.z = directionA->z - MUL_FIXED12_NO_ROUND(kartUp.z, dot);
        Vec3CrossUnrounded(directionB, &flatTarget, &turnCross);
        kart->mHeadingAngle +=
            (turnSign = Vec3DotUnrounded(&kartUp, &turnCross) > 0 ? 1 : -1) *
            (MUL_FIXED12_NO_ROUND((s32) (((s64) kartAi->mTurnAngleDegrees * 0xB60B60B60BLL + 0x80000000LL) >> 32),
                                  MUL_FIXED12_NO_ROUND(speedFactor, 0xa4)) >>
             12);
        steered = TRUE;
    }
    if ((kart->mUnk_4c & 0x8000000) && kartAi->mTurnAngleDegrees < 0x46000 && (kart->mUnk_44 & KART_44_ON_GROUND) &&
        !(kart->mUnk_48 & 0x8020) && kart->mVelocityLength > 0x3000 && kartAi->mDriftState != 2 &&
        kartAi->mContactStage == 0) {
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
        kart->mUnk_48 |= KART_48_TURN_LEFT;
    } else {
        kart->mUnk_48 |= KART_48_TURN_RIGHT;
    }
}

void QuaternionFromAxisAngle(const Vec3 *axis, s32 angle, Vec4 *result) {
    s32 halfAngle = (s32) ((u32) (angle << 15) >> 16);
    s32 sinHalf = SIN_OF_ANGLE(halfAngle);
    result->x = MUL_FIXED12_ROUNDED(axis->x, sinHalf);
    result->y = MUL_FIXED12_ROUNDED(axis->y, sinHalf);
    result->z = MUL_FIXED12_ROUNDED(axis->z, sinHalf);
    result->w = COS_OF_ANGLE(halfAngle);
}

s32 TryQuaternionFromVectors(Vec4 *result, const Vec3 *source, const Vec3 *target) {
    Vec3 cross;
    s32 sqrtValue;
    BOOL success = TRUE;
    VEC_CrossProduct(source, target, &cross);
    sqrtValue = FX_Sqrt((VEC_DotProduct(source, target) + 0x1000) << 1);
    *result = data_usa_02155194;
    if (sqrtValue <= 0) {
        success = FALSE;
    } else {
        result->x = FX_Div(cross.x, sqrtValue);
        result->y = FX_Div(cross.y, sqrtValue);
        result->z = FX_Div(cross.z, sqrtValue);
        result->w = sqrtValue >> 1;
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
    lengthSquared += (s64) input->w * input->w;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    sqrtResult = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    divResult = reg_CP_DIV_RESULT;
    scale = divResult * sqrtResult;
    output->x = (scale * input->x + 0x100000000000LL) >> 45;
    output->y = (scale * input->y + 0x100000000000LL) >> 45;
    output->z = (scale * input->z + 0x100000000000LL) >> 45;
    output->w = (scale * input->w + 0x100000000000LL) >> 45;
}
