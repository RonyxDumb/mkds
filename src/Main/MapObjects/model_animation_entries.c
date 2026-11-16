#include "Main/MapObjects/model_animation_entries.h"
#include "Main/Graphics/model_animation.h"

#include "Main/System/heap_call.h"
#include "Main/MapObjects/woodbox1_kind_data.h"
#include "Main/MapObjects/woodbox.h"

const Vec3 gJgMatrixRow1Source = {0, 0x1000, 0};
const MapObjectKindDescriptor gWoodbox1KindDescriptor = {0,
                                                         {0, 0},
                                                         0x148,
                                                         InitWoodbox1,
                                                         (MapObjectKindData * (*) (void) ) CreateWoodbox1KindData,
                                                         CreateWoodbox1DrawList,
                                                         NULL,
                                                         NULL,
                                                         CreateWoodbox1UpdateList,
                                                         NULL,
                                                         {NULL, NULL, NULL, NULL}};

#pragma thumb on

void SomeAnimationLoadWrapper_from_thumb(u32 animationKind, void *model, void *animation, void *nsbmdFile,
                                   void *animationFile) {
    void *heap;

    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    StructAM_CreateFrom(animationKind, animation, model, 1, heap, nsbmdFile);
    StructAM_MaybeLoadAnimation(animation, animationFile, ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
    StructAM_SomeFn_MaybeLoadFrame(animation, 0);
}

#pragma thumb off
