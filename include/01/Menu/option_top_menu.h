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
