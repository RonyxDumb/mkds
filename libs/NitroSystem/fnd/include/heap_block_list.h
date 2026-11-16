#pragma once

#include "types.h"
#include "heap_block_head.h" // NNSiFndExpHeapMBlockHead, NNSiMemRegion

// First and last blocks of a chain linked through mMBHeadPrev and mMBHeadNext of NNSiFndExpHeapMBlockHead.
typedef struct NNSiFndExpMBlockList {
    /* 00 */ NNSiFndExpHeapMBlockHead *mHead;
    /* 04 */ NNSiFndExpHeapMBlockHead *mTail;
} NNSiFndExpMBlockList;

NNSiFndExpHeapMBlockHead *Mem_ExpHeapMemoryBlockList_Insert(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *target,
                                       NNSiFndExpHeapMBlockHead *prev);
NNSiFndExpHeapMBlockHead *Mem_ExpHeapMemoryBlockList_Remove(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block);
void Mem_GetMemoryBlockRegion(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block);
