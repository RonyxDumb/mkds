#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d275c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d8654.h"

// Calls StartEffectWithCallback twice at the rock; skipped when bit 0 of mDistanceSquaredAndFlags is set, or when b is
// 0 and bit 1 is set. Then resets the rock.
void ResetRockWithEffects(RockObject *rock, s32 wasHit) {
    EmitterParams firstEmitterParams;
    EmitterParams secondEmitterParams;
    s32 scaleY;
    u32 distanceAndFlags;
    s32 scaledRow;
    s32 baseRow;
    s32 firstTerm0;
    s16 secondTerm6;
    s16 secondTerm8;
    s32 secondTerm0;
    s32 firstTerm8;
    s16 secondTerm4;
    s16 firstTerm6;
    s32 firstTerm4;

    distanceAndFlags = rock->mMapObject.mDistanceSquaredAndFlags;
    scaleY = rock->mMapObject.mScale.y;
    if (!(distanceAndFlags & 1)) {
        if (wasHit != 0 || !(distanceAndFlags & 3)) {
            if (scaleY > 0x1000) {
                scaledRow = 1;
                baseRow = 0;
            } else {
                scaledRow = 3;
                baseRow = 2;
            }
            firstTerm0 = data_02156960[scaledRow];
            secondTerm8 = data_02156938[scaledRow];
            secondTerm6 = data_02156930[scaledRow];
            secondTerm4 = data_02156928[scaledRow];
            firstTerm6 = data_02156948[scaledRow];
            firstEmitterParams.mUnk_00 = data_02156960[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm0, scaleY);
            firstTerm4 = data_02156940[scaledRow];
            firstEmitterParams.mUnk_04 = data_02156940[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm4, scaleY);
            secondTerm0 = data_02156950[scaledRow];
            firstEmitterParams.mUnk_06 = data_02156948[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm6, scaleY);
            secondEmitterParams.mUnk_00 = data_02156950[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm0, scaleY);
            firstTerm8 = data_02156920[scaledRow];
            firstEmitterParams.mUnk_08 = data_02156920[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm8, scaleY);
            secondEmitterParams.mUnk_04 = data_02156928[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm4, scaleY);
            secondEmitterParams.mUnk_06 = data_02156930[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm6, scaleY);
            secondEmitterParams.mUnk_08 = data_02156938[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm8, scaleY);
            if (rock->mMapObject.mKind == 0x192) {
                StartEffectWithCallback(0x54, &rock->mMapObject.mPos, &firstEmitterParams, CopyEmitterParams);
                StartEffectWithCallback(0x57, &rock->mMapObject.mPos, &secondEmitterParams, CopyEmitterParams);
            } else {
                StartEffectWithCallback(0x56, &rock->mMapObject.mPos, &firstEmitterParams, CopyEmitterParams);
                StartEffectWithCallback(0x55, &rock->mMapObject.mPos, &secondEmitterParams, CopyEmitterParams);
            }
        }
    }
    ResetRock(rock);
}

void UpdateRock(void *mapObjectList, RockObject *rock) {
    s32 oldBaseX;
    s32 oldBaseZ;
    s32 depthBelowBase;
    s32 verticalSpeed;
    s32 sideIndex;
    s64 newScale;
    s32 newBottomOffset;
    Vec3 *scale;

    if (rock->mUnk_0e0 > 0) {
        rock->mUnk_0e0 -= 1;
        if (rock->mUnk_0e0 != 0) {
            return;
        }
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = 1;
        return;
    }
    oldBaseX = rock->mBasePos.x;
    oldBaseZ = rock->mBasePos.z;
    AdvanceGroupFollowerWithSpeeds(&rock->mUnk_0a4);
    GetGroupFollowerCurveXzLinearY(&rock->mUnk_0a4.mGroupFollower, &rock->mBasePos);
    rock->mMapObject.mPosStep.x = rock->mBasePos.x - oldBaseX;
    rock->mMapObject.mPosStep.z = rock->mBasePos.z - oldBaseZ;
    rock->mOffsetX += rock->mOffsetVelocityX;
    rock->mOffsetZ += rock->mOffsetVelocityZ;
    rock->mMapObject.mPosStep.x += rock->mOffsetVelocityX;
    rock->mMapObject.mPosStep.z += rock->mOffsetVelocityZ;
    rock->mMapObject.mPos.x = rock->mBasePos.x + rock->mOffsetX;
    rock->mMapObject.mPos.z = rock->mBasePos.z + rock->mOffsetZ;
    rock->mOffsetX = (rock->mOffsetX * 0x3f) >> 6;
    rock->mOffsetZ = (rock->mOffsetZ * 0x3f) >> 6;
    depthBelowBase = rock->mBasePos.y - (rock->mMapObject.mPos.y - rock->mBottomOffset);
    if (depthBelowBase > 0) {
        rock->mMapObject.mPos.y = rock->mMapObject.mPos.y + depthBelowBase;
        verticalSpeed = rock->mMapObject.mPosStep.y;
        if (verticalSpeed < 0) {
            if (verticalSpeed >= -0x2000) {
                rock->mMapObject.mPosStep.y = 0;
            } else {
                rock->mMapObject.mPosStep.y = -MUL_FIXED12_NO_ROUND(verticalSpeed, rock->mBounceRatio);
                rock->mBounceSide = (rock->mBounceSide == FALSE);
                if (rock->mMapObject.mPosStep.y > 0x4000) {
                    sideIndex = (u16) rock->mUnk_0a4.mGroupFollower.mSegmentIndex;
                    rock->mMapObject.mPosStep.y = 0x4000;
                    if (rock->mBounceSide != FALSE) {
                        rock->mOffsetVelocityX = rock->mSideVectors[sideIndex].x << 1;
                        rock->mOffsetVelocityZ = rock->mSideVectors[sideIndex].z >> 1;
                    } else {
                        rock->mOffsetVelocityX = -rock->mSideVectors[sideIndex].x >> 1;
                        rock->mOffsetVelocityZ = -rock->mSideVectors[sideIndex].z >> 1;
                    }
                } else {
                    rock->mOffsetVelocityX = 0;
                    rock->mOffsetVelocityZ = 0;
                }
            }
        }
        rock->mSinceGroundFrames = 0;
    } else {
        rock->mSinceGroundFrames += 1;
    }
    if (rock->mSinceGroundFrames < 10) {
        StartMapObjectSoundWhileRequested(&rock->mMapObject, 0x179);
    }
    rock->mMapObject.mPosStep.y = rock->mMapObject.mPosStep.y - 0x400;
    rock->mMapObject.mPos.y = rock->mMapObject.mPos.y + rock->mMapObject.mPosStep.y;
    if (rock->mScalePerFrame != 0 && rock->mMapObject.mScale.y < rock->mScaleLimit) {
        newScale = rock->mMapObject.mScale.y + rock->mScalePerFrame;
        newBottomOffset = (newScale * 0x1e000) >> 12;
        FX_DivAsync(0x1000, newBottomOffset);
        scale = &rock->mMapObject.mScale;
        scale->x = newScale;
        scale->y = newScale;
        scale->z = newScale;
        rock->mBottomOffset = newBottomOffset;
        rock->mMapObject.mExtent.x = (newScale * 0x1b000) >> 12;
        if (rock->mMapObject.mCollisionSlotIndex >= 0) {
            SetCollisionSlotRadius(rock->mMapObject.mCollisionSlotIndex, rock->mMapObject.mExtent.x);
        }
        rock->mMapObject.mViewRadius = MUL_FIXED12_NO_ROUND(rock->mMapObject.mKindData->mUnk_2c, newScale);
        rock->mBottomOffsetReciprocal = FX_GetDivResult();
    }
    if (rock->mUnk_0a4.mGroupFollower.mForward == 0) {
        ResetRockWithEffects(rock, 0);
    } else if (rock->mMapObject.mPos.y < 0) {
        ResetRockWithEffects(rock, 0);
    }
}

// Calls ResetRockWithEffects with b = 1 when the byte at c is 1; returns the byte at d.
u8 CollideKartWithRock(RockObject *rock, s32 unused, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        ResetRockWithEffects(rock, 1);
    }
    return *secondResponsePtr;
}

// Same body as CollideKartWithRock.
u8 CollideItemObjectWithRock(RockObject *rock, s32 unused, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        ResetRockWithEffects(rock, 1);
    }
    return *secondResponsePtr;
}

// Puts the rock back at its start: timer, position, speed and scale.
void ResetRock(RockObject *rock) {
    s64 startScale;
    s32 bottomOffset;
    s32 zero;
    Vec3 *scale;

    SetupGroupFollowerWithSpeeds(&rock->mUnk_0a4, 0, 1);
    GetGroupFollowerCurvePosStepXz(&rock->mUnk_0a4.mGroupFollower, &rock->mMapObject.mPos, &rock->mMapObject.mPosStep);
    rock->mUnk_0e0 = rock->mUnk_0dc;
    if (rock->mUnk_0e0 != 0) {
        rock->mMapObject.mFlags |= data_0215691c;
        rock->mMapObject.mFlags |= data_02156914;
    }
    rock->mBasePos = rock->mMapObject.mPos;
    rock->mBounceSide = TRUE;
    zero = 0;
    rock->mOffsetVelocityX = zero;
    rock->mOffsetVelocityZ = zero;
    rock->mOffsetX = zero;
    rock->mOffsetZ = zero;
    rock->mMapObject.mPos.y = rock->mStartY;
    rock->mMapObject.mPosStep.y = 0x8000;
    rock->mMapObject.mMatrix.mRows[0] = data_021569d8;
    rock->mMapObject.mMatrix.mRows[1] = data_021569e4;
    rock->mMapObject.mMatrix.mRows[2] = data_021569f0;
    startScale = rock->mStartScale;
    bottomOffset = (startScale * 0x1e000) >> 12;
    FX_DivAsync(0x1000, bottomOffset);
    scale = &rock->mMapObject.mScale;
    scale->x = startScale;
    scale->y = startScale;
    scale->z = startScale;
    rock->mBottomOffset = bottomOffset;
    rock->mMapObject.mExtent.x = (startScale * 0x1b000) >> 12;
    if (rock->mMapObject.mCollisionSlotIndex >= 0) {
        SetCollisionSlotRadius(rock->mMapObject.mCollisionSlotIndex, rock->mMapObject.mExtent.x);
    }
    rock->mMapObject.mViewRadius = MUL_FIXED12_NO_ROUND(rock->mMapObject.mKindData->mUnk_2c, startScale);
    rock->mBottomOffsetReciprocal = FX_GetDivResult();
}

#pragma thumb on
void CreateNsbmdAndShadowNsbmd(void *mapObjectList, const char *name, const char *shadowName) {
    CreateNsbmd(&gRock, FindCourseMapObjFile(name), NULL);
    CreateShadowModel(&gRockShadow, FindCourseMapObjFile(shadowName), 7);
    SetNsbmdPolygonIdLightEmiAll(gRock, 0x3f, 2, 0x294a);
    SetNsbmdPolygonIdAll(gRock, 7);
}
#pragma thumb off

#pragma thumb on
void CreateRock(void *mapObjectList) {
    CreateNsbmdAndShadowNsbmd(mapObjectList, "rock.nsbmd", "rock_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
void CreateRock2(void *mapObjectList) {
    CreateNsbmdAndShadowNsbmd(mapObjectList, "rock2.nsbmd", "rock2_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
// Fills a Rock from its course map row; both Rock kinds use it.
void InitRock(RockObject *rock, struct CourseMapRow *courseRow) {
    CourseMapGroupEntry *startEntry;
    s32 rowValue;
    float scaledValue;

    InitGroupFollowerWithSpeeds(&rock->mUnk_0a4, courseRow, 0x3000, courseRow->mSettings[1]);
    rock->mUnk_0dc = courseRow->mSettings[0];
    rock->mSideVectors = CreateCourseMapGroupSideVectors(courseRow);
    startEntry = GetCourseMapGroupEntry(courseRow->mGroupIndex, 0);
    rock->mStartY = startEntry->mPos.y;
    rock->mStartScale = rock->mMapObject.mScale.y;
    rowValue = courseRow->mSettings[3];
    if (rowValue > 0) {
        scaledValue = 0.5f + TO_FIXED12(rowValue);
    } else {
        scaledValue = TO_FIXED12(rowValue) - 0.5f;
    }
    rock->mScalePerFrame = (s32) scaledValue / 60000;
    rowValue = courseRow->mSettings[4];
    if (rowValue > 0) {
        scaledValue = 0.5f + TO_FIXED12(rowValue);
    } else {
        scaledValue = TO_FIXED12(rowValue) - 0.5f;
    }
    rock->mScaleLimit = (s32) scaledValue / 1000 + 0x1000;
    ResetRock(rock);
    rock->mSinceGroundFrames = 0;
    rock->mUnk_0e0 = courseRow->mSettings[5];
    if (rock->mUnk_0e0 != 0) {
        rock->mMapObject.mFlags |= data_0215691c;
        rock->mMapObject.mFlags |= data_02156914;
    } else {
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = 0x1f;
    }
    rock->mBounceRatio = TO_FIXED12(courseRow->mSettings[2]) / 100;
    if (rock->mMapObject.mKind == 0x192) {
        CreateMapObjectSoundSourceFalloff4(&rock->mMapObject);
    } else {
        CreateMapObjectSoundSourceFalloff3(&rock->mMapObject);
    }
    rock->mMapObject.mFlags |= data_02156918;
}
#pragma thumb off

#pragma thumb on
// Turns the stored offsets of the loaded collision file into pointers.
void LoadCourseCollisionData(CourseCollision *collision, CourseCollision *file) {
    *collision = *file;
    collision->mPoints = OFFSET_PTR(Vec3, file, (u32) collision->mPoints);
    collision->mNormals = OFFSET_PTR(Vec3s16, file, (u32) collision->mNormals);
    collision->mTriangles = OFFSET_PTR(CourseTriangle, file, (u32) collision->mTriangles);
    collision->mTree = OFFSET_PTR(u8, file, (u32) collision->mTree);
    data_0217b610 = 0;
}
#pragma thumb off

#pragma thumb on
void InitCourseCollision(void) {
    LoadCourseCollisionData(&gCourseCollision, FindCourseFile("course_collision.kcl"));
}
#pragma thumb off

// Keeps the link c on the first object of the hit list a: clears it when b has the top bit or the object changed, sets
// it when b has a bit of 0x1e34ef.
void UpdateCollisionHitLink(void *hitListPtr, u32 collisionBits, CollisionHitLink *link, Vec3 *position, Vec3 *normal) {
    Unk020d5a68 **hitList = hitListPtr;
    Unk020d5a68 *firstHit;

    if (link->mObject != NULL) {
        if (collisionBits & 0x80000000) {
            link->mObject = NULL;
            return;
        }
        GetCollisionHitLinkPosition(link, position);
        firstHit = *hitList;
        if (firstHit->mUnk_04 == 0 && link->mObject == firstHit->mUnk_00) {
            return;
        }
        link->mObject = NULL;
        return;
    }
    if (collisionBits & 0x80000000) {
        return;
    }
    firstHit = *hitList;
    if (firstHit->mUnk_00 == NULL) {
        return;
    }
    if (firstHit->mUnk_04 != 0) {
        return;
    }
    if (!(collisionBits & 0x1e34ef)) {
        return;
    }
    SetCollisionHitLink(firstHit->mUnk_00, position, normal, link);
}

// TRUE when b has the top bit, the hit list a has a non-zero word at 4, or its object differs from the link c.
BOOL IsCollisionHitLinkOutdated(void *hitListPtr, u32 collisionBits, CollisionHitLink *link) {
    Unk020d5a68 **hitList = hitListPtr;

    if ((collisionBits & 0x80000000) || (*hitList)->mUnk_04 != 0 || link->mObject != (*hitList)->mUnk_00) {
        return TRUE;
    }
    return FALSE;
}

// Returns the value of the recorded hit with the highest bits inside the mask a.
u16 PickCollisionHitValue(u32 mask) {
    s32 hitIndex;
    s32 bestIndex;
    u32 maskedBits;
    u32 bestBits;
    s32 hitCount;

    bestIndex = -1;
    hitIndex = 0;
    hitCount = gCollisionHitCount;
    if (hitCount > 0) {
        do {
            maskedBits = mask & gCollisionHitBits[hitIndex];
            if (maskedBits != 0) {
                if (bestIndex < 0 || maskedBits > bestBits) {
                    bestIndex = hitIndex;
                    bestBits = maskedBits;
                }
            }
            hitIndex++;
        } while (hitIndex < hitCount);
    }
    return gCollisionHitValues[bestIndex];
}

void InitCollisionSlots(void) {
    void *heap;
    s16 nextFreeIndex;
    s16 slotIndex;

    heap = GetHeap(GetCurrentHeapCall());
    gCollisionSlotCount = 0;
    gFirstFreeCollisionSlot = 0;
    gCollisionSlotHighEnds = HeapAlloc(heap, 0x400);
    gCollisionSlotLowEnds = HeapAlloc(heap, 0x400);
    gCollisionSlots = HeapAlloc(heap, 0x1c00);
    gCollisionSlotNextFree = HeapAlloc(heap, 0x200);
    gFoundCollisionSlotIndices = HeapAlloc(heap, 0x100);
    gFoundCollisionSlotFlags = HeapAlloc(heap, 0x100);
    gFoundCollisionSlotObjects = HeapAlloc(heap, 0x200);
    nextFreeIndex = 0;
    do {
        gCollisionSlotNextFree[nextFreeIndex] = nextFreeIndex + 1;
        nextFreeIndex++;
    } while (nextFreeIndex < 0x100);
    slotIndex = 0;
    do {
        gCollisionSlots[slotIndex].mCenterPos = NULL;
        slotIndex++;
    } while (slotIndex < 0x100);
}

// Returns the new slot index, or -1 when all 0x100 slots are in use.
s32 CreateCollisionSlot(Vec3 *centerPos, s32 radius, s32 flags, void *object) {
    CollisionSlot *slot;
    s16 hi;
    s16 lo;
    s32 slotIndex;
    s32 highPosition;
    s32 lowPosition;
    s32 searchStep;
    s32 highProbe;
    s32 index;
    s32 endIndex;
    CollisionSlotEnd *endEntry;
    CollisionSlotEnd *otherEnd;

    if (gCollisionSlotCount >= 0x100) {
        return -1;
    }
    slotIndex = gFirstFreeCollisionSlot;
    gFirstFreeCollisionSlot = gCollisionSlotNextFree[slotIndex];
    slot = &gCollisionSlots[slotIndex];
    slot->mHighZ = centerPos->z + radius;
    slot->mLowZ = centerPos->z - radius;
    slot->mCenterPos = centerPos;
    slot->mRadius = radius;
    slot->mFlags = flags;
    slot->mObject = object;
    hi = (centerPos->x + radius) >> 11;
    lo = (centerPos->x - radius) >> 11;
    if (gCollisionSlotCount == 0) {
        gCollisionSlotHighEnds[0].mOtherEndIndex = 0;
        gCollisionSlotHighEnds[0].mUnk_01 = 0;
        gCollisionSlotHighEnds[0].mEndX = hi;
        gCollisionSlotLowEnds[0].mOtherEndIndex = 0;
        gCollisionSlotLowEnds[0].mUnk_01 = slotIndex;
        gCollisionSlotLowEnds[0].mEndX = lo;
        gCollisionSlots[0].mHighEndIndex = 0;
        gCollisionSlots[0].mLowEndIndex = 0;
        gCollisionSlotCount = 1;
        return slotIndex;
    }
    highPosition = 0;
    lowPosition = 0;
    searchStep = gCollisionSlotCount;
    endIndex = gCollisionSlotCount;
    for (;;) {
        highProbe = highPosition + searchStep;
        index = lowPosition + searchStep;
        if (highProbe <= endIndex) {
            if (hi > gCollisionSlotHighEnds[highProbe - 1].mEndX) {
                highPosition = highProbe;
            }
        }
        if (index <= endIndex) {
            if (lo > gCollisionSlotLowEnds[index - 1].mEndX) {
                lowPosition = index;
            }
        }
        if (searchStep == 1) {
            break;
        }
        searchStep = (searchStep + 1) >> 1;
    }
    slot->mHighEndIndex = highPosition;
    slot->mLowEndIndex = lowPosition;
    endIndex = gCollisionSlotCount;
    if (endIndex > highPosition) {
        do {
            endEntry = &gCollisionSlotHighEnds[endIndex];
            *endEntry = gCollisionSlotHighEnds[endIndex - 1];
            otherEnd = &gCollisionSlotLowEnds[endEntry->mOtherEndIndex];
            otherEnd->mOtherEndIndex += 1;
            gCollisionSlots[otherEnd->mUnk_01].mHighEndIndex += 1;
            endIndex--;
            if (endEntry->mUnk_01 >= lowPosition) {
                endEntry->mUnk_01 += 1;
            }
        } while (endIndex > highPosition);
    }
    gCollisionSlotHighEnds[highPosition].mOtherEndIndex = lowPosition;
    gCollisionSlotHighEnds[highPosition].mEndX = hi;
    if (highPosition == gCollisionSlotCount || gCollisionSlotHighEnds[highPosition + 1].mUnk_01 > lowPosition) {
        gCollisionSlotHighEnds[highPosition].mUnk_01 = lowPosition;
        for (index = highPosition - 1; index >= 0 && gCollisionSlotHighEnds[index].mUnk_01 > lowPosition; index--) {
            gCollisionSlotHighEnds[index].mUnk_01 = lowPosition;
        }
    } else {
        gCollisionSlotHighEnds[highPosition].mUnk_01 = gCollisionSlotHighEnds[highPosition + 1].mUnk_01;
    }
    endIndex = gCollisionSlotCount;
    if (endIndex > lowPosition) {
        do {
            endEntry = &gCollisionSlotLowEnds[endIndex];
            *endEntry = gCollisionSlotLowEnds[endIndex - 1];
            gCollisionSlotHighEnds[endEntry->mOtherEndIndex].mOtherEndIndex += 1;
            gCollisionSlots[endEntry->mUnk_01].mLowEndIndex += 1;
            endIndex--;
        } while (endIndex > lowPosition);
    }
    gCollisionSlotLowEnds[lowPosition].mOtherEndIndex = highPosition;
    gCollisionSlotLowEnds[lowPosition].mUnk_01 = slotIndex;
    gCollisionSlotLowEnds[lowPosition].mEndX = lo;
    gCollisionSlotCount += 1;
    return slotIndex;
}

// Always returns -1, which the caller stores as its slot index.
u32 FreeCollisionSlot(s32 slotIndex) {
    CollisionSlot *slot;
    s32 highIndex;
    s32 lowIndex;
    s32 endIndex;
    s32 index;
    s32 otherIndex;
    CollisionSlotEnd *endEntry;
    CollisionSlotEnd *otherEnd;

    if (slotIndex < 0 || slotIndex >= 0x100) {
        return -1;
    }
    slot = &gCollisionSlots[slotIndex];
    highIndex = slot->mHighEndIndex;
    lowIndex = slot->mLowEndIndex;
    if (slot->mCenterPos == NULL) {
        return -1;
    }
    endIndex = highIndex;
    if (endIndex < gCollisionSlotCount - 1) {
        do {
            endEntry = &gCollisionSlotHighEnds[endIndex];
            *endEntry = gCollisionSlotHighEnds[endIndex + 1];
            otherEnd = &gCollisionSlotLowEnds[endEntry->mOtherEndIndex];
            otherEnd->mOtherEndIndex -= 1;
            gCollisionSlots[otherEnd->mUnk_01].mHighEndIndex -= 1;
            if (endEntry->mUnk_01 > lowIndex) {
                endEntry->mUnk_01 -= 1;
            }
            endIndex++;
        } while (endIndex < gCollisionSlotCount - 1);
    }
    endIndex = lowIndex;
    if (endIndex < gCollisionSlotCount - 1) {
        do {
            endEntry = &gCollisionSlotLowEnds[endIndex];
            *endEntry = gCollisionSlotLowEnds[endIndex + 1];
            gCollisionSlotHighEnds[endEntry->mOtherEndIndex].mOtherEndIndex -= 1;
            gCollisionSlots[endEntry->mUnk_01].mLowEndIndex -= 1;
            otherIndex = endEntry->mOtherEndIndex;
            if (otherIndex < highIndex) {
                otherEnd = &gCollisionSlotHighEnds[otherIndex];
                index = otherEnd->mUnk_01;
                if (index == lowIndex) {
                    while (gCollisionSlotLowEnds[index].mOtherEndIndex < (u32) otherIndex) {
                        index++;
                    }
                    otherEnd->mUnk_01 = index;
                }
            }
            endIndex++;
        } while (endIndex < gCollisionSlotCount - 1);
    }
    slot->mCenterPos = NULL;
    gCollisionSlotNextFree[slotIndex] = gFirstFreeCollisionSlot;
    gFirstFreeCollisionSlot = slotIndex;
    gCollisionSlotCount -= 1;
    return -1;
}

// Fills the Found arrays with the slots whose x and z ranges lie within b of position a, whose flags share a bit with
// mask c and that are not disabled.
void FindCollisionSlotsAroundPos(Vec3 *position, s32 radius, s32 flagMask) {
    Vec3 *centerPos = position;
    s32 hi;
    s32 lo;
    s32 searchStep;
    s32 lowProbe;
    s32 value;
    s32 centerZ;
    s32 slotCount;
    s32 zhi;
    s32 highEndIndex;
    s32 zlo;
    s32 highProbe;
    CollisionSlot *slot;
    s32 slotFlags;

    slotCount = gCollisionSlotCount;
    value = centerPos->x;
    centerZ = centerPos->z;
    hi = (s16) ((value + radius) >> 11);
    lo = (s16) ((value - radius) >> 11);
    highEndIndex = 0;
    gFoundCollisionSlotCount = 0;
    value = 0;
    zhi = centerZ + radius;
    zlo = centerZ - radius;
    searchStep = slotCount - 1;
    for (;;) {
        highProbe = highEndIndex + searchStep;
        lowProbe = value + searchStep;
        if (highProbe <= slotCount) {
            if (lo > gCollisionSlotHighEnds[highProbe - 1].mEndX) {
                highEndIndex = highProbe;
            }
        }
        if (lowProbe <= slotCount) {
            if (hi >= gCollisionSlotLowEnds[lowProbe].mEndX) {
                value = lowProbe;
            }
        }
        if (searchStep == 1) {
            break;
        }
        searchStep = (searchStep + 1) >> 1;
    }
    searchStep = gCollisionSlotHighEnds[highEndIndex].mUnk_01;
    if (value < searchStep) {
        return;
    }
    do {
        if (gCollisionSlotLowEnds[value].mOtherEndIndex >= highEndIndex) {
            slot = &gCollisionSlots[gCollisionSlotLowEnds[value].mUnk_01];
            slotFlags = slot->mFlags;
            if (slot->mHighZ >= zlo && slot->mLowZ <= zhi && (slotFlags & flagMask) && !(slotFlags & 0x200)) {
                gFoundCollisionSlotIndices[gFoundCollisionSlotCount] = gCollisionSlotLowEnds[value].mUnk_01;
                gFoundCollisionSlotFlags[gFoundCollisionSlotCount] = slotFlags;
                gFoundCollisionSlotObjects[gFoundCollisionSlotCount] = slot->mObject;
                gFoundCollisionSlotCount++;
                if (gFoundCollisionSlotCount == 0x80) {
                    return;
                }
            } else {
                continue;
            }
        }
        if (value == 0) {
            return;
        }
    } while (--value >= searchStep);
}

// A slot with flag 0x400 also gets the flags of data_02156900 set.
void SetCollisionSlotRadius(s16 slotIndex, s32 radius) {
    CollisionSlot *slot;

    slot = &gCollisionSlots[slotIndex];
    slot->mRadius = radius;
    if (slot->mFlags & 0x400) {
        slot->mFlags |= data_02156900;
    }
}

void DisableCollisionSlot(s16 slotIndex) {
    gCollisionSlots[slotIndex].mFlags |= data_021568fc;
}

void EnableCollisionSlot(s16 slotIndex) {
    gCollisionSlots[slotIndex].mFlags &= ~0x200;
}
