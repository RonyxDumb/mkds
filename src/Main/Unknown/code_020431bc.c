#include "Main/Unknown/code_020431bc.h"
#include "Main/System/Heap.h"

#pragma thumb on
CourseMap *mdat_allocMapDataStruct(void *heap) {
    return heap_alloc(heap, 0x110);
}
#pragma thumb off
