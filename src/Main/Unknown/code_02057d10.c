#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_020019b0.h"
#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_020364e0.h"
#include "os_irqHandler.h"
#include "os_thread.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

void bgwkr_threadMain(void *threadArgument) {
    for (;;) {
        if (gBgWkrState->mRunRequested != 0) {
            void (*queuedFunction)(void) = bgwkr_dequeueTask(gBgWkrState);
            if (queuedFunction == NULL) {
                gBgWkrState->mRunRequested = 0;
            } else {
                queuedFunction();
            }
        }
        OS_Sleep(2);
    }
}

u32 bgwkr_enqueueTask(void (*function)(void)) {
    s32 checkedCount;
    s32 searchIndex;
    ThreadFunctionQueue *queue = gBgWkrState;
    u8 slotIndex;
    void (*slotFunction)(void);
    if (queue->mRunRequested != 0) {
        return 0;
    }
    searchIndex = queue->mNewestIndex;
    checkedCount = 0;
    do {
        slotIndex = searchIndex % 10;
        slotFunction = queue->mFunctions[slotIndex];
        if (slotFunction == NULL) {
            break;
        }
        checkedCount++;
        searchIndex++;
    } while (checkedCount < 10);
    if (slotFunction != NULL) {
        return 0;
    }
    queue->mFunctions[slotIndex] = function;
    queue->mNewestIndex = slotIndex;
    return 1;
}

void bgwkr_waitForCompletion(void) {
    while (gBgWkrState->mRunRequested != 0) {
        OS_WaitIrq(1, 1);
    }
}

void logodef_create(void) {
    logo_create(proc_getHeap(proc_getCurrent()));
}

void logodef_finish(void) {
    logo_finish();
}

void logodef_vblank(void) {
    logo_vblank();
}

void logodef_render(void *sceneNumbers) {
    logo_render(sceneNumbers);
}

s32 logo_run(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = sLogoMenu;

    scene_runScene(sceneNumbers, &callbacks);
    return 0;
}
