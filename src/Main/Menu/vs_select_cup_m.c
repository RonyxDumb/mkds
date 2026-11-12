#include "Main/Menu/vs_select_cup_m.h"
#include "Main/Menu/menu_screen_switch.h"
#include "gx.h"
#include "code_02148950.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Race/race_setup.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Menu/select_cup_grid.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/Menu/select_race_rule_state.h"
#include "registers.h"
#include "Main/Menu/select_cup_m.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_hud_sub_screen_rain_star_cells.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma thumb on

void WriteVsSelectCharacterRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
        VsSelectGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(0);
    }
    VsSelectGXS_SetVisiblePlane(0x12);
    WriteSelectCharacterRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
            SwitchMenuScreen(9, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0xa, 0x1f);
            break;
    }
}
#pragma thumb off

#pragma thumb on

void WriteVsSelectKartRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
    }
    VsSelectGXS_SetVisiblePlane(0x12);
    WriteSelectKartRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectKart(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            SwitchMenuScreen(0xa, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(8, 0x1f);
            break;
    }
}
#pragma thumb off

#pragma thumb on

void WriteVsSelectRaceRuleRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGXS_SetVisiblePlane(0x1f);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectRaceRuleRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectRaceRule(void) {
    switch (AdvanceSelectRaceRule()) {
        case 1:
            if (GetRaceSetupCopy()->mCourseListMode == 2) {
                GetRaceSetupCopy()->mCourseId = COURSE_ID_CROSS;
                SwitchMenuScreen(0x1d, 0x1f);
            } else {
                SwitchMenuScreen(0xb, 0x1f);
            }
            break;
        case 2:
            SwitchMenuScreen(9, 0x1f);
            break;
    }
}
#pragma thumb off

#pragma thumb on

void WriteVsSelectCupGridRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupMB_IsMultiBootChildWrapper();
        if (flag == 0) {
            VsSelectGX_SetVisiblePlane(0x19);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x16);
            GXS_SetGraphicsMode(0);
        } else {
            VsSelectGX_SetVisiblePlane(0x18);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x12);
            GXS_SetGraphicsMode(0);
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
        case 1:
            SwitchMenuScreen(0xc, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0xa, 0x1f);
            break;
        case 3:
            if (VsSelectCupGetConnectionKind() == 0) {
                SwitchMenuScreen(0, 0x1f);
            } else {
                SwitchMenuScreen(0xe, 0x1f);
            }
            VsSelectCupSetMenuEntryKind(0);
            VsSelectCupSetRaceSetupRequested(1);
            break;
    }
}
#pragma thumb off

#pragma thumb on

void WriteVsSelectCupCourseRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupMB_IsMultiBootChildWrapper();
        if (flag == 0) {
            VsSelectGX_SetVisiblePlane(0x19);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x1e);
            GXS_SetGraphicsMode(0);
        } else {
            VsSelectGX_SetVisiblePlane(0x1c);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x12);
            GXS_SetGraphicsMode(0);
        }
    }
    WriteSelectCupCourseBgOffsets();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupCourse(void) {
    switch (AdvanceSelectCupCourse()) {
        case 1:
            SwitchMenuScreen(0x1d, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0xc, 0x1f);
            break;
    }
}
#pragma thumb off

BootInfo *VsSelectCupMB_GetMultiBootParam(void) {
    return gBootInfo;
}

BOOL VsSelectCupMB_IsMultiBootChild(void) {
    return VsSelectCupMB_GetMultiBootParam()->mBootType == 2 ? 1 : 0;
}

BOOL VsSelectCupMB_IsMultiBootChildWrapper(void) {
    return VsSelectCupMB_IsMultiBootChild();
}

void VsSelectGX_SetVisiblePlane(int bits) {
    u32 value0 = bits;
    u32 value1;
    value1 = reg_GX_DISPCNT;
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    reg_GX_DISPCNT = value0;
}

void VsSelectGXS_SetVisiblePlane(int bits) {
    u32 value0 = bits;
    u32 value1;
    value1 = reg_GXS_DB_DISPCNT;
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    reg_GXS_DB_DISPCNT = value0;
}

#pragma thumb on

void WriteVsSelectCupMRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupMB_IsMultiBootChildWrapper();
        if (flag == 0) {
            VsSelectGX_SetVisiblePlane(0x19);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x1e);
            GXS_SetGraphicsMode(0);
        } else {
            VsSelectGX_SetVisiblePlane(0x18);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x12);
            GXS_SetGraphicsMode(0);
        }
    }
    WriteSelectCupMBgOffsets();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupM(void) {
    switch (AdvanceSelectCupM()) {
        case 1:
            SwitchMenuScreen(0xd, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0xb, 0x1f);
            break;
    }
}
#pragma thumb off

s32 CreateRaceHudSubScreenRainStarCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRainStarCells, 0x154);
}
