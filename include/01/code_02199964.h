#pragma once

#include "types.h"

void RegisterOptionHensyuMenuCallbacks(void);
void WriteOptionHensyuMenuRegisters(void);
void AdvanceOptionHensyuMenu(void);
void UpdateOptionHensyuMenuHighlight(void);
void AdvanceOptionHensyuMenuState5(void);
void AdvanceOptionHensyuMenuState4(void);
void AdvanceOptionHensyuMenuState3(void);
void AdvanceOptionHensyuMenuState2(void);
void AdvanceOptionHensyuMenuState1(void);
void AdvanceOptionHensyuMenuState0(void);
void LocateAndQueueOptionHensyuMenu(void);
/* slot mRelease of OptionStateCallbacks; only clears the global, the state heap is destroyed by
   AdvanceOptionStates after it returns */
void ReleaseOptionHensyuMenu(void);
void InitOptionHensyuMenu(void *heap);
