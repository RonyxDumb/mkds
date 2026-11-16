#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_02025f54.h"

#pragma thumb on

void interp_setState(Interpolation *interpolation, s32 requestedState) {
    switch (requestedState) {
        case 0:
            switch (interpolation->mState) {
                case 2:
                case 3:
                    interp_setStateDirect(interpolation, requestedState);
            }
            break;
        case 2:
            switch (interpolation->mState) {
                case 0:
                case 1:
                    interp_setStateDirect(interpolation, requestedState);
            }
            break;
        default:
            interp_setStateDirect(interpolation, requestedState);
            break;
    }
}

void interp_update(Interpolation *interpolation) {
    switch (interpolation->mState) {
        case 0:
            interpolation->mCounter++;
            if (interpolation->mCounter > interpolation->mCounterLimit) {
                interpolation->mCounter = interpolation->mCounterLimit;
                interpolation->mState = 1;
            }
            break;
        case 2:
            interpolation->mCounter--;
            if (interpolation->mCounter < 0) {
                interpolation->mCounter = 0;
                interpolation->mState = 3;
            }
            break;
    }
}

#pragma thumb off
