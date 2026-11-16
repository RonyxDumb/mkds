#include "Main/Unknown/code_0209df00.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209eb54.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02077bc0.h"

void *pud_setupRenderPart(void) {
    return mobj_createRenderPart2d(pud_loadModel, pud_render, pud_globalPreRender);
}

void fbal2_init(Fireball2 *a) {
    a->field0.mFlags |= data_021565ec;
    a->fieldA0 = a->field0.mCourseMapRow->field28;
    a->fieldA2 = a->field0.mCourseMapRow->field2E + 1;
    mobj_initSoundEmitterForObjectSfxParam2(&a->field0);
    a->field0.mFlags &= ~1;
    a->field0.mFlags &= ~2;
    a->field0.mFlags &= ~8;
    a->field0.mAlpha = 0x1f;
}

u8 fbal2_onDriverCollide(Fireball2 *a, Kart *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->field19C4[b->mIndex] == 0) {
        if (b->mItemEffect == 1 || b->mItemEffect == 3) {
            a->field0.mDistanceSquaredAndFlags |= data_021565e8;
        }
        mobj_tryDestroyByDriver(&a->field0, b);
    }
    a->field19C4[b->mIndex] = 0xb;
    return v;
}

static inline BOOL func_0209df84_inline(Kart *p, Fireball2 *b, s32 t) {
    s32 y;
    s32 x;
    s32 z;
    s32 u;

    u = -t;
    z = p->mPos.z - b->field0.mPos.z;
    if (z > t || z < u) {
        return FALSE;
    }
    x = p->mPos.x - b->field0.mPos.x;
    if (x > t || x < u) {
        return FALSE;
    }
    y = p->mPos.y - b->field0.mPos.y;
    if (y > t || y < u) {
        return FALSE;
    }
    return (s64) x * x + (s64) y * y + (s64) z * z < (s64) t * t;
}

BOOL fbal2_collide(Fireball2 *a, Vec3 *b, s32 c) {
    s32 i;
    s32 d;
    s32 e;
    s32 f;

    for (i = 0; i < a->fieldA0; i++) {
        d = b->x - a->fieldC4[i][0].field0.x;
        e = b->y - a->fieldC4[i][0].field0.y;
        f = b->z - a->fieldC4[i][0].field0.z;
        if ((s64) d * d + (s64) e * e + (s64) f * f < (s64) (c + 0xf000) * (c + 0xf000)) {
            return TRUE;
        }
    }
    return FALSE;
}

void fbal2_loadModel(Unk0209e950 *a) {
    fbal2_sModel = mobj_loadBillboardModel(a, aFireball2_nsbm);
    mobj_setModelPolygonIdAll(fbal2_sModel, 0x3f);
    a->field1C = 1;
}

void fbal2_applyMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, fbal2_sModel);
}

void fbal2_render(void *a, Fireball2 *b) {
    s32 s1;
    s32 s2;
    s32 s3;
    s32 m1[9];
    s32 m2[9];
    s32 m3[9];
    s32 i;
    s32 c;
    s32 j;
    s32 f;
    s32 g;
    Camera *q;

    q = race_getCamera();
    c = vec_dotProduct(&b->field0.mMatrix.field0[0], &q->mForward);
    for (i = 0; i < b->fieldA0; i++) {
        if (c >= 0) {
            f = 1;
        } else {
            f = 0;
        }
        if (b->fieldC4[i][0].fieldC >= 0x4000 && b->fieldC4[i][0].fieldC < 0xc000) {
            g = 1;
        } else {
            g = 0;
        }
        if (f ^ g) {
            for (j = 0; j < b->fieldA2; j++) {
                s1 = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &s1, 1);
                NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&b->fieldC4[i][j].field0), 0xc);
                if (b->fieldC4[i][j].fieldE != 0) {
                    MTX_RotZ33_(m1, FX_SinCosTable_[(b->fieldC4[i][j].fieldE >> 4) * 2],
                                FX_SinCosTable_[(b->fieldC4[i][j].fieldE >> 4) * 2 + 1]);
                    NNS_G3dGeBufferOP_N(0x1a, m1, 9);
                }
                NNS_G3dGeBufferOP_N(0x1b, &b->field0.mScale, 3);
                mobj_setModelPolygonIdAll(fbal2_sModel, mobj_getCyclicPolygonId());
                mobj_renderModel(a, fbal2_sModel, b);
            }
        }
    }
    if (b->fieldA2 > 1) {
        s2 = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &s2, 1);
        NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&b->fieldB4), 0xc);
        if (b->fieldC2 != 0) {
            MTX_RotZ33_(m2, FX_SinCosTable_[(b->fieldC2 >> 4) * 2], FX_SinCosTable_[(b->fieldC2 >> 4) * 2 + 1]);
            NNS_G3dGeBufferOP_N(0x1a, m2, 9);
        }
        NNS_G3dGeBufferOP_N(0x1b, &b->field0.mScale, 3);
        mobj_setModelPolygonIdAll(fbal2_sModel, mobj_getCyclicPolygonId());
        mobj_renderModel(a, fbal2_sModel, b);
    }
    for (i = 0; i < b->fieldA0; i++) {
        if (c >= 0) {
            f = 1;
        } else {
            f = 0;
        }
        if (b->fieldC4[i][0].fieldC >= 0x4000 && b->fieldC4[i][0].fieldC < 0xc000) {
            g = 1;
        } else {
            g = 0;
        }
        if ((f ^ g) == 0) {
            for (j = b->fieldA2 - 1; j >= 0; j--) {
                s3 = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &s3, 1);
                NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&b->fieldC4[i][j].field0), 0xc);
                if (b->fieldC4[i][j].fieldE != 0) {
                    MTX_RotZ33_(m3, FX_SinCosTable_[(b->fieldC4[i][j].fieldE >> 4) * 2],
                                FX_SinCosTable_[(b->fieldC4[i][j].fieldE >> 4) * 2 + 1]);
                    NNS_G3dGeBufferOP_N(0x1a, m3, 9);
                }
                NNS_G3dGeBufferOP_N(0x1b, &b->field0.mScale, 3);
                mobj_setModelPolygonIdAll(fbal2_sModel, mobj_getCyclicPolygonId());
                mobj_renderModel(a, fbal2_sModel, b);
            }
        }
    }
}

void fbal2_globalLogicInit(MapObjectList *p) {
    s32 i;
    s32 j;
    s32 k;
    s16 v;
    float f;
    u64 t;
    Fireball2 *e;
    RandomState64 *r;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mMapObjectCount && (e = p->mMapObjects[i]) != NULL; i++) {
        v = e->field0.mCourseMapRow->field2A;
        if (v > 0) {
            f = 0.5f + (v << 12);
        } else {
            f = (v << 12) - 0.5f;
        }
        e->fieldAC = f;
        e->fieldB0 = (e->field0.mCourseMapRow->field2C * 0x16c) / 100;
        e->fieldA4 = 0x10000 / e->fieldA0;
        e->fieldA8 = e->fieldAC / e->fieldA2;
        r = mobj_getRng1();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        t = r->mValue >> 32;
        e->fieldC2 = (t * 0x10000) >> 32;
        for (j = 0; j < e->fieldA2; j++) {
            for (k = 0; k < e->fieldA0; k++) {
                r = mobj_getRng1();
                r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                t = r->mValue >> 32;
                e->fieldC4[k][j].fieldE = (t * 0x10000) >> 32;
            }
        }
    }
}

void fbal2_update(void *a, Fireball2 *b) {
    s32 i;
    s32 j;
    s32 n;
    s32 d;
    u16 w;
    Kart *p;
    NNSSndSeqPlayer **h;
    Vec3 v;

    n = b->fieldAC;
    b->fieldB4 = b->field0.mPos;
    if (b->fieldA2 == 1) {
        p = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
        if (func_0209df84_inline(p, b, n - 0xf000) != FALSE) {
            VEC_Subtract(&p->mPos, &b->field0.mPos, &v);
            d = vec_dotProduct(&v, &b->field0.mMatrix.field0[2]);
            if ((b->field19E4 < 0 && d > 0) || (b->field19E4 > 0 && d < 0)) {
                sub_2108E38();
                h = GetSndHandleSlot(7);
                if ((data_0217c780 & 1) && SoundHandle_217D084.fieldC != 0) {
                    if (h[0] != NULL) {
                        NNS_SndPlayerStopSeq(h, 0);
                    }
                    if (h[0] != NULL) {
                        NNS_SndPlayerStopSeq(h, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(h, 0, 0x1c2);
                }
                b->field19E4 = 0;
            } else {
                b->field19E4 = d;
            }
        } else {
            b->field19E4 = 0;
        }
    }
    if (b->fieldA2 > 1) {
        b->fieldC2 = b->fieldC2 + 0x51e;
    }
    for (i = 0; i < b->fieldA2; i++) {
        w = b->fieldB2;
        for (j = 0; j < b->fieldA0; j++) {
            w = w + b->fieldA4;
            b->fieldC4[j][i].fieldC = w;
            VEC_MultAdd(((s64) n * FX_SinCosTable_[(w >> 4) * 2 + 1]) >> 12, &b->field0.mMatrix.field0[0],
                        &b->field0.mPos, &b->fieldC4[j][i].field0);
            VEC_MultAdd(((s64) n * FX_SinCosTable_[(w >> 4) * 2]) >> 12, &b->field0.mMatrix.field0[1],
                        &b->fieldC4[j][i].field0, &b->fieldC4[j][i].field0);
            b->fieldC4[j][i].fieldE = b->fieldC4[j][i].fieldE + 0x51e;
        }
        n = n - b->fieldA8;
    }
    b->fieldB2 = b->fieldB2 - b->fieldB0;
    for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
        if (b->field19C4[i] > 0) {
            b->field19C4[i] = b->field19C4[i] - 1;
        }
    }
    mobj_emitSfxFromEmitter(&b->field0, 0x160);
}

void fbal2_setupConfig(void) {
    mobj_createConfigEx(fbal2_onDriverCollide, NULL, fbal2_collide, 0, 0, 0x18d);
}

void *fbal2_setupRenderPart(void) {
    return mobj_createRenderPart2d(fbal2_loadModel, fbal2_render, fbal2_applyMaterial);
}

void *fbal2_setupLogicPart(void) {
    return mobj_createLogicPart(fbal2_globalLogicInit, fbal2_update, NULL);
}
