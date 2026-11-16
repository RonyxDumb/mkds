#pragma once

#include "types.h"
#include "Main/Unknown/code_020ade08.h"

s32 echoi_moveCursor(s32 step);
s32 echoi_handleTouch(void);
void echoi_resetSelectedOption(void);
void echoi_renderOptionBar(u16 *mapData, s32 column, s32 row);
void echoi_renderChoicesUnselected(void);
void echoi_renderSelection(s32 choiceIndex);
