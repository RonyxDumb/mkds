#include "Main/Unknown/code_020caf08.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_modeSelectOutStateRender(void) {
    s32 frame;
    LayoutTableEntry *mainCells;
    LayoutTableEntry *subCells;
    s32 i;
    s16 offset;

    frame = menu_getFrameCounter();
    mainCells = gMenuSceneState->mSinglePlaySelectModeMLayoutTable;
    subCells = gMenuSceneState->mSinglePlaySelectModeSLayoutTable;
    if (frame < 10) {
        mainCells->mOffsetY = mutil_interpolate(1, 0, -0x28, frame, 10);
        offset = mutil_interpolate(1, 0, 0xf0, frame, 10);
        for (i = 0; i <= 14; i++) {
            subCells[i].mOffsetX = offset;
        }
    } else {
        mainCells->mOffsetY = -0x28;
        for (i = 0; i <= 14; i++) {
            subCells[i].mOffsetX = 0xf0;
        }
        menu_gotoState(menu_getField10(), 0x1f);
    }
    menu_renderModeSelectUI();
}
#pragma thumb off
