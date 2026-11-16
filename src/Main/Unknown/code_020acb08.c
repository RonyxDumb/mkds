#include "Main/Unknown/code_020acb08.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

u32 title_savd_getNksyOffs31Bit0(void) {
    return gSaveData->mFirstBlock->field31_0 != 0;
}

#pragma optimize_for_size on
#pragma thumb on

void title_buttonsOutRender(void) {
    u32 w;
    s32 i;
    LayoutTableEntry *titleTable;

    titleTable = sTitleSceneState->mTitleTable;
    w = title_jn_ui_getBnclElementCount(sTitleSceneState->mTitleSBncl);
    if (title_getFrameCounter() < 10) {
        for (i = 0; i <= 14; i++) {
            titleTable[i].mOffsetX = mutil_interpolate(1, 0, 0xf8, title_getFrameCounter(), 10);
        }
        for (i = 0; i <= 1; i++) {
            titleTable[i + w].mOffsetX = mutil_interpolate(1, 0, 0xf8, title_getFrameCounter(), 10);
        }
    } else {
        for (i = 0; i <= 14; i++) {
            titleTable[i].mOffsetX = 0xf8;
        }
        for (i = 0; i <= 1; i++) {
            titleTable[i + w].mOffsetX = 0xf8;
        }
        if (title_savd_getNksyOffs31Bit0() != 0) {
            title_gotoState(sTitleSceneState->mNextState, 8);
        } else {
            title_gotoState(6, 8);
        }
    }
    title_renderUI();
}

#pragma thumb off
