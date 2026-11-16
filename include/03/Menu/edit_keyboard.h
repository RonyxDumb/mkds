#pragma once

#include "types.h"
#include "03/System/tasks.h"

void MoveEditKeyboardCursor(int direction);
void PlaceEditKeyboardCursor(void);
void SetEditKeyboardKeyHighlight(int keyIndex, int highlight);
void ChangeEditKeyboardPage(int page);
void SetEditKeyboardRowY(u32 page, s32 row, u32 yPos);
void UpdateEditKeyboardPad(void);
void ChangeEditKeyboardHighlight(int keyIndex);

extern const u16 gEditKeyboardPage1KeyPosition[1][2];
extern const u16 gEditKeyboardLastExtraKeyPositions[2][2];
extern const u16 gEditKeyboardExtraKeyPositions[1][2];
