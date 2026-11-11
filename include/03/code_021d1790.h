#pragma once

#include "types.h"

typedef struct OamRange OamRange;

void SetOamRangePriority(OamRange *range, s32 index, u32 priority);
void SetOamRangePosition(OamRange *range, s32 index, u32 xPos, u32 yPos);
void SetOamRangeMode(OamRange *range, s32 index, u32 mode, u32 colorParam);
void SetOamRangeEffect(OamRange *range, s32 index, u32 effect, u32 affineIndex);
