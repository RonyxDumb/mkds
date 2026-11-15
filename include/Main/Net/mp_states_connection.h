#pragma once

#include "types.h"

void EnterMPSendParticipantMask(void *stateObject);
void UpdateMPChildDelay(void *stateObject);
void EnterMPChildDelay(void *stateObject);
void UpdateMPFillOwnRecord(void *stateObject);
void EnterMPFillOwnRecord(void *stateObject);
s32 AdvanceMPStateMachineWithOwnIndex(void);
s32 AdvanceSyncedCallback(void (*callback)(void));
