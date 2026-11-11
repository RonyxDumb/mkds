#pragma once

#include "types.h"

void RequestOptionNextScene(u16 nextScene);
int GetOptionNextScene(void);
u32 GetOptionPrevState(void);
void RequestOptionState(u32 nextState);
void SetOptionStateCallbacks(UnkFunc **callbacks);
void WriteOptionStatesRegisters(void);
void AdvanceOptionStates(void);
void ReleaseOptionStates(void);
void InitOptionStates(void *heap, s16 a);
void SetupOptionBackgrounds(void);
void LoadOptionData(void);
void ClearOptionStateCallbacks(void);
