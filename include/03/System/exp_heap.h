#pragma once

#include "types.h"
#include "Main/System/heap.h" // HEAP_ALIGN_CACHE_LINE

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// Bytes of the buffer passed to CreateExpHeapOverBuffer that are cleared and used as gExpHeap.
#define EXP_HEAP_BYTES 0x40000

void FreeExpHeapBlock(void *block);
void FreeExpHeapBlockAndClearPointer(void *storage);
void *AllocZeroedExpHeapBlock(u32 size, s32 alignment);
void *AllocExpHeapBlock(u32 size, s32 alignment);
void ReleaseExpHeap(void);
void CreateExpHeapOverBuffer(void *buffer);

extern NNSiFndHeapHead *gExpHeap;
