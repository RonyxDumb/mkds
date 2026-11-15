#pragma once

#include "types.h"
#include "code_02010c84.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/Graphics/g3d_anm_function_pointers.h"

void NNS_G3dGeUseFastDma(BOOL enabled);

extern BOOL NNS_G3dFlagUseFastDma;
extern struct GxCommandBuffer *NNS_G3dGeBuffer;
extern vu32 NNS_G3dFlagGXDmaAsync;

extern void (*NNS_G3dSendTexSRT_FuncArray[4])(NNSG3dMatAnmResult *);
extern void (*NNS_G3dSendJointSRT_FuncArray[3])(NNSG3dJntAnmResult *);
extern NNSG3dGetJointScale NNS_G3dGetJointScale_FuncArray[3];
