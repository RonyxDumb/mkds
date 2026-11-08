#include "code_02016468.h"

#include "code_02016574.h"
#include "code_020165d8.h"
#include "code_02016638.h"
#include "code_020165b8.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0201661c.h"

CallQueue data_02173220;

void CallQueueInit(void *arg0, u32 arg1) {
    data_02173220.mEntries = arg0;
    data_02173220.mCapacity = arg1;
    CallQueueReset(&data_02173220);
}

void CallQueueDrain(void) {
    CallQueue *p;
    CallQueueEntry *e;

    p = &data_02173220;
    e = CallQueueGetHeadEntry(p);
    while (CallQueueRemoveHead(p) != 0) {
        CallQueueRunEntry(e);
        p->mQueuedSize -= e->mSize;
        e = CallQueueGetHeadEntry(p);
    }
}

s32 CallQueueAppend(u32 a, u32 b, void *c, u32 d) {
    CallQueue *p;
    CallQueueEntry *e;

    p = &data_02173220;
    if (CallQueueIsFull(p) != 0) {
        return 0;
    }
    e = CallQueueGetTailEntry(p);
    e->mFuncIndex = a;
    e->mSource = c;
    e->mUnk_08 = b;
    e->mSize = d;
    CallQueueAddTail(p);
    p->mQueuedSize = p->mQueuedSize + e->mSize;
    return 1;
}
