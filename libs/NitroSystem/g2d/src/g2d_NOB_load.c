#include "g2d_NOB_load.h"

Unk020224e0_s *GetPtrOamArrayHead_(Unk02021dc8 *bank) {
    if (bank->mUnk_02 & 1) {
        return OFFSET_PTR(Unk020224e0_s, bank->mUnk_04, bank->mUnk_00 * 16);
    }
    return OFFSET_PTR(Unk020224e0_s, bank->mUnk_04, bank->mUnk_00 * 8);
}

Unk020224e0_c *NNS_G2dGetCellDataByIdx(Unk02021dc8 *bank, u32 idx) {
    if (idx >= bank->mUnk_00) {
        return 0;
    }
    if (bank->mUnk_02 & 1) {
        return (Unk020224e0_c *) (bank->mUnk_04 + idx * 16);
    }
    return (Unk020224e0_c *) (bank->mUnk_04 + idx * 8);
}

void NNS_G2dUnpackNCE(Unk02021dc8 *bank) {
    Unk020224e0_s *oamHead;
    Unk020224e0_c *cell;
    Unk02021dc8_0c *transfer;
    u16 i;

    bank->mUnk_04 += (u32) bank;
    oamHead = GetPtrOamArrayHead_(bank);
    for (i = 0; i < bank->mUnk_00; i++) {
        cell = NNS_G2dGetCellDataByIdx(bank, i);
        cell->mUnk_04 = OFFSET_PTR(Unk020224e0_s, cell->mUnk_04, (u32) oamHead);
    }
    if (bank->mUnk_0c != 0) {
        bank->mUnk_0c = OFFSET_PTR(Unk02021dc8_0c, bank->mUnk_0c, (u32) bank);
        transfer = bank->mUnk_0c;
        transfer->mUnk_04 = OFFSET_PTR(Unk02021e40, transfer->mUnk_04, (u32) transfer);
        bank->mUnk_0c = transfer;
    }
}
