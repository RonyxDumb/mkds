#pragma once

#include "types.h"

unsigned int menu_sysdat_getOverlay(void);
void menu_MI_CpuClearFast(void *destination, u32 size);
void menu_MI_CpuFillFast(void *destination, u32 value, u32 size);
void menu_createRaceConfig(void *heap);
