#include "Main/Menu/vs_select_cup_m.h"
#include "Main/Menu/menu_screen_switch.h"
#include "fixed_point_graphics_setup.h"
#include "vram_bank_display_setup.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Race/race_setup.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Menu/select_cup_grid.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/Menu/select_race_rule_state.h"
#include "registers.h"
#include "Main/Menu/select_cup_m.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_hud_sub_screen_rain_star_cells.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Menu/menu_entry_kind.h"

#pragma thumb on

void WriteVsSelectCharacterRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
        VsSelectGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    VsSelectGXS_SetVisiblePlane(0x12);
    WriteSelectCharacterRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_KART_VS, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_IN, SCREEN_NONE);
            break;
        case SELECT_CHARACTER_RESULT_TIME_UP:
            SwitchMenuScreen(SCREEN_SELECT_RACE_RULE_VS, SCREEN_NONE);
            break;
    }
}

void WriteVsSelectKartRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    }
    VsSelectGXS_SetVisiblePlane(0x12);
    WriteSelectKartRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectKart(void) {
    switch (AdvanceSelectKart()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_RACE_RULE_VS, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CHARACTER_VS, SCREEN_NONE);
            break;
    }
}

void WriteVsSelectRaceRuleRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGXS_SetVisiblePlane(0x1f);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectRaceRuleRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectRaceRule(void) {
    switch (AdvanceSelectRaceRule()) {
        case MENU_SCREEN_RESULT_NEXT:
            if (GetRaceSetupCopy()->mCourseListMode == COURSE_LIST_MODE_SHUFFLED) {
                GetRaceSetupCopy()->mCourseId = COURSE_ID_CROSS;
                SwitchMenuScreen(SCREEN_NEXT_RACE_SETUP, SCREEN_NONE);
            } else {
                SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_VS, SCREEN_NONE);
            }
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_KART_VS, SCREEN_NONE);
            break;
    }
}

void WriteVsSelectCupGridRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupMB_IsMultiBootChildWrapper();
        if (flag == 0) {
            VsSelectGX_SetVisiblePlane(0x19);
            GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
            VsSelectGXS_SetVisiblePlane(0x16);
            GXS_SetGraphicsMode(GX_BGMODE_0);
        } else {
            VsSelectGX_SetVisiblePlane(0x18);
            GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
            VsSelectGXS_SetVisiblePlane(0x12);
            GXS_SetGraphicsMode(GX_BGMODE_0);
        }
    }
    WriteSelectCupGridRegisters();
}

#pragma thumb off

u32 VsSelectCupGetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}

void VsSelectCupSetMenuEntryKind(u32 entryKind) {
    gMenuShared->mMenuEntryKind = entryKind;
}

void VsSelectCupSetRaceSetupRequested(u32 requested) {
    gMenuShared->mRaceSetupRequested = requested;
}

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupGrid(void) {
    switch (AdvanceSelectCupGrid()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_CUP_M_VS, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_RACE_RULE_VS, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_LEAVE:
            if (VsSelectCupGetConnectionKind() == CONNECTION_KIND_NONE) {
                SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_IN, SCREEN_NONE);
            } else {
                SwitchMenuScreen(SCREEN_SELECT_GAME, SCREEN_NONE);
            }
            VsSelectCupSetMenuEntryKind(MENU_ENTRY_SINGLE_PLAY_SELECT);
            VsSelectCupSetRaceSetupRequested(1);
            break;
    }
}

void WriteVsSelectCupCourseRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupMB_IsMultiBootChildWrapper();
        if (flag == 0) {
            VsSelectGX_SetVisiblePlane(0x19);
            GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
            VsSelectGXS_SetVisiblePlane(0x1e);
            GXS_SetGraphicsMode(GX_BGMODE_0);
        } else {
            VsSelectGX_SetVisiblePlane(0x1c);
            GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
            VsSelectGXS_SetVisiblePlane(0x12);
            GXS_SetGraphicsMode(GX_BGMODE_0);
        }
    }
    WriteSelectCupCourseBgOffsets();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupCourse(void) {
    switch (AdvanceSelectCupCourse()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_NEXT_RACE_SETUP, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CUP_M_VS, SCREEN_NONE);
            break;
    }
}
#pragma thumb off

BootInfo *VsSelectCupMB_GetMultiBootParam(void) {
    return gBootInfo;
}

BOOL VsSelectCupMB_IsMultiBootChild(void) {
    return VsSelectCupMB_GetMultiBootParam()->mBootType == BOOT_TYPE_MULTIBOOT ? 1 : 0;
}

BOOL VsSelectCupMB_IsMultiBootChildWrapper(void) {
    return VsSelectCupMB_IsMultiBootChild();
}

void VsSelectGX_SetVisiblePlane(int bits) {
    u32 newDispcnt = bits;
    u32 dispcnt;
    dispcnt = reg_GX_DISPCNT;
    dispcnt = (dispcnt) & ~(0x1f00u);
    newDispcnt = (dispcnt) | ((newDispcnt << 8));
    reg_GX_DISPCNT = newDispcnt;
}

void VsSelectGXS_SetVisiblePlane(int bits) {
    u32 newDispcnt = bits;
    u32 dispcnt;
    dispcnt = reg_GXS_DB_DISPCNT;
    dispcnt = (dispcnt) & ~(0x1f00u);
    newDispcnt = (dispcnt) | ((newDispcnt << 8));
    reg_GXS_DB_DISPCNT = newDispcnt;
}

#pragma thumb on

void WriteVsSelectCupMRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupMB_IsMultiBootChildWrapper();
        if (flag == 0) {
            VsSelectGX_SetVisiblePlane(0x19);
            GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
            VsSelectGXS_SetVisiblePlane(0x1e);
            GXS_SetGraphicsMode(GX_BGMODE_0);
        } else {
            VsSelectGX_SetVisiblePlane(0x18);
            GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
            VsSelectGXS_SetVisiblePlane(0x12);
            GXS_SetGraphicsMode(GX_BGMODE_0);
        }
    }
    WriteSelectCupMBgOffsets();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupM(void) {
    switch (AdvanceSelectCupM()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_CUP_COURSE_VS, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_VS, SCREEN_NONE);
            break;
    }
}
#pragma thumb off

s32 CreateRaceHudSubScreenRainStarCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRainStarCells, 0x154);
}
