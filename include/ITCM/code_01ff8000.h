#pragma once

#include "types.h"
#include "00/code_02188720.h"

typedef struct NNSG3dResShpData NNSG3dResShpData;
typedef struct Unk02170500_04 Unk02170500_04;
typedef struct Unk02170500 Unk02170500;
typedef struct NNSG3dAnmObj NNSG3dAnmObj;

// Command buffer: the number of words stored from mUnk_04, then the words.
typedef struct GxCommandBuffer {
    /* 00 */ u32 mWordCount;
    /* 04 */ u32 mWords[1];
} GxCommandBuffer;

void func_01ff8000(void);
void func_01ff8058(void);
void func_01ff81b4(Unk02170500 *s, u32 a);
void func_01ff8220(Unk02170500 *s, u32 a);
void func_01ff85d0(Unk02170500 *s, u32 a);
void func_01ff8648(Unk02170500 *s, u32 a, NNSG3dResShpData *c);
void func_01ff86b4(Unk02170500 *s, u32 a);
void func_01ff8738(Unk02170500 *s, u32 a, const u8 *e, u32 b);
void func_01ff8b08(Unk02170500 *s, u32 a);
void func_01ff8b98(Unk02170500 *s, u32 a);
void func_01ff8c98(Unk02170500 *s, u32 a);
void func_01ff8cc4(Unk02170500 *s, u32 a);
void DrawNsbmdRenderObj(void *object);
void func_01ff8dec(u32 *a, NNSG3dAnmObj *b);
void func_01ff8e64(Unk02170500 *s, Unk02170500_04 *i);
void func_01ff8ff8(Unk02170500 *s);
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
