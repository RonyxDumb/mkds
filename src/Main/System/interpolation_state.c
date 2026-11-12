#include "Main/System/interpolation_state.h"
#include "Main/System/interpolation_value.h"

#pragma thumb on

void SetInterpolationState(Interpolation *interpolation, u32 state) {
    interpolation->mState = state;
    switch (interpolation->mState) {
        case 0:
        case 3:
            interpolation->mCounter = 0;
            return;
        case 1:
        case 2:
            interpolation->mCounter = interpolation->mCounterLimit;
    }
}

#pragma thumb off
