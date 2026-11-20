#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// Shrinks the frame heap to its allocated front and resizes its block in the enclosing heap to that size. The enclosing
// heap is used as an Exp heap (no tag check); if NNS_FndAdjustFrmHeap returns 0 because back allocations exist, the
// block is resized to 0.
void FrmHeapShrinkInParent(void *heap);
void *CreateFrmHeapFromBack(void *parent, u32 size);
void *CreateFrmHeapFromFront(void *parent, u32 size);
void *CreateFrmHeapFromMaxFree(void *parent);
void *CreateExpHeapFromMaxFree(void *parent);
void HeapDestroy(NNSiFndHeapHead *heap);
void HeapFree(void *heap, void *block);
// A negative alignment takes the block from the back end of the heap.
void *HeapAllocAligned(void *heap, u32 size, s32 alignment);
// A 32-byte alignment: the size of a data cache line.
#define HEAP_ALIGN_CACHE_LINE 0x20
void *HeapAlloc(void *heap, u32 size);
