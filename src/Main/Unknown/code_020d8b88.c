#include "Main/Unknown/code_020d8b88.h"
#include "Main/Unknown/code_020d9340.h"
#include "Main/Unknown/code_020e005c.h"

void GetGroupFollowerCurveXz(GroupFollower *follower, Vec3 *output) {
    GetCurvePointXz(follower->mPath->mSegments[follower->mSegmentIndex].mPoints, follower->mProgress, output);
}
