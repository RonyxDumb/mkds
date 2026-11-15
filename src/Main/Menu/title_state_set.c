#include "Main/Menu/title_state_set.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

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
