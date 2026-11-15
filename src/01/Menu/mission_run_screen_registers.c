#include "01/Menu/mission_run_screen_registers.h"
#include "01/Menu/select_screen_registers.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/Menu/mission_run_level_select.h"
#include "01/Menu/mission_run_mission_select.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "01/Menu/time_attack_top_menu.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_cup_grid.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/ghost_record_set.h"
#include "gx.h"
#include "vram_bank_assign.h"
#include "registers.h"
#include "Main/Menu/menu_shared_clear.h"
#include "01/Menu/menu_screen_states_and_file_names.h"

#pragma optimize_for_size on

u16 IsMissionGateFrameAdvanced(MissionGateObject *missionGateObject) {
    return missionGateObject->mNsbmaFrameIndex != 0;
}

void WriteMissionRunLVselScreenRegisters(void) {
    if (GetMenuScreenSwitched()) {
        MissionRunGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        MissionRunGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteMissionRunLVselBg0Offset();
}

void UpdateMissionRunLVsel(void) {
    switch (AdvanceMissionRunLVsel()) {
        case MISSION_RUN_LVSEL_RESULT_LEVEL_CHOSEN:
            SwitchMenuScreen(SCREEN_MISSION_RUN_MSSEL, 0x1f);
            break;
        case MISSION_RUN_LVSEL_RESULT_BACK:
            SwitchMenuScreen(0, 0x1f);
            break;
    }
}

#pragma thumb off
void MissionRunGX_SetVisiblePlane(u32 bits) {
    vu32 *dispCnt = &reg_GX_DISPCNT;
    *dispCnt = (*dispCnt & ~0x1f00) | (bits << 8);
}

void MissionRunGXS_SetVisiblePlane(u32 bits) {
    vu32 *dispCnt = &reg_GXS_DB_DISPCNT;
    *dispCnt = (*dispCnt & ~0x1f00) | (bits << 8);
}
#pragma thumb on

void WriteMissionRunMSselScreenRegisters(void) {
    if (GetMenuScreenSwitched()) {
        MissionRunGX_SetVisiblePlane(0x1b);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        MissionRunGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteMissionRunMSselBgOffsets();
}

void UpdateMissionRunMSsel(void) {
    switch (AdvanceMissionRunMSsel()) {
        case MISSION_RUN_MSSEL_RESULT_MISSION_CHOSEN:
            SwitchMenuScreen(SCREEN_NEXT_RACE_SETUP, 0x1f);
            break;
        case MISSION_RUN_MSSEL_RESULT_BACK:
            SwitchMenuScreen(SCREEN_MISSION_RUN_LVSEL, 0x1f);
            break;
    }
}

void WriteTimeAttackTopMenuRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        TimeAttackGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteTimeAttackTopMenuBg0Offset();
}

#pragma thumb off
void SetGhostSceneInitialCallbacksIndex(s32 callbacksIndex) {
    gMenuShared->mGhostSceneInitialCallbacksIndex = callbacksIndex;
}
#pragma thumb on

void UpdateTimeAttackTopMenu(void) {
    switch (AdvanceTimeAttackTopMenu()) {
        case TIME_ATTACK_TOP_RESULT_TIME_TRIALS:
            SwitchMenuScreen(SCREEN_SELECT_CHARACTER_TIME_ATTACK, 0x1f);
            break;
        case TIME_ATTACK_TOP_RESULT_SEND_GHOST:
            SwitchMenuScreen(0x1c, 0x1f);
            SetGhostSceneInitialCallbacksIndex(0);
            break;
        case TIME_ATTACK_TOP_RESULT_RECEIVE_GHOST:
            SwitchMenuScreen(0x1c, 0x1f);
            SetGhostSceneInitialCallbacksIndex(1);
            break;
        case TIME_ATTACK_TOP_RESULT_RETURN:
            SwitchMenuScreen(0, 0x1f);
            break;
    }
}

void WriteTimeAttackCharacterRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
        TimeAttackGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    TimeAttackGXS_SetVisiblePlane(0x12);
    WriteSelectCharacterRegisters();
}

void UpdateTimeAttackSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_KART_TIME_ATTACK, 0x1f);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_TIME_ATTACK_TOP_MENU, 0x1f);
            break;
    }
}

void WriteTimeAttackKartRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    }
    TimeAttackGXS_SetVisiblePlane(0x12);
    WriteSelectKartRegisters();
}

void UpdateTimeAttackSelectKart(void) {
    switch (AdvanceSelectKart()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_TIME_ATTACK, 0x1f);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CHARACTER_TIME_ATTACK, 0x1f);
            break;
    }
}

void WriteTimeAttackCupGridRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        TimeAttackGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectCupGridRegisters();
}

#pragma thumb off
void TimeAttackSetMenuEntryKind(s32 value) {
    gMenuShared->mMenuEntryKind = value;
}

void TimeAttackSetRaceSetupRequested(s32 value) {
    gMenuShared->mRaceSetupRequested = value;
}
#pragma thumb on

void UpdateTimeAttackSelectCupGrid(void) {
    switch (AdvanceSelectCupGrid()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_SELECT_CUP_M_TIME_ATTACK, 0x1f);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_KART_TIME_ATTACK, 0x1f);
            break;
        case MENU_SCREEN_RESULT_LEAVE:
            SwitchMenuScreen(0, 0x1f);
            TimeAttackSetMenuEntryKind(0);
            TimeAttackSetRaceSetupRequested(1);
            break;
    }
}

void WriteTimeAttackCupCourseRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        TimeAttackGXS_SetVisiblePlane(0x1e);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectCupCourseBgOffsets();
}

void UpdateTimeAttackSelectCupCourse(void) {
    switch (AdvanceSelectCupCourse()) {
        case MENU_SCREEN_RESULT_NEXT:
            if (HasNoSelectableGhost()) {
                SwitchMenuScreen(SCREEN_NEXT_RACE_SETUP, 0x1f);
            } else {
                SwitchMenuScreen(SCREEN_SELECT_GHOST, 0x1f);
            }
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CUP_M_TIME_ATTACK, 0x1f);
            break;
    }
}

#pragma thumb off
void WriteMainBg1Offset(u32 offsetX, u32 offsetY) {
    reg_G2_BG1OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteMainBg1CntLowBits(u32 bits) {
    vu16 *bg1Cnt = &reg_G2_BG1CNT;
    *bg1Cnt = (*bg1Cnt & ~3) | bits;
}
#pragma thumb on
