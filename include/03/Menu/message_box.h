#pragma once

#include "types.h"

typedef struct TaskEntry TaskEntry;

typedef struct OamRange OamRange;

void AdvanceMessageBoxRelease(u32 task);
void AdvanceMessageBoxBrightnessUp(TaskEntry *taskEntry);
void AdvanceMessageBoxSlideOut(TaskEntry *taskEntry);
void AdvanceMessageBoxCloseWait(TaskEntry *taskEntry);
void ShowMessageBoxButtonPressed(s32 buttonIndex);
void ClipOamRangeAboveY(OamRange *range, s32 minY);
void PlaceMessageBox(s32 yPos);
void AdvanceMessageBoxTimed(u32 task);
void AdvanceMessageBoxInput(void);
void AdvanceMessageBoxSlideIn(u32 task);
void AdvanceMessageBoxBrightnessDown(TaskEntry *taskEntry);
BOOL IsMessageBoxOpen(void);
int GetMessageBoxResult(void);
// K&R on purpose: a caller passes a u8 array where the definition takes a u16 *.
void WriteWinRect();
