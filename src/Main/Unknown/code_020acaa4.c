#include "Main/Unknown/code_020acaa4.h"

#include "Main/Unknown/code_020acacc.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acb00.h"
#include "00/code_02181f98.h"

#pragma thumb on
u32 title_selectedOutEffectVblank(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

#pragma thumb on

void title_selectedOutEffectRender(void) {
    s32 titleStateFrames;

    titleStateFrames = title_getFrameCounter();
    sTitleSceneState->mSelectedOffset = mutil_getButtonOutEffectOffset(titleStateFrames);
    if (titleStateFrames >= 10) {
        title_gotoState(3, 5);
    }
    title_renderUI();
}

void title_gotoSelectedVblank(void) {}

#pragma thumb off

void title_sysdat_setOverlayRelatedNum(u32 p0) {
    gSystemData->field20 = p0;
}

void title_struct217B488_setField74(u32 p0) {
    gStruct217B488->field74 = p0;
}
