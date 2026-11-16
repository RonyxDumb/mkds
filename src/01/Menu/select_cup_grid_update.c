#include "01/Menu/select_cup_grid_update.h"
#include "Main/Menu/menu_screen_switch.h"
#include "01/Menu/select_cup_grid_flags.h"
#include "model_material_set.h"
#include "sound_archive_load.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Menu/select_cup_grid.h"
#include "Main/Menu/menu_entry_kind.h"

#pragma optimize_for_size on

void UpdateSelectCupGrid(void) {
    switch (AdvanceSelectCupGrid()) {
        case MENU_SCREEN_RESULT_NEXT:
            SwitchMenuScreen(SCREEN_NEXT_RACE_SETUP, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_KART_GRAND_PRIX, SCREEN_NONE);
            break;
        case MENU_SCREEN_RESULT_LEAVE:
            SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_IN, SCREEN_NONE);
            SelectCupGridSetMenuEntryKind(MENU_ENTRY_SINGLE_PLAY_SELECT);
            SelectCupGridSetRaceSetupRequested(1);
            break;
    }
}
