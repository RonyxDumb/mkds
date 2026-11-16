#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020ada7c.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void title_update(s32 a) {
    enum { K0 } i;
    oam_resetBuffers(&sTitleSceneState->mMainOam, &sTitleSceneState->mSubOam);
    i = sTitleSceneState->mState;
    sTitleSceneState->mStateHandlers[i].mUpdate(a);
    title_ssm_increaseFrameCounter((s32 *) sTitleSceneState);
    gmenu_render();
    oam_prepareBuffers(&sTitleSceneState->mMainOam, &sTitleSceneState->mSubOam);
}

#pragma thumb off
