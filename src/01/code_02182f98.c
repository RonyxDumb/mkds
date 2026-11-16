#include "01/code_02182f98.h"
#include "01/code_02181bd0.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "code_02146cbc.h"

const u16 data_ov001_021a656c[4] = {0, 0xe38, 0x1c71};

void coin_globalInitShadow(void) {
    data_ov001_021a9b94 = 0;
}

void coin_globalPreRenderShadow(void) {
    s32 nextIndex = data_ov001_021a9b94 + 1;
    if (nextIndex >= 3) {
        nextIndex = 0;
    }
    data_ov001_021a9b94 = nextIndex;
}

void coin_renderShadow(void *f, Coin *coin, void *h, u32 l) {
    s32 a;
    s32 scaleFactor;
    Vec3 b;
    s32 m[9];
    Vec3 scale;
    Vec3 d;

    if (coin->mScaleFactor > 0 && coin->mModelAlpha != 0 && (coin->field0.mFlags & 1) == 0 &&
        (s32) (coin->field0.mDistanceSquaredAndFlags & 0x3fffffe0) < 0x3d090) {
        b.x = coin->field0.mPos.x;
        b.y = coin->field0.mPos.y - 0x16000;
        b.z = coin->field0.mPos.z;
        a = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &a, 1);
        NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&b), 0xc);
        scaleFactor = coin->mScaleFactor;
        if (scaleFactor < 0x1000) {
            scale.x = scaleFactor;
            scale.y = scaleFactor;
            scale.z = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
        }
        NNS_G3dGeBufferOP_N(0x1b, &coin->field0.mScale, 3);
        MTX_RotY33_(m, FX_SinCosTable_[(data_ov001_021a656c[data_ov001_021a9b94] >> 4) * 2 + 1],
                    FX_SinCosTable_[(data_ov001_021a656c[data_ov001_021a9b94] >> 4) * 2]);
        NNS_G3dGeBufferOP_N(0x1a, m, 9);
        d.x = 0x199a;
        d.y = 0x2000;
        d.z = 0x199a;
        NNS_G3dGeBufferOP_N(0x1b, &d, 3);
        oshd_renderJgShadow(8, l);
    }
}
