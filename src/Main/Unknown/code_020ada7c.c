#include "Main/Unknown/code_020ada7c.h"

#include "Main/Unknown/code_020ada94.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void title_vblank(void) {
    sTitleSceneState->mStateHandlers[sTitleSceneState->mState].mUnk_00();
    sTitleSceneState->mStateChanged = FALSE;
    gmenu_vblank();
    oam_applyBuffers(&sTitleSceneState->mMainOam, &sTitleSceneState->mSubOam);
}

#pragma thumb off

void title_ssm_increaseFrameCounter(int *counter) {
    u32 value;
    value = *(u32 *) counter;
    if ((s32) value < 0x7fffffff) {
        *counter = value + 1;
    }
}
