#pragma once

#include "types.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"

typedef struct TaskEntry TaskEntry;

// MessageBox.mKind of the box that closes by itself, the frames it stays up, and the frames the close waits.
#define MESSAGE_BOX_KIND_TIMED 5
#define MESSAGE_BOX_TIMED_FRAMES 0x78
#define MESSAGE_BOX_CLOSE_WAIT_FRAMES 8

typedef struct OamRange OamRange;

// Window in/out bits by message box kind.
typedef struct MessageBoxWindowFlags {
    /* 0 */ u8 mFlagsByKind[6];
} MessageBoxWindowFlags;

void AdvanceMessageBoxRelease(TaskEntry *task, void *arg);
void AdvanceMessageBoxBrightnessUp(TaskEntry *taskEntry, void *arg);
void AdvanceMessageBoxSlideOut(TaskEntry *taskEntry, void *arg);
void AdvanceMessageBoxCloseWait(TaskEntry *taskEntry, void *arg);
void ShowMessageBoxButtonPressed(s32 buttonIndex);
void ClipOamRangeAboveY(OamRange *range, s32 minY);
void PlaceMessageBox(s32 yPos);
void AdvanceMessageBoxTimed(TaskEntry *task, void *arg);
void AdvanceMessageBoxInput(TaskEntry *task, void *arg);
void AdvanceMessageBoxSlideIn(TaskEntry *task, void *arg);
void AdvanceMessageBoxBrightnessDown(TaskEntry *taskEntry, void *arg);
BOOL IsMessageBoxOpen(void);
int GetMessageBoxResult(void);
// K&R on purpose: a caller passes a u8 array where the definition takes a u16 *.
void WriteWinRect();

extern const u8 gMessageBoxButtonCounts[6];
extern const u16 gMessageBoxWindowRect[4];
extern const u8 gMessageBoxButtonSlots[6][2];
extern const u8 gMessageBoxButtonImageIds[6][2];
extern const s8 gMessageBoxKeyResults[6][2];
extern const u16 gMessageBoxTextSizes[6][2];
extern const u16 gMessageBoxPositions[6][2];
extern const u16 gMessageBoxSizes[6][2];
extern const u16 gMessageBoxButtonPositions[5][2][2];

extern const u16 gMessageBoxTextOffset[2];
extern const u8 gMessageBoxImageIds[6];
extern const u16 gMessageBoxButtonSizes[5][2];
// Objects whose layout isn't known yet.
extern MessageBoxWindowFlags gMessageBoxWindowExtraBitFlags;
extern struct MessageBox *gMessageBox;
