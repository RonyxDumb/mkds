#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d8cac.h"

void pw_reverse(GroupFollower *follower) {
    CourseMapGroupEntry *savedEntry = follower->mFromEntry;
    follower->mFromEntry = follower->mToEntry;
    follower->mToEntry = savedEntry;
    follower->mForward = follower->mForward == 0;
}

void pwex_init(GroupFollowerWithSpeeds *follower, u16 entryIndex, s32 forward) {
    s32 entryValue;
    s32 speed;
    pw_init(&follower->field0, entryIndex, forward);
    entryValue = follower->field0.mFromEntry->fieldE;
    follower->mFromSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    follower->field30 = follower->mFromSpeed;
    entryValue = follower->field0.mToEntry->fieldE;
    follower->mToSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    speed = follower->field30;
    follower->field0.mSpeed = speed;
    follower->field0.mProgressStep =
        ((s64) speed * follower->field0.mPath->mSegments[follower->field0.mSegmentIndex].mInverseProgressLength) >>
        12;
}

s32 pwex_update(GroupFollowerWithSpeeds *follower) {
    s32 crossedEnd;
    s32 entryValue;
    s32 blend;
    s32 speed;
    crossedEnd = pw_update(&follower->field0);
    if (crossedEnd != 0) {
        follower->mFromSpeed = follower->mToSpeed;
        entryValue = follower->field0.mToEntry->fieldE;
        follower->mToSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    }
    if (follower->mFromSpeed != follower->mToSpeed) {
        blend = pw_getProgress(&follower->field0);
        speed = (s32) (((s64) follower->mFromSpeed * (0x1000 - blend)) >> 12) +
                (s32) (((s64) follower->mToSpeed * blend) >> 12);
        follower->field0.mSpeed = speed;
        follower->field0.mProgressStep =
            ((s64) speed *
             follower->field0.mPath->mSegments[follower->field0.mSegmentIndex].mInverseProgressLength) >>
            12;
    }
    return crossedEnd;
}

void pwex_20D84C0(SegmentProgress *segmentProgress, s32 a) {
    s32 inverseLength = segmentProgress->field0.mInverseProgressLength;
    segmentProgress->field54 = a;
    a = inverseLength != 0 ? (s32) (((s64) a * inverseLength) >> 12) : 0x1000000;
    segmentProgress->field58 = a;
}

BOOL pwex_20D849C(SegmentProgress *segmentProgress) {
    segmentProgress->field5C = segmentProgress->field5C + segmentProgress->field58;
    return segmentProgress->field5C >= 0x1000000;
}
