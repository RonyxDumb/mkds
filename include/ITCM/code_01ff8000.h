#pragma once

#include "types.h"
#include "00/code_02188720.h"

typedef struct NNSG3dResShpData NNSG3dResShpData;
typedef struct NNSG3dRenderObj NNSG3dRenderObj;
typedef struct NNSG3dRS NNSG3dRS;
typedef struct NNSG3dAnmObj NNSG3dAnmObj;
typedef struct Nsbmd Nsbmd;

// Command buffer: the number of words stored from mUnk_04, then the words.
typedef struct GxCommandBuffer {
    /* 00 */ u32 mWordCount;
    /* 04 */ u32 mWords[1];
} GxCommandBuffer;

void OS_IrqHandler(void);
void OS_IrqHandler_ThreadSwitch(void);
void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *renderState, u32 option);
void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *renderState, u32 option);
void NNSi_G3dFuncSbc_SHP(NNSG3dRS *renderState, u32 option);
void NNSi_G3dFuncSbc_SHP_InternalDefault(NNSG3dRS *renderState, u32 option, NNSG3dResShpData *shpData);
void NNSi_G3dFuncSbc_MAT(NNSG3dRS *renderState, u32 option);
void NNSi_G3dFuncSbc_MAT_InternalDefault(NNSG3dRS *renderState, u32 option, const u8 *matData, u32 materialIndex);
void NNSi_G3dFuncSbc_MTX(NNSG3dRS *renderState, u32 option);
void NNSi_G3dFuncSbc_NODE(NNSG3dRS *renderState, u32 option);
void NNSi_G3dFuncSbc_RET(NNSG3dRS *renderState, u32 option);
void NNSi_G3dFuncSbc_NOP(NNSG3dRS *renderState, u32 option);
void DrawNsbmdRenderObj(Nsbmd *object);
void SbcUpdateHintVec_(u32 *hintVector, NNSG3dAnmObj *animObj);
void G3dDrawInternal_(NNSG3dRS *renderState, NNSG3dRenderObj *renderObj);
void G3dDrawInternal_Loop_(NNSG3dRS *renderState);
void NNS_G3dGeBufferOP_N(u32 command, const void *parameters, u32 parameterCount);
void NNS_G3dGeSendDL(const void *commands, u32 commandLength);
void simpleUnlock_(u32 *a);
void NNS_G3dGeWaitSendDL(void);
void NNS_G3dGeFlushBuffer(void);
GxCommandBuffer *NNS_G3dGeReleaseBuffer(void);
void NNS_G3dGeSetBuffer(GxCommandBuffer *a);

// Calls MIi_CpuClear32 with 0, passed through a stack offset of its own.
static inline void func_01ff8cf0_inline(u32 *p) {
    volatile u32 v = 0;
    MIi_CpuClear32(v, p, 8);
}
