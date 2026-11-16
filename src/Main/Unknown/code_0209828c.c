#include "Main/Unknown/code_0209828c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d9000.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02148538.h"

void *pknf_setupLogicPart(void) {
    return mobj_createLogicPart(NULL, pknf_update, NULL);
}

void pknf_spawn(GroupFollower *groupFollower, s32 b) {
    Unk0209905c *p;
    p = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(0x1ab));
    if (p == NULL) {
        return;
    }
    p->field0.mFlags = p->field0.mFlags & ~1;
    p->field0.mFlags = p->field0.mFlags & ~8;
    p->field0.mFlags = p->field0.mFlags & ~2;
    p->field0.mFlags = p->field0.mFlags & ~8;
    p->field0.mAlpha = 0x1f;
    p->mFollower.mGroupIndex = groupFollower->mGroupIndex;
    p->mFollower.mPath = groupFollower->mPath;
    pw_init(&p->mFollower, 0, 1);
    p->mFollower.mSpeed = 0x7800;
    p->mFollower.mProgressStep =
        ((s64) p->mFollower.mPath->mSegments[p->mFollower.mSegmentIndex].mInverseProgressLength * 0x7800) >> 12;
    p->mHeightOffset = b;
    p->fieldC8 = -0x5000;
    p->mState = 0;
    p->mEmitter = ptcm_createEmitter(0x33, &p->field0.mPos);
}

void pakn_init(Pakkun *pakkun) {
    s32 v;
    s32 d;
    Vec3 position;
    Vec3 step;
    s32 i;
    pakkun->field1D8 =
        (u32) (((s64) pakkun->field0.mCourseMapRow->fieldC.y * 0xb60b60b60bLL + 0x80000000000LL) >> 32 << 4) >> 16;
    pakkun->field1E4 = TRUE;
    pakkun->field1E8 = 0x1000;
    pakkun->field1EC = 0;
    pakkun->field1F0 = 0x1000;
    pakkun->field1F4 = 0;
    pakkun->field1F8 = 0x46000;
    for (i = 0; i < 7; i++) {
        pakkun->mFollowers[i].mGroupIndex = 0xffff;
    }
    for (i = 0; i < 7; i++) {
        if (i == 0) {
            v = pakkun->field0.mCourseMapRow->field28;
        } else if (i == 1) {
            v = pakkun->field0.mCourseMapRow->field2A;
        } else if (i == 2) {
            v = pakkun->field0.mCourseMapRow->field2C;
        } else if (i == 3) {
            v = pakkun->field0.mCourseMapRow->field2E;
        } else if (i == 4) {
            v = pakkun->field0.mCourseMapRow->field30;
        } else if (i == 5) {
            v = pakkun->field0.mCourseMapRow->field32;
        } else {
            v = pakkun->field0.mCourseMapRow->field34;
        }
        if (v >= 0) {
            pw_initFromPathId(&pakkun->mFollowers[pakkun->mFollowerCount], v, 100);
            pw_calcCurrentPointLinearXYZSpecial(&pakkun->mFollowers[pakkun->mFollowerCount], &position, &step);
            d = FX_Atan2Idx(step.x, step.z) - pakkun->field1D8;
            if (d > 0x8000) {
                d -= 0x10000;
            }
            pakkun->field1BC[pakkun->mFollowerCount] = d;
            pakkun->field1FC = pakkun->field0.mPos.y - position.y;
            pakkun->mFollowerCount++;
        }
    }
    pakkun->mPolygonId = mobj_getStaticPolygonId();
    mobj_createSubObjects(0x1ab, 0x14, pakkun);
}

void pakn_loadMouthModel(void *a) {
    gPakkunMouth = mobj_loadModel(a, "PakkunMouth.nsbmd");
    mobj_loadNsbcaAnim(gPakkunMouth, "PakkunMouth.nsbca");
    mobj_setModelAlpha(gPakkunMouth, 0x1f);
}

static inline u32 func_020983c4_inline(u32 n) {
    RandomState64 *mapObjectRandom;
    u32 t;
    u32 m;
    if (n == 0x10000) {
        mapObjectRandom = mobj_getRng1();
        mapObjectRandom->mValue =
            mapObjectRandom->mIncrement + (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue;
        return (u16) ((mapObjectRandom->mValue >> 32) * 0x10000 >> 32);
    }
    mapObjectRandom = mobj_getRng1();
    m = (u16) n;
    if (m == 0) {
        t = 0;
    } else {
        mapObjectRandom->mValue =
            mapObjectRandom->mIncrement + (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue;
        if (m == 0) {
            t = mapObjectRandom->mValue >> 32;
        } else {
            t = ((mapObjectRandom->mValue >> 32) * m) >> 32;
        }
    }
    return (u16) t;
}

void pakn_renderMouth(void *a, Pakkun *pakkun) {
    s32 w;
    s32 m[9];
    s32 n[9];
    s32 f[3];
    s32 g[3];
    s32 t;
    w = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w, 1);
    pakkun->field0.mMatrix.field0[3].x = pakkun->field0.mPos.x >> 4;
    pakkun->field0.mMatrix.field0[3].y = pakkun->field0.mPos.y >> 4;
    pakkun->field0.mMatrix.field0[3].z = pakkun->field0.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &pakkun->field0.mMatrix, 12);
    f[1] = pakkun->field1F8 >> 4;
    f[0] = 0;
    f[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, f, 3);
    if (pakkun->field1DC != 0) {
        MTX_RotY33_(m, FX_SinCosTable_[((u16) pakkun->field1DC >> 4) * 2],
                    FX_SinCosTable_[((u16) pakkun->field1DC >> 4) * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, m, 9);
    }
    if (pakkun->field1E0 != 0) {
        MTX_RotX33_(n, FX_SinCosTable_[((u16) pakkun->field1E0 >> 4) * 2],
                    FX_SinCosTable_[((u16) pakkun->field1E0 >> 4) * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, n, 9);
    }
    t = pakkun->field1F0;
    g[0] = t;
    g[1] = t;
    g[2] = t;
    NNS_G3dGeBufferOP_N(0x1b, g, 3);
    NNS_G3dGeBufferOP_N(0x1b, &pakkun->field0.mScale, 3);
    mobj_setModelPolygonIdAll(gPakkunMouth, pakkun->mPolygonId);
    mobj_setModelNsbcaFrame(gPakkunMouth, pakkun->fieldA4 >> 12);
    mobj_renderModel(a, gPakkunMouth, pakkun);
}

void pakn_loadHeadModel(void *a) {
    gPakkunZHead = mobj_loadBillboardModel(a, "PakkunZHead.nsbmd");
    mobj_setModelAlpha(gPakkunZHead, 0x1e);
}

void pakn_applyHeadMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, gPakkunZHead);
}

void pakn_renderHead(void *a, Pakkun *pakkun) {
    s32 w;
    Vec3 position;
    s32 f[3];
    s32 t;
    position.x = pakkun->field0.mPos.x;
    position.y = pakkun->field0.mPos.y + pakkun->field1F8;
    position.z = pakkun->field0.mPos.z;
    w = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&position), 12);
    t = pakkun->field1F0;
    f[0] = t;
    f[1] = t;
    f[2] = t;
    NNS_G3dGeBufferOP_N(0x1b, f, 3);
    NNS_G3dGeBufferOP_N(0x1b, &pakkun->field0.mScale, 3);
    mobj_setModelPolygonIdAll(gPakkunZHead, pakkun->mPolygonId);
    mobj_renderModel(a, gPakkunZHead, pakkun);
}

void pakn_loadBodyModel(void *a) {
    gPakkunBody = mobj_loadBillboardModel(a, "PakkunBody.nsbmd");
    mobj_setModelPolygonIdAll(gPakkunBody, 0x3f);
    mobj_setModelAlpha(gPakkunBody, 0x1f);
}

void pakn_applyBodyMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, gPakkunBody);
}

void pakn_renderBody(void *a, Pakkun *pakkun) {
    s32 w;
    s32 v[3];
    s32 d;
    s32 y;
    s32 x;
    x = pakkun->field1E8;
    y = pakkun->field1F0;
    d = 0x3000 - x - y;
    w = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&pakkun->field0.mPos), 12);
    v[0] = d;
    v[1] = x + y - 0x1000;
    v[2] = d;
    NNS_G3dGeBufferOP_N(0x1b, v, 3);
    NNS_G3dGeBufferOP_N(0x1b, &pakkun->field0.mScale, 3);
    mobj_renderModel(a, gPakkunBody, pakkun);
}

void pakn_globalLogicInit(void) {
    s32 i;
    Pakkun *pakkun;
    float f;
    if (pakn_sLogicPart == NULL) {
        return;
    }
    for (i = 0; i < pakn_sLogicPart->mMapObjectCount && (pakkun = pakn_sLogicPart->mMapObjects[i]) != NULL; i++) {
        if (mobj_getModelNsbcaFrameCount(gPakkunMouth) - 1 > 0) {
            f = 0.5f + ((mobj_getModelNsbcaFrameCount(gPakkunMouth) - 1) << 12);
        } else {
            f = ((mobj_getModelNsbcaFrameCount(gPakkunMouth) - 1) << 12) - 0.5f;
        }
        pakkun->fieldA4 = 0;
        pakkun->fieldA8 = 0x1000;
        pakkun->fieldAC = 0;
        pakkun->fieldB0 = f;
        pakkun->field1E0 = -0xa4;
    }
}

void pakn_update(void *a, Pakkun *pakkun) {
    BOOL f;
    s32 t;
    s32 x;
    s32 y;
    Unk0210b7a8 s;
    switch (pakkun->mState) {
        case 0:
            pakkun->mFollowerIndex += func_020983c4_inline((u16) (pakkun->mFollowerCount - 1)) + 1;
            if (pakkun->mFollowerIndex >= pakkun->mFollowerCount) {
                pakkun->mFollowerIndex -= pakkun->mFollowerCount;
            }
            pakkun->mState = 1;
        case 1:
            f = FALSE;
            if (pakkun->field1DC < pakkun->field1BC[pakkun->mFollowerIndex]) {
                pakkun->field1DC = pakkun->field1DC + 0x6d;
                if (pakkun->field1DC >= pakkun->field1BC[pakkun->mFollowerIndex]) {
                    f = TRUE;
                }
            } else {
                pakkun->field1DC = pakkun->field1DC - 0x6d;
                if (pakkun->field1DC <= pakkun->field1BC[pakkun->mFollowerIndex]) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                if (func_020983c4_inline(2) == 0) {
                    pakkun->mState = 2;
                } else {
                    pakkun->mState = 0;
                }
            }
            break;
        case 2:
            if (pakkun->field1EC >= -4 && pakkun->field1EC <= 4) {
                pakkun->mTimer = 0x1e;
                pakkun->mState = 3;
            }
            break;
        case 3:
            if (pakkun->mTimer-- <= 0) {
                pakkun->mTimer = 0;
                if (pakkun->field1E8 >= 0xffc) {
                    pakkun->field1E8 = 0x1000;
                    pakkun->field1E4 = FALSE;
                    pakkun->field1F4 = 0x7b;
                    pakkun->mState = 4;
                }
            } else {
                pakkun->field1E0 = pakkun->field1E0 + 0xa4;
            }
            break;
        case 4:
            pakkun->field1F0 = pakkun->field1F0 + pakkun->field1F4;
            pakkun->field1F4 = pakkun->field1F4 - 8;
            if (pakkun->field1F4 <= 0) {
                if (pakkun->field1F0 <= 0x119a) {
                    pakkun->mState = 5;
                }
            }
            break;
        case 5:
            pakkun->field1F0 = pakkun->field1F0 + pakkun->field1F4;
            pakkun->field1F4 = pakkun->field1F4 - 8;
            if (pakkun->field1F0 <= 0x1000) {
                pakkun->field1F0 = 0x1000;
                pakkun->field1E4 = TRUE;
            }
            pakkun->fieldA4 = pakkun->fieldA4 + pakkun->fieldA8;
            if (pakkun->fieldA4 >= pakkun->fieldB0) {
                pakkun->fieldA4 = pakkun->fieldAC;
            }
            if ((pakkun->fieldA4 >> 12) == 10) {
                pknf_spawn(&pakkun->mFollowers[pakkun->mFollowerIndex], pakkun->field1FC + 0x46000);
                if ((pakkun->field0.mDistanceSquaredAndFlags & 4) == 0) {
                    if (pakkun->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                        t = 2;
                    } else if (pakkun->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                        t = 3;
                    } else {
                        t = 4;
                    }
                    s.mSoundId = 0x171;
                    s.mPositionSource = &pakkun->field0.mPos;
                    s.field8 = t;
                    s.mDistanceSquared = mobj_calcXZCamDist(&pakkun->field0.mPos);
                    func_0210b7a8(&s);
                }
            } else if (pakkun->fieldA4 == 0) {
                pakkun->mTimer = 0x1e;
                pakkun->mState = 6;
            }
            break;
        case 6:
            if (pakkun->mTimer-- <= 0) {
                pakkun->mTimer = 0;
                pakkun->mState = 0;
            } else {
                pakkun->field1E0 = pakkun->field1E0 - 0xa4;
            }
            break;
    }
    if (pakkun->field1E4 != FALSE) {
        pakkun->field1E8 = pakkun->field1E8 + pakkun->field1EC;
        pakkun->field1EC = pakkun->field1EC + 4;
        if (pakkun->field1E8 >= 0x1000) {
            pakkun->field1EC = -0x52;
        }
    }
    x = ((s64) (pakkun->field1E8 + pakkun->field1F0 - 0x1000) * 0x2f000) >> 12;
    y = ((s64) pakkun->field1F0 * 0x17000) >> 12;
    pakkun->field1F8 = x + y;
}

void *pakn_setupMouthRenderPart(void) {
    pakn_sMouthRenderPart = mobj_createRenderPart3d(pakn_loadMouthModel, pakn_renderMouth, NULL);
    pakn_sMouthRenderPart->field1C = TRUE;
    mobj_renderPartSetThisPointer(&pakn_sMouthRenderPart);
    return pakn_sMouthRenderPart;
}

void *pakn_setupBodyRenderPart(void) {
    pakn_sBodyRenderPart = mobj_createRenderPart2d(pakn_loadBodyModel, pakn_renderBody, pakn_applyBodyMaterial);
    mobj_renderPartSetThisPointer(&pakn_sBodyRenderPart);
    return pakn_sBodyRenderPart;
}

void *pakn_setupZHeadRenderPart(void) {
    pakn_sHeadRenderPart = mobj_createRenderPart2d(pakn_loadHeadModel, pakn_renderHead, pakn_applyHeadMaterial);
    pakn_sHeadRenderPart->field1C = TRUE;
    mobj_renderPartSetThisPointer(&pakn_sHeadRenderPart);
    return pakn_sHeadRenderPart;
}

void *pakn_setupLogicPart(void) {
    pakn_sLogicPart = mobj_createLogicPart(pakn_globalLogicInit, pakn_update, NULL);
    mobj_logicPartSetThisPointer(&pakn_sLogicPart);
    return pakn_sLogicPart;
}
