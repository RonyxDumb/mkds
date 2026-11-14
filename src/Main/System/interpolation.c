#include "Main/System/interpolation.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/interpolation_state.h"

#pragma thumb on

// Takes rising only from falling or at start and falling only from rising or at end; any other state is set at once.
void SetInterpolationStateIfOpposite(Interpolation *interpolation, s32 requestedState) {
    switch (requestedState) {
        case INTERPOLATION_STATE_RISING:
            switch (interpolation->mState) {
                case INTERPOLATION_STATE_FALLING:
                case INTERPOLATION_STATE_AT_START:
                    SetInterpolationState(interpolation, requestedState);
            }
            break;
        case INTERPOLATION_STATE_FALLING:
            switch (interpolation->mState) {
                case INTERPOLATION_STATE_RISING:
                case INTERPOLATION_STATE_AT_END:
                    SetInterpolationState(interpolation, requestedState);
            }
            break;
        default:
            SetInterpolationState(interpolation, requestedState);
            break;
    }
}

void AdvanceInterpolation(Interpolation *interpolation) {
    switch (interpolation->mState) {
        case INTERPOLATION_STATE_RISING:
            interpolation->mCounter++;
            if (interpolation->mCounter > interpolation->mCounterLimit) {
                interpolation->mCounter = interpolation->mCounterLimit;
                interpolation->mState = INTERPOLATION_STATE_AT_END;
            }
            break;
        case INTERPOLATION_STATE_FALLING:
            interpolation->mCounter--;
            if (interpolation->mCounter < 0) {
                interpolation->mCounter = 0;
                interpolation->mState = INTERPOLATION_STATE_AT_START;
            }
            break;
    }
}

#pragma thumb off
