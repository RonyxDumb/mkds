#include "01/Menu/select_cup_grid_registers.h"
#include "01/Menu/select_visible_plane.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_cup_grid.h"
#include "gx.h"
#include "code_02148950.h"

void WriteSelectCupGridScreenRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        SelectGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        SelectGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectCupGridRegisters();
}
