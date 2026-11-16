#include "Main/Unknown/code_020cefa0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020cef1c.h"
#include "00/code_02181f98.h"

#pragma thumb on

void struct217B488_init(void *heap) {
    u32 allocation;
    allocation = ((u32) heap_alloc(heap, (0x00000130u)));
    *(u32 *) &gStruct217B488 = allocation;
    struct217B488_reset();
}

#pragma thumb off
