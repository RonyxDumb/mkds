#include "01/code_0218c7a0.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181000.h"
#include "01/code_0218d4c8.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02110000.h"
#include "01/code_0218155c.h"
#include "01/code_0219b250.h"
#include "01/code_0218dce4.h"
#include "01/code_02188484.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020d3000.h"
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
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_02188da4.h"
#include "01/code_02187000.h"
#include "01/code_0218d520.h"
#include "01/code_0218ddb4.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "01/code_0218d374.h"

void func_ov001_0218d2c4(Unk02188950 *a) {
    int i;
    Unk0218d87c *list;
    Unk02188950 *p;
    Unk0210b7a8 local;

    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->field70, a->mPrm->field74);
    mobj_setModelNsbtpFrame(a->mNsbmd, 0);
    list = mobj_getLogicPartForObjectId(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->field4 && (p = list->field0[i]) != NULL; i++) {
            func_ov001_02187218(p, 1, NULL);
            StartAnimationNoEndCallback(p, p->mPrm->field70, p->mPrm->field74);
            mobj_setModelNsbtpFrame((p->mNsbmd), 0);
        }
    }
    local = data_ov001_021a7c08;
    local.mPositionSource = &a->field0.mPos;
    local.mDistanceSquared = mobj_calcXZCamDist(&a->field0.mPos);
    sub_210B734(&local, func_02108e7c());
}

void func_ov001_0218d280(void) {
    Unk0218d87c *list;
    Unk02188950 *p;
    int i;

    func_ov001_021882b8();
    list = mobj_getLogicPartForObjectId(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->field4 && (p = list->field0[i]) != NULL; i++) {
            func_ov001_0218dadc(p);
            func_ov001_0218dabc(p);
        }
    }
}

s32 func_ov001_0218d264(Unk02188950 *a) {
    int v1;
    v1 = race_getState();
    if (v1 == 1) {
        func_ov001_0218d4c8(a);
    }
    return 0;
}

void func_ov001_0218d23c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218d264);
    StartAnimationNoEndCallback(a, a->mPrm->field64, a->mPrm->field68);
}

void func_ov001_0218d214(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationWithEndCallback(a, a->mPrm->field58, a->mPrm->field5C, &func_ov001_0218d23c);
}

void func_ov001_0218d1e0(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->field4C, a->mPrm->field50);
    StartStateFrameCountCallback(a, a->mPrm->field54, &func_ov001_0218d214);
}

void func_ov001_0218d1bc(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->field40, a->mPrm->field44);
}

void func_ov001_0218d188(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->field34, a->mPrm->field38);
    StartStateFrameCountCallback(a, a->mPrm->field3C, &func_ov001_0218d1bc);
}

s32 func_ov001_0218d16c(Unk02188950 *a) {
    int v1;
    v1 = race_getState();
    if (v1 == 1) {
        func_ov001_0218d950(a);
    }
    return 0;
}

s32 func_ov001_0218d0fc(Unk02188950 *a) {
    int v1;
    v1 = mobj_getModelCurNsbcaFrame(a->mNsbmd);
    if (v1 == 0x33) {
        ReleaseEffects(a);
        StartEffectAtOffset(a, (0xfffff666u), 0, (0x00000400u), (0x00000434u), 0);
    } else {
        v1 = mobj_getModelCurNsbcaFrame(a->mNsbmd);
        if (v1 == 0x66) {
            ReleaseEffects(a);
            StartEffectAtOffset(a, (0x0000099au), 0, (0x00000400u), (0x00000434u), 0);
        }
    }
    return 0;
}

void func_ov001_0218d0d4(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218d16c);
    StartAnimationNoEndCallback(a, a->mPrm->field64, a->mPrm->field68);
}

void func_ov001_0218d0a8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218d0fc);
    StartAnimationWithEndCallback(a, a->mPrm->field58, a->mPrm->field5C, &func_ov001_0218d0d4);
}

void func_ov001_0218d074(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->field4C, a->mPrm->field50);
    StartStateFrameCountCallback(a, a->mPrm->field54, &func_ov001_0218d0a8);
}

void func_ov001_0218d050(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->field40, a->mPrm->field44);
}

void func_ov001_0218d01c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(a, a->mPrm->field34, a->mPrm->field38);
    StartStateFrameCountCallback(a, a->mPrm->field3C, &func_ov001_0218d050);
}

void func_ov001_0218cfe8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->field64, a->mPrm->field68);
    StartStateFrameCountCallback(a, a->mPrm->field54, &func_ov001_0218d0a8);
}

void InitHanachanObjects(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;

    if (a != NULL) {
        for (i = 0; i < a->field4 && (p = a->field0[i]) != NULL; i++) {
            p->field2C4 = TRUE;
            if (race_isCamAnimMode() != 0) {
                func_ov001_0218d188(p);
            } else {
                func_ov001_0218d1e0(p);
            }
        }
    }
    mgcnt_setOnEndFunc((void (*)(void)) func_ov001_0218d280);
}

void UpdateHanachan(u32 a, Unk02188950 *b) {
    int r;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        r = mgcnt_hasWinnerBeenDecided();
    } else {
        r = 0;
    }
    if (r != 0) {
        if (func_ov001_021871f8(b, 1) != 0) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                r = mgcnt_isDriverDead((u16) gRaceMultiConfig->mEntryIndex);
            } else {
                r = 0;
            }
            if (r != 0) {
                func_ov001_0218d374(b);
            } else {
                func_ov001_0218d2c4(b);
            }
        }
    } else {
        if (func_ov001_021871f8(b, 1) != 0) {
            func_ov001_0218d3ec(b);
        }
    }
    if (mobj_collideAsItemDirect(&b->mPosWithOffset, &b->field0.field10, b->mPrm->field100, b->field0.mCollisionSlotIndex, 9,
                      NULL) == 2) {
        mobj_emitSfxFromEmitter2(&b->field0, 0x253);
    }
    boss_update(a, b);
}

void func_ov001_0218ce90(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;

    if (a != NULL) {
        for (i = 0; i < a->field4 && (p = a->field0[i]) != NULL; i++) {
            if (race_isCamAnimMode() != 0) {
                func_ov001_0218d01c(p);
            } else if (i == 0) {
                func_ov001_0218d074(p);
            } else {
                func_ov001_0218cfe8(p);
            }
        }
    }
}

void func_ov001_0218ce30(u32 a, Unk02188950 *b) {
    int v1;
    func_ov001_0218dc20(b);
    func_ov001_0218dba8(b);
    v1 = mobj_collideAsItemDirect(&b->mPosWithOffset, &b->field0.field10, b->mPrm->field100, b->field0.mCollisionSlotIndex, 9,
                       NULL);
    if (v1 == 2) {
        mobj_emitSfxFromEmitter2(&b->field0, 0x253);
    }
    boss_update(a, b);
}

void hchan_initHead(Unk02188950 *e) {
    Unk02188950 *a;
    Unk02188950 *b;
    Unk02188950 *c;
    Unk02188950 *d;

    a = (Unk02188950 *) mobj_createSubObject(&e->field0, 0x1fe);
    b = (Unk02188950 *) mobj_createSubObject(&e->field0, 0x1fe);
    c = (Unk02188950 *) mobj_createSubObject(&e->field0, 0x1fe);
    d = (Unk02188950 *) mobj_createSubObject(&e->field0, 0x1fe);
    a->fieldA4 = (struct Unk0218dabc *) e;
    b->fieldA4 = (struct Unk0218dabc *) a;
    c->fieldA4 = (struct Unk0218dabc *) b;
    d->fieldA4 = (struct Unk0218dabc *) c;
    e->field0.mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&e->field0.mSound->mSoundSource, 0xd, &e->field0.mPos);
    e->field0.mFarDistanceSquared = data_0217cbec[0x1d];
}

void hchan_initBody(Unk02188950 *a) {
    a->field0.mSound = heap_alloc(proc_getHeap(proc_getCurrent()), 0x44);
    InitSoundSource(&a->field0.mSound->mSoundSource, 0xd, &a->field0.mPos);
    a->field0.mFarDistanceSquared = data_0217cbec[0x1d];
}

void func_ov001_0218cbdc(Unk02188950 *a, MissionRunPrm *b) {
    s32 r4;
    s32 diff;

    if (b->field29C == 1) {
        if (a->mTimer > 0) {
            a->field2D8 = 0xc;
        } else {
            r4 = a->mMoveAngle;
            diff = (u16) (FX_Atan2Idx(b->field80 - a->field0.mPos.x, b->field88 - a->field0.mPos.z) - r4);
            if (diff > 0x8000) {
                diff -= 0x10000;
            }
            if (diff > 0) {
                a->field0.field10.x = ((s64) a->mPrm->fieldFC * FX_SinCosTable_[(((u16) r4 + 0x4000) >> 4) * 2]) >> 12;
                a->field0.field10.y = 0;
                a->field0.field10.z =
                    ((s64) a->mPrm->fieldFC * FX_SinCosTable_[(((u16) a->mMoveAngle + 0x4000) >> 4) * 2 + 1]) >> 12;
            } else {
                a->field0.field10.x = ((s64) a->mPrm->fieldFC * FX_SinCosTable_[(((u16) r4 - 0x4000) >> 4) * 2]) >> 12;
                a->field0.field10.y = 0;
                a->field0.field10.z =
                    ((s64) a->mPrm->fieldFC * FX_SinCosTable_[(((u16) a->mMoveAngle - 0x4000) >> 4) * 2 + 1]) >> 12;
            }
            a->field2D8 = 0xc;
            cam_tryImpactShakePlayerCamera(a->field0.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
            a->field0.mDistanceSquaredAndFlags |= data_ov001_021a65ac;
            mobj_driverEmitSfx2(b, 0x252);
        }
    } else {
        a->field2D8 = 0xa;
        cam_tryImpactShakePlayerCamera(a->field0.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
        a->field0.mDistanceSquaredAndFlags |= data_ov001_021a65ac;
        mobj_driverEmitSfx2(b, 0x251);
    }
    SetKartCollisionCallback(a, func_ov001_0218cbdc);
}

void LoadHanachan(Unk0218d87c *a) {
    Unk02188950 *obj;
    s32 i;

    if (a != NULL) {
        for (i = 0; i < a->field4 && (obj = a->field0[i]) != NULL; i++) {
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            boss_21870E4(a, obj, aHanachan_nsbmd, aHanachan_nsbca, aHanachan_prm);
            LoadMissionRunMapObjectShadow(a, obj, aSh_circle_ns_3);
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, aHanachan_nsbtp);
            SetCollisionOffsetAndExtent(obj, obj->mPrm->field8, obj->mPrm->fieldC, obj->mPrm->fieldC);
            SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
            SetKartCollisionCallback(obj, func_ov001_0218cbdc);
            SetItemCollisionCallback(obj, func_ov001_0218dd9c);
            obj->fieldA8 = obj->mPrm->field12C;
        }
    }
}

void LoadHanachan_1234(Unk0218d87c *d) {
    void *a;
    void *b;
    void *c;
    Unk02188950 *obj;
    Unk02188950 *src;

    a = LoadFileInMissionRunFolder(aHanachan_1_nsb);
    b = LoadFileInMissionRunFolder(aHanachan_2_nsb);
    c = LoadFileInMissionRunFolder(aHanachan_1_n_0);
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        src = GetMissionRunMapObject(gRaceMultiConfig->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0);
    } else {
        src = NULL;
    }

    obj = d->field0[0];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    boss_21870E4(d, obj, aHanachan_1_n_1, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, a);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->fieldA8 = 1;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->fieldDC, obj->mPrm->fieldC, src->mPrm->fieldC);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);

    obj = d->field0[1];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    boss_21870E4(d, obj, aHanachan_2_n_0, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, b);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->fieldA8 = 2;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->fieldE4, obj->mPrm->fieldC, src->mPrm->fieldC);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);

    obj = d->field0[2];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    boss_21870E4(d, obj, aHanachan_3_nsb, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, a);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->fieldA8 = 3;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->fieldEC, obj->mPrm->fieldC, src->mPrm->fieldC);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);

    obj = d->field0[3];
    obj->mPrm = src->mPrm;
    obj->mShadowNsbmd = src->mShadowNsbmd;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    boss_21870E4(d, obj, aHanachan_4_nsb, NULL, NULL);
    func_ov001_0219b28c(obj->mNsbmd, b);
    func_ov001_0219b25c(obj->mNsbmd, c);
    obj->fieldA8 = 4;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->fieldF4, obj->mPrm->fieldC, src->mPrm->fieldC);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, func_ov001_0218cbdc);
    SetItemCollisionCallback(obj, func_ov001_0218dd9c);
}

void RenderHanachan(void *a, Unk02188950 *b) {
    boss_render(a, b);
    boss_renderShadow(a, b, 0);
}

void hchan_setupHeadCollision(void) {
    void *v7 = &boss_onDriverCollide;
    void *v8 = &boss_onItemCollide;
    void *v9 = &boss_collide;
    void *v11 = func_ov001_0219b510(v7, v8, v9, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *hchan_setupHeadRenderPart(void) {
    return mobj_createRenderPart3d(LoadHanachan, RenderHanachan, NULL);
}

void *hchan_setupHeadLogicPart(void) {
    return mobj_createLogicPart(InitHanachanObjects, UpdateHanachan, NULL);
}

void hchan_setupBodyCollision(void) {
    void *v7 = &boss_onDriverCollide;
    void *v8 = &boss_onItemCollide;
    void *v9 = &boss_collide;
    void *v11 = func_ov001_0219b510(v7, v8, v9, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *hchan_setupBodyRenderPart(void) {
    return mobj_createRenderPart3d(LoadHanachan_1234, RenderHanachan, ktesa_globalPreRender);
}

void *hchan_setupBodyLogicPart(void) {
    return mobj_createLogicPart(func_ov001_0218ce90, func_ov001_0218ce30, NULL);
}
