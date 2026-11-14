#include "Main/System/interpolation_state.h"
#include "Main/System/interpolation_value.h"

#pragma thumb on

void SetInterpolationState(Interpolation *interpolation, u32 state) {
    interpolation->mState = state;
    switch (interpolation->mState) {
        case INTERPOLATION_STATE_RISING:
        case INTERPOLATION_STATE_AT_START:
            interpolation->mCounter = 0;
            return;
        case INTERPOLATION_STATE_AT_END:
        case INTERPOLATION_STATE_FALLING:
            interpolation->mCounter = interpolation->mCounterLimit;
    }
}

#pragma thumb off
