#include "Main/MapObjects/segment_progress_point.h"
#include "Main/MapObjects/curve_point_xz.h"
#include "Main/MapObjects/curve_point.h"

void GetSegmentProgressPoint(SegmentPoints *progressOwner, Vec3 *output) {
    Vec3 *points = progressOwner->mSegmentProgress.mSegment.mPoints;
    u32 value1;
    Vec3 *resultAddress;
    u32 unused;
    resultAddress = output;
    value1 = progressOwner->mSegmentProgress.mProgress;
    GetCurvePoint(points, value1, resultAddress);
}

void GetSegmentProgressPointXz(SegmentProgress *segmentProgress, Vec3 *output) {
    Vec3 *points = segmentProgress->mSegment.mPoints;
    u32 value1;
    Vec3 *resultAddress;
    u32 unused;
    resultAddress = output;
    value1 = segmentProgress->mProgress;
    GetCurvePointXz(points, value1, resultAddress);
}
