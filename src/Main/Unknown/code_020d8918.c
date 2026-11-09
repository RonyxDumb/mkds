#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e005c.h"
#include "code_02147cd8.h"

void GetGroupFollowerCurvePosStepXz(GroupFollower *follower, Vec3 *position, Vec3 *step) {
    GetSegmentCurvePosStepXz(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress,
                             follower->mProgressStep, position, step);
    if (follower->mForward == 0) {
        step->x = -step->x;
        step->z = -step->z;
    }
}

void GetGroupFollowerLinearPosition(GroupFollower *follower, Vec3 *position) {
    Segment *segment;
    s32 progress;
    s32 remaining;
    segment = &follower->mPath->mSegments[follower->mSegmentIndex];
    progress = follower->mProgress;
    remaining = 0x1000000 - progress;
    position->x = MUL_FIXED24_NO_ROUND(segment->mPoints[0].x, remaining);
    position->y = MUL_FIXED24_NO_ROUND(segment->mPoints[0].y, remaining);
    position->z = MUL_FIXED24_NO_ROUND(segment->mPoints[0].z, remaining);
    position->x = position->x + MUL_FIXED24_NO_ROUND(segment->mPoints[3].x, progress);
    position->y = position->y + MUL_FIXED24_NO_ROUND(segment->mPoints[3].y, progress);
    position->z = position->z + MUL_FIXED24_NO_ROUND(segment->mPoints[3].z, progress);
}

void GetGroupFollowerLinearPosStep(GroupFollower *follower, Vec3 *position, Vec3 *step) {
    Segment *segment;
    s32 progress;
    s32 remaining;
    s32 rate;
    segment = &follower->mPath->mSegments[follower->mSegmentIndex];
    progress = follower->mProgress;
    remaining = 0x1000000 - progress;
    position->x = MUL_FIXED24_NO_ROUND(segment->mPoints[0].x, remaining);
    position->y = MUL_FIXED24_NO_ROUND(segment->mPoints[0].y, remaining);
    position->z = MUL_FIXED24_NO_ROUND(segment->mPoints[0].z, remaining);
    position->x = position->x + MUL_FIXED24_NO_ROUND(segment->mPoints[3].x, progress);
    position->y = position->y + MUL_FIXED24_NO_ROUND(segment->mPoints[3].y, progress);
    position->z = position->z + MUL_FIXED24_NO_ROUND(segment->mPoints[3].z, progress);
    VEC_Subtract(&segment->mPoints[3], &segment->mPoints[0], step);
    rate = follower->mProgressStep;
    step->x = MUL_FIXED24_NO_ROUND(step->x, rate);
    step->y = MUL_FIXED24_NO_ROUND(step->y, rate);
    step->z = MUL_FIXED24_NO_ROUND(step->z, rate);
    if (follower->mForward == 0) {
        step->x = -step->x;
        step->y = -step->y;
        step->z = -step->z;
    }
}
