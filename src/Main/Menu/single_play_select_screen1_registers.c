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
        ConfigureDispcntDisplay(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        CopySomePaletteData(g_GlobalB43C->mSinglePlaySelectModeMONclr->mData, 0, (0x000001a0u));
        CopySomePaletteData(&g_GlobalB43C->mSinglePlaySelectModeMONclr->mData[0xe0], 0x1c0, 0x40);
        CopyTileDataTop_0(g_GlobalB43C->mSinglePlaySelectModeMNcgr->mData, 0, g_GlobalB43C->mSinglePlaySelectModeMNcgr->mDataSize);
        MenuGXS_SetVisiblePlane(0x16);
        SetDispcntSubBgMode(GX_BGMODE_0);
        TEQSub_Fn30Impl(g_GlobalB43C->mSinglePlaySelectModeSONclr->mData, 0,
                        g_GlobalB43C->mSinglePlaySelectModeSONclr->mDataSize);
        TEQSub_Fn35Impl(g_GlobalB43C->mSinglePlaySelectModeSNcgr->mData, 0,
                    g_GlobalB43C->mSinglePlaySelectModeSNcgr->mDataSize);
    }
}

#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
void UpdateSinglePlaySelectSubCells(void) {
    LayoutTableEntry *subCells;
    s32 selectedIndex;
    s32 cellIndex;

    subCells = g_GlobalB43C->mSinglePlaySelectModeSLayoutTable;
    selectedIndex = g_GlobalB43C->mSinglePlaySelectModeIndex;
    for (cellIndex = 0; cellIndex <= 9; cellIndex++) {
        subCells[cellIndex].mVisible = 1;
    }
    for (cellIndex = 10; cellIndex <= 14; cellIndex++) {
        subCells[cellIndex].mVisible = 0;
    }
    if (GetMenuScreenNumber() != SCREEN_SINGLE_PLAY_SELECT_PRESS ||
        g_GlobalB43C->mSinglePlaySelectStartedOnSelected == FALSE ||
        GetFramesSinceMenuScreenSwitch() >= 5) {
        subCells[selectedIndex + 5].mVisible = 0;
        subCells[selectedIndex + 10].mVisible = 1;
    }
    if (g_GlobalB43C->mScreenNumber == SCREEN_SINGLE_PLAY_SELECT_PRESS) {
        subCells[selectedIndex].mOffsetX = g_GlobalB43C->mSinglePlaySelectModePressOffset;
        subCells[selectedIndex + 5].mOffsetX = g_GlobalB43C->mSinglePlaySelectModePressOffset;
        subCells[selectedIndex + 10].mOffsetX = g_GlobalB43C->mSinglePlaySelectModePressOffset;
    }
}
#pragma thumb off

#pragma thumb on

void DrawSinglePlaySelectCells(void) {
    MenuScene *menu;
    UpdateSinglePlaySelectSubCells();
    menu = g_GlobalB43C;
    DrawLayoutTable(menu->mSinglePlaySelectModeMBncl, menu->mSinglePlaySelectModeMNcer, NULL, menu->mMainOam,
                    menu->mSinglePlaySelectModeMLayoutTable);
    menu = g_GlobalB43C;
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
    mainCells = g_GlobalB43C->mSinglePlaySelectModeMLayoutTable;
    subCells = g_GlobalB43C->mSinglePlaySelectModeSLayoutTable;
    if (frame < 10) {
        mainCells->mOffsetY = ComputeValueInterpolation_from_thumb(1, -0x28, 0, frame, 10);
        offset = ComputeValueInterpolation_from_thumb(1, 0xf0, 0, frame, 10);
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
        g_GlobalB43C->mSinglePlaySelectStartedOnSelected = FALSE;
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
