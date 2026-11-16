#include "01/code_0218550c.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Scene/SelectCupM.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_0211e000.h"
#include "01/code_021854d8.h"
#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/code_021857a4.h"
#include "01/code_0219b540.h"
#include "01/code_021a1000.h"
#include "01/code_021a11a4.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_020cc000.h"
#include "gx.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_02027e78.h"

#pragma optimize_for_size on

#pragma thumb off

void func_ov001_02185778(int enable) {
    if (enable != 0) {
        reg_G2_BG1CNT |= 0x40;
    } else {
        reg_G2_BG1CNT &= ~0x40;
    }
}

void func_ov001_02185740(u32 a, u32 b, u32 c, u32 d, u32 e) {
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13);
}

#pragma thumb on

void menu_state26Vblank(void) {
    if (menu_getField4() != 0) {
        menu_ta_GX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        WriteMainBg1Offset(0, 0);
        func_ov001_021857a4(0);
        func_ov001_02185778(0);
        func_ov001_02185740(0, 0, 0xc, 0, 0);
        menu_ta_GXS_SetVisiblePlane(0x1f);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectGhostRegisters();
}

void menu_state26Render(void) {
    switch (AdvanceSelectGhost()) {
        case 1:
            menu_gotoState(29, 0x1f);
            break;
        case 2:
            menu_gotoState(25, 0x1f);
            break;
    }
}

#pragma thumb off

void menu_ta_GX_SetVisiblePlane(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (bits << 8);
}

void menu_ta_GXS_SetVisiblePlane(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (bits << 8);
}

#pragma thumb on

void menu_state24Vblank(void) {
    if (menu_getField4() != 0) {
        menu_ta_GX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        menu_ta_GXS_SetVisiblePlane(0x1e);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectCupMBgOffsets();
}

void menu_state24Render(void) {
    switch (AdvanceSelectCupM()) {
        case 1:
            menu_gotoState(25, 0x1f);
            break;
        case 2:
            menu_gotoState(23, 0x1f);
            break;
    }
}

void menu_state4Vblank(void) {
    if (menu_getField4() != 0) {
        moverlay_menu_GX_SetVisiblePlane(0x1b);
        GX_SetGraphicsMode(1, 0, 0);
        moverlay_menu_GXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectEngineBg0Offset();
}

void menu_state4Render(void) {
    switch (AdvanceSelectEngine()) {
        case 1:
            menu_gotoState(5, 0x1f);
            break;
        case 2:
            menu_gotoState(0, 0x1f);
            break;
    }
}

void menu_state5Vblank(void) {
    if (menu_getField4() != 0) {
        moverlay_menu_GX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
        moverlay_menu_GXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(0);
    }
    menucs_2026058();
}

void menu_state5Render(void) {
    switch (menucs_render()) {
        case 1:
            menu_gotoState(6, 0x1f);
            break;
        case 2:
            menu_gotoState(SCREEN_SELECT_ENGINE, 0x1f);
            break;
    }
}

void menu_state6Vblank(void) {
    if (menu_getField4() != 0) {
        moverlay_menu_GX_SetVisiblePlane(9);
        GX_SetGraphicsMode(1, 0, 1);
        moverlay_menu_GXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectKartRegisters();
}

void menu_state6Render(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            menu_gotoState(7, 0x1f);
            break;
        case 2:
            menu_gotoState(5, 0x1f);
            break;
    }
}
