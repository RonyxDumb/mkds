#include "Main/Race/race_hud_sub_screen_shine16_cells_clear.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_hud_sub_screen_shine16_cells.h"

void ClearRaceHudSubScreenShine16Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenShine16Cells);
}
