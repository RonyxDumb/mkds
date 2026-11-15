#include "Main/Menu/title_states.h"
#include "Main/Menu/title_registers.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma optimize_for_size on
#pragma thumb on

void AdvanceTitleStates(s32 flag) {
    enum { STATE_INDEX_FIRST } stateIndex;
    ClearOamListCounts(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
    stateIndex = gTitleScene->mState;
    gTitleScene->mStateHandlers[stateIndex].mUpdate(flag);
    IncrementCounterSaturating(&gTitleScene->mStateFrames);
    AdvanceSceneText();
    HideUnusedOams(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
}

#pragma thumb off
