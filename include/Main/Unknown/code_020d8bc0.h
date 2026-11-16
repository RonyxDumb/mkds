#pragma once

#include "types.h"

typedef struct GroupFollower GroupFollower;

void pw_20D8BF8_XYZ(GroupFollower *follower, Vec3 *position, Vec3 *step);
void pw_calcCurrentPointXZLinearY(GroupFollower *follower, Vec3 *position);
