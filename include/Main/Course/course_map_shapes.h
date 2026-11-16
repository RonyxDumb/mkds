#pragma once

#include "types.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_objects_and_race_progress.h"

extern const u8 gKartStartGroupCounts[16];

// TRUE when the position of kart a lies inside any shape of list b of mZoneShapeLists.
s32 IsKartInCourseMapZoneShapeList(s32 kartIndex, u32 listIndex);
// Returns the element of mItemPointLinks given by mItemPointIndex of the respawn spot of slot a, NULL when there is no
// respawn spot.
struct ItemPointLink *GetCourseMapRespawnItemPointLink(u16 slot);
// Looks up the respawn spot of slot a: writes its position to b and its rotation angles to c (a default position and
// angles when there is none) and returns its element of mBattlePointLinks (mPointIndex), NULL for -1.
BattlePointLink *GetCourseMapRespawnBattlePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation);
// Looks up the respawn spot of slot a: writes its position to b and its rotation angles to c (a default position and
// angles when there is none) and returns its element of mRacePointLinks (mPointIndex), NULL for -1.
void *GetCourseMapRespawnRacePointLink(u32 slot, Vec3 *outPos, Vec3 *outRotation);
u16 GetCourseMapRespawnSlot(u32 checkpointIndex);
// Returns CourseMapShape.mCameraIndex of the first shape of mKind 1 that contains position a, or -1 when there is none.
s32 GetCourseMapCameraIndexAtPos(Vec3 *pos);
// Returns the element of mBattlePointLinks given by mPointIndex of the first mKind 4 shape that contains position a, or
// NULL; NULL at once when the course has no kind 4 shapes.
BattlePointLink *FindCourseMapPointLinkShapeBattlePointLink(Vec3 *pos);
// Returns the element of mRacePointLinks given by mPointIndex of the first mKind 4 shape that contains position a, or
// NULL; NULL at once when the course has no kind 4 shapes.
void *FindCourseMapPointLinkShapeRacePointLink(Vec3 *pos);
s32 IsPosInCourseMapMissionEndShape(Vec3 *pos, s32 *outFlag);
s32 IsPosInCourseMapShape(Vec3 *pos, CourseMapShape *shape);
BOOL IsPosInCourseMapShapeBox(Vec3 *pos, CourseMapShape *shape);
void GetCourseMapKartStartPlacement(Vec3 *outPos, Vec3 *outRotation, s32 kartIndex);
void GetCourseMapStartPlacementWithOffsets(Vec3 *outPos, Vec3 *outRotation, s32 key, s32 firstAxisOffset,
                                           s32 thirdAxisOffset);
