#pragma once

#include "types.h"
#include "Main/Graphics/oam.h"

s32 MoveEmblemChoisesIndex(s32 step);
s32 MoveEmblemChoisesIndexByTouch(void);
void ResetEmblemChoisesState(void);
void WriteEmblemChoisesChoiceTiles(u16 *mapData, s32 column, s32 row);
void WriteEmblemChoisesTiles(void);
void WriteEmblemChoisesSelectedTiles(s32 choiceIndex);
