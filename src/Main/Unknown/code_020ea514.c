#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_02087d0c.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"

#pragma thumb on

void anim_20EA514(u32 animationKind, void *model, void *animation, void *nsbmdFile,
                                   void *animationFile) {
    void *heap;

    heap = proc_getHeap(proc_getCurrent());
    anim_initManager(animationKind, animation, model, 1, heap, nsbmdFile);
    anim_registerAllAnims(animation, animationFile, proc_getHeap(proc_getCurrent()));
    anim_setAnim(animation, 0);
}

#pragma thumb off
