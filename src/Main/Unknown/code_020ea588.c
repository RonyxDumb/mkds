#include "Main/Unknown/code_020ea588.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020e66e4.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020e6000.h"

void sub_20EA5B0(NsbmdModel *model, u32 maxAlpha, Vec3 *position) {
    Vec3 shiftedPosition;

    if (position != NULL) {
        shiftedPosition.x = position->x >> 4;
        shiftedPosition.y = position->y >> 4;
        shiftedPosition.z = position->z >> 4;
        bbm_render(model, &shiftedPosition, 1, maxAlpha);
    } else {
        bbm_render(model, NULL, 0, maxAlpha);
    }
}

#pragma thumb on

void model2_createFromNsbmd(void **slot, void *file, void *unused) {
    *slot = heap_alloc(proc_getHeap(proc_getCurrent()), 0x6c);
    model_initFromNsbmd(*slot, file);
}

#pragma thumb off
