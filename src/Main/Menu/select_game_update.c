#include "Main/Menu/select_game_update.h"
#include "Main/Menu/select_game.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Race/race_setup_block.h"
#include "Main/Menu/battle_gx_set_visible_plane.h"
#include "gx.h"
#include "vram_bank_assign.h"
#include "Main/Race/race_setup.h"

#pragma thumb on

void WriteSelectGameRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        BattleGX_SetVisiblePlane(0x18);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        BattleGXS_SetVisiblePlane(0x12);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectGameMainRegisters();
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void UpdateSelectGame(void) {
    switch (AdvanceSelectGame()) {
        case MENU_SCREEN_RESULT_NEXT:
            switch (GetRaceSetupCopy()->mMode) {
                case MODE_VS:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_VS, SCREEN_NONE);
                    break;
                case MODE_BATTLE:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_BATTLE, SCREEN_NONE);
                    break;
            }
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_IN, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_LEAVE:
            SwitchMenuScreen(0x1b, SCREEN_NONE);
            break;
    }
}
#pragma thumb off
