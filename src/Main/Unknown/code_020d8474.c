#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020d9340.h"
#include "Main/Unknown/code_020d9480.h"

void GetSegmentProgressPoint(SegmentPoints *progressOwner, Vec3 *output) {
    u32 pointsAddress = (u32) progressOwner;
    u32 value1 = (u32) output;
    u32 resultAddress;
    u32 unused;
    resultAddress = value1;
    value1 = progressOwner->mSegmentProgress.mProgress;
    GetCurvePoint(pointsAddress, value1, resultAddress);
}

void GetSegmentProgressPointXz(SegmentProgress *segmentProgress, Vec3 *output) {
    u32 pointsAddress = (u32) segmentProgress;
    u32 value1 = (u32) output;
    u32 resultAddress;
    u32 unused;
    resultAddress = value1;
    value1 = segmentProgress->mProgress;
    GetCurvePointXz(pointsAddress, value1, resultAddress);
}
