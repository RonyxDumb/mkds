#pragma once

#include "types.h"
#include "sound_archive_load.h"

void EraseSync(void);
BOOL NewSection(NNSSndHeap *heap);
BOOL InitHeap(NNSSndHeap *heap, void *handle);
