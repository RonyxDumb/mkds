#pragma once

#include "types.h"

typedef struct Segment Segment;
typedef struct CourseMapEntryGroup CourseMapEntryGroup;

#include "Main/Unknown/unk_0217b000.h"

void pw_initFromPathId(GroupFollower *follower, u16 groupIndex, int speed);
void pw_setupPaths(void);
void pw_setupPath(u32 groupIndex, CourseMapEntryGroup *entryGroup);
void pw_setupPoint(Segment *segment, s32 useStraightLength, s32 computeUp, Vec3 *previousPoint, Vec3 *startPoint,
                  Vec3 *endPoint, Vec3 *nextPoint);
void pwex_interpolateXZLinearY(void *segmentProgressPointer, Vec3 *position);
