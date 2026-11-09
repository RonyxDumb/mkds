#include "g2d_NAN_load.h"

void NNS_G2dUnpackNAN(Unk02021db0 *bank) {
    int offset;
    u16 seq;
    u16 frame;
    Unk02021e1c *sequences;
    Unk02022188 *frames;
    s32 contents;

    bank->mUnk_04 = OFFSET_PTR(Unk02021e1c, bank->mUnk_04, (u32) bank);
    bank->mUnk_08 = OFFSET_PTR(Unk02022188, bank->mUnk_08, (u32) bank);
    bank->mUnk_0c = OFFSET_PTR(Unk020229c8, bank->mUnk_0c, (u32) bank);
    sequences = bank->mUnk_04;
    contents = (u32) bank->mUnk_0c;
    frames = bank->mUnk_08;
    for (seq = 0; seq < bank->mUnk_00; seq++) {
        offset = (int) sequences[seq].mUnk_0c;
        sequences[seq].mUnk_0c = OFFSET_PTR(Unk02022188, frames, offset);
        for (frame = 0; frame < sequences[seq].mUnk_00; frame++) {
            sequences[seq].mUnk_0c[frame].mUnk_00 = contents + sequences[seq].mUnk_0c[(u32) frame].mUnk_00;
        }
    }
}

Unk02021e1c *NNS_G2dGetAnimSequenceByIdx(Unk02021db0 *bank, u32 idx) {
    if (bank->mUnk_00 > idx) {
        return bank->mUnk_04 + idx;
    }
    return 0;
}
