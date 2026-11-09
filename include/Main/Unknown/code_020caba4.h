#pragma once

#include "types.h"
#include "Main/Unknown/code_020ade08.h"

s32 MoveEmblemChoisesIndex(s32 step);
s32 MoveEmblemChoisesIndexByTouch(void);
void ResetEmblemChoisesState(void);
void WriteEmblemChoisesChoiceTiles(u16 *mapData, s32 column, s32 row);
void WriteEmblemChoisesTiles(void);
void func_020caba4(s32 choiceIndex);
