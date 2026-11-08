#include "Main/Unknown/code_0205dc54.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_0217a000.h"

void CreateCupRecords(void *heap) {
    gCupRecords = HeapAlloc(heap, sizeof(CupRecords));
}
