#pragma once

#include "types.h"

void EnterMPState5(void *stateObject);
void UpdateMPState22(void *stateObject);
void EnterMPState22(void *stateObject);
void UpdateMPState0(void *stateObject);
void EnterMPState0(void *stateObject);
s32 AdvanceMPStateMachineWithOwnIndex(void);
s32 AdvanceSyncedCallback(void (*callback)(void));
