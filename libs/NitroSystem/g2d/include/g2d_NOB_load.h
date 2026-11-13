#pragma once

#include "types.h"
#include "g2d_NAN_load.h" // NNSG2dCellDataBank, NNSG2dCellVramTransferData
#include "g2d_Animation.h" // NNSG2dCellDataWithBR

void NNS_G2dUnpackNCE(NNSG2dCellDataBank *bank);
NNSG2dCellDataWithBR *NNS_G2dGetCellDataByIdx(NNSG2dCellDataBank *bank, u32 idx);
NNSG2dCellOAMAttrData *GetPtrOamArrayHead_(NNSG2dCellDataBank *bank);
