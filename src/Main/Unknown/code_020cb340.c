#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateSinglePlaySelectSubCells(void) {
    LayoutTableEntry *subCells;
    s32 selectedIndex;
    s32 cellIndex;

    subCells = gMenuScene->mSinglePlaySelectModeSLayoutTable;
    selectedIndex = gMenuScene->mSinglePlaySelectModeIndex;
    for (cellIndex = 0; cellIndex <= 9; cellIndex++) {
        subCells[cellIndex].mVisible = 1;
    }
    for (cellIndex = 10; cellIndex <= 14; cellIndex++) {
        subCells[cellIndex].mVisible = 0;
    }
    if (GetMenuScreenNumber() != 3 || gMenuScene->mSinglePlaySelectStartedOnSelected == FALSE ||
        GetFramesSinceMenuScreenSwitch() >= 5) {
        subCells[selectedIndex + 5].mVisible = 0;
        subCells[selectedIndex + 10].mVisible = 1;
    }
    if (gMenuScene->mScreenNumber == 3) {
        subCells[selectedIndex].mOffsetX = gMenuScene->mSinglePlaySelectModePressOffset;
        subCells[selectedIndex + 5].mOffsetX = gMenuScene->mSinglePlaySelectModePressOffset;
        subCells[selectedIndex + 10].mOffsetX = gMenuScene->mSinglePlaySelectModePressOffset;
    }
}
