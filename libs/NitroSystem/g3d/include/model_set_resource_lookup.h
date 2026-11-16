#pragma once

#include "types.h"
#include "animation_lookup.h"

typedef struct NNSG3dResMdlSet NNSG3dResMdlSet;

NNSG3dResMdlSet *Nsbmd_GetMDL0Block(const NNSG3dResFileHeader *header);

extern u32 gSbcBillboardPackedOps[1];
extern u32 gSbcBillboardOpArgs[2];
extern u32 gSbcBillboardMatrix[9];
