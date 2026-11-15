#include "Main/System/last_tick.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "tick_counter.h"

u64 gLastTick;

#pragma thumb on

void SetLastTick(void) {
    u64 tick;
    tick = OS_GetTick();
    gLastTick = tick;
}

#pragma thumb off
