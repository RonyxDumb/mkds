#include "Main/Menu/menu_shared_create.h"
#include "Main/System/heap.h"
#include "Main/Menu/menu_shared_clear.h"
#include "00/Menu/wi_fi_vs_setting.h"

#pragma thumb on

void InitializeGlobalB488_from_thumb(void *heap) {
    g_GlobalB488 = Mem_AllocateHeap(heap, (0x00000130u));
    CreateGlobalB488_from_thumb();
}

#pragma thumb off
