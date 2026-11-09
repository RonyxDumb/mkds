#include "Main/Unknown/code_020f2dac.h"

#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f3678.h"
#include "Main/Unknown/code_020f36a0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02077bc0.h"

// Runs the countdown that starts the held objects, then counts the use timer down and, when it ends, takes one object
// off the held item.
void UpdateHeldItem(HeldItem *rec) {
    s32 i;
    u32 objectKind;
    Unk020f40dc_Kind kind;
    s32 reservedCount;

    StartNextHeldItemObject(rec);
    if (rec->mUnk_0c == 0) {
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
    if (gRaceSetup->mMode == 5) {
        if (gRaceSetup->mEntryIndex == rec->mKartItems->mKartIndex) {
            kind = (Unk020f40dc_Kind) rec->mItemInfoIndex;
            AddItemDataFrameOnly(gItemInfos[kind].mObjectKind);
        }
    }
    rec->mObjectCount -= 1;
    objectKind = gItemInfos[rec->mItemInfoIndex].mObjectKind;
    reservedCount = gItemPools[objectKind].mReservedCount;
    gItemPools[(s32) objectKind].mReservedCount = reservedCount - 1;
    if (rec->mObjectCount == 0) {
        rec->mItemInfoIndex = 0x13;
        rec->mObjectCount = 0;
        rec->mObjectStartFramesLeft = 0;
        rec->mUnk_0c = 0;
        rec->mTimer = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mObjects[i] = NULL;
        }
    }
}

// Makes the item held and reserves its objects in the item's pool.
void SetHeldItem(HeldItem *rec, s32 kind) {
    u32 k;
    s32 reservedCount;

    k = gItemInfos[kind].mObjectCount;
    rec->mItemInfoIndex = kind;
    rec->mObjectCount = k;
    rec->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(rec->mKartItems->mKart);
    rec->mUnk_0c = gItemInfos[kind].mUnk_10;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    k = gItemInfos[kind].mObjectKind;
    reservedCount = gItemPools[k].mReservedCount;
    gItemPools[(s32) k].mReservedCount = reservedCount + rec->mObjectCount;
}

void RemoveHeldItemObjects(HeldItem *rec, s32 n) {
    s32 i;
    int objectKind;

    rec->mObjectCount -= n;
    objectKind = gItemInfos[rec->mItemInfoIndex].mObjectKind;
    gItemPools[(s32) objectKind].mReservedCount = gItemPools[objectKind].mReservedCount - n;
    if (rec->mObjectCount == 0) {
        rec->mItemInfoIndex = 0x13;
        rec->mObjectCount = 0;
        rec->mObjectStartFramesLeft = 0;
        rec->mUnk_0c = 0;
        rec->mTimer = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mObjects[i] = NULL;
        }
    }
}

void ResetHeldItem(HeldItem *rec) {
    s32 i;

    rec->mItemInfoIndex = 0x13;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUnk_0c = 0;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mObjects[i] = NULL;
    }
}

// Gives the held objects back to the pool, or the reserved count unless keep is set, then empties the record.
void ReleaseHeldItem(HeldItem *rec, s32 keep) {
    s32 reservedCount;
    s32 i;
    s32 objectCount;
    s32 j;
    s32 m;
    Unk020f40dc_Kind kind = (Unk020f40dc_Kind) rec->mItemInfoIndex;
    u32 poolIndex = gItemInfos[kind].mObjectKind;

    if (gRaceSetup->mMode == 5) {
        objectCount = rec->mObjectCount;
        if (rec->mUnk_24 == FALSE) {
            for (i = 0; i < objectCount; i++) {
                AddItemDataNoItemId(poolIndex);
            }
        }
    }
    if (rec->mObjectStartFramesLeft != 0) {
        m = rec->mObjectCount;
        for (j = 0; j < m; j++) {
            ReleaseItemPoolObject(&gItemPools[rec->mObjects[j]->mKind], rec->mObjects[j]);
        }
    } else if (keep == 0) {
        reservedCount = gItemPools[poolIndex].mReservedCount;
        gItemPools[(s32) poolIndex].mReservedCount = reservedCount - rec->mObjectCount;
    }
    rec->mItemInfoIndex = 0x13;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUnk_0c = 0;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mObjects[i] = NULL;
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
    Vec3 *dir = &owner->mUnk_168;
    Vec3 *axis = &owner->mUnk_150;
    s32 i;
    s32 count;
    RandomState64 *generator;
    ItemSpreadRow *row;
    ItemObject *object;
    s32 kind = rec->mItemInfoIndex;
    s32 poolIndex;
    s32 radius;
    s32 angle;
    s32 va;
    s32 vb;
    s32 w1;
    s32 w2;
    s32 d;
    s32 rowX;
    s32 rowY;

    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        generator = &gRaceProgress->mLocalRandom;
    } else {
        generator = &gRaceProgress->mRandom;
    }
    angle = (u16) TakeHeldItemObjects_inline(generator, 0x10000);
    angle >>= 4;
    poolIndex = gItemInfos[kind].mObjectKind;
    if (gItemKinds[poolIndex].mUnk_80 != 0) {
        radius = 0x2000;
    } else {
        radius = 0x1800;
    }
    count = rec->mObjectCount;
    va = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[angle * 2]);
    vb = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[angle * 2 + 1]);
    TakeItemPoolObjects(&gItemPools[poolIndex], count, rec->mObjects, owner->mIndex, &owner->mDrawMatrixPos);
    i = 0;
    if (i < count) {
        row = &gItemSpreadRows[count - 1];
        do {
            rowX = row->mUnk_00[i].mUnk_00;
            rowY = row->mUnk_00[i].mUnk_04;
            w1 = MUL_FIXED12_NO_ROUND(rowX, 0x1000 + (s32) TakeHeldItemObjects_inline(generator, 0x333));
            w2 = MUL_FIXED12_NO_ROUND(rowY, 0x1000 + (s32) TakeHeldItemObjects_inline(generator, 0x333));
            d = MUL_FIXED12_NO_ROUND(w1, vb) - MUL_FIXED12_NO_ROUND(w2, va);
            object = rec->mObjects[i];
            object->mVelocity.x = MUL_FIXED12_NO_ROUND(dir->x, d);
            object->mVelocity.y = MUL_FIXED12_NO_ROUND(dir->y, d);
            object->mVelocity.z = MUL_FIXED12_NO_ROUND(dir->z, d);
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(w2, vb) + MUL_FIXED12_NO_ROUND(d, va), axis,
                        &object->mVelocity, &object->mVelocity);
            object->mScale.x = 0xcd;
            object->mScale.y = 0xcd;
            object->mScale.z = 0xcd;
            object->mColorBlend = *halves;
            i++;
        } while (i < count);
    }
}

// Takes the held objects and starts the countdown that starts them one at a time.
void StartHeldItemObjects(HeldItem *rec) {
    rec->mObjectStartFramesLeft = 10;
    TakeHeldItemObjects(rec);
}

BOOL StartHeldItemTimer(HeldItem *rec, s32 v) {
    if (rec->mTimer != 0) {
        return FALSE;
    }
    rec->mTimer = v;
    return TRUE;
}

void func_020f4188(HeldItem *rec, s32 v) {
    rec->mUnk_12 = rec->mTimer - v;
}

void RemoveHeldItem(HeldItem *rec, s32 *kind, s32 *count) {
    s32 i;

    *kind = rec->mItemInfoIndex;
    *count = rec->mObjectCount;
    rec->mItemInfoIndex = 0x13;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUnk_0c = 0;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mObjects[i] = NULL;
    }
}

// Like SetHeldItem, but the count comes from the caller and nothing is reserved in the pool.
void SetHeldItemWithCount(HeldItem *rec, s32 kind, s32 count) {
    rec->mItemInfoIndex = kind;
    rec->mObjectCount = count;
    rec->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(rec->mKartItems->mKart);
    rec->mUnk_0c = gItemInfos[kind].mUnk_10;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
}

void RemoveReservedItemObjects(s32 itemInfoIndex, s32 amount) {
    int objectKind = gItemInfos[itemInfoIndex].mObjectKind;

    gItemPools[(s32) objectKind].mReservedCount = gItemPools[objectKind].mReservedCount - amount;
}

s32 func_020f4090(s32 idx) {
    return data_0217bc38[idx];
}

void InitSegmentPoints(SegmentPoints *segmentPoints, Vec3 *points, s32 scale) {
    s32 i;

    for (i = 0; i < 4; i++) {
        segmentPoints->mPointPointers[i] = &segmentPoints->mPoints[i];
        segmentPoints->mPoints[i] = points[i];
    }
    segmentPoints->mWriteIndex = 0;
    InitSegmentProgress(&segmentPoints->mSegmentProgress, 1, segmentPoints->mPointPointers, scale);
}

s32 PushSegmentPoint(SegmentPoints *segmentPoints, Vec3 *point) {
    Vec3 *first;

    segmentPoints->mPoints[segmentPoints->mWriteIndex] = *point;
    segmentPoints->mWriteIndex += 1;
    segmentPoints->mWriteIndex &= 3;
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
    s32 i;
    s32 j;
    s32 k;
    Vec3 *posAlias = pos;
    ItemPointLink *nodeAlias = node;

    best = node;
    deltaX = (linkPos->x - pos->x) >> 12;
    deltaY = (linkPos->y - pos->y) >> 12;
    deltaZ = (linkPos->z - pos->z) >> 12;
    bestDist = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    for (i = 0; i < nodeAlias->mNextCount; i++) {
        nextLink = node->mNextLinks[i];
        if (nextLink != NULL) {
            linkPos = nextLink->mPointPos;
            deltaX = (linkPos->x - pos->x) >> 12;
            deltaY = (linkPos->y - posAlias->y) >> 12;
            deltaZ = (linkPos->z - posAlias->z) >> 12;
            distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
            nextCount = nextLink->mNextCount;
            if (distanceSquared < bestDist) {
                bestDist = distanceSquared;
                best = nextLink;
            }
            for (j = 0; j < nextCount; j++) {
                linkAroundNext = nextLink->mNextLinks[j];
                linkPos = linkAroundNext->mPointPos;
                deltaX = (linkPos->x - pos->x) >> 12;
                deltaY = (linkPos->y - posAlias->y) >> 12;
                deltaZ = (linkPos->z - posAlias->z) >> 12;
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDist) {
                    bestDist = distanceSquared;
                    best = linkAroundNext;
                }
            }
            previousCount = nextLink->mPreviousCount;
            for (k = 0; k < previousCount; k++) {
                linkAroundNext = nextLink->mPreviousLinks[k];
                if (linkAroundNext != node) {
                    linkPos = linkAroundNext->mPointPos;
                    deltaX = (linkPos->x - pos->x) >> 12;
                    deltaY = (linkPos->y - posAlias->y) >> 12;
                    deltaZ = (linkPos->z - posAlias->z) >> 12;
                    distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                    if (distanceSquared < bestDist) {
                        bestDist = distanceSquared;
                        best = linkAroundNext;
                    }
                }
            }
        }
    }
    for (i = 0; i < nodeAlias->mPreviousCount; i++) {
        previousLink = node->mPreviousLinks[i];
        if (previousLink != NULL) {
            previousLinkPos = previousLink->mPointPos;
            deltaX = (previousLinkPos->x - pos->x) >> 12;
            deltaY = (previousLinkPos->y - posAlias->y) >> 12;
            deltaZ = (previousLinkPos->z - posAlias->z) >> 12;
            distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
            previousCount = previousLink->mPreviousCount;
            if (distanceSquared < bestDist) {
                bestDist = distanceSquared;
                best = previousLink;
            }
            for (j = 0; j < previousCount; j++) {
                linkAroundPrevious = previousLink->mPreviousLinks[j];
                previousLinkPos = linkAroundPrevious->mPointPos;
                deltaX = (previousLinkPos->x - pos->x) >> 12;
                deltaY = (previousLinkPos->y - posAlias->y) >> 12;
                deltaZ = (previousLinkPos->z - posAlias->z) >> 12;
                distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
                if (distanceSquared < bestDist) {
                    bestDist = distanceSquared;
                    best = linkAroundPrevious;
                }
            }
            nextCount = previousLink->mNextCount;
            for (k = 0; k < nextCount; k++) {
                linkAroundPrevious = previousLink->mNextLinks[k];
                if (linkAroundPrevious != node) {
                    previousLinkPos = linkAroundPrevious->mPointPos;
                    deltaX = (previousLinkPos->x - pos->x) >> 12;
                    deltaY = (previousLinkPos->y - posAlias->y) >> 12;
                    deltaZ = (previousLinkPos->z - posAlias->z) >> 12;
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
    s32 currentDistanceSquared = ((currentPos->x - pos->x) >> 12) * ((currentPos->x - pos->x) >> 12) +
                                 ((currentPos->y - pos->y) >> 12) * ((currentPos->y - pos->y) >> 12) +
                                 ((currentPos->z - pos->z) >> 12) * ((currentPos->z - pos->z) >> 12);
    s32 candidateDistanceSquared = ((candidatePos->x - pos->x) >> 12) * ((candidatePos->x - pos->x) >> 12) +
                                   ((candidatePos->y - pos->y) >> 12) * ((candidatePos->y - pos->y) >> 12) +
                                   ((candidatePos->z - pos->z) >> 12) * ((candidatePos->z - pos->z) >> 12);

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
    s32 i;

    linkPos = node->mPointPos;
    deltaX = (linkPos->x - pos->x) >> 12;
    deltaY = (linkPos->y - pos->y) >> 12;
    deltaZ = (linkPos->z - pos->z) >> 12;
    startDistanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    stepsLeft = gCourseMap->mItemPointCount;
    posAlias = pos;

    current = node;
    do {
        best = NULL;
        bestDist = 0x7fffffff;
        for (i = 0; i < current->mNextCount; i++) {
            child = current->mNextLinks[i];
            if (child != NULL) {
                linkPos = child->mPointPos;
                deltaX = (linkPos->x - pos->x) >> 12;
                deltaY = (linkPos->y - posAlias->y) >> 12;
                deltaZ = (linkPos->z - posAlias->z) >> 12;
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
    s32 i;
    Vec3 *childPos;
    Kart *other;
    s32 d;

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
                for (i = 0; i < linkCount; i++) {
                    child = side != 0 ? node->mNextLinks[i] : node->mPreviousLinks[i];
                    if (child != NULL) {
                        childPos = child->mPointPos;
                        d = ((pos->x - origin->x) >> 12) * ((childPos->x - origin->x) >> 12);
                        d += ((pos->z - origin->z) >> 12) * ((childPos->z - origin->z) >> 12);
                        if (d > 0) {
                            d = ((child->mPointPos->x - pos->x) >> 12) * ((child->mPointPos->x - pos->x) >> 12);
                            d += ((child->mPointPos->y - pos->y) >> 12) * ((child->mPointPos->y - pos->y) >> 12);
                            d += ((child->mPointPos->z - pos->z) >> 12) * ((child->mPointPos->z - pos->z) >> 12);
                            if (d < bestDistanceSquared) {
                                bestDistanceSquared = d;
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
            for (i = 0; i < secondCount; i++) {
                child = side != 0 ? cur->mPreviousLinks[i] : cur->mNextLinks[i];
                if (child != NULL && child != node) {
                    if (found != FALSE) {
                        childPos = child->mPointPos;
                        d = ((pos->x - origin->x) >> 12) * ((childPos->x - origin->x) >> 12);
                        d += ((pos->z - origin->z) >> 12) * ((childPos->z - origin->z) >> 12);
                        if (d > 0) {
                            d = ((child->mPointPos->x - pos->x) >> 12) * ((child->mPointPos->x - pos->x) >> 12);
                            d += ((child->mPointPos->y - pos->y) >> 12) * ((child->mPointPos->y - pos->y) >> 12);
                            d += ((child->mPointPos->z - pos->z) >> 12) * ((child->mPointPos->z - pos->z) >> 12);
                            if (d < bestDistanceSquared) {
                                bestDistanceSquared = d;
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
    s32 linkAddress = (s32) ref->mLink;

    if (linkAddress == 0) {
        return 0xff;
    }
    return (linkAddress - gCourseMap->mItemRoute0FirstLink) / 40;
}

s32 SetItemPointLinkRefFromIndex(u32 index, u32 *ref) {
    if (index >= 0xff) {
        *ref = 0;
    } else {
        *ref = gCourseMap->mItemRoute0FirstLink + index * 0x28;
    }
    ref[1] = 1;
    return 1;
}

u32 GetItemPointLinkDirection(ItemPointLink *link, Vec3 *directionOut) {
    u32 value0;
    u32 component;
    component = link->mDirectionX;
    component = (component << 6);
    directionOut->x = component;
    component = link->mDirectionY;
    component = (component << 6);
    directionOut->y = component;
    value0 = link->mDirectionZ;
    value0 = (value0 << 6);
    directionOut->z = value0;
    return value0;
}

#pragma thumb on

// Sets each link's direction to its first next link; also fills data_0217bc38.
void InitItemPointLinkDirections(void) {
    ItemPointLink *link;
    Vec3 direction;
    u32 linkCount;
    u16 i;

    linkCount = gCourseMap->mItemPointCount;
    link = gCourseMap->mItemPointLinks;
    i = 0;
    for (i = 0; i < 4; i++) {
        data_0217bc38[i] = 0;
    }
    for (i = 0; i < linkCount; i++, link++) {
        if (link->mUnk_1c >= 0x3e8000) {
            data_0217bc38[link->mUnk_20] = (s32) link;
        }
    }
    link = gCourseMap->mItemPointLinks;
    for (i = 0; i < linkCount; i++, link++) {
        VEC_Subtract(link->mNextLinks[0]->mPointPos, link->mPointPos, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
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
    Vec3 v;
    s32 n;
    BOOL m;
    Vec3 *scale;
    s32 dx;
    s32 dy;
    s32 dz;

    n = Vec3DotUnrounded(&itemInUse->mKartMovement, &itemInUse->mKartOrientation.mUnk_00[2]);
    m = (itemInUse->mKart->mUnk_48 & 1) != 0;
    n = MUL_FIXED12_NO_ROUND(n, 0x1ec);
    if (n < 0x666) {
        n = 0x666;
    }
    if (throwForward != 0) {
        n = ComputeItemThrowForward(itemInUse, forwardSpeed, 0x1b33, 0x7000, &v);
    } else {
        n = ComputeItemThrowBackward(itemInUse, n, 0x1000, 0x7000, &v);
    }
    if (throwForward != 0) {
        if (itemInUse->mKartHopHeight > 0) {
            n += MUL_FIXED12_NO_ROUND(itemInUse->mKartHopHeight, 0x14cd);
        }
    }
    if (itemInUse->mKartVelocityLength < 0x3000) {
        v.z += ThrowBouncingItem_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
        v.x += ThrowBouncingItem_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
    }
    v.x = MUL_FIXED12_NO_ROUND(v.x, n);
    v.y = MUL_FIXED12_NO_ROUND(v.y, n);
    v.z = MUL_FIXED12_NO_ROUND(v.z, n);
    if (!m) {
        if (throwForward != 0) {
            n = forwardUpSpeed + MUL_FIXED12_NO_ROUND(itemInUse->mKartVelocityLength, 0x200) +
                MUL_FIXED12_NO_ROUND(itemInUse->mKartMovement.y, 0x2000);
        } else {
            n = backwardUpSpeed;
            dx = itemInUse->mKartMovement.y > 0 ? 0x666 : 0x1333;
            n += MUL_FIXED12_NO_ROUND(dx, itemInUse->mKartMovement.y);
        }
        VEC_MultAdd(n, &itemInUse->mKartOrientation.mUnk_00[1], &v, &item->mItemObject.mVelocity);
    }
    if (throwForward == 0) {
        VEC_Add(&item->mItemObject.mVelocity, &itemInUse->mKart->mUnk_1fc, &item->mItemObject.mVelocity);
    }
    if (throwForward != 0) {
        item->mItemObject.mPos = itemInUse->mKart->mCollisionCenter;
        VEC_MultAdd(item->mItemObject.mScale.z * 10, &itemInUse->mKartOrientation.mUnk_00[2], &item->mItemObject.mPos,
                    &item->mItemObject.mPos);
    } else {
        if (itemInUse->mKartHopHeight != 0 && itemInUse->mKartVelocityLength < 0x2000 &&
            item->mItemObject.mScale.z < 0xccd) {
            VEC_Subtract(&itemInUse->mKartOrientation.mUnk_00[1], &itemInUse->mKartOrientation.mUnk_00[2], &v);
            VEC_MultAdd(0x2000, &v, &item->mItemObject.mPos, &item->mItemObject.mPos);
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
    item->mItemObject.mFlags &= ~0x7000000;
    if (!m) {
        return;
    }
    n = VEC_DotProduct(&itemInUse->mKartOrientation.mUnk_00[1], &item->mItemObject.mVelocity);
    dx = MUL_FIXED12_NO_ROUND(itemInUse->mKartOrientation.mUnk_00[1].x, n);
    dy = MUL_FIXED12_NO_ROUND(itemInUse->mKartOrientation.mUnk_00[1].y, n);
    dz = MUL_FIXED12_NO_ROUND(itemInUse->mKartOrientation.mUnk_00[1].z, n);
    item->mItemObject.mVelocity.x -= dx;
    item->mItemObject.mVelocity.y -= dy;
    item->mItemObject.mVelocity.z -= dz;
    VEC_MultAdd(throwForward != 0 ? 0x8800 : -0x1000, &itemInUse->mKartOrientation.mUnk_00[1],
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
    item->mItemObject.mFlags &= ~0x7000000;
}

// One step: moves by the velocity and reflects it at a surface while bounces are left.
void AdvanceBouncingItem(BouncingItemObject *item, s32 gravity, s32 velocityFactor, s32 reflectFactor, u32 *e) {
    Vec3 t;
    Vec3 hitNormal;
    Vec3 wallNormal;
    Vec3 *velocity;
    Vec3 *pos;
    s32 n;

    velocity = &item->mItemObject.mVelocity;
    pos = &item->mItemObject.mPos;
    VEC_Add(velocity, pos, pos);
    velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, velocityFactor);
    velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, velocityFactor);
    velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, velocityFactor);
    if (CollideSphereWithCourse(pos, &item->mItemObject.mPrevPos, 0, item->mItemObject.mUnk_dc, 0x24,
                                item->mItemObject.mCollisionSlotIndex, &t, &hitNormal, &wallNormal,
                                &item->mItemObject.mCollisionBits, NULL, NULL, NULL, e) != 0) {
        VEC_Add(&t, pos, pos);
        if (item->mItemObject.mCollisionBits & 0x1e34ef) {
            n = item->mBouncesRemaining;
            item->mBouncesRemaining = n - 1;
            if (n <= 0) {
                func_020f9334(&item->mItemObject, pos, velocity, gravity, &hitNormal);
            } else {
                item->mItemObject.mFlags |= 0x10;
                n = VEC_DotProduct(&hitNormal, velocity);
                t.x = MUL_FIXED12_NO_ROUND(hitNormal.x, n);
                t.y = MUL_FIXED12_NO_ROUND(hitNormal.y, n);
                t.z = MUL_FIXED12_NO_ROUND(hitNormal.z, n);
                velocity->x -= t.x;
                velocity->y -= t.y;
                velocity->z -= t.z;
                velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, 0x8cd);
                velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, 0x8cd);
                velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0x8cd);
                VEC_MultAdd(-reflectFactor, &t, velocity, velocity);
                item->mItemObject.mNormal = hitNormal;
            }
        }
        if (item->mItemObject.mCollisionBits & 0x214300) {
            item->mItemObject.mFlags |= 0x20;
            BounceItemVelocityOffSurface(velocity, &wallNormal);
            if (func_020f9290(&item->mItemObject, &wallNormal) != FALSE) {
                return;
            }
            item->mItemObject.mUnk_78 &= ~0x4000;
        }
        if (item->mItemObject.mCollisionBits & 0x8000) {
            func_020f7070(&item->mItemObject, 1);
            return;
        }
    }
    item->mItemObject.mFlags &= ~0x4000000;
    if (item->mItemObject.mCollisionBits & 0x1e34ef) {
        return;
    }
    velocity->y -= gravity;
    if (velocity->y < -0xa000) {
        velocity->y = -0xa000;
    }
}

// Hit handler of bouncing items: reflects the velocity about the surface normal.
void BounceItemObject(ItemObject *item, Vec3 *b, Vec3 *awayDirection) {
    BounceItemVelocityOffSurface(&item->mVelocity, awayDirection);
    if (item->mFlags & 0x1000000) {
        return;
    }
    item->mFlags |= 0x1000000;
    item->mUnk_108.x = 0;
    item->mUnk_108.y = 0;
    item->mUnk_108.z = 0;
}
