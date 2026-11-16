#include "Main/Save/ghost_file_records_create.h"
#include "Main/System/heap.h"

GhostListEntry *CreateGhostFileRecords(void *heap) {
    return HeapAlloc(heap, 0x4600u);
}
