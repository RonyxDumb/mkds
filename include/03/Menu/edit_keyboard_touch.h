#pragma once

#include "types.h"

void AdvanceEditKeyboardTouchDown(void);
void ToggleEditKeyboardPage1(void);
void ToggleEditKeyboardPage2(void);
void AdvanceEditKeyboardTouchReleased(void);
void AdvanceEditKeyboardTouchPressed(void);
void AdvanceEditKeyboardInput(void);

extern const u16 gEditKeyboardExtraKeySizes[1][2];
extern const u16 gEditKeyboardPage1KeySize[1][2];
extern const u16 gEditKeyboardLastExtraKeySizes[2][2];
extern const u16 gEditKeyboardKeyPositions[16][2];
extern const u16 gEditKeyboardKeyPositionsSecond[16][2];
