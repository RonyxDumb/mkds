#pragma once

#include "types.h"

void *WiFiSessionHeapAlloc(u32 unused, u32 size, s32 alignment);
void WiFiSessionHeapFree(u32 unused, void *memory);
