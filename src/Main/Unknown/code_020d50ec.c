#include "Main/Unknown/code_020d50ec.h"
#include "Main/System/Heap.h"
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

// Calls ptcm_createEmitterNoUpdateSkip twice at the rock; skipped when bit 0 of mDistanceSquaredAndFlags is set, or when b is
// 0 and bit 1 is set. Then resets the rock.
void sub_20D634C(RockObject *rock, s32 b) {
    EmitterParams firstEmitterParams;
    EmitterParams secondEmitterParams;
    s32 scaleY;
    u32 distanceAndFlags;
    s32 k;
    s32 j;
    s32 a;
    s16 c;
    s16 d;
    s32 e;
    s32 f;
    s16 g;
    s16 h;
    s32 i;

    distanceAndFlags = rock->mMapObject.mDistanceSquaredAndFlags;
    scaleY = rock->mMapObject.mScale.y;
    if (!(distanceAndFlags & 1)) {
        if (b != 0 || !(distanceAndFlags & 3)) {
            if (scaleY > 0x1000) {
                k = 1;
                j = 0;
            } else {
                k = 3;
                j = 2;
            }
            a = data_02156960[k];
            d = data_02156938[k];
            c = data_02156930[k];
            g = data_02156928[k];
            h = data_02156948[k];
            firstEmitterParams.field0 = data_02156960[j] + (s32) (((s64) a * scaleY) >> 12);
            i = data_02156940[k];
            firstEmitterParams.field4 = data_02156940[j] + (s32) (((s64) i * scaleY) >> 12);
            e = data_02156950[k];
            firstEmitterParams.field6 = data_02156948[j] + (s32) (((s64) h * scaleY) >> 12);
            secondEmitterParams.field0 = data_02156950[j] + (s32) (((s64) e * scaleY) >> 12);
            f = data_02156920[k];
            firstEmitterParams.field8 = data_02156920[j] + (s32) (((s64) f * scaleY) >> 12);
            secondEmitterParams.field4 = data_02156928[j] + (s32) (((s64) g * scaleY) >> 12);
            secondEmitterParams.field6 = data_02156930[j] + (s32) (((s64) c * scaleY) >> 12);
            secondEmitterParams.field8 = data_02156938[j] + (s32) (((s64) d * scaleY) >> 12);
            if (rock->mMapObject.mKind == 0x192) {
                ptcm_createEmitterNoUpdateSkip(0x54, &rock->mMapObject.mPos, &firstEmitterParams, func_020d6538);
                ptcm_createEmitterNoUpdateSkip(0x57, &rock->mMapObject.mPos, &secondEmitterParams, func_020d6538);
            } else {
                ptcm_createEmitterNoUpdateSkip(0x56, &rock->mMapObject.mPos, &firstEmitterParams, func_020d6538);
                ptcm_createEmitterNoUpdateSkip(0x55, &rock->mMapObject.mPos, &secondEmitterParams, func_020d6538);
            }
        }
    }
    ResetRock(rock);
}

void rock_update(void *a, RockObject *rock) {
    s32 oldBaseX;
    s32 oldBaseZ;
    s32 depthBelowBase;
    s32 verticalSpeed;
    s32 sideIndex;
    s64 newScale;
    s32 newBottomOffset;
    Vec3 *scale;

    if (rock->fieldE0 > 0) {
        rock->fieldE0 -= 1;
        if (rock->fieldE0 != 0) {
            return;
        }
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = 1;
        return;
    }
    oldBaseX = rock->mBasePos.x;
    oldBaseZ = rock->mBasePos.z;
    pwex_update(&rock->fieldA4);
    pw_calcCurrentPointXZLinearY(&rock->fieldA4.field0, &rock->mBasePos);
    rock->mMapObject.field10.x = rock->mBasePos.x - oldBaseX;
    rock->mMapObject.field10.z = rock->mBasePos.z - oldBaseZ;
    rock->mOffsetX += rock->mOffsetVelocityX;
    rock->mOffsetZ += rock->mOffsetVelocityZ;
    rock->mMapObject.field10.x += rock->mOffsetVelocityX;
    rock->mMapObject.field10.z += rock->mOffsetVelocityZ;
    rock->mMapObject.mPos.x = rock->mBasePos.x + rock->mOffsetX;
    rock->mMapObject.mPos.z = rock->mBasePos.z + rock->mOffsetZ;
    rock->mOffsetX = (rock->mOffsetX * 0x3f) >> 6;
    rock->mOffsetZ = (rock->mOffsetZ * 0x3f) >> 6;
    depthBelowBase = rock->mBasePos.y - (rock->mMapObject.mPos.y - rock->mBottomOffset);
    if (depthBelowBase > 0) {
        rock->mMapObject.mPos.y = rock->mMapObject.mPos.y + depthBelowBase;
        verticalSpeed = rock->mMapObject.field10.y;
        if (verticalSpeed < 0) {
            if (verticalSpeed >= -0x2000) {
                rock->mMapObject.field10.y = 0;
            } else {
                rock->mMapObject.field10.y = -(s32) (((s64) verticalSpeed * rock->mBounceRatio) >> 12);
                rock->mBounceSide = (rock->mBounceSide == FALSE);
                if (rock->mMapObject.field10.y > 0x4000) {
                    sideIndex = (u16) rock->fieldA4.field0.mSegmentIndex;
                    rock->mMapObject.field10.y = 0x4000;
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
        mobj_emitSfxFromEmitter(&rock->mMapObject, 0x179);
    }
    rock->mMapObject.field10.y = rock->mMapObject.field10.y - 0x400;
    rock->mMapObject.mPos.y = rock->mMapObject.mPos.y + rock->mMapObject.field10.y;
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
            col_setBoundingSphereRadius(rock->mMapObject.mCollisionSlotIndex, rock->mMapObject.mExtent.x);
        }
        rock->mMapObject.mViewRadius = ((s64) rock->mMapObject.mKindData->field2C * newScale) >> 12;
        rock->mBottomOffsetReciprocal = FX_GetDivResult();
    }
    if (rock->fieldA4.field0.mForward == 0) {
        sub_20D634C(rock, 0);
    } else if (rock->mMapObject.mPos.y < 0) {
        sub_20D634C(rock, 0);
    }
}

// Calls sub_20D634C with b = 1 when the byte at c is 1; returns the byte at d.
u8 rock_onDriverCollide(RockObject *rock, s32 b, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        sub_20D634C(rock, 1);
    }
    return *secondResponsePtr;
}

// Same body as rock_onDriverCollide.
u8 rock_onItemCollide(RockObject *rock, s32 b, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (*firstResponsePtr == 1) {
        sub_20D634C(rock, 1);
    }
    return *secondResponsePtr;
}

// Puts the rock back at its start: timer, position, speed and scale.
void ResetRock(RockObject *rock) {
    s64 startScale;
    s32 bottomOffset;
    s32 zero;
    Vec3 *scale;

    pwex_init(&rock->fieldA4, 0, 1);
    pw_20D8B18_XZ(&rock->fieldA4.field0, &rock->mMapObject.mPos, &rock->mMapObject.field10);
    rock->fieldE0 = rock->fieldDC;
    if (rock->fieldE0 != 0) {
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
    rock->mMapObject.field10.y = 0x8000;
    rock->mMapObject.mMatrix.field0[0] = data_021569d8;
    rock->mMapObject.mMatrix.field0[1] = data_021569e4;
    rock->mMapObject.mMatrix.field0[2] = data_021569f0;
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
        col_setBoundingSphereRadius(rock->mMapObject.mCollisionSlotIndex, rock->mMapObject.mExtent.x);
    }
    rock->mMapObject.mViewRadius = ((s64) rock->mMapObject.mKindData->field2C * startScale) >> 12;
    rock->mBottomOffsetReciprocal = FX_GetDivResult();
}

#pragma thumb on
void rock_loadModels(void *a, const char *name, const char *shadowName) {
    model2_createFromNsbmd((void **) &gRock, mobj_getMapObjFile(name), NULL);
    model2_createShadowFromNsbmd((void **) &gRockShadow, mobj_getMapObjFile(shadowName), 7);
    model_setPolyIdLightFlagsEmi(gRock, 0x3f, 2, 0x294a);
    model_setPolygonId(gRock, 7);
}
#pragma thumb off

#pragma thumb on
void rock_loadRockModels(void *a) {
    rock_loadModels(a, "rock.nsbmd", "rock_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
void rock_loadRock2Models(void *a) {
    rock_loadModels(a, "rock2.nsbmd", "rock2_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
// Fills a Rock from its course map row; both Rock kinds use it.
void rock_init(RockObject *rock, struct CourseMapRow *courseRow) {
    CourseMapGroupEntry *startEntry;
    s32 rowValue;
    float scaledValue;

    pwex_initFromObject(&rock->fieldA4, courseRow, 0x3000, courseRow->field2A);
    rock->fieldDC = courseRow->field28;
    rock->mSideVectors = CreateCourseMapGroupSideVectors(courseRow);
    startEntry = mdat_getPathPoint(courseRow->field26, 0);
    rock->mStartY = startEntry->mPos.y;
    rock->mStartScale = rock->mMapObject.mScale.y;
    rowValue = courseRow->field2E;
    if (rowValue > 0) {
        scaledValue = 0.5f + (rowValue << 12);
    } else {
        scaledValue = (rowValue << 12) - 0.5f;
    }
    rock->mScalePerFrame = (s32) scaledValue / 60000;
    rowValue = courseRow->field30;
    if (rowValue > 0) {
        scaledValue = 0.5f + (rowValue << 12);
    } else {
        scaledValue = (rowValue << 12) - 0.5f;
    }
    rock->mScaleLimit = (s32) scaledValue / 1000 + 0x1000;
    ResetRock(rock);
    rock->mSinceGroundFrames = 0;
    rock->fieldE0 = courseRow->field32;
    if (rock->fieldE0 != 0) {
        rock->mMapObject.mFlags |= data_0215691c;
        rock->mMapObject.mFlags |= data_02156914;
    } else {
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = 0x1f;
    }
    rock->mBounceRatio = (courseRow->field2C << 12) / 100;
    if (rock->mMapObject.mKind == 0x192) {
        mobj_initSoundEmitterForObjectSfxParam4(&rock->mMapObject);
    } else {
        mobj_initSoundEmitterForObjectSfxParam3(&rock->mMapObject);
    }
    rock->mMapObject.mFlags |= data_02156918;
}
#pragma thumb off

#pragma thumb on
// Turns the stored offsets of the loaded collision file into pointers.
void col_initFromKcl(CourseCollision *collision, CourseCollision *file) {
    *collision = *file;
    collision->field0 = OFFSET_PTR(Vec3, file, (u32) collision->field0);
    collision->field4 = OFFSET_PTR(Vec3s16, file, (u32) collision->field4);
    collision->field8 = OFFSET_PTR(Unk0217b614_08, file, (u32) collision->field8);
    collision->fieldC = OFFSET_PTR(u8, file, (u32) collision->fieldC);
    gUsesDynamicCollision = 0;
}
#pragma thumb off

#pragma thumb on
void col_loadCourseCollision(void) {
    col_initFromKcl(&gKCollisionData, arc_getCourseArcFile("course_collision.kcl"));
}
#pragma thumb off

// Keeps the link c on the first object of the hit list a: clears it when b has the top bit or the object changed, sets
// it when b has a bit of 0x1e34ef.
void sub_20D5AA0(void *hitListPtr, u32 b, Unk020e04b0 *link, Vec3 *d, Vec3 *e) {
    Unk020d5a68 **hitList = hitListPtr;
    Unk020d5a68 *firstHit;

    if (link->field0 != NULL) {
        if (b & 0x80000000) {
            link->field0 = NULL;
            return;
        }
        sub_20E0538(link, d);
        firstHit = *hitList;
        if (firstHit->field4 == 0 && link->field0 == firstHit->field0) {
            return;
        }
        link->field0 = NULL;
        return;
    }
    if (b & 0x80000000) {
        return;
    }
    firstHit = *hitList;
    if (firstHit->field0 == NULL) {
        return;
    }
    if (firstHit->field4 != 0) {
        return;
    }
    if (!(b & 0x1e34ef)) {
        return;
    }
    sub_20E0584(firstHit->field0, d, e, link);
}

// TRUE when b has the top bit, the hit list a has a non-zero word at 4, or its object differs from the link c.
BOOL sub_20D5A68(void *hitListPtr, u32 b, Unk020e04b0 *link) {
    Unk020d5a68 **hitList = hitListPtr;

    if ((b & 0x80000000) || (*hitList)->field4 != 0 || link->field0 != (*hitList)->field0) {
        return TRUE;
    }
    return FALSE;
}

// Returns the value of the recorded hit with the highest bits inside the mask a.
u16 col_findResponsePrismAttribute(u32 mask) {
    s32 i;
    s32 bestIndex;
    u32 maskedBits;
    u32 bestBits;
    s32 hitCount;

    bestIndex = -1;
    i = 0;
    hitCount = col_sColResponseCount;
    if (hitCount > 0) {
        do {
            maskedBits = mask & col_sColResponseColFlags[i];
            if (maskedBits != 0) {
                if (bestIndex < 0 || maskedBits > bestBits) {
                    bestIndex = i;
                    bestBits = maskedBits;
                }
            }
            i++;
        } while (i < hitCount);
    }
    return col_sColResponsePrismAttributes[bestIndex];
}

void col_init(void) {
    void *heap;
    s16 i;
    s16 j;

    heap = proc_getHeap(proc_getCurrent());
    col_sEntryCount = 0;
    col_sCurAllocIdx = 0;
    col_sSegRightEndpoints = heap_alloc(heap, 0x400);
    col_sSegLeftEndpoints = heap_alloc(heap, 0x400);
    col_sColEntries = heap_alloc(heap, 0x1c00);
    col_sAllocTable = heap_alloc(heap, 0x200);
    gColQueryResultEntryIds = heap_alloc(heap, 0x100);
    gColQueryResultFlags = heap_alloc(heap, 0x100);
    gColQueryResultObjects = heap_alloc(heap, 0x200);
    i = 0;
    do {
        col_sAllocTable[i] = i + 1;
        i++;
    } while (i < 0x100);
    j = 0;
    do {
        col_sColEntries[j].mCenterPos = NULL;
        j++;
    } while (j < 0x100);
}

// Returns the new slot index, or -1 when all 0x100 slots are in use.
s32 col_createColEntry(Vec3 *centerPos, s32 radius, s32 flags, void *object) {
    CollisionSlot *slot;
    s16 hi;
    s16 lo;
    s32 slotIndex;
    s32 highPosition;
    s32 lowPosition;
    s32 searchStep;
    s32 highProbe;
    s32 j;
    s32 m;
    CollisionSlotEnd *endEntry;
    CollisionSlotEnd *otherEnd;

    if (col_sEntryCount >= 0x100) {
        return -1;
    }
    slotIndex = col_sCurAllocIdx;
    col_sCurAllocIdx = col_sAllocTable[slotIndex];
    slot = &col_sColEntries[slotIndex];
    slot->mHighZ = centerPos->z + radius;
    slot->mLowZ = centerPos->z - radius;
    slot->mCenterPos = centerPos;
    slot->mRadius = radius;
    slot->mFlags = flags;
    slot->mObject = object;
    hi = (centerPos->x + radius) >> 11;
    lo = (centerPos->x - radius) >> 11;
    if (col_sEntryCount == 0) {
        col_sSegRightEndpoints[0].mOtherEndIndex = 0;
        col_sSegRightEndpoints[0].field1 = 0;
        col_sSegRightEndpoints[0].mEndX = hi;
        col_sSegLeftEndpoints[0].mOtherEndIndex = 0;
        col_sSegLeftEndpoints[0].field1 = slotIndex;
        col_sSegLeftEndpoints[0].mEndX = lo;
        col_sColEntries[0].mHighEndIndex = 0;
        col_sColEntries[0].mLowEndIndex = 0;
        col_sEntryCount = 1;
        return slotIndex;
    }
    highPosition = 0;
    lowPosition = 0;
    searchStep = col_sEntryCount;
    m = col_sEntryCount;
    for (;;) {
        highProbe = highPosition + searchStep;
        j = lowPosition + searchStep;
        if (highProbe <= m) {
            if (hi > col_sSegRightEndpoints[highProbe - 1].mEndX) {
                highPosition = highProbe;
            }
        }
        if (j <= m) {
            if (lo > col_sSegLeftEndpoints[j - 1].mEndX) {
                lowPosition = j;
            }
        }
        if (searchStep == 1) {
            break;
        }
        searchStep = (searchStep + 1) >> 1;
    }
    slot->mHighEndIndex = highPosition;
    slot->mLowEndIndex = lowPosition;
    m = col_sEntryCount;
    if (m > highPosition) {
        do {
            endEntry = &col_sSegRightEndpoints[m];
            *endEntry = col_sSegRightEndpoints[m - 1];
            otherEnd = &col_sSegLeftEndpoints[endEntry->mOtherEndIndex];
            otherEnd->mOtherEndIndex += 1;
            col_sColEntries[otherEnd->field1].mHighEndIndex += 1;
            m--;
            if (endEntry->field1 >= lowPosition) {
                endEntry->field1 += 1;
            }
        } while (m > highPosition);
    }
    col_sSegRightEndpoints[highPosition].mOtherEndIndex = lowPosition;
    col_sSegRightEndpoints[highPosition].mEndX = hi;
    if (highPosition == col_sEntryCount || col_sSegRightEndpoints[highPosition + 1].field1 > lowPosition) {
        col_sSegRightEndpoints[highPosition].field1 = lowPosition;
        for (j = highPosition - 1; j >= 0 && col_sSegRightEndpoints[j].field1 > lowPosition; j--) {
            col_sSegRightEndpoints[j].field1 = lowPosition;
        }
    } else {
        col_sSegRightEndpoints[highPosition].field1 = col_sSegRightEndpoints[highPosition + 1].field1;
    }
    m = col_sEntryCount;
    if (m > lowPosition) {
        do {
            endEntry = &col_sSegLeftEndpoints[m];
            *endEntry = col_sSegLeftEndpoints[m - 1];
            col_sSegRightEndpoints[endEntry->mOtherEndIndex].mOtherEndIndex += 1;
            col_sColEntries[endEntry->field1].mLowEndIndex += 1;
            m--;
        } while (m > lowPosition);
    }
    col_sSegLeftEndpoints[lowPosition].mOtherEndIndex = highPosition;
    col_sSegLeftEndpoints[lowPosition].field1 = slotIndex;
    col_sSegLeftEndpoints[lowPosition].mEndX = lo;
    col_sEntryCount += 1;
    return slotIndex;
}

// Always returns -1, which the caller stores as its slot index.
u32 col_deleteColEntry(s32 slotIndex) {
    CollisionSlot *slot;
    s32 highIndex;
    s32 lowIndex;
    s32 k;
    s32 j;
    s32 otherIndex;
    CollisionSlotEnd *endEntry;
    CollisionSlotEnd *otherEnd;

    if (slotIndex < 0 || slotIndex >= 0x100) {
        return -1;
    }
    slot = &col_sColEntries[slotIndex];
    highIndex = slot->mHighEndIndex;
    lowIndex = slot->mLowEndIndex;
    if (slot->mCenterPos == NULL) {
        return -1;
    }
    k = highIndex;
    if (k < col_sEntryCount - 1) {
        do {
            endEntry = &col_sSegRightEndpoints[k];
            *endEntry = col_sSegRightEndpoints[k + 1];
            otherEnd = &col_sSegLeftEndpoints[endEntry->mOtherEndIndex];
            otherEnd->mOtherEndIndex -= 1;
            col_sColEntries[otherEnd->field1].mHighEndIndex -= 1;
            if (endEntry->field1 > lowIndex) {
                endEntry->field1 -= 1;
            }
            k++;
        } while (k < col_sEntryCount - 1);
    }
    k = lowIndex;
    if (k < col_sEntryCount - 1) {
        do {
            endEntry = &col_sSegLeftEndpoints[k];
            *endEntry = col_sSegLeftEndpoints[k + 1];
            col_sSegRightEndpoints[endEntry->mOtherEndIndex].mOtherEndIndex -= 1;
            col_sColEntries[endEntry->field1].mLowEndIndex -= 1;
            otherIndex = endEntry->mOtherEndIndex;
            if (otherIndex < highIndex) {
                otherEnd = &col_sSegRightEndpoints[otherIndex];
                j = otherEnd->field1;
                if (j == lowIndex) {
                    while (col_sSegLeftEndpoints[j].mOtherEndIndex < (u32) otherIndex) {
                        j++;
                    }
                    otherEnd->field1 = j;
                }
            }
            k++;
        } while (k < col_sEntryCount - 1);
    }
    slot->mCenterPos = NULL;
    col_sAllocTable[slotIndex] = col_sCurAllocIdx;
    col_sCurAllocIdx = slotIndex;
    col_sEntryCount -= 1;
    return -1;
}

// Fills the Found arrays with the slots whose x and z ranges lie within b of position a, whose flags share a bit with
// mask c and that are not disabled.
void col_queryBySphere(Vec3 *position, s32 radius, s32 flagMask) {
    Vec3 *centerPos = position;
    s32 hi;
    s32 lo;
    s32 searchStep;
    s32 j;
    s32 k;
    s32 centerZ;
    s32 slotCount;
    s32 zhi;
    s32 p;
    s32 zlo;
    s32 t;
    CollisionSlot *slot;
    s32 slotFlags;

    slotCount = col_sEntryCount;
    k = centerPos->x;
    centerZ = centerPos->z;
    hi = (s16) ((k + radius) >> 11);
    lo = (s16) ((k - radius) >> 11);
    p = 0;
    gColQueryResultCount = 0;
    k = 0;
    zhi = centerZ + radius;
    zlo = centerZ - radius;
    searchStep = slotCount - 1;
    for (;;) {
        t = p + searchStep;
        j = k + searchStep;
        if (t <= slotCount) {
            if (lo > col_sSegRightEndpoints[t - 1].mEndX) {
                p = t;
            }
        }
        if (j <= slotCount) {
            if (hi >= col_sSegLeftEndpoints[j].mEndX) {
                k = j;
            }
        }
        if (searchStep == 1) {
            break;
        }
        searchStep = (searchStep + 1) >> 1;
    }
    searchStep = col_sSegRightEndpoints[p].field1;
    if (k < searchStep) {
        return;
    }
    do {
        if (col_sSegLeftEndpoints[k].mOtherEndIndex >= p) {
            slot = &col_sColEntries[col_sSegLeftEndpoints[k].field1];
            slotFlags = slot->mFlags;
            if (slot->mHighZ >= zlo && slot->mLowZ <= zhi && (slotFlags & flagMask) && !(slotFlags & 0x200)) {
                gColQueryResultEntryIds[gColQueryResultCount] = col_sSegLeftEndpoints[k].field1;
                gColQueryResultFlags[gColQueryResultCount] = slotFlags;
                gColQueryResultObjects[gColQueryResultCount] = slot->mObject;
                gColQueryResultCount++;
                if (gColQueryResultCount == 0x80) {
                    return;
                }
            } else {
                continue;
            }
        }
        if (k == 0) {
            return;
        }
    } while (--k >= searchStep);
}

// A slot with flag 0x400 also gets the flags of data_02156900 set.
void col_setBoundingSphereRadius(s16 slotIndex, s32 radius) {
    CollisionSlot *slot;

    slot = &col_sColEntries[slotIndex];
    slot->mRadius = radius;
    if (slot->mFlags & 0x400) {
        slot->mFlags |= data_02156900;
    }
}

void col_disableColEntry(s16 slotIndex) {
    col_sColEntries[slotIndex].mFlags |= data_021568fc;
}

void col_enableColEntry(s16 slotIndex) {
    col_sColEntries[slotIndex].mFlags &= ~0x200;
}
