#include "Main/MapObjects/segment_curve_pos_step.h"
#include "Main/MapObjects/water.h"

void GetSegmentCurvePosStep(Segment *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult) {
    s32 firstWeight0;
    s32 firstWeight1;
    s32 firstWeight2;
    s32 firstWeight3;
    s32 secondWeight0;
    s32 secondWeight1;
    s32 secondWeight2;
    s32 secondWeight3;
    GetCurveAndSlopeWeights(fraction, &firstWeight0, &firstWeight1, &firstWeight2, &firstWeight3, &secondWeight0,
                            &secondWeight1, &secondWeight2, &secondWeight3);
    ComputeWeightedPoint(segment->mPoints, firstResult, firstWeight0, firstWeight1, firstWeight2, firstWeight3);
    ComputeWeightedPoint(segment->mPoints, secondResult, secondWeight0, secondWeight1, secondWeight2, secondWeight3);
    secondResult->x = MUL_FIXED24_NO_ROUND(secondResult->x, scale);
    secondResult->y = MUL_FIXED24_NO_ROUND(secondResult->y, scale);
    secondResult->z = MUL_FIXED24_NO_ROUND(secondResult->z, scale);
}
