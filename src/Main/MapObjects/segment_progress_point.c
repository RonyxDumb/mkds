#include "Main/MapObjects/segment_progress_point.h"
#include "Main/MapObjects/curve_point_xz.h"
#include "Main/MapObjects/curve_point.h"

void GetSegmentProgressPoint(SegmentProgress *segmentProgress, Vec3 *output) {
    Vec3 *points = segmentProgress->mSegment.mPoints;
    u32 progress;
    Vec3 *resultAddress;
    u32 unused;
    resultAddress = output;
    progress = segmentProgress->mProgress;
    GetCurvePoint(points, progress, resultAddress);
}

void GetSegmentProgressPointXz(SegmentProgress *segmentProgress, Vec3 *output) {
    Vec3 *points = segmentProgress->mSegment.mPoints;
    u32 progress;
    Vec3 *resultAddress;
    u32 unused;
    resultAddress = output;
    progress = segmentProgress->mProgress;
    GetCurvePointXz(points, progress, resultAddress);
}
