#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void title_gotoState(u32 a, u32 b) {
    sTitleSceneState->mStateFrames = 0;
    sTitleSceneState->mStateChanged = TRUE;
    sTitleSceneState->mPrevState = sTitleSceneState->mState;
    sTitleSceneState->mState = a;
    sTitleSceneState->mNextState = b;
}

#pragma thumb off
