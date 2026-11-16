#include "01/Menu/select_cup_grid_registers.h"
#include "01/Menu/select_visible_plane.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_cup_grid.h"
#include "fixed_point_graphics_setup.h"
#include "vram_bank_display_setup.h"

void WriteSelectCupGridScreenRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        SelectGX_SetVisiblePlane(0x19);
        ConfigureDispcntDisplay(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        SelectGXS_SetVisiblePlane(0x16);
        SetDispcntSubBgMode(GX_BGMODE_0);
    }
    WriteSelectCupGridRegisters();
}
