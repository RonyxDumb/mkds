#include "Main/System/state_machine_init.h"

void InitStateMachine(StateMachine *stateMachine, const StateCallbacks *stateTable, s32 stateCount, void *object) {
    stateMachine->mObject = object;
    stateMachine->mStateTable = stateTable;
    stateMachine->mStateCount = stateCount;
    stateMachine->mStateFrames = 0x0u;
    stateMachine->mNextStateRequested = 0x1u;
    stateMachine->mState = 0x0u;
    stateMachine->mNextState = 0x0u;
}
