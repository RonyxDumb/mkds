#pragma once

#include "types.h"
#include "00/code_02188720.h"

typedef struct NNSG3dResShpData NNSG3dResShpData;
typedef struct Unk02170500_04 Unk02170500_04;
typedef struct Unk02170500 Unk02170500;
typedef struct NNSG3dAnmObj NNSG3dAnmObj;

// Command buffer: the number of words stored from field4, then the words.
typedef struct Unk01ff9048 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4[1];
} Unk01ff9048;

void OS_IrqHandler(void);
void OS_IrqHandler_ThreadSwitch(void);
void func_01ff81b4(Unk02170500 *s, u32 a);
void NNSi_G3dFuncSbc_NODEDESC(Unk02170500 *s, u32 a);
void NNSi_G3dFuncSbc_SHP(Unk02170500 *s, u32 a);
void NNSi_G3dFuncSbc_SHP_InternalDefault(Unk02170500 *s, u32 a, NNSG3dResShpData *c);
void NNSi_G3dFuncSbc_MAT(Unk02170500 *s, u32 a);
void NNSi_G3dFuncSbc_MAT_InternalDefault(Unk02170500 *s, u32 a, const u8 *e, u32 b);
void NNSi_G3dFuncSbc_MTX(Unk02170500 *s, u32 a);
void NNSi_G3dFuncSbc_NODE(Unk02170500 *s, u32 a);
void NNSi_G3dFuncSbc_RET(Unk02170500 *s, u32 a);
void NNSi_G3dFuncSbc_NOP(Unk02170500 *s, u32 a);
void NNS_G3dDraw(void *a);
void updateHintVec__0(u32 *a, NNSG3dAnmObj *b);
void G3dDrawInternal_(Unk02170500 *s, Unk02170500_04 *i);
void G3dDrawInternal_Loop_(Unk02170500 *s);
void NNS_G3dGeBufferOP_N(u32 a, const void *b, u32 n);
void NNS_G3dGeSendDL(const void *a, u32 b);
void func_01ff9210(u32 *a);
void NNS_G3dGeWaitSendDL(void);
void NNS_G3dGeFlushBuffer(void);
Unk01ff9048 *NNS_G3dGeReleaseBuffer(void);
void NNS_G3dGeSetBuffer(Unk01ff9048 *a);

// Calls MIi_CpuClear32 with 0, passed through a stack offset of its own.
static inline void func_01ff8cf0_inline(u32 *p) {
    volatile u32 v = 0;
    MIi_CpuClear32(v, p, 8);
}
