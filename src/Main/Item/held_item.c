#include "Main/Item/held_item.h"

#include "Main/Item/item_in_use.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_object_reset_collide.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "fixed_vector_math.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_f_box.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const u16 gItemObjectPendingUpdateCatchUpBit = ITEM_OBJECT_PENDING_UPDATE_CATCH_UP;
const ItemSpreadRow gItemSpreadRows[3] = {{{{0x1000, 0}, {0, 0}, {0, 0}}},
                                          {{{-2048, 0xddb}, {-2048, -3547}, {0, 0}}},
                                          {{{0x1000, 0}, {-2048, 0xddb}, {-2048, -3547}}}};
s32 gItemPointLinksByIndex[4];

// Runs the countdown that starts the held objects. Then, only for an item with a use timer that is running and once the
// start countdown has finished, counts the timer down and, when it reaches 0, takes one object off the held item (and
// its pool reservation).
void UpdateHeldItem(HeldItem *heldItem) {
    s32 objectIndex;
    u32 objectKind;
    ItemInfoIndex itemInfoIndex;
    s32 reservedCount;

    StartNextHeldItemObject(heldItem);
    if (heldItem->mUsesTimer == 0) {
        return;
    }
    if (heldItem->mTimer == 0) {
        return;
    }
    if (heldItem->mObjectStartFramesLeft != 0) {
        return;
    }
    heldItem->mTimer -= 1;
    if (heldItem->mTimer != 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        if (gRaceSetup->mEntryIndex == heldItem->mKartItems->mKartIndex) {
            itemInfoIndex = (ItemInfoIndex) heldItem->mItemInfoIndex;
            AddItemDataFrameOnly(gItemInfos[itemInfoIndex].mObjectKind);
        }
    }
    heldItem->mObjectCount -= 1;
    objectKind = gItemInfos[heldItem->mItemInfoIndex].mObjectKind;
    reservedCount = gItemPools[objectKind].mReservedCount;
    GetItemPool(objectKind)->mReservedCount = reservedCount - 1;
    if (heldItem->mObjectCount == 0) {
        heldItem->mItemInfoIndex = ITEM_INFO_NONE;
        heldItem->mObjectCount = 0;
        heldItem->mObjectStartFramesLeft = 0;
        heldItem->mUsesTimer = 0;
        heldItem->mTimer = 0;
        heldItem->mUseTimerLimit = 0;
        for (objectIndex = 0; objectIndex < 3; objectIndex++) {
            heldItem->mObjects[objectIndex] = NULL;
        }
    }
}

// Makes the item held and reserves its objects in the item's pool.
void SetHeldItem(HeldItem *heldItem, s32 itemInfoIndex) {
    u32 objectCountOrKind;
    s32 reservedCount;

    objectCountOrKind = gItemInfos[itemInfoIndex].mObjectCount;
    heldItem->mItemInfoIndex = itemInfoIndex;
    heldItem->mObjectCount = objectCountOrKind;
    heldItem->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(heldItem->mKartItems->mKart);
    heldItem->mUsesTimer = gItemInfos[itemInfoIndex].mUsesTimer;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    objectCountOrKind = gItemInfos[itemInfoIndex].mObjectKind;
    reservedCount = gItemPools[objectCountOrKind].mReservedCount;
    GetItemPool(objectCountOrKind)->mReservedCount = reservedCount + heldItem->mObjectCount;
}

void RemoveHeldItemObjects(HeldItem *heldItem, s32 amount) {
    s32 objectIndex;
    int objectKind;

    heldItem->mObjectCount -= amount;
    objectKind = gItemInfos[heldItem->mItemInfoIndex].mObjectKind;
    GetItemPool(objectKind)->mReservedCount = gItemPools[objectKind].mReservedCount - amount;
    if (heldItem->mObjectCount == 0) {
        heldItem->mItemInfoIndex = ITEM_INFO_NONE;
        heldItem->mObjectCount = 0;
        heldItem->mObjectStartFramesLeft = 0;
        heldItem->mUsesTimer = 0;
        heldItem->mTimer = 0;
        heldItem->mUseTimerLimit = 0;
        for (objectIndex = 0; objectIndex < 3; objectIndex++) {
            heldItem->mObjects[objectIndex] = NULL;
        }
    }
}

void ResetHeldItem(HeldItem *heldItem) {
    s32 objectIndex;

    heldItem->mItemInfoIndex = ITEM_INFO_NONE;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (objectIndex = 0; objectIndex < 3; objectIndex++) {
        heldItem->mObjects[objectIndex] = NULL;
    }
}

// Gives the held objects back to the pool, or the reserved count unless keep is set, then empties the record.
void ReleaseHeldItem(HeldItem *heldItem, s32 keepReservedCount) {
    s32 reservedCount;
    s32 objectIndex;
    s32 objectCount;
    s32 releaseIndex;
    s32 takenObjectCount;
    ItemInfoIndex itemInfoIndex = (ItemInfoIndex) heldItem->mItemInfoIndex;
    u32 poolIndex = gItemInfos[itemInfoIndex].mObjectKind;

    if (gRaceSetup->mMode == MODE_WIFI) {
        objectCount = heldItem->mObjectCount;
        if (heldItem->mIsPeerEntry == FALSE) {
            for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
                AddItemDataNoItemId(poolIndex);
            }
        }
    }
    if (heldItem->mObjectStartFramesLeft != 0) {
        takenObjectCount = heldItem->mObjectCount;
        for (releaseIndex = 0; releaseIndex < takenObjectCount; releaseIndex++) {
            ReleaseItemPoolObject(&gItemPools[heldItem->mObjects[releaseIndex]->mKind], heldItem->mObjects[releaseIndex]);
        }
    } else if (keepReservedCount == 0) {
        reservedCount = gItemPools[poolIndex].mReservedCount;
        GetItemPool(poolIndex)->mReservedCount = reservedCount - heldItem->mObjectCount;
    }
    heldItem->mItemInfoIndex = ITEM_INFO_NONE;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (objectIndex = 0; objectIndex < 3; objectIndex++) {
        heldItem->mObjects[objectIndex] = NULL;
    }
}

static inline u32 HeldItemNextRandomBelow(RandomState64 *generator, u32 range) {
    RANDOM_ADVANCE(generator);
    if (range == 0) {
        return RANDOM_HIGH32(generator);
    } else {
        return RANDOM_BELOW(generator, range);
    }
}

// Takes the held objects from their pool and gives each a starting velocity.
void TakeHeldItemObjects(HeldItem *heldItem) {
    Kart *owner = heldItem->mKartItems->mKart;
    CourseColorBlend *colorBlend = &owner->mKartModelsEntry->mCourseColorBlend;
    Vec3 *drawBaseRow2 = &owner->mDrawBaseRow2;
    Vec3 *drawBaseRow0 = &owner->mDrawBaseRow0;
    s32 objectIndex;
    s32 count;
    RandomState64 *generator;
    const ItemSpreadRow *row;
    ItemObject *object;
    s32 itemInfoIndex = heldItem->mItemInfoIndex;
    s32 poolIndex;
    s32 radius;
    s32 angle;
    s32 radiusTimesAnglePairFirst;
    s32 radiusTimesAnglePairSecond;
    s32 rowXJittered;
    s32 rowYJittered;
    s32 directionAmount;
    s32 rowX;
    s32 rowY;

    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        generator = &gRaceProgress->mLocalRandom;
    } else {
        generator = &gRaceProgress->mRandom;
    }
    angle = (u16) HeldItemNextRandomBelow(generator, ANGLE_FULL_TURN);
    poolIndex = gItemInfos[itemInfoIndex].mObjectKind;
    if (gItemKinds[poolIndex].mStartsFalling != 0) {
        radius = 0x2000;
    } else {
        radius = 0x1800;
    }
    count = heldItem->mObjectCount;
    radiusTimesAnglePairFirst = MUL_FIXED12_NO_ROUND(radius, SIN_OF_ANGLE(angle));
    radiusTimesAnglePairSecond = MUL_FIXED12_NO_ROUND(radius, COS_OF_ANGLE(angle));
    TakeItemPoolObjects(&gItemPools[poolIndex], count, heldItem->mObjects, owner->mIndex, &owner->mDrawMatrixPos);
    objectIndex = 0;
    if (objectIndex < count) {
        row = &gItemSpreadRows[count - 1];
        do {
            rowX = row->mOffsets[objectIndex].mX;
            rowY = row->mOffsets[objectIndex].mY;
            rowXJittered = MUL_FIXED12_NO_ROUND(rowX, 0x1000 + (s32) HeldItemNextRandomBelow(generator, 0x333));
            rowYJittered = MUL_FIXED12_NO_ROUND(rowY, 0x1000 + (s32) HeldItemNextRandomBelow(generator, 0x333));
            directionAmount = MUL_FIXED12_NO_ROUND(rowXJittered, radiusTimesAnglePairSecond) -
                              MUL_FIXED12_NO_ROUND(rowYJittered, radiusTimesAnglePairFirst);
            object = heldItem->mObjects[objectIndex];
            object->mVelocity.x = MUL_FIXED12_NO_ROUND(drawBaseRow2->x, directionAmount);
            object->mVelocity.y = MUL_FIXED12_NO_ROUND(drawBaseRow2->y, directionAmount);
            object->mVelocity.z = MUL_FIXED12_NO_ROUND(drawBaseRow2->z, directionAmount);
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(rowYJittered, radiusTimesAnglePairSecond) +
                            MUL_FIXED12_NO_ROUND(directionAmount, radiusTimesAnglePairFirst),
                        drawBaseRow0, &object->mVelocity, &object->mVelocity);
            object->mScale.x = 0xcd;
            object->mScale.y = 0xcd;
            object->mScale.z = 0xcd;
            object->mColorBlend = *colorBlend;
            objectIndex++;
        } while (objectIndex < count);
    }
}

// Takes the held objects and starts the countdown that starts them one at a time.
void StartHeldItemObjects(HeldItem *heldItem) {
    heldItem->mObjectStartFramesLeft = HELD_ITEM_OBJECT_START_FRAMES;
    TakeHeldItemObjects(heldItem);
}

BOOL StartHeldItemTimer(HeldItem *heldItem, s32 frames) {
    if (heldItem->mTimer != 0) {
        return FALSE;
    }
    heldItem->mTimer = frames;
    return TRUE;
}

// The held item can be used again once the timer has counted down by this many frames.
void SetHeldItemUseDelay(HeldItem *heldItem, s32 frames) {
    heldItem->mUseTimerLimit = heldItem->mTimer - frames;
}

void RemoveHeldItem(HeldItem *heldItem, s32 *itemInfoIndex, s32 *count) {
    s32 objectIndex;

    *itemInfoIndex = heldItem->mItemInfoIndex;
    *count = heldItem->mObjectCount;
    heldItem->mItemInfoIndex = ITEM_INFO_NONE;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (objectIndex = 0; objectIndex < 3; objectIndex++) {
        heldItem->mObjects[objectIndex] = NULL;
    }
}

// Like SetHeldItem, but the count comes from the caller and nothing is reserved in the pool.
void SetHeldItemWithCount(HeldItem *heldItem, s32 itemInfoIndex, s32 count) {
    heldItem->mItemInfoIndex = itemInfoIndex;
    heldItem->mObjectCount = count;
    heldItem->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(heldItem->mKartItems->mKart);
    heldItem->mUsesTimer = gItemInfos[itemInfoIndex].mUsesTimer;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
}

void RemoveReservedItemObjects(s32 itemInfoIndex, s32 amount) {
    int objectKind = gItemInfos[itemInfoIndex].mObjectKind;

    GetItemPool(objectKind)->mReservedCount = gItemPools[objectKind].mReservedCount - amount;
}

s32 GetItemPointLinkByIndex(s32 index) {
    return gItemPointLinksByIndex[index];
}

void InitSegmentPoints(SegmentPoints *segmentPoints, const Vec3 *points, s32 rate) {
    s32 pointIndex;

    for (pointIndex = 0; pointIndex < SEGMENT_POINT_COUNT; pointIndex++) {
        segmentPoints->mPointPointers[pointIndex] = &segmentPoints->mPoints[pointIndex];
        segmentPoints->mPoints[pointIndex] = points[pointIndex];
    }
    segmentPoints->mWriteIndex = 0;
    InitSegmentProgress(&segmentPoints->mSegmentProgress, 1, segmentPoints->mPointPointers, rate);
}

s32 PushSegmentPoint(SegmentPoints *segmentPoints, const Vec3 *point) {
    Vec3 *first;

    segmentPoints->mPoints[segmentPoints->mWriteIndex] = *point;
    segmentPoints->mWriteIndex += 1;
    segmentPoints->mWriteIndex &= SEGMENT_POINT_COUNT - 1;
    first = segmentPoints->mPointPointers[0];
    segmentPoints->mPointPointers[0] = segmentPoints->mPointPointers[1];
    segmentPoints->mPointPointers[1] = segmentPoints->mPointPointers[2];
    segmentPoints->mPointPointers[2] = segmentPoints->mPointPointers[3];
    segmentPoints->mPointPointers[3] = first;
    return BuildNextSegmentProgress(&segmentPoints->mSegmentProgress, 1, segmentPoints->mPointPointers);
}

// Writes the link nearest pos among the link, its neighbours and their neighbours.
BOOL PickNearestNearbyItemPointLink(ItemPointLinkRef *in, ItemPointLinkRef *out, Vec3 *pos) {
    ItemPointLink *startLink = in->mLink;
    ItemPointLink *best;
    ItemPointLink *nextLink;
    ItemPointLink *linkAroundNext;
    Vec3 *linkPos = startLink->mPointPos;
    s32 nextCount;
    ItemPointLink *previousLink;
    ItemPointLink *linkAroundPrevious;
    Vec3 *previousLinkPos;
    s32 previousCount;
    s32 distanceSquared;
    s32 deltaX;
    s32 deltaY;
    s32 deltaZ;
    s32 bestDistanceSquared;
    s32 linkIndex;
    s32 firstAroundIndex;
    s32 secondAroundIndex;
    Vec3 *posAlias = pos;
    ItemPointLink *nodeAlias = startLink;

    best = startLink;
    deltaX = FROM_FIXED12(linkPos->x - pos->x);
    deltaY = FROM_FIXED12(linkPos->y - pos->y);
    deltaZ = FROM_FIXED12(linkPos->z - pos->z);
    bestDistanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    for (linkIndex = 0; linkIndex < nodeAlias->mNextCount; linkIndex++) {
        nextLink = startLink->mNextLinks[linkIndex];
        if (nextLink != NULL) {
            linkPos = nextLink->mPointPos;
            deltaX = FROM_FIXED12(linkPos->x - pos->x);
            deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
            deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
            distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
            nextCount = nextLink->mNextCount;
            if (distanceSquared < bestDistanceSquared) {
                bestDistanceSquared = distanceSquared;
                best = nextLink;
            }
            for (firstAroundIndex = 0; firstAroundIndex < nextCount; firstAroundIndex++) {
                linkAroundNext = nextLink->mNextLinks[firstAroundIndex];
                linkPos = linkAroundNext->mPointPos;
                deltaX = FROM_FIXED12(linkPos->x - pos->x);
                deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
                deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDistanceSquared) {
                    bestDistanceSquared = distanceSquared;
                    best = linkAroundNext;
                }
            }
            previousCount = nextLink->mPreviousCount;
            for (secondAroundIndex = 0; secondAroundIndex < previousCount; secondAroundIndex++) {
                linkAroundNext = nextLink->mPreviousLinks[secondAroundIndex];
                if (linkAroundNext != startLink) {
                    linkPos = linkAroundNext->mPointPos;
                    deltaX = FROM_FIXED12(linkPos->x - pos->x);
                    deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
                    deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
                    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                    if (distanceSquared < bestDistanceSquared) {
                        bestDistanceSquared = distanceSquared;
                        best = linkAroundNext;
                    }
                }
            }
        }
    }
    for (linkIndex = 0; linkIndex < nodeAlias->mPreviousCount; linkIndex++) {
        previousLink = startLink->mPreviousLinks[linkIndex];
        if (previousLink != NULL) {
            previousLinkPos = previousLink->mPointPos;
            deltaX = FROM_FIXED12(previousLinkPos->x - pos->x);
            deltaY = FROM_FIXED12(previousLinkPos->y - posAlias->y);
            deltaZ = FROM_FIXED12(previousLinkPos->z - posAlias->z);
            distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
            previousCount = previousLink->mPreviousCount;
            if (distanceSquared < bestDistanceSquared) {
                bestDistanceSquared = distanceSquared;
                best = previousLink;
            }
            for (firstAroundIndex = 0; firstAroundIndex < previousCount; firstAroundIndex++) {
                linkAroundPrevious = previousLink->mPreviousLinks[firstAroundIndex];
                previousLinkPos = linkAroundPrevious->mPointPos;
                deltaX = FROM_FIXED12(previousLinkPos->x - pos->x);
                deltaY = FROM_FIXED12(previousLinkPos->y - posAlias->y);
                deltaZ = FROM_FIXED12(previousLinkPos->z - posAlias->z);
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDistanceSquared) {
                    bestDistanceSquared = distanceSquared;
                    best = linkAroundPrevious;
                }
            }
            nextCount = previousLink->mNextCount;
            for (secondAroundIndex = 0; secondAroundIndex < nextCount; secondAroundIndex++) {
                linkAroundPrevious = previousLink->mNextLinks[secondAroundIndex];
                if (linkAroundPrevious != startLink) {
                    previousLinkPos = linkAroundPrevious->mPointPos;
                    deltaX = FROM_FIXED12(previousLinkPos->x - pos->x);
                    deltaY = FROM_FIXED12(previousLinkPos->y - posAlias->y);
                    deltaZ = FROM_FIXED12(previousLinkPos->z - posAlias->z);
                    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                    if (distanceSquared < bestDistanceSquared) {
                        bestDistanceSquared = distanceSquared;
                        best = linkAroundPrevious;
                    }
                }
            }
        }
    }
    out->mLink = best;
    out->mNextLinksUsed = 1;
    return best != startLink;
}

BOOL CopyCloserItemPointLinkRef(ItemPointLinkRef *current, ItemPointLinkRef *candidate, ItemPointLinkRef *out,
                                Vec3 *pos) {
    Vec3 *currentPos = current->mLink->mPointPos;
    Vec3 *candidatePos = candidate->mLink->mPointPos;
    s32 currentDistanceSquared = FROM_FIXED12(currentPos->x - pos->x) * FROM_FIXED12(currentPos->x - pos->x) +
                                 FROM_FIXED12(currentPos->y - pos->y) * FROM_FIXED12(currentPos->y - pos->y) +
                                 FROM_FIXED12(currentPos->z - pos->z) * FROM_FIXED12(currentPos->z - pos->z);
    s32 candidateDistanceSquared = FROM_FIXED12(candidatePos->x - pos->x) * FROM_FIXED12(candidatePos->x - pos->x) +
                                   FROM_FIXED12(candidatePos->y - pos->y) * FROM_FIXED12(candidatePos->y - pos->y) +
                                   FROM_FIXED12(candidatePos->z - pos->z) * FROM_FIXED12(candidatePos->z - pos->z);

    if (candidateDistanceSquared < currentDistanceSquared) {
        *out = *candidate;
        return TRUE;
    }
    return FALSE;
}

// Follows the next links until one is nearer to pos than the start link.
BOOL FollowItemPointLinksToPos(ItemPointLinkRef *in, ItemPointLinkRef *out, Vec3 *pos) {
    ItemPointLink *startLink = in->mLink;
    s32 distanceSquared;
    Vec3 *linkPos;
    s32 deltaY;
    Vec3 *posAlias;
    s32 deltaX;
    s32 startDistanceSquared;
    s32 stepsLeft;
    s32 deltaZ;
    ItemPointLink *nextLink;
    ItemPointLink *current;
    ItemPointLink *best;
    s32 bestDistanceSquared;
    s32 nextLinkIndex;

    linkPos = startLink->mPointPos;
    deltaX = FROM_FIXED12(linkPos->x - pos->x);
    deltaY = FROM_FIXED12(linkPos->y - pos->y);
    deltaZ = FROM_FIXED12(linkPos->z - pos->z);
    startDistanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    stepsLeft = gCourseMap->mItemPointCount;
    posAlias = pos;

    current = startLink;
    do {
        best = NULL;
        bestDistanceSquared = 0x7fffffff;
        for (nextLinkIndex = 0; nextLinkIndex < current->mNextCount; nextLinkIndex++) {
            nextLink = current->mNextLinks[nextLinkIndex];
            if (nextLink != NULL) {
                linkPos = nextLink->mPointPos;
                deltaX = FROM_FIXED12(linkPos->x - pos->x);
                deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
                deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDistanceSquared) {
                    bestDistanceSquared = distanceSquared;
                    best = nextLink;
                }
            }
        }
        if (bestDistanceSquared < startDistanceSquared) {
            out->mLink = best;
            out->mNextLinksUsed = 1;
            return best != startLink;
        }
        stepsLeft--;
        current = best;
    } while (stepsLeft > 1 && best != startLink);
    out->mLink = startLink;
    out->mNextLinksUsed = 1;
    return FALSE;
}

// Writes the link to go on to, leaning toward kart idx when it is close.
void PickNextItemPointLink(ItemPointLinkRef *in, ItemPointLinkRef *out, u32 kartIndex, s32 flag) {
    ItemPointLink *startLink = in->mLink;
    s32 nextLinksUsed = in->mNextLinksUsed;
    ItemPointLink *targetLink;
    ItemPointLink *candidateLink;
    s32 secondCount;
    s32 linkCount;
    Vec3 *origin;
    BOOL kartIsNear;
    s32 bestDistanceSquared;
    ItemPointLink *bestSecondLink;
    Vec3 *kartPos;
    s32 candidateIndex;
    Vec3 *childPos;
    Kart *kart;
    s32 distance;

    if (nextLinksUsed != 0) {
        linkCount = startLink->mNextCount;
        targetLink = startLink->mNextLinks[0];
    } else {
        linkCount = startLink->mPreviousCount;
        targetLink = startLink->mPreviousLinks[0];
    }
    if (linkCount <= 1 && (nextLinksUsed != 0 ? targetLink->mPreviousCount : targetLink->mNextCount) <= 1) {
    done:
        out->mLink = targetLink;
        out->mNextLinksUsed = nextLinksUsed;
        return;
    }
    origin = startLink->mPointPos;
    kartIsNear = FALSE;
    bestDistanceSquared = 0x5f592e1;
    if (kartIndex < 8) {
        kart = GetKart(kartIndex);
        kartPos = &kart->mDrawMatrixPos;
        {
            s64 distanceSquaredXZ = (s64) (((const Vec3 *) kartPos)->x - ((const Vec3 *) origin)->x) *
                     (((const Vec3 *) kartPos)->x - ((const Vec3 *) origin)->x);
            distanceSquaredXZ += (s64) (((const Vec3 *) kartPos)->z - ((const Vec3 *) origin)->z) *
                  (((const Vec3 *) kartPos)->z - ((const Vec3 *) origin)->z);
            if (distanceSquaredXZ < 0x225510000000LL) {
                kartIsNear = TRUE;
                for (candidateIndex = 0; candidateIndex < linkCount; candidateIndex++) {
                    candidateLink = nextLinksUsed != 0 ? startLink->mNextLinks[candidateIndex] : startLink->mPreviousLinks[candidateIndex];
                    if (candidateLink != NULL) {
                        childPos = candidateLink->mPointPos;
                        distance = FROM_FIXED12(kartPos->x - origin->x) * FROM_FIXED12(childPos->x - origin->x);
                        distance += FROM_FIXED12(kartPos->z - origin->z) * FROM_FIXED12(childPos->z - origin->z);
                        if (distance > 0) {
                            distance =
                                FROM_FIXED12(candidateLink->mPointPos->x - kartPos->x) * FROM_FIXED12(candidateLink->mPointPos->x - kartPos->x);
                            distance +=
                                FROM_FIXED12(candidateLink->mPointPos->y - kartPos->y) * FROM_FIXED12(candidateLink->mPointPos->y - kartPos->y);
                            distance +=
                                FROM_FIXED12(candidateLink->mPointPos->z - kartPos->z) * FROM_FIXED12(candidateLink->mPointPos->z - kartPos->z);
                            if (distance < bestDistanceSquared) {
                                bestDistanceSquared = distance;
                                targetLink = candidateLink;
                            }
                        }
                    }
                }
            }
        }
    }
    if (nextLinksUsed == 0 || (kartIsNear != FALSE && flag != 0)) {
        if ((nextLinksUsed != 0 ? targetLink->mPreviousCount : targetLink->mNextCount) > 1) {
            bestSecondLink = NULL;
            secondCount = nextLinksUsed != 0 ? targetLink->mPreviousCount : targetLink->mNextCount;
            for (candidateIndex = 0; candidateIndex < secondCount; candidateIndex++) {
                candidateLink = nextLinksUsed != 0 ? targetLink->mPreviousLinks[candidateIndex] : targetLink->mNextLinks[candidateIndex];
                if (candidateLink != NULL && candidateLink != startLink) {
                    if (kartIsNear != FALSE) {
                        childPos = candidateLink->mPointPos;
                        distance = FROM_FIXED12(kartPos->x - origin->x) * FROM_FIXED12(childPos->x - origin->x);
                        distance += FROM_FIXED12(kartPos->z - origin->z) * FROM_FIXED12(childPos->z - origin->z);
                        if (distance > 0) {
                            distance =
                                FROM_FIXED12(candidateLink->mPointPos->x - kartPos->x) * FROM_FIXED12(candidateLink->mPointPos->x - kartPos->x);
                            distance +=
                                FROM_FIXED12(candidateLink->mPointPos->y - kartPos->y) * FROM_FIXED12(candidateLink->mPointPos->y - kartPos->y);
                            distance +=
                                FROM_FIXED12(candidateLink->mPointPos->z - kartPos->z) * FROM_FIXED12(candidateLink->mPointPos->z - kartPos->z);
                            if (distance < bestDistanceSquared) {
                                bestDistanceSquared = distance;
                                bestSecondLink = candidateLink;
                            }
                        }
                    } else {
                        targetLink = candidateLink;
                        nextLinksUsed = 1;
                        goto done;
                    }
                }
            }
            if (bestSecondLink != NULL) {
                targetLink = bestSecondLink;
                nextLinksUsed = nextLinksUsed == 0 ? 1 : 0;
            }
        }
    }
    goto done;
}

u8 GetItemPointLinkIndex(ItemPointLinkRef *ref) {
    if (ref->mLink == NULL) {
        return 0xff;
    }
    return ref->mLink - gCourseMap->mItemRoute0FirstLink;
}

s32 SetItemPointLinkRefFromIndex(u32 index, ItemPointLinkRef *ref) {
    if (index >= 0xff) {
        ref->mLink = NULL;
    } else {
        ref->mLink = gCourseMap->mItemRoute0FirstLink + index;
    }
    ref->mNextLinksUsed = 1;
    return 1;
}

u32 GetItemPointLinkDirection(ItemPointLink *link, Vec3 *directionOut) {
    u32 scaledDirectionZ;
    u32 component;
    component = link->mDirectionX;
    component = (component << 6);
    directionOut->x = component;
    component = link->mDirectionY;
    component = (component << 6);
    directionOut->y = component;
    scaledDirectionZ = link->mDirectionZ;
    scaledDirectionZ = (scaledDirectionZ << 6);
    directionOut->z = scaledDirectionZ;
    return scaledDirectionZ;
}

#pragma thumb on

// Stores each link's direction toward its first next link (normalised when the offset is long enough), and records the
// links whose mRadius is at least ITEM_POINT_LINK_INDEXED_RADIUS in gItemPointLinksByIndex by mLinkIndex.
void InitItemPointLinkDirections(void) {
    ItemPointLink *link;
    Vec3 direction;
    u32 linkCount;
    u16 linkIndex;

    linkCount = gCourseMap->mItemPointCount;
    link = gCourseMap->mItemPointLinks;
    linkIndex = 0;
    for (linkIndex = 0; linkIndex < 4; linkIndex++) {
        gItemPointLinksByIndex[linkIndex] = 0;
    }
    for (linkIndex = 0; linkIndex < linkCount; linkIndex++, link++) {
        if (link->mRadius >= ITEM_POINT_LINK_INDEXED_RADIUS) {
            gItemPointLinksByIndex[link->mLinkIndex] = (s32) link;
        }
    }
    link = gCourseMap->mItemPointLinks;
    for (linkIndex = 0; linkIndex < linkCount; linkIndex++, link++) {
        VEC_Subtract(link->mNextLinks[0]->mPointPos, link->mPointPos, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        link->mDirectionX = direction.x >> 6;
        link->mDirectionY = direction.y >> 6;
        link->mDirectionZ = direction.z >> 6;
    }
}

#pragma thumb off

static inline u32 BouncingItemNextRandomBelow(RandomState64 *generator, u32 range) {
    RANDOM_ADVANCE(generator);
    return RANDOM_BELOW_U64(generator, range);
}

// Gives a bouncing item its start velocity and position from the kart; c is 1 to throw forward.
void ThrowBouncingItem(BouncingItemObject *item, ItemInUse *itemInUse, s32 bounceCount, s32 throwForward,
                       s32 forwardSpeed, s32 forwardUpSpeed, s32 backwardUpSpeed) {
    Vec3 direction;
    s32 value;
    BOOL kartOnBoostSurface;
    Vec3 *scale;
    s32 dx;
    s32 alongY;
    s32 alongZ;

    value = Vec3DotUnrounded(&itemInUse->mKartMovement, &itemInUse->mKartOrientation.mRows[2]);
    kartOnBoostSurface = (itemInUse->mKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) != 0;
    value = MUL_FIXED12_NO_ROUND(value, 0x1ec);
    if (value < 0x666) {
        value = 0x666;
    }
    if (throwForward != 0) {
        value = ComputeItemThrowForward(itemInUse, forwardSpeed, 0x1b33, 0x7000, &direction);
    } else {
        value = ComputeItemThrowBackward(itemInUse, value, 0x1000, 0x7000, &direction);
    }
    if (throwForward != 0) {
        if (itemInUse->mKartHopHeight > 0) {
            value += MUL_FIXED12_NO_ROUND(itemInUse->mKartHopHeight, 0x14cd);
        }
    }
    if (itemInUse->mKartVelocityLength < ITEM_THROW_RANDOM_OFFSET_KART_SPEED) {
        direction.z += BouncingItemNextRandomBelow(&gRaceProgress->mRandom, 0xf6) - 0x7b;
        direction.x += BouncingItemNextRandomBelow(&gRaceProgress->mRandom, 0xf6) - 0x7b;
    }
    direction.x = MUL_FIXED12_NO_ROUND(direction.x, value);
    direction.y = MUL_FIXED12_NO_ROUND(direction.y, value);
    direction.z = MUL_FIXED12_NO_ROUND(direction.z, value);
    if (!kartOnBoostSurface) {
        if (throwForward != 0) {
            value = forwardUpSpeed + MUL_FIXED12_NO_ROUND(itemInUse->mKartVelocityLength, 0x200) +
                    MUL_FIXED12_NO_ROUND(itemInUse->mKartMovement.y, 0x2000);
        } else {
            value = backwardUpSpeed;
            dx = itemInUse->mKartMovement.y > 0 ? 0x666 : 0x1333;
            value += MUL_FIXED12_NO_ROUND(dx, itemInUse->mKartMovement.y);
        }
        VEC_MultAdd(value, &itemInUse->mKartOrientation.mRows[1], &direction, &item->mItemObject.mVelocity);
    }
    if (throwForward == 0) {
        VEC_Add(&item->mItemObject.mVelocity, &itemInUse->mKart->mPointMotion, &item->mItemObject.mVelocity);
    }
    if (throwForward != 0) {
        item->mItemObject.mPos = itemInUse->mKart->mCollisionCenter;
        VEC_MultAdd(item->mItemObject.mScale.z * 10, &itemInUse->mKartOrientation.mRows[2], &item->mItemObject.mPos,
                    &item->mItemObject.mPos);
    } else {
        if (itemInUse->mKartHopHeight != 0 && itemInUse->mKartVelocityLength < ITEM_THROW_HOP_OFFSET_KART_SPEED &&
            item->mItemObject.mScale.z < 0xccd) {
            VEC_Subtract(&itemInUse->mKartOrientation.mRows[1], &itemInUse->mKartOrientation.mRows[2], &direction);
            VEC_MultAdd(0x2000, &direction, &item->mItemObject.mPos, &item->mItemObject.mPos);
        }
    }
    if (item->mItemObject.mScale.z < 0xccd) {
        scale = &item->mItemObject.mScale;
        scale->x = 0xccd;
        scale->y = 0xccd;
        scale->z = 0xccd;
    }
    item->mBouncesRemaining = bounceCount;
    item->mItemObject.mBounce = BounceItemObject;
    item->mItemObject.mFlags &=
        ~(ITEM_OBJECT_FLAG_BOUNCED_BEFORE | ITEM_OBJECT_FLAG_DEFLECTED | ITEM_OBJECT_FLAG_HIT_THIS_STEP);
    if (!kartOnBoostSurface) {
        return;
    }
    value = VEC_DotProduct(&itemInUse->mKartOrientation.mRows[1], &item->mItemObject.mVelocity);
    dx = MUL_FIXED12_NO_ROUND(itemInUse->mKartOrientation.mRows[1].x, value);
    alongY = MUL_FIXED12_NO_ROUND(itemInUse->mKartOrientation.mRows[1].y, value);
    alongZ = MUL_FIXED12_NO_ROUND(itemInUse->mKartOrientation.mRows[1].z, value);
    item->mItemObject.mVelocity.x -= dx;
    item->mItemObject.mVelocity.y -= alongY;
    item->mItemObject.mVelocity.z -= alongZ;
    VEC_MultAdd(throwForward != 0 ? 0x8800 : -0x1000, &itemInUse->mKartOrientation.mRows[1],
                &item->mItemObject.mVelocity, &item->mItemObject.mVelocity);
    item->mBouncesRemaining = 0;
}

void InitBouncingItem(BouncingItemObject *item, s32 bounceCount, Vec3 *velocity) {
    if (velocity != NULL) {
        item->mItemObject.mVelocity = *velocity;
    }
    if (item->mItemObject.mScale.z < 0xccd) {
        item->mItemObject.mScale.x = 0xccd;
        item->mItemObject.mScale.y = 0xccd;
        item->mItemObject.mScale.z = 0xccd;
    }
    item->mBouncesRemaining = bounceCount;
    item->mItemObject.mBounce = BounceItemObject;
    item->mItemObject.mFlags &=
        ~(ITEM_OBJECT_FLAG_BOUNCED_BEFORE | ITEM_OBJECT_FLAG_DEFLECTED | ITEM_OBJECT_FLAG_HIT_THIS_STEP);
}

// One step: moves by the velocity and reflects it at a surface while bounces are left.
void AdvanceBouncingItem(BouncingItemObject *item, s32 gravity, s32 velocityFactor, s32 reflectFactor,
                         u32 *collisionHitLink) {
    Vec3 offset;
    Vec3 hitNormal;
    Vec3 wallNormal;
    Vec3 *velocity;
    Vec3 *pos;
    s32 value;

    velocity = &item->mItemObject.mVelocity;
    pos = &item->mItemObject.mPos;
    VEC_Add(velocity, pos, pos);
    velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, velocityFactor);
    velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, velocityFactor);
    velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, velocityFactor);
    if (CollideSphereWithCourse(pos, &item->mItemObject.mPrevPos, 0, item->mItemObject.mCourseRadius, 0x24,
                                item->mItemObject.mCollisionSlotIndex, &offset, &hitNormal, &wallNormal,
                                &item->mItemObject.mCollisionBits, NULL, NULL, NULL, collisionHitLink) != 0) {
        VEC_Add(&offset, pos, pos);
        if (item->mItemObject.mCollisionBits & COURSE_HIT_GROUND) {
            value = item->mBouncesRemaining;
            item->mBouncesRemaining = value - 1;
            if (value <= 0) {
                LandItemObjectIfOnGround(&item->mItemObject, pos, velocity, gravity, &hitNormal);
            } else {
                item->mItemObject.mFlags |= ITEM_OBJECT_FLAG_BOUNCED_OFF_GROUND;
                value = VEC_DotProduct(&hitNormal, velocity);
                offset.x = MUL_FIXED12_NO_ROUND(hitNormal.x, value);
                offset.y = MUL_FIXED12_NO_ROUND(hitNormal.y, value);
                offset.z = MUL_FIXED12_NO_ROUND(hitNormal.z, value);
                velocity->x -= offset.x;
                velocity->y -= offset.y;
                velocity->z -= offset.z;
                velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, 0x8cd);
                velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, 0x8cd);
                velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0x8cd);
                VEC_MultAdd(-reflectFactor, &offset, velocity, velocity);
                item->mItemObject.mNormal = hitNormal;
            }
        }
        if (item->mItemObject.mCollisionBits & COURSE_HIT_WALL) {
            item->mItemObject.mFlags |= ITEM_OBJECT_FLAG_HIT_WALL;
            BounceItemVelocityOffSurface(velocity, &wallNormal);
            if (TryFadeOutDeflectedItemObject(&item->mItemObject, &wallNormal) != FALSE) {
                return;
            }
            item->mItemObject.mOwnerKartIndexAndFlags &= ~ITEM_OWNER_EXCLUDED;
        }
        if (item->mItemObject.mCollisionBits & COURSE_HIT_KEYED_PLACEMENT_OR_FADE) {
            FadeOutItemObjectNoCallback(&item->mItemObject, 1);
            return;
        }
    }
    item->mItemObject.mFlags &= ~ITEM_OBJECT_FLAG_HIT_THIS_STEP;
    if (item->mItemObject.mCollisionBits & COURSE_HIT_GROUND) {
        return;
    }
    velocity->y -= gravity;
    if (velocity->y < -0xa000) {
        velocity->y = -0xa000;
    }
}

// Hit handler of bouncing items: reflects the velocity about the surface normal.
void BounceItemObject(ItemObject *item, Vec3 *unused, Vec3 *awayDirection) {
    BounceItemVelocityOffSurface(&item->mVelocity, awayDirection);
    if (item->mFlags & ITEM_OBJECT_FLAG_BOUNCED_BEFORE) {
        return;
    }
    item->mFlags |= ITEM_OBJECT_FLAG_BOUNCED_BEFORE;
    item->mCoursePointOrParams.x = 0;
    item->mCoursePointOrParams.y = 0;
    item->mCoursePointOrParams.z = 0;
}
