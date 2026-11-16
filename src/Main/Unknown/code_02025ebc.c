#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_020ade08.h"

#pragma thumb on

s16 interp_interpolate(Interpolation *interpolation) {
    return mutil_interpolate(1, interpolation->mStartValue, interpolation->mEndValue, interpolation->mCounter,
                          interpolation->mCounterLimit);
}

#pragma thumb off
