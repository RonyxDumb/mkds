#include "Main/Unknown/code_020aca08.h"
#include "Main/Unknown/code_02105e98.h"

#pragma thumb on

u32 func_020aca20(u32 value) {
    return value;
}

void UpdateTitleState6(Unk0203a0dc *a) {
    if (a != 0) {
        a->mNextScene = 0xb;
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
