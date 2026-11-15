#pragma once

#include "types.h"

void LoadSndDataFromFileCallback(void);
s32 WLMenuToResultAdvanceMPStateMachineWrapper(void);
void UpdateMPLoadResultSound(void *stateObject);
void LoadResultSceneSoundSetCallback(void);
void EnterMPLoadResultSound(void *stateObject);
void UpdateMPWaitResultArchives(void *stateObject);
void EnterMPWaitResultArchives(void *stateObject);
void UpdateMPWaitMenuArchives(void *stateObject);
void EnterMPWaitMenuArchives(void *stateObject);
