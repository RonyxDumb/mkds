#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"

#include "Main/System/heap_call.h"

void DrawNsbmdModelWithMaxAlphaMapObjectPos(NsbmdModel *model, u32 maxAlpha, Vec3 *position) {
    Vec3 shiftedPosition;

    if (position != NULL) {
        shiftedPosition.x = position->x >> 4;
        shiftedPosition.y = position->y >> 4;
        shiftedPosition.z = position->z >> 4;
        DrawNsbmdModelWithMaxAlpha(model, &shiftedPosition, 1, maxAlpha);
    } else {
        DrawNsbmdModelWithMaxAlpha(model, NULL, 0, maxAlpha);
    }
}

#pragma thumb on

void CreateNsbmd(Nsbmd **slot, void *file, void *unused) {
    *slot = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(**slot));
    StructML_LoadModel2(*slot, file);
}

#pragma thumb off
