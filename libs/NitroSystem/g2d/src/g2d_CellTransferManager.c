#include "g2d_CellTransferManager.h"
#include "Main/Unknown/unk_02174000.h"

NNSG2dCellTransferState *NNSi_G2dGetCellTransferState(u32 handle) {
    return data_02174e04 + handle;
}

void NNS_G2dSetCellTransferStateRequested(u32 handle, u32 srcOffset, u32 szByte) {
    NNSG2dCellTransferState *state;

    state = NNSi_G2dGetCellTransferState(handle);
    state->mTransferRequested = ~0;
    state->mSrcOffset = srcOffset;
    state->mSzByte = szByte;
}
