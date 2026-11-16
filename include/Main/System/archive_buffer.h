#pragma once

#include "types.h"

void InitializeMountDatas_from_thumb(int bufferIndex);
void DecompressLzssAndDCClean_from_thumb(const void *source, void *destination, u32 size);
