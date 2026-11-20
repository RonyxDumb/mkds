#include "Main/Menu/single_play_select_screen1_registers.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Menu/menu_screen_switch.h"
#include "fixed_point_graphics_setup.h"
#include "vram_bank_display_setup.h"
#include "vram_load_2d_graphics.h"
#include "registers.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/select_return.h"
#include "00/Menu/wi_fi_vs_setting.h"

void MenuGX_SetVisiblePlane(int bits) {
    u32 newDispcnt = bits;
    u32 registerValue;
    registerValue = reg_GX_DISPCNT;
    registerValue = (registerValue) & ~(0x1f00u);
    newDispcnt = (registerValue) | ((newDispcnt << 8));
    reg_GX_DISPCNT = newDispcnt;
}

void MenuGXS_SetVisiblePlane(int bits) {
    u32 newDispcnt = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0x1f00u);
    newDispcnt = (registerValue) | ((newDispcnt << 8));
    reg_GXS_DB_DISPCNT = newDispcnt;
}

#pragma thumb on

void SetupSinglePlaySelectGraphics(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        MenuGX_SetVisiblePlane(0x18);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        GX_LoadOBJPltt(gMenuScene->mSinglePlaySelectModeMONclr->mData, 0, (0x000001a0u));
        GX_LoadOBJPltt(&gMenuScene->mSinglePlaySelectModeMONclr->mData[0xe0], 0x1c0, 0x40);
        GX_LoadOBJ(gMenuScene->mSinglePlaySelectModeMNcgr->mData, 0, gMenuScene->mSinglePlaySelectModeMNcgr->mDataSize);
        MenuGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(GX_BGMODE_0);
        GXS_LoadOBJPltt(gMenuScene->mSinglePlaySelectModeSONclr->mData, 0,
                        gMenuScene->mSinglePlaySelectModeSONclr->mDataSize);
        GXS_LoadOBJ(gMenuScene->mSinglePlaySelectModeSNcgr->mData, 0,
                    gMenuScene->mSinglePlaySelectModeSNcgr->mDataSize);
    }
}

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
    if (GetMenuScreenNumber() != SCREEN_SINGLE_PLAY_SELECT_PRESS ||
        gMenuScene->mSinglePlaySelectStartedOnSelected == FALSE ||
        GetFramesSinceMenuScreenSwitch() >= 5) {
        subCells[selectedIndex + 5].mVisible = 0;
        subCells[selectedIndex + 10].mVisible = 1;
    }
    if (gMenuScene->mScreenNumber == SCREEN_SINGLE_PLAY_SELECT_PRESS) {
        subCells[selectedIndex].mOffsetX = gMenuScene->mSinglePlaySelectModePressOffset;
        subCells[selectedIndex + 5].mOffsetX = gMenuScene->mSinglePlaySelectModePressOffset;
        subCells[selectedIndex + 10].mOffsetX = gMenuScene->mSinglePlaySelectModePressOffset;
    }
}

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

void WriteSinglePlaySelect0Registers(void) {
    u32 unusedValue;
    SetupSinglePlaySelectGraphics();
}

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
        offset = InterpolateS16(1, SINGLE_PLAY_SELECT_OFFSCREEN_X, 0, frame, 10);
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = offset;
        }
        RequestSelectReturnSlideIn();
    } else {
        mainCells->mOffsetY = 0;
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = 0;
        }
        SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_CHOOSE, SCREEN_NONE);
        SetSelectReturnSoundId(0xf);
        gMenuScene->mSinglePlaySelectStartedOnSelected = FALSE;
    }
    DrawSinglePlaySelectCells();
}

void WriteSinglePlaySelect1Registers(void) {
    u32 unusedValue;
    SetupSinglePlaySelectGraphics();
}
#pragma thumb off

u32 GetMenuInputSlot(void) {
    return 0x8u;
}
