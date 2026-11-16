#pragma once

#include "types.h"
#include "03/System/tasks.h"

void AdvanceEditKeyboardSlideInRow4(TaskEntry *task, void *arg);
void AdvanceEditKeyboardSlideInRow3(TaskEntry *task, void *arg);
void AdvanceEditKeyboardSlideInRow2(TaskEntry *task, void *arg);
void AdvanceEditKeyboardSlideInRow1(TaskEntry *task, void *arg);
void AdvanceEditKeyboardSlideInRow0(TaskEntry *task, void *arg);
BOOL HasEditKeyboard(void);
void SetEditKeyboardAddCharEnabled(u8 canAdd);
void SetEditKeyboardRemoveCharEnabled(u8 canRemove);
u8 GetEditKeyboardInput(void);
void StartEditKeyboardSlideOut(void);
void CreateEditKeyboard(void);

extern const u16 gEditKeyboardKeyPositionsThird[15][2];
extern const u16 gEditKeyboardCursorPositions[53][2];
extern const s8 gEditKeyboardCursorMoves[53][4];
