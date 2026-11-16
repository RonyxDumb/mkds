#include "Main/Unknown/code_020acf04.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acb08.h"

#pragma optimize_for_size on
#pragma thumb on

void title_buttonsInStateRender(void) {
    u32 subBase;
    s32 i;
    LayoutTableEntry *titleTable;

    titleTable = sTitleSceneState->mTitleTable;
    subBase = title_jn_ui_getBnclElementCount(sTitleSceneState->mTitleSBncl);
    if (title_getFrameCounter() < 10) {
        for (i = 0; i <= 14; i++) {
            titleTable[i].mOffsetX = mutil_interpolate(1, 0xf8, 0, title_getFrameCounter(), 10);
        }
        for (i = 0; i <= 1; i++) {
            titleTable[i + subBase].mOffsetX = mutil_interpolate(1, 0xe4, 0, title_getFrameCounter(), 10);
        }
    } else {
        for (i = 0; i <= 14; i++) {
            titleTable[i].mOffsetX = 0;
        }
        for (i = 0; i <= 1; i++) {
            titleTable[i + subBase].mOffsetX = 0;
        }
        title_gotoState(2, 8);
        sTitleSceneState->mSelectedPressed = FALSE;
    }
    title_renderUI();
}

void title_playActivationSound(void) {
    switch (sTitleSceneState->mSelectedIndex) {
        case 0:
        case 1:
        case 2:
            sfx_2105AC0(9);
            break;
        case 3:
        case 4:
            sfx_2105AC0(8);
            break;
        default:
            break;
    }
}

#pragma thumb off
