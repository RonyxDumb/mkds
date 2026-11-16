#include "Main/MapObjects/curve_point.h"
#include "Main/MapObjects/water.h"

void GetCurvePoint(const Vec3 *points, u32 fraction, Vec3 *result) {
    s32 weight0;
    s32 weight1;
    s32 weight2;
    s32 weight3[2];
    GetCurveWeights(fraction, &weight0, &weight1, &weight2, weight3);
    ComputeWeightedPoint(points, result, weight0, weight1, weight2, weight3[0]);
}
