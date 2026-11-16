#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// Uses the enclosing heap as an Exp heap (no tag check); if NNS_FndAdjustFrmHeap returns 0 because back allocations
// exist, the block is resized to 0.
void heap_adjustSubFrmHeap(void *a);
void *heap_createSubFrmHeapWithSizeFromTail(void *a, u32 b);
void *heap_createSubFrmHeapWithSize(void *a, u32 b);
void *heap_createSubFrmHeap(void *a);
void *heap_createSubExpHeap(void *a);
void heap_destroySubHeap(NNSiFndHeapHead *a);
void heap_free(void *a, void *b);
// A negative alignment takes the block from the back end of the heap.
void *heap_allocEx(void *a, u32 b, s32 c);
void *heap_alloc(void *a, u32 b);
