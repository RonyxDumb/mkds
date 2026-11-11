#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020ada7c.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void AdvanceTitleStates(s32 flag) {
    enum { K0 } stateIndex;
    ClearOamListCounts(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
    stateIndex = gTitleScene->mState;
    gTitleScene->mStateHandlers[stateIndex].mUpdate(flag);
    IncrementCounterSaturating((s32 *) gTitleScene);
    AdvanceSceneText();
    HideUnusedOams(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
}

#pragma thumb off
