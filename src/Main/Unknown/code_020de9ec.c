#include "Main/Unknown/code_020de9ec.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d8c74.h"

#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020deb2c.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020debec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020df428.h"
#include "code_021471bc.h"

#pragma thumb on

void mibox_init(ItemBox *itemBox, Unk020de6a8_1 *row) {
    ibox_init(itemBox, row);
    if (itemBox->fieldF8 != 0) {
        itemBox->mFollower.field0.mGroupIndex = (0x0000ffffu);
        return;
    }
    pwex_initFromObject(&itemBox->mFollower, (CourseMapRow *) row, *&data_02158908, row->field28);
    pwex_init(&itemBox->mFollower, row->field30, 1);
    pw_calcCurrentPointXYZ(&itemBox->mFollower.field0, &itemBox->field0.mPos);
}

#pragma thumb off

#pragma thumb on
void mibox_globalInitLogic(void) {
    data_0217b750 = 0;
    data_0217b754 = 0;
    data_0217b75c = 0x1000;
    data_0217b760.x = 0x1000;
    data_0217b760.y = 0x1000;
    data_0217b760.z = 0x1000;
}
#pragma thumb off

MapObjectKindData *ibox_setupCollision(void) {
    MapObjectKindData *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_02158654;
    return kindData;
}

MapObjectDrawList *ibox_setupBoxRenderPart(void) {
    gBoxDrawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    *gBoxDrawList = data_02158628;
    mobj_renderPartSetThisPointer(&gBoxDrawList);
    return gBoxDrawList;
}

MapObjectDrawList *ibox_setupQuestionRenderPart(void) {
    gQuestionDrawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    *gQuestionDrawList = data_021585fc;
    mobj_renderPartSetThisPointer(&gQuestionDrawList);
    return gQuestionDrawList;
}

MapObjectDrawList *ibox_setupShadowRenderPart(void) {
    data_0217b714 = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    *data_0217b714 = data_021585d0;
    mobj_renderPartSetThisPointer(&data_0217b714);
    return data_0217b714;
}

MapObjectList *ibox_setupLogicPart(void) {
    ibox_sLogicPart = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    *ibox_sLogicPart = data_021585a8;
    mobj_logicPartSetThisPointer(&ibox_sLogicPart);
    return ibox_sLogicPart;
}

void ibox_applyBoxMaterial(void) {
    bbm_applyMaterial(ibox_sBoxModel);
}

void ibox_renderBox(void *unused0, ItemBox *itemBox, void *unused1, u16 d) {
    MtxFx43 matrix;
    NsbmdModel *model;
    Vec3 *position;
    s32 cosine;
    s32 sine;
    s32 negatedProduct;
    u16 x;
    u16 polygonId;
    u16 newPolygonId;
    BoxRotation *rotation;

    if (itemBox->fieldE8 < 1) {
        return;
    }
    if (itemBox->field100 != NULL) {
        itemBox->field100(itemBox->field104, &matrix);
        newPolygonId = mobj_getCyclicPolygonId();
        model = ibox_sBoxModel;
        model->field14 = model->field14 & 0xc0ffffff;
        model->field14 = model->field14 | newPolygonId << 24;
    } else {
        rotation = &gBoxRotations[itemBox->mBoxRotationIndex];
        cosine = rotation->field0;
        matrix.field0[0].x = cosine;
        sine = rotation->field4;
        matrix.field0[0].y = sine;
        matrix.field0[0].z = 0;
        negatedProduct = -rotation->field10;
        matrix.field0[1].x = negatedProduct;
        matrix.field0[1].y = rotation->field8;
        matrix.field0[1].z = sine;
        matrix.field0[2].x = rotation->fieldC;
        matrix.field0[2].y = negatedProduct;
        matrix.field0[2].z = cosine;
        position = itemBox->fieldFC;
        matrix.field0[3].x = position->x >> 4;
        matrix.field0[3].y = position->y >> 4;
        matrix.field0[3].z = position->z >> 4;
        polygonId = itemBox->mPolygonId;
        model = ibox_sBoxModel;
        model->field14 = model->field14 & 0xc0ffffff;
        model->field14 = model->field14 | polygonId << 24;
    }
    x = itemBox->fieldE8;
    model = ibox_sBoxModel;
    model->field14 = model->field14 & 0xffe0ffff;
    model->field14 = model->field14 | x << 16;
    if (itemBox->fieldFC != NULL) {
        if (itemBox->field0.mScale.z < 0x29) {
            return;
        }
        bbm_renderTransformedScaled(ibox_sBoxModel, &matrix, &itemBox->field0.mScale, 0, d);
    } else {
        bbm_renderTransformedScaled(ibox_sBoxModel, &matrix, NULL, 0, d);
    }
}

void ibox_applyQuestionMaterial(void) {
    bbm_applyMaterial(ibox_sQuestionModel);
}

void ibox_renderQuestion(void *unused0, ItemBox *itemBox, void *unused1, u16 d) {
    MtxFx43 matrix;
    s32 cosine;
    s32 negatedSine;
    QuestionRotation *rotation;
    NsbmdModel *p;
    Vec3 *position;
    s32 x;
    NsbmdModel *p2;
    u16 polygonId;

    itemBox->mPolygonId = mobj_getCyclicPolygonId();
    if (itemBox->field100 != NULL) {
        return;
    }
    if ((s32) (itemBox->field0.mDistanceSquaredAndFlags & 0x3fffffe0) > 0x27100) {
        if (rstat_getUncontrollable() == 0) {
            return;
        }
    }
    if (itemBox->fieldEC < 1) {
        return;
    }
    rotation = &gQuestionRotations[itemBox->mQuestionRotationIndex];
    cosine = rotation->field0;
    matrix.field0[0].x = cosine;
    matrix.field0[0].y = 0;
    negatedSine = -rotation->field4;
    matrix.field0[0].z = negatedSine;
    matrix.field0[1].x = 0;
    matrix.field0[1].y = 0x1000;
    matrix.field0[1].z = 0;
    matrix.field0[2].x = -negatedSine;
    matrix.field0[2].y = 0;
    matrix.field0[2].z = cosine;
    position = itemBox->fieldFC;
    matrix.field0[3].x = position->x >> 4;
    matrix.field0[3].y = position->y >> 4;
    matrix.field0[3].z = position->z >> 4;
    p = ibox_sQuestionModel;
    x = itemBox->fieldEC;
    p->field14 &= 0xffe0ffff;
    p->field14 |= (u16) x << 16;
    polygonId = itemBox->mPolygonId;
    p2 = ibox_sQuestionModel;
    p2->field14 &= 0xc0ffffff;
    p2->field14 |= polygonId << 24;
    bbm_renderTransformedScaled(ibox_sQuestionModel, &matrix, itemBox->fieldFC != NULL ? &itemBox->field0.mScale : 0, 0, d);
}

void ibox_globalPreRenderShadow(void) {
    s32 angleIndex;

    oshd_applyMaterial();
    if (rchoi_getIsRacePaused() != 0) {
        return;
    }
    data_0217b6fc += 0xca;
    angleIndex = data_0217b6fc >> 4;
    MTX_RotY43_(&data_0217b720, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
}

void ibox_renderShadow(void *unused, ItemBox *itemBox, u32 c, u32 d) {
    Vec3 shadowScale;
    Vec3 *position;
    s32 n;
    s32 x;
    s32 y;
    MtxFx43 *matrix;

    n = itemBox->mFramesSinceHit - 0x40;
    if (n >= 0x40) {
        itemBox->fieldE8 = 0x1a;
        itemBox->fieldEC = 0x14;
        n = 0xd;
    } else {
        x = n * 0x1a >> 6;
        y = n * 0x14 >> 6;
        n = n * 0xd >> 6;
        if (x > 0) {
            if (y < 1) {
                y = 1;
            }
            if (n < 1) {
                n = 1;
            }
        }
        itemBox->fieldE8 = x;
        itemBox->fieldEC = y;
    }
    if ((s32) (itemBox->field0.mDistanceSquaredAndFlags & ~0xc000001f) > 0x27100) {
        if (rstat_getUncontrollable() == 0) {
            return;
        }
    }
    if (n < 1) {
        return;
    }
    if (itemBox->fieldB0 == 0) {
        itemBox->fieldB4.field30 = n;
        oshd_render(&itemBox->fieldB4, itemBox->fieldA8 != 0 ? &data_0217b75c : 0, c, d);
        return;
    }
    if (itemBox->fieldB0 != 1) {
        return;
    }
    if (itemBox->fieldA8 != 0) {
        position = itemBox->fieldFC;
        data_0217b720.field0[3].x = position->x >> 4;
        data_0217b720.field0[3].y = position->y >> 4;
        data_0217b720.field0[3].z = position->z >> 4;
        oshd_renderJgShadowTransformed(&data_0217b760, &data_0217b720, (u16) n, d);
        return;
    }
    shadowScale.x = ((s64) itemBox->field0.mScale.x * 0x1666) >> 12;
    shadowScale.y = ((s64) itemBox->field0.mScale.y * 0x1666) >> 12;
    shadowScale.z = ((s64) itemBox->field0.mScale.z * 0x1666) >> 12;
    if (itemBox->field100 != NULL) {
        matrix = bbm_20E6B58(itemBox->fieldFC);
    } else {
        position = itemBox->fieldFC;
        data_0217b720.field0[3].x = position->x >> 4;
        data_0217b720.field0[3].y = position->y >> 4;
        data_0217b720.field0[3].z = position->z >> 4;
        matrix = &data_0217b720;
    }
    oshd_renderJgShadowTransformed(&shadowScale, matrix, (u16) n, d);
}

void ibox_update(void *unused, ItemBox *itemBox) {
    u32 framesSinceHit;

    itemBox->mBoxRotationIndex++;
    if (itemBox->mBoxRotationIndex >= 0x12c) {
        itemBox->mBoxRotationIndex = 0;
    }
    itemBox->mQuestionRotationIndex++;
    if (itemBox->mQuestionRotationIndex >= 0x82) {
        itemBox->mQuestionRotationIndex = 0;
    }
    framesSinceHit = itemBox->mFramesSinceHit;
    if (framesSinceHit >= 0x80) {
        return;
    }
    itemBox->mFramesSinceHit = framesSinceHit + 1;
    if (framesSinceHit > 0x60) {
        itemBox->field0.mFlags = itemBox->field0.mFlags & ~1;
    }
}

void ibox_handleBreak(Vec3 *position, void *kart, u32 c, int d, u32 e) {
    void *effect;
    u32 kartIndex;
    kartIndex = *OFFSET_PTR(u16, kart, 0x74);
    if (d == 0) {
        if (kartIndex == gRaceMultiConfig->mEntryIndex) {
            effect = ptcm_createEmitter(0x2d, position);
            if (effect != NULL) {
                rptc_2081F10(effect, kartIndex, 0x1e);
            }
            effect = ptcm_createEmitter(0x2e, position);
            if (effect != NULL) {
                rptc_2081F10(effect, kartIndex, 0x1e);
            }
        }
        effect = ptcm_createEmitter(0x2f, position);
        if (effect != NULL) {
            rptc_2081F10(effect, kartIndex, 0x1e);
        }
    }
    mobj_driverEmitSfx2(kart, 0xd4);
    StartItemSlotForKart(kartIndex, c, e);
}

u8 ibox_onDriverCollide(ItemBox *itemBox, Unk020dea50_1 *kart, void *c, u8 *d) {
    s32 playerKind;
    BOOL kindInMask;
    u32 distanceBits;

    if ((kart->field7C & 0x400000) != 0) {
        return 0;
    }
    kindInMask = FALSE;
    itemBox->mFramesSinceHit = 0;
    itemBox->field0.mFlags |= data_021585a4;
    distanceBits = itemBox->field0.mDistanceSquaredAndFlags & 3;
    playerKind = gRaceMultiConfig->mCurrentEntries[kart->field74].mPlayer.mKind;
    if ((u32) playerKind <= 3) {
        if (((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
            kindInMask = TRUE;
        }
    }
    ibox_handleBreak(&itemBox->field0.mPos, kart, kindInMask != FALSE ? itemBox->fieldF2 : itemBox->fieldF4,
                  distanceBits, itemBox->fieldAC);
    if (itemBox->fieldF8 != 0 || itemBox->field0.mCourseMapRow->field32 != 0) {
        itemBox->mFramesSinceHit = 0x80;
        mobj_setInvisible(&itemBox->field0);
    }
    return *d;
}

u32 sub_20DE9F8(ItemBox *itemBox) {
    if (itemBox->fieldF8 != 0) {
        return 0x270f000;
    }
    if (itemBox->fieldA8 == 0) {
        return 0;
    }
    return GetMaxXzDistanceToGroup(&itemBox->mFollower.field0, &itemBox->field0.mPos);
}

void func_020de9ec(ItemBox *itemBox) {
    itemBox->mFramesSinceHit = 0x80;
}
