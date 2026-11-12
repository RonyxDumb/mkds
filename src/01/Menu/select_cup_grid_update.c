#include "01/Menu/select_cup_grid_update.h"
#include "Main/Menu/menu_screen_switch.h"
#include "01/Menu/select_cup_grid_flags.h"
#include "code_02012b30.h"
#include "code_0212d214.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Menu/select_cup_grid.h"

#pragma optimize_for_size on

void UpdateSelectCupGrid(void) {
    switch (AdvanceSelectCupGrid()) {
        case 1:
            SwitchMenuScreen(0x1d, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(6, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0, 0x1f);
            SelectCupGridSetMenuEntryKind(0);
            SelectCupGridSetRaceSetupRequested(1);
            break;
    }
}
