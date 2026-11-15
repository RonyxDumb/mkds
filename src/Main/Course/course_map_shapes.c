#include "Main/Course/course_map_shapes.h"
#include "Main/Course/course_map_alloc.h"
#include "Main/System/heap.h"
#include "Main/Course/course_map_sections.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "print_memory_functions.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/cup_records.h"
#include "Main/Kart/kart_drift.h"
#include "matrix_4x3_basic.h"
#include "vector_math.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const u8 gKartStartGroupCounts[16] = {1, 0, 2, 0, 3, 0, 4, 0, 3, 2, 3, 3, 4, 3, 4, 4};

const CourseMapSectionLoader gCourseMapSectionLoaders[17] = {
    LoadCourseMapRowsData,
    LoadCourseMapEntryGroupsData,
    LoadCourseMapGroupEntriesData,
    (CourseMapSectionLoader) LoadCourseMapSettingsData,
    LoadCourseMapStartPlacementsData,
    LoadCourseMapRespawnsData,
    LoadCourseMapSubScreenViewData,
    LoadCourseMapKeyedPlacementsData,
    LoadCourseMapRaceEndPlacementsData,
    LoadCourseMapCheckpointsData,
    LoadCourseMapCheckpointRoutesData,
    LoadCourseMapItemPointsData,
    LoadCourseMapItemRoutesData,
    LoadCourseMapBattleOrRacePointsData,
    LoadCourseMapBattleOrRaceRoutesData,
    LoadCourseMapShapesData,
    LoadCourseMapCamerasData,
};

#pragma thumb on
CourseMap *AllocCourseMap(void *heap) {
    return HeapAlloc(heap, sizeof(CourseMap));
}
#pragma thumb off

#pragma thumb on
u16 ReadCourseMapSectionCount(void **cursor) {
    u32 *countWord;
    u16 count;

    *cursor = (u32 *) *cursor + 1;
    countWord = *cursor;
    count = *countWord;
    *cursor = countWord + 1;
    return count;
}

s32 LoadCourseMapRowsData(void *section, ...) {
    gCourseMap->mRowCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mRowCount == 0) {
        gCourseMap->mRows = NULL;
    } else {
        gCourseMap->mRows = section;
    }
    return 1;
}

s32 LoadCourseMapEntryGroupsData(void *section, ...) {
    gCourseMap->mEntryGroupCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mEntryGroupCount == 0) {
        gCourseMap->mEntryGroups = NULL;
    } else {
        gCourseMap->mEntryGroups = section;
    }
    return 1;
}

s32 LoadCourseMapGroupEntriesData(void *section, ...) {
    gCourseMap->mGroupEntryCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mGroupEntryCount == 0) {
        gCourseMap->mGroupEntries = NULL;
    } else {
        gCourseMap->mGroupEntries = section;
    }
    return 1;
}

static inline CourseMapCheckpoint *GetCourseMapCheckpoint(u16 checkpointIndex) {
    return &gCourseMap->mCheckpoints[checkpointIndex];
}

// Sums mUnk_18 along the route, plus the average of the sums of the routes that follow it.
s32 ComputeCourseMapRouteCheckpointSum(u16 routeIndex) {
    u16 followingCount;
    s32 followingSum;
    CourseMapRoute *route;
    s32 total;
    u16 entryOffset;
    u16 nextSlot;
    s8 nextRoute;

    route = gCourseMap->mCheckpointRoutes + routeIndex;
    followingSum = 0;
    followingCount = 0;
    total = 0;
    for (entryOffset = 0; entryOffset < route->mEntryCount; entryOffset++) {
        total += GetCourseMapCheckpoint(route->mFirstEntry + entryOffset)->mSumValue;
    }
    for (nextSlot = 0; nextSlot < 3; nextSlot++) {
        nextRoute = (route->mNextRoutes)[nextSlot];
        if (nextRoute != COURSE_MAP_ROUTE_NONE_S8 && nextRoute != 0) {
            followingSum += ComputeCourseMapRouteCheckpointSum(nextRoute);
            followingCount++;
        }
    }
    if (followingCount != 0) {
        total += followingSum / followingCount;
    }
    return total;
}

// Both values are 0 on courses with more than one start placement.
void SetCourseMapCheckpointTotals(void) {
    u32 checkpointSum;
    u32 checkpointSumQuotient;

    checkpointSum = 0;
    checkpointSumQuotient = 0;
    if (gCourseMap->mStartPlacementCount <= 1) {
        checkpointSum = ComputeCourseMapRouteCheckpointSum(0);
        checkpointSumQuotient = checkpointSum / 15000;
    }
    gCourseMap->mCheckpointSum = checkpointSum;
    gCourseMap->mCheckpointSumQuotient = checkpointSumQuotient;
}

void BuildCourseMapEntryGroupTable(void *heap) {
    CourseMap *courseMap;
    CourseMapEntryGroupTableRow *row;
    u16 groupCount;
    CourseMapGroupEntry *groupEntries;
    u32 size;
    u16 groupIndex;
    CourseMapEntryGroup *group;

    courseMap = gCourseMap;
    groupCount = courseMap->mEntryGroupCount;
    size = groupCount << 3;
    groupEntries = courseMap->mGroupEntries;
    if (size != 0) {
        row = HeapAlloc(heap, size);
        gCourseMap->mEntryGroupTable = row;
        for (groupIndex = 0; groupIndex < groupCount; groupIndex++) {
            group = gCourseMap->mEntryGroups + groupIndex;
            row->mGroup = group;
            row->mEntries = groupEntries;
            groupEntries += group->mEntryCount;
            row++;
        }
    } else {
        courseMap->mEntryGroupTable = NULL;
    }
    SetCourseMapCheckpointTotals();
}
#pragma thumb off

#pragma thumb on

CourseMapEntryGroupTableRow *GetCourseMapEntryGroupTableRow(u32 groupIndex) {
    return gCourseMap->mEntryGroupTable + groupIndex;
}

#pragma thumb off

#pragma thumb on
void BuildCourseMapItemRouteLinks(ItemPointLink *previousLink, CourseMapRoute *route, u16 pointIndex) {
    CourseMapItemPoint *itemPoint;
    ItemPointLink *link;
    s32 nextRoute;
    s32 slotIndex;

    if (gCourseMap->mVersion < COURSE_MAP_VERSION_ITEM_POINT_SIZE) {
        itemPoint = (CourseMapItemPoint *) ((CourseMapOldItemPoint *) gCourseMap->mItemPoints + pointIndex);
    } else {
        itemPoint = gCourseMap->mItemPoints + pointIndex;
    }
    link = gCourseMap->mItemPointLinks + pointIndex;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        if (previousLink != NULL && link->mPreviousLinks[slotIndex] == previousLink) {
            return;
        }
    }
    link->mPointPos = &itemPoint->mPos;
    link->mRadius = itemPoint->mRadius;
    if (gCourseMap->mVersion < COURSE_MAP_VERSION_ITEM_POINT_SIZE) {
        link->mLinkIndex = 0;
    } else {
        link->mLinkIndex = itemPoint->mLinkIndex;
    }
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        if (previousLink->mNextLinks[slotIndex] == NULL) {
            previousLink->mNextLinks[slotIndex] = link;
            previousLink->mNextCount++;
            break;
        }
    }
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        if (link->mPreviousLinks[slotIndex] == NULL) {
            link->mPreviousLinks[slotIndex] = previousLink;
            link->mPreviousCount++;
            break;
        }
    }
    if (pointIndex < route->mFirstEntry + route->mEntryCount - 1) {
        BuildCourseMapItemRouteLinks(link, route, pointIndex + 1);
        return;
    }
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        nextRoute = route->mNextRoutes[slotIndex];
        if (nextRoute != COURSE_MAP_ROUTE_NONE && nextRoute != 0) {
            BuildCourseMapItemRouteLinks(link, &gCourseMap->mItemRoutes[nextRoute],
                                         gCourseMap->mItemRoutes[nextRoute].mFirstEntry);
        }
    }
}

void BuildCourseMapItemPointLinks(void *heap) {
    CourseMap *courseMap;
    CourseMapRoute *firstRoute;
    ItemPointLink **linkPointers;
    s32 pointIndex;
    ItemPointLink *link;
    s32 slotIndex;
    s32 lastEntry;
    s32 previousFirstEntry;
    CourseMapRoute *routes;
    CourseMapRoute *previousRoute;

    courseMap = gCourseMap;
    firstRoute = courseMap->mItemRoutes;
    linkPointers = &courseMap->mItemPointLinks;
    courseMap->mItemPointLinks = HeapAlloc(heap, courseMap->mItemPointCount * 0x28);
    linkPointers[1] = courseMap->mItemPointLinks + firstRoute->mFirstEntry;
    for (pointIndex = 0; pointIndex < gCourseMap->mItemPointCount; pointIndex++) {
        link = linkPointers[0] + pointIndex;
        for (slotIndex = 0; slotIndex < 3; slotIndex++) {
            link->mPreviousLinks[slotIndex] = NULL;
            link->mNextLinks[slotIndex] = NULL;
        }
        link->mNextCount = 0;
        link->mPreviousCount = 0;
        link->mPointPos = NULL;
        link->mLinkIndex = 0;
        link->mRadius = 0;
    }
    routes = gCourseMap->mItemRoutes;
    previousRoute = routes + firstRoute->mPreviousRoutes[0];
    previousFirstEntry = routes[firstRoute->mPreviousRoutes[0]].mFirstEntry;
    lastEntry = previousFirstEntry + previousRoute->mEntryCount - 1;
    linkPointers[2] = linkPointers[0] + lastEntry;
    BuildCourseMapItemRouteLinks(linkPointers[0] + lastEntry, firstRoute, firstRoute->mFirstEntry);
}

void BuildCourseMapRaceRouteLinks(RacePointLink *previousLink, CourseMapRoute *route, u16 pointIndex) {
    RacePointLink *link;
    s32 nextRoute;
    s32 slotIndex;
    CourseMapPoint *racePoint;

    racePoint = gCourseMap->mRacePoints + pointIndex;
    link = gCourseMap->mRacePointLinks + pointIndex;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        if (previousLink != NULL && link->mPreviousLinks[slotIndex] == previousLink) {
            return;
        }
    }
    link->mPoint = &racePoint->mPos;
    link->mRadius = racePoint->mRadius;
    link->mValues = racePoint->mValues;
    if (previousLink != NULL) {
        for (slotIndex = 0; slotIndex < 3; slotIndex++) {
            if (previousLink->mNextLinks[slotIndex] == NULL) {
                previousLink->mNextLinks[slotIndex] = link;
                previousLink->mNextCount++;
                break;
            }
        }
        for (slotIndex = 0; slotIndex < 3; slotIndex++) {
            if (link->mPreviousLinks[slotIndex] == NULL) {
                link->mPreviousLinks[slotIndex] = previousLink;
                link->mPreviousCount++;
                break;
            }
        }
    }
    if (pointIndex < route->mFirstEntry + route->mEntryCount - 1) {
        BuildCourseMapRaceRouteLinks(link, route, pointIndex + 1);
        return;
    }
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        nextRoute = route->mNextRoutes[slotIndex];
        if (nextRoute != COURSE_MAP_ROUTE_NONE) {
            BuildCourseMapRaceRouteLinks(link, &gCourseMap->mRaceRoutes[nextRoute],
                                         gCourseMap->mRaceRoutes[nextRoute].mFirstEntry);
        }
    }
}

void BuildCourseMapRacePointLinks(void *heap) {
    CourseMap *courseMap;
    CourseMapRoute *firstRoute;
    RacePointLink **linkPointers;
    CourseMapRoute *lastRoute;
    s32 index;
    RacePointLink *link;
    s32 slotIndex;
    s32 lastEntry;

    courseMap = gCourseMap;
    firstRoute = courseMap->mRaceRoutes;
    linkPointers = &courseMap->mRacePointLinks;
    courseMap->mRacePointLinks = HeapAlloc(heap, courseMap->mRacePointCount * 0x28);
    linkPointers[1] = courseMap->mRacePointLinks + firstRoute->mFirstEntry;
    for (index = 0; index < gCourseMap->mRacePointCount; index++) {
        link = linkPointers[0] + index;
        for (slotIndex = 0; slotIndex < 3; slotIndex++) {
            link->mPreviousLinks[slotIndex] = NULL;
            link->mNextLinks[slotIndex] = NULL;
        }
        link->mNextCount = 0;
        link->mPreviousCount = 0;
        link->mPoint = NULL;
        link->mValues = NULL;
        link->mRadius = 0;
    }
    lastRoute = gCourseMap->mRaceRoutes + firstRoute->mPreviousRoutes[0];
    lastEntry = lastRoute->mFirstEntry + lastRoute->mEntryCount - 1;
    linkPointers[2] = linkPointers[0] + lastEntry;
    BuildCourseMapRaceRouteLinks(linkPointers[0] + lastEntry, firstRoute, firstRoute->mFirstEntry);
    for (index = 0; index < gCourseMap->mRaceRouteCount; index++) {
        lastRoute = gCourseMap->mRaceRoutes + (u16) index;
        if (linkPointers[0][lastRoute->mFirstEntry].mNextCount == 0) {
            BuildCourseMapRaceRouteLinks(NULL, lastRoute, lastRoute->mFirstEntry);
        }
    }
}

void BuildCourseMapBattlePointLinks(void *heap) {
    CourseMap *courseMap;
    CourseMapBattleRoute *route;
    CourseMapBattleRoute *routes;
    PointLink **linkPointers;
    s32 index;
    PointLink *link;
    PointLink *pointLink;
    s32 pointIndex;
    s32 slotIndex;
    u16 routeIndex;
    u16 linkCount;
    u16 lastPoint;
    CourseMapPoint *battlePoint;
    u16 previousIndex;
    u16 nextIndex;

    courseMap = gCourseMap;
    route = courseMap->mBattleRoutes;
    linkPointers = &courseMap->mBattlePointLinks;
    courseMap->mBattlePointLinks = HeapAlloc(heap, courseMap->mBattlePointCount * 0x30);
    linkPointers[1] = courseMap->mBattlePointLinks;
    linkPointers[2] = courseMap->mBattlePointLinks + gCourseMap->mBattlePointCount;
    for (index = 0; index < gCourseMap->mBattlePointCount; index++) {
        link = linkPointers[0] + index;
        for (slotIndex = 0; slotIndex < 8; slotIndex++) {
            link->mLinks[slotIndex] = NULL;
        }
        link->mLinkCount = 0;
        link->mPoint = NULL;
        link->mValues = NULL;
        link->mRadius = 0;
    }
    for (pointIndex = 0; pointIndex < gCourseMap->mBattlePointCount; pointIndex++) {
        battlePoint = gCourseMap->mBattlePoints + (u16) pointIndex;
        pointLink = linkPointers[0] + pointIndex;
        linkCount = 0;
        for (routeIndex = 0; routeIndex < gCourseMap->mBattleRouteCount; routeIndex++) {
            routes = gCourseMap->mBattleRoutes;
            route = routes + routeIndex;
            if (pointIndex >= routes[routeIndex].mFirstEntry && pointIndex < route->mFirstEntry + route->mEntryCount) {
                break;
            }
        }
        pointLink->mRouteLinkMask = 0;
        lastPoint = route->mFirstEntry + route->mEntryCount - 1;
        if (pointIndex == route->mFirstEntry) {
            for (previousIndex = 0; previousIndex < 8; previousIndex++) {
                if (route->mPreviousPoints[previousIndex] != COURSE_MAP_ROUTE_NONE) {
                    BIT_SET(pointLink->mRouteLinkMask, linkCount);
                    pointLink->mLinks[linkCount++] = linkPointers[0] + route->mPreviousPoints[previousIndex];
                }
            }
            if (route->mEntryCount > 1) {
                pointLink->mLinks[linkCount++] = pointLink + 1;
            }
        }
        if (pointIndex == lastPoint) {
            for (nextIndex = 0; nextIndex < 8; nextIndex++) {
                if (route->mNextPoints[nextIndex] != COURSE_MAP_ROUTE_NONE) {
                    BIT_SET(pointLink->mRouteLinkMask, linkCount);
                    pointLink->mLinks[linkCount++] = linkPointers[0] + route->mNextPoints[nextIndex];
                }
            }
            if (route->mEntryCount > 1) {
                pointLink->mLinks[linkCount++] = pointLink - 1;
            }
        }
        if (pointIndex != route->mFirstEntry && pointIndex != lastPoint) {
            linkCount = 0;
            pointLink->mLinks[linkCount++] = pointLink + 1;
            pointLink->mLinks[linkCount++] = pointLink - 1;
        }
        pointLink->mPoint = &battlePoint->mPos;
        pointLink->mRadius = battlePoint->mRadius;
        pointLink->mValues = battlePoint->mValues;
        pointLink->mLinkCount = linkCount;
    }
}

void BuildCourseMapPointLinks(void *heap) {
    if (gCourseMap->mItemRouteCount != 0) {
        BuildCourseMapItemPointLinks(heap);
    }
    if (gCourseMap->mRaceRouteCount != 0) {
        BuildCourseMapRacePointLinks(heap);
    } else if (gCourseMap->mBattleRouteCount != 0) {
        BuildCourseMapBattlePointLinks(heap);
    }
}
#pragma thumb off

// The settings section of a course map file: four unread bytes, then the settings record.
struct CourseMapSettingsSection {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ CourseMapSettings mSettings;
};

#pragma thumb on
u32 LoadCourseMapSettingsData(CourseMapSettingsSection *section) {
    gCourseMap->mSettings = &section->mSettings;
    return 1;
}
#pragma thumb off

#pragma thumb on
s32 LoadCourseMapStartPlacementsData(void *section, ...) {
    gCourseMap->mStartPlacementCount = ReadCourseMapSectionCount(&section);
    gCourseMap->mStartPlacements = section;
    return 1;
}

s32 LoadCourseMapRespawnsData(void *section, ...) {
    s32 index;
    s32 maxSlot;
    void *heap;
    s32 respawnCount;
    s32 respawnIndex;
    u16 unused;
    CourseMapRespawn *respawn;

    heap = GetHeap(GetCurrentHeapCall());
    gCourseMap->mRespawnCount = ReadCourseMapSectionCount(&section);
    gCourseMap->mRespawns = section;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        respawnCount = gCourseMap->mRespawnCount;
        gCourseMap->mRespawnIndexBySlot = HeapAlloc(heap, respawnCount * 2);
        gCourseMap->mNextRespawnSlot = 0;
        for (index = 0; index < respawnCount; index++) {
            gCourseMap->mRespawnIndexBySlot[index] = index;
        }
    } else if (gCourseMap->mRespawnCount != 0) {
        maxSlot = 0;
        for (respawnIndex = 0; respawnIndex < gCourseMap->mRespawnCount; respawnIndex++) {
            respawn = &gCourseMap->mRespawns[respawnIndex];
            if (respawn->mSlot > maxSlot) {
                maxSlot = respawn->mSlot;
            }
        }
        gCourseMap->mRespawnIndexBySlot = HeapAlloc(heap, (maxSlot + 1) * 2);
        for (index = 0; index < maxSlot + 1; index++) {
            gCourseMap->mRespawnIndexBySlot[index] = COURSE_MAP_RESPAWN_SLOT_NONE;
        }
        for (index = 0; index < gCourseMap->mRespawnCount; index++) {
            gCourseMap->mRespawnIndexBySlot[gCourseMap->mRespawns[index].mSlot] = index;
        }
    }
    return 1;
}

static inline u16 CourseMapNextRandomBelowU16(RandomState64 *randomState64, u16 limit) {
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

void ShuffleCourseMapRespawnSlots(RandomState64 *randomState64) {
    s32 swapIndex;
    u16 respawnCount;
    u16 firstSlot;
    u16 secondSlot;
    u16 respawnIndex;

    respawnCount = gCourseMap->mRespawnCount;
    for (swapIndex = 0; swapIndex < 100; swapIndex++) {
        firstSlot = CourseMapNextRandomBelowU16(randomState64, respawnCount);
        secondSlot = CourseMapNextRandomBelowU16(randomState64, respawnCount);
        respawnIndex = gCourseMap->mRespawnIndexBySlot[secondSlot];
        gCourseMap->mRespawnIndexBySlot[secondSlot] = gCourseMap->mRespawnIndexBySlot[firstSlot];
        gCourseMap->mRespawnIndexBySlot[firstSlot] = respawnIndex;
    }
}

s32 LoadCourseMapSubScreenViewData(void *section, ...) {
    gCourseMap->mSubScreenViewCount = ReadCourseMapSectionCount(&section);
    gCourseMap->mSubScreenView = section;
    return 1;
}

void BuildCourseMapKeyedPlacementIndexByKey(void) {
    u16 placementCount;
    u16 placementIndex;

    placementCount = gCourseMap->mKeyedPlacementCount;
    if (placementCount == 0) {
        gCourseMap->mKeyedPlacementIndexByKey = NULL;
        return;
    }
    gCourseMap->mKeyedPlacementIndexByKey = HeapAlloc(GetHeap(GetCurrentHeapCall()), placementCount * 2);
    for (placementIndex = 0; placementIndex < placementCount; placementIndex++) {
        gCourseMap->mKeyedPlacementIndexByKey[gCourseMap->mKeyedPlacements[placementIndex].mKey] = placementIndex;
    }
}

s32 LoadCourseMapKeyedPlacementsData(void *section, ...) {
    BOOL loaded = FALSE;

    if (gCourseMap->mVersion < COURSE_MAP_VERSION_KEYED_PLACEMENTS) {
        gCourseMap->mKeyedPlacementCount = 0;
        gCourseMap->mKeyedPlacements = NULL;
    } else {
        gCourseMap->mKeyedPlacementCount = ReadCourseMapSectionCount(&section);
        gCourseMap->mKeyedPlacements = section;
        loaded = TRUE;
    }
    BuildCourseMapKeyedPlacementIndexByKey();
    return loaded;
}

s32 LoadCourseMapRaceEndPlacementsData(void *section, ...) {
    enum { RESULT_EMPTY } result = 0;

    if (gCourseMap->mVersion < COURSE_MAP_VERSION_RACE_END_PLACEMENTS) {
        gCourseMap->mRaceEndPlacementCount = result;
        gCourseMap->mRaceEndPlacements = NULL;
        return result;
    }
    gCourseMap->mRaceEndPlacementCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mRaceEndPlacementCount != 0) {
        gCourseMap->mRaceEndPlacements = section;
    } else {
        gCourseMap->mRaceEndPlacements = NULL;
    }
    return 1;
}

s32 LoadCourseMapCheckpointsData(void *section, ...) {
    u16 checkpointIndex;
    u16 numberedCount;

    gCourseMap->mCheckpointCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mCheckpointCount == 0) {
        gCourseMap->mCheckpoints = NULL;
        return 1;
    }
    gCourseMap->mCheckpoints = section;
    numberedCount = 0;
    for (checkpointIndex = 0; checkpointIndex < gCourseMap->mCheckpointCount; checkpointIndex++) {
        if (gCourseMap->mCheckpoints[checkpointIndex].mNumber != COURSE_MAP_CHECKPOINT_NO_NUMBER) {
            numberedCount++;
        }
    }
    gCourseMap->mNumberedCheckpointCount = numberedCount;
    return 1;
}

s32 LoadCourseMapCheckpointRoutesData(void *section, ...) {
    s32 routeIndex;
    CourseMapRoute *lastRoute;
    s32 firstEntry;

    gCourseMap->mCheckpointRouteCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mCheckpointRouteCount == 0) {
        gCourseMap->mCheckpointRoutes = NULL;
        gCourseMap->mLastCheckpoint = 0;
        return 1;
    }
    gCourseMap->mCheckpointRoutes = section;
    for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
        if (GetCheckpointRoute(routeIndex)->mFirstEntry == 0) {
            lastRoute = GetCheckpointRoute((s8) GetCheckpointRoute(routeIndex)->mPreviousRoutes[0]);
            firstEntry = GetCheckpointRoute((s8) GetCheckpointRoute(routeIndex)->mPreviousRoutes[0])->mFirstEntry;
            gCourseMap->mLastCheckpoint = firstEntry + lastRoute->mEntryCount - 1;
            break;
        }
    }
    return 1;
}

s32 LoadCourseMapItemPointsData(void *section, ...) {
    gCourseMap->mItemPointCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mItemPointCount == 0) {
        gCourseMap->mItemPoints = NULL;
    } else {
        gCourseMap->mItemPoints = section;
    }
    return 1;
}

s32 LoadCourseMapItemRoutesData(void *section, ...) {
    gCourseMap->mItemRouteCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mItemRouteCount == 0) {
        gCourseMap->mItemRoutes = NULL;
    } else {
        gCourseMap->mItemRoutes = section;
    }
    return 1;
}

s32 LoadCourseMapBattleOrRacePointsData(void *section, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mBattlePointCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mBattlePointCount == 0) {
            gCourseMap->mBattlePoints = NULL;
        } else {
            gCourseMap->mBattlePoints = section;
            gCourseMap->mRacePoints = NULL;
            gCourseMap->mRacePointCount = 0;
        }
    } else {
        gCourseMap->mRacePointCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mRacePointCount == 0) {
            gCourseMap->mRacePoints = NULL;
        } else {
            gCourseMap->mRacePoints = section;
            gCourseMap->mBattlePoints = NULL;
            gCourseMap->mBattlePointCount = 0;
        }
    }
    return 1;
}

s32 LoadCourseMapBattleOrRaceRoutesData(void *section, ...) {
    if (gCourseMap->mStartPlacementCount > 1) {
        gCourseMap->mBattleRouteCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mBattleRouteCount == 0) {
            gCourseMap->mBattleRoutes = NULL;
        } else {
            gCourseMap->mBattleRoutes = section;
            gCourseMap->mRaceRoutes = NULL;
            gCourseMap->mRaceRouteCount = 0;
        }
    } else {
        gCourseMap->mRaceRouteCount = ReadCourseMapSectionCount(&section);
        if (gCourseMap->mRaceRouteCount == 0) {
            gCourseMap->mRaceRoutes = NULL;
        } else {
            gCourseMap->mRaceRoutes = section;
            gCourseMap->mBattleRoutes = NULL;
            gCourseMap->mBattleRouteCount = 0;
        }
    }
    return 1;
}
#pragma thumb off

#pragma thumb on

CourseMapShape *GetCourseMapShape(u32 shapeIndex) {
    return &gCourseMap->mShapes[shapeIndex];
}

#pragma thumb off

#pragma thumb on
void BuildCourseMapZoneShapeLists(void) {
    void *heap;
    CourseMapShape *shape;
    CourseMapZoneShapeNode **nodeSlot;
    u16 shapeIndex;
    u16 listIndex;

    heap = GetHeap(GetCurrentHeapCall());
    shapeIndex = 0;
    for (listIndex = 0; listIndex < 8; listIndex++) {
        gCourseMap->mZoneShapeLists[listIndex] = NULL;
    }
    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_ZONE) {
            nodeSlot = &gCourseMap->mZoneShapeLists[(s16) shape->mKindValue];
            while (*nodeSlot != NULL) {
                nodeSlot = &(*nodeSlot)->mNext;
            }
            *nodeSlot = HeapAlloc(heap, 8);
            (*nodeSlot)->mShape = shape;
            (*nodeSlot)->mNext = NULL;
        }
    }
}
#pragma thumb off

#pragma thumb on

void CountCourseMapPointLinkShapes(void) {
    u16 count;
    u16 shapeIndex;
    count = 0;
    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        if (GetCourseMapShape(shapeIndex)->mKind == COURSE_MAP_SHAPE_KIND_POINT_LINK) {
            count++;
        }
    }
    gCourseMap->mPointLinkShapeCount = count;
}

void CountCourseMapMissionEndShapes(void) {
    u8 count;
    u16 shapeIndex;
    count = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
            if (GetCourseMapShape(shapeIndex)->mKind == COURSE_MAP_SHAPE_KIND_MISSION_END) {
                count++;
            }
        }
    }
    gCourseMap->mMissionEndShapeCount = count;
}

#pragma thumb off

#pragma thumb on
s32 LoadCourseMapShapesData(void *section, ...) {
    gCourseMap->mShapeCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mShapeCount == 0) {
        gCourseMap->mShapes = NULL;
    } else {
        gCourseMap->mShapes = section;
    }
    BuildCourseMapZoneShapeLists();
    CountCourseMapPointLinkShapes();
    CountCourseMapMissionEndShapes();
    return 1;
}

s32 LoadCourseMapCamerasData(void *section, ...) {
    u16 cameraIndex;
    CourseMapCamera *camera;

    gCourseMap->mCameraCount = ReadCourseMapSectionCount(&section);
    if (gCourseMap->mCameraCount == 0) {
        gCourseMap->mCameras = NULL;
        return 1;
    }
    gCourseMap->mCameras = section;
    gCourseMap->mFirstChainStartEntry = NULL;
    gCourseMap->mSecondChainStartEntry = NULL;
    gCourseMap->mFirstAngleStartCamera = NULL;
    gCourseMap->mFirstBattleSequenceCamera = NULL;
    for (cameraIndex = 0; cameraIndex < gCourseMap->mCameraCount; cameraIndex++) {
        camera = gCourseMap->mCameras + cameraIndex;
        if (gCourseMap->mFirstChainStartEntry == NULL && camera->mChainStart == CAMERA_CHAIN_START_FIRST) {
            gCourseMap->mFirstChainStartEntry = camera;
        }
        if (gCourseMap->mSecondChainStartEntry == NULL && camera->mChainStart == CAMERA_CHAIN_START_SECOND) {
            gCourseMap->mSecondChainStartEntry = camera;
        }
        if (gCourseMap->mFirstAngleStartCamera == NULL && camera->mKind == COURSE_MAP_CAMERA_KIND_ANGLE_START) {
            gCourseMap->mFirstAngleStartCamera = camera;
        }
        if (gRaceSetup->mMode == MODE_BATTLE && gCourseMap->mFirstBattleSequenceCamera == NULL &&
            camera->mKind == COURSE_MAP_CAMERA_KIND_SEQUENCE) {
            gCourseMap->mFirstBattleSequenceCamera = camera;
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN && gCourseMap->mFirstMissionRunCamera == NULL &&
            camera->mKind == COURSE_MAP_CAMERA_KIND_MISSION_RUN) {
            gCourseMap->mFirstMissionRunCamera = camera;
        }
    }
    return 1;
}

void CreateCourseMap(void *heap) {
    char path[0x100];
    CourseMapHeader *header;
    CourseMap *courseMap;
    s32 *offset;
    u8 *base;
    s32 sectionIndex;
    u16 routeIndex;

    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                header = FindCourseFile("/course_map.nkm");
            } else {
                snprintf(path, 0x100, "/MissionRun/%s_tool.nkm", gRaceSetup->mMissionRunStem);
                header = FindCourseFile(path);
            }
            break;
        case MODE_WIFI:
            header = FindCourseFile("/Net/net_course_map.nkm");
            if (header == NULL) {
                header = FindCourseFile("/course_map.nkm");
            }
            break;
        default:
            header = FindCourseFile("/course_map.nkm");
            break;
    }
    courseMap = AllocCourseMap(heap);
    gCourseMap = courseMap;
    courseMap->mVersion = header->mVersion;
    offset = header->mSectionOffsets;
    base = (u8 *) header + header->mBaseOffset;
    for (sectionIndex = 0; sectionIndex < 17; sectionIndex++) {
        if (gCourseMapSectionLoaders[sectionIndex](base + *offset) != 0) {
            offset++;
        }
    }
    BuildCourseMapEntryGroupTable(heap);
    BuildCourseMapPointLinks(heap);
    gCourseMap->mLapProgressBaseMax = 0;
    for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
        if (gCourseMap->mCheckpointRoutes[routeIndex].mLapProgressBase > gCourseMap->mLapProgressBaseMax) {
            gCourseMap->mLapProgressBaseMax = gCourseMap->mCheckpointRoutes[routeIndex].mLapProgressBase;
        }
    }
}
#pragma thumb off

CourseMapGroupEntry *GetCourseMapGroupEntry(u16 groupIndex, u16 entryIndex) {
    return GetCourseMapEntryGroupTableRow(groupIndex)->mEntries + entryIndex;
}

void GetCourseMapStartPlacementWithOffsets(Vec3 *outPos, Vec3 *outRotation, s32 key, s32 firstAxisOffset,
                                           s32 thirdAxisOffset) {
    CourseMapPlacement *placement = NULL;
    CourseMapPlacement *candidate;
    s32 placementIndex;
    u16 angleX;
    u16 angleY;
    u16 angleZ;
    MtxFx43 rotationMatrix;
    MtxFx43 rotationMatrixX;
    MtxFx43 rotationMatrixY;
    MtxFx43 rotationMatrixZ;
    s32 negatedFirstAxisX;
    s32 negatedFirstAxisY;
    s32 negatedFirstAxisZ;
    s32 negatedThirdAxisX;
    s32 negatedThirdAxisY;
    s32 negatedThirdAxisZ;

    if (gCourseMap->mSettings->mStartSideFlipped != 0) {
        firstAxisOffset = 0x1000 - firstAxisOffset;
    }
    if (gCourseMap->mStartPlacementCount > 1) {
        for (placementIndex = 0; placementIndex < gCourseMap->mStartPlacementCount; placementIndex++) {
            candidate = &(gCourseMap->mStartPlacements)[placementIndex];
            if (key == (s16) candidate->mKey) {
                placement = candidate;
                break;
            }
        }
    } else {
        placement = gCourseMap->mStartPlacements;
    }
    angleX = FROM_FIXED12(placement->mRotation.x) * 0xb6;
    angleY = FROM_FIXED12(placement->mRotation.y) * 0xb6;
    angleZ = FROM_FIXED12(placement->mRotation.z) * 0xb6;
    MTX_RotX43_(&rotationMatrixX, FX_SinIdx(angleX), FX_CosIdx(angleX));
    MTX_RotY43_(&rotationMatrixY, FX_SinIdx(angleY), FX_CosIdx(angleY));
    MTX_RotZ43_(&rotationMatrixZ, FX_SinIdx(angleZ), FX_CosIdx(angleZ));
    MTX_Concat43(&rotationMatrixX, &rotationMatrixZ, &rotationMatrix);
    MTX_Concat43(&rotationMatrixY, &rotationMatrix, &rotationMatrix);
    negatedFirstAxisX = -rotationMatrix.mRows[0].x;
    negatedFirstAxisY = -rotationMatrix.mRows[0].y;
    negatedFirstAxisZ = -rotationMatrix.mRows[0].z;
    negatedThirdAxisX = -rotationMatrix.mRows[2].x;
    negatedThirdAxisY = -rotationMatrix.mRows[2].y;
    negatedThirdAxisZ = -rotationMatrix.mRows[2].z;
    outPos->x = placement->mPos.x + MUL_FIXED12_ROUNDED(negatedFirstAxisX, firstAxisOffset) +
                MUL_FIXED12_ROUNDED(negatedThirdAxisX, thirdAxisOffset);
    outPos->y = placement->mPos.y + MUL_FIXED12_ROUNDED(negatedFirstAxisY, firstAxisOffset) +
                MUL_FIXED12_ROUNDED(negatedThirdAxisY, thirdAxisOffset);
    outPos->z = placement->mPos.z + MUL_FIXED12_ROUNDED(negatedFirstAxisZ, firstAxisOffset) +
                MUL_FIXED12_ROUNDED(negatedThirdAxisZ, thirdAxisOffset);
    outRotation->x = placement->mRotation.x;
    outRotation->y = placement->mRotation.y;
    outRotation->z = placement->mRotation.z;
}

// Position and rotation of the start spot of kart c by mode: a staggered grid by rank in a race, by key
// (kart + mStartPlacementOffset) % 8 in battle.
void GetCourseMapKartStartPlacement(Vec3 *outPos, Vec3 *outRotation, s32 kartIndex) {
    u16 lastKartIndex = gRaceSetup->mKartCount - 1;
    s32 rankIndex = (u16) (GetKartStartRank(kartIndex) - 1);
    s32 firstGroupCount;
    s32 groupCount;
    s32 groupPosition;
    s32 groupIndex;
    s32 sideOffset;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0, 0);
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation,
                                                  (u16) ((rankIndex + gRaceProgress->mStartPlacementOffset) % 8), 0, 0);
            break;
        case MODE_TIME_ATTACK:
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0x800, 0);
            break;
        case MODE_MISSION_RUN:
            if (gRaceSetup->mKartCount <= 1) {
                GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0x800, 0);
            } else {
                GetCourseMapStartPlacementWithOffsets(outPos, outRotation, kartIndex,
                                                      (1 - kartIndex * 2) * 0x14000 + 0x800, 0);
            }
            break;
        default:
            firstGroupCount = gKartStartGroupCounts[lastKartIndex * 2];
            groupCount = firstGroupCount;
            groupPosition = rankIndex;
            if (rankIndex >= firstGroupCount) {
                groupCount = (gKartStartGroupCounts + 1)[lastKartIndex * 2];
                groupPosition = rankIndex - firstGroupCount;
            }
            if ((groupCount & 1) == 1) {
                groupPosition = (groupPosition - groupCount / 2) * 2;
            } else {
                groupPosition = groupPosition * 2 + 1 - groupCount;
            }
            if (rankIndex >= firstGroupCount) {
                if (firstGroupCount == (gKartStartGroupCounts + 1)[(u32) lastKartIndex * 2]) {
                    groupPosition = groupPosition + 1;
                }
            }
            sideOffset = groupPosition * 0x11000;
            groupIndex = 0;
            if (rankIndex >= firstGroupCount) {
                groupIndex = 1;
            }
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, sideOffset,
                                                  rankIndex * 0x19000 + groupIndex * 0x14000);
            break;
    }
}

BOOL IsPosInCourseMapShapeBox(Vec3 *pos, CourseMapShape *shape) {
    Vec3 offset;
    s32 distance;
    s32 extent;

    VEC_Subtract(pos, &shape->mPos, &offset);
    distance = VEC_DotProduct(&offset, &shape->mAxisY);
    if (distance > MUL_FIXED12_ROUNDED(shape->mScale.y, 0x64000) || distance < 0) {
        return FALSE;
    }
    distance = VEC_DotProduct(&offset, &shape->mAxisX);
    extent = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000);
    if (distance < -extent || distance > extent) {
        return FALSE;
    }
    distance = VEC_DotProduct(&offset, &shape->mAxisZ);
    extent = MUL_FIXED12_ROUNDED(shape->mScale.z, 0x32000);
    if (distance < -extent || distance > extent) {
        return FALSE;
    }
    return TRUE;
}

s32 IsPosInCourseMapShape(Vec3 *pos, CourseMapShape *shape) {
    Vec3 offset;
    s32 inside = 0;
    s32 distanceX;
    s32 distanceZ;
    s32 radius;

    switch (shape->mShapeKind) {
        case COURSE_MAP_SHAPE_FORM_BOX:
            inside = IsPosInCourseMapShapeBox(pos, shape);
            break;
        case COURSE_MAP_SHAPE_FORM_CYLINDER:
            VEC_Subtract(pos, &shape->mPos, &offset);
            if (VEC_DotProduct(&offset, &shape->mAxisY) > MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                inside = 0;
            } else {
                distanceX = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                distanceZ = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                inside = MUL_FIXED12_ROUNDED(radius, radius) >=
                         MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ);
            }
            break;
    }
    return inside;
}

s32 IsPosInCourseMapMissionEndShape(Vec3 *pos, s32 *outFlag) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    BOOL found = FALSE;
    s32 distanceX;
    s32 distanceZ;
    s32 radius;
    s32 inside;

    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_MISSION_END) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        distanceX = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                        if (MUL_FIXED12_ROUNDED(radius, radius) >=
                            MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                if ((s16) shape->mKindValue == 0) {
                    *outFlag = 1;
                } else {
                    *outFlag = 0;
                }
                found = TRUE;
                break;
            }
        }
    }
    return found;
}

void *FindCourseMapPointLinkShapeRacePointLink(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 distanceX;
    s32 distanceZ;
    s32 radius;
    void *link = NULL;
    s32 inside;

    if (gCourseMap->mPointLinkShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_POINT_LINK) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        distanceX = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                        if (MUL_FIXED12_ROUNDED(radius, radius) >=
                            MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = &gCourseMap->mRacePointLinks[shape->mPointIndex];
                break;
            }
        }
    }
    return link;
}

PointLink *FindCourseMapPointLinkShapeBattlePointLink(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 distanceX;
    s32 distanceZ;
    s32 radius;
    PointLink *link = NULL;
    s32 inside;

    if (gCourseMap->mPointLinkShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_POINT_LINK) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        distanceX = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                        if (MUL_FIXED12_ROUNDED(radius, radius) >=
                            MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = &gCourseMap->mBattlePointLinks[shape->mPointIndex];
                break;
            }
        }
    }
    return link;
}

s32 GetCourseMapCameraIndexAtPos(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 distanceX;
    s32 distanceZ;
    s32 radius;
    s32 cameraIndex = -1;
    s32 inside;

    for (shapeIndex = 0; shapeIndex < gCourseMap->mShapeCount; shapeIndex++) {
        shape = GetCourseMapShape(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_CAMERA) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) > MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        inside = 0;
                    } else {
                        distanceX = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                        if (MUL_FIXED12_ROUNDED(radius, radius) <
                            MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ)) {
                            inside = 0;
                        } else {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                cameraIndex = shape->mCameraIndex;
                break;
            }
        }
    }
    return cameraIndex;
}

// Mode 2: returns mNextRespawnSlot and advances it modulo mRespawnCount (the argument is ignored); otherwise returns
// mCheckpoints[a].mRespawnSlot, a = the kart's current entry.
u16 GetCourseMapRespawnSlot(u32 checkpointIndex) {
    u16 respawnSlot;
    CourseMap *courseMap;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        courseMap = gCourseMap;
        respawnSlot = courseMap->mNextRespawnSlot;
        courseMap->mNextRespawnSlot = (respawnSlot + 1) % courseMap->mRespawnCount;
    } else {
        respawnSlot = gCourseMap->mCheckpoints[checkpointIndex].mRespawnSlot;
    }
    return respawnSlot;
}

void *GetCourseMapRespawnRacePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (gCourseMap->mCheckpoints == NULL && gCourseMap->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gCourseMap->mRespawns[gCourseMap->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        outPos->x = 0;
        outPos->y = 0;
        outPos->z = 0;
        outRotation->x = 0x1000;
        outRotation->y = 0;
        outRotation->z = 0;
        pointIndex = -1;
    } else {
        outPos->x = respawn->mPos.x;
        outPos->y = respawn->mPos.y;
        outPos->z = respawn->mPos.z;
        outRotation->x = respawn->mRotation.x;
        outRotation->y = respawn->mRotation.y;
        outRotation->z = respawn->mRotation.z;
        pointIndex = respawn->mPointIndex;
    }
    if (pointIndex == -1) {
        return NULL;
    }
    return &gCourseMap->mRacePointLinks[pointIndex];
}

PointLink *GetCourseMapRespawnBattlePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (gCourseMap->mCheckpoints == NULL && gCourseMap->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gCourseMap->mRespawns[gCourseMap->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        outPos->x = 0;
        outPos->y = 0;
        outPos->z = 0;
        outRotation->x = 0x1000;
        outRotation->y = 0;
        outRotation->z = 0;
        pointIndex = -1;
    } else {
        outPos->x = respawn->mPos.x;
        outPos->y = respawn->mPos.y;
        outPos->z = respawn->mPos.z;
        outRotation->x = respawn->mRotation.x;
        outRotation->y = respawn->mRotation.y;
        outRotation->z = respawn->mRotation.z;
        pointIndex = respawn->mPointIndex;
    }
    if (pointIndex == -1) {
        return NULL;
    }
    return &gCourseMap->mBattlePointLinks[pointIndex];
}

struct ItemPointLink *GetCourseMapRespawnItemPointLink(u16 slot) {
    CourseMapRespawn *respawn;

    if (gCourseMap->mCheckpoints == NULL && gCourseMap->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gCourseMap->mRespawns[gCourseMap->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        return NULL;
    }
    return &gCourseMap->mItemPointLinks[respawn->mItemPointIndex];
}

s32 IsKartInCourseMapZoneShapeList(s32 kartIndex, u32 listIndex) {
    CourseMapZoneShapeNode *node;
    s32 inside;
    CourseMapShape *shape;
    Vec3 kartPos;
    Vec3 offset;
    s32 distanceX;
    s32 distanceZ;
    s32 radius;
    BOOL found = FALSE;

    node = gCourseMap->mZoneShapeLists[listIndex];
    GetKartPos(&kartPos, kartIndex);
    for (; found == FALSE && node != NULL; node = node->mNext) {
        shape = node->mShape;
        inside = 0;
        switch (shape->mShapeKind) {
            case COURSE_MAP_SHAPE_FORM_BOX:
                inside = IsPosInCourseMapShapeBox(&kartPos, shape);
                break;
            case COURSE_MAP_SHAPE_FORM_CYLINDER:
                VEC_Subtract(&kartPos, &shape->mPos, &offset);
                if (VEC_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                    distanceX = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                    distanceZ = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                    radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                    if (MUL_FIXED12_ROUNDED(radius, radius) >=
                        MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ)) {
                        inside = 1;
                    }
                }
                break;
        }
        if (inside != 0) {
            found = TRUE;
        }
    }
    return found;
}
