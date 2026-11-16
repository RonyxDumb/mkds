#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// Uses the enclosing heap as an Exp heap (no tag check); if NNS_FndAdjustFrmHeap returns 0 because back allocations
// exist, the block is resized to 0.
void FrmHeapShrinkInParent(void *heap);
void *CreateFrmHeapFromBack(void *parent, u32 size);
void *CreateFrmHeapFromFront(void *parent, u32 size);
void *CreateFrmHeapFromMaxFree(void *parent);
void *CreateExpHeapFromMaxFree(void *parent);
void HeapDestroy(NNSiFndHeapHead *heap);
void HeapFree(void *heap, void *block);
// A negative alignment takes the block from the back end of the heap.
void *HeapAllocAligned(void *heap, u32 size, s32 alignment);
// Blocks that the cache invalidate or DMA touch start on a 32-byte line.
#define HEAP_ALIGN_CACHE_LINE 0x20
void *HeapAlloc(void *heap, u32 size);
