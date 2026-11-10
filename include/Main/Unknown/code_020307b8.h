#pragma once

#include "types.h"

void InitMultiSelectNS(void *parentHeap, void *scene, void *oamList);
void MultiSelectNSMI_CpuClearFast(void *destination, u32 size);
void MultiSelectNSMI_CpuFillFast(void *destination, u32 value, u32 size);
void RefreshMultiSelectNS(s32 showSelected);
void SetMultiSelectNSCellTableOffsetY(void);
