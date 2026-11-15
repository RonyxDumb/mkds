#include "Main/Menu/battle_select_race_rule_registers.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/battle_gx_set_visible_plane.h"
#include "fixed_point_graphics_setup.h"
#include "vram_bank_assign.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_race_rule.h"

#pragma thumb on

void WriteBattleSelectCharacterRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        BattleGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
        BattleGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    BattleGXS_SetVisiblePlane(0x12);
    WriteSelectCharacterRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateBattleSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case MENU_SCREEN_RESULT_NEXT:
        case SELECT_CHARACTER_RESULT_TIME_UP:
            SwitchMenuScreen(SCREEN_SELECT_RACE_RULE_BATTLE, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_GAME, SCREEN_NONE);
            break;
    }
}
#pragma thumb off

#pragma thumb on

void WriteBattleSelectRaceRuleRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        BattleGXS_SetVisiblePlane(0x1f);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectRaceRuleRegisters();
}

#pragma thumb off
