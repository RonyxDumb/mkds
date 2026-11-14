#include "Main/MapObjects/item_box_kind_descriptor.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Course/course_triangle_flag.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/earthen_pipe.h"
#include "Main/MapObjects/group_item_box_kind_descriptor.h"

const u16 gItemBoxTriangleFlag2Flag = 0x20;
const u32 gItemBoxInitDistanceFlag = 0x10;
const MapObjectKindDescriptor gItemBoxKindDescriptor = {0,
                                                        {0, 0},
                                                        0x108,
                                                        InitItemBox,
                                                        CreateItemBoxKindData,
                                                        CreateItemBoxShadowDrawList,
                                                        CreateQuestionDrawList,
                                                        CreateBoxDrawList,
                                                        CreateItemBoxUpdateList,
                                                        NULL,
                                                        {NULL, NULL, NULL, NULL}};

#pragma thumb on
void CreateBoxAndQuestion(void) {
    s32 boxIndex;
    s32 questionIndex;
    s32 cosine;
    s32 sine;
    u32 angleIndex;
    NsbmdModel *model;

    CreateNsbmdModel(&gBox, FindMainRaceOrMainEffectMapObjFile("box.nsbmd"), 0, 0);
    CreateNsbmdModel(&gQuestion, FindMainRaceOrMainEffectMapObjFile("question.nsbmd"), 0, 0);
    SetNsbmdModelFixedAttributes(gBox);
    SetNsbmdModelFixedAttributes(gQuestion);
    model = gBox;
    model->mSpecEmi = model->mSpecEmi & 0x8000ffff;
    model->mSpecEmi = model->mSpecEmi | 0x52940000;
    model = gQuestion;
    model->mSpecEmi = model->mSpecEmi & 0x8000ffff;
    model->mSpecEmi = model->mSpecEmi | 0x52940000;
    gBoxRotations = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1770);
    for (boxIndex = 0; boxIndex < 0x12c; boxIndex++) {
        angleIndex = (u16) (((u32) boxIndex << 16) / 0x12c) >> 4;
        cosine = FX_SinCosTable_[angleIndex * 2 + 1];
        sine = FX_SinCosTable_[angleIndex * 2];
        gBoxRotations[boxIndex].mCosine = cosine;
        gBoxRotations[boxIndex].mSine = sine;
        gBoxRotations[boxIndex].mCosineSquared = MUL_FIXED12_NO_ROUND(cosine, cosine);
        gBoxRotations[boxIndex].mSineSquared = MUL_FIXED12_NO_ROUND(sine, sine);
        gBoxRotations[boxIndex].mCosineSineProduct = MUL_FIXED12_NO_ROUND(cosine, sine);
    }
    gQuestionRotations = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x410);
    for (questionIndex = 0; questionIndex < 0x82; questionIndex++) {
        angleIndex = (u16) (((u32) questionIndex << 16) / 0x82) >> 4;
        gQuestionRotations[questionIndex].mCosine = FX_SinCosTable_[angleIndex * 2 + 1];
        gQuestionRotations[questionIndex].mSine = FX_SinCosTable_[angleIndex * 2];
    }
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        gBox->mPolygonAttributes &= 0xffff7fff;
        gQuestion->mPolygonAttributes &= 0xffff7fff;
    }
}

void InitItemBox(ItemBox *itemBox, CourseMapRow *row) {
    RandomState64 *random;
    Vec3 shadowPos;
    BOOL usesGroupShadow;

    itemBox->mMapObject.mPos.y += 0xc000;
    itemBox->mPositionSource = &itemBox->mMapObject.mPos;
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemBox->mBoxRotationIndex = ((u64) (u32) (random->mValue >> 32) * 0x12c) >> 32;
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemBox->mQuestionRotationIndex = ((u64) (u32) (random->mValue >> 32) * 0x82) >> 32;
    itemBox->mFramesSinceHit = 0x80;
    if (row != NULL) {
        if (itemBox->mMapObject.mKind == 0xc9 && row->mGroupIndex >= 0) {
            usesGroupShadow = TRUE;
        } else {
            usesGroupShadow = FALSE;
        }
        itemBox->mUsesGroupShadow = usesGroupShadow;
        itemBox->mShortSpin = row->mSettings[6];
        itemBox->mNoCourseRow = 0;
    } else {
        itemBox->mUsesGroupShadow = 1;
        itemBox->mShortSpin = 0;
        itemBox->mNoCourseRow = 1;
        SetMapObjectScale(&itemBox->mMapObject, &gItemBoxDefaultScale);
    }
    if (itemBox->mNoCourseRow != 0) {
        itemBox->mForcedRowHumanGhostPeer = 0;
        itemBox->mForcedRowCpu = 0;
    } else {
        itemBox->mForcedRowHumanGhostPeer = row->mSettings[1];
        itemBox->mForcedRowCpu = row->mSettings[2];
    }
    if (itemBox->mNoCourseRow != 0) {
        itemBox->mShadowMode = 1;
    } else {
        itemBox->mShadowMode = row->mSettings[3];
        if (itemBox->mShadowMode == 0) {
            shadowPos = row->mPosition;
            if (itemBox->mUsesGroupShadow != 0) {
                shadowPos.y += 0x800;
            }
            if (RefreshShadowMatrix(&itemBox->mShadowMatrix, &shadowPos, 0x14000, 0xd) == 0) {
                itemBox->mShadowMode = 2;
            }
        }
    }
    if (row != NULL) {
        if (HasCourseTriangleFlag2At(&row->mPosition) != 0) {
            itemBox->mMapObject.mFlags |= gItemBoxTriangleFlag2Flag;
        }
    }
    itemBox->mMapObject.mDistanceSquaredAndFlags |= gItemBoxInitDistanceFlag;
}
