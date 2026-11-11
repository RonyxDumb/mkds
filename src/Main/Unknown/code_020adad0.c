#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/unk_0217b000.h"

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
