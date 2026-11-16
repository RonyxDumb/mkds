#include "Main/Race/race_goal_player_character.h"
#include "Main/Graphics/chars_block.h"
#include "Main/Race/race_ncer_tables.h"
#include "Main/Menu/message_screen.h"

void CopyPlayerCharacterToRaceGoalMO(void *palette, void *chars) {
    (GetSomeBgCanvasTileData_from_thumb());
    MaybeSomePlayerTilePaletteCopy(palette, 0xc, chars, 0x1b, 8);
}

void FillRaceSOPaletteAndChars(void *palette, void *chars) {
    DrawRacerNames();
    CopyRaceTransferSOAndMapSO(palette, chars);
}
