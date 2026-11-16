#include "Main/Unknown/code_020df7d0.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020df48c.h"

#include "Main/Unknown/code_020df7d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020df85c.h"

void efbub_waitStateInit(MapObjectFlagsView *bubble) {
    bubble->field2 |= data_0215877c;
    bubble->field2 |= data_02158780;
}

void efbub_waitStateUpdate(MkdEfBubbleObject *bubble) {
    if (bubble->field0.mStateMachine.mStateFrames >= bubble->fieldA0) {
        bubble->field0.mStateMachine.mNextState = 0;
        bubble->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u8 efbub_onDriverCollide(MkdEfBubbleObject *bubble, Unk020dea50_1 *kart, void *unused, u8 *d) {
    u32 kartBit;

    kartBit = (1 << kart->field74) & 0xff;
    if ((bubble->fieldE4 & kartBit) == 0) {
        if (mobj_tryDestroyByDriver(&bubble->field0, (Kart *) kart) != 0) {
            bubble->field0.mDistanceSquaredAndFlags |= data_02158778;
            bubble->fieldE4 |= kartBit;
        }
    }
    return *d;
}

u32 efbub_onItemCollide(u32 unused0, u32 unused1, u32 unused2, u32 bytePointer) {
    return (*OFFSET_PTR(const u8, bytePointer, 0));
}
