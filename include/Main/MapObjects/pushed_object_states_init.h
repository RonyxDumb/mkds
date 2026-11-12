#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h"

typedef struct PushedObject PushedObject;

void InitPushedObjectStates(PushedObject *object);

extern StateCallbacks gPushedObjectStateTable[3];
