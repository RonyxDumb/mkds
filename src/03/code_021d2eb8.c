#include "03/code_021d2eb8.h"
#include "03/code_021d27d8.h"

void DeleteNodeList(void *block, ...) {
    FreeExpHeapBlockAndClearPointer(&block);
}
