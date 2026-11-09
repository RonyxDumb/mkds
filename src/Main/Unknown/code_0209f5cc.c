#include "Main/Unknown/code_0209f5cc.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"

void DrawChandelier(void *a, Unk0209f338 *b) {
    MtxFx43 *v1;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    v1 = SetViewRotatedMatrixPos(&b->mUnk_00.mPos);
    NNS_G3dGeBufferOP_N(0x19, v1, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &b->mUnk_00.mScale, 3);
    SetMapObjectModelNsbcaFrameIndex(gChandelier, b->mFrameIndex);
    DrawMapObjectModel(a, gChandelier, b);
}
