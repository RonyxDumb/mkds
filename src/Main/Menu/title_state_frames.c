#include "Main/Menu/title_state_frames.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma thumb on

s32 GetTitleStateFrames(void) {
    return ((u32) gTitleScene->mStateFrames);
}

#pragma thumb off
