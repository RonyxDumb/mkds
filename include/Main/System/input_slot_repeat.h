#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

void SetInputSlotRepeat(InputSlot *slot, unsigned int mask, unsigned int delayLimit, unsigned int intervalLimit);

void UpdateInputSlot(u32 keys, InputSlot *slot);

void ClearInputSlotBitsAndRepeat(InputSlot *slot);
void ResetInputSlot(InputSlot *slot);
