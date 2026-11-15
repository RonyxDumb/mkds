#include "01/Menu/select_screen_registers.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_cup_m.h"
#include "01/Menu/select_visible_plane.h"
#include "01/callees_0219b000.h"
#include "01/Menu/mission_run_screen_registers.h"
#include "01/Menu/select_ghost.h"
#include "01/Menu/select_engine.h"
#include "gx.h"
#include "vram_bank_assign.h"
#include "registers.h"
#include "Main/Menu/select_kart_data.h"

#pragma optimize_for_size on

#pragma thumb off

void WriteMainBg1CntFlag(int enable) {
    if (enable != 0) {
        reg_G2_BG1CNT |= REG_G2_BG1CNT_MOSAIC_MASK;
    } else {
        reg_G2_BG1CNT &= ~REG_G2_BG1CNT_MOSAIC_MASK;
    }
}

void WriteMainBg1CntFields(u32 screenSize, u32 colorMode, u32 screenBase, u32 charBase, u32 overflowMode) {
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | (screenSize << 14) |
                    (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (overflowMode << 13);
}

#pragma thumb on

void WriteSelectGhostScreenRegisters(void) {
    if (GetMenuScreenSwitched() != 0) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        WriteMainBg1Offset(0, 0);
        WriteMainBg1CntLowBits(0);
        WriteMainBg1CntFlag(0);
        WriteMainBg1CntFields(0, 0, 0xc, 0, 0);
        TimeAttackGXS_SetVisiblePlane(0x1f);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectGhostRegisters();
}

void UpdateSelectGhost(void) {
    switch (AdvanceSelectGhost()) {
        case SELECT_GHOST_RESULT_CHOSEN:
            SwitchMenuScreen(29, 0x1f);
            break;
        case SELECT_GHOST_RESULT_RETURN:
            SwitchMenuScreen(25, 0x1f);
            break;
    }
}

#pragma thumb off

void TimeAttackGX_SetVisiblePlane(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (bits << 8);
}

void TimeAttackGXS_SetVisiblePlane(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (bits << 8);
}

#pragma thumb on

void WriteSelectCupMScreenRegisters(void) {
    if (GetMenuScreenSwitched() != 0) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        TimeAttackGXS_SetVisiblePlane(0x1e);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectCupMBgOffsets();
}

void UpdateSelectCupM(void) {
    switch (AdvanceSelectCupM()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_CUP_COURSE_TIME_ATTACK, 0x1f);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_TIME_ATTACK, 0x1f);
            break;
    }
}

void WriteSelectEngineScreenRegisters(void) {
    if (GetMenuScreenSwitched() != 0) {
        SelectGX_SetVisiblePlane(0x1b);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        SelectGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectEngineBg0Offset();
}

void UpdateSelectEngine(void) {
    switch (AdvanceSelectEngine()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_CHARACTER_GRAND_PRIX, 0x1f);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(0, 0x1f);
            break;
    }
}

void WriteSelectCharacterScreenRegisters(void) {
    if (GetMenuScreenSwitched() != 0) {
        SelectGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
        SelectGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectCharacterRegisters();
}

void UpdateSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_KART_GRAND_PRIX, 0x1f);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_ENGINE, 0x1f);
            break;
    }
}

void WriteSelectKartScreenRegisters(void) {
    if (GetMenuScreenSwitched() != 0) {
        SelectGX_SetVisiblePlane(9);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
        SelectGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectKartRegisters();
}

void UpdateSelectKart(void) {
    switch (AdvanceSelectKart()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_GRAND_PRIX, 0x1f);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CHARACTER_GRAND_PRIX, 0x1f);
            break;
    }
}
