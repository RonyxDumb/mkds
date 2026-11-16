#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine

void StateDualHandler_Create(StateMachine *stateMachine, const StateCallbacks *stateTable, s32 stateCount, void *object);
