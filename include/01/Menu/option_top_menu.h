#pragma once

#include "types.h"

typedef struct OptionTopMenu OptionTopMenu;
typedef struct OptionStateCallbacks OptionStateCallbacks;

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

extern const u8 gOptionTopMenuOffsetTableIndices[3][4];
extern const s32 gOptionTopMenuOffsetCellCounts[3];
extern OptionStateCallbacks gOptionTopMenuCallbacks;
extern const u8 gOptionTopMenuSTableIndices[3];
extern const u8 gOptionTopMenuXluCellIndices[3];
extern const u8 gOptionTopMenuCellIndices[3];
