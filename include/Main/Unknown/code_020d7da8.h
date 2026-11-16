#pragma once

#include "types.h"

typedef struct GroupFollower GroupFollower;
typedef struct CourseMapRow CourseMapRow;

void pw_initFromObject(GroupFollower *follower, CourseMapRow *row, s32 speed);
