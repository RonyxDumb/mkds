#include "01/Menu/select_screen_registers.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_cup_m.h"
#include "01/Menu/select_visible_plane.h"
#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/Menu/mission_run_screen_registers.h"
#include "01/Menu/select_ghost.h"
#include "01/code_021a1000.h"
#include "01/Menu/select_engine.h"
#include "gx.h"
#include "code_02148950.h"
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

void WriteMainBg1CntFields(u32 a, u32 b, u32 c, u32 d, u32 e) {
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | (a << 14) | (b << 7) |
                    (c << 8) | (d << 2) | (e << 13);
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
        case 1:
            SwitchMenuScreen(29, 0x1f);
            break;
        case 2:
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
        case 1:
            SwitchMenuScreen(25, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(23, 0x1f);
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
        case 1:
            SwitchMenuScreen(5, 0x1f);
            break;
        case 2:
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
        case 1:
            SwitchMenuScreen(6, 0x1f);
            break;
        case 2:
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
        case 1:
            SwitchMenuScreen(7, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(5, 0x1f);
            break;
    }
}
