#include "Main/MapObjects/straight_segment_lengths.h"

#pragma thumb on

void SetStraightSegmentLengths(GroupFollower *follower) {
    GroupPath *path;
    int index;
    int segmentCount;
    Segment *segment;
    path = follower->mPath;
    segmentCount = path->mSegmentCount;
    index = 0;
    if (0 < segmentCount) {
        do {
            segment = &path->mSegments[index];
            segment->mProgressLength = segment->mStraightLength;
            segment->mInverseProgressLength = segment->mInverseStraightLength;
            index = index + 1;
        } while (index < segmentCount);
    }
}

#pragma thumb off
