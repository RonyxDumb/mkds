#include "g2d_NAN_load.h"

void NNS_G2dUnpackNAN(AnimBank *bank) {
    int offset;
    u16 seq;
    u16 frame;
    NNSG2dAnimSequenceData *sequences;
    NNSG2dAnimFrameData *frames;
    s32 contents;

    bank->mPSequenceArrayHead = OFFSET_PTR(NNSG2dAnimSequenceData, bank->mPSequenceArrayHead, (u32) bank);
    bank->mPFrameArrayHead = OFFSET_PTR(NNSG2dAnimFrameData, bank->mPFrameArrayHead, (u32) bank);
    bank->mPAnimContents = OFFSET_PTR(NNSG2dAnimDataSRT, bank->mPAnimContents, (u32) bank);
    sequences = bank->mPSequenceArrayHead;
    contents = (u32) bank->mPAnimContents;
    frames = bank->mPFrameArrayHead;
    for (seq = 0; seq < bank->mNumSequences; seq++) {
        offset = (int) sequences[seq].mPAnmFrameArray;
        sequences[seq].mPAnmFrameArray = OFFSET_PTR(NNSG2dAnimFrameData, frames, offset);
        for (frame = 0; frame < sequences[seq].mNumFrames; frame++) {
            sequences[seq].mPAnmFrameArray[frame].mPContent =
                contents + sequences[seq].mPAnmFrameArray[(u32) frame].mPContent;
        }
    }
}

NNSG2dAnimSequenceData *NNS_G2dGetAnimSequenceByIdx(AnimBank *bank, u32 idx) {
    if (bank->mNumSequences > idx) {
        return bank->mPSequenceArrayHead + idx;
    }
    return 0;
}
