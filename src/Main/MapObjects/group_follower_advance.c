#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/curve_point.h"
#include "Main/MapObjects/code_020e005c.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/segment_curve_pos_step.h"
#include "Main/MapObjects/curve_point_xz.h"
#include "code_02147cd8.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_koura_w.h"
#include "registers.h"
#include "Main/System/init_after_startup.h"

void GetGroupFollowerCurvePosition(GroupFollower *follower, Vec3 *output) {
    GetCurvePoint(follower->mPath->mSegments[follower->mSegmentIndex].mPoints, follower->mProgress, output);
}

void GetGroupFollowerCurvePosStep(GroupFollower *follower, Vec3 *position, Vec3 *step) {
    GetSegmentCurvePosStep(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress,
                           follower->mProgressStep, position, step);
    if (follower->mForward == 0) {
        step->x = -step->x;
        step->y = -step->y;
        step->z = -step->z;
    }
}

void GetGroupFollowerCurveXzLinearY(GroupFollower *follower, Vec3 *position) {
    GetSegmentCurveXzLinearY(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress, position);
}

void GetGroupFollowerCurveXz(GroupFollower *follower, Vec3 *output) {
    GetCurvePointXz(follower->mPath->mSegments[follower->mSegmentIndex].mPoints, follower->mProgress, output);
}

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
    remaining = SEGMENT_PROGRESS_END - progress;
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
    remaining = SEGMENT_PROGRESS_END - progress;
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

Vec3 *GetGroupFollowerSegmentUp(GroupFollower *follower) {
    return &follower->mPath->mSegments[follower->mSegmentIndex].mUp;
}

u32 GetMaxXzDistanceToGroup(GroupFollower *follower, Vec3 *point) {
    GroupPath *path;
    s32 segmentIndex;
    s64 maxDistanceSquared;
    Segment *segment;
    s64 distanceSquared;
    s32 pointX;
    s32 pointZ;
    s32 delta;
    path = follower->mPath;
    maxDistanceSquared = 0;
    segmentIndex = path->mSegmentCount - 1;
    segment = path->mSegments;
    if (segmentIndex >= 0) {
        segment = &segment[segmentIndex];
        pointX = point->x;
        pointZ = point->z;
        do {
            delta = pointX - segment->mPoints[0].x;
            distanceSquared = (s64) delta * delta;
            delta = pointZ - segment->mPoints[0].z;
            distanceSquared = distanceSquared + (s64) delta * delta;
            if (maxDistanceSquared < distanceSquared) {
                maxDistanceSquared = distanceSquared;
            }
            delta = pointX - segment->mPoints[3].x;
            distanceSquared = (s64) delta * delta;
            delta = pointZ - segment->mPoints[3].z;
            distanceSquared = distanceSquared + (s64) delta * delta;
            if (maxDistanceSquared < distanceSquared) {
                maxDistanceSquared = distanceSquared;
            }
            segment--;
            segmentIndex--;
        } while (segmentIndex >= 0);
    }
    reg_CP_SQRTCNT = 1;
    *(vs64 *) 0x40002b8 = maxDistanceSquared;
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
    return reg_CP_SQRT_RESULT;
}

void GetGroupFollowerLinearXz(GroupFollower *follower, Vec3 *position) {
    Segment *segment;
    s32 progress;
    s32 remaining;
    segment = &follower->mPath->mSegments[follower->mSegmentIndex];
    progress = follower->mProgress;
    remaining = SEGMENT_PROGRESS_END - progress;
    position->x = MUL_FIXED24_NO_ROUND(segment->mPoints[0].x, remaining);
    position->z = MUL_FIXED24_NO_ROUND(segment->mPoints[0].z, remaining);
    position->x = position->x + MUL_FIXED24_NO_ROUND(segment->mPoints[3].x, progress);
    position->z = position->z + MUL_FIXED24_NO_ROUND(segment->mPoints[3].z, progress);
}

Vec3 *CreateCourseMapGroupSideVectors(CourseMapRow *row) {
    u16 entryIndex;
    u16 groupIndex;
    u16 entryCount;
    Vec3 *sideVectors;
    Vec3 direction;
    CourseMapGroupEntry *endEntry;
    CourseMapGroupEntry *startEntry;
    s32 savedZ;
    groupIndex = row->mGroupIndex;
    entryCount = gCourseMap->mEntryGroups[groupIndex].mEntryCount;
    sideVectors = HeapAlloc(GetHeap(GetCurrentHeapCall()), entryCount * 12);
    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        if (entryIndex == entryCount - 1) {
            if (*(u8 *) ((u32) gCourseMap->mEntryGroups + groupIndex * 4 + 1) == 0) {
                continue;
            }
            endEntry = GetCourseMapGroupEntry(groupIndex, 0);
            startEntry = GetCourseMapGroupEntry(groupIndex, entryCount - 1);
            VEC_Subtract(&endEntry->mPos, &startEntry->mPos, &direction);
        } else {
            endEntry = GetCourseMapGroupEntry(groupIndex, entryIndex + 1);
            startEntry = GetCourseMapGroupEntry(groupIndex, entryIndex);
            VEC_Subtract(&endEntry->mPos, &startEntry->mPos, &direction);
        }
        savedZ = direction.z;
        direction.z = -direction.x;
        direction.y = 0;
        direction.x = savedZ;
        direction.y = 0;
        Vec3NormalizeAndGetLengthUnchecked(&direction, &sideVectors[entryIndex]);
    }
    return sideVectors;
}

void SetGroupFollowerSegmentEnd(GroupFollower *follower) {
    follower->mProgress = SEGMENT_PROGRESS_END;
}

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
    entryValue = follower->mGroupFollower.mFromEntry->mValue;
    follower->mFromSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    follower->mInitialSpeed = follower->mFromSpeed;
    entryValue = follower->mGroupFollower.mToEntry->mValue;
    follower->mToSpeed = entryValue != 0 ? follower->mSpeedPerEntryUnit * entryValue : follower->mDefaultSpeed;
    speed = follower->mInitialSpeed;
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
        entryValue = follower->mGroupFollower.mToEntry->mValue;
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
    value = inverseLength != 0 ? MUL_FIXED12_NO_ROUND(value, inverseLength) : SEGMENT_PROGRESS_END;
    segmentProgress->mProgressStep = value;
}

BOOL AdvanceSegmentProgress(SegmentProgress *segmentProgress) {
    segmentProgress->mProgress = segmentProgress->mProgress + segmentProgress->mProgressStep;
    return segmentProgress->mProgress >= SEGMENT_PROGRESS_END;
}
