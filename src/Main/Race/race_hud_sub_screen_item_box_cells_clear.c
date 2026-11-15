#include "Main/Race/race_hud_sub_screen_item_box_cells_clear.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"

void ClearRaceHudSubScreenItemBoxCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenItemBoxCells);
}
