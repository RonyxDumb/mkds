#include "Main/Menu/battle_select_race_rule_registers.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/battle_gx_set_visible_plane.h"
#include "gx.h"
#include "code_02148950.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_race_rule.h"

#pragma thumb on

void WriteBattleSelectCharacterRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        BattleGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
        BattleGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(0);
    }
    BattleGXS_SetVisiblePlane(0x12);
    WriteSelectCharacterRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateBattleSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
        case 3:
            SwitchMenuScreen(0x10, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0xe, 0x1f);
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
        GXS_SetGraphicsMode(0);
    }
    WriteSelectRaceRuleRegisters();
}

#pragma thumb off
