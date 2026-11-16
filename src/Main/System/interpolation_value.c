#include "Main/System/interpolation_value.h"
#include "Main/Graphics/oam.h"

#pragma thumb on

s16 GetInterpolatedValue(Interpolation *interpolation) {
    return ComputeValueInterpolation_from_thumb(1, interpolation->mStartValue, interpolation->mEndValue, interpolation->mCounter,
                          interpolation->mCounterLimit);
}

#pragma thumb off
