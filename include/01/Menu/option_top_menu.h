#pragma once

#include "types.h"

typedef struct OptionTopMenu OptionTopMenu;
typedef struct OptionStateCallbacks OptionStateCallbacks;

void RegisterOptionTopMenuCallbacks(void);
void WriteOptionTopMenuRegisters(void);
void AdvanceOptionTopMenu(void);
void UpdateOptionTopMenuHighlight(void);
void AdvanceOptionTopMenuResetDone(void);
void AdvanceOptionTopMenuWaitResetWrite(void);
void AdvanceOptionTopMenuAskResetAgain(void);
void AdvanceOptionTopMenuAskReset(void);
void AdvanceOptionTopMenuSlideOut(void);
void AdvanceOptionTopMenuPress(void);
void AdvanceOptionTopMenuInput(void);
void AdvanceOptionTopMenuWaitSelectReturn(void);
void AdvanceOptionTopMenuSlideIn(void);
void AdvanceOptionTopMenuWaitFade(void);
void LocateAndQueueOptionTopMenu(void);
/* slot mRelease of OptionStateCallbacks; only clears the global, the state heap is destroyed by
   AdvanceOptionStates after it returns */
void ReleaseOptionTopMenu(void);
void InitOptionTopMenu(void *heap);

extern const u8 gOptionTopMenuOffsetTableIndices[3][4];
extern const s32 gOptionTopMenuOffsetCellCounts[3];
extern OptionStateCallbacks gOptionTopMenuCallbacks;
extern const u8 gOptionTopMenuSTableIndices[3];
extern const u8 gOptionTopMenuXluCellIndices[3];
extern const u8 gOptionTopMenuCellIndices[3];

// Frames of the slide in and the slide out of the option top menu cells, and the distance they travel (mOffsetX);
// mBg0Offset slides by OPTION_TOP_BG0_SLIDE_DISTANCE alongside when the screen comes from or goes to the settings menu.
#define OPTION_TOP_SLIDE_FRAMES 10
#define OPTION_TOP_SLIDE_DISTANCE 250
#define OPTION_TOP_BG0_SLIDE_DISTANCE 50

// Frames the pressed row is shown before the slide out; the highlight comes back at the fifth.
#define OPTION_TOP_PRESS_FRAMES 10
#define OPTION_TOP_HIGHLIGHT_FRAME 5
