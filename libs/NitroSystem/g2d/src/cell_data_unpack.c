#include "cell_data_unpack.h"

NNSG2dCellOAMAttrData *CellBank_GetObjectTable(NNSG2dCellDataBank *bank) {
    if (bank->mCellBankAttr & 1) {
        return OFFSET_PTR(NNSG2dCellOAMAttrData, bank->mPCellDataArrayHead, bank->mNumCells * 16);
    }
    return OFFSET_PTR(NNSG2dCellOAMAttrData, bank->mPCellDataArrayHead, bank->mNumCells * 8);
}

NNSG2dCellDataWithBR *CellBank_GetMetatileEntry(NNSG2dCellDataBank *bank, u32 idx) {
    if (idx >= bank->mNumCells) {
        return 0;
    }
    if (bank->mCellBankAttr & 1) {
        return (NNSG2dCellDataWithBR *) (bank->mPCellDataArrayHead + idx * 16);
    }
    return (NNSG2dCellDataWithBR *) (bank->mPCellDataArrayHead + idx * 8);
}

void CellBank_InitializeLoad(NNSG2dCellDataBank *bank) {
    NNSG2dCellOAMAttrData *oamHead;
    NNSG2dCellDataWithBR *cell;
    NNSG2dVramTransferData *transfer;
    u16 cellIndex;

    bank->mPCellDataArrayHead += (u32) bank;
    oamHead = CellBank_GetObjectTable(bank);
    for (cellIndex = 0; cellIndex < bank->mNumCells; cellIndex++) {
        cell = CellBank_GetMetatileEntry(bank, cellIndex);
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
