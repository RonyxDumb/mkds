#pragma once

#include "types.h"
#include "03/System/tasks.h"

void ReleaseEditKeyboard(u32 task);
void AdvanceEditKeyboardSlideOutRow0(TaskEntry *task);
void AdvanceEditKeyboardSlideOutRow1(TaskEntry *task);
void AdvanceEditKeyboardSlideOutRow2(TaskEntry *task);
void AdvanceEditKeyboardSlideOutRow3(TaskEntry *task);
void AdvanceEditKeyboardSlideOutRow4(TaskEntry *task);

extern const u8 gEditKeyboardKeyPalettes[2];
extern const u8 gEditKeyboardRow4HighlightValues[2];
extern const u8 gEditKeyboardRow4KeyImages[2];
extern const u8 gEditKeyboardRow4Inputs[2];
extern const u8 gEditKeyboardExtraKeyImages[4];
extern const u16 gEditKeyboardRowTextAreaSize[2];
extern const u16 gEditKeyboardRow4KeySize[1][2];
extern const u16 gEditKeyboardKeySize[1][2];
extern const u8 gEditKeyboardExtraKeyInputs[5];
extern const u16 gEditKeyboardRow4KeyPositions[2][2];
