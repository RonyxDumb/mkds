#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/heap.h"

#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0207a000.h"

#pragma thumb on

void CreateShadowModel(ShadowModel **slot, void *file, u32 polygonId) {
    *slot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x74);
    InitShadowModel(*slot, file, (u8) polygonId);
}

#pragma thumb off
