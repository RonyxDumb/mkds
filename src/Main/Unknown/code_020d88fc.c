#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020e005c.h"

Vec3 *GetGroupFollowerSegmentUp(GroupFollower *follower) {
    return &follower->mPath->mSegments[follower->mSegmentIndex].mUp;
}
