#include "Main/Unknown/code_020cb234.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0212775c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccc9c.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_modeSelectInStateRender(void) {
    s32 frame;
    LayoutTableEntry *mainCells;
    LayoutTableEntry *subCells;
    s32 i;
    s16 offset;

    frame = menu_getFrameCounter();
    mainCells = gMenuSceneState->mSinglePlaySelectModeMLayoutTable;
    subCells = gMenuSceneState->mSinglePlaySelectModeSLayoutTable;
    if (frame < 10) {
        mainCells->mOffsetY = mutil_interpolate(1, -0x28, 0, frame, 10);
        offset = mutil_interpolate(1, 0xf0, 0, frame, 10);
        for (i = 0; i <= 14; i++) {
            subCells[i].mOffsetX = offset;
        }
        RequestSelectReturnState1();
    } else {
        mainCells->mOffsetY = 0;
        for (i = 0; i <= 14; i++) {
            subCells[i].mOffsetX = 0;
        }
        menu_gotoState(1, 0x1f);
        gmenu_setSeqArcIndex(0xf);
        gMenuSceneState->field934 = FALSE;
    }
    menu_renderModeSelectUI();
}
#pragma thumb off
