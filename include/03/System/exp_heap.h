#pragma once

#include "types.h"
#include "Main/System/heap.h" // HEAP_ALIGN_CACHE_LINE

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

void FreeExpHeapBlock(void *block);
void FreeExpHeapBlockAndClearPointer(void *storage);
void *AllocZeroedExpHeapBlock(u32 size, s32 alignment);
void *AllocExpHeapBlock(u32 size, s32 alignment);
void ReleaseExpHeap(void);
void CreateExpHeapOverBuffer(void *buffer);

extern NNSiFndHeapHead *gExpHeap;
