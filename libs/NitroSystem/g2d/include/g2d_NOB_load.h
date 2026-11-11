#pragma once

#include "types.h"
#include "g2d_NAN_load.h" // Unk02021dc8, NNSG2dCellVramTransferData
#include "code_02022030.h" // NNSG2dCellDataWithBR

void NNS_G2dUnpackNCE(Unk02021dc8 *bank);
NNSG2dCellDataWithBR *NNS_G2dGetCellDataByIdx(Unk02021dc8 *bank, u32 idx);
NNSG2dCellOAMAttrData *GetPtrOamArrayHead_(Unk02021dc8 *bank);
