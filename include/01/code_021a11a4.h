#pragma once

#include "types.h"
#include "Main/Unknown/code_02061654.h" // Camera

void WriteSelectEngineBg0Offset(void);
int AdvanceSelectEngine(void);
void AdvanceSelectEngineState6(void);
void AdvanceSelectEngineState5(void);
void AdvanceSelectEngineState4(void);
void AdvanceSelectEngineState3(void);
void AdvanceSelectEngineState2(void);
void AdvanceSelectEngineState1(void);
void AdvanceSelectEngineState0(void);
void ReleaseSelectEngine(void);
void InitSelectEngine(void *parentHeap, void *mainOamList, void *subOamList);
void RequestSelectEngineState6(void);
void RequestSelectEngineState5(void);
void RequestSelectEngineState4(void);
void RequestSelectEngineState3(void);
void RequestSelectEngineState2(void);
void RequestSelectEngineState1(void);
void ResetSelectEngineOffsets(void);
void AdvanceSelectEngineIndexChange(void);
u32 IsSelectEngineIndexChangeRunning(void);
void SetEngineFromSelectEngine(void);
void RefreshSelectEngineMCells(void);
void UpdateSelectEngineIndexCells(void);
void InitSelectEngineCells(void);
void LocateAndQueueSelectEngine(void);
void LoadSelectEngineData(void);
