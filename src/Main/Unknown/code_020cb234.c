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
void UpdateSinglePlaySelectMenuScreen0(void) {
    s32 frame;
    LayoutTableEntry *mainCells;
    LayoutTableEntry *subCells;
    s32 cellIndex;
    s16 offset;

    frame = GetFramesSinceMenuScreenSwitch();
    mainCells = gMenuScene->mSinglePlaySelectModeMLayoutTable;
    subCells = gMenuScene->mSinglePlaySelectModeSLayoutTable;
    if (frame < 10) {
        mainCells->mOffsetY = InterpolateS16(1, -0x28, 0, frame, 10);
        offset = InterpolateS16(1, 0xf0, 0, frame, 10);
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = offset;
        }
        RequestSelectReturnState1();
    } else {
        mainCells->mOffsetY = 0;
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = 0;
        }
        SwitchMenuScreen(1, 0x1f);
        SetSelectReturnSoundId(0xf);
        gMenuScene->mSinglePlaySelectStartedOnSelected = FALSE;
    }
    DrawSinglePlaySelectCells();
}
#pragma thumb off
