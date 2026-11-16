#include "Main/Unknown/code_020a2f30.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_0209b634.h"

#include "Main/Unknown/code_020a36a8.h"
#include "Main/Unknown/code_020a3690.h"
#include "Main/Unknown/code_020a392c.h"
#include "Main/Unknown/code_020a3948.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3f18.h"
#include "Main/Unknown/code_02077bc0.h"

void blln_init(u32 balloon) {
    u32 balloonAddress = balloon;
    u32 noKartIndex;
    u32 value12;
    noKartIndex = ~(0u);
    *(u32 *) ((balloonAddress) + (164)) = noKartIndex;
    mobj_setInvisible((void *) balloonAddress);
}

void blln_loadModel(Unk020a3eb8 *a) {
    blln_sModel = mobj_loadTexAnimBillboardModel(a, aBalloon_nsbmd, aBalloon_nsbtp);
    mobj_setModelPolygonIdAll(blln_sModel, 0x3f);
    mobj_setModelAlpha(blln_sModel, 0x1a);
    mobj_setModelFogEnableFlag(blln_sModel, 0);
    a->field1C = 1;
}

void blln_globalPreRender(void *mapObjectList) {
    Camera *currentCamera;

    currentCamera = race_getCamera();
    data_0217b214.x = currentCamera->mPos.x >> 1;
    data_0217b214.y = currentCamera->mPos.y >> 1;
    data_0217b214.z = currentCamera->mPos.z >> 1;
    data_0217b208.x = currentCamera->mPos.x >> 3;
    data_0217b208.y = currentCamera->mPos.y >> 3;
    data_0217b208.z = currentCamera->mPos.z >> 3;
    mobj_bbModelApplyMaterial(mapObjectList, blln_sModel);
}

void blln_render(void *mapObjectList, Balloon *balloon) {
    s32 j;
    s32 drawCount;
    s32 i;
    s32 k;
    s32 drawScale;
    u32 distanceSquared;
    s32 t;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m0[9];
    s32 m1[9];
    s32 f0[3];
    s32 g0[3];
    s32 f1[3];
    s32 g1[3];
    s32 h[3];
    Balloon *listBalloon;

    if (balloon->mKartIndex >= 0) {
        if (driver_getById(balloon->mKartIndex)->mVisible == 0) {
            return;
        }
    }
    drawCount = balloon->mDrawCount;
    if (drawCount == 1 && balloon->mDrawList == NULL) {
        distanceSquared = balloon->field0.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = data_0217b214.x + (balloon->field0.mPos.x >> 1);
            balloon->mDrawPos.y = data_0217b214.y + (balloon->field0.mPos.y >> 1);
            balloon->mDrawPos.z = data_0217b214.z + (balloon->field0.mPos.z >> 1);
            balloon->mDrawScale = 0x800;
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x = data_0217b208.x + balloon->field0.mPos.x - (balloon->field0.mPos.x >> 3);
            balloon->mDrawPos.y = data_0217b208.y + balloon->field0.mPos.y - (balloon->field0.mPos.y >> 3);
            balloon->mDrawPos.z = data_0217b208.z + balloon->field0.mPos.z - (balloon->field0.mPos.z >> 3);
            balloon->mDrawScale = 0xe00;
        } else {
            balloon->mDrawPos = balloon->field0.mPos;
            balloon->mDrawScale = 0x1000;
        }
        w0 = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &w0, 1);
        NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&balloon->mDrawPos), 12);
        if (balloon->field0.mAngle != 0) {
            i = (balloon->field0.mAngle >> 4) * 2;
            MTX_RotZ33_(m0, FX_SinCosTable_[i + 1], FX_SinCosTable_[i]);
            NNS_G3dGeBufferOP_N(0x1a, m0, 9);
        }
        drawScale = balloon->mDrawScale;
        f0[0] = drawScale;
        f0[1] = drawScale;
        f0[2] = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, f0, 3);
        t = balloon->mScaleFactor + balloon->fieldD8;
        if (t != 0x1000) {
            g0[0] = t;
            g0[1] = t;
            g0[2] = t;
            NNS_G3dGeBufferOP_N(0x1b, g0, 3);
        }
        mobj_setModelPolygonIdAll(blln_sModel, mobj_getCyclicPolygonId());
        mobj_setModelNsbtpFrame(blln_sModel, balloon->mNsbtpFrameIndex);
        mobj_renderModel(mapObjectList, blln_sModel, balloon);
    } else if (drawCount > 0) {
        distanceSquared = balloon->field0.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = data_0217b214.x + (balloon->mTargetPos.x >> 1);
            balloon->mDrawPos.y = data_0217b214.y + (balloon->mTargetPos.y >> 1);
            balloon->mDrawPos.z = data_0217b214.z + (balloon->mTargetPos.z >> 1);
            balloon->mDrawScale = 0x800;
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x = data_0217b208.x + balloon->mTargetPos.x - (balloon->mTargetPos.x >> 3);
            balloon->mDrawPos.y = data_0217b208.y + balloon->mTargetPos.y - (balloon->mTargetPos.y >> 3);
            balloon->mDrawPos.z = data_0217b208.z + balloon->mTargetPos.z - (balloon->mTargetPos.z >> 3);
            balloon->mDrawScale = 0xe00;
        } else {
            balloon->mDrawPos = balloon->mTargetPos;
            balloon->mDrawScale = 0x1000;
        }
        w1 = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &w1, 1);
        NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&balloon->mDrawPos), 12);
        drawScale = balloon->mDrawScale;
        f1[0] = drawScale;
        f1[1] = drawScale;
        f1[2] = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, f1, 3);
        for (j = 0; j < drawCount; j++) {
            i = data_02156720[drawCount - 1][j];
            listBalloon = balloon->mDrawList[i];
            NNS_G3dGeBufferOP_N(0x11, NULL, 0);
            k = data_02156700[drawCount - 1][i];
            MTX_RotZ33_(m1, FX_SinCosTable_[(k >> 4) * 2 + 1], FX_SinCosTable_[(k >> 4) * 2]);
            NNS_G3dGeBufferOP_N(0x1a, m1, 9);
            t = listBalloon->mScaleFactor;
            if (t != 0x1000) {
                g1[0] = t;
                g1[1] = t;
                g1[2] = t;
                NNS_G3dGeBufferOP_N(0x1b, g1, 3);
            }
            h[0] = 0;
            h[1] = 0xf66;
            h[2] = 0;
            NNS_G3dGeBufferOP_N(0x1c, h, 3);
            mobj_setModelPolygonIdAll(blln_sModel, mobj_getCyclicPolygonId());
            mobj_setModelNsbtpFrame(blln_sModel, listBalloon->mNsbtpFrameIndex);
            mobj_renderModel(mapObjectList, blln_sModel, balloon);
            w2 = 1;
            NNS_G3dGeBufferOP_N(0x12, &w2, 1);
        }
    }
}

void blln_setParticleColor(Unk0201ca6c *effect, Balloon *balloon) {
    effect->field72 = func_0208606c(balloon->mNsbtpFrameIndex);
}

void func_020a36a8(Balloon *balloon) {
    Kart *kart;
    Vec3 *q;
    Vec3 v;
    s32 s;
    s32 t;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;

    if (balloon->mKartIndex < 0) {
        balloon->field0.field10.y = balloon->field0.field10.y + 0x1800;
    } else {
        kart = driver_getById((u16) balloon->mKartIndex);
        q = &kart->field12C;
        balloon->field0.field10.x = balloon->field0.field10.x + (q->x + (q->x >> 1));
        balloon->field0.field10.y = balloon->field0.field10.y + (q->y + (q->y >> 1));
        balloon->field0.field10.z = balloon->field0.field10.z + (q->z + (q->z >> 1));
    }
    v1 = (balloon->field0.mPos.x + balloon->field0.field10.x) - (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    v3 = (balloon->field0.mPos.z + balloon->field0.field10.z) - (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    t = ((s64) 0xa000 * (balloon->mScaleFactor + balloon->fieldD8)) >> 12;
    v6 = v3 < 0 ? -v3 : v3;
    v4 = v1 < 0 ? -v1 : v1;
    v7 = v4 / 2 + v6 / 2;
    if (v7 <= t) {
        balloon->fieldE0 = 1;
    } else if (balloon->fieldE0 != 0) {
        if (v7 > t) {
            s = FX_Div(v7 - t, v7);
            v.x = ((s64) v1 * s) >> 12;
            v.y = 0;
            v.z = ((s64) v3 * s) >> 12;
            VEC_Subtract(&balloon->field0.mPos, &v, &balloon->field0.mPos);
        }
    }
    v1 = (balloon->field0.mPos.x + balloon->field0.field10.x) - (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    v2 = (balloon->field0.mPos.y + balloon->field0.field10.y) - (balloon->mTargetPos.y + balloon->mTargetVelocity.y);
    v3 = (balloon->field0.mPos.z + balloon->field0.field10.z) - (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    t = (balloon->mScaleFactor + balloon->fieldD8) << 4;
    v5 = v2 < 0 ? -v2 : v2;
    v4 = v1 < 0 ? -v1 : v1;
    v6 = v3 < 0 ? -v3 : v3;
    v7 = v5 + (v4 >> 2) + (v6 >> 2);
    if (v7 > t) {
        s = FX_Div(v7 - t, v7);
        v.x = ((s64) v1 * s) >> 12;
        v.y = ((s64) v2 * s) >> 12;
        v.z = ((s64) v3 * s) >> 12;
        if (balloon->mKartIndex >= 0) {
            VEC_Subtract(&balloon->field0.field10, &v, &balloon->field0.field10);
        } else {
            VEC_Add(&balloon->mTargetVelocity, &v, &balloon->mTargetVelocity);
        }
    }
    VEC_Add(&balloon->field0.mPos, &balloon->field0.field10, &balloon->field0.mPos);
    VEC_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
}

u32 func_020a369c(Balloon *balloon) {
    return balloon->field0.mFlags & 0x12;
}

u32 GetBalloonDistanceSquared(Balloon *balloon) {
    return balloon->field0.mDistanceSquaredAndFlags & ~0xc000001fu;
}

void UpdateBalloonAngle(Balloon *balloon) {
    Camera *currentCamera;
    Vec3 v;
    u16 cameraAngle;
    s32 i;
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    s32 u;
    s32 w;

    currentCamera = race_getCamera();
    cameraAngle = FX_Atan2Idx(currentCamera->mForward.x, currentCamera->mForward.z) - 0x4000;
    VEC_Subtract(&balloon->field0.mPos, &currentCamera->mPos, &v);
    i = (cameraAngle >> 4) * 2;
    s = FX_SinCosTable_[i];
    c = FX_SinCosTable_[i + 1];
    x = ((s64) v.z * c) >> 12;
    y = ((s64) v.x * s) >> 12;
    u = v.y;
    VEC_Subtract(&balloon->mTargetPos, &currentCamera->mPos, &v);
    w = (s32) (((s64) v.x * s) >> 12) + (s32) (((s64) v.z * c) >> 12);
    balloon->field0.mAngle = FX_Atan2Idx(u - v.y, -(y + x - w));
}

void blln_update(void *mapObjectList, Balloon *balloon) {
    Kart *kart;

    if (balloon->mKartIndex >= 0) {
        switch (balloon->mState) {
            case 0:
                balloon->fieldD8 = balloon->fieldD8 + balloon->fieldDC;
                if (balloon->fieldD8 >= 0) {
                    if (balloon->fieldDC < 0) {
                        balloon->fieldDC = -50;
                    } else {
                        balloon->fieldDC = balloon->fieldDC - 10;
                    }
                } else {
                    if (balloon->fieldDC >= 0) {
                        balloon->fieldDC = 50;
                    } else {
                        balloon->fieldDC = balloon->fieldDC + 10;
                    }
                }
                if (balloon->mKartIndex == gRaceMultiConfig->mEntryIndex) {
                    if (race_getState() == 1) {
                        kart = driver_getById((u16) balloon->mKartIndex);
                        snd_emitBalloonInflationSfx(kart, balloon->mScaleFactor + balloon->fieldD8, balloon->fieldD4);
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    func_020a36a8(balloon);
                    if (func_020a369c(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->field0.mPos.x = balloon->mTargetPos.x;
                    balloon->field0.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->field0.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case 1:
                balloon->fieldD8 = 0;
                balloon->mScaleFactor = balloon->mScaleFactor + balloon->fieldD4;
                if (balloon->mScaleFactor >= 0x1000) {
                    balloon->fieldD4 = balloon->fieldD4 - 200;
                }
                if (balloon->fieldD4 < 0) {
                    if (balloon->mScaleFactor <= 0x1000) {
                        balloon->mScaleFactor = 0x1000;
                        balloon->mState = 2;
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    func_020a36a8(balloon);
                    if (func_020a369c(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->field0.mPos.x = balloon->mTargetPos.x;
                    balloon->field0.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->field0.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case 2:
                balloon->fieldD8 = 0;
                balloon->mScaleFactor = 0x1000;
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    func_020a36a8(balloon);
                    if (func_020a369c(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->field0.mPos.x = balloon->mTargetPos.x;
                    balloon->field0.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->field0.mPos.z = balloon->mTargetPos.z;
                }
                break;
            default:
                return;
        }
    } else {
        balloon->fieldD8 = 0;
        balloon->mScaleFactor = 0x1000;
        if (balloon->mNoKartTimer-- <= 0) {
            ptcm_createEmitterNoUpdateSkip(0x5b, &balloon->field0.mPos, balloon, blln_setParticleColor);
            ptcm_createEmitterNoUpdateSkip(0x5c, &balloon->field0.mPos, balloon, blln_setParticleColor);
            ptcm_createEmitterNoUpdateSkip(0x5d, &balloon->field0.mPos, balloon, blln_setParticleColor);
            func_0210b8f4(&balloon->field0.mPos, mobj_calcXZCamDist(&balloon->field0.mPos));
            mobj_setInvisible(&balloon->field0);
        } else {
            balloon->fieldC8 = balloon->fieldC8 + balloon->fieldCC;
            if (balloon->fieldC8 >= 0) {
                if (balloon->fieldCC < 0) {
                    balloon->fieldCC = -0x640;
                } else {
                    balloon->fieldCC = balloon->fieldCC - 200;
                }
            } else {
                if (balloon->fieldCC >= 0) {
                    balloon->fieldCC = 0x640;
                } else {
                    balloon->fieldCC = balloon->fieldCC + 200;
                }
            }
        }
        balloon->field0.mAngle = balloon->fieldC8 + 0x4000;
        balloon->field0.field10.y = balloon->field0.field10.y + 0x59a;
        balloon->mTargetVelocity.y = balloon->mTargetVelocity.y - 0x2000;
        balloon->field0.field10.x = ((s64) balloon->field0.field10.x * 0xc00) >> 12;
        balloon->field0.field10.y = ((s64) balloon->field0.field10.y * 0xc00) >> 12;
        balloon->field0.field10.z = ((s64) balloon->field0.field10.z * 0xc00) >> 12;
        VEC_Add(&balloon->field0.mPos, &balloon->field0.field10, &balloon->field0.mPos);
        VEC_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
    }
}

void *blln_setupRenderPart(void) {
    return mobj_createRenderPart2d(blln_loadModel, blln_render, blln_globalPreRender);
}

void *blln_setupLogicPart(void) {
    return mobj_createLogicPart(NULL, blln_update, NULL);
}

void sub_20A305C(void) {
    s32 i;
    MapObjectList *mapObjectList;
    Balloon *balloon;

    mapObjectList = mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_BALLOON);
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (balloon = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (balloon->mKartIndex >= 0) {
            balloon->mKartIndex = (u16) gRaceMultiConfig->mEntryIndex;
            balloon->mScaleFactor = 0x1000;
            balloon->fieldD4 = 0;
            balloon->fieldD8 = 0;
            balloon->fieldDC = 0;
            balloon->mState = 2;
        } else if ((balloon->field0.mFlags & 0x100) == 0) {
            mobj_setInvisible(&balloon->field0);
        }
    }
}

Balloon *blln_spawn(u16 nsbtpFrameIndex, Vec3 *targetPos) {
    Balloon *balloon;

    balloon = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_BALLOON));
    if (balloon == NULL) {
        return NULL;
    }
    balloon->mTargetPos = *targetPos;
    balloon->field0.mPos = balloon->mTargetPos;
    balloon->mScaleFactor = 0;
    balloon->fieldD4 = 0;
    balloon->fieldD8 = 0;
    balloon->fieldDC = 0;
    balloon->fieldE0 = 0;
    balloon->mNsbtpFrameIndex = nsbtpFrameIndex;
    balloon->mState = 0;
    return balloon;
}

void blln_inflate(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->fieldD4 = scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->fieldD4;
    balloon->fieldD8 = 0;
    balloon->fieldDC = 0;
    balloon->mState = 0;
    if (balloon->mScaleFactor >= 0x1000) {
        balloon->fieldD8 = 0;
        balloon->fieldD4 = 0x258;
        balloon->mState = 1;
    }
}

void blln_deflate(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->fieldD4 = -scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->fieldD4;
    balloon->mState = 0;
    if (balloon->mScaleFactor > 0) {
        return;
    }
    balloon->fieldD8 = 0;
    balloon->mScaleFactor = 0;
    balloon->mKartIndex = -1;
    balloon->mDrawCount = 1;
    balloon->mDrawList = NULL;
    mobj_setInvisible(&balloon->field0);
}
