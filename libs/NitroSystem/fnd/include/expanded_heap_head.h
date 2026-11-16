#pragma once

#include "types.h"
#include "heap_list_common_head.h" // NNSiFndHeapHead, NNSFndHeapHandle
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

u32 Mem_Exp_GetAllocatableSize(NNSFndHeapHandle heap, int alignment);
u32 Mem_GetExpHeapTotalFreeSize(NNSFndHeapHandle heap);
void Mem_Exp_Free(NNSFndHeapHandle heap, void *memBlock);
u32 Mem_ResizeExpHeap(NNSFndHeapHandle heap, void *memBlock, u32 size);
void *Mem_Exp_Allocate(NNSFndHeapHandle heap, u32 size, int alignment);
void Mem_Exp_Finalize(NNSFndHeapHandle heap);
NNSFndHeapHandle Mem_Exp_Create(void *startAddress, u32 size, u16 optFlag);
BOOL Mem_Exp_CoalesceFreedRegion(NNSiFndExpHeapHead *expHeap, const NNSiMemRegion *region);
void *Mem_Exp_AllocFromTail(NNSiFndHeapHead *heap, u32 size, int alignment);
void *Mem_Exp_AllocFromHead(NNSiFndHeapHead *heap, u32 size, int alignment);
void *Mem_Exp_ConvertFreeBlockToUsedBlock(NNSiFndExpHeapHead *expHeap, NNSiFndExpHeapMBlockHead *freeBlock, void *mblock,
                                  u32 size, u16 direction);
NNSiFndHeapHead *Mem_Exp_Initialize(void *startAddress, void *endAddress, u16 optFlag);
