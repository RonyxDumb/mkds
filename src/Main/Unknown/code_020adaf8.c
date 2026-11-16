#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

s32 title_getFrameCounter(void) {
    return ((u32) sTitleSceneState->mStateFrames);
}

#pragma thumb off
