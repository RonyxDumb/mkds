#include "03/code_021d1d4c.h"
#include "03/code_021d27d8.h"

void DeletePointerStack(void *block, ...) {
    FreeExpHeapBlockAndClearPointer(&block);
}
