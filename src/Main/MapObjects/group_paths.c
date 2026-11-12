#include "Main/MapObjects/group_paths.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"

#include "Main/MapObjects/segment_curve.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Course/code_02042044.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "code_02147cd8.h"

const Vec3 gGroupPathZeroLengthUp = {0, 0x1000, 0};
const Vec3 gGroupPathUpAxis = {0, 0x1000, 0};
struct GroupPath *gGroupPaths;

#pragma thumb off

void GetSegmentProgressPointXzLinearY(SegmentProgress *segmentProgress, Vec3 *position) {
    GetSegmentCurveXzLinearY(&segmentProgress->mSegment, segmentProgress->mProgress, position);
}

#pragma thumb on

void BuildSegment(Segment *segment, s32 useStraightLength, s32 computeUp, Vec3 *previousPoint, Vec3 *startPoint,
                  Vec3 *endPoint, Vec3 *nextPoint) {
    Vec3 startToEnd;
    Vec3 direction;
    Vec3 previousToEnd;
    Vec3 startSlope;
    Vec3 startToNext;
    Vec3 endSlope;
    s32 length;
    s32 startExtra = 0;
    s32 endExtra = 0;
    s32 value;
    s32 bend;
    s64 squaredUpLength;
    segment->mPoints[0] = *startPoint;
    segment->mPoints[3] = *endPoint;
    VEC_Subtract(endPoint, startPoint, &startToEnd);
    length = Vec3NormalizeAndGetLengthOrZero(&startToEnd, &direction);
    if (length == 0) {
        segment->mPoints[1] = segment->mPoints[0];
        segment->mPoints[2] = segment->mPoints[3];
        segment->mProgressLength = 0;
        segment->mInverseProgressLength = 0;
        if (computeUp != 0) {
            segment->mUp = gGroupPathZeroLengthUp;
        }
        return;
    }
    if (previousPoint != NULL) {
        VEC_Subtract(endPoint, previousPoint, &previousToEnd);
        if (Vec3NormalizeAndGetLengthOrZero(&previousToEnd, &previousToEnd) != 0) {
            bend = (0x1000 - Vec3DotUnrounded(&direction, &previousToEnd)) >> 1;
            startExtra = MUL_FIXED12_NO_ROUND(length, bend);
            if (useStraightLength != 0) {
                startSlope.x = MUL_FIXED12_NO_ROUND(previousToEnd.x, length);
                startSlope.y = MUL_FIXED12_NO_ROUND(previousToEnd.y, length);
                startSlope.z = MUL_FIXED12_NO_ROUND(previousToEnd.z, length);
            } else {
                value = length + startExtra;
                startSlope.x = MUL_FIXED12_NO_ROUND(previousToEnd.x, value);
                startSlope.y = MUL_FIXED12_NO_ROUND(previousToEnd.y, value);
                startSlope.z = MUL_FIXED12_NO_ROUND(previousToEnd.z, value);
            }
            VEC_MultAdd(0x555, &startSlope, &segment->mPoints[0], &segment->mPoints[1]);
        } else {
            segment->mPoints[1] = segment->mPoints[0];
        }
    } else {
        segment->mPoints[1] = segment->mPoints[0];
    }
    if (nextPoint != NULL) {
        VEC_Subtract(nextPoint, startPoint, &startToNext);
        if (Vec3NormalizeAndGetLengthOrZero(&startToNext, &startToNext) != 0) {
            bend = (0x1000 - Vec3DotUnrounded(&direction, &startToNext)) >> 1;
            endExtra = MUL_FIXED12_NO_ROUND(length, bend);
            if (useStraightLength != 0) {
                endSlope.x = MUL_FIXED12_NO_ROUND(startToNext.x, length);
                endSlope.y = MUL_FIXED12_NO_ROUND(startToNext.y, length);
                endSlope.z = MUL_FIXED12_NO_ROUND(startToNext.z, length);
            } else {
                value = length + endExtra;
                endSlope.x = MUL_FIXED12_NO_ROUND(startToNext.x, value);
                endSlope.y = MUL_FIXED12_NO_ROUND(startToNext.y, value);
                endSlope.z = MUL_FIXED12_NO_ROUND(startToNext.z, value);
            }
            VEC_MultAdd(-0x555, &endSlope, &segment->mPoints[3], &segment->mPoints[2]);
        } else {
            segment->mPoints[2] = segment->mPoints[3];
        }
    } else {
        segment->mPoints[2] = segment->mPoints[3];
    }
    segment->mStraightLength = length;
    segment->mInverseStraightLength = FX_Div(0x1000000, segment->mStraightLength);
    segment->mCurveLength = endExtra + (length + startExtra);
    segment->mInverseCurveLength = FX_Div(0x1000000, segment->mCurveLength);
    segment->mProgressLength = segment->mCurveLength;
    segment->mInverseProgressLength = segment->mInverseCurveLength;
    if (computeUp != 0) {
        value = VEC_DotProduct(&direction, &gGroupPathUpAxis);
        segment->mUp.x = gGroupPathUpAxis.x - MUL_FIXED12_NO_ROUND(direction.x, value);
        segment->mUp.y = gGroupPathUpAxis.y - MUL_FIXED12_NO_ROUND(direction.y, value);
        segment->mUp.z = gGroupPathUpAxis.z - MUL_FIXED12_NO_ROUND(direction.z, value);
        squaredUpLength = (s64) segment->mUp.x * segment->mUp.x + (s64) segment->mUp.y * segment->mUp.y +
                          (s64) segment->mUp.z * segment->mUp.z;
        if (squaredUpLength < 16) {
            value = 0;
        } else {
            value = Vec3NormalizeAndGetLengthUnchecked(&segment->mUp, &segment->mUp);
        }
        if (value == 0) {
            segment->mUp = gGroupPathUpAxis;
        }
    }
}

void BuildGroupPath(u32 groupIndex, CourseMapEntryGroup *entryGroup) {
    GroupPath *path;
    s32 entryCount;
    s32 segmentIndex;
    path = &gGroupPaths[groupIndex];
    if (path->mSegments != NULL) {
        return;
    }
    entryCount = entryGroup->mEntryCount;
    path->mSegmentCount = entryCount;
    path->mWraps = entryGroup->mWraps;
    if (path->mWraps == 0) {
        path->mSegmentCount = path->mSegmentCount - 1;
    }
    path->mSegments = HeapAlloc(GetHeap(GetCurrentHeapCall()), path->mSegmentCount * 0x54);
    if (entryCount == 2) {
        BuildSegment(path->mSegments, 0, 1, NULL, &GetCourseMapGroupEntry(groupIndex, 0)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 1)->mPos, NULL);
        if (path->mWraps != 0) {
            BuildSegment(&path->mSegments[1], 0, 1, NULL, &GetCourseMapGroupEntry(groupIndex, 1)->mPos,
                         &GetCourseMapGroupEntry(groupIndex, 0)->mPos, NULL);
        }
        return;
    }
    if (path->mWraps != 0) {
        BuildSegment(path->mSegments, 0, 1, &GetCourseMapGroupEntry(groupIndex, entryCount - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 0)->mPos, &GetCourseMapGroupEntry(groupIndex, 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 2)->mPos);
    } else {
        BuildSegment(path->mSegments, 0, 1, NULL, &GetCourseMapGroupEntry(groupIndex, 0)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 1)->mPos, &GetCourseMapGroupEntry(groupIndex, 2)->mPos);
    }
    for (segmentIndex = 1; segmentIndex < entryCount - 2; segmentIndex++) {
        BuildSegment(&path->mSegments[segmentIndex], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 2)->mPos);
    }
    if (path->mWraps != 0) {
        BuildSegment(&path->mSegments[segmentIndex], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 0)->mPos);
    } else {
        BuildSegment(&path->mSegments[segmentIndex], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos, NULL);
    }
    if (path->mWraps != 0) {
        BuildSegment(&path->mSegments[segmentIndex + 1], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 0)->mPos, &GetCourseMapGroupEntry(groupIndex, 1)->mPos);
    }
}

void InitGroupPaths(void) {
    s32 groupCount = gCourseMap->mEntryGroupCount;
    s32 groupIndex;
    if (groupCount != 0) {
        gGroupPaths = HeapAlloc(GetHeap(GetCurrentHeapCall()), groupCount * 0xc);
    }
    for (groupIndex = 0; groupIndex < groupCount; groupIndex++) {
        gGroupPaths[groupIndex].mSegments = NULL;
    }
}

#pragma thumb off

#pragma thumb on

void InitGroupFollowerForGroup(GroupFollower *follower, u16 groupIndex, int speed) {
    follower->mGroupIndex = groupIndex;
    BuildGroupPath(follower->mGroupIndex, &gCourseMap->mEntryGroups[follower->mGroupIndex]);
    follower->mPath = &gGroupPaths[follower->mGroupIndex];
    follower->mSpeed = speed;
    SetupGroupFollowerAtEntry(follower, 0, 1);
}

#pragma thumb off
