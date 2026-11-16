#pragma once

#include "types.h"

typedef struct GroupFollower GroupFollower;

void pw_20D8B18_XZ(GroupFollower *follower, Vec3 *position, Vec3 *step);
void pw_calcCurrentPointLinearXYZ(GroupFollower *follower, Vec3 *position);
void pw_calcCurrentPointLinearXYZSpecial(GroupFollower *follower, Vec3 *position, Vec3 *step);
