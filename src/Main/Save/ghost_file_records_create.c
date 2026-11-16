#include "Main/Save/ghost_file_records_create.h"
#include "Main/System/heap.h"

GhostListEntry *AllocateGhostHolder(void *heap) {
    return Mem_AllocateHeap(heap, 0x4600u);
}
