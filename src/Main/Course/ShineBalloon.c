#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020a10f0.h"

#include "Main/Unknown/code_020ac6a8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020ac67c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ac9fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void sblln_init(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    mobj_setInvisible((void *) value0);
}

void sblln_loadModel(void *a) {
    void *p;

    p = mobj_loadBillboardModel(a, "shine_balloon.nsbmd");
    sblln_sModel = p;
    mobj_setModelPolygonIdAll(p, 0x3f);
}

void sblln_applyMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, sblln_sModel);
}

void sblln_render(void *a, ShineBalloonObject *b) {
    s32 s0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v4;
    s32 t;
    s32 v5;

    if (b->mUnk_ac->mVisible == 0) {
        return;
    }
    s0 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &s0, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&b->mUnk_00.mPos), 0xc);
    v2.y = mgcnt_20A23A0(b->mUnk_ac) >> 4;
    v2.x = 0;
    v2.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &v2, 3);
    t = b->mUnk_a0;
    if (t != 0x1000) {
        v3.x = t;
        v3.y = t;
        v3.z = t;
        NNS_G3dGeBufferOP_N(0x1b, &v3, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &b->mUnk_00.mScale, 3);
    VEC_Subtract(&b->mUnk_00.mPos, &race_getCamera()->mPos, &v1);
    v5 = VEC_Mag(&v1);
    v4.x = v5;
    v4.y = v5;
    v4.z = v5;
    NNS_G3dGeBufferOP_N(0x1b, &v4, 3);
    mobj_renderModel(a, sblln_sModel, b);
}

void sblln_update(void *a, ShineBalloonObject *b) {
    switch (b->mState) {
        case 0:
            if (mgcnt_getDriverBalloonShineCount(b->mUnk_ac->mIndex) == 0) {
                return;
            }
            b->mTimer = 0x1e;
            b->mUnk_a4 = 0x19;
            b->mState = 1;
            b->mUnk_00.mFlags &= ~2;
            b->mUnk_00.mFlags &= ~8;
            b->mUnk_00.mAlpha = 0x1f;
            break;
        case 1:
            if (b->mTimer-- > 0) {
                return;
            }
            b->mTimer = 0;
            b->mUnk_a0 += b->mUnk_a4;
            b->mUnk_a4 -= 4;
            if (b->mUnk_a4 < 0) {
                if (b->mUnk_a0 <= 0x4a) {
                    b->mUnk_a0 = 0x4a;
                    b->mState = 2;
                }
            }
            b->mUnk_00.mPos = b->mUnk_ac->mPos;
            break;
        case 2:
            if (mgcnt_getDriverBalloonShineCount(b->mUnk_ac->mIndex) == 0) {
                b->mTimer = 0x1e;
                b->mUnk_a4 = 8;
                b->mState = 3;
            }
            b->mUnk_00.mPos = b->mUnk_ac->mPos;
            break;
        case 3:
            if (b->mTimer-- <= 0) {
                b->mTimer = 0;
                b->mUnk_a0 += b->mUnk_a4;
                b->mUnk_a4 -= 4;
                if (b->mUnk_a4 < 0) {
                    if (b->mUnk_a0 <= 0) {
                        b->mUnk_a0 = 0;
                        b->mState = 0;
                        b->mUnk_00.mFlags |= data_02156838;
                        b->mUnk_00.mFlags |= data_0215683c;
                    }
                }
            }
            b->mUnk_00.mPos = b->mUnk_ac->mPos;
            break;
    }
}

void sblln_setupConfig(void) {
    mobj_createConfig(NULL, NULL, NULL, 1, 0);
}

void *sblln_setupRenderPart(void) {
    return mobj_createRenderPart2d(sblln_loadModel, sblln_render, sblln_applyMaterial);
}

void *sblln_setupLogicPart(void) {
    return mobj_createLogicPart(NULL, sblln_update, NULL);
}

void sblln_spawn(Kart *a) {
    ShineBalloonObject *o;

    o = mobj_acquireFreeObject(mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_SHINE_BALLOON));
    if (o == NULL) {
        return;
    }
    o->mUnk_00.mPos.x = 0;
    o->mUnk_00.mPos.y = 0;
    o->mUnk_00.mPos.z = 0;
    o->mUnk_00.mUnk_10.x = 0;
    o->mUnk_00.mUnk_10.y = 0;
    o->mUnk_00.mUnk_10.z = 0;
    o->mUnk_ac = a;
    o->mUnk_a0 = 0;
    o->mUnk_a4 = 0;
    o->mTimer = 0;
    o->mState = 0;
}

// Creates b map objects of kind a from the source object c and parks each one that is not already parked.
void mobj_createSubObjects(u32 a, s32 b, void *c) {
    s32 i;
    MapObject *e;

    for (i = 0; i < b; i++) {
        e = mobj_createSubObject(c, a);
        if ((e->mFlags & 0x100) == 0) {
            mobj_setInvisible(e);
        }
    }
}

// Returns the first map object in the update list of kind a that has the parked bit 0x100, or NULL if there is none;
// changes nothing.
void *FindParkedMapObject(s32 a) {
    MapObjectList *v1;
    void **v2;
    s32 n;
    s32 i;
    MapObject *e;

    v1 = mobj_getLogicPartForObjectId(a);
    v2 = mobj_logicPartGetInstanceList(v1);
    n = mobj_logicPartGetInstanceCount(v1);
    for (i = 0; i < n; i++) {
        e = v2[i];
        if (e->mFlags & 0x100) {
            return e;
        }
    }
    return NULL;
}
