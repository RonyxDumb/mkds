#include "Main/System/heap_exp_over_block.h"
#include "expanded_heap_head.h"

void *Mem_CreateExpHeap(void *start, u32 size) {
    return Mem_Exp_Create(start, size, 1);
}
