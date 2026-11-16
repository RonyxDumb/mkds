#include "Main/Menu/title_blend_in.h"
#include "Main/Menu/title_blend.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma thumb on

void TitleBlendInNop(void) {}

void UpdateTitleBlendIn(void) {
    int stateFrames;
    int waitFrames;
    waitFrames = 0;
    if (g_SceneTitleContext->mBlendDone == FALSE) {
        waitFrames = 0x6b;
    }
    stateFrames = GetTitleStateFrames();
    if (stateFrames >= waitFrames) {
        SetTitleState(TITLE_STATE_SLIDE_IN, 8);
    }
    Title_SomeBldalphaConfig_from_thumb();
}

u32 TitleReturnArgument(u32 value) {
    return value;
}

#pragma thumb off
