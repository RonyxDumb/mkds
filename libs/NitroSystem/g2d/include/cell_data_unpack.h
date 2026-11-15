#pragma once

#include "types.h"
#include "animation_data_unpack.h" // NNSG2dCellDataBank, NNSG2dCellVramTransferData
#include "sprite_animation_control.h" // NNSG2dCellDataWithBR

void NNS_G2dUnpackNCE(NNSG2dCellDataBank *bank);
NNSG2dCellDataWithBR *NNS_G2dGetCellDataByIdx(NNSG2dCellDataBank *bank, u32 idx);
NNSG2dCellOAMAttrData *GetPtrOamArrayHead_(NNSG2dCellDataBank *bank);
