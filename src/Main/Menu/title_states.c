#include "Main/Menu/title_states.h"
#include "Main/Menu/title_registers.h"
#include "Main/Graphics/scene_text.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void AdvanceTitleStates(s32 flag) {
    enum { K0 } stateIndex;
    ClearOamListCounts(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
    stateIndex = gTitleScene->mState;
    gTitleScene->mStateHandlers[stateIndex].mUpdate(flag);
    IncrementCounterSaturating(&gTitleScene->mStateFrames);
    AdvanceSceneText();
    HideUnusedOams(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
}

#pragma thumb off
