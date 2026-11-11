#include "g2d_NOB_load.h"

NNSG2dCellOAMAttrData *GetPtrOamArrayHead_(Unk02021dc8 *bank) {
    if (bank->mCellBankAttr & 1) {
        return OFFSET_PTR(NNSG2dCellOAMAttrData, bank->mPCellDataArrayHead, bank->mNumCells * 16);
    }
    return OFFSET_PTR(NNSG2dCellOAMAttrData, bank->mPCellDataArrayHead, bank->mNumCells * 8);
}

NNSG2dCellDataWithBR *NNS_G2dGetCellDataByIdx(Unk02021dc8 *bank, u32 idx) {
    if (idx >= bank->mNumCells) {
        return 0;
    }
    if (bank->mCellBankAttr & 1) {
        return (NNSG2dCellDataWithBR *) (bank->mPCellDataArrayHead + idx * 16);
    }
    return (NNSG2dCellDataWithBR *) (bank->mPCellDataArrayHead + idx * 8);
}

void NNS_G2dUnpackNCE(Unk02021dc8 *bank) {
    NNSG2dCellOAMAttrData *oamHead;
    NNSG2dCellDataWithBR *cell;
    NNSG2dVramTransferData *transfer;
    u16 i;

    bank->mPCellDataArrayHead += (u32) bank;
    oamHead = GetPtrOamArrayHead_(bank);
    for (i = 0; i < bank->mNumCells; i++) {
        cell = NNS_G2dGetCellDataByIdx(bank, i);
        cell->mPOamAttrArray = OFFSET_PTR(NNSG2dCellOAMAttrData, cell->mPOamAttrArray, (u32) oamHead);
    }
    if (bank->mPVramTransferData != 0) {
        bank->mPVramTransferData = OFFSET_PTR(NNSG2dVramTransferData, bank->mPVramTransferData, (u32) bank);
        transfer = bank->mPVramTransferData;
        transfer->mPCellTransferDataArray =
            OFFSET_PTR(NNSG2dCellVramTransferData, transfer->mPCellTransferDataArray, (u32) transfer);
        bank->mPVramTransferData = transfer;
    }
}
