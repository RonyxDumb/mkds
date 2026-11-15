#include "Main/Item/held_item.h"

#include "Main/Item/item_in_use.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/code_020f9334.h"
#include "ITCM/code_01ffd000.h"
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
#include "code_02147cd8.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_f_box.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const u16 gItemObjectPendingUpdateBit = ITEM_OBJECT_PENDING_UPDATE_CATCH_UP;
const ItemSpreadRow gItemSpreadRows[3] = {{{{0x1000, 0}, {0, 0}, {0, 0}}},
                                          {{{-2048, 0xddb}, {-2048, -3547}, {0, 0}}},
                                          {{{0x1000, 0}, {-2048, 0xddb}, {-2048, -3547}}}};
s32 gItemPointLinksByIndex[4];

// Runs the countdown that starts the held objects, then counts the use timer down and, when it ends, takes one object
// off the held item.
void UpdateHeldItem(HeldItem *rec) {
    s32 objectIndex;
    u32 objectKind;
    ItemInfoIndex kind;
    s32 reservedCount;

    StartNextHeldItemObject(rec);
    if (rec->mUsesTimer == 0) {
        return;
    }
    if (rec->mTimer == 0) {
        return;
    }
    if (rec->mObjectStartFramesLeft != 0) {
        return;
    }
    rec->mTimer -= 1;
    if (rec->mTimer != 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        if (gRaceSetup->mEntryIndex == rec->mKartItems->mKartIndex) {
            kind = (ItemInfoIndex) rec->mItemInfoIndex;
            AddItemDataFrameOnly(gItemInfos[kind].mObjectKind);
        }
    }
    rec->mObjectCount -= 1;
    objectKind = gItemInfos[rec->mItemInfoIndex].mObjectKind;
    reservedCount = gItemPools[objectKind].mReservedCount;
    GetItemPool(objectKind)->mReservedCount = reservedCount - 1;
    if (rec->mObjectCount == 0) {
        rec->mItemInfoIndex = ITEM_INFO_NONE;
        rec->mObjectCount = 0;
        rec->mObjectStartFramesLeft = 0;
        rec->mUsesTimer = 0;
        rec->mTimer = 0;
        rec->mUseTimerLimit = 0;
        for (objectIndex = 0; objectIndex < 3; objectIndex++) {
            rec->mObjects[objectIndex] = NULL;
        }
    }
}

// Makes the item held and reserves its objects in the item's pool.
void SetHeldItem(HeldItem *rec, s32 kind) {
    u32 objectCountOrKind;
    s32 reservedCount;

    objectCountOrKind = gItemInfos[kind].mObjectCount;
    rec->mItemInfoIndex = kind;
    rec->mObjectCount = objectCountOrKind;
    rec->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(rec->mKartItems->mKart);
    rec->mUsesTimer = gItemInfos[kind].mUsesTimer;
    rec->mTimer = 0;
    rec->mUseTimerLimit = 0;
    objectCountOrKind = gItemInfos[kind].mObjectKind;
    reservedCount = gItemPools[objectCountOrKind].mReservedCount;
    GetItemPool(objectCountOrKind)->mReservedCount = reservedCount + rec->mObjectCount;
}

void RemoveHeldItemObjects(HeldItem *rec, s32 amount) {
    s32 objectIndex;
    int objectKind;

    rec->mObjectCount -= amount;
    objectKind = gItemInfos[rec->mItemInfoIndex].mObjectKind;
    GetItemPool(objectKind)->mReservedCount = gItemPools[objectKind].mReservedCount - amount;
    if (rec->mObjectCount == 0) {
        rec->mItemInfoIndex = ITEM_INFO_NONE;
        rec->mObjectCount = 0;
        rec->mObjectStartFramesLeft = 0;
        rec->mUsesTimer = 0;
        rec->mTimer = 0;
        rec->mUseTimerLimit = 0;
        for (objectIndex = 0; objectIndex < 3; objectIndex++) {
            rec->mObjects[objectIndex] = NULL;
        }
    }
}

void ResetHeldItem(HeldItem *rec) {
    s32 slotIndex;

    rec->mItemInfoIndex = ITEM_INFO_NONE;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUsesTimer = 0;
    rec->mTimer = 0;
    rec->mUseTimerLimit = 0;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        rec->mObjects[slotIndex] = NULL;
    }
}

// Gives the held objects back to the pool, or the reserved count unless keep is set, then empties the record.
void ReleaseHeldItem(HeldItem *rec, s32 keep) {
    s32 reservedCount;
    s32 objectIndex;
    s32 objectCount;
    s32 releaseIndex;
    s32 startedObjectCount;
    ItemInfoIndex kind = (ItemInfoIndex) rec->mItemInfoIndex;
    u32 poolIndex = gItemInfos[kind].mObjectKind;

    if (gRaceSetup->mMode == MODE_WIFI) {
        objectCount = rec->mObjectCount;
        if (rec->mIsPeerEntry == FALSE) {
            for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
                AddItemDataNoItemId(poolIndex);
            }
        }
    }
    if (rec->mObjectStartFramesLeft != 0) {
        startedObjectCount = rec->mObjectCount;
        for (releaseIndex = 0; releaseIndex < startedObjectCount; releaseIndex++) {
            ReleaseItemPoolObject(&gItemPools[rec->mObjects[releaseIndex]->mKind], rec->mObjects[releaseIndex]);
        }
    } else if (keep == 0) {
        reservedCount = gItemPools[poolIndex].mReservedCount;
        GetItemPool(poolIndex)->mReservedCount = reservedCount - rec->mObjectCount;
    }
    rec->mItemInfoIndex = ITEM_INFO_NONE;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUsesTimer = 0;
    rec->mTimer = 0;
    rec->mUseTimerLimit = 0;
    for (objectIndex = 0; objectIndex < 3; objectIndex++) {
        rec->mObjects[objectIndex] = NULL;
    }
}

static inline u32 TakeHeldItemObjects_inline(RandomState64 *generator, u32 range) {
    generator->mValue = generator->mMultiplier * generator->mValue + generator->mIncrement;
    if (range == 0) {
        return generator->mValue >> 32;
    } else {
        return ((generator->mValue >> 32) * range) >> 32;
    }
}

// Takes the held objects from their pool and gives each a starting velocity.
void TakeHeldItemObjects(HeldItem *rec) {
    Kart *owner = rec->mKartItems->mKart;
    CourseColorBlend *halves = &owner->mKartModelsEntry->mCourseColorBlend;
    Vec3 *dir = &owner->mDrawBaseRow2;
    Vec3 *axis = &owner->mDrawBaseRow0;
    s32 slotIndex;
    s32 count;
    RandomState64 *generator;
    const ItemSpreadRow *row;
    ItemObject *object;
    s32 kind = rec->mItemInfoIndex;
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
    angle = (u16) TakeHeldItemObjects_inline(generator, 0x10000);
    poolIndex = gItemInfos[kind].mObjectKind;
    if (gItemKinds[poolIndex].mStartsFalling != 0) {
        radius = 0x2000;
    } else {
        radius = 0x1800;
    }
    count = rec->mObjectCount;
    radiusTimesAnglePairFirst = MUL_FIXED12_NO_ROUND(radius, SIN_OF_ANGLE(angle));
    radiusTimesAnglePairSecond = MUL_FIXED12_NO_ROUND(radius, COS_OF_ANGLE(angle));
    TakeItemPoolObjects(&gItemPools[poolIndex], count, rec->mObjects, owner->mIndex, &owner->mDrawMatrixPos);
    slotIndex = 0;
    if (slotIndex < count) {
        row = &gItemSpreadRows[count - 1];
        do {
            rowX = row->mOffsets[slotIndex].mX;
            rowY = row->mOffsets[slotIndex].mY;
            rowXJittered = MUL_FIXED12_NO_ROUND(rowX, 0x1000 + (s32) TakeHeldItemObjects_inline(generator, 0x333));
            rowYJittered = MUL_FIXED12_NO_ROUND(rowY, 0x1000 + (s32) TakeHeldItemObjects_inline(generator, 0x333));
            directionAmount = MUL_FIXED12_NO_ROUND(rowXJittered, radiusTimesAnglePairSecond) -
                              MUL_FIXED12_NO_ROUND(rowYJittered, radiusTimesAnglePairFirst);
            object = rec->mObjects[slotIndex];
            object->mVelocity.x = MUL_FIXED12_NO_ROUND(dir->x, directionAmount);
            object->mVelocity.y = MUL_FIXED12_NO_ROUND(dir->y, directionAmount);
            object->mVelocity.z = MUL_FIXED12_NO_ROUND(dir->z, directionAmount);
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(rowYJittered, radiusTimesAnglePairSecond) +
                            MUL_FIXED12_NO_ROUND(directionAmount, radiusTimesAnglePairFirst),
                        axis, &object->mVelocity, &object->mVelocity);
            object->mScale.x = 0xcd;
            object->mScale.y = 0xcd;
            object->mScale.z = 0xcd;
            object->mColorBlend = *halves;
            slotIndex++;
        } while (slotIndex < count);
    }
}

// Takes the held objects and starts the countdown that starts them one at a time.
void StartHeldItemObjects(HeldItem *rec) {
    rec->mObjectStartFramesLeft = HELD_ITEM_OBJECT_START_FRAMES;
    TakeHeldItemObjects(rec);
}

BOOL StartHeldItemTimer(HeldItem *rec, s32 frames) {
    if (rec->mTimer != 0) {
        return FALSE;
    }
    rec->mTimer = frames;
    return TRUE;
}

// The held item can be used again once the timer has counted down by this many frames.
void SetHeldItemUseDelay(HeldItem *rec, s32 frames) {
    rec->mUseTimerLimit = rec->mTimer - frames;
}

void RemoveHeldItem(HeldItem *rec, s32 *kind, s32 *count) {
    s32 slotIndex;

    *kind = rec->mItemInfoIndex;
    *count = rec->mObjectCount;
    rec->mItemInfoIndex = ITEM_INFO_NONE;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUsesTimer = 0;
    rec->mTimer = 0;
    rec->mUseTimerLimit = 0;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        rec->mObjects[slotIndex] = NULL;
    }
}

// Like SetHeldItem, but the count comes from the caller and nothing is reserved in the pool.
void SetHeldItemWithCount(HeldItem *rec, s32 kind, s32 count) {
    rec->mItemInfoIndex = kind;
    rec->mObjectCount = count;
    rec->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(rec->mKartItems->mKart);
    rec->mUsesTimer = gItemInfos[kind].mUsesTimer;
    rec->mTimer = 0;
    rec->mUseTimerLimit = 0;
}

void RemoveReservedItemObjects(s32 itemInfoIndex, s32 amount) {
    int objectKind = gItemInfos[itemInfoIndex].mObjectKind;

    GetItemPool(objectKind)->mReservedCount = gItemPools[objectKind].mReservedCount - amount;
}

s32 GetItemPointLinkByIndex(s32 idx) {
    return gItemPointLinksByIndex[idx];
}

void InitSegmentPoints(SegmentPoints *segmentPoints, const Vec3 *points, s32 scale) {
    s32 pointIndex;

    for (pointIndex = 0; pointIndex < 4; pointIndex++) {
        segmentPoints->mPointPointers[pointIndex] = &segmentPoints->mPoints[pointIndex];
        segmentPoints->mPoints[pointIndex] = points[pointIndex];
    }
    segmentPoints->mWriteIndex = 0;
    InitSegmentProgress(&segmentPoints->mSegmentProgress, 1, segmentPoints->mPointPointers, scale);
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
    ItemPointLink *node = in->mLink;
    ItemPointLink *best;
    ItemPointLink *nextLink;
    ItemPointLink *linkAroundNext;
    Vec3 *linkPos = node->mPointPos;
    s32 nextCount;
    ItemPointLink *previousLink;
    ItemPointLink *linkAroundPrevious;
    Vec3 *previousLinkPos;
    s32 previousCount;
    s32 distanceSquared;
    s32 deltaX;
    s32 deltaY;
    s32 deltaZ;
    s32 bestDist;
    s32 linkIndex;
    s32 firstAroundIndex;
    s32 secondAroundIndex;
    Vec3 *posAlias = pos;
    ItemPointLink *nodeAlias = node;

    best = node;
    deltaX = FROM_FIXED12(linkPos->x - pos->x);
    deltaY = FROM_FIXED12(linkPos->y - pos->y);
    deltaZ = FROM_FIXED12(linkPos->z - pos->z);
    bestDist = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    for (linkIndex = 0; linkIndex < nodeAlias->mNextCount; linkIndex++) {
        nextLink = node->mNextLinks[linkIndex];
        if (nextLink != NULL) {
            linkPos = nextLink->mPointPos;
            deltaX = FROM_FIXED12(linkPos->x - pos->x);
            deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
            deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
            distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
            nextCount = nextLink->mNextCount;
            if (distanceSquared < bestDist) {
                bestDist = distanceSquared;
                best = nextLink;
            }
            for (firstAroundIndex = 0; firstAroundIndex < nextCount; firstAroundIndex++) {
                linkAroundNext = nextLink->mNextLinks[firstAroundIndex];
                linkPos = linkAroundNext->mPointPos;
                deltaX = FROM_FIXED12(linkPos->x - pos->x);
                deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
                deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDist) {
                    bestDist = distanceSquared;
                    best = linkAroundNext;
                }
            }
            previousCount = nextLink->mPreviousCount;
            for (secondAroundIndex = 0; secondAroundIndex < previousCount; secondAroundIndex++) {
                linkAroundNext = nextLink->mPreviousLinks[secondAroundIndex];
                if (linkAroundNext != node) {
                    linkPos = linkAroundNext->mPointPos;
                    deltaX = FROM_FIXED12(linkPos->x - pos->x);
                    deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
                    deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
                    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                    if (distanceSquared < bestDist) {
                        bestDist = distanceSquared;
                        best = linkAroundNext;
                    }
                }
            }
        }
    }
    for (linkIndex = 0; linkIndex < nodeAlias->mPreviousCount; linkIndex++) {
        previousLink = node->mPreviousLinks[linkIndex];
        if (previousLink != NULL) {
            previousLinkPos = previousLink->mPointPos;
            deltaX = FROM_FIXED12(previousLinkPos->x - pos->x);
            deltaY = FROM_FIXED12(previousLinkPos->y - posAlias->y);
            deltaZ = FROM_FIXED12(previousLinkPos->z - posAlias->z);
            distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
            previousCount = previousLink->mPreviousCount;
            if (distanceSquared < bestDist) {
                bestDist = distanceSquared;
                best = previousLink;
            }
            for (firstAroundIndex = 0; firstAroundIndex < previousCount; firstAroundIndex++) {
                linkAroundPrevious = previousLink->mPreviousLinks[firstAroundIndex];
                previousLinkPos = linkAroundPrevious->mPointPos;
                deltaX = FROM_FIXED12(previousLinkPos->x - pos->x);
                deltaY = FROM_FIXED12(previousLinkPos->y - posAlias->y);
                deltaZ = FROM_FIXED12(previousLinkPos->z - posAlias->z);
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDist) {
                    bestDist = distanceSquared;
                    best = linkAroundPrevious;
                }
            }
            nextCount = previousLink->mNextCount;
            for (secondAroundIndex = 0; secondAroundIndex < nextCount; secondAroundIndex++) {
                linkAroundPrevious = previousLink->mNextLinks[secondAroundIndex];
                if (linkAroundPrevious != node) {
                    previousLinkPos = linkAroundPrevious->mPointPos;
                    deltaX = FROM_FIXED12(previousLinkPos->x - pos->x);
                    deltaY = FROM_FIXED12(previousLinkPos->y - posAlias->y);
                    deltaZ = FROM_FIXED12(previousLinkPos->z - posAlias->z);
                    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                    if (distanceSquared < bestDist) {
                        bestDist = distanceSquared;
                        best = linkAroundPrevious;
                    }
                }
            }
        }
    }
    out->mLink = best;
    out->mNextLinksUsed = 1;
    return best != node;
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
    ItemPointLink *node = in->mLink;
    s32 distanceSquared;
    Vec3 *linkPos;
    s32 deltaY;
    Vec3 *posAlias;
    s32 deltaX;
    s32 startDistanceSquared;
    s32 stepsLeft;
    s32 deltaZ;
    ItemPointLink *child;
    ItemPointLink *current;
    ItemPointLink *best;
    s32 bestDist;
    s32 childIndex;

    linkPos = node->mPointPos;
    deltaX = FROM_FIXED12(linkPos->x - pos->x);
    deltaY = FROM_FIXED12(linkPos->y - pos->y);
    deltaZ = FROM_FIXED12(linkPos->z - pos->z);
    startDistanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    stepsLeft = gCourseMap->mItemPointCount;
    posAlias = pos;

    current = node;
    do {
        best = NULL;
        bestDist = 0x7fffffff;
        for (childIndex = 0; childIndex < current->mNextCount; childIndex++) {
            child = current->mNextLinks[childIndex];
            if (child != NULL) {
                linkPos = child->mPointPos;
                deltaX = FROM_FIXED12(linkPos->x - pos->x);
                deltaY = FROM_FIXED12(linkPos->y - posAlias->y);
                deltaZ = FROM_FIXED12(linkPos->z - posAlias->z);
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDist) {
                    bestDist = distanceSquared;
                    best = child;
                }
            }
        }
        if (bestDist < startDistanceSquared) {
            out->mLink = best;
            out->mNextLinksUsed = 1;
            return best != node;
        }
        stepsLeft--;
        current = best;
    } while (stepsLeft > 1 && best != node);
    out->mLink = node;
    out->mNextLinksUsed = 1;
    return FALSE;
}

// Writes the link to go on to, leaning toward kart idx when it is close.
void PickNextItemPointLink(ItemPointLinkRef *in, ItemPointLinkRef *out, u32 idx, s32 flag) {
    ItemPointLink *node = in->mLink;
    s32 side = in->mNextLinksUsed;
    ItemPointLink *cur;
    ItemPointLink *child;
    s32 secondCount;
    s32 linkCount;
    Vec3 *origin;
    BOOL found;
    s32 bestDistanceSquared;
    ItemPointLink *bestSecondLink;
    Vec3 *pos;
    s32 childIndex;
    Vec3 *childPos;
    Kart *other;
    s32 distance;

    if (side != 0) {
        linkCount = node->mNextCount;
        cur = node->mNextLinks[0];
    } else {
        linkCount = node->mPreviousCount;
        cur = node->mPreviousLinks[0];
    }
    if (linkCount <= 1 && (side != 0 ? cur->mPreviousCount : cur->mNextCount) <= 1) {
    done:
        out->mLink = cur;
        out->mNextLinksUsed = side;
        return;
    }
    origin = node->mPointPos;
    found = FALSE;
    bestDistanceSquared = 0x5f592e1;
    if (idx < 8) {
        other = GetKart(idx);
        pos = &other->mDrawMatrixPos;
        {
            s64 sq = (s64) (((const Vec3 *) pos)->x - ((const Vec3 *) origin)->x) *
                     (((const Vec3 *) pos)->x - ((const Vec3 *) origin)->x);
            sq += (s64) (((const Vec3 *) pos)->z - ((const Vec3 *) origin)->z) *
                  (((const Vec3 *) pos)->z - ((const Vec3 *) origin)->z);
            if (sq < 0x225510000000LL) {
                found = TRUE;
                for (childIndex = 0; childIndex < linkCount; childIndex++) {
                    child = side != 0 ? node->mNextLinks[childIndex] : node->mPreviousLinks[childIndex];
                    if (child != NULL) {
                        childPos = child->mPointPos;
                        distance = FROM_FIXED12(pos->x - origin->x) * FROM_FIXED12(childPos->x - origin->x);
                        distance += FROM_FIXED12(pos->z - origin->z) * FROM_FIXED12(childPos->z - origin->z);
                        if (distance > 0) {
                            distance =
                                FROM_FIXED12(child->mPointPos->x - pos->x) * FROM_FIXED12(child->mPointPos->x - pos->x);
                            distance +=
                                FROM_FIXED12(child->mPointPos->y - pos->y) * FROM_FIXED12(child->mPointPos->y - pos->y);
                            distance +=
                                FROM_FIXED12(child->mPointPos->z - pos->z) * FROM_FIXED12(child->mPointPos->z - pos->z);
                            if (distance < bestDistanceSquared) {
                                bestDistanceSquared = distance;
                                cur = child;
                            }
                        }
                    }
                }
            }
        }
    }
    if (side == 0 || (found != FALSE && flag != 0)) {
        if ((side != 0 ? cur->mPreviousCount : cur->mNextCount) > 1) {
            bestSecondLink = NULL;
            secondCount = side != 0 ? cur->mPreviousCount : cur->mNextCount;
            for (childIndex = 0; childIndex < secondCount; childIndex++) {
                child = side != 0 ? cur->mPreviousLinks[childIndex] : cur->mNextLinks[childIndex];
                if (child != NULL && child != node) {
                    if (found != FALSE) {
                        childPos = child->mPointPos;
                        distance = FROM_FIXED12(pos->x - origin->x) * FROM_FIXED12(childPos->x - origin->x);
                        distance += FROM_FIXED12(pos->z - origin->z) * FROM_FIXED12(childPos->z - origin->z);
                        if (distance > 0) {
                            distance =
                                FROM_FIXED12(child->mPointPos->x - pos->x) * FROM_FIXED12(child->mPointPos->x - pos->x);
                            distance +=
                                FROM_FIXED12(child->mPointPos->y - pos->y) * FROM_FIXED12(child->mPointPos->y - pos->y);
                            distance +=
                                FROM_FIXED12(child->mPointPos->z - pos->z) * FROM_FIXED12(child->mPointPos->z - pos->z);
                            if (distance < bestDistanceSquared) {
                                bestDistanceSquared = distance;
                                bestSecondLink = child;
                            }
                        }
                    } else {
                        cur = child;
                        side = 1;
                        goto done;
                    }
                }
            }
            if (bestSecondLink != NULL) {
                cur = bestSecondLink;
                side = side == 0 ? 1 : 0;
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

// Sets each link's direction to its first next link; also fills gItemPointLinksByIndex.
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

static inline u32 ThrowBouncingItem_inline(RandomState64 *generator, u32 range) {
    generator->mValue = generator->mMultiplier * generator->mValue + generator->mIncrement;
    return ((u64) (u32) (generator->mValue >> 32) * range) >> 32;
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
    if (itemInUse->mKartVelocityLength < ITEM_THROW_RANDOM_SPREAD_KART_SPEED) {
        direction.z += ThrowBouncingItem_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
        direction.x += ThrowBouncingItem_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
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
                item->mItemObject.mFlags |= ITEM_OBJECT_FLAG_BOUNCED;
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
        if (item->mItemObject.mCollisionBits & COURSE_HIT_FADES_ITEMS) {
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
