#pragma once

#include "types.h"

void RegisterOptionHensyuMenuCallbacks(void);
void WriteOptionHensyuMenuRegisters(void);
void AdvanceOptionHensyuMenu(void);
void UpdateOptionHensyuMenuHighlight(void);
void AdvanceOptionHensyuMenuSlideOut(void);
void AdvanceOptionHensyuMenuHoldChosen(void);
void AdvanceOptionHensyuMenuSelect(void);
void AdvanceOptionHensyuMenuWaitSelectReturn(void);
void AdvanceOptionHensyuMenuSlideIn(void);
void AdvanceOptionHensyuMenuWaitFade(void);
void LocateAndQueueOptionHensyuMenu(void);
/* slot mRelease of OptionStateCallbacks; only clears the global, the state heap is destroyed by
   AdvanceOptionStates after it returns */
void ReleaseOptionHensyuMenu(void);
void InitOptionHensyuMenu(void *heap);

extern const u8 gOptionHensyuMenuSTableIndices[2];
extern const u8 gOptionHensyuMenuXluCellIndices[2];
extern const u8 gOptionHensyuMenuCellIndices[2];
extern const u8 gOptionHensyuMenuOffsetTableIndices[2][4];
extern const s32 gOptionHensyuMenuOffsetCellCounts[2];
