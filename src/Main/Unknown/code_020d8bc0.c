#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d939c.h"
#include "Main/Unknown/code_020e005c.h"

void pw_20D8BF8_XYZ(GroupFollower *follower, Vec3 *position, Vec3 *step) {
    pw_20D939C(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress,
                           follower->mProgressStep, position, step);
    if (follower->mForward == 0) {
        step->x = -step->x;
        step->y = -step->y;
        step->z = -step->z;
    }
}

void pw_calcCurrentPointXZLinearY(GroupFollower *follower, Vec3 *position) {
    pw_interpolateXZLinearY(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress, position);
}
