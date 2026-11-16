#include "Main/Unknown/code_0209f5cc.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"

void chdn_render(void *a, Unk0209f1c8 *b) {
    MtxFx43 *v1;
    u32 v2;
    v2 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v2, 1);
    v1 = bbm_getYBillboardAtPos(&b->mUnk_00.mPos);
    NNS_G3dGeBufferOP_N(0x19, v1, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &b->mUnk_00.mScale, 3);
    mobj_setModelNsbcaFrame(chnd_sModel, b->mUnk_a0);
    mobj_renderModel(a, chnd_sModel, b);
}
