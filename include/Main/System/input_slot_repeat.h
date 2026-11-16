#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;
typedef struct InputSlotHead InputSlotHead;

void SetInputSlotRepeat(InputSlot *slot, unsigned int mask, unsigned int delayLimit, unsigned int intervalLimit);

void UpdateInputSlot(u32 keys, InputSlotHead *slot);

void ClearInputSlotBitsAndRepeat(InputSlot *slot);
void ResetInputSlot(InputSlot *slot);
