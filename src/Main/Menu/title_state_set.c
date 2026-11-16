#include "Main/Menu/title_state_set.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma optimize_for_size on
#pragma thumb on

void SetTitleState(u32 state, u32 nextState) {
    g_SceneTitleContext->mStateFrames = 0;
    g_SceneTitleContext->mStateChanged = TRUE;
    g_SceneTitleContext->mPrevState = g_SceneTitleContext->mState;
    g_SceneTitleContext->mState = state;
    g_SceneTitleContext->mNextState = nextState;
}

#pragma thumb off
