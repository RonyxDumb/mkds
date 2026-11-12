#include "Main/MapObjects/model_animation_entries.h"
#include "Main/Graphics/model_animation.h"

#include "Main/System/heap_call.h"

#pragma thumb on

void InitModelAnimationWithEntries(u32 animationKind, void *model, void *animation, void *nsbmdFile,
                                   void *animationFile) {
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    InitModelAnimation(animationKind, animation, model, 1, heap, nsbmdFile);
    InitModelAnimationEntries(animation, animationFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(animation, 0);
}

#pragma thumb off
