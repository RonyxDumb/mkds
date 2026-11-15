#include "Main/Menu/title_state0.h"
#include "Main/Menu/title_blend.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma thumb on

u32 TitleState0ReturnArgument(u32 value) {
    return value;
}

void UpdateTitleState0(void) {
    int stateFrames;
    int waitFrames;
    waitFrames = 0;
    if (gTitleScene->mBlendDone == FALSE) {
        waitFrames = 0x6b;
    }
    stateFrames = GetTitleStateFrames();
    if (stateFrames >= waitFrames) {
        SetTitleState(TITLE_STATE_SLIDE_IN, 8);
    }
    AdvanceTitleBlend();
}

u32 TitleReturnArgument(u32 value) {
    return value;
}

#pragma thumb off
