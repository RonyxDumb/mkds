#pragma once

#include "types.h"
#include "code_02013740.h"

typedef struct NNSG3dResMdlSet NNSG3dResMdlSet;

NNSG3dResMdlSet *NNS_G3dGetMdlSet(const NNSG3dResFileHeader *header);

extern u32 gSbcBillboardPackedOps[1];
extern u32 gSbcBillboardOpArgs[2];
extern u32 gSbcBillboardMatrix[9];
