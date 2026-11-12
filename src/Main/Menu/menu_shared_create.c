#include "Main/Menu/menu_shared_create.h"
#include "Main/System/heap.h"
#include "Main/Menu/menu_shared_clear.h"
#include "00/code_02181f98.h"

#pragma thumb on

void CreateMenuShared(void *heap) {
    u32 allocation;
    allocation = ((u32) HeapAlloc(heap, (0x00000130u)));
    *(u32 *) &gMenuShared = allocation;
    ClearMenuShared();
}

#pragma thumb off
