#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020d9480.h"
#include "Main/Unknown/code_020e005c.h"

void GetGroupFollowerCurvePosition(GroupFollower *follower, Vec3 *output) {
    GetCurvePoint((u32) &follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress, (u32) output);
}
