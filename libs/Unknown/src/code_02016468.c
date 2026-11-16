#include "code_02016468.h"

#include "code_02016574.h"
#include "code_020165d8.h"
#include "code_02016638.h"
#include "code_020165b8.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0201661c.h"

CallQueue g_GlobalTEQ;

void CallQueueInit(void *arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value12;
    value2 = (u32) &g_GlobalTEQ;
    *(u32 *) ((value2) + (0)) = value0;
    value0 = value2;
    g_GlobalTEQ.mCapacity = value1;
    CallQueueReset(value0);
}

void CallQueueDrain(void) {
    CallQueue *p;
    CallQueueEntry *e;

    p = &g_GlobalTEQ;
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

    p = &g_GlobalTEQ;
    if (CallQueueIsFull(p) != 0) {
        return 0;
    }
    e = CallQueueGetTailEntry(p);
    e->mFuncIndex = a;
    e->mSource = c;
    e->field8 = b;
    e->mSize = d;
    CallQueueAddTail(p);
    p->mQueuedSize = p->mQueuedSize + e->mSize;
    return 1;
}
