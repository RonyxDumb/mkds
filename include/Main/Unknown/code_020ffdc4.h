#pragma once

#include "types.h"
#include "Main/Unknown/code_020ffc4c.h"

void UpdateDram(u32 unused,
                Dram *dram); /* the whole per-object step; the group also has a pre-step, PickDramAngleChoices */
