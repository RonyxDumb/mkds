#pragma once

#include "types.h"

int GetEndingSceneNextScene(void);
s32 GetStaffRollEndedEarly(void);
void SetStaffRollEndedEarly(void);
void WriteEndingSceneRegisters(void);
void AdvanceEndingScene(void);
void AdvanceEndingSceneHoldThenLeave(void);
void AdvanceEndingSceneFadeOutToLeave(void);
void AdvanceEndingSceneWaitInput(void);
void AdvanceEndingSceneFadeIn(void);
void AdvanceEndingSceneHoldFaded(void);
void AdvanceEndingSceneFadeOut(void);
void AdvanceEndingSceneShowLogo(void);
void AdvanceEndingSceneWaitFirstFadeIn(void);
void LoadAndQueueEndingSceneData(void);
void QueueEndingSceneIndex1Data(void);
void QueueEndingSceneNcgrNscrNclr(int i);
void InitEndingSceneDisplay(void);
void ClearEndingScenePointer(void);
void CreateEndingScene(void *heap);

extern const u16 gEndingSceneStateTable[8];
