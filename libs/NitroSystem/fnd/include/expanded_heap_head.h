#pragma once

#include "types.h"
#include "heapcommon.h" // NNSiFndHeapHead, NNSFndHeapHandle
#include "heap_block_head.h" // NNSiFndExpHeapMBlockHead, NNSiMemRegion
#include "heap_block_list.h" // NNSiFndExpMBlockList

// Follows the NNSiFndHeapHead of an Exp heap: its free and used blocks, the group ID given to new blocks, and the
// allocation mode in bit 0 of mFeature (0 takes the first free block that fits).
typedef struct NNSiFndExpHeapHead {
    /* 00 */ NNSiFndExpMBlockList mMbFreeList;
    /* 08 */ NNSiFndExpMBlockList mMbUsedList;
    /* 10 */ u16 mGroupID;
    /* 12 */ u16 mFeature;
} NNSiFndExpHeapHead;

// The Exp heap head sits right after the common head.
#define EXP_HEAP_HEAD(heap) ((NNSiFndExpHeapHead *) ((heap) + 1))

u32 NNS_FndGetAllocatableSizeForExpHeapEx(NNSFndHeapHandle heap, int alignment);
u32 NNS_FndGetTotalFreeSizeForExpHeap(NNSFndHeapHandle heap);
void NNS_FndFreeToExpHeap(NNSFndHeapHandle heap, void *memBlock);
u32 NNS_FndResizeForMBlockExpHeap(NNSFndHeapHandle heap, void *memBlock, u32 size);
void *NNS_FndAllocFromExpHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);
void NNS_FndDestroyExpHeap(NNSFndHeapHandle heap);
NNSFndHeapHandle NNS_FndCreateExpHeapEx(void *startAddress, u32 size, u16 optFlag);
BOOL RecycleRegion(NNSiFndExpHeapHead *expHeap, const NNSiMemRegion *region);
void *AllocFromTail(NNSiFndHeapHead *heap, u32 size, int alignment);
void *AllocFromHead(NNSiFndHeapHead *heap, u32 size, int alignment);
void *AllocUsedBlockFromFreeBlock(NNSiFndExpHeapHead *expHeap, NNSiFndExpHeapMBlockHead *freeBlock, void *mblock,
                                  u32 size, u16 direction);
NNSiFndHeapHead *InitExpHeap(void *startAddress, void *endAddress, u16 optFlag);
