#pragma once

#include "types.h"

void EnterMPSendParticipantMask(void *stateObject);
void UpdateMPChildDelay(void *stateObject);
void EnterMPChildDelay(void *stateObject);
void UpdateMPFillOwnRecord(void *stateObject);
void EnterMPFillOwnRecord(void *stateObject);
// Results of AdvanceMPStateMachineWithOwnIndex besides 0 (still running): 1 the state machine is finished or no
// connection is active, 2 a child that is not multiboot lost its own index, 3 a multiboot child lost it and the error
// code was set. AdvanceConnectionSetup, AdvanceBlockCountRequest and AdvanceBlockReceive also return 2 for the same
// loss.
#define MP_STATE_ADVANCE_FINISHED 1
#define MP_STATE_ADVANCE_OWN_INDEX_LOST 2
#define MP_STATE_ADVANCE_DISCONNECTED 3

s32 AdvanceMPStateMachineWithOwnIndex(void);
s32 AdvanceSyncedCallback(void (*callback)(void));
