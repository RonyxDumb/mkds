#include "Main/Menu/title_state_frames.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

s32 GetTitleStateFrames(void) {
    return ((u32) gTitleScene->mStateFrames);
}

#pragma thumb off
