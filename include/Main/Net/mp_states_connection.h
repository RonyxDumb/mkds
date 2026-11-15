#pragma once

#include "types.h"

void EnterMPSendParticipantMask(void *stateObject);
void UpdateMPChildDelay(void *stateObject);
void EnterMPChildDelay(void *stateObject);
void UpdateMPFillOwnRecord(void *stateObject);
void EnterMPFillOwnRecord(void *stateObject);
// Results of AdvanceMPStateMachineWithOwnIndex besides 0 (still running): the state machine is ready or no connection is
// active, a child lost its own index, a multiboot child lost it and the error code was set.
#define MP_STATE_ADVANCE_READY 1
#define MP_STATE_ADVANCE_OWN_INDEX_LOST 2
#define MP_STATE_ADVANCE_DISCONNECTED 3

s32 AdvanceMPStateMachineWithOwnIndex(void);
s32 AdvanceSyncedCallback(void (*callback)(void));
