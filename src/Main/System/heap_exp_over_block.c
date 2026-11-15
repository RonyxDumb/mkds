#include "Main/System/heap_exp_over_block.h"
#include "expanded_heap_head.h"

void *CreateExpHeapOverBlock(void *start, u32 size) {
    return NNS_FndCreateExpHeapEx(start, size, 1);
}
