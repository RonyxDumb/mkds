#pragma once

#include "types.h"

void sm_init(void *rawStateMachine, UnkFunc *const *stateTable, s32 stateCount, void *object);
