#pragma once

#include "types.h"
#include "ITCM/code_01ff8000.h"

void NNS_G3dGeUseFastDma(BOOL enabled);

extern BOOL NNS_G3dFlagUseFastDma;
extern struct GxCommandBuffer *NNS_G3dGeBuffer;
extern vu32 NNS_G3dFlagGXDmaAsync;
