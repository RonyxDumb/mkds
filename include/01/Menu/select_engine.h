#pragma once

#include "types.h"
#include "Main/Race/race.h" // Camera

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

extern const s16 gSelectEngineDownStepsFlagClear[4];
extern const s16 gSelectEngineRightStepsFlagSet[4];
extern const s16 gSelectEngineDownStepsFlagSet[4];
extern const s16 gSelectEngineLeftStepsFlagClear[4];
extern const u16 gSelectEngineFixedMTableIndices[6];
extern const s16 gSelectEngineRightStepsFlagClear[4];
extern const u16 gSelectEngineAOrBSTableIndices[4][3];
extern const u32 gSelectEngineEngineIndices[4];
extern const s16 gSelectEngineUpStepsFlagClear[4];
extern const s16 gSelectEngineLeftStepsFlagSet[4];
extern const u32 gSelectEngineIndicesByEngineIndex[3];
extern const s32 gSelectEngineRectIndices[4];
extern const s16 gSelectEngineUpStepsFlagSet[4];
extern const u16 gSelectEngineMTableIndices[4];

extern const char *gSelectEngineMBNclrName;
extern const char *gSelectEngineBSBnclName;
extern const char *gSelectEngineBSBnblName;
extern const char *gSelectEngineMNscrName;
extern const char *gSelectEngineSNcgrName;
extern const char *gSelectEngineMBNcgrName;
extern const char *gSelectEngineMBnclName;
extern const char *gSelectEngineMNcerName;
extern const char *gSelectEngineSNcerName;
extern const char *gSelectEngineMNcgrName;
extern const char *gSelectEngineMONclrName;
extern const char *gSelectEngineSONclrName;
extern const char *gSelectEngineASBnblName;
extern const char *gSelectEngineASBnclName;
