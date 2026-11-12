#include "Main/Menu/title_state_set.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void SetTitleState(u32 state, u32 nextState) {
    gTitleScene->mStateFrames = 0;
    gTitleScene->mStateChanged = TRUE;
    gTitleScene->mPrevState = gTitleScene->mState;
    gTitleScene->mState = state;
    gTitleScene->mNextState = nextState;
}

#pragma thumb off
