#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h"

typedef struct PushedObject PushedObject;

// Values of the PushedObject state machine, the slots of gPushedObjectStateTable: waiting in place, flying off with
// gravity and a spin after a hit, parked once it has fallen below its lowest height.
enum {
    PUSHED_OBJECT_STATE_IDLE,
    PUSHED_OBJECT_STATE_TUMBLE,
    PUSHED_OBJECT_STATE_PARK,
};

void InitPushedObjectStates(PushedObject *object);

extern StateCallbacks gPushedObjectStateTable[3];
