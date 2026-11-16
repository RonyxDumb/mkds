#pragma once

#include "types.h"

typedef struct Segment Segment;
typedef struct GroupFollower GroupFollower;

s32 pw_getProgress(GroupFollower *p);
void pw_interpolateXZLinearY(Segment *segment, s32 fraction, Vec3 *result);
void pw_20D9270_XZ(Segment *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult);
BOOL pw_update(GroupFollower *path);
void pw_init(GroupFollower *path, u16 follower, s32 entryIndex);
