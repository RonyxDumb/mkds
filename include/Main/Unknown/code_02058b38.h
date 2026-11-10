#pragma once

#include "types.h"

void EnterMPState5(void);
void UpdateMPState22(void);
void EnterMPState22(void);
void UpdateMPState0(void);
void EnterMPState0(void);
s32 AdvanceMPStateMachineWithOwnIndex(void);
s32 AdvanceSyncedCallback(void (*callback)(void));
