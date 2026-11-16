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
void menu_modeSelectSelectedOutEffectStateRender(void) {
    s32 nextScreenAndModeTable[5][2] = {{4, 0}, {0x14, 1}, {8, 3}, {0xe, 2}, {0x12, 4}};
    s32 framesSinceSwitch;

    framesSinceSwitch = menu_getFrameCounter();
    gMenuSceneState->field938 = mutil_getButtonOutEffectOffset(framesSinceSwitch);
    if (framesSinceSwitch >= 10) {
        menu_gotoState(2, nextScreenAndModeTable[gMenuSceneState->mSinglePlaySelectModeIndex][0]);
        menu_initRaceConfig();
        menu_getRaceConfig()->mMode = nextScreenAndModeTable[gMenuSceneState->mSinglePlaySelectModeIndex][1];
    }
    menu_renderModeSelectUI();
}
#pragma thumb off
