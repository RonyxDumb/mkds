#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02029890.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0202993c.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateSinglePlaySelectMenuScreen3(void) {
    s32 nextScreenAndModeTable[5][2] = {{4, 0}, {0x14, 1}, {8, 3}, {0xe, 2}, {0x12, 4}};
    s32 framesSinceSwitch;

    framesSinceSwitch = GetFramesSinceMenuScreenSwitch();
    gMenuScene->mSinglePlaySelectModePressOffset = GetSelectedPressOffset(framesSinceSwitch);
    if (framesSinceSwitch >= 10) {
        SwitchMenuScreen(2, nextScreenAndModeTable[gMenuScene->mSinglePlaySelectModeIndex][0]);
        ResetRaceSetupCopy();
        GetRaceSetupCopy()->mMode = nextScreenAndModeTable[gMenuScene->mSinglePlaySelectModeIndex][1];
    }
    DrawSinglePlaySelectCells();
}
#pragma thumb off
