#include "Main/Unknown/code_020a3f2c.h"

#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a3fa8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2e4c.h"
#include "Main/Unknown/code_020a2e74.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020a2e88.h"
#include "Main/Unknown/code_020a2f0c.h"
#include "Main/Unknown/code_020a3000.h"
#include "Main/Unknown/code_020a683c.h"
#include "Main/Unknown/code_020a69a0.h"
#include "Main/Unknown/code_020a69b4.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020a6cb4.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_02039860.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_0210bae8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020a6000.h"
#include "Main/Unknown/code_020a0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/code_020a6c64.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02077bc0.h"

void shine_init(MapObject *p) {
    mobj_setInvisible(p);
    p->mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&p->mSound->mSoundSource, 0xb, &p->mPos);
    func_0210bae8(&p->mSound->mSoundSource);
    p->mFarDistanceSquared = gSfxParams[0xb].field20;
}

u32 shine_onDriverCollide(Shine16 *p, Kart *o, u8 *a, u8 *b) {
    u8 v1;
    u8 v2;
    s32 r;
    u16 c;
    s32 n;

    v1 = *a;
    v2 = *b;
    if (o->mState != KART_STATE_NORMAL || (o->field48 & 0x200) != 0 || mgcnt_isDriverDead(o->mIndex) != FALSE) {
        return 0;
    }
    if (v1 == 1) {
        if ((o->field4C & 0x400000) != 0) {
            return v2;
        }
        if (p->mPickupTimer > 0) {
            return v2;
        }
        p->field0.mFlags |= data_021567a0;
        p->mPickupTimer = 0x19;
        p->field0.mPos.x = o->mPos.x;
        p->field0.mPos.y = o->mPos.y + mgcnt_20A23A0(o) + 0x7800;
        p->field0.mPos.z = o->mPos.z;
        p->mHeightAboveKart = 0;
        p->field0.field10.x = 0;
        p->field0.field10.y = 0x3000;
        p->field0.field10.z = 0;
        p->mDrawScale = 0;
        p->mState = 2;
        p->mKartIndex = o->mIndex;
        p->fieldCA = o->mIndex;
        mgcnt_updateDriverBalloonShineInventoryCount(o->mIndex, 1);
        mgcnt_updateDriverBalloonShineCount(o->mIndex, 1);
        r = o->mIndex == gRaceMultiConfig->mEntryIndex ? 1 : 0;
        c = mgcnt_getMaxOwnedShineCount();
        n = mgcnt_getDriverBalloonShineCount(o->mIndex);
        sub_210B98C(p->field0.mSound, snd_getShineLoseSfxId(0, r, c, n));
        p->mEffect = ptcm_createEmitter(0x7d, &p->field0.mPos);
        p->mEffectTimer = 0xe;
    }
    return v2;
}

void shine_loadShineModel(void *a) {
    shine_sShineModel = mobj_loadTexAnimBillboardModel(a, aShine16_nsbmd, aShine16_nsbtp);
    mobj_setModelPolygonIdAll(shine_sShineModel, 0x3f);
}

void shine_applyShineMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, shine_sShineModel);
}

void shine_renderShine(void *a, Shine16 *p) {
    s32 t;
    Vec3 s;
    s32 n;

    if (p->mDrawScale <= 0) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&p->field0.mPos), 0xc);
    n = p->mDrawScale;
    if (n != 0x1000) {
        s.x = n;
        s.y = n;
        s.z = n;
        NNS_G3dGeBufferOP_N(0x1b, &s, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &p->field0.mScale, 3);
    mobj_setModelFlip(shine_sShineModel, p->mMirror, 0);
    mobj_setModelNsbtpFrame(shine_sShineModel, p->mNsbtpFrameIndex);
    mobj_renderModel(a, shine_sShineModel, p);
}

u32 func_020a69a0(void) {
    data_0217b220 = 0;
    return (u32) &data_0217b220;
}

void func_020a697c(void) {
    s32 v;

    v = data_0217b220 + 1;
    if (v >= 3) {
        v = 0;
    }
    data_0217b220 = v;
}

void func_020a683c(void *a, Shine16 *p, void *b, s32 c) {
    s32 t;
    s32 m[9];
    Vec3 s;
    Vec3 u;
    s32 n;
    s32 x;

    if (p->mDrawScale <= 0) {
        return;
    }
    if (p->mState == 2) {
        return;
    }
    if (p->mState == 3) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&p->field0.mPos), 0xc);
    n = p->mDrawScale;
    if (n < 0x1000) {
        s.x = n;
        s.y = n;
        s.z = n;
        NNS_G3dGeBufferOP_N(0x1b, &s, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &p->field0.mScale, 3);
    x = data_021567a4[data_0217b220] >> 4;
    MTX_RotY33_(m, FX_SinCosTable_[x * 2 + 1], FX_SinCosTable_[x * 2]);
    NNS_G3dGeBufferOP_N(0x1a, m, 9);
    u.x = 0x2000;
    u.y = 0x2000;
    u.z = 0x2000;
    NNS_G3dGeBufferOP_N(0x1b, &u, 3);
    oshd_renderJgShadow(8, c);
}

void shine_update(void *a, Shine16 *p) {
    Vec3 c;
    Vec3 b;
    Vec3 d;
    Vec3 e;
    u32 f;
    Kart *v;
    s32 i;
    CourseMapPoint *q;
    s32 n;
    s32 x;
    s32 z;
    s32 t;
    u16 r;
    s32 s;
    RandomState64 *g;

    switch (p->mState) {
        case 0:
            p->fieldB4 += 1;
            if (p->fieldB4 >= 3) {
                p->fieldB4 -= 3;
                p->mNsbtpFrameIndex++;
                if (p->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(shine_sShineModel)) {
                    p->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(shine_sShineModel);
                }
                p->mNsbtpFramesSinceMirror++;
                if (p->mNsbtpFramesSinceMirror >= 8) {
                    p->mNsbtpFramesSinceMirror -= 8;
                    p->mMirror = p->mMirror == 0;
                }
            }
            p->mDrawScale += 0x19a;
            if (p->mDrawScale >= 0x1000) {
                p->mDrawScale = 0x1000;
            }
            p->field0.field10.y -= 0x19a;
            VEC_Add(&p->field0.mPos, &p->field0.field10, &p->field0.mPos);
            if (p->field0.mPos.y > p->mFloorY) {
                return;
            }
            p->field0.mPos.y = p->mFloorY;
            p->field0.field10.y = ((s64) p->field0.field10.y * -0x333) >> 12;
            if (p->field0.field10.y < 0x1000) {
                p->field0.field10.y = 0;
                p->mState = 1;
            }
            sub_210B98C(p->field0.mSound, 0x139);
            return;
        case 1:
            p->fieldB4 += 1;
            if (p->fieldB4 >= 3) {
                p->fieldB4 -= 3;
                p->mNsbtpFrameIndex++;
                if (p->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(shine_sShineModel)) {
                    p->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(shine_sShineModel);
                }
                p->mNsbtpFramesSinceMirror++;
                if (p->mNsbtpFramesSinceMirror >= 8) {
                    p->mNsbtpFramesSinceMirror -= 8;
                    p->mMirror = p->mMirror == 0;
                }
            }
            p->mDrawScale += 0x19a;
            if (p->mDrawScale >= 0x1000) {
                p->mDrawScale = 0x1000;
            }
            sub_210BA38(p->field0.mSound, 0x14e);
            return;
        case 6:
            p->fieldB4 += 4;
            if (p->fieldB4 >= 3) {
                p->fieldB4 -= 3;
                p->mNsbtpFrameIndex++;
                if (p->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(shine_sShineModel)) {
                    p->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(shine_sShineModel);
                }
                p->mNsbtpFramesSinceMirror++;
                if (p->mNsbtpFramesSinceMirror >= 8) {
                    p->mNsbtpFramesSinceMirror -= 8;
                    p->mMirror = p->mMirror == 0;
                }
            }
            p->mDrawScale -= 0x19a;
            if (p->mDrawScale > 0) {
                return;
            }
            p->mDrawScale = 0;
            mobj_setInvisible(&p->field0);
            mgcnt_updateCollectableShineCount(-1);
            if (p->mSpawnObjectIndex < 0) {
                return;
            }
            sub_20A6CB4(p->mSpawnObjectIndex);
            return;
        case 2:
            p->fieldB4 += 4;
            if (p->fieldB4 >= 3) {
                p->fieldB4 -= 3;
                p->mNsbtpFrameIndex++;
                if (p->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(shine_sShineModel)) {
                    p->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(shine_sShineModel);
                }
                p->mNsbtpFramesSinceMirror++;
                if (p->mNsbtpFramesSinceMirror >= 8) {
                    p->mNsbtpFramesSinceMirror -= 8;
                    p->mMirror = p->mMirror == 0;
                }
            }
            v = driver_getById(p->mKartIndex);
            p->mHeightAboveKart += p->field0.field10.y;
            p->field0.mPos = *mgcnt_getDriverPosition(p->mKartIndex);
            p->field0.mPos.y += p->mHeightAboveKart + (mgcnt_20A23A0(v) + 0x7800);
            p->field0.field10.y -= 0x333;
            if (p->mPickupTimer-- <= 0) {
                p->mPickupTimer = 0;
                p->mDrawScale -= 0x19a;
                if (p->mDrawScale <= 0) {
                    p->mDrawScale = 0;
                    mobj_setInvisible(&p->field0);
                    mgcnt_updateCollectableShineCount(-1);
                    if (p->mSpawnObjectIndex >= 0) {
                        sub_20A6CB4(p->mSpawnObjectIndex);
                    }
                }
                if (p->mDrawScale <= 0) {
                    rptc_2081F10(ptcm_createEmitter(0x7c, &v->mPos), v->mIndex, 0x16);
                }
            } else {
                p->mDrawScale += 0x19a;
                if (p->mDrawScale >= 0x1000) {
                    p->mDrawScale = 0x1000;
                }
            }
            if (p->mEffect == NULL) {
                return;
            }
            ptcm_setEmitterPosition(p->mEffect, &p->field0.mPos);
            p->mEffectTimer--;
            if (p->mEffectTimer >= 0) {
                return;
            }
            ptcm_killEmitter(&p->mEffect);
            return;
        case 3:
            p->fieldB4 += 4;
            if (p->fieldB4 >= 3) {
                p->fieldB4 -= 3;
                p->mNsbtpFrameIndex++;
                if (p->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(shine_sShineModel)) {
                    p->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(shine_sShineModel);
                }
                p->mNsbtpFramesSinceMirror++;
                if (p->mNsbtpFramesSinceMirror >= 8) {
                    p->mNsbtpFramesSinceMirror -= 8;
                    p->mMirror = p->mMirror == 0;
                }
            }
            for (i = 0; i < 2; i++) {
                q = mgcnt_getRandomShineMepo();
                n = q->mPos.y - mgcnt_getDriverPosition(p->mKartIndex)->y;
                if (n <= 0) {
                    n = -n;
                }
                if (n < 0x14000) {
                    x = (q->mPos.x - mgcnt_getDriverPosition(p->fieldCA)->x) >> 12;
                    z = (q->mPos.z - mgcnt_getDriverPosition(p->fieldCA)->z) >> 12;
                    n = x * x + z * z;
                    if (p->fieldCA == p->mKartIndex) {
                        if (n < 0x9c400 && n > p->fieldD8) {
                            p->fieldD8 = n;
                            p->fieldCC.x = q->mPos.x;
                            p->fieldCC.y = q->mPos.y;
                            p->fieldCC.z = q->mPos.z;
                            p->fieldDC++;
                        }
                    } else {
                        if (n < 0x9c400 && n < p->fieldD8) {
                            p->fieldD8 = n;
                            p->fieldCC.x = q->mPos.x;
                            p->fieldCC.y = q->mPos.y;
                            p->fieldCC.z = q->mPos.z;
                            p->fieldDC++;
                        }
                    }
                }
            }
            p->mHeightAboveKart += p->field0.field10.y;
            p->field0.mPos = *mgcnt_getDriverPosition(p->mKartIndex);
            p->field0.mPos.y += p->mHeightAboveKart + (mgcnt_20A23A0(driver_getById(p->mKartIndex)) + 0x7800);
            p->field0.field10.y -= 0x52;
            p->mDrawScale += 0x19a;
            if (p->mDrawScale >= 0x1000) {
                p->mDrawScale = 0x1000;
            }
            if (p->field0.field10.y > 0) {
                return;
            }
            if (p->fieldDC > 0) {
                g = &gRaceStatus->mRandom;
                g->mValue = g->mMultiplier * g->mValue + g->mIncrement;
                r = ((u64) (u32) (g->mValue >> 32) * 0x10000) >> 32;
                g = &gRaceStatus->mRandom;
                g->mValue = g->mMultiplier * g->mValue + g->mIncrement;
                s = ((u64) (u32) (g->mValue >> 32) * 0x14000) >> 32;
                x = p->fieldCC.x + (s32) (((s64) s * FX_SinCosTable_[(r >> 4) * 2]) >> 12) - p->field0.mPos.x;
                z = p->fieldCC.z + (s32) (((s64) s * FX_SinCosTable_[(r >> 4) * 2 + 1]) >> 12) - p->field0.mPos.z;
                p->mState = 4;
                p->field0.field10.x = ((s64) x * 0x25) >> 12;
                p->field0.field10.y = 0x5000;
                p->field0.field10.z = ((s64) z * 0x25) >> 12;
                p->mDrawScale = 0x1000;
                p->field0.mFlags &= ~1;
                return;
            }
            p->mState = 5;
            p->field0.field10.x = 0;
            p->field0.field10.y = 0x5000;
            p->field0.field10.z = 0;
            p->mDrawScale = 0x1000;
            p->field0.mFlags &= ~1;
            return;
        case 5:
            p->fieldB4 += 1;
            if (p->fieldB4 >= 3) {
                p->fieldB4 -= 3;
                p->mNsbtpFrameIndex++;
                if (p->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(shine_sShineModel)) {
                    p->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(shine_sShineModel);
                }
                p->mNsbtpFramesSinceMirror++;
                if (p->mNsbtpFramesSinceMirror >= 8) {
                    p->mNsbtpFramesSinceMirror -= 8;
                    p->mMirror = p->mMirror == 0;
                }
            }
            p->mDrawScale += 0x19a;
            if (p->mDrawScale >= 0x1000) {
                p->mDrawScale = 0x1000;
            }
            p->field0.field10.y -= 0x19a;
            VEC_Add(&p->field0.mPos, &p->field0.field10, &p->field0.mPos);
            if (p->field0.field10.y >= 0) {
                return;
            }
            p->mState = 6;
            p->field0.mFlags |= data_021567a0;
            return;
        case 4:
            p->fieldB4 += 1;
            if (p->fieldB4 >= 3) {
                p->fieldB4 -= 3;
                p->mNsbtpFrameIndex++;
                if (p->mNsbtpFrameIndex >= mobj_getModelNsbtpFrameCount(shine_sShineModel)) {
                    p->mNsbtpFrameIndex -= mobj_getModelNsbtpFrameCount(shine_sShineModel);
                }
                p->mNsbtpFramesSinceMirror++;
                if (p->mNsbtpFramesSinceMirror >= 8) {
                    p->mNsbtpFramesSinceMirror -= 8;
                    p->mMirror = p->mMirror == 0;
                }
            }
            p->mDrawScale += 0x19a;
            if (p->mDrawScale >= 0x1000) {
                p->mDrawScale = 0x1000;
            }
            p->field0.field10.y -= 0x19a;
            VEC_Add(&p->field0.mPos, &p->field0.field10, &p->field0.mPos);
            if (p->field0.field10.y < 0 && p->field0.mPos.y <= p->fieldCC.y + p->field0.mExtent.x) {
                if (mobj_collideAsItem(&p->field0, 0, &b)) {
                    t = p->field0.field10.y;
                    VEC_Add(&p->field0.mPos, &b, &p->field0.mPos);
                    sub_20EA94C(&p->field0.field10, &b, 0x1000, 0x1000, 0x800, &p->field0.field10);
                    p->field0.field10.y = 0;
                    if ((s64) p->field0.field10.x * p->field0.field10.x +
                            (s64) p->field0.field10.y * p->field0.field10.y +
                            (s64) p->field0.field10.z * p->field0.field10.z >=
                        0x10) {
                        vec_normalize(&p->field0.field10, &p->field0.field10);
                    }
                    p->field0.field10.x = ((s64) p->field0.field10.x * 0x1000) >> 12;
                    p->field0.field10.y = ((s64) p->field0.field10.y * 0x1000) >> 12;
                    p->field0.field10.z = ((s64) p->field0.field10.z * 0x1000) >> 12;
                    p->field0.field10.y = t;
                }
                c.x = p->field0.mPos.x;
                c.y = p->field0.mExtent.x + (p->field0.mPos.y - 0x14000);
                c.z = p->field0.mPos.z;
                if (col_collide(&c, NULL, 0, p->field0.mExtent.x, 8, -2, &b, &d, &e.x, &f, NULL, NULL, NULL, NULL)) {
                    VEC_Add(&p->field0.mPos, &b, &p->field0.mPos);
                    if (f & 0x214300) {
                        t = p->field0.field10.y;
                        BounceVelocityOffSurface(&p->field0.field10, &e, 0x1000, 0x1000, 0x800, &p->field0.field10);
                        p->field0.field10.y = 0;
                        if ((s64) p->field0.field10.x * p->field0.field10.x +
                                (s64) p->field0.field10.y * p->field0.field10.y +
                                (s64) p->field0.field10.z * p->field0.field10.z >=
                            0x10) {
                            vec_normalize(&p->field0.field10, &p->field0.field10);
                        }
                        p->field0.field10.x = ((s64) p->field0.field10.x * 0x1000) >> 12;
                        p->field0.field10.y = ((s64) p->field0.field10.y * 0x1000) >> 12;
                        p->field0.field10.z = ((s64) p->field0.field10.z * 0x1000) >> 12;
                        p->field0.field10.y = t;
                    }
                    if (f & 0x1e34ef) {
                        p->field0.field10.x = ((s64) p->field0.field10.x * 0x19a) >> 12;
                        p->field0.field10.y = ((s64) p->field0.field10.y * -0x333) >> 12;
                        p->field0.field10.z = ((s64) p->field0.field10.z * 0x19a) >> 12;
                        if (p->field0.field10.y < 0x1000) {
                            p->field0.field10.y = 0;
                            p->mState = 1;
                        }
                        sub_210B98C(p->field0.mSound, 0x139);
                    }
                    if (f & 0x1000000) {
                        p->field0.mFlags |= data_021567ac;
                    } else {
                        p->field0.mFlags &= ~0x20;
                    }
                }
            }
            if (p->field0.mPos.y >= 0) {
                return;
            }
            p->mState = 6;
            p->field0.mFlags |= data_021567a0;
            return;
    }
}

void shine_setupCollision(void) {
    MapObjectKindData *p;

    p = mobj_createConfig(shine_onDriverCollide, NULL, NULL, 1, 0);
    p->field38 = 0x190000;
    p->field3C = -0x190000;
}

void *shine_setupShineRenderPart(void) {
    return mobj_createRenderPart2d(shine_loadShineModel, shine_renderShine, shine_applyShineMaterial);
}

void *shine_setupRenderPart2(void) {
    return mobj_createRenderPart3d(func_020a69a0, func_020a683c, func_020a697c);
}

void *shine_setupLogicPart(void) {
    return mobj_createLogicPart(NULL, shine_update, NULL);
}

// Parks each map object of kind 0x6a (Shine16) that is not already parked.
void shine_clearAll(void) {
    s32 i;
    MapObject *o;
    MapObjectList *l;

    l = mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_SHINE16);
    if (l == NULL) {
        return;
    }
    for (i = 0; i < l->mMapObjectCount && (o = l->mMapObjects[i]) != NULL; i++) {
        if ((o->mFlags & 0x100) == 0) {
            mobj_setInvisible(o);
        }
    }
}

// Unparks a Shine16 at the position; a nonzero last argument drops it from above, zero leaves it resting.
void shine_spawn(Vec3 *a, s32 b, s32 c) {
    Shine16 *p;

    p = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_SHINE16));
    if (p == NULL) {
        return;
    }
    if (c != 0) {
        p->field0.mPos.x = a->x;
        p->field0.mPos.y = a->y + 0x32000;
        p->field0.mPos.z = a->z;
        p->field0.field10.x = 0;
        p->field0.field10.y = 0x2800;
        p->field0.field10.z = 0;
        p->mHeightAboveKart = 0;
        p->mFloorY = a->y + 0x14000;
        p->mState = 0;
    } else {
        p->field0.mPos.x = a->x;
        p->field0.mPos.y = a->y + 0x14000;
        p->field0.mPos.z = a->z;
        p->field0.field10.x = 0;
        p->field0.field10.y = 0;
        p->field0.field10.z = 0;
        p->mHeightAboveKart = 0;
        p->mFloorY = 0;
        p->mState = 1;
    }
    p->mDrawScale = 0;
    p->mPickupTimer = 0;
    p->mSpawnObjectIndex = b;
    p->field0.mFlags &= ~1;
    p->field0.mFlags &= ~0x20;
    mgcnt_updateCollectableShineCount(1);
    sub_210B98C(p->field0.mSound, 0x138);
}

void shine_driverLostSpawn(Kart *a, Kart *b) {
    Shine16 *p;
    s32 r;
    u16 c;
    s32 n;

    p = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_SHINE16));
    if (p == NULL) {
        return;
    }
    p->field0.mFlags = p->field0.mFlags | data_021567a0;
    p->field0.mFlags &= ~0x20;
    p->field0.mPos.x = a->mPos.x;
    p->field0.mPos.y = a->mPos.y;
    p->field0.mPos.z = a->mPos.z;
    p->field0.field10.x = 0;
    p->field0.field10.y = 0x1000;
    p->field0.field10.z = 0;
    p->mKartIndex = a->mIndex;
    p->fieldCA = b->mIndex;
    p->mHeightAboveKart = 0;
    p->mFloorY = 0;
    p->mDrawScale = 0;
    p->mPickupTimer = 0;
    p->mState = 3;
    p->fieldCC = b->mPos;
    if (b == a) {
        p->fieldD8 = 0;
    } else {
        p->fieldD8 = 0x9c400;
    }
    p->fieldDC = 0;
    p->mSpawnObjectIndex = -1;
    mgcnt_updateCollectableShineCount(1);
    r = a->mIndex == gRaceMultiConfig->mEntryIndex ? 1 : 0;
    c = mgcnt_getMaxOwnedShineCount();
    n = mgcnt_getDriverBalloonShineCount(a->mIndex);
    sub_210B98C(p->field0.mSound, snd_getShineLoseSfxId(1, r, c, n));
}

BOOL blncnt_tryStealBalloon(u16 a, u16 b) {
    Kart *o;
    KartBalloons *e;
    Balloon *f;
    Balloon *l;
    Vec3 v;
    s32 n;

    o = driver_getById(a);
    mgcnt_getBlncntDriverEntries();
    if (mgcnt_getDriverBalloonShineCount(b) >= 3 || mgcnt_getDriverBalloonShineCount(a) == 0) {
        e = mgcnt_getBlncntDriverEntries() + a;
        f = mgcnt_getDriverIsInflating(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] : 0;
        l = mgcnt_getDriverBalloonShineCount(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a) - 1] : 0;
        if (mgcnt_getDriverBalloonShineCount(a) != 0 && l != NULL) {
            if (mgcnt_getDriverIsInflating(a) != 0 && f != NULL) {
                e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = l;
                mgcnt_updateDriverBalloonShineCount(a, -1);
                e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = f;
            } else {
                mgcnt_updateDriverBalloonShineCount(a, -1);
            }
        }
        if (l != NULL) {
            if (a == gRaceMultiConfig->mEntryIndex) {
                sub_20A2EBC(l, NULL);
            } else {
                v.x = o->mPos.x;
                v.y = o->mPos.y + mgcnt_20A23A0(o) - 0xf666;
                v.z = o->mPos.z;
                l->field0.mFlags &= ~4;
                l->field0.mFlags &= ~2;
                l->field0.mFlags &= ~8;
                l->field0.mAlpha = 0x1f;
                sub_20A2EBC(l, &v);
            }
            mobj_driverEmitSfx2(o, 0x153);
            if (mgcnt_getDriverBalloonShineCount(a) == 0) {
                mgcnt_killDriver(a);
            }
            return FALSE;
        }
    } else {
        e = mgcnt_getBlncntDriverEntries() + a;
        f = mgcnt_getDriverIsInflating(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] : 0;
        l = mgcnt_getDriverBalloonShineCount(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a) - 1] : 0;
        if (mgcnt_getDriverBalloonShineCount(a) != 0 && l != NULL) {
            if (mgcnt_getDriverIsInflating(a) != 0 && f != NULL) {
                e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = l;
                mgcnt_updateDriverBalloonShineCount(a, -1);
                e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = f;
            } else {
                mgcnt_updateDriverBalloonShineCount(a, -1);
            }
        }
        if (l != NULL) {
            e = mgcnt_getBlncntDriverEntries() + b;
            n = mgcnt_getDriverBalloonShineCount(b);
            e->mBalloons[n + 1] = e->mBalloons[mgcnt_getDriverBalloonShineCount(b)];
            e->mBalloons[mgcnt_getDriverBalloonShineCount(b)] = l;
            mgcnt_updateDriverBalloonShineCount(b, 1);
            sub_20A2E68(l);
            blln_setDriverId(l, b);
            if (mgcnt_getDriverBalloonShineCount(b) >= 2 && mgcnt_getDriverIsInflating(b) != 0) {
                e->mState = 4;
            }
            rptc_2081F10(ptcm_createEmitter(0x7a, &o->mPos), o->mIndex, 0x20);
            rptc_2081F10(ptcm_createEmitter(0x7b, &o->mPos), o->mIndex, 0x20);
            mobj_driverEmitSfx2(driver_getById(b), 0x14f);
            if (mgcnt_getDriverBalloonShineCount(a) == 0) {
                mgcnt_killDriver(a);
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 BalloonKartsHitEachOtherCallback(u16 a, u16 b) {
    KartBalloons *v1;
    KartBalloons *v2;
    Balloon *f;
    Balloon *l;
    Balloon *g;
    Balloon *m;
    Unk0210b7a8 s;
    s32 n;

    v1 = mgcnt_getBlncntDriverEntries();
    v1 += a;
    f = mgcnt_getDriverIsInflating(a) != 0 ? v1->mBalloons[mgcnt_getDriverBalloonShineCount(a)] : 0;
    l = mgcnt_getDriverBalloonShineCount(a) != 0 ? v1->mBalloons[mgcnt_getDriverBalloonShineCount(a) - 1] : 0;
    if (mgcnt_getDriverBalloonShineCount(a) != 0 && l != NULL) {
        if (mgcnt_getDriverIsInflating(a) != 0 && f != NULL) {
            v1->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = l;
            mgcnt_updateDriverBalloonShineCount(a, -1);
            v1->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = f;
        } else {
            mgcnt_updateDriverBalloonShineCount(a, -1);
        }
    }
    v2 = mgcnt_getBlncntDriverEntries();
    v2 += b;
    g = mgcnt_getDriverIsInflating(b) != 0 ? v2->mBalloons[mgcnt_getDriverBalloonShineCount(b)] : 0;
    m = mgcnt_getDriverBalloonShineCount(b) != 0 ? v2->mBalloons[mgcnt_getDriverBalloonShineCount(b) - 1] : 0;
    if (mgcnt_getDriverBalloonShineCount(b) != 0 && m != NULL) {
        if (mgcnt_getDriverIsInflating(b) != 0 && g != NULL) {
            v2->mBalloons[mgcnt_getDriverBalloonShineCount(b)] = m;
            mgcnt_updateDriverBalloonShineCount(b, -1);
            v2->mBalloons[mgcnt_getDriverBalloonShineCount(b)] = g;
        } else {
            mgcnt_updateDriverBalloonShineCount(b, -1);
        }
    }
    if (l != NULL) {
        v2 = mgcnt_getBlncntDriverEntries();
        v2 += b;
        n = mgcnt_getDriverBalloonShineCount(b);
        v2->mBalloons[n + 1] = v2->mBalloons[mgcnt_getDriverBalloonShineCount(b)];
        v2->mBalloons[mgcnt_getDriverBalloonShineCount(b)] = l;
        mgcnt_updateDriverBalloonShineCount(b, 1);
        sub_20A2E68(l);
        blln_setDriverId(l, b);
        if (mgcnt_getDriverBalloonShineCount(b) >= 2 && mgcnt_getDriverIsInflating(b) != 0) {
            v2->mState = 4;
        }
    }
    if (m != NULL) {
        v1 = mgcnt_getBlncntDriverEntries();
        v1 += a;
        n = mgcnt_getDriverBalloonShineCount(a);
        v1->mBalloons[n + 1] = v1->mBalloons[mgcnt_getDriverBalloonShineCount(a)];
        v1->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = m;
        mgcnt_updateDriverBalloonShineCount(a, 1);
        sub_20A2E68(m);
        blln_setDriverId(m, a);
        if (mgcnt_getDriverBalloonShineCount(a) >= 2 && mgcnt_getDriverIsInflating(a) != 0) {
            v1->mState = 4;
        }
    }
    if (a == gRaceMultiConfig->mEntryIndex || b == gRaceMultiConfig->mEntryIndex) {
        s.mSoundId = 0x14f;
        s.mPositionSource = NULL;
        s.field8 = 2;
        s.mDistanceSquared = mobj_calcXZCamDist(NULL);
        sub_210B7A8(&s);
    }
    return 1;
}

BOOL blncnt_loseBalloonOnDamage(u16 a, u16 b) {
    Kart *o;
    KartBalloons *e;
    Balloon *f;
    Balloon *l;
    Vec3 v;

    e = mgcnt_getBlncntDriverEntries() + a;
    f = mgcnt_getDriverIsInflating(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] : 0;
    l = mgcnt_getDriverBalloonShineCount(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a) - 1] : 0;
    if (mgcnt_getDriverBalloonShineCount(a) != 0 && l != NULL) {
        if (mgcnt_getDriverIsInflating(a) != 0 && f != NULL) {
            e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = l;
            mgcnt_updateDriverBalloonShineCount(a, -1);
            e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = f;
        } else {
            mgcnt_updateDriverBalloonShineCount(a, -1);
        }
    }
    if (l != NULL) {
        o = driver_getById(a);
        mgcnt_getBlncntDriverEntries();
        if (a == gRaceMultiConfig->mEntryIndex) {
            sub_20A2EBC(l, NULL);
        } else {
            v.x = o->mPos.x;
            v.y = o->mPos.y + mgcnt_20A23A0(o) - 0xf666;
            v.z = o->mPos.z;
            l->field0.mFlags &= ~4;
            l->field0.mFlags &= ~2;
            l->field0.mFlags &= ~8;
            l->field0.mAlpha = 0x1f;
            sub_20A2EBC(l, &v);
        }
        mobj_driverEmitSfx2(o, 0x153);
        if (mgcnt_getDriverBalloonShineCount(a) == 0) {
            mgcnt_killDriver(a);
        }
        return TRUE;
    }
    return FALSE;
}

void blncnt_onDriverKill(u16 a) {
    KartBalloons *e;
    Balloon *f;
    Balloon *l;

    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        return;
    }
    blncnt_loseBalloonOnDamage(a, a);
    if (mgcnt_getDriverBalloonShineCount(a) == 0) {
        return;
    }
    do {
        e = mgcnt_getBlncntDriverEntries() + a;
        f = mgcnt_getDriverIsInflating(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] : 0;
        l = mgcnt_getDriverBalloonShineCount(a) != 0 ? e->mBalloons[mgcnt_getDriverBalloonShineCount(a) - 1] : 0;
        if (mgcnt_getDriverBalloonShineCount(a) != 0 && l != NULL) {
            if (mgcnt_getDriverIsInflating(a) != 0 && f != NULL) {
                e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = l;
                mgcnt_updateDriverBalloonShineCount(a, -1);
                e->mBalloons[mgcnt_getDriverBalloonShineCount(a)] = f;
            } else {
                mgcnt_updateDriverBalloonShineCount(a, -1);
            }
        }
        if (l != NULL) {
            ParkBalloon(l, a);
        }
    } while (mgcnt_getDriverBalloonShineCount(a) != 0);
}

void blncnt_onMgEnd(void) {
    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        return;
    }
    sub_20A305C();
}

void blncnt_applyForceToDriverBalloons(u16 a, Vec3 *b) {
    KartBalloons *e;
    Balloon *p;
    s32 i;
    s32 n;

    e = mgcnt_getBlncntDriverEntries() + a;
    if (b == NULL) {
        return;
    }
    n = (mgcnt_getDriverIsInflating(a) != 0 ? 1 : 0) + mgcnt_getDriverBalloonShineCount(a);
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        p = e->mBalloons[i];
        p->field0.mPos.x += b->x;
        p->field0.mPos.y += b->y;
        p->field0.mPos.z += b->z;
        i++;
    } while (i < n);
}

// Init of the kind 0x69 object: creates and parks the kind 0x6c balloon objects (0x20 in mode 2, else 4), fills the
// frame indices, offsets and start timer, sets Standings.mKartBalloons and registers the callbacks in Standings (four
// hit callbacks, the kart-eliminated and the end callback). If kind 0x6c already exists it parks itself instead.
void blncnt_init(Unk020a3fa8 *a) {
    RaceSetup *d;
    s32 n;
    s32 i;
    KartBalloons *p;
    s32 j;
    s32 w;
    s32 v;

    if (mobj_getInstanceCountWithId(MAP_OBJECT_KIND_BALLOON) == 0) {
        d = gRaceMultiConfig;
        n = d->mKartCount;
        if (d->mMode == MODE_BATTLE) {
            mobj_createSubObjects(MAP_OBJECT_KIND_BALLOON, 0x20, a);
        } else {
            mobj_createSubObjects(MAP_OBJECT_KIND_BALLOON, 4, a);
        }
        for (i = 0; i < n; i++) {
            p = &a->mKartBalloons[i];
            if (a->field0.mCourseMapRow->field2C != 0) {
                p->mBalloonNsbtpFrameIndex = a->field0.mCourseMapRow->field2C;
            } else {
                switch (gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mTeamIndex) {
                    case 0:
                        p->mBalloonNsbtpFrameIndex = 1;
                        break;
                    case 1:
                        p->mBalloonNsbtpFrameIndex = 3;
                        break;
                    default:
                        p->mBalloonNsbtpFrameIndex = i;
                        break;
                }
            }
        }
        for (i = 0, w = 0; i < 8; i++, w -= 0x600) {
            for (j = 0, v = w; j < 8; j++, v += 0xc00) {
                a->mBalloonOffsets[i][j] = v;
            }
        }
        if (race_isCamAnimMode() != 0) {
            a->mStartTimer = 0xffff;
        } else {
            a->mStartTimer = 0x3c;
        }
        mgcnt_setBlncntDriverEntries(a->mKartBalloons);
        mgcnt_setTryStealBalloonFunc((s32(*)(s32, s32)) blncnt_tryStealBalloon);
        mgcnt_setField384((void (*)(s32, s32)) BalloonKartsHitEachOtherCallback);
        mgcnt_setOnDamageFunc(blncnt_loseBalloonOnDamage);
        mgcnt_setOnKillFunc(blncnt_onDriverKill);
        mgcnt_setOnEndFunc(blncnt_onMgEnd);
        mgcnt_setApplyForceToDriverBalloonsFunc((void (*)(s32, s32)) blncnt_applyForceToDriverBalloons);
    } else {
        mobj_setInvisible(&a->field0);
    }
}

// Per-frame step of the kind 0x69 object: after mStartTimer runs out it steps every kart's KartBalloons (makes,
// inflates, holds and deflates its balloons), updates the kart's count and hands each balloon its kart index, target
// position and velocity.
void blncnt_update(void *b, Unk020a3fa8 *c) {
    Balloon *balloon;
    s32 i;
    s32 j;
    s32 kartCount;
    s32 balloonCount;
    s32 a;
    s32 s;
    s32 d;
    Vec3 balloonPos;
    Vec3 t;
    Vec3 t2;
    Vec3 *q;

    kartCount = gRaceMultiConfig->mKartCount;
    if (c->mStartTimer > 0) {
        c->mStartTimer--;
        if (c->mStartTimer > 0) {
            return;
        }
        for (i = 0; i < kartCount; i++) {
            KartBalloons *kartBalloons = &c->mKartBalloons[i];
            driver_getById((u16) i);
            kartBalloons->mState = 1;
            if (c->field0.mCourseMapRow->field28 != 0 || c->field0.mCourseMapRow->field2A != 0) {
                kartBalloons->mRemainingSpawnCount = c->field0.mCourseMapRow->field28;
                mgcnt_updateDriverBalloonShineInventoryCount(i, c->field0.mCourseMapRow->field28 + c->field0.mCourseMapRow->field2A);
            } else {
                kartBalloons->mRemainingSpawnCount = 1;
                mgcnt_updateDriverBalloonShineInventoryCount(i, 5);
            }
        }
        return;
    }
    for (i = 0; i < kartCount; i++) {
        Kart *kart;
        KartBalloons *kartBalloons = &c->mKartBalloons[i];
        cam_getPlayerCamera();
        kart = driver_getById((u16) i);
        balloonPos.x = kart->mPos.x;
        balloonPos.y = kart->mPos.y + mgcnt_20A23A0(kart) - 0xf666;
        balloonPos.z = kart->mPos.z;
        switch (kartBalloons->mState) {
            case 0:
                if (kartBalloons->mSpawnTimer > 0) {
                    kartBalloons->mSpawnTimer--;
                    break;
                }
                if (mgcnt_getDriverBalloonShineInventoryCount(i) == 0) {
                    break;
                }
                if (mgcnt_getDriverBalloonShineCount(i) >= 3) {
                    break;
                }
                if (mgcnt_getDriverMicInflatingCounter(i) <= 0 && mgcnt_getDriverKeyInflating(i) <= 0) {
                    break;
                }
                balloon = blln_spawn(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                if (balloon == NULL) {
                    break;
                }
                kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)] = balloon;
                blln_inflate(balloon, i, 0xcd);
                kartBalloons->mState = 2;
                mgcnt_setDriverIsInflating(i, 1);
                mgcnt_updateDriverBalloonShineInventoryCount(i, -1);
                break;
            case 1:
                if (mgcnt_getDriverIsInflating(i) != 0) {
                    blln_inflate(kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)], i, 0x266);
                    break;
                }
                if (mgcnt_getDriverBalloonShineInventoryCount(i) != 0 && mgcnt_getDriverBalloonShineCount(i) < 3) {
                    if (kartBalloons->mRemainingSpawnCount > 0) {
                        balloon = blln_spawn(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                        if (balloon != NULL) {
                            kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)] = balloon;
                            blln_inflate(balloon, i, 0x266);
                            mgcnt_setDriverIsInflating(i, 1);
                            mgcnt_updateDriverBalloonShineInventoryCount(i, -1);
                            kartBalloons->mRemainingSpawnCount--;
                        }
                    }
                } else {
                    kartBalloons->mState = 0;
                }
                break;
            case 2:
                if (mgcnt_getDriverMicInflatingCounter(i) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                balloon = kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)];
                blln_inflate(balloon, i, 0xcd);
                if (blln_getInflationProgress(balloon) >= 0x800) {
                    kartBalloons->mState = 3;
                }
                break;
            case 3:
                if (mgcnt_getDriverMicInflatingCounter(i) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                if (mgcnt_getDriverKeyInflating(i) > 0) {
                    blln_inflate(kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)], i, 0x10);
                } else if (mgcnt_getDriverMicInflatingCounter(i) > 0) {
                    blln_inflate(kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)], i, 0x29);
                } else {
                    balloon = kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)];
                    blln_deflate(balloon, i, 0xe);
                    if (blln_getInflationProgress(balloon) <= 0x400) {
                        kartBalloons->mState = 4;
                    }
                }
                break;
            case 4:
                blln_deflate(kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)], i, 0x19a);
                break;
        }
        if (mgcnt_getDriverIsInflating(i) != 0) {
            balloon = kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)];
            if (blln_getInflationProgress(balloon) <= 0) {
                kartBalloons->mBalloons[mgcnt_getDriverBalloonShineCount(i)] = NULL;
                mgcnt_setDriverIsInflating(i, 0);
                mgcnt_updateDriverBalloonShineInventoryCount(i, 1);
                kartBalloons->mSpawnTimer = 0;
                kartBalloons->mState = 0;
            } else if (blln_getInflationProgress(balloon) >= 0x1000) {
                mgcnt_setDriverIsInflating(i, 0);
                mgcnt_updateDriverBalloonShineCount(i, 1);
                if (kartBalloons->mRemainingSpawnCount <= 0) {
                    kartBalloons->mSpawnTimer = 30;
                    kartBalloons->mState = 0;
                }
                mobj_driverEmitSfx2(driver_getById((u16) i), 0x152);
            }
        } else if (kartBalloons->mRemainingSpawnCount <= 0) {
            kartBalloons->mState = 0;
        }
        if (i == gRaceMultiConfig->mEntryIndex) {
            if (mgcnt_getDriverMicInflatingCounter(i) > 0 || mgcnt_getDriverKeyInflating(i) > 0) {
                s = mgcnt_getDriverBalloonShineCount(i) >= 3 ? 600 : 300;
                d = mgcnt_getDriverBalloonShineCount(i) >= 3 ? 200 : 100;
                kartBalloons->field8 += kartBalloons->fieldC;
                if (kartBalloons->field8 >= 0) {
                    if (kartBalloons->fieldC < 0) {
                        kartBalloons->fieldC = -s;
                    } else {
                        kartBalloons->fieldC -= d;
                    }
                } else {
                    if (kartBalloons->fieldC >= 0) {
                        kartBalloons->fieldC = s;
                    } else {
                        kartBalloons->fieldC += d;
                    }
                }
            } else {
                s = mgcnt_getDriverBalloonShineCount(i) >= 3 ? 600 : 300;
                if (kartBalloons->field8 >= 0) {
                    kartBalloons->field8 = kartBalloons->field8 < s ? 0 : kartBalloons->field8 - s;
                } else {
                    kartBalloons->field8 = kartBalloons->field8 > -s ? 0 : kartBalloons->field8 + s;
                }
            }
            balloonCount = mgcnt_getDriverBalloonShineCount(i) + (mgcnt_getDriverIsInflating(i) != 0 ? 1 : 0);
            for (j = 0; j < balloonCount; j++) {
                Balloon *balloon = kartBalloons->mBalloons[j];
                a = kartBalloons->field8 + c->mBalloonOffsets[balloonCount - 1][j];
                if (a != 0) {
                    q = &kart->field150;
                    t.x = ((s64) q->x * a) >> 12;
                    t.y = ((s64) q->y * a) >> 12;
                    t.z = ((s64) q->z * a) >> 12;
                    blln_addVelocity(balloon, &t);
                }
                if ((j & 1) == 1) {
                    q = &kart->field168;
                    t2.x = ((s64) q->x * -0xcd) >> 12;
                    t2.y = ((s64) q->y * -0xcd) >> 12;
                    t2.z = ((s64) q->z * -0xcd) >> 12;
                    blln_addVelocity(balloon, &t2);
                }
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                blln_setDriverId(balloon, i);
                blln_setSubBalloons(balloon, 1, NULL);
                balloon->field0.mFlags &= ~4;
                balloon->field0.mFlags &= ~2;
                balloon->field0.mFlags &= ~8;
                balloon->field0.mAlpha = 0x1f;
            }
        } else {
            balloonCount = mgcnt_getDriverBalloonShineCount(i) + (mgcnt_getDriverIsInflating(i) != 0 ? 1 : 0);
            for (j = 0; j < balloonCount; j++) {
                balloon = kartBalloons->mBalloons[j];
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                blln_setDriverId(balloon, i);
                if (j == 0) {
                    blln_setSubBalloons(balloon, balloonCount, kartBalloons->mBalloons);
                    balloon->field0.mFlags &= ~4;
                    balloon->field0.mFlags &= ~2;
                    balloon->field0.mFlags &= ~8;
                    balloon->field0.mAlpha = 0x1f;
                } else {
                    blln_setSubBalloons(balloon, 0, NULL);
                    balloon->field0.mFlags |= data_02156794;
                    balloon->field0.mFlags |= data_02156798;
                    balloon->field0.mFlags |= data_0215679c;
                }
            }
        }
    }
}

u32 CreateKartBalloonsKindData(void) {
    RaceSetup *d;
    s32 k;

    d = gRaceMultiConfig;
    k = d->mMode;
    if (k == MODE_BATTLE && d->mBattleKind == BATTLE_KIND_BALLOON) {
        return mobj_createDummyConfig();
    }
    if (k != MODE_MISSION_RUN) {
        return 0;
    }
    return mobj_createDummyConfig();
}

void *blncnt_setupLogicPart(void) {
    return mobj_createLogicPart(NULL, blncnt_update, NULL);
}
