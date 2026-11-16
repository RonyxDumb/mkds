#include "Main/Unknown/code_0209f13c.h"
#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209f5cc.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146cbc.h"

void chnd_globalInitLogic(Unk0209f514 *a) {
    s32 i;
    Unk0209f1c8 *o;
    RandomState64 *r;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != NULL; i++) {
        r = &gRaceStatus->mLocalRandom;
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        o->mUnk_a4 = (u16) (((u64) (u32) (r->mValue >> 32) * 0x3c) >> 32) + 0x3c;
    }
}

void chnd_update(void *a, Unk0209f1c8 *b) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    Unk0210b7a8 s3;
    s32 t;
    s32 n;

    switch (b->mUnk_a8) {
        case 0:
            if (b->mUnk_a4-- <= 0) {
                b->mUnk_a8 = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (b->mUnk_a0 == 0 || b->mUnk_a0 == 0x7d) {
        if ((b->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
            if (b->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
                t = 2;
            } else if (b->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
                t = 3;
            } else {
                t = 4;
            }
            s1.mSoundId = 0x11a;
            s1.mPositionSource = &b->mUnk_00.mPos;
            s1.mUnk_08 = t;
            s1.mDistanceSquared = mobj_calcXZCamDist(&b->mUnk_00.mPos);
            func_0210b7a8(&s1);
        }
    } else if (b->mUnk_a0 == 0x46 || b->mUnk_a0 == 0xaf) {
        if ((b->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
            if (b->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
                t = 2;
            } else if (b->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
                t = 3;
            } else {
                t = 4;
            }
            s2.mSoundId = 0x11b;
            s2.mPositionSource = &b->mUnk_00.mPos;
            s2.mUnk_08 = t;
            s2.mDistanceSquared = mobj_calcXZCamDist(&b->mUnk_00.mPos);
            func_0210b7a8(&s2);
        }
    } else if (b->mUnk_a0 == 0xfa) {
        if ((b->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
            if (b->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
                t = 2;
            } else if (b->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
                t = 3;
            } else {
                t = 4;
            }
            s3.mSoundId = 0x119;
            s3.mPositionSource = &b->mUnk_00.mPos;
            s3.mUnk_08 = t;
            s3.mDistanceSquared = mobj_calcXZCamDist(&b->mUnk_00.mPos);
            func_0210b7a8(&s3);
        }
    }
    n = b->mUnk_a0 + 1;
    if (n >= mobj_getModelNsbcaFrameCount(chnd_sModel)) {
        n = 0;
    }
    b->mUnk_a0 = n;
    if (b->mUnk_a0 == 0) {
        b->mUnk_a8 = 0;
    }
}

void *chnd_setupRenderPart(void) {
    return mobj_createRenderPart3d(chnd_loadModel, chdn_render, NULL);
}

void *chnd_setupLogicPart(void) {
    return mobj_createLogicPart(chnd_globalInitLogic, chnd_update, NULL);
}

void rstar_loadModel(void *a) {
    mobj_loadNsbtaAnim(rstar_sModel = mobj_loadModel(a, aRainstar_nsbmd),
                                       aRainstar_nsbta);
    mobj_setModelPolygonIdAll(rstar_sModel, 0x3f);
}

void rstar_render(void *a, Unk0209f1c8 *b) {
    u32 l;
    s32 m[9];
    s32 i;

    l = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &l, 1);
    b->mUnk_00.mMatrix.mUnk_00[3].x = b->mUnk_00.mPos.x >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].y = b->mUnk_00.mPos.y >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].z = b->mUnk_00.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &b->mUnk_00.mMatrix, 0xc);
    if (b->mUnk_00.mAngle != 0) {
        i = b->mUnk_00.mAngle >> 4;
        MTX_RotY33_(m, FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, m, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &b->mUnk_00.mScale, 3);
    mobj_setModelNsbtaFrame(rstar_sModel, b->mUnk_a0);
    mobj_renderModel(a, rstar_sModel, b);
}

void rstar_update(void *a, Unk0209f1c8 *b) {
    u16 n;

    n = mobj_getModelNsbtaFrameCount(rstar_sModel);
    b->mUnk_a0 += 1;
    if (b->mUnk_a0 >= n) {
        b->mUnk_a0 = 0;
    }
    b->mUnk_00.mAngle += 0x111;
}

void *rstar_setupRenderPart(void) {
    return mobj_createRenderPart3d(rstar_loadModel, rstar_render, NULL);
}

void *rstar_setupLogicPart(void) {
    return mobj_createLogicPart(NULL, rstar_update, NULL);
}
