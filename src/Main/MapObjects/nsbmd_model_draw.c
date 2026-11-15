#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/code_020e66e4.h"

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
    *slot = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(**slot));
    InitNsbmd(*slot, file);
}

#pragma thumb off
