#include "Main/Menu/menu_shared_create.h"
#include "Main/System/heap.h"
#include "Main/Menu/menu_shared_clear.h"
#include "00/Menu/wi_fi_vs_setting.h"

#pragma thumb on

void CreateMenuShared(void *heap) {
    gMenuShared = HeapAlloc(heap, (0x00000130u));
    ClearMenuShared();
}

#pragma thumb off
