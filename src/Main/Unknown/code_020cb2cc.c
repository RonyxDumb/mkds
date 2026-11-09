#include "Main/Unknown/code_020cb2cc.h"

#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cb3e4.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void DrawSinglePlaySelectCells(void) {
    MenuScene *menu;
    UpdateSinglePlaySelectSubCells();
    menu = gMenuScene;
    DrawLayoutTable(menu->mSinglePlaySelectModeMBncl, menu->mSinglePlaySelectModeMNcer, NULL, menu->mMainOam,
                    menu->mSinglePlaySelectModeMLayoutTable);
    menu = gMenuScene;
    DrawLayoutTable(menu->mSinglePlaySelectModeSBncl, menu->mSinglePlaySelectModeSNcer, NULL, menu->mSubOam,
                    menu->mSinglePlaySelectModeSLayoutTable);
}

#pragma thumb off

#pragma thumb on
void WriteSinglePlaySelect0Registers(void) {
    u32 unusedValue;
    SetupSinglePlaySelectGraphics();
}
#pragma thumb off
