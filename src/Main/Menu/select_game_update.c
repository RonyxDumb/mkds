#include "Main/Menu/select_game_update.h"
#include "Main/Unknown/code_020cecdc.h"
#include "Main/Menu/select_game.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Menu/battle_gx_set_visible_plane.h"
#include "gx.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Unknown/code_02032000.h"

#pragma thumb on

void WriteSelectGameRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        BattleGX_SetVisiblePlane(0x18);
        GX_SetGraphicsMode(1, 0, 0);
        BattleGXS_SetVisiblePlane(0x12);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectGameMainRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateSelectGame(void) {
    switch (AdvanceSelectGame()) {
        case 1:
            switch (GetRaceSetupCopy()->mMode) {
                case 3:
                    SwitchMenuScreen(8, 0x1f);
                    break;
                case 2:
                    SwitchMenuScreen(0xf, 0x1f);
                    break;
            }
            break;
        case 2:
            SwitchMenuScreen(0, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0x1b, 0x1f);
            break;
    }
}
#pragma thumb off
