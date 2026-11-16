#include "Main/Unknown/code_020de588.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e512c.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void ibox_loadModels(void) {
    s32 boxIndex;
    s32 questionIndex;
    s32 cosine;
    s32 sine;
    u32 angleIndex;
    NsbmdModel *p;

    bbm_createFromNsbmd(&ibox_sBoxModel, mobj_getSharedMapObjFile("box.nsbmd"), 0, 0);
    bbm_createFromNsbmd(&ibox_sQuestionModel, mobj_getSharedMapObjFile("question.nsbmd"), 0, 0);
    bbm_setDefaultMatParams(ibox_sBoxModel);
    bbm_setDefaultMatParams(ibox_sQuestionModel);
    p = ibox_sBoxModel;
    p->mUnk_10 = p->mUnk_10 & 0x8000ffff;
    p->mUnk_10 = p->mUnk_10 | 0x52940000;
    p = ibox_sQuestionModel;
    p->mUnk_10 = p->mUnk_10 & 0x8000ffff;
    p->mUnk_10 = p->mUnk_10 | 0x52940000;
    gBoxRotations = heap_alloc(proc_getHeap(proc_getCurrent()), 0x1770);
    for (boxIndex = 0; boxIndex < 0x12c; boxIndex++) {
        angleIndex = (u16) (((u32) boxIndex << 16) / 0x12c) >> 4;
        cosine = FX_SinCosTable_[angleIndex * 2 + 1];
        sine = FX_SinCosTable_[angleIndex * 2];
        gBoxRotations[boxIndex].mUnk_00 = cosine;
        gBoxRotations[boxIndex].mUnk_04 = sine;
        gBoxRotations[boxIndex].mUnk_08 = ((s64) cosine * cosine) >> 12;
        gBoxRotations[boxIndex].mUnk_0c = ((s64) sine * sine) >> 12;
        gBoxRotations[boxIndex].mUnk_10 = ((s64) cosine * sine) >> 12;
    }
    gQuestionRotations = heap_alloc(proc_getHeap(proc_getCurrent()), 0x410);
    for (questionIndex = 0; questionIndex < 0x82; questionIndex++) {
        angleIndex = (u16) (((u32) questionIndex << 16) / 0x82) >> 4;
        gQuestionRotations[questionIndex].mUnk_00 = FX_SinCosTable_[angleIndex * 2 + 1];
        gQuestionRotations[questionIndex].mUnk_04 = FX_SinCosTable_[angleIndex * 2];
    }
    if (gRaceMultiConfig->mCourseId == COURSE_ID_RAINBOW) {
        ibox_sBoxModel->mUnk_14 &= 0xffff7fff;
        ibox_sQuestionModel->mUnk_14 &= 0xffff7fff;
    }
}

void ibox_init(ItemBox *itemBox, Unk020de6a8_1 *row) {
    RandomState64 *random;
    Vec3 shadowPos;
    BOOL v1;

    itemBox->mUnk_000.mPos.y += 0xc000;
    itemBox->mUnk_0fc = &itemBox->mUnk_000.mPos;
    random = mobj_getRng1();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemBox->mBoxRotationIndex = ((u64) (u32) (random->mValue >> 32) * 0x12c) >> 32;
    random = mobj_getRng1();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemBox->mQuestionRotationIndex = ((u64) (u32) (random->mValue >> 32) * 0x82) >> 32;
    itemBox->mFramesSinceHit = 0x80;
    if (row != NULL) {
        if (itemBox->mUnk_000.mKind == 0xc9 && row->mUnk_26 >= 0) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
        itemBox->mUnk_0a8 = v1;
        itemBox->mUnk_0ac = row->mUnk_34;
        itemBox->mUnk_0f8 = 0;
    } else {
        itemBox->mUnk_0a8 = 1;
        itemBox->mUnk_0ac = 0;
        itemBox->mUnk_0f8 = 1;
        mobj_setScale(&itemBox->mUnk_000, (Vec3 *) ItemBoxScale);
    }
    if (itemBox->mUnk_0f8 != 0) {
        itemBox->mUnk_0f2 = 0;
        itemBox->mUnk_0f4 = 0;
    } else {
        itemBox->mUnk_0f2 = row->mUnk_2a;
        itemBox->mUnk_0f4 = row->mUnk_2c;
    }
    if (itemBox->mUnk_0f8 != 0) {
        itemBox->mUnk_0b0 = 1;
    } else {
        itemBox->mUnk_0b0 = row->mUnk_2e;
        if (itemBox->mUnk_0b0 == 0) {
            shadowPos = row->mUnk_00;
            if (itemBox->mUnk_0a8 != 0) {
                shadowPos.y += 0x800;
            }
            if (oshd_setParams(&itemBox->mUnk_0b4, &shadowPos, 0x14000, 0xd) == 0) {
                itemBox->mUnk_0b0 = 2;
            }
        }
    }
    if (row != NULL) {
        if (oshd_20E512C(&row->mUnk_00) != 0) {
            itemBox->mUnk_000.mFlags |= data_02158568;
        }
    }
    itemBox->mUnk_000.mDistanceSquaredAndFlags |= data_0215856c;
}
#pragma thumb off

MapObjectKindData *epipe_setupConfig(void) {
    MapObjectKindData *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_02158528;
    return kindData;
}

MapObjectDrawList *epipe_setupRenderPart(void) {
    epipe_sRenderPart = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    *epipe_sRenderPart = data_021584fc;
    mobj_renderPartSetThisPointer(&epipe_sRenderPart);
    return epipe_sRenderPart;
}

MapObjectList *epipe_setupLogicPart(void) {
    epipe_sLogicPart = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    *epipe_sLogicPart = data_021584d4;
    mobj_logicPartSetThisPointer(&epipe_sLogicPart);
    return epipe_sLogicPart;
}

void epipe_applyMaterial(void) {
    bbm_applyMaterial(epipe_sModel1);
}
