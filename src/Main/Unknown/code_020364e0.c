#include "Main/Unknown/code_020364e0.h"

#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/unk_02174000.h"

u32 proc_run(HeapCall *call, u32 argument) {
    u32 result;
    void *outerHeap;
    call->mParent = sCurProcess;
    if (call->mParent != NULL) {
        outerHeap = call->mParent->mHeap;
    } else {
        outerHeap = getMainHeapHandle();
    }
    call->mHeap = heap_createSubExpHeap(outerHeap);
    sCurProcess = call;
    result = ((u32(*)(u32)) call->mFunc)(argument);
    if (call->mAfterFunc != 0) {
        ((void (*)(void)) call->mAfterFunc)();
    }
    sCurProcess = call->mParent;
    heap_destroySubHeap(call->mHeap);
    call->mHeap = NULL;
    return result;
}

void *proc_getCurrent(void) {
    return sCurProcess;
}

void *proc_getHeap(HeapCall *call) {
    return call->mHeap;
}
