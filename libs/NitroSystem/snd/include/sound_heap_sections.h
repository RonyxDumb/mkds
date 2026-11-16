#pragma once

#include "types.h"
#include "sound_archive_load.h"

void EraseSync(void);
BOOL Sound_Context_MaybeReset(NNSSndHeap *heap);
BOOL Sound_Context_SetHeap(NNSSndHeap *heap, void *handle);
