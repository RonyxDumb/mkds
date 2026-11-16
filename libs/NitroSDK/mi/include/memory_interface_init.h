#pragma once

#include "types.h"

// Called once from the start-up chain. Calls Mem_SetWramcnt(3) and Mem_DmaStop(0).
void Mem_Initialize(void);
