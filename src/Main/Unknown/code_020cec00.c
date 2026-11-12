#include "Main/Unknown/code_020cec00.h"
#include "Main/Unknown/code_020cec50.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "gx.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_020cec24.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02119e14.h"

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
