#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// Uses the enclosing heap as an Exp heap (no tag check); if Mem_Frame_SomeFn4 returns 0 because back allocations
// exist, the block is resized to 0.
void FrmHeapShrinkInParent(void *heap);
void *Mem_CreateChildFrameHeapFromTail(void *parent, u32 size);
void *Mem_CreateChildFrameHeapFromHead(void *parent, u32 size);
void *Mem_CreateOrphanChildHeap(void *parent);
void *Mem_CreateChildExpHeap(void *parent);
void Mem_DestroyHeap(NNSiFndHeapHead *heap);
void Mem_FreeHeap(void *heap, void *block);
// A negative alignment takes the block from the back end of the heap.
void *Mem_AllocateHeapAligned(void *heap, u32 size, s32 alignment);
// Blocks that the cache invalidate or DMA touch start on a 32-byte line.
#define HEAP_ALIGN_CACHE_LINE 0x20
void *Mem_AllocateHeap(void *heap, u32 size);
