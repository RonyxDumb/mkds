#pragma once

#include "types.h"

// The header of a course map file: its format version, the base offset and the offsets of its sections.
typedef struct CourseMapHeader {
    /* 00 */ u8 mLink[4];
    /* 04 */ u16 mVersion;
    /* 06 */ u16 mBaseOffset;
    /* 08 */ s32 mSectionOffsets[1];
} CourseMapHeader;

typedef s32 (*CourseMapSectionLoader)(void *section, ...);

extern const CourseMapSectionLoader g_NkmSectionFnTable[17];

#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"

void LoadCourseMapNkm_from_thumb(void *heap);

typedef struct RandomState64 RandomState64;

typedef struct CourseMapRoute CourseMapRoute;
typedef struct RacePointLink RacePointLink;
typedef struct ItemPointLink ItemPointLink;

// Takes the camera section: stores mCameraCount and mCameras (NULL when empty) and remembers the first entry of chain
// 1, chain 2, kind 6, kind 7 (battle) and kind 8 (mission run) in the CourseMap members of those names. Returns 1.
s32 NkmHandler_CAME_from_thumb(void *section, ...);
// Takes the shape section: stores mShapeCount and mShapes (NULL when empty), then builds the kind 3 lists and counts
// the kind 4 shapes and, in mission run, the kind 2 shapes. Returns 1.
s32 NkmHandler_AREA_from_thumb(void *section, ...);
void CountAreaType2_from_thumb(void);
void CountAreaType4_from_thumb(void);
void InitializeAreaType3s_from_thumb(void);
CourseMapShape *GetGlobalPENkmAREAByIndex_from_thumb(u32 shapeIndex);
// Takes the route section of table entry 14: with several start placements it stores mBattleRouteCount and
// mBattleRoutes, otherwise mRaceRouteCount and mRaceRoutes; when the section is not empty the other pair is cleared.
// Returns 1.
s32 NkmHandler_EPAT_from_thumb(void *section, ...);
// Takes the point section of table entry 13: with several start placements it stores mBattlePointCount and
// mBattlePoints, otherwise mRacePointCount and mRacePoints; when the section is not empty the other pair is cleared.
// Returns 1.
s32 NkmHandler_EPOI_from_thumb(void *section, ...);
// Takes the item route section: stores mItemRouteCount and mItemRoutes (NULL when empty). Returns 1.
s32 NkmHandler_IPAT_from_thumb(void *section, ...);
// Takes the item point section: stores mItemPointCount and mItemPoints (NULL when empty). Returns 1.
s32 NkmHandler_IPOI_from_thumb(void *section, ...);
s32 NkmHandler_CPAT_from_thumb(void *section, ...);
s32 NkmHandler_CPOI_from_thumb(void *section, ...);
s32 NkmHandler_KTPM_from_thumb(void *section, ...);
// Takes the keyed placement section when the format version is 0x1f or more (else clears mKeyedPlacementCount and
// mKeyedPlacements), then builds the index by key. Returns 1 when the version has the section, else 0 and the same
// section offset goes to the next loader.
s32 NkmHandler_KTPC_from_thumb(void *section, ...);
// Allocates mKeyedPlacementIndexByKey (one halfword per record) and stores in it the index of each record at its key;
// NULL when there are no records.
void InitializePECannonTable_from_thumb(void);
s32 NkmHandler_KTP2_from_thumb(void *section, ...);
void ShuffleCourseMapRespawnSlots(RandomState64 *randomState64);
s32 NkmHandler_KTPJ_from_thumb(void *section, ...);
s32 NkmHandler_KTPS_from_thumb(void *section, ...);
typedef struct CourseMapSettingsSection CourseMapSettingsSection;
u32 NkmHandler_STAG_from_thumb(CourseMapSettingsSection *section);
// Called once by LoadCourseMapNkm_from_thumb after the sections are loaded: builds mItemPointLinks when mItemRouteCount is not 0,
// and mRacePointLinks when mRaceRouteCount is not 0, else mBattlePointLinks when mBattleRouteCount is not 0.
void BuildCourseMapPointLinks(void *heap);
// Allocates mBattlePointLinks (one per battle point) and clears it, stores the first link and the end pointer in the
// next two CourseMap members, then fills each link from its point and its route: the first point of a route joins the
// routes named by the bytes at 0x0c of the route, the last point those named by the bytes at 0x04, inner points the
// next and previous point.
void BuildCourseMapBattlePointLinks(void *heap);
// Allocates mRacePointLinks (one per race point) and clears it, stores the link of the first point of route 0 and the
// link of the last point of the route before route 0 in the next two CourseMap members, links the points route by route
// from route 0 (BuildCourseMapRaceRouteLinks), then starts every route whose first point has no previous link.
void BuildCourseMapRacePointLinks(void *heap);
// Fills the link of point c of route b (pointer to its point and two values), joins it to link a when a is not NULL,
// then goes on with the next point of the route and, at the route end, with the first point of each following route
// (255 = none).
void BuildCourseMapRaceRouteLinks(RacePointLink *previousLink, CourseMapRoute *route, u16 pointIndex);
// Allocates mItemPointLinks (one per item point) and clears it, stores the link of the first point of route 0 and the
// link of the last point of the route before route 0 in the next two CourseMap members, then links the points route by
// route from route 0 (BuildCourseMapItemRouteLinks).
void BuildCourseMapItemPointLinks(void *heap);
// Fills the link of point c of route b (pointer to its point and two values), joins it to link a as next and previous
// (skipped when already joined), then goes on with the next point of the route and, at the route end, with the first
// point of each following route other than route 0 and 255.
void BuildCourseMapItemRouteLinks(ItemPointLink *previousLink, CourseMapRoute *route, u16 pointIndex);
CourseMapEntryGroupTableRow *GetLoadedNkmPathEntry_from_thumb(unsigned int groupIndex);
void PopulatePathEntries_from_thumb(void *heap);
void ComputeTotalCpatDistance_from_thumb(void);
s32 ComputeTotalDistanceRecursively_from_thumb(u16 routeIndex);
s32 NkmHandler_POIT_from_thumb(void *section, ...);
s32 NkmHandler_PATH_from_thumb(void *section, ...);
s32 NkmHandler_OBJI_from_thumb(void *section, ...);
u16 NkmSection_AdvanceHeaderGetEntryCount_from_thumb(void **cursor);
