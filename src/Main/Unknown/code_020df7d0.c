#include "Main/Unknown/code_020df7d0.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020df48c.h"
#include "Main/Unknown/code_0206bcb0.h"

#include "Main/Unknown/code_020df7d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020df85c.h"

void EnterMkdEfBubbleState1(MkdEfBubbleObject *bubble) {
    bubble->mMapObject.mFlags |= data_0215877c;
    bubble->mMapObject.mFlags |= data_02158780;
}

void UpdateMkdEfBubbleState1(MkdEfBubbleObject *bubble) {
    if (bubble->mMapObject.mStateMachine.mStateFrames >= bubble->mDelayFrameCount) {
        bubble->mMapObject.mStateMachine.mNextState = 0;
        bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u8 func_020df7d8(MkdEfBubbleObject *bubble, Kart *kart, void *unused, u8 *d) {
    u32 kartBit;

    kartBit = (1 << kart->mIndex) & 0xff;
    if ((bubble->mKartMask & kartBit) == 0) {
        if (StartSoundIfKartStarOrKiller(&bubble->mMapObject, kart) != 0) {
            bubble->mMapObject.mDistanceSquaredAndFlags |= data_02158778;
            bubble->mKartMask |= kartBit;
        }
    }
    return *d;
}

u32 func_020df7d0(u32 unused0, u32 unused1, u32 unused2, u32 bytePointer) {
    return (*OFFSET_PTR(const u8, bytePointer, 0));
}
