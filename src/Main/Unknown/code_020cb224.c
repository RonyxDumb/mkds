#include "Main/Unknown/code_020cb224.h"
#include "Main/Unknown/code_020cb3e4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb48c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "gx.h"
#include "code_02148950.h"
#include "code_0214b824.h"
#include "registers.h"
#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020cb2cc.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_020cb234.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0212775c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020cb22c.h"

void MenuGX_SetVisiblePlane(int bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GX_DISPCNT;
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    reg_GX_DISPCNT = value0;
}

void MenuGXS_SetVisiblePlane(int bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    reg_GXS_DB_DISPCNT = value0;
}

#pragma thumb on

void SetupSinglePlaySelectGraphics(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        MenuGX_SetVisiblePlane(0x18);
        GX_SetGraphicsMode(1, 0, 0);
        GX_LoadOBJPltt(gMenuScene->mSinglePlaySelectModeMONclr->mData, 0, (0x000001a0u));
        GX_LoadOBJPltt(&gMenuScene->mSinglePlaySelectModeMONclr->mData[0xe0], 0x1c0, 0x40);
        GX_LoadOBJ(gMenuScene->mSinglePlaySelectModeMNcgr->mData, 0, gMenuScene->mSinglePlaySelectModeMNcgr->mDataSize);
        MenuGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
        GXS_LoadOBJPltt(gMenuScene->mSinglePlaySelectModeSONclr->mData, 0,
                        gMenuScene->mSinglePlaySelectModeSONclr->mDataSize);
        GXS_LoadOBJ(gMenuScene->mSinglePlaySelectModeSNcgr->mData, 0,
                    gMenuScene->mSinglePlaySelectModeSNcgr->mDataSize);
    }
}

#pragma thumb off

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
#pragma thumb off

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

#pragma thumb on
void WriteSinglePlaySelect1Registers(void) {
    u32 unusedValue;
    SetupSinglePlaySelectGraphics();
}
#pragma thumb off

u32 GetMenuInputSlot(void) {
    return 0x8u;
}
