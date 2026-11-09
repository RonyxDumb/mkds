#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020d9340.h"
#include "Main/Unknown/code_020d9480.h"

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
