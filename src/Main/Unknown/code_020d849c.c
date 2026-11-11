#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d8cac.h"

void ReverseGroupFollower(GroupFollower *follower) {
    CourseMapGroupEntry *savedEntry = follower->mFromEntry;
    follower->mFromEntry = follower->mToEntry;
    follower->mToEntry = savedEntry;
    follower->mForward = follower->mForward == 0;
}

void SetupGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower, u16 entryIndex, s32 forward) {
    s32 entryValue;
    s32 speed;
    SetupGroupFollowerAtEntry(&follower->mGroupFollower, entryIndex, forward);
    entryValue = follower->mGroupFollower.mFromEntry->mUnk_0e;
    follower->mFromSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    follower->mUnk_30 = follower->mFromSpeed;
    entryValue = follower->mGroupFollower.mToEntry->mUnk_0e;
    follower->mToSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    speed = follower->mUnk_30;
    follower->mGroupFollower.mSpeed = speed;
    follower->mGroupFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
        speed,
        follower->mGroupFollower.mPath->mSegments[follower->mGroupFollower.mSegmentIndex].mInverseProgressLength);
}

s32 AdvanceGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower) {
    s32 crossedEnd;
    s32 entryValue;
    s32 blend;
    s32 speed;
    crossedEnd = AdvanceGroupFollower(&follower->mGroupFollower);
    if (crossedEnd != 0) {
        follower->mFromSpeed = follower->mToSpeed;
        entryValue = follower->mGroupFollower.mToEntry->mUnk_0e;
        follower->mToSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    }
    if (follower->mFromSpeed != follower->mToSpeed) {
        blend = GetGroupFollowerProgress(&follower->mGroupFollower);
        speed = MUL_FIXED12_NO_ROUND(follower->mFromSpeed, 0x1000 - blend) +
                MUL_FIXED12_NO_ROUND(follower->mToSpeed, blend);
        follower->mGroupFollower.mSpeed = speed;
        follower->mGroupFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
            speed,
            follower->mGroupFollower.mPath->mSegments[follower->mGroupFollower.mSegmentIndex].mInverseProgressLength);
    }
    return crossedEnd;
}

void SetSegmentProgressRate(SegmentProgress *segmentProgress, s32 value) {
    s32 inverseLength = segmentProgress->mSegment.mInverseProgressLength;
    segmentProgress->mRate = value;
    value = inverseLength != 0 ? MUL_FIXED12_NO_ROUND(value, inverseLength) : 0x1000000;
    segmentProgress->mProgressStep = value;
}

BOOL AdvanceSegmentProgress(SegmentProgress *segmentProgress) {
    segmentProgress->mProgress = segmentProgress->mProgress + segmentProgress->mProgressStep;
    return segmentProgress->mProgress >= 0x1000000;
}
