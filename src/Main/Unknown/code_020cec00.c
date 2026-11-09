#include "Main/Unknown/code_020cec00.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "Main/Unknown/code_02119e14.h"
#include "gx.h"

#pragma thumb on

void WriteBattleSelectRaceRuleRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        GxsDispCntBits8To12Write2(0x1f);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectRaceRuleRegisters();
}

#pragma thumb off
