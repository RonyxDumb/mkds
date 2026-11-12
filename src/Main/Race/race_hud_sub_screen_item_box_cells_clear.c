#include "Main/Race/race_hud_sub_screen_item_box_cells_clear.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/MapObjects/data_0217b000.h"

void ClearRaceHudSubScreenItemBoxCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenItemBoxCells);
}
