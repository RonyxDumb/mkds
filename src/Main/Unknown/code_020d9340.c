#include "Main/Unknown/code_020d9340.h"
#include "Main/Unknown/code_020d94dc.h"

void GetCurvePointXz(const Vec3 *points, u32 fraction, Vec3 *result) {
    s32 weight0;
    s32 weight1;
    s32 weight2;
    s32 weight3[2];
    GetCurveWeights(fraction, &weight0, &weight1, &weight2, weight3);
    ComputeWeightedPointXz(points, result, weight0, weight1, weight2, weight3[0]);
}
