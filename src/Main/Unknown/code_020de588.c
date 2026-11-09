#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_02036820.h"
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
void CreateBoxAndQuestion(void) {
    s32 boxIndex;
    s32 questionIndex;
    s32 cosine;
    s32 sine;
    u32 angleIndex;
    NsbmdModel *p;

    CreateNsbmdModel(&gBox, FindMainRaceOrMainEffectMapObjFile("box.nsbmd"), 0, 0);
    CreateNsbmdModel(&gQuestion, FindMainRaceOrMainEffectMapObjFile("question.nsbmd"), 0, 0);
    SetNsbmdModelFixedAttributes(gBox);
    SetNsbmdModelFixedAttributes(gQuestion);
    p = gBox;
    p->mSpecEmi = p->mSpecEmi & 0x8000ffff;
    p->mSpecEmi = p->mSpecEmi | 0x52940000;
    p = gQuestion;
    p->mSpecEmi = p->mSpecEmi & 0x8000ffff;
    p->mSpecEmi = p->mSpecEmi | 0x52940000;
    gBoxRotations = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1770);
    for (boxIndex = 0; boxIndex < 0x12c; boxIndex++) {
        angleIndex = (u16) (((u32) boxIndex << 16) / 0x12c) >> 4;
        cosine = gPairsByAngle[angleIndex * 2 + 1];
        sine = gPairsByAngle[angleIndex * 2];
        gBoxRotations[boxIndex].mCosine = cosine;
        gBoxRotations[boxIndex].mSine = sine;
        gBoxRotations[boxIndex].mCosineSquared = MUL_FIXED12_NO_ROUND(cosine, cosine);
        gBoxRotations[boxIndex].mSineSquared = MUL_FIXED12_NO_ROUND(sine, sine);
        gBoxRotations[boxIndex].mCosineSineProduct = MUL_FIXED12_NO_ROUND(cosine, sine);
    }
    gQuestionRotations = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x410);
    for (questionIndex = 0; questionIndex < 0x82; questionIndex++) {
        angleIndex = (u16) (((u32) questionIndex << 16) / 0x82) >> 4;
        gQuestionRotations[questionIndex].mCosine = gPairsByAngle[angleIndex * 2 + 1];
        gQuestionRotations[questionIndex].mSine = gPairsByAngle[angleIndex * 2];
    }
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        gBox->mPolygonAttributes &= 0xffff7fff;
        gQuestion->mPolygonAttributes &= 0xffff7fff;
    }
}

void InitItemBox(ItemBox *itemBox, CourseMapRow *row) {
    RandomState64 *random;
    Vec3 shadowPos;
    BOOL v1;

    itemBox->mUnk_000.mPos.y += 0xc000;
    itemBox->mPositionSource = &itemBox->mUnk_000.mPos;
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemBox->mBoxRotationIndex = ((u64) (u32) (random->mValue >> 32) * 0x12c) >> 32;
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemBox->mQuestionRotationIndex = ((u64) (u32) (random->mValue >> 32) * 0x82) >> 32;
    itemBox->mFramesSinceHit = 0x80;
    if (row != NULL) {
        if (itemBox->mUnk_000.mKind == 0xc9 && row->mUnk_26 >= 0) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
        itemBox->mUsesGroupShadow = v1;
        itemBox->mUnk_0ac = row->mUnk_34;
        itemBox->mNoCourseRow = 0;
    } else {
        itemBox->mUsesGroupShadow = 1;
        itemBox->mUnk_0ac = 0;
        itemBox->mNoCourseRow = 1;
        SetMapObjectScale(&itemBox->mUnk_000, &data_02158694);
    }
    if (itemBox->mNoCourseRow != 0) {
        itemBox->mUnk_0f2 = 0;
        itemBox->mUnk_0f4 = 0;
    } else {
        itemBox->mUnk_0f2 = row->mUnk_2a;
        itemBox->mUnk_0f4 = row->mUnk_2c;
    }
    if (itemBox->mNoCourseRow != 0) {
        itemBox->mShadowMode = 1;
    } else {
        itemBox->mShadowMode = row->mUnk_2e;
        if (itemBox->mShadowMode == 0) {
            shadowPos = row->mUnk_00;
            if (itemBox->mUsesGroupShadow != 0) {
                shadowPos.y += 0x800;
            }
            if (RefreshShadowMatrix(&itemBox->mUnk_0b4, &shadowPos, 0x14000, 0xd) == 0) {
                itemBox->mShadowMode = 2;
            }
        }
    }
    if (row != NULL) {
        if (func_020e512c(&row->mUnk_00) != 0) {
            itemBox->mUnk_000.mFlags |= data_02158568;
        }
    }
    itemBox->mUnk_000.mDistanceSquaredAndFlags |= data_0215856c;
}
#pragma thumb off

MapObjectKindData *CreateEarthenPipeKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158528;
    return kindData;
}

MapObjectDrawList *CreateEarthenPipeDrawList(void) {
    gEarthenPipeDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gEarthenPipeDrawList = data_021584fc;
    SetDrawListSlot(&gEarthenPipeDrawList);
    return gEarthenPipeDrawList;
}

MapObjectList *CreateEarthenPipeUpdateList(void) {
    gEarthenPipeUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *gEarthenPipeUpdateList = data_021584d4;
    SetUpdateListSlot(&gEarthenPipeUpdateList);
    return gEarthenPipeUpdateList;
}

void SetupDrawEarthenPipe(void) {
    QueueNsbmdModelMaterial(gEarthenPipe1);
}
