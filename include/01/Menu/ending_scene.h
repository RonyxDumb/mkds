#pragma once

#include "types.h"

int GetEndingSceneNextScene(void);
s32 GetStaffRollEndedEarly(void);
void SetStaffRollEndedEarly(void);
void WriteEndingSceneRegisters(void);
void AdvanceEndingScene(void);
void AdvanceEndingSceneState7(void);
void AdvanceEndingSceneState6(void);
void AdvanceEndingSceneState5(void);
void AdvanceEndingSceneState4(void);
void AdvanceEndingSceneState3(void);
void AdvanceEndingSceneState2(void);
void AdvanceEndingSceneState1(void);
void AdvanceEndingSceneState0(void);
void LoadAndQueueEndingSceneData(void);
void QueueEndingSceneIndex1Data(void);
void QueueEndingSceneNcgrNscrNclr(int i);
void InitEndingSceneDisplay(void);
void ClearEndingScenePointer(void);
void CreateEndingScene(void *heap);

extern const u16 gEndingSceneStateTable[8];
