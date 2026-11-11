#include "code_0212c7a0.h"
#include "Main/Unknown/unk_0217d000.h"

// Sets NNSSndPlayer.mVolume.
void NNS_SndPlayerSetPlayerVolume(u32 index, u32 volume) {
    sPlayer[index].mVolume = volume;
}

// Sets NNSSndPlayer.mPlayableSeqCount.
void NNS_SndPlayerSetPlayableSeqCount(u32 index, u32 seqCount) {
    sPlayer[index].mPlayableSeqCount = (u16) seqCount;
}

// Sets NNSSndPlayer.mAllocChBitFlag.
void NNS_SndPlayerSetAllocatableChannel(u32 index, u32 channels) {
    sPlayer[index].mAllocChBitFlag = channels;
}
