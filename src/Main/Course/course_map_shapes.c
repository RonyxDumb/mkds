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
#include "print_memory_multibyte_write.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/cup_records.h"
#include "Main/Kart/kart_drift.h"
#include "matrix_4x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const u8 gKartStartGroupCounts[16] = {1, 0, 2, 0, 3, 0, 4, 0, 3, 2, 3, 3, 4, 3, 4, 4};

const CourseMapSectionLoader g_NkmSectionFnTable[17] = {
    NkmHandler_OBJI_from_thumb,
    NkmHandler_PATH_from_thumb,
    NkmHandler_POIT_from_thumb,
    (CourseMapSectionLoader) NkmHandler_STAG_from_thumb,
    NkmHandler_KTPS_from_thumb,
    NkmHandler_KTPJ_from_thumb,
    NkmHandler_KTP2_from_thumb,
    NkmHandler_KTPC_from_thumb,
    NkmHandler_KTPM_from_thumb,
    NkmHandler_CPOI_from_thumb,
    NkmHandler_CPAT_from_thumb,
    NkmHandler_IPOI_from_thumb,
    NkmHandler_IPAT_from_thumb,
    NkmHandler_EPOI_from_thumb,
    NkmHandler_EPAT_from_thumb,
    NkmHandler_AREA_from_thumb,
    NkmHandler_CAME_from_thumb,
};

#pragma thumb on
CourseMap *AllocateStructPE_from_thumb(void *heap) {
    return Mem_AllocateHeap(heap, sizeof(CourseMap));
}
#pragma thumb off

#pragma thumb on
u16 NkmSection_AdvanceHeaderGetEntryCount_from_thumb(void **cursor) {
    u32 *countWord;
    u16 count;

    *cursor = (u32 *) *cursor + 1;
    countWord = *cursor;
    count = *countWord;
    *cursor = countWord + 1;
    return count;
}

s32 NkmHandler_OBJI_from_thumb(void *section, ...) {
    g_GlobalPE->mRowCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mRowCount == 0) {
        g_GlobalPE->mRows = NULL;
    } else {
        g_GlobalPE->mRows = section;
    }
    return 1;
}

s32 NkmHandler_PATH_from_thumb(void *section, ...) {
    g_GlobalPE->mEntryGroupCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mEntryGroupCount == 0) {
        g_GlobalPE->mEntryGroups = NULL;
    } else {
        g_GlobalPE->mEntryGroups = section;
    }
    return 1;
}

s32 NkmHandler_POIT_from_thumb(void *section, ...) {
    g_GlobalPE->mGroupEntryCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mGroupEntryCount == 0) {
        g_GlobalPE->mGroupEntries = NULL;
    } else {
        g_GlobalPE->mGroupEntries = section;
    }
    return 1;
}

static inline CourseMapCheckpoint *GetCourseMapCheckpoint(u16 checkpointIndex) {
    return &g_GlobalPE->mCheckpoints[checkpointIndex];
}

// Sums mUnk_18 along the route, plus the average of the sums of the routes that follow it.
s32 ComputeTotalDistanceRecursively_from_thumb(u16 routeIndex) {
    u16 followingCount;
    s32 followingSum;
    CourseMapRoute *route;
    s32 total;
    u16 entryOffset;
    u16 nextSlot;
    s8 nextRoute;

    route = g_GlobalPE->mCheckpointRoutes + routeIndex;
    followingSum = 0;
    followingCount = 0;
    total = 0;
    for (entryOffset = 0; entryOffset < route->mEntryCount; entryOffset++) {
        total += GetCourseMapCheckpoint(route->mFirstEntry + entryOffset)->mSumValue;
    }
    for (nextSlot = 0; nextSlot < 3; nextSlot++) {
        nextRoute = (route->mNextRoutes)[nextSlot];
        if (nextRoute != COURSE_MAP_ROUTE_NONE_S8 && nextRoute != 0) {
            followingSum += ComputeTotalDistanceRecursively_from_thumb(nextRoute);
            followingCount++;
        }
    }
    if (followingCount != 0) {
        total += followingSum / followingCount;
    }
    return total;
}

// Both values are 0 on courses with more than one start placement.
void ComputeTotalCpatDistance_from_thumb(void) {
    u32 checkpointSum;
    u32 checkpointSumQuotient;

    checkpointSum = 0;
    checkpointSumQuotient = 0;
    if (g_GlobalPE->mStartPlacementCount <= 1) {
        checkpointSum = ComputeTotalDistanceRecursively_from_thumb(0);
        checkpointSumQuotient = checkpointSum / 15000;
    }
    g_GlobalPE->mCheckpointSum = checkpointSum;
    g_GlobalPE->mCheckpointSumQuotient = checkpointSumQuotient;
}

void PopulatePathEntries_from_thumb(void *heap) {
    CourseMap *courseMap;
    CourseMapEntryGroupTableRow *row;
    u16 groupCount;
    CourseMapGroupEntry *groupEntries;
    u32 size;
    u16 groupIndex;
    CourseMapEntryGroup *group;

    courseMap = g_GlobalPE;
    groupCount = courseMap->mEntryGroupCount;
    size = groupCount << 3;
    groupEntries = courseMap->mGroupEntries;
    if (size != 0) {
        row = Mem_AllocateHeap(heap, size);
        g_GlobalPE->mEntryGroupTable = row;
        for (groupIndex = 0; groupIndex < groupCount; groupIndex++) {
            group = g_GlobalPE->mEntryGroups + groupIndex;
            row->mGroup = group;
            row->mEntries = groupEntries;
            groupEntries += group->mEntryCount;
            row++;
        }
    } else {
        courseMap->mEntryGroupTable = NULL;
    }
    ComputeTotalCpatDistance_from_thumb();
}
#pragma thumb off

#pragma thumb on

CourseMapEntryGroupTableRow *GetLoadedNkmPathEntry_from_thumb(u32 groupIndex) {
    return g_GlobalPE->mEntryGroupTable + groupIndex;
}

#pragma thumb off

#pragma thumb on
void BuildCourseMapItemRouteLinks(ItemPointLink *previousLink, CourseMapRoute *route, u16 pointIndex) {
    CourseMapItemPoint *itemPoint;
    ItemPointLink *link;
    s32 nextRoute;
    s32 slotIndex;

    if (g_GlobalPE->mVersion < COURSE_MAP_VERSION_ITEM_POINT_SIZE) {
        itemPoint = (CourseMapItemPoint *) ((CourseMapOldItemPoint *) g_GlobalPE->mItemPoints + pointIndex);
    } else {
        itemPoint = g_GlobalPE->mItemPoints + pointIndex;
    }
    link = g_GlobalPE->mItemPointLinks + pointIndex;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        if (previousLink != NULL && link->mPreviousLinks[slotIndex] == previousLink) {
            return;
        }
    }
    link->mPointPos = &itemPoint->mPos;
    link->mRadius = itemPoint->mRadius;
    if (g_GlobalPE->mVersion < COURSE_MAP_VERSION_ITEM_POINT_SIZE) {
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
            BuildCourseMapItemRouteLinks(link, &g_GlobalPE->mItemRoutes[nextRoute],
                                         g_GlobalPE->mItemRoutes[nextRoute].mFirstEntry);
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

    courseMap = g_GlobalPE;
    firstRoute = courseMap->mItemRoutes;
    linkPointers = &courseMap->mItemPointLinks;
    courseMap->mItemPointLinks = Mem_AllocateHeap(heap, courseMap->mItemPointCount * 0x28);
    linkPointers[1] = courseMap->mItemPointLinks + firstRoute->mFirstEntry;
    for (pointIndex = 0; pointIndex < g_GlobalPE->mItemPointCount; pointIndex++) {
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
    routes = g_GlobalPE->mItemRoutes;
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

    racePoint = g_GlobalPE->mRacePoints + pointIndex;
    link = g_GlobalPE->mRacePointLinks + pointIndex;
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
            BuildCourseMapRaceRouteLinks(link, &g_GlobalPE->mRaceRoutes[nextRoute],
                                         g_GlobalPE->mRaceRoutes[nextRoute].mFirstEntry);
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

    courseMap = g_GlobalPE;
    firstRoute = courseMap->mRaceRoutes;
    linkPointers = &courseMap->mRacePointLinks;
    courseMap->mRacePointLinks = Mem_AllocateHeap(heap, courseMap->mRacePointCount * 0x28);
    linkPointers[1] = courseMap->mRacePointLinks + firstRoute->mFirstEntry;
    for (index = 0; index < g_GlobalPE->mRacePointCount; index++) {
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
    lastRoute = g_GlobalPE->mRaceRoutes + firstRoute->mPreviousRoutes[0];
    lastEntry = lastRoute->mFirstEntry + lastRoute->mEntryCount - 1;
    linkPointers[2] = linkPointers[0] + lastEntry;
    BuildCourseMapRaceRouteLinks(linkPointers[0] + lastEntry, firstRoute, firstRoute->mFirstEntry);
    for (index = 0; index < g_GlobalPE->mRaceRouteCount; index++) {
        lastRoute = g_GlobalPE->mRaceRoutes + (u16) index;
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

    courseMap = g_GlobalPE;
    route = courseMap->mBattleRoutes;
    linkPointers = &courseMap->mBattlePointLinks;
    courseMap->mBattlePointLinks = Mem_AllocateHeap(heap, courseMap->mBattlePointCount * 0x30);
    linkPointers[1] = courseMap->mBattlePointLinks;
    linkPointers[2] = courseMap->mBattlePointLinks + g_GlobalPE->mBattlePointCount;
    for (index = 0; index < g_GlobalPE->mBattlePointCount; index++) {
        link = linkPointers[0] + index;
        for (slotIndex = 0; slotIndex < 8; slotIndex++) {
            link->mLinks[slotIndex] = NULL;
        }
        link->mLinkCount = 0;
        link->mPoint = NULL;
        link->mValues = NULL;
        link->mRadius = 0;
    }
    for (pointIndex = 0; pointIndex < g_GlobalPE->mBattlePointCount; pointIndex++) {
        battlePoint = g_GlobalPE->mBattlePoints + (u16) pointIndex;
        pointLink = linkPointers[0] + pointIndex;
        linkCount = 0;
        for (routeIndex = 0; routeIndex < g_GlobalPE->mBattleRouteCount; routeIndex++) {
            routes = g_GlobalPE->mBattleRoutes;
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
    if (g_GlobalPE->mItemRouteCount != 0) {
        BuildCourseMapItemPointLinks(heap);
    }
    if (g_GlobalPE->mRaceRouteCount != 0) {
        BuildCourseMapRacePointLinks(heap);
    } else if (g_GlobalPE->mBattleRouteCount != 0) {
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
u32 NkmHandler_STAG_from_thumb(CourseMapSettingsSection *section) {
    g_GlobalPE->mSettings = &section->mSettings;
    return 1;
}
#pragma thumb off

#pragma thumb on
s32 NkmHandler_KTPS_from_thumb(void *section, ...) {
    g_GlobalPE->mStartPlacementCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    g_GlobalPE->mStartPlacements = section;
    return 1;
}

s32 NkmHandler_KTPJ_from_thumb(void *section, ...) {
    s32 index;
    s32 maxSlot;
    void *heap;
    s32 respawnCount;
    s32 respawnIndex;
    u16 unused;
    CourseMapRespawn *respawn;

    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    g_GlobalPE->mRespawnCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    g_GlobalPE->mRespawns = section;
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        respawnCount = g_GlobalPE->mRespawnCount;
        g_GlobalPE->mRespawnIndexBySlot = Mem_AllocateHeap(heap, respawnCount * 2);
        g_GlobalPE->mNextRespawnSlot = 0;
        for (index = 0; index < respawnCount; index++) {
            g_GlobalPE->mRespawnIndexBySlot[index] = index;
        }
    } else if (g_GlobalPE->mRespawnCount != 0) {
        maxSlot = 0;
        for (respawnIndex = 0; respawnIndex < g_GlobalPE->mRespawnCount; respawnIndex++) {
            respawn = &g_GlobalPE->mRespawns[respawnIndex];
            if (respawn->mSlot > maxSlot) {
                maxSlot = respawn->mSlot;
            }
        }
        g_GlobalPE->mRespawnIndexBySlot = Mem_AllocateHeap(heap, (maxSlot + 1) * 2);
        for (index = 0; index < maxSlot + 1; index++) {
            g_GlobalPE->mRespawnIndexBySlot[index] = COURSE_MAP_RESPAWN_SLOT_NONE;
        }
        for (index = 0; index < g_GlobalPE->mRespawnCount; index++) {
            g_GlobalPE->mRespawnIndexBySlot[g_GlobalPE->mRespawns[index].mSlot] = index;
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

    respawnCount = g_GlobalPE->mRespawnCount;
    for (swapIndex = 0; swapIndex < 100; swapIndex++) {
        firstSlot = CourseMapNextRandomBelowU16(randomState64, respawnCount);
        secondSlot = CourseMapNextRandomBelowU16(randomState64, respawnCount);
        respawnIndex = g_GlobalPE->mRespawnIndexBySlot[secondSlot];
        g_GlobalPE->mRespawnIndexBySlot[secondSlot] = g_GlobalPE->mRespawnIndexBySlot[firstSlot];
        g_GlobalPE->mRespawnIndexBySlot[firstSlot] = respawnIndex;
    }
}

s32 NkmHandler_KTP2_from_thumb(void *section, ...) {
    g_GlobalPE->mSubScreenViewCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    g_GlobalPE->mSubScreenView = section;
    return 1;
}

void InitializePECannonTable_from_thumb(void) {
    u16 placementCount;
    u16 placementIndex;

    placementCount = g_GlobalPE->mKeyedPlacementCount;
    if (placementCount == 0) {
        g_GlobalPE->mKeyedPlacementIndexByKey = NULL;
        return;
    }
    g_GlobalPE->mKeyedPlacementIndexByKey = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), placementCount * 2);
    for (placementIndex = 0; placementIndex < placementCount; placementIndex++) {
        g_GlobalPE->mKeyedPlacementIndexByKey[g_GlobalPE->mKeyedPlacements[placementIndex].mKey] = placementIndex;
    }
}

s32 NkmHandler_KTPC_from_thumb(void *section, ...) {
    BOOL loaded = FALSE;

    if (g_GlobalPE->mVersion < COURSE_MAP_VERSION_KEYED_PLACEMENTS) {
        g_GlobalPE->mKeyedPlacementCount = 0;
        g_GlobalPE->mKeyedPlacements = NULL;
    } else {
        g_GlobalPE->mKeyedPlacementCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
        g_GlobalPE->mKeyedPlacements = section;
        loaded = TRUE;
    }
    InitializePECannonTable_from_thumb();
    return loaded;
}

s32 NkmHandler_KTPM_from_thumb(void *section, ...) {
    enum { RESULT_EMPTY } result = 0;

    if (g_GlobalPE->mVersion < COURSE_MAP_VERSION_RACE_END_PLACEMENTS) {
        g_GlobalPE->mRaceEndPlacementCount = result;
        g_GlobalPE->mRaceEndPlacements = NULL;
        return result;
    }
    g_GlobalPE->mRaceEndPlacementCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mRaceEndPlacementCount != 0) {
        g_GlobalPE->mRaceEndPlacements = section;
    } else {
        g_GlobalPE->mRaceEndPlacements = NULL;
    }
    return 1;
}

s32 NkmHandler_CPOI_from_thumb(void *section, ...) {
    u16 checkpointIndex;
    u16 numberedCount;

    g_GlobalPE->mCheckpointCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mCheckpointCount == 0) {
        g_GlobalPE->mCheckpoints = NULL;
        return 1;
    }
    g_GlobalPE->mCheckpoints = section;
    numberedCount = 0;
    for (checkpointIndex = 0; checkpointIndex < g_GlobalPE->mCheckpointCount; checkpointIndex++) {
        if (g_GlobalPE->mCheckpoints[checkpointIndex].mNumber != COURSE_MAP_CHECKPOINT_NO_NUMBER) {
            numberedCount++;
        }
    }
    g_GlobalPE->mNumberedCheckpointCount = numberedCount;
    return 1;
}

s32 NkmHandler_CPAT_from_thumb(void *section, ...) {
    s32 routeIndex;
    CourseMapRoute *lastRoute;
    s32 firstEntry;

    g_GlobalPE->mCheckpointRouteCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mCheckpointRouteCount == 0) {
        g_GlobalPE->mCheckpointRoutes = NULL;
        g_GlobalPE->mLastCheckpoint = 0;
        return 1;
    }
    g_GlobalPE->mCheckpointRoutes = section;
    for (routeIndex = 0; routeIndex < g_GlobalPE->mCheckpointRouteCount; routeIndex++) {
        if (GetCheckpointRoute(routeIndex)->mFirstEntry == 0) {
            lastRoute = GetCheckpointRoute((s8) GetCheckpointRoute(routeIndex)->mPreviousRoutes[0]);
            firstEntry = GetCheckpointRoute((s8) GetCheckpointRoute(routeIndex)->mPreviousRoutes[0])->mFirstEntry;
            g_GlobalPE->mLastCheckpoint = firstEntry + lastRoute->mEntryCount - 1;
            break;
        }
    }
    return 1;
}

s32 NkmHandler_IPOI_from_thumb(void *section, ...) {
    g_GlobalPE->mItemPointCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mItemPointCount == 0) {
        g_GlobalPE->mItemPoints = NULL;
    } else {
        g_GlobalPE->mItemPoints = section;
    }
    return 1;
}

s32 NkmHandler_IPAT_from_thumb(void *section, ...) {
    g_GlobalPE->mItemRouteCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mItemRouteCount == 0) {
        g_GlobalPE->mItemRoutes = NULL;
    } else {
        g_GlobalPE->mItemRoutes = section;
    }
    return 1;
}

s32 NkmHandler_EPOI_from_thumb(void *section, ...) {
    if (g_GlobalPE->mStartPlacementCount > 1) {
        g_GlobalPE->mBattlePointCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
        if (g_GlobalPE->mBattlePointCount == 0) {
            g_GlobalPE->mBattlePoints = NULL;
        } else {
            g_GlobalPE->mBattlePoints = section;
            g_GlobalPE->mRacePoints = NULL;
            g_GlobalPE->mRacePointCount = 0;
        }
    } else {
        g_GlobalPE->mRacePointCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
        if (g_GlobalPE->mRacePointCount == 0) {
            g_GlobalPE->mRacePoints = NULL;
        } else {
            g_GlobalPE->mRacePoints = section;
            g_GlobalPE->mBattlePoints = NULL;
            g_GlobalPE->mBattlePointCount = 0;
        }
    }
    return 1;
}

s32 NkmHandler_EPAT_from_thumb(void *section, ...) {
    if (g_GlobalPE->mStartPlacementCount > 1) {
        g_GlobalPE->mBattleRouteCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
        if (g_GlobalPE->mBattleRouteCount == 0) {
            g_GlobalPE->mBattleRoutes = NULL;
        } else {
            g_GlobalPE->mBattleRoutes = section;
            g_GlobalPE->mRaceRoutes = NULL;
            g_GlobalPE->mRaceRouteCount = 0;
        }
    } else {
        g_GlobalPE->mRaceRouteCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
        if (g_GlobalPE->mRaceRouteCount == 0) {
            g_GlobalPE->mRaceRoutes = NULL;
        } else {
            g_GlobalPE->mRaceRoutes = section;
            g_GlobalPE->mBattleRoutes = NULL;
            g_GlobalPE->mBattleRouteCount = 0;
        }
    }
    return 1;
}
#pragma thumb off

#pragma thumb on

CourseMapShape *GetGlobalPENkmAREAByIndex_from_thumb(u32 shapeIndex) {
    return &g_GlobalPE->mShapes[shapeIndex];
}

#pragma thumb off

#pragma thumb on
void InitializeAreaType3s_from_thumb(void) {
    void *heap;
    CourseMapShape *shape;
    CourseMapZoneShapeNode **nodeSlot;
    u16 shapeIndex;
    u16 listIndex;

    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    shapeIndex = 0;
    for (listIndex = 0; listIndex < 8; listIndex++) {
        g_GlobalPE->mZoneShapeLists[listIndex] = NULL;
    }
    for (shapeIndex = 0; shapeIndex < g_GlobalPE->mShapeCount; shapeIndex++) {
        shape = GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_ZONE) {
            nodeSlot = &g_GlobalPE->mZoneShapeLists[(s16) shape->mKindValue];
            while (*nodeSlot != NULL) {
                nodeSlot = &(*nodeSlot)->mNext;
            }
            *nodeSlot = Mem_AllocateHeap(heap, 8);
            (*nodeSlot)->mShape = shape;
            (*nodeSlot)->mNext = NULL;
        }
    }
}
#pragma thumb off

#pragma thumb on

void CountAreaType4_from_thumb(void) {
    u16 count;
    u16 shapeIndex;
    count = 0;
    for (shapeIndex = 0; shapeIndex < g_GlobalPE->mShapeCount; shapeIndex++) {
        if (GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex)->mKind == COURSE_MAP_SHAPE_KIND_POINT_LINK) {
            count++;
        }
    }
    g_GlobalPE->mPointLinkShapeCount = count;
}

void CountAreaType2_from_thumb(void) {
    u8 count;
    u16 shapeIndex;
    count = 0;
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        for (shapeIndex = 0; shapeIndex < g_GlobalPE->mShapeCount; shapeIndex++) {
            if (GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex)->mKind == COURSE_MAP_SHAPE_KIND_MISSION_END) {
                count++;
            }
        }
    }
    g_GlobalPE->mMissionEndShapeCount = count;
}

#pragma thumb off

#pragma thumb on
s32 NkmHandler_AREA_from_thumb(void *section, ...) {
    g_GlobalPE->mShapeCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mShapeCount == 0) {
        g_GlobalPE->mShapes = NULL;
    } else {
        g_GlobalPE->mShapes = section;
    }
    InitializeAreaType3s_from_thumb();
    CountAreaType4_from_thumb();
    CountAreaType2_from_thumb();
    return 1;
}

s32 NkmHandler_CAME_from_thumb(void *section, ...) {
    u16 cameraIndex;
    CourseMapCamera *camera;

    g_GlobalPE->mCameraCount = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&section);
    if (g_GlobalPE->mCameraCount == 0) {
        g_GlobalPE->mCameras = NULL;
        return 1;
    }
    g_GlobalPE->mCameras = section;
    g_GlobalPE->mFirstChainStartEntry = NULL;
    g_GlobalPE->mSecondChainStartEntry = NULL;
    g_GlobalPE->mFirstAngleStartCamera = NULL;
    g_GlobalPE->mFirstBattleSequenceCamera = NULL;
    for (cameraIndex = 0; cameraIndex < g_GlobalPE->mCameraCount; cameraIndex++) {
        camera = g_GlobalPE->mCameras + cameraIndex;
        if (g_GlobalPE->mFirstChainStartEntry == NULL && camera->mChainStart == CAMERA_CHAIN_START_FIRST) {
            g_GlobalPE->mFirstChainStartEntry = camera;
        }
        if (g_GlobalPE->mSecondChainStartEntry == NULL && camera->mChainStart == CAMERA_CHAIN_START_SECOND) {
            g_GlobalPE->mSecondChainStartEntry = camera;
        }
        if (g_GlobalPE->mFirstAngleStartCamera == NULL && camera->mKind == COURSE_MAP_CAMERA_KIND_ANGLE_START) {
            g_GlobalPE->mFirstAngleStartCamera = camera;
        }
        if (g_GlobalCO->mMode == MODE_BATTLE && g_GlobalPE->mFirstBattleSequenceCamera == NULL &&
            camera->mKind == COURSE_MAP_CAMERA_KIND_SEQUENCE) {
            g_GlobalPE->mFirstBattleSequenceCamera = camera;
        }
        if (g_GlobalCO->mMode == MODE_MISSION_RUN && g_GlobalPE->mFirstMissionRunCamera == NULL &&
            camera->mKind == COURSE_MAP_CAMERA_KIND_MISSION_RUN) {
            g_GlobalPE->mFirstMissionRunCamera = camera;
        }
    }
    return 1;
}

void LoadCourseMapNkm_from_thumb(void *heap) {
    char path[0x100];
    CourseMapHeader *header;
    CourseMap *courseMap;
    s32 *offset;
    u8 *base;
    s32 sectionIndex;
    u16 routeIndex;

    switch (g_GlobalCO->mMode) {
        case MODE_MISSION_RUN:
            if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
                header = FindFileBuffer_CRS_CST_from_thumb("/course_map.nkm");
            } else {
                _snprintf(path, 0x100, "/MissionRun/%s_tool.nkm", g_GlobalCO->mMissionRunStem);
                header = FindFileBuffer_CRS_CST_from_thumb(path);
            }
            break;
        case MODE_WIFI:
            header = FindFileBuffer_CRS_CST_from_thumb("/Net/net_course_map.nkm");
            if (header == NULL) {
                header = FindFileBuffer_CRS_CST_from_thumb("/course_map.nkm");
            }
            break;
        default:
            header = FindFileBuffer_CRS_CST_from_thumb("/course_map.nkm");
            break;
    }
    courseMap = AllocateStructPE_from_thumb(heap);
    g_GlobalPE = courseMap;
    courseMap->mVersion = header->mVersion;
    offset = header->mSectionOffsets;
    base = (u8 *) header + header->mBaseOffset;
    for (sectionIndex = 0; sectionIndex < 17; sectionIndex++) {
        if (g_NkmSectionFnTable[sectionIndex](base + *offset) != 0) {
            offset++;
        }
    }
    PopulatePathEntries_from_thumb(heap);
    BuildCourseMapPointLinks(heap);
    g_GlobalPE->mLapProgressBaseMax = 0;
    for (routeIndex = 0; routeIndex < g_GlobalPE->mCheckpointRouteCount; routeIndex++) {
        if (g_GlobalPE->mCheckpointRoutes[routeIndex].mLapProgressBase > g_GlobalPE->mLapProgressBaseMax) {
            g_GlobalPE->mLapProgressBaseMax = g_GlobalPE->mCheckpointRoutes[routeIndex].mLapProgressBase;
        }
    }
}
#pragma thumb off

CourseMapGroupEntry *GetLoadedNkmPathEntryPOIT(u16 groupIndex, u16 entryIndex) {
    return GetLoadedNkmPathEntry_from_thumb(groupIndex)->mEntries + entryIndex;
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

    if (g_GlobalPE->mSettings->mStartSideFlipped != 0) {
        firstAxisOffset = 0x1000 - firstAxisOffset;
    }
    if (g_GlobalPE->mStartPlacementCount > 1) {
        for (placementIndex = 0; placementIndex < g_GlobalPE->mStartPlacementCount; placementIndex++) {
            candidate = &(g_GlobalPE->mStartPlacements)[placementIndex];
            if (key == (s16) candidate->mKey) {
                placement = candidate;
                break;
            }
        }
    } else {
        placement = g_GlobalPE->mStartPlacements;
    }
    angleX = FROM_FIXED12(placement->mRotation.x) * 0xb6;
    angleY = FROM_FIXED12(placement->mRotation.y) * 0xb6;
    angleZ = FROM_FIXED12(placement->mRotation.z) * 0xb6;
    MTX_RotX43__from_thumb(&rotationMatrixX, FX_SinIdx(angleX), FX_CosIdx(angleX));
    MTX_RotY43__from_thumb(&rotationMatrixY, FX_SinIdx(angleY), FX_CosIdx(angleY));
    MTX_RotZ43__from_thumb(&rotationMatrixZ, FX_SinIdx(angleZ), FX_CosIdx(angleZ));
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
    u16 lastKartIndex = g_GlobalCO->mKartCount - 1;
    s32 rankIndex = (u16) (GetKartStartRank(kartIndex) - 1);
    s32 firstGroupCount;
    s32 groupCount;
    s32 groupPosition;
    s32 groupIndex;
    s32 sideOffset;

    if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
        GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0, 0);
        return;
    }
    switch (g_GlobalCO->mMode) {
        case MODE_BATTLE:
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation,
                                                  (u16) ((rankIndex + g_GlobalMV->mStartPlacementOffset) % 8), 0, 0);
            break;
        case MODE_TIME_ATTACK:
            GetCourseMapStartPlacementWithOffsets(outPos, outRotation, 0, 0x800, 0);
            break;
        case MODE_MISSION_RUN:
            if (g_GlobalCO->mKartCount <= 1) {
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

    VecFx32_Subtract(pos, &shape->mPos, &offset);
    distance = Vector3_DotProduct(&offset, &shape->mAxisY);
    if (distance > MUL_FIXED12_ROUNDED(shape->mScale.y, 0x64000) || distance < 0) {
        return FALSE;
    }
    distance = Vector3_DotProduct(&offset, &shape->mAxisX);
    extent = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000);
    if (distance < -extent || distance > extent) {
        return FALSE;
    }
    distance = Vector3_DotProduct(&offset, &shape->mAxisZ);
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
            VecFx32_Subtract(pos, &shape->mPos, &offset);
            if (Vector3_DotProduct(&offset, &shape->mAxisY) > MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                inside = 0;
            } else {
                distanceX = Vector3_DotProduct(&offset, &shape->mAxisX) >> 4;
                distanceZ = Vector3_DotProduct(&offset, &shape->mAxisZ) >> 4;
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

    for (shapeIndex = 0; shapeIndex < g_GlobalPE->mShapeCount; shapeIndex++) {
        shape = GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_MISSION_END) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VecFx32_Subtract(pos, &shape->mPos, &offset);
                    if (Vector3_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        distanceX = Vector3_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = Vector3_DotProduct(&offset, &shape->mAxisZ) >> 4;
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

    if (g_GlobalPE->mPointLinkShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < g_GlobalPE->mShapeCount; shapeIndex++) {
        shape = GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_POINT_LINK) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VecFx32_Subtract(pos, &shape->mPos, &offset);
                    if (Vector3_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        distanceX = Vector3_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = Vector3_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                        if (MUL_FIXED12_ROUNDED(radius, radius) >=
                            MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = &g_GlobalPE->mRacePointLinks[shape->mPointIndex];
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

    if (g_GlobalPE->mPointLinkShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < g_GlobalPE->mShapeCount; shapeIndex++) {
        shape = GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_POINT_LINK) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VecFx32_Subtract(pos, &shape->mPos, &offset);
                    if (Vector3_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        distanceX = Vector3_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = Vector3_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = MUL_FIXED12_ROUNDED(shape->mScale.x, 0x32000) >> 4;
                        if (MUL_FIXED12_ROUNDED(radius, radius) >=
                            MUL_FIXED12_ROUNDED(distanceX, distanceX) + MUL_FIXED12_ROUNDED(distanceZ, distanceZ)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = &g_GlobalPE->mBattlePointLinks[shape->mPointIndex];
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

    for (shapeIndex = 0; shapeIndex < g_GlobalPE->mShapeCount; shapeIndex++) {
        shape = GetGlobalPENkmAREAByIndex_from_thumb(shapeIndex);
        if (shape->mKind == COURSE_MAP_SHAPE_KIND_CAMERA) {
            inside = 0;
            switch (shape->mShapeKind) {
                case COURSE_MAP_SHAPE_FORM_BOX:
                    inside = IsPosInCourseMapShapeBox(pos, shape);
                    break;
                case COURSE_MAP_SHAPE_FORM_CYLINDER:
                    VecFx32_Subtract(pos, &shape->mPos, &offset);
                    if (Vector3_DotProduct(&offset, &shape->mAxisY) > MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                        inside = 0;
                    } else {
                        distanceX = Vector3_DotProduct(&offset, &shape->mAxisX) >> 4;
                        distanceZ = Vector3_DotProduct(&offset, &shape->mAxisZ) >> 4;
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
u16 GetCourseCpoiRespawnId(u32 checkpointIndex) {
    u16 respawnSlot;
    CourseMap *courseMap;

    if (g_GlobalCO->mMode == MODE_BATTLE) {
        courseMap = g_GlobalPE;
        respawnSlot = courseMap->mNextRespawnSlot;
        courseMap->mNextRespawnSlot = (respawnSlot + 1) % courseMap->mRespawnCount;
    } else {
        respawnSlot = g_GlobalPE->mCheckpoints[checkpointIndex].mRespawnSlot;
    }
    return respawnSlot;
}

void *GetCourseMapRespawnRacePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (g_GlobalPE->mCheckpoints == NULL && g_GlobalPE->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &g_GlobalPE->mRespawns[g_GlobalPE->mRespawnIndexBySlot[slot]];
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
    return &g_GlobalPE->mRacePointLinks[pointIndex];
}

PointLink *GetCourseMapRespawnBattlePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (g_GlobalPE->mCheckpoints == NULL && g_GlobalPE->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &g_GlobalPE->mRespawns[g_GlobalPE->mRespawnIndexBySlot[slot]];
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
    return &g_GlobalPE->mBattlePointLinks[pointIndex];
}

struct ItemPointLink *GetCourseMapRespawnItemPointLink(u16 slot) {
    CourseMapRespawn *respawn;

    if (g_GlobalPE->mCheckpoints == NULL && g_GlobalPE->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &g_GlobalPE->mRespawns[g_GlobalPE->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        return NULL;
    }
    return &g_GlobalPE->mItemPointLinks[respawn->mItemPointIndex];
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

    node = g_GlobalPE->mZoneShapeLists[listIndex];
    LoadRacerMQVectorB(&kartPos, kartIndex);
    for (; found == FALSE && node != NULL; node = node->mNext) {
        shape = node->mShape;
        inside = 0;
        switch (shape->mShapeKind) {
            case COURSE_MAP_SHAPE_FORM_BOX:
                inside = IsPosInCourseMapShapeBox(&kartPos, shape);
                break;
            case COURSE_MAP_SHAPE_FORM_CYLINDER:
                VecFx32_Subtract(&kartPos, &shape->mPos, &offset);
                if (Vector3_DotProduct(&offset, &shape->mAxisY) <= MUL_FIXED12_ROUNDED(shape->mScale.y, 0x32000)) {
                    distanceX = Vector3_DotProduct(&offset, &shape->mAxisX) >> 4;
                    distanceZ = Vector3_DotProduct(&offset, &shape->mAxisZ) >> 4;
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
