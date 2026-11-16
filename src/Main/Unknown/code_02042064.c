#include "Main/Unknown/code_02042064.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020431bc.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_02134398.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on
u16 mdat_readSectionHeader(void **cursor) {
    u32 *countWord;
    u16 count;

    *cursor = (u32 *) *cursor + 1;
    countWord = *cursor;
    count = *countWord;
    *cursor = countWord + 1;
    return count;
}

s32 mdat_loadObji(void *section, ...) {
    gMapData->mRowCount = mdat_readSectionHeader(&section);
    if (gMapData->mRowCount == 0) {
        gMapData->mRows = NULL;
    } else {
        gMapData->mRows = section;
    }
    return 1;
}

s32 mdat_loadPath(void *section, ...) {
    gMapData->mEntryGroupCount = mdat_readSectionHeader(&section);
    if (gMapData->mEntryGroupCount == 0) {
        gMapData->mEntryGroups = NULL;
    } else {
        gMapData->mEntryGroups = section;
    }
    return 1;
}

s32 mdat_loadPoit(void *section, ...) {
    gMapData->mGroupEntryCount = mdat_readSectionHeader(&section);
    if (gMapData->mGroupEntryCount == 0) {
        gMapData->mGroupEntries = NULL;
    } else {
        gMapData->mGroupEntries = section;
    }
    return 1;
}

static inline CourseMapCheckpoint *func_02043078_inline(u16 i) {
    return &gMapData->mCheckpoints[i];
}

// Sums field18 along the route, plus the average of the sums of the routes that follow it.
s32 mdat_calcCpatLength(u16 routeIndex) {
    u16 followingCount;
    s32 followingSum;
    CourseMapRoute *route;
    s32 total;
    u16 entryOffset;
    u16 nextSlot;
    s8 nextRoute;

    route = gMapData->mCheckpointRoutes + routeIndex;
    followingSum = 0;
    followingCount = 0;
    total = 0;
    for (entryOffset = 0; entryOffset < route->mEntryCount; entryOffset++) {
        total += func_02043078_inline(route->mFirstEntry + entryOffset)->field18;
    }
    for (nextSlot = 0; nextSlot < 3; nextSlot++) {
        nextRoute = (route->mNextRoutes)[nextSlot];
        if (nextRoute != -1 && nextRoute != 0) {
            followingSum += mdat_calcCpatLength(nextRoute);
            followingCount++;
        }
    }
    if (followingCount != 0) {
        total += followingSum / followingCount;
    }
    return total;
}

// Both values are 0 on courses with more than one start placement.
void mdat_calculateTrackLength(void) {
    u32 checkpointSum;
    u32 checkpointSumQuotient;

    checkpointSum = 0;
    checkpointSumQuotient = 0;
    if (gMapData->mStartPlacementCount <= 1) {
        checkpointSum = mdat_calcCpatLength(0);
        checkpointSumQuotient = checkpointSum / 15000;
    }
    gMapData->mCheckpointSum = checkpointSum;
    gMapData->mCheckpointSumQuotient = checkpointSumQuotient;
}

void mdat_initPaths(void *heap) {
    CourseMap *courseMap;
    CourseMapEntryGroupTableRow *row;
    u16 groupCount;
    CourseMapGroupEntry *groupEntries;
    u32 size;
    u16 i;
    CourseMapEntryGroup *group;

    courseMap = gMapData;
    groupCount = courseMap->mEntryGroupCount;
    size = groupCount << 3;
    groupEntries = courseMap->mGroupEntries;
    if (size != 0) {
        row = heap_alloc(heap, size);
        gMapData->mEntryGroupTable = row;
        for (i = 0; i < groupCount; i++) {
            group = gMapData->mEntryGroups + i;
            row->mGroup = group;
            row->mEntries = groupEntries;
            groupEntries += group->mEntryCount;
            row++;
        }
    } else {
        courseMap->mEntryGroupTable = NULL;
    }
    mdat_calculateTrackLength();
}
#pragma thumb off

#pragma thumb on

CourseMapEntryGroupTableRow *mdat_getPath(u32 groupIndex) {
    return gMapData->mEntryGroupTable + groupIndex;
}

#pragma thumb off

#pragma thumb on
void mdat_initIpatNextPrev(ItemPointLink *previousLink, CourseMapRoute *route, u16 pointIndex) {
    CourseMapItemPoint *itemPoint;
    ItemPointLink *link;
    s32 nextRoute;
    s32 k;

    if (gMapData->mVersion < 0x21) {
        itemPoint = (CourseMapItemPoint *) ((Unk02175620_54_10 *) gMapData->mItemPoints + pointIndex);
    } else {
        itemPoint = gMapData->mItemPoints + pointIndex;
    }
    link = gMapData->mItemPointLinks + pointIndex;
    for (k = 0; k < 3; k++) {
        if (previousLink != NULL && link->mPreviousLinks[k] == previousLink) {
            return;
        }
    }
    link->mPointPos = &itemPoint->mPos;
    link->field1C = itemPoint->fieldC;
    if (gMapData->mVersion < 0x21) {
        link->field20 = 0;
    } else {
        link->field20 = itemPoint->field10;
    }
    for (k = 0; k < 3; k++) {
        if (previousLink->mNextLinks[k] == NULL) {
            previousLink->mNextLinks[k] = link;
            previousLink->mNextCount++;
            break;
        }
    }
    for (k = 0; k < 3; k++) {
        if (link->mPreviousLinks[k] == NULL) {
            link->mPreviousLinks[k] = previousLink;
            link->mPreviousCount++;
            break;
        }
    }
    if (pointIndex < route->mFirstEntry + route->mEntryCount - 1) {
        mdat_initIpatNextPrev(link, route, pointIndex + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        nextRoute = route->mNextRoutes[k];
        if (nextRoute != 0xff && nextRoute != 0) {
            mdat_initIpatNextPrev(link, &gMapData->mItemRoutes[nextRoute],
                                         gMapData->mItemRoutes[nextRoute].mFirstEntry);
        }
    }
}

void mdat_initItemPaths(void *heap) {
    CourseMap *courseMap;
    CourseMapRoute *firstRoute;
    ItemPointLink **q;
    s32 i;
    ItemPointLink *link;
    s32 k;
    s32 lastEntry;
    s32 previousFirstEntry;
    CourseMapRoute *routes;
    CourseMapRoute *previousRoute;

    courseMap = gMapData;
    firstRoute = courseMap->mItemRoutes;
    q = &courseMap->mItemPointLinks;
    courseMap->mItemPointLinks = heap_alloc(heap, courseMap->mItemPointCount * 0x28);
    q[1] = courseMap->mItemPointLinks + firstRoute->mFirstEntry;
    for (i = 0; i < gMapData->mItemPointCount; i++) {
        link = q[0] + i;
        for (k = 0; k < 3; k++) {
            link->mPreviousLinks[k] = NULL;
            link->mNextLinks[k] = NULL;
        }
        link->mNextCount = 0;
        link->mPreviousCount = 0;
        link->mPointPos = NULL;
        link->field20 = 0;
        link->field1C = 0;
    }
    routes = gMapData->mItemRoutes;
    previousRoute = routes + firstRoute->mPreviousRoutes[0];
    previousFirstEntry = routes[firstRoute->mPreviousRoutes[0]].mFirstEntry;
    lastEntry = previousFirstEntry + previousRoute->mEntryCount - 1;
    q[2] = q[0] + lastEntry;
    mdat_initIpatNextPrev(q[0] + lastEntry, firstRoute, firstRoute->mFirstEntry);
}

void mdat_initEpatNextPrev(RacePointLink *previousLink, CourseMapRoute *route, u16 pointIndex) {
    RacePointLink *link;
    s32 nextRoute;
    s32 k;
    CourseMapPoint *racePoint;

    racePoint = gMapData->mRacePoints + pointIndex;
    link = gMapData->mRacePointLinks + pointIndex;
    for (k = 0; k < 3; k++) {
        if (previousLink != NULL && link->fieldC[k] == previousLink) {
            return;
        }
    }
    link->field18 = racePoint;
    link->field1C = racePoint->fieldC;
    link->field20 = racePoint->field10;
    if (previousLink != NULL) {
        for (k = 0; k < 3; k++) {
            if (previousLink->field0[k] == NULL) {
                previousLink->field0[k] = link;
                previousLink->field24++;
                break;
            }
        }
        for (k = 0; k < 3; k++) {
            if (link->fieldC[k] == NULL) {
                link->fieldC[k] = previousLink;
                link->field26++;
                break;
            }
        }
    }
    if (pointIndex < route->mFirstEntry + route->mEntryCount - 1) {
        mdat_initEpatNextPrev(link, route, pointIndex + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        nextRoute = route->mNextRoutes[k];
        if (nextRoute != 0xff) {
            mdat_initEpatNextPrev(link, &gMapData->mRaceRoutes[nextRoute],
                                         gMapData->mRaceRoutes[nextRoute].mFirstEntry);
        }
    }
}

void mdat_initEnemyPaths(void *heap) {
    CourseMap *courseMap;
    CourseMapRoute *firstRoute;
    RacePointLink **q;
    CourseMapRoute *t;
    s32 i;
    RacePointLink *link;
    s32 k;
    s32 lastEntry;

    courseMap = gMapData;
    firstRoute = courseMap->mRaceRoutes;
    q = &courseMap->mRacePointLinks;
    courseMap->mRacePointLinks = heap_alloc(heap, courseMap->mRacePointCount * 0x28);
    q[1] = courseMap->mRacePointLinks + firstRoute->mFirstEntry;
    for (i = 0; i < gMapData->mRacePointCount; i++) {
        link = q[0] + i;
        for (k = 0; k < 3; k++) {
            link->fieldC[k] = NULL;
            link->field0[k] = NULL;
        }
        link->field24 = 0;
        link->field26 = 0;
        link->field18 = NULL;
        link->field20 = NULL;
        link->field1C = 0;
    }
    t = gMapData->mRaceRoutes + firstRoute->mPreviousRoutes[0];
    lastEntry = t->mFirstEntry + t->mEntryCount - 1;
    q[2] = q[0] + lastEntry;
    mdat_initEpatNextPrev(q[0] + lastEntry, firstRoute, firstRoute->mFirstEntry);
    for (i = 0; i < gMapData->mRaceRouteCount; i++) {
        t = gMapData->mRaceRoutes + (u16) i;
        if (q[0][t->mFirstEntry].field24 == 0) {
            mdat_initEpatNextPrev(NULL, t, t->mFirstEntry);
        }
    }
}

void mdat_initMgEnemyPaths(void *heap) {
    CourseMap *courseMap;
    CourseMapBattleRoute *route;
    CourseMapBattleRoute *t;
    PointLink **q;
    s32 i;
    PointLink *link;
    PointLink *pointLink;
    s32 pointIndex;
    s32 k;
    u16 routeIndex;
    u16 linkCount;
    u16 lastPoint;
    CourseMapPoint *battlePoint;
    u16 b;
    u16 c;

    courseMap = gMapData;
    route = courseMap->mBattleRoutes;
    q = &courseMap->mBattlePointLinks;
    courseMap->mBattlePointLinks = heap_alloc(heap, courseMap->mBattlePointCount * 0x30);
    q[1] = courseMap->mBattlePointLinks;
    q[2] = courseMap->mBattlePointLinks + gMapData->mBattlePointCount;
    for (i = 0; i < gMapData->mBattlePointCount; i++) {
        link = q[0] + i;
        for (k = 0; k < 8; k++) {
            link->mLinks[k] = NULL;
        }
        link->mLinkCount = 0;
        link->field20 = NULL;
        link->field28 = NULL;
        link->field24 = 0;
    }
    for (pointIndex = 0; pointIndex < gMapData->mBattlePointCount; pointIndex++) {
        battlePoint = gMapData->mBattlePoints + (u16) pointIndex;
        pointLink = q[0] + pointIndex;
        linkCount = 0;
        for (routeIndex = 0; routeIndex < gMapData->mBattleRouteCount; routeIndex++) {
            t = gMapData->mBattleRoutes;
            route = t + routeIndex;
            if (pointIndex >= t[routeIndex].field0 && pointIndex < route->field0 + route->field2) {
                break;
            }
        }
        pointLink->field2E = 0;
        lastPoint = route->field0 + route->field2 - 1;
        if (pointIndex == route->field0) {
            for (b = 0; b < 8; b++) {
                if (route->fieldC[b] != 0xff) {
                    pointLink->field2E |= 1 << linkCount;
                    pointLink->mLinks[linkCount++] = q[0] + route->fieldC[b];
                }
            }
            if (route->field2 > 1) {
                pointLink->mLinks[linkCount++] = pointLink + 1;
            }
        }
        if (pointIndex == lastPoint) {
            for (c = 0; c < 8; c++) {
                if (route->field4[c] != 0xff) {
                    pointLink->field2E |= 1 << linkCount;
                    pointLink->mLinks[linkCount++] = q[0] + route->field4[c];
                }
            }
            if (route->field2 > 1) {
                pointLink->mLinks[linkCount++] = pointLink - 1;
            }
        }
        if (pointIndex != route->field0 && pointIndex != lastPoint) {
            linkCount = 0;
            pointLink->mLinks[linkCount++] = pointLink + 1;
            pointLink->mLinks[linkCount++] = pointLink - 1;
        }
        pointLink->field20 = &battlePoint->mPos;
        pointLink->field24 = battlePoint->fieldC;
        pointLink->field28 = battlePoint->field10;
        pointLink->mLinkCount = linkCount;
    }
}

void mdat_initItemEnemyPaths(void *a) {
    if (gMapData->mItemRouteCount != 0) {
        mdat_initItemPaths(a);
    }
    if (gMapData->mRaceRouteCount != 0) {
        mdat_initEnemyPaths(a);
    } else if (gMapData->mBattleRouteCount != 0) {
        mdat_initMgEnemyPaths(a);
    }
}
#pragma thumb off

#pragma thumb on
u32 mdat_loadStag(void *arg0) {
    gMapData->mSettings = OFFSET_PTR(CourseMapSettings, arg0, 4);
    return 1;
}
#pragma thumb off

#pragma thumb on
s32 mdat_loadKtps(void *section, ...) {
    gMapData->mStartPlacementCount = mdat_readSectionHeader(&section);
    gMapData->mStartPlacements = section;
    return 1;
}

s32 mdat_loadKtpj(void *section, ...) {
    s32 i;
    s32 maxSlot;
    void *heap;
    s32 respawnCount;
    s32 k;
    u16 t;
    CourseMapRespawn *respawn;

    heap = proc_getHeap(proc_getCurrent());
    gMapData->mRespawnCount = mdat_readSectionHeader(&section);
    gMapData->mRespawns = section;
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        respawnCount = gMapData->mRespawnCount;
        gMapData->mRespawnIndexBySlot = heap_alloc(heap, respawnCount * 2);
        gMapData->mNextRespawnSlot = 0;
        for (i = 0; i < respawnCount; i++) {
            gMapData->mRespawnIndexBySlot[i] = i;
        }
    } else if (gMapData->mRespawnCount != 0) {
        maxSlot = 0;
        for (k = 0; k < gMapData->mRespawnCount; k++) {
            respawn = &gMapData->mRespawns[k];
            if (respawn->mSlot > maxSlot) {
                maxSlot = respawn->mSlot;
            }
        }
        gMapData->mRespawnIndexBySlot = heap_alloc(heap, (maxSlot + 1) * 2);
        for (i = 0; i < maxSlot + 1; i++) {
            gMapData->mRespawnIndexBySlot[i] = 0xffff;
        }
        for (i = 0; i < gMapData->mRespawnCount; i++) {
            gMapData->mRespawnIndexBySlot[gMapData->mRespawns[i].mSlot] = i;
        }
    }
    return 1;
}

static inline u16 func_020427d4_inline(RandomState64 *randomState64, u16 limit) {
    u32 value;
    if (limit == 0) {
        value = 0;
    } else {
        randomState64->mValue =
            (s64) randomState64->mMultiplier * (s64) randomState64->mValue + randomState64->mIncrement;
        if (limit == 0) {
            value = randomState64->mValue >> 32;
        } else {
            value = ((s64) (randomState64->mValue >> 32) * (u32) limit) >> 32;
        }
    }
    return value;
}

void mdat_shuffleRespawns(RandomState64 *randomState64) {
    s32 i;
    u16 respawnCount;
    u16 firstSlot;
    u16 secondSlot;
    u16 t;

    respawnCount = gMapData->mRespawnCount;
    for (i = 0; i < 100; i++) {
        firstSlot = func_020427d4_inline(randomState64, respawnCount);
        secondSlot = func_020427d4_inline(randomState64, respawnCount);
        t = gMapData->mRespawnIndexBySlot[secondSlot];
        gMapData->mRespawnIndexBySlot[secondSlot] = gMapData->mRespawnIndexBySlot[firstSlot];
        gMapData->mRespawnIndexBySlot[firstSlot] = t;
    }
}

s32 mdat_loadKtp2(void *section, ...) {
    gMapData->field30 = mdat_readSectionHeader(&section);
    gMapData->field2C = section;
    return 1;
}

void mdat_initKtpc(void) {
    u16 placementCount;
    u16 i;

    placementCount = gMapData->mKeyedPlacementCount;
    if (placementCount == 0) {
        gMapData->mKeyedPlacementIndexByKey = NULL;
        return;
    }
    gMapData->mKeyedPlacementIndexByKey = heap_alloc(proc_getHeap(proc_getCurrent()), placementCount * 2);
    for (i = 0; i < placementCount; i++) {
        gMapData->mKeyedPlacementIndexByKey[gMapData->mKeyedPlacements[i].mKey] = i;
    }
}

s32 mdat_loadKtpc(void *section, ...) {
    BOOL loaded = FALSE;

    if (gMapData->mVersion < 0x1f) {
        gMapData->mKeyedPlacementCount = 0;
        gMapData->mKeyedPlacements = NULL;
    } else {
        gMapData->mKeyedPlacementCount = mdat_readSectionHeader(&section);
        gMapData->mKeyedPlacements = section;
        loaded = TRUE;
    }
    mdat_initKtpc();
    return loaded;
}

s32 mdat_loadKtpm(void *section, ...) {
    enum { K0 } r = 0;

    if (gMapData->mVersion < 0x24) {
        gMapData->field40 = r;
        gMapData->field3C = NULL;
        return r;
    }
    gMapData->field40 = mdat_readSectionHeader(&section);
    if (gMapData->field40 != 0) {
        gMapData->field3C = section;
    } else {
        gMapData->field3C = NULL;
    }
    return 1;
}

s32 mdat_loadCpoi(void *section, ...) {
    u16 i;
    u16 j;

    gMapData->mCheckpointCount = mdat_readSectionHeader(&section);
    if (gMapData->mCheckpointCount == 0) {
        gMapData->mCheckpoints = NULL;
        return 1;
    }
    gMapData->mCheckpoints = section;
    j = 0;
    for (i = 0; i < gMapData->mCheckpointCount; i++) {
        if (gMapData->mCheckpoints[i].mNumber != -1) {
            j++;
        }
    }
    gMapData->mNumberedCheckpointCount = j;
    return 1;
}

s32 mdat_loadCpat(void *section, ...) {
    s32 i;
    CourseMapRoute *routes;
    CourseMapRoute *lastRoute;
    s32 firstEntry;

    gMapData->mCheckpointRouteCount = mdat_readSectionHeader(&section);
    if (gMapData->mCheckpointRouteCount == 0) {
        gMapData->mCheckpointRoutes = NULL;
        gMapData->mLastCheckpoint = 0;
        return 1;
    }
    gMapData->mCheckpointRoutes = section;
    for (i = 0; i < gMapData->mCheckpointRouteCount; i++) {
        if (gMapData->mCheckpointRoutes[(u16) i].mFirstEntry == 0) {
            routes = gMapData->mCheckpointRoutes;
            lastRoute = &routes[(u16) (s8) routes[(u16) i].mPreviousRoutes[0]];
            firstEntry = routes[(u16) (s8) routes[(u16) i].mPreviousRoutes[0]].mFirstEntry;
            gMapData->mLastCheckpoint = firstEntry + lastRoute->mEntryCount - 1;
            break;
        }
    }
    return 1;
}

s32 mdat_loadIpoi(void *section, ...) {
    gMapData->mItemPointCount = mdat_readSectionHeader(&section);
    if (gMapData->mItemPointCount == 0) {
        gMapData->mItemPoints = NULL;
    } else {
        gMapData->mItemPoints = section;
    }
    return 1;
}

s32 mdat_loadIpat(void *section, ...) {
    gMapData->mItemRouteCount = mdat_readSectionHeader(&section);
    if (gMapData->mItemRouteCount == 0) {
        gMapData->mItemRoutes = NULL;
    } else {
        gMapData->mItemRoutes = section;
    }
    return 1;
}

s32 mdat_loadEpoiMepo(void *section, ...) {
    if (gMapData->mStartPlacementCount > 1) {
        gMapData->mBattlePointCount = mdat_readSectionHeader(&section);
        if (gMapData->mBattlePointCount == 0) {
            gMapData->mBattlePoints = NULL;
        } else {
            gMapData->mBattlePoints = section;
            gMapData->mRacePoints = NULL;
            gMapData->mRacePointCount = 0;
        }
    } else {
        gMapData->mRacePointCount = mdat_readSectionHeader(&section);
        if (gMapData->mRacePointCount == 0) {
            gMapData->mRacePoints = NULL;
        } else {
            gMapData->mRacePoints = section;
            gMapData->mBattlePoints = NULL;
            gMapData->mBattlePointCount = 0;
        }
    }
    return 1;
}

s32 mdat_loadEpatMepa(void *section, ...) {
    if (gMapData->mStartPlacementCount > 1) {
        gMapData->mBattleRouteCount = mdat_readSectionHeader(&section);
        if (gMapData->mBattleRouteCount == 0) {
            gMapData->mBattleRoutes = NULL;
        } else {
            gMapData->mBattleRoutes = section;
            gMapData->mRaceRoutes = NULL;
            gMapData->mRaceRouteCount = 0;
        }
    } else {
        gMapData->mRaceRouteCount = mdat_readSectionHeader(&section);
        if (gMapData->mRaceRouteCount == 0) {
            gMapData->mRaceRoutes = NULL;
        } else {
            gMapData->mRaceRoutes = section;
            gMapData->mBattleRoutes = NULL;
            gMapData->mBattleRouteCount = 0;
        }
    }
    return 1;
}
#pragma thumb off

#pragma thumb on

CourseMapShape *mdat_getAreaEntryByIndex(u32 shapeIndex) {
    return &gMapData->mShapes[shapeIndex];
}

#pragma thumb off

#pragma thumb on
void mdat_initClipAreas(void) {
    void *heap;
    CourseMapShape *shape;
    CourseMapKind3ShapeNode **nodeSlot;
    u16 shapeIndex;
    u16 listIndex;

    heap = proc_getHeap(proc_getCurrent());
    shapeIndex = 0;
    for (listIndex = 0; listIndex < 8; listIndex++) {
        gMapData->mKind3ShapeLists[listIndex] = NULL;
    }
    for (shapeIndex = 0; shapeIndex < gMapData->mShapeCount; shapeIndex++) {
        shape = mdat_getAreaEntryByIndex(shapeIndex);
        if (shape->mKind == 3) {
            nodeSlot = &gMapData->mKind3ShapeLists[(s16) shape->field3C];
            while (*nodeSlot != NULL) {
                nodeSlot = &(*nodeSlot)->field4;
            }
            *nodeSlot = heap_alloc(heap, 8);
            (*nodeSlot)->field0 = shape;
            (*nodeSlot)->field4 = NULL;
        }
    }
}
#pragma thumb off

#pragma thumb on

void mdat_countEnemyRespawnRouteAreas(void) {
    u16 count;
    u16 i;
    count = 0;
    for (i = 0; i < gMapData->mShapeCount; i++) {
        if (mdat_getAreaEntryByIndex(i)->mKind == 4) {
            count++;
        }
    }
    gMapData->mKind4ShapeCount = count;
}

void mdat_countMissionEndAreas(void) {
    u8 count;
    u16 i;
    count = 0;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        for (i = 0; i < gMapData->mShapeCount; i++) {
            if (mdat_getAreaEntryByIndex(i)->mKind == 2) {
                count++;
            }
        }
    }
    gMapData->mKind2ShapeCountInMode4 = count;
}

#pragma thumb off

#pragma thumb on
s32 mdat_loadArea(void *section, ...) {
    gMapData->mShapeCount = mdat_readSectionHeader(&section);
    if (gMapData->mShapeCount == 0) {
        gMapData->mShapes = NULL;
    } else {
        gMapData->mShapes = section;
    }
    mdat_initClipAreas();
    mdat_countEnemyRespawnRouteAreas();
    mdat_countMissionEndAreas();
    return 1;
}

s32 mdat_loadCame(void *section, ...) {
    u16 i;
    CourseMapCamera *e;

    gMapData->mCameraCount = mdat_readSectionHeader(&section);
    if (gMapData->mCameraCount == 0) {
        gMapData->mCameras = NULL;
        return 1;
    }
    gMapData->mCameras = section;
    gMapData->mFirstChainStartEntry = NULL;
    gMapData->mSecondChainStartEntry = NULL;
    gMapData->mFirstKind6Entry = NULL;
    gMapData->mFirstKind7EntryInMode2 = NULL;
    for (i = 0; i < gMapData->mCameraCount; i++) {
        e = gMapData->mCameras + i;
        if (gMapData->mFirstChainStartEntry == NULL && e->mChainStart == 1) {
            gMapData->mFirstChainStartEntry = e;
        }
        if (gMapData->mSecondChainStartEntry == NULL && e->mChainStart == 2) {
            gMapData->mSecondChainStartEntry = e;
        }
        if (gMapData->mFirstKind6Entry == NULL && e->mKind == 6) {
            gMapData->mFirstKind6Entry = e;
        }
        if (gRaceMultiConfig->mMode == MODE_BATTLE && gMapData->mFirstKind7EntryInMode2 == NULL && e->mKind == 7) {
            gMapData->mFirstKind7EntryInMode2 = e;
        }
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN && gMapData->mFirstKind8EntryInMode4 == NULL && e->mKind == 8) {
            gMapData->mFirstKind8EntryInMode4 = e;
        }
    }
    return 1;
}

void mdat_init(void *heap) {
    char path[0x100];
    CourseMapHeader *header;
    CourseMap *courseMap;
    s32 *offset;
    u8 *base;
    s32 sectionIndex;
    u16 routeIndex;

    switch (gRaceMultiConfig->mMode) {
        case MODE_MISSION_RUN:
            if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
                header = arc_getCourseArcFile("/course_map.nkm");
            } else {
                snprintf(path, 0x100, "/MissionRun/%s_tool.nkm", gRaceMultiConfig->mMissionRunStem);
                header = arc_getCourseArcFile(path);
            }
            break;
        case 5:
            header = arc_getCourseArcFile("/Net/net_course_map.nkm");
            if (header == NULL) {
                header = arc_getCourseArcFile("/course_map.nkm");
            }
            break;
        default:
            header = arc_getCourseArcFile("/course_map.nkm");
            break;
    }
    courseMap = mdat_allocMapDataStruct(heap);
    gMapData = courseMap;
    courseMap->mVersion = header->mVersion;
    offset = header->mSectionOffsets;
    base = (u8 *) header + header->mBaseOffset;
    for (sectionIndex = 0; sectionIndex < 17; sectionIndex++) {
        if (mdat_sNkmLoadFunctions[sectionIndex](base + *offset) != 0) {
            offset++;
        }
    }
    mdat_initPaths(heap);
    mdat_initItemEnemyPaths(heap);
    gMapData->mLapProgressBaseMax = 0;
    for (routeIndex = 0; routeIndex < gMapData->mCheckpointRouteCount; routeIndex++) {
        if (gMapData->mCheckpointRoutes[routeIndex].mLapProgressBase > gMapData->mLapProgressBaseMax) {
            gMapData->mLapProgressBaseMax = gMapData->mCheckpointRoutes[routeIndex].mLapProgressBase;
        }
    }
}
#pragma thumb off
