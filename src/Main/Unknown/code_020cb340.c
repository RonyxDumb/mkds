#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_updateModeSelectUI(void) {
    LayoutTableEntry *subCells;
    s32 selectedIndex;
    s32 i;

    subCells = gMenuSceneState->mSinglePlaySelectModeSLayoutTable;
    selectedIndex = gMenuSceneState->mSinglePlaySelectModeIndex;
    for (i = 0; i <= 9; i++) {
        subCells[i].mVisible = 1;
    }
    for (i = 10; i <= 14; i++) {
        subCells[i].mVisible = 0;
    }
    if (menu_getCurState() != 3 || gMenuSceneState->field934 == FALSE || menu_getFrameCounter() >= 5) {
        subCells[selectedIndex + 5].mVisible = 0;
        subCells[selectedIndex + 10].mVisible = 1;
    }
    if (gMenuSceneState->mScreenNumber == 3) {
        subCells[selectedIndex].mOffsetX = gMenuSceneState->field938;
        subCells[selectedIndex + 5].mOffsetX = gMenuSceneState->field938;
        subCells[selectedIndex + 10].mOffsetX = gMenuSceneState->field938;
    }
}
