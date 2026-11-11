#pragma once

#include "types.h"

typedef struct OptionTopMenu OptionTopMenu;

extern u8 gOptionTopMenuXluCellIndices[];
extern s32 gOptionTopMenuOffsetCellCounts[];
extern const char gOptionBmgName[];
extern const char gOptionTopMenuCommonBmgName[];

void RegisterOptionTopMenuCallbacks(void);
void WriteOptionTopMenuRegisters(void);
void AdvanceOptionTopMenu(void);
void UpdateOptionTopMenuHighlight(void);
void AdvanceOptionTopMenuState9(void);
void AdvanceOptionTopMenuState8(void);
void AdvanceOptionTopMenuState7(void);
void AdvanceOptionTopMenuState6(void);
void AdvanceOptionTopMenuState5(void);
void AdvanceOptionTopMenuState4(void);
void AdvanceOptionTopMenuState3(void);
void AdvanceOptionTopMenuState2(void);
void AdvanceOptionTopMenuState1(void);
void AdvanceOptionTopMenuState0(void);
void LocateAndQueueOptionTopMenu(void);
/* slot mRelease of OptionStateCallbacks; only clears the global, the state heap is destroyed by
   AdvanceOptionStates after it returns */
void ReleaseOptionTopMenu(void);
void InitOptionTopMenu(void *heap);
