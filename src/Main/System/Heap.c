#include "Main/System/Heap.h"
#include "code_020176c0.h"
#include "frameheap.h"
#include "heapcommon.h"
#include "code_0200fc8c.h"

void *heap_alloc(void *a, u32 b) {
    NNSiFndHeapHead *h = a;
    void *c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return c;
}

void *heap_allocEx(void *a, u32 b, s32 c) {
    NNSiFndHeapHead *h = a;
    void *d = NULL;
    u32 e;
    switch (h->mSignature) {
        case 0x45585048:
            d = NNS_FndAllocFromExpHeapEx(a, b, c);
            break;
        case 0x46524d48:
            e = OS_DisableInterrupts();
            d = NNS_FndAllocFromFrmHeapEx(a, b, c);
            OS_RestoreInterrupts(e);
            break;
    }
    return d;
}

void heap_free(void *a, void *b) {
    NNSiFndHeapHead *h = a;
    switch (h->mSignature) {
        case 0x45585048:
            NNS_FndFreeToExpHeap(a, b);
            break;
        case 0x46524d48:
            break;
    }
}

void heap_destroySubHeap(NNSiFndHeapHead *a) {
    NNSiFndHeapHead *h = a;
    NNSiFndHeapHead *p;
    switch (h->mSignature) {
        case 0x45585048:
            NNS_FndDestroyExpHeap(a);
            break;
        case 0x46524d48:
            NNS_FndDestroyFrmHeap(a);
            break;
    }
    p = NNS_FndFindContainHeap(a);
    if (p == NULL) {
        return;
    }
    switch (p->mSignature) {
        case 0x45585048:
            NNS_FndFreeToExpHeap(p, a);
            break;
        case 0x46524d48:
            break;
    }
}

void *heap_createSubExpHeap(void *a) {
    NNSiFndHeapHead *h = a;
    u32 b = 0;
    void *c;
    switch (h->mSignature) {
        case 0x45585048:
            b = NNS_FndGetAllocatableSizeForExpHeapEx(a, 4);
            break;
        case 0x46524d48:
            b = NNS_FndGetAllocatableSizeForFrmHeapEx(a, 4);
            break;
    }
    c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return NNS_FndCreateExpHeapEx(c, b, 1);
}

void *heap_createSubFrmHeap(void *a) {
    NNSiFndHeapHead *h = a;
    u32 b = 0;
    void *c;
    switch (h->mSignature) {
        case 0x45585048:
            b = NNS_FndGetAllocatableSizeForExpHeapEx(a, 4);
            break;
        case 0x46524d48:
            b = NNS_FndGetAllocatableSizeForFrmHeapEx(a, 4);
            break;
    }
    c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return NNS_FndCreateFrmHeapEx(c, b, 1);
}

void *heap_createSubFrmHeapWithSize(void *a, u32 b) {
    NNSiFndHeapHead *h = a;
    void *c = NULL;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, 4);
            break;
        case 0x46524d48:
            c = NNS_FndAllocFromFrmHeapEx(a, b, 4);
            break;
    }
    return NNS_FndCreateFrmHeapEx(c, b, 1);
}

void *heap_createSubFrmHeapWithSizeFromTail(void *a, u32 b) {
    NNSiFndHeapHead *h = a;
    void *c = NULL;
    u32 d;
    switch (h->mSignature) {
        case 0x45585048:
            c = NNS_FndAllocFromExpHeapEx(a, b, -4);
            break;
        case 0x46524d48:
            d = OS_DisableInterrupts();
            c = NNS_FndAllocFromFrmHeapEx(a, b, -4);
            OS_RestoreInterrupts(d);
            break;
    }
    return NNS_FndCreateFrmHeapEx(c, b, 1);
}

void heap_adjustSubFrmHeap(void *a) {
    u32 b = NNS_FndAdjustFrmHeap(a);
    NNS_FndResizeForMBlockExpHeap(NNS_FndFindContainHeap(a), a, b);
}
