#include "Main/Unknown/code_020aca08.h"
#include "Main/Unknown/code_02105e98.h"

#pragma thumb on

u32 TitleState6ReturnArgument(u32 value) {
    return value;
}

void UpdateTitleState6(Unk0203a0dc *sceneNumbers) {
    if (sceneNumbers != 0) {
        sceneNumbers->mNextScene = 0xb;
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
