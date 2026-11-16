#include "Main/Unknown/code_02036c4c.h"
#include "code_020176c0.h"

void *heap_create(void *start, u32 size) {
    return NNS_FndCreateExpHeapEx(start, size, 1);
}
