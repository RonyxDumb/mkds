#include "Main/Unknown/code_020d9480.h"
#include "Main/Course/WaterEfct.h"

void pw_interpolateXYZ(u32 points, u32 fraction, u32 result) {
    u32 weight0;
    u32 weight1;
    u32 weight2;
    u32 weight3[2];
    pw_hermiteSplineCalcCoef(fraction, (s32 *) &weight0, (s32 *) &weight1, (s32 *) &weight2, (s32 *) weight3);
    pw_applyCoefXYZ((const Vec3 *) points, (Vec3 *) result, weight0, weight1, weight2, weight3[0]);
}
