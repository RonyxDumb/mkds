#include "Main/Unknown/code_020cb2cc.h"

#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cb3e4.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void menu_renderModeSelectUI(void) {
    MenuScene *menu;
    menu_updateModeSelectUI();
    menu = gMenuSceneState;
    jn_ui_renderElements(menu->mSinglePlaySelectModeMBncl, menu->mSinglePlaySelectModeMNcer, NULL, menu->mMainOam,
                    menu->mSinglePlaySelectModeMLayoutTable);
    menu = gMenuSceneState;
    jn_ui_renderElements(menu->mSinglePlaySelectModeSBncl, menu->mSinglePlaySelectModeSNcer, NULL, menu->mSubOam,
                    menu->mSinglePlaySelectModeSLayoutTable);
}

#pragma thumb off

#pragma thumb on
void menu_modeSelectInStateVblank(void) {
    u32 unusedValue;
    modeSelectVblank();
}
#pragma thumb off
