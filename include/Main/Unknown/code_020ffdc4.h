#pragma once

#include "types.h"

void dram_update(u32 arg0, u32 dram); /* the whole per-object step; the group also has a pre-step, dram_globalPreUpdate */
