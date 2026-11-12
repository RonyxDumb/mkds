#include "Main/System/last_tick.h"
#include "Main/Unknown/unk_0217b000.h"
#include "os_tick.h"

#pragma thumb on

void SetLastTick(void) {
    u64 tick;
    tick = OS_GetTick();
    *(u64 *) &gLastTick = tick;
}

#pragma thumb off
