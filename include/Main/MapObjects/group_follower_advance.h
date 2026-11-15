#pragma once

#include "types.h"
#include "Main/MapObjects/segment_group_collision.h"
#include "Main/Course/course_map_group_entry.h"

// Object of 0x38 bytes whose first 0x24 bytes are an GroupFollower (AdvanceGroupFollowerWithSpeeds,
// SetupGroupFollowerWithSpeeds, ReverseGroupFollower).
typedef struct GroupFollowerWithSpeeds {
    /* 00 */ GroupFollower mGroupFollower;
    /* 24 */ s32 mSpeedPerEntryUnit;
    /* 28 */ s32 mDefaultSpeed;
    /* 2c */ s32 mFromSpeed;
    /* 30 */ s32 mInitialSpeed;
    /* 34 */ s32 mToSpeed;
} GroupFollowerWithSpeeds;

// An Segment (BuildSegment and GetSegmentCurveXzLinearY), then three words.
typedef struct SegmentProgress {
    /* 00 */ Segment mSegment;
    /* 54 */ s32 mRate;
    /* 58 */ s32 mProgressStep;
    /* 5c */ s32 mProgress;
} SegmentProgress;

void ReverseGroupFollower(GroupFollower *follower);
void SetupGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower, u16 entryValue, s32 entryIndex);
s32 AdvanceGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower);
void SetSegmentProgressRate(SegmentProgress *segmentProgress, s32 value);
BOOL AdvanceSegmentProgress(SegmentProgress *segmentProgress);

typedef struct GroupFollower GroupFollower;

void SetGroupFollowerSegmentEnd(GroupFollower *follower);

typedef struct CourseMapRow CourseMapRow;

u32 GetMaxXzDistanceToGroup(GroupFollower *follower, Vec3 *point);
void GetGroupFollowerLinearXz(GroupFollower *follower, Vec3 *position);
Vec3 *CreateCourseMapGroupSideVectors(CourseMapRow *row);

Vec3 *GetGroupFollowerSegmentUp(GroupFollower *follower);

void GetGroupFollowerCurvePosStepXz(GroupFollower *follower, Vec3 *position, Vec3 *step);
void GetGroupFollowerLinearPosition(GroupFollower *follower, Vec3 *position);
void GetGroupFollowerLinearPosStep(GroupFollower *follower, Vec3 *position, Vec3 *step);

void GetGroupFollowerCurveXz(GroupFollower *follower, Vec3 *output);

void GetGroupFollowerCurvePosStep(GroupFollower *follower, Vec3 *position, Vec3 *step);
void GetGroupFollowerCurveXzLinearY(GroupFollower *follower, Vec3 *position);

void GetGroupFollowerCurvePosition(GroupFollower *follower, Vec3 *output);
