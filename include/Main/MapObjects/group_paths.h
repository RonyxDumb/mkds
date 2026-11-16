#pragma once

#include "types.h"

typedef struct Segment Segment;
typedef struct CourseMapEntryGroup CourseMapEntryGroup;

#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/segment_group_collision.h"

void InitGroupFollowerForGroup(GroupFollower *follower, u16 groupIndex, int speed);
void InitGroupPaths(void);
void BuildGroupPath(u32 groupIndex, CourseMapEntryGroup *entryGroup);
void BuildSegment(Segment *segment, s32 useStraightLength, s32 computeUp, Vec3 *previousPoint, Vec3 *startPoint,
                  Vec3 *endPoint, Vec3 *nextPoint);
void GetSegmentProgressPointXzLinearY(SegmentProgress *segmentProgress, Vec3 *position);

extern const Vec3 gGroupPathZeroLengthUp;
extern const Vec3 gGroupPathUpAxis;
extern struct GroupPath *gGroupPaths;
