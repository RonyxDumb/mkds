#pragma once

#include "types.h"

void ChildWaitResultCallback(int eventCode);
void UpdateChildWaitRelease(void);
void UpdateChildWaitFadeOut(void);
void StartChildWaitClose(void);
void UpdateChildWaitResult(void);
void UpdateChildWaitNop(void);
void UpdateChildWaitInput(void);
void UpdateChildWait(void);
void UpdateChildWaitButtonsIn(void);
void UpdateChildWaitFadeIn(void);
void StartChildWaitFadeIn(void);
void LoadChildWaitFileAndSetBgCnt(void);
void SetupChildWait(void);

extern u8 gChildWaitYb5MultiNscName[19];
extern u8 gChildWaitResult;
