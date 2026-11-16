#include "g2d_NAN_load.h"

void NNS_G2dUnpackNAN(Unk02021dc8 *bank) {
    int offset;
    u16 seq;
    u16 frame;
    Unk02021e1c *sequences;
    u32 frames;
    s32 contents;

    bank->field4 += (u32) bank;
    bank->field8 += (u32) bank;
    bank->fieldC = OFFSET_PTR(Unk02021e40, bank->fieldC, (u32) bank);
    sequences = (Unk02021e1c *) bank->field4;
    contents = (u32) bank->fieldC;
    frames = bank->field8;
    for (seq = 0; seq < bank->field0; seq++) {
        offset = sequences[seq].fieldC;
        sequences[seq].fieldC = frames + offset;
        for (frame = 0; frame < sequences[seq].field0; frame++) {
            ((Unk02021e40 *) sequences[seq].fieldC)[frame].field0 =
                contents + ((Unk02021e40 *) sequences[seq].fieldC)[(u32) frame].field0;
        }
    }
}

void *NNS_G2dGetAnimSequenceByIdx(void *bank, u32 idx) {
    Unk02021dc8 *header = bank;

    if (header->field0 > idx) {
        return (Unk02021e1c *) header->field4 + idx;
    }
    return 0;
}
