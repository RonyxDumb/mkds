#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/heap.h"

#include "Main/System/heap_call.h"
#include "Main/Kart/code_0207a000.h"

const u32 gWoodbox1HitFlag = 0x40000000;

#pragma thumb on

void CreateShadowModel(ShadowModel **slot, void *file, u32 polygonId) {
    *slot = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(**slot));
    InitShadowModel(*slot, file, (u8) polygonId);
}

#pragma thumb off
