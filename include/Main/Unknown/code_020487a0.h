#pragma once

#include "types.h"

void ResetArchiveBuffer(int bufferIndex);
void UncompressLZ8AndStoreRange(const void *source, void *destination, u32 size);
