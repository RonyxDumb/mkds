#include "03/System/free_exp_heap_block.h"
#include "03/System/exp_heap.h"

void FreeExpHeapBlockWrapper(void *block) {
    FreeExpHeapBlock(block);
}
