#include "g2d_NOB_load.h"

Unk02021e40 *GetPtrOamArrayHead_(Unk02021dc8 *bank) {
    if (bank->field2 & 1) {
        return (Unk02021e40 *) (bank->field4 + bank->field0 * 16);
    }
    return (Unk02021e40 *) (bank->field4 + bank->field0 * 8);
}

Unk020224e0_c *NNS_G2dGetCellDataByIdx(Unk02021dc8 *bank, u32 idx) {
    if (idx >= bank->field0) {
        return 0;
    }
    if (bank->field2 & 1) {
        return (Unk020224e0_c *) (bank->field4 + idx * 16);
    }
    return (Unk020224e0_c *) (bank->field4 + idx * 8);
}

void NNS_G2dUnpackNCE(Unk02021dc8 *bank) {
    Unk02021e40 *oamHead;
    Unk02021e40 *entry;
    u16 i;

    bank->field4 += (u32) bank;
    oamHead = GetPtrOamArrayHead_(bank);
    for (i = 0; i < bank->field0; i++) {
        entry = (Unk02021e40 *) NNS_G2dGetCellDataByIdx(bank, i);
        entry->field4 += (u32) oamHead;
    }
    if (bank->fieldC != 0) {
        bank->fieldC = OFFSET_PTR(Unk02021e40, bank->fieldC, (u32) bank);
        entry = bank->fieldC;
        entry->field4 += (u32) entry;
        bank->fieldC = entry;
    }
}
