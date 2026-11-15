#include "Main/MapObjects/rock.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/map_object_sound.h"
#include "fixed_vector_math.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/MapObjects/sphere_collision_data.h"
#include "Main/MapObjects/course_collision_data.h"

const s16 gRockFirstEffectRows08[4] = {0, 0x1000, -1024, 0x1400};
const s16 gRockSecondEffectRows04[4] = {0x52, 0x29, -123, 0xf6};
const s16 gRockSecondEffectRows06[4] = {0x1c3, 0xa4, 0x266, 0};
const s32 gRockSecondEffectRows00[4] = {0, 0x99a, 0, 0x99a};
const s16 gRockSecondEffectRows08[4] = {0, 0x1000, -1024, 0x1400};
const s32 gRockFirstEffectRows00[4] = {0x3d7, 0xf5c, 0, 0x1333};
const s16 gRockFirstEffectRows04[4] = {0x66, 0x11f, 0x4a, 0x13f};
const s16 gRockFirstEffectRows06[4] = {0x1ec, 0xa4, 0x23d, 0x52};
const MapObjectKindDescriptor gRock2KindDescriptor = {
    0, {0, 0}, 0x124, InitRock, CreateRockKindData, CreateRock2DrawList, 0, 0, CreateRockUpdateList};
const MapObjectKindDescriptor gRockKindDescriptor = {
    0, {0, 0}, 0x124, InitRock, CreateRockKindData, CreateRockDrawList, 0, 0, CreateRockUpdateList};
s16 gFoundCollisionSlotCount;
s16 gFirstFreeCollisionSlot;
s16 gCollisionSlotCount;
s16 *gCollisionSlotNextFree;
struct CollisionSlotEnd *gCollisionSlotLowEnds;
struct CollisionSlot *gCollisionSlots;
struct CollisionSlotEnd *gCollisionSlotHighEnds;
s16 *gFoundCollisionSlotIndices;
u16 *gFoundCollisionSlotFlags;
void **gFoundCollisionSlotObjects;
void *gSphereHitObjects[16];

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
            firstTerm0 = gRockFirstEffectRows00[scaledRow];
            secondTerm8 = gRockSecondEffectRows08[scaledRow];
            secondTerm6 = gRockSecondEffectRows06[scaledRow];
            secondTerm4 = gRockSecondEffectRows04[scaledRow];
            firstTerm6 = gRockFirstEffectRows06[scaledRow];
            firstEmitterParams.mRadius = gRockFirstEffectRows00[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm0, scaleY);
            firstTerm4 = gRockFirstEffectRows04[scaledRow];
            firstEmitterParams.mDirectionSpeed =
                gRockFirstEffectRows04[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm4, scaleY);
            secondTerm0 = gRockSecondEffectRows00[scaledRow];
            firstEmitterParams.mAxisSpeed = gRockFirstEffectRows06[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm6, scaleY);
            secondEmitterParams.mRadius = gRockSecondEffectRows00[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm0, scaleY);
            firstTerm8 = gRockFirstEffectRows08[scaledRow];
            firstEmitterParams.mSizeScale = gRockFirstEffectRows08[baseRow] + MUL_FIXED12_NO_ROUND(firstTerm8, scaleY);
            secondEmitterParams.mDirectionSpeed =
                gRockSecondEffectRows04[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm4, scaleY);
            secondEmitterParams.mAxisSpeed =
                gRockSecondEffectRows06[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm6, scaleY);
            secondEmitterParams.mSizeScale =
                gRockSecondEffectRows08[baseRow] + MUL_FIXED12_NO_ROUND(secondTerm8, scaleY);
            if (rock->mMapObject.mKind == MAP_OBJECT_KIND_ROCK) {
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

    if (rock->mDelayFramesLeft > 0) {
        rock->mDelayFramesLeft -= 1;
        if (rock->mDelayFramesLeft != 0) {
            return;
        }
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = 1;
        return;
    }
    oldBaseX = rock->mBasePos.x;
    oldBaseZ = rock->mBasePos.z;
    AdvanceGroupFollowerWithSpeeds(&rock->mFollower);
    GetGroupFollowerCurveXzLinearY(&rock->mFollower.mGroupFollower, &rock->mBasePos);
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
                    sideIndex = (u16) rock->mFollower.mGroupFollower.mSegmentIndex;
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
    if (rock->mSinceGroundFrames < ROCK_GROUND_GRACE_FRAMES) {
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
        rock->mMapObject.mViewRadius = MUL_FIXED12_NO_ROUND(rock->mMapObject.mKindData->mViewRadius, newScale);
        rock->mBottomOffsetReciprocal = FX_GetDivResult();
    }
    if (rock->mFollower.mGroupFollower.mForward == 0) {
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

    SetupGroupFollowerWithSpeeds(&rock->mFollower, 0, 1);
    GetGroupFollowerCurvePosStepXz(&rock->mFollower.mGroupFollower, &rock->mMapObject.mPos, &rock->mMapObject.mPosStep);
    rock->mDelayFramesLeft = rock->mDelayFrames;
    if (rock->mDelayFramesLeft != 0) {
        rock->mMapObject.mFlags |= gRockFirstFlag;
        rock->mMapObject.mFlags |= gRockSecondFlag;
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
    rock->mMapObject.mMatrix.mRows[0] = gRockMatrixRow0;
    rock->mMapObject.mMatrix.mRows[1] = gRockMatrixRow1;
    rock->mMapObject.mMatrix.mRows[2] = gRockMatrixRow2;
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
    rock->mMapObject.mViewRadius = MUL_FIXED12_NO_ROUND(rock->mMapObject.mKindData->mViewRadius, startScale);
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

    InitGroupFollowerWithSpeeds(&rock->mFollower, courseRow, 0x3000, courseRow->mSettings[1]);
    rock->mDelayFrames = courseRow->mSettings[0];
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
    rock->mDelayFramesLeft = courseRow->mSettings[5];
    if (rock->mDelayFramesLeft != 0) {
        rock->mMapObject.mFlags |= gRockFirstFlag;
        rock->mMapObject.mFlags |= gRockSecondFlag;
    } else {
        rock->mMapObject.mFlags &= ~2;
        rock->mMapObject.mFlags &= ~8;
        rock->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    }
    rock->mBounceRatio = TO_FIXED12(courseRow->mSettings[2]) / 100;
    if (rock->mMapObject.mKind == MAP_OBJECT_KIND_ROCK) {
        CreateMapObjectSoundSourceFalloff4(&rock->mMapObject);
    } else {
        CreateMapObjectSoundSourceFalloff3(&rock->mMapObject);
    }
    rock->mMapObject.mFlags |= gRockThirdFlag;
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
    gSearchCollisionSlots = 0;
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
    CollisionFirstHit **hitList = hitListPtr;
    CollisionFirstHit *firstHit;

    if (link->mObject != NULL) {
        if (collisionBits & 0x80000000) {
            link->mObject = NULL;
            return;
        }
        GetCollisionHitLinkPosition(link, position);
        firstHit = *hitList;
        if (firstHit->mLinkBlocked == 0 && link->mObject == firstHit->mObject) {
            return;
        }
        link->mObject = NULL;
        return;
    }
    if (collisionBits & 0x80000000) {
        return;
    }
    firstHit = *hitList;
    if (firstHit->mObject == NULL) {
        return;
    }
    if (firstHit->mLinkBlocked != 0) {
        return;
    }
    if (!(collisionBits & 0x1e34ef)) {
        return;
    }
    SetCollisionHitLink(firstHit->mObject, position, normal, link);
}

// TRUE when b has the top bit, the hit list a has a non-zero word at 4, or its object differs from the link c.
BOOL IsCollisionHitLinkOutdated(void *hitListPtr, u32 collisionBits, CollisionHitLink *link) {
    CollisionFirstHit **hitList = hitListPtr;

    if ((collisionBits & 0x80000000) || (*hitList)->mLinkBlocked != 0 || link->mObject != (*hitList)->mObject) {
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
    gCollisionSlotHighEnds = HeapAlloc(heap, COLLISION_SLOT_COUNT * sizeof(*gCollisionSlotHighEnds));
    gCollisionSlotLowEnds = HeapAlloc(heap, COLLISION_SLOT_COUNT * sizeof(*gCollisionSlotLowEnds));
    gCollisionSlots = HeapAlloc(heap, COLLISION_SLOT_COUNT * sizeof(*gCollisionSlots));
    gCollisionSlotNextFree = HeapAlloc(heap, COLLISION_SLOT_COUNT * sizeof(*gCollisionSlotNextFree));
    gFoundCollisionSlotIndices = HeapAlloc(heap, FOUND_COLLISION_SLOT_CAPACITY * sizeof(*gFoundCollisionSlotIndices));
    gFoundCollisionSlotFlags = HeapAlloc(heap, FOUND_COLLISION_SLOT_CAPACITY * sizeof(*gFoundCollisionSlotFlags));
    gFoundCollisionSlotObjects = HeapAlloc(heap, FOUND_COLLISION_SLOT_CAPACITY * sizeof(*gFoundCollisionSlotObjects));
    nextFreeIndex = 0;
    do {
        gCollisionSlotNextFree[nextFreeIndex] = nextFreeIndex + 1;
        nextFreeIndex++;
    } while (nextFreeIndex < COLLISION_SLOT_COUNT);
    slotIndex = 0;
    do {
        gCollisionSlots[slotIndex].mCenterPos = NULL;
        slotIndex++;
    } while (slotIndex < COLLISION_SLOT_COUNT);
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

    if (gCollisionSlotCount >= COLLISION_SLOT_COUNT) {
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
        gCollisionSlotHighEnds[0].mSlotIndexOrScanLimit = 0;
        gCollisionSlotHighEnds[0].mEndX = hi;
        gCollisionSlotLowEnds[0].mOtherEndIndex = 0;
        gCollisionSlotLowEnds[0].mSlotIndexOrScanLimit = slotIndex;
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
            gCollisionSlots[otherEnd->mSlotIndexOrScanLimit].mHighEndIndex += 1;
            endIndex--;
            if (endEntry->mSlotIndexOrScanLimit >= lowPosition) {
                endEntry->mSlotIndexOrScanLimit += 1;
            }
        } while (endIndex > highPosition);
    }
    gCollisionSlotHighEnds[highPosition].mOtherEndIndex = lowPosition;
    gCollisionSlotHighEnds[highPosition].mEndX = hi;
    if (highPosition == gCollisionSlotCount ||
        gCollisionSlotHighEnds[highPosition + 1].mSlotIndexOrScanLimit > lowPosition) {
        gCollisionSlotHighEnds[highPosition].mSlotIndexOrScanLimit = lowPosition;
        for (index = highPosition - 1; index >= 0 && gCollisionSlotHighEnds[index].mSlotIndexOrScanLimit > lowPosition;
             index--) {
            gCollisionSlotHighEnds[index].mSlotIndexOrScanLimit = lowPosition;
        }
    } else {
        gCollisionSlotHighEnds[highPosition].mSlotIndexOrScanLimit =
            gCollisionSlotHighEnds[highPosition + 1].mSlotIndexOrScanLimit;
    }
    endIndex = gCollisionSlotCount;
    if (endIndex > lowPosition) {
        do {
            endEntry = &gCollisionSlotLowEnds[endIndex];
            *endEntry = gCollisionSlotLowEnds[endIndex - 1];
            gCollisionSlotHighEnds[endEntry->mOtherEndIndex].mOtherEndIndex += 1;
            gCollisionSlots[endEntry->mSlotIndexOrScanLimit].mLowEndIndex += 1;
            endIndex--;
        } while (endIndex > lowPosition);
    }
    gCollisionSlotLowEnds[lowPosition].mOtherEndIndex = highPosition;
    gCollisionSlotLowEnds[lowPosition].mSlotIndexOrScanLimit = slotIndex;
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
            gCollisionSlots[otherEnd->mSlotIndexOrScanLimit].mHighEndIndex -= 1;
            if (endEntry->mSlotIndexOrScanLimit > lowIndex) {
                endEntry->mSlotIndexOrScanLimit -= 1;
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
            gCollisionSlots[endEntry->mSlotIndexOrScanLimit].mLowEndIndex -= 1;
            otherIndex = endEntry->mOtherEndIndex;
            if (otherIndex < highIndex) {
                otherEnd = &gCollisionSlotHighEnds[otherIndex];
                index = otherEnd->mSlotIndexOrScanLimit;
                if (index == lowIndex) {
                    while (gCollisionSlotLowEnds[index].mOtherEndIndex < (u32) otherIndex) {
                        index++;
                    }
                    otherEnd->mSlotIndexOrScanLimit = index;
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
    searchStep = gCollisionSlotHighEnds[highEndIndex].mSlotIndexOrScanLimit;
    if (value < searchStep) {
        return;
    }
    do {
        if (gCollisionSlotLowEnds[value].mOtherEndIndex >= highEndIndex) {
            slot = &gCollisionSlots[gCollisionSlotLowEnds[value].mSlotIndexOrScanLimit];
            slotFlags = slot->mFlags;
            if (slot->mHighZ >= zlo && slot->mLowZ <= zhi && (slotFlags & flagMask) &&
                !(slotFlags & COLLISION_SLOT_FLAG_DISABLED)) {
                gFoundCollisionSlotIndices[gFoundCollisionSlotCount] =
                    gCollisionSlotLowEnds[value].mSlotIndexOrScanLimit;
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

// A slot with flag 0x400 also gets the flags of gCollisionSlotRadiusFlag set.
void SetCollisionSlotRadius(s16 slotIndex, s32 radius) {
    CollisionSlot *slot;

    slot = &gCollisionSlots[slotIndex];
    slot->mRadius = radius;
    if (slot->mFlags & COLLISION_SLOT_FLAG_MARK_RADIUS_CHANGE) {
        slot->mFlags |= gCollisionSlotRadiusFlag;
    }
}

void DisableCollisionSlot(s16 slotIndex) {
    gCollisionSlots[slotIndex].mFlags |= gCollisionSlotDisabledFlag;
}

void EnableCollisionSlot(s16 slotIndex) {
    gCollisionSlots[slotIndex].mFlags &= ~COLLISION_SLOT_FLAG_DISABLED;
}

const u16 gRockFirstFlag = 2;
const u16 gRockSecondFlag = 8;
const u16 gRockThirdFlag = 0x200;
