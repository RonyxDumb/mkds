#pragma once

#include "types.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Kart/data_02161000.h"

void NNS_G3dGeUseFastDma(BOOL enabled);

extern BOOL NNS_G3dFlagUseFastDma;
extern struct GxCommandBuffer *NNS_G3dGeBuffer;
extern vu32 NNS_G3dFlagGXDmaAsync;

extern void (*NNS_G3dSendTexSRT_FuncArray[4])(NNSG3dMatAnmResult *);
extern void (*NNS_G3dSendJointSRT_FuncArray[3])(NNSG3dJntAnmResult *);
extern void (*NNS_G3dGetJointScale_FuncArray[3])(NNSG3dJntAnmResult *, void *, u8 *, u32);
