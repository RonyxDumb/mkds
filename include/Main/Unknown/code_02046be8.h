#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateMachine

void InitStateMachine(StateMachine *stateMachine, const StateCallbacks *stateTable, s32 stateCount, void *object);
