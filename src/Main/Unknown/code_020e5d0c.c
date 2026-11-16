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

    a = model->field4;
    b = OFFSET_PTR(Unk020e52bc_8, a->field0, a->field8);
    d = OFFSET_PTR(Unk020e53ac, b->field0, ((u32 *) &b->field0[b->fieldA])[2]);
    c = OFFSET_PTR(Unk020e52bc_c, a->field0, a->fieldC);
    e = OFFSET_PTR(Unk020e54e4, c->field0, ((u32 *) &c->field0[c->field6])[1]);
    record->field0 = &e->field0[e->field8];
    record->field4 = e->fieldC;
    record->field8 = model->field4->field1C;
    record->fieldC = d->field4;
    record->field10 = d->field8;
    record->field14 = d->fieldC & 0xfffffff0;
    record->mFrameIndex = 0;
    if (animation != NULL) {
        x.field0 = d->field14;
        frameCount = anim_getAnimLength(animation) >> 12;
        record->mFrameCount = frameCount;
        t = proc_getHeap(proc_getCurrent());
        record->field1C = heap_alloc(t, frameCount * 4);
        t = proc_getHeap(proc_getCurrent());
        record->field20 = heap_alloc(t, frameCount * 4);
        frame = 0;
        if (frame < frameCount) {
            k = 0xc00f0000;
            x.field0 &= k;
            x.field4 = 0;
            do {
                animation->fieldC = frame << 12;
                animation->field1C[animation->field1A]->mFrame = animation->fieldC;
                NNSi_G3dAnmCalcNsBtp(&x.field8, animation->field1C[0], x.field4);
                record->field1C[frame] = x.field8.field10 & 0x3ff0ffff;
                record->field1C[frame] |= x.field0;
                record->field20[frame] = x.field8.field14;
                frame++;
            } while (frame < frameCount);
        }
    } else {
        record->mFrameCount = 1;
        record->field1C = heap_alloc(proc_getHeap(proc_getCurrent()), 4);
        record->field20 = heap_alloc(proc_getHeap(proc_getCurrent()), 4);
        record->field1C[0] = d->field14;
        record->field20[0] = d->field1C;
    }
}

void bbm_initFromNsbmd(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 c) {
    record->field24 = heap_alloc(proc_getHeap(proc_getCurrent()), 0x6c);
    model_initFromNsbmd(record->field24, nsbmdFile);
    if (nsbtpFile != NULL) {
        record->field28 = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
        anim_20EA514(2, record->field24, record->field28, nsbmdFile, nsbtpFile);
    } else {
        record->field28 = NULL;
    }
    bbm_initFromModel(record->field24, record->field28, record);
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
    pendulum->field4C.x = pendulum->fieldBC.x >> 4;
    pendulum->field4C.y = pendulum->fieldBC.y >> 4;
    pendulum->field4C.z = pendulum->fieldBC.z >> 4;
    model2_renderModel(pend_sModel, &pendulum->field28, &pendulum->field1C, alpha);
    model2_renderShadowModel(pend_sShadowModel, &pendulum->fieldC8, &pendulum->field1C, alpha);
}

void pend_update(u32 param_1, PendulumObject *pendulum) {
    u32 swingRotation[4];
    Unk0210b7a8 soundRequest;
    u32 previousAngle;
    u16 swingAngle;
    s32 falloffIndex;

    previousAngle = pendulum->field100;
    pendulum->field100 = previousAngle + pendulum->fieldFE;
    swingAngle = ((s64) (s32) pendulum->fieldFC * FX_SinCosTable_[(pendulum->field100 >> 4) * 2]) >> 12;
    if ((previousAngle < 0x58f0 && pendulum->field100 >= 0x58f0) ||
        (previousAngle < 0xd8f0 && pendulum->field100 >= 0xd8f0)) {
        if ((pendulum->field78 & 4) == 0) {
            if (pendulum->field70 == gSfxParams[2].field20) {
                falloffIndex = 2;
            } else if (pendulum->field70 == gSfxParams[3].field20) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            soundRequest.mSoundId = 0x173;
            soundRequest.mPositionSource = &pendulum->field4;
            soundRequest.field8 = falloffIndex;
            soundRequest.mDistanceSquared = mobj_calcXZCamDist(&pendulum->field4);
            sub_210B7A8(&soundRequest);
        }
    }
    Quaternion_Rotate_20D7734(pendulum->fieldA0, swingAngle, swingRotation);
    qtrn_toMtx33(&pendulum->field28, swingRotation);
    VEC_MultAdd(-pendulum->fieldF8, &pendulum->field28.fieldC, &pendulum->fieldBC, &pendulum->field4);
    pendulum->fieldEC.x = pendulum->field4.x >> 4;
    pendulum->fieldEC.y = pendulum->field4.y >> 4;
    pendulum->fieldEC.z = pendulum->field4.z >> 4;
    VEC_Subtract(&pendulum->field4, &pendulum->fieldB0, &pendulum->field10);
    pendulum->fieldB0 = pendulum->field4;
}

BOOL pend_collide(PendulumObject *pendulum, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *out) {
    Vec3 v;
    s32 axisDistance;
    s32 t;
    s32 d;
    s64 distanceSquared;

    VEC_Subtract(sphereCenter, &pendulum->field4, &v);
    axisDistance = vec_dotProduct(&v, &pendulum->field28.field18);
    if (axisDistance > 0) {
        t = pendulum->field108 + sphereRadius - axisDistance;
        if (t < 0) {
            return FALSE;
        }
    } else {
        t = -(pendulum->field108 + sphereRadius) - axisDistance;
        if (t > 0) {
            return FALSE;
        }
    }
    d = sphereRadius + pendulum->field104;
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
        out->x = ((s64) pendulum->field28.field18.x * t) >> 12;
        out->y = ((s64) pendulum->field28.field18.y * t) >> 12;
        out->z = ((s64) pendulum->field28.field18.z * t) >> 12;
        pendulum->field10C = FALSE;
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
        pendulum->field10C = TRUE;
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

    pendulum->field5C = ((s64) pendulum->field98->field10 * courseRow->field20) >> 12;
    qtrn_fromEulerAngles(&courseRow->fieldC, pendulum->fieldA0);
    pendulum->fieldC8 = pendulum->field28;
    pendulum->fieldF8 = ((s64) pendulum->field1C.y * 0x1f4000) >> 12;
    pendulum->field100 = 0;
    pendulum->fieldBC.x = courseRow->field0.x;
    pendulum->fieldBC.y = courseRow->field0.y;
    pendulum->fieldBC.z = courseRow->field0.z;
    VEC_MultAdd(-pendulum->fieldF8, &pendulum->field28.fieldC, &pendulum->fieldBC, &pendulum->field4);
    pendulum->fieldB0 = pendulum->field4;
    pendulum->fieldEC.x = pendulum->field4.x >> 4;
    pendulum->fieldEC.y = pendulum->field4.y >> 4;
    pendulum->fieldEC.z = pendulum->field4.z >> 4;
    m = courseRow->field2A;
    pendulum->fieldFE = 0x640000u / (u32) courseRow->field28 / 0xf0u;
    pendulum->fieldFC = (u32) (m * 0x1111) / 0x64u;
    pendulum->field104 = ((s64) pendulum->field1C.x * 0x64000) >> 12;
    pendulum->field108 = ((s64) pendulum->field1C.z * 0x32000) >> 12;
    pendulum->field10C = FALSE;
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
