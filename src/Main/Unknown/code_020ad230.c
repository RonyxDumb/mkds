#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

u32 title_fadeInStateVblank(u32 value) {
    return value;
}

void title_fadeInStateRender(void) {
    int stateFrames;
    int waitFrames;
    waitFrames = 0;
    if (sTitleSceneState->mBlendDone == FALSE) {
        waitFrames = 0x6b;
    }
    stateFrames = title_getFrameCounter();
    if (stateFrames >= waitFrames) {
        title_gotoState(1, 8);
    }
    title_updateIntro();
}

u32 func_020ad230(u32 value) {
    return value;
}

#pragma thumb off
