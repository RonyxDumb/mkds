#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/heap.h"

#include "Main/System/heap_call.h"
#include "Main/Kart/shadow_model_draw.h"

const u32 gWoodbox1HitFlag = 0x40000000;

#pragma thumb on

void CreateShadowModel(ShadowModel **slot, void *file, u32 polygonId) {
    *slot = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(**slot));
    StructAD00Sh_SomeFn_2(*slot, file, (u8) polygonId);
}

#pragma thumb off
