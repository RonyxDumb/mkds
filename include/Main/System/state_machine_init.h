#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine

void InitStateMachine(StateMachine *stateMachine, const StateCallbacks *stateTable, s32 stateCount, void *object);
