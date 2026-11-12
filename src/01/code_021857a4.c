#include "01/code_021857a4.h"
#include "01/code_0218550c.h"
#include "01/code_02185ef4.h"
#include "01/code_0219e000.h"
#include "01/code_0219eab4.h"
#include "01/code_0219f8ec.h"
#include "01/code_ov001_02197b34.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Menu/select_character.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02028130.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020eb000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Menu/select_cup_grid.h"
#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/Unknown/code_0211e000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Race/ghost_record_set.h"
#include "gx.h"
#include "code_02148950.h"
#include "registers.h"

#pragma optimize_for_size on

u16 IsMissionGateFrameAdvanced(MissionGateObject *missionGateObject) {
    return missionGateObject->mNsbmaFrameIndex != 0;
}

void WriteMissionRunLVselScreenRegisters(void) {
    if (GetMenuScreenSwitched()) {
        MissionRunGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        MissionRunGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteMissionRunLVselBg0Offset();
}

void UpdateMissionRunLVsel(void) {
    switch (AdvanceMissionRunLVsel()) {
        case 1:
            SwitchMenuScreen(SCREEN_MISSION_RUN_MSSEL, 0x1f);
            break;
        case 2:
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
        GX_SetGraphicsMode(1, 0, 0);
        MissionRunGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteMissionRunMSselBgOffsets();
}

void UpdateMissionRunMSsel(void) {
    switch (AdvanceMissionRunMSsel()) {
        case 1:
            SwitchMenuScreen(0x1d, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(SCREEN_MISSION_RUN_LVSEL, 0x1f);
            break;
    }
}

void WriteTimeAttackTopMenuRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        TimeAttackGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
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
        case 1:
            SwitchMenuScreen(0x15, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0x1c, 0x1f);
            SetGhostSceneInitialCallbacksIndex(0);
            break;
        case 3:
            SwitchMenuScreen(0x1c, 0x1f);
            SetGhostSceneInitialCallbacksIndex(1);
            break;
        case 4:
            SwitchMenuScreen(0, 0x1f);
            break;
    }
}

void WriteTimeAttackCharacterRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
        TimeAttackGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(0);
    }
    TimeAttackGXS_SetVisiblePlane(0x12);
    WriteSelectCharacterRegisters();
}

void UpdateTimeAttackSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
            SwitchMenuScreen(0x16, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(SCREEN_TIME_ATTACK_TOP_MENU, 0x1f);
            break;
    }
}

void WriteTimeAttackKartRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
    }
    TimeAttackGXS_SetVisiblePlane(0x12);
    WriteSelectKartRegisters();
}

void UpdateTimeAttackSelectKart(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            SwitchMenuScreen(0x17, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0x15, 0x1f);
            break;
    }
}

void WriteTimeAttackCupGridRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        TimeAttackGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
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
        case 1:
            SwitchMenuScreen(0x18, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0x16, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0, 0x1f);
            TimeAttackSetMenuEntryKind(0);
            TimeAttackSetRaceSetupRequested(1);
            break;
    }
}

void WriteTimeAttackCupCourseRegisters(void) {
    if (GetMenuScreenSwitched()) {
        TimeAttackGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        TimeAttackGXS_SetVisiblePlane(0x1e);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectCupCourseBgOffsets();
}

void UpdateTimeAttackSelectCupCourse(void) {
    switch (AdvanceSelectCupCourse()) {
        case 1:
            if (HasNoSelectableGhost()) {
                SwitchMenuScreen(0x1d, 0x1f);
            } else {
                SwitchMenuScreen(SCREEN_SELECT_GHOST, 0x1f);
            }
            break;
        case 2:
            SwitchMenuScreen(0x18, 0x1f);
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
