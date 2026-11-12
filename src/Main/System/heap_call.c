#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/System/startup.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/heap.h"
#include "Main/Unknown/unk_02174000.h"

void InitHeapCall(HeapCall *call, u32 func) {
    call->mUnk_00 = 0;
    call->mFunc = func;
    call->mAfterFunc = 0;
    call->mParent = NULL;
    call->mHeap = NULL;
}

void SetHeapCallFunc(HeapCall *call, u32 func) {
    call->mFunc = func;
}

u32 RunHeapCall(HeapCall *call, u32 argument) {
    u32 result;
    void *outerHeap;
    call->mParent = gCurrentHeapCall;
    if (call->mParent != NULL) {
        outerHeap = call->mParent->mHeap;
    } else {
        outerHeap = GetArenaHeap();
    }
    call->mHeap = CreateExpHeapFromMaxFree(outerHeap);
    gCurrentHeapCall = call;
    result = ((u32(*)(u32)) call->mFunc)(argument);
    if (call->mAfterFunc != 0) {
        ((void (*)(void)) call->mAfterFunc)();
    }
    gCurrentHeapCall = call->mParent;
    HeapDestroy(call->mHeap);
    call->mHeap = NULL;
    return result;
}

void *GetCurrentHeapCall(void) {
    return gCurrentHeapCall;
}

void *GetHeap(HeapCall *call) {
    return call->mHeap;
}
