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

void func_01ff8000(void);
void func_01ff8058(void);
void func_01ff81b4(NNSG3dRS *s, u32 a);
void func_01ff8220(NNSG3dRS *s, u32 a);
void func_01ff85d0(NNSG3dRS *s, u32 a);
void func_01ff8648(NNSG3dRS *s, u32 a, NNSG3dResShpData *c);
void func_01ff86b4(NNSG3dRS *s, u32 a);
void func_01ff8738(NNSG3dRS *s, u32 a, const u8 *e, u32 b);
void func_01ff8b08(NNSG3dRS *s, u32 a);
void func_01ff8b98(NNSG3dRS *s, u32 a);
void func_01ff8c98(NNSG3dRS *s, u32 a);
void func_01ff8cc4(NNSG3dRS *s, u32 a);
void DrawNsbmdRenderObj(Nsbmd *object);
void func_01ff8dec(u32 *a, NNSG3dAnmObj *b);
void func_01ff8e64(NNSG3dRS *s, NNSG3dRenderObj *i);
void func_01ff8ff8(NNSG3dRS *s);
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
