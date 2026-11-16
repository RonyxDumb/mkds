#include "Main/Unknown/code_020e5d0c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020ea000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "registers.h"

#pragma thumb on

void bbm_initFromModel(Unk020e52bc *model, Unk020e6514 *animation, NsbmdModel *record) {
    Unk020e52bc_4 *a;
    Unk020e52bc_8 *b;
    Unk020e52bc_c *c;
    Unk020e53ac *d;
    Unk020e54e4 *e;
    Unk020e6514_8 x;
    u16 frameCount;
    u16 frame;
    void *t;
    enum { K0 } k;

    a = model->mUnk_004;
    b = OFFSET_PTR(Unk020e52bc_8, a->mUnk_000, a->mUnk_008);
    d = OFFSET_PTR(Unk020e53ac, b->mUnk_000, ((u32 *) &b->mUnk_000[b->mUnk_00a])[2]);
    c = OFFSET_PTR(Unk020e52bc_c, a->mUnk_000, a->mUnk_00c);
    e = OFFSET_PTR(Unk020e54e4, c->mUnk_000, ((u32 *) &c->mUnk_000[c->mUnk_006])[1]);
    record->mUnk_00 = &e->mUnk_000[e->mUnk_008];
    record->mUnk_04 = e->mUnk_00c;
    record->mUnk_08 = model->mUnk_004->mUnk_01c;
    record->mUnk_0c = d->mUnk_004;
    record->mUnk_10 = d->mUnk_008;
    record->mUnk_14 = d->mUnk_00c & 0xfffffff0;
    record->mFrameIndex = 0;
    if (animation != NULL) {
        x.mUnk_00 = d->mUnk_014;
        frameCount = anim_getAnimLength(animation) >> 12;
        record->mFrameCount = frameCount;
        t = proc_getHeap(proc_getCurrent());
        record->mUnk_1c = heap_alloc(t, frameCount * 4);
        t = proc_getHeap(proc_getCurrent());
        record->mUnk_20 = heap_alloc(t, frameCount * 4);
        frame = 0;
        if (frame < frameCount) {
            k = 0xc00f0000;
            x.mUnk_00 &= k;
            x.mUnk_04 = 0;
            do {
                animation->mUnk_00c = frame << 12;
                animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
                NNSi_G3dAnmCalcNsBtp(&x.mUnk_08, animation->mUnk_1c[0], x.mUnk_04);
                record->mUnk_1c[frame] = x.mUnk_08.mUnk_10 & 0x3ff0ffff;
                record->mUnk_1c[frame] |= x.mUnk_00;
                record->mUnk_20[frame] = x.mUnk_08.mUnk_14;
                frame++;
            } while (frame < frameCount);
        }
    } else {
        record->mFrameCount = 1;
        record->mUnk_1c = heap_alloc(proc_getHeap(proc_getCurrent()), 4);
        record->mUnk_20 = heap_alloc(proc_getHeap(proc_getCurrent()), 4);
        record->mUnk_1c[0] = d->mUnk_014;
        record->mUnk_20[0] = d->mUnk_01c;
    }
}

void bbm_initFromNsbmd(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 c) {
    record->mUnk_24 = heap_alloc(proc_getHeap(proc_getCurrent()), 0x6c);
    model_initFromNsbmd(record->mUnk_24, nsbmdFile);
    if (nsbtpFile != NULL) {
        record->mUnk_28 = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
        anim_20EA514(2, record->mUnk_24, record->mUnk_28, nsbmdFile, nsbtpFile);
    } else {
        record->mUnk_28 = NULL;
    }
    bbm_initFromModel(record->mUnk_24, record->mUnk_28, record);
}

void bbm_createFromNsbmd(NsbmdModel **recordSlot, void *nsbmdFile, void *nsbtpFile, u32 param_4) {
    *recordSlot = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    bbm_initFromNsbmd(*recordSlot, nsbmdFile, nsbtpFile, param_4);
}

#pragma thumb off

Unk020e5a9c *pend_setupConfig(void) {
    Unk020e5a9c *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = pend_colData;
    return kindData;
}

Unk020e5a40 *pend_setupRenderPart(void) {
    Unk020e5a40 *drawList;
    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    pend_sRenderPart = drawList;
    *drawList = pend_renderPartData;
    mobj_renderPartSetThisPointer(&pend_sRenderPart);
    return pend_sRenderPart;
}

Unk020e59e4 *pend_setupLogicPart(void) {
    Unk020e59e4 *updateList;
    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    pend_sLogicPart = updateList;
    *updateList = pend_logicPartData;
    mobj_logicPartSetThisPointer(&pend_sLogicPart);
    return pend_sLogicPart;
}

void pend_render(u32 param_1, PendulumObject *pendulum, u32 param_3, u32 alpha) {
    pendulum->mUnk_4c.x = pendulum->mUnk_bc.x >> 4;
    pendulum->mUnk_4c.y = pendulum->mUnk_bc.y >> 4;
    pendulum->mUnk_4c.z = pendulum->mUnk_bc.z >> 4;
    model2_renderModel(pend_sModel, &pendulum->mUnk_28, &pendulum->mUnk_1c, alpha);
    model2_renderShadowModel(pend_sShadowModel, &pendulum->mUnk_c8, &pendulum->mUnk_1c, alpha);
}

void pend_update(u32 param_1, PendulumObject *pendulum) {
    u32 swingRotation[4];
    Unk0210b7a8 soundRequest;
    u32 previousAngle;
    u16 swingAngle;
    s32 falloffIndex;

    previousAngle = pendulum->mUnk_100;
    pendulum->mUnk_100 = previousAngle + pendulum->mUnk_fe;
    swingAngle = ((s64) (s32) pendulum->mUnk_fc * FX_SinCosTable_[(pendulum->mUnk_100 >> 4) * 2]) >> 12;
    if ((previousAngle < 0x58f0 && pendulum->mUnk_100 >= 0x58f0) ||
        (previousAngle < 0xd8f0 && pendulum->mUnk_100 >= 0xd8f0)) {
        if ((pendulum->mUnk_78 & 4) == 0) {
            if (pendulum->mUnk_70 == gSfxParams[2].mUnk_20) {
                falloffIndex = 2;
            } else if (pendulum->mUnk_70 == gSfxParams[3].mUnk_20) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            soundRequest.mSoundId = 0x173;
            soundRequest.mPositionSource = &pendulum->mUnk_04;
            soundRequest.mUnk_08 = falloffIndex;
            soundRequest.mDistanceSquared = mobj_calcXZCamDist(&pendulum->mUnk_04);
            func_0210b7a8(&soundRequest);
        }
    }
    Quaternion_Rotate_20D7734(pendulum->mUnk_a0, swingAngle, swingRotation);
    qtrn_toMtx33(&pendulum->mUnk_28, swingRotation);
    VEC_MultAdd(-pendulum->mUnk_f8, &pendulum->mUnk_28.mUnk_0c, &pendulum->mUnk_bc, &pendulum->mUnk_04);
    pendulum->mUnk_ec.x = pendulum->mUnk_04.x >> 4;
    pendulum->mUnk_ec.y = pendulum->mUnk_04.y >> 4;
    pendulum->mUnk_ec.z = pendulum->mUnk_04.z >> 4;
    VEC_Subtract(&pendulum->mUnk_04, &pendulum->mUnk_b0, &pendulum->mUnk_10);
    pendulum->mUnk_b0 = pendulum->mUnk_04;
}

BOOL pend_collide(PendulumObject *pendulum, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *out) {
    Vec3 v;
    s32 axisDistance;
    s32 t;
    s32 d;
    s64 distanceSquared;

    VEC_Subtract(sphereCenter, &pendulum->mUnk_04, &v);
    axisDistance = vec_dotProduct(&v, &pendulum->mUnk_28.mUnk_18);
    if (axisDistance > 0) {
        t = pendulum->mUnk_108 + sphereRadius - axisDistance;
        if (t < 0) {
            return FALSE;
        }
    } else {
        t = -(pendulum->mUnk_108 + sphereRadius) - axisDistance;
        if (t > 0) {
            return FALSE;
        }
    }
    d = sphereRadius + pendulum->mUnk_104;
    distanceSquared = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
    if (distanceSquared < (s64) d * d) {
        reg_CP_SQRTCNT = 1;
        *(volatile s64 *) 0x40002b8 = distanceSquared;
        while (reg_CP_SQRTCNT & 0x8000) {
        }
        d -= reg_CP_SQRT_RESULT;
    } else {
        return FALSE;
    }
    if ((t > 0 ? t : -t) < d) {
        out->x = ((s64) pendulum->mUnk_28.mUnk_18.x * t) >> 12;
        out->y = ((s64) pendulum->mUnk_28.mUnk_18.y * t) >> 12;
        out->z = ((s64) pendulum->mUnk_28.mUnk_18.z * t) >> 12;
        pendulum->mUnk_10c = FALSE;
    } else {
        if (v.y < 0) {
            v.y = 0;
        }
        distanceSquared = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
        if (distanceSquared >= 16) {
            vec_normalize(&v, &v);
        }
        out->x = ((s64) v.x * d) >> 12;
        out->y = ((s64) v.y * d) >> 12;
        out->z = ((s64) v.z * d) >> 12;
        pendulum->mUnk_10c = TRUE;
    }
    return TRUE;
}

#pragma thumb on

void pend_loadModels(void) {
    model2_createFromNsbmd(&pend_sModel, mobj_getMapObjFile(aPendulum_nsbmd), NULL);
    model2_createShadowFromNsbmd(&pend_sShadowModel, mobj_getMapObjFile(aPendulum_shado), 0x3f);
    model_setPolyIdLightFlagsEmi(pend_sModel, 0x3f, 2, 0x294a);
}

void pend_init(PendulumObject *pendulum, Unk020e5e24_2 *courseRow) {
    s32 m;

    pendulum->mUnk_5c = ((s64) pendulum->mUnk_98->mUnk_10 * courseRow->mUnk_20) >> 12;
    qtrn_fromEulerAngles(&courseRow->mUnk_0c, pendulum->mUnk_a0);
    pendulum->mUnk_c8 = pendulum->mUnk_28;
    pendulum->mUnk_f8 = ((s64) pendulum->mUnk_1c.y * 0x1f4000) >> 12;
    pendulum->mUnk_100 = 0;
    pendulum->mUnk_bc.x = courseRow->mUnk_00.x;
    pendulum->mUnk_bc.y = courseRow->mUnk_00.y;
    pendulum->mUnk_bc.z = courseRow->mUnk_00.z;
    VEC_MultAdd(-pendulum->mUnk_f8, &pendulum->mUnk_28.mUnk_0c, &pendulum->mUnk_bc, &pendulum->mUnk_04);
    pendulum->mUnk_b0 = pendulum->mUnk_04;
    pendulum->mUnk_ec.x = pendulum->mUnk_04.x >> 4;
    pendulum->mUnk_ec.y = pendulum->mUnk_04.y >> 4;
    pendulum->mUnk_ec.z = pendulum->mUnk_04.z >> 4;
    m = courseRow->mUnk_2a;
    pendulum->mUnk_fe = 0x640000u / (u32) courseRow->mUnk_28 / 0xf0u;
    pendulum->mUnk_fc = (u32) (m * 0x1111) / 0x64u;
    pendulum->mUnk_104 = ((s64) pendulum->mUnk_1c.x * 0x64000) >> 12;
    pendulum->mUnk_108 = ((s64) pendulum->mUnk_1c.z * 0x32000) >> 12;
    pendulum->mUnk_10c = FALSE;
}

#pragma thumb off

Unk020e5a9c *obpak_setupConfig(void) {
    Unk020e5a9c *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_02159208;
    return kindData;
}

Unk020e5a40 *obpak_setupRenderPart(void) {
    Unk020e5a40 *drawList;
    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    obpak_sRenderPart = drawList;
    *drawList = data_021591dc;
    mobj_renderPartSetThisPointer(&obpak_sRenderPart);
    return obpak_sRenderPart;
}

Unk020e59e4 *obpak_setupLogicPart(void) {
    Unk020e59e4 *updateList;
    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    obpak_sLogicPart = updateList;
    *updateList = data_021591b4;
    return updateList;
}

void obpak_globalPreRender(void) {
    bbm_applyMaterial(obpak_sModel);
}
