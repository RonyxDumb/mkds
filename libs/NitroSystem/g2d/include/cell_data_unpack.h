#pragma once

#include "types.h"
#include "animation_data_unpack.h" // NNSG2dCellDataBank, NNSG2dCellVramTransferData
#include "sprite_animation_control.h" // NNSG2dCellDataWithBR

void CellBank_InitializeLoad(NNSG2dCellDataBank *bank);
NNSG2dCellDataWithBR *CellBank_GetMetatileEntry(NNSG2dCellDataBank *bank, u32 idx);
NNSG2dCellOAMAttrData *CellBank_GetObjectTable(NNSG2dCellDataBank *bank);
