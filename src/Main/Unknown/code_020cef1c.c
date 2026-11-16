#include "Main/Unknown/code_020cef1c.h"
#include "Main/Unknown/code_020cef68.h"
#include "00/code_02181f98.h"

#pragma thumb on

void struct217B488_reset(void) {
    struct217B488_MI_CpuClearFast(gStruct217B488, 0x130);
    gStruct217B488->mTitleBlendDone = 0;
    gStruct217B488->field4 = 0;
    gStruct217B488->field8 = 0;
    gStruct217B488->mGhostSceneInitialCallbacksIndex = 0;
    gStruct217B488->field10 = 0;
    gStruct217B488->field14 = 0;
    gStruct217B488->field1C = 0;
    gStruct217B488->field54 = 0;
    gStruct217B488->field58 = FALSE;
    gStruct217B488->field70 = 0;
}

#pragma thumb off
