#pragma once

#include "types.h"

void NNS_G2dSetCellTransferStateRequested(u32 handle, u32 srcOffset, u32 szByte);

typedef struct NNSG2dCellTransferState {
    /* 00 */ u32 mUnk_00[9];
    /* 24 */ u32 mTransferRequested;
    /* 28 */ u32 mSrcOffset;
    /* 2c */ u32 mSzByte;
} NNSG2dCellTransferState;

NNSG2dCellTransferState *NNSi_G2dGetCellTransferState(u32 handle);

extern NNSG2dCellTransferState *s_pCellStateArray;
