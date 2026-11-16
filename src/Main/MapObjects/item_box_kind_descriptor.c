#include "Main/MapObjects/item_box_kind_descriptor.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Course/course_triangle_flag.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "fixed_vector_math.h"
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
    gBoxRotations = HeapAlloc(GetHeap(GetCurrentHeapCall()), BOX_ROTATION_COUNT * sizeof(*gBoxRotations));
    for (boxIndex = 0; boxIndex < BOX_ROTATION_COUNT; boxIndex++) {
        angleIndex = (u16) (((u32) boxIndex << 16) / BOX_ROTATION_COUNT) >> 4;
        cosine = FX_SinCosTable_[angleIndex * 2 + 1];
        sine = FX_SinCosTable_[angleIndex * 2];
        gBoxRotations[boxIndex].mCosine = cosine;
        gBoxRotations[boxIndex].mSine = sine;
        gBoxRotations[boxIndex].mCosineSquared = MUL_FIXED12_NO_ROUND(cosine, cosine);
        gBoxRotations[boxIndex].mSineSquared = MUL_FIXED12_NO_ROUND(sine, sine);
        gBoxRotations[boxIndex].mCosineSineProduct = MUL_FIXED12_NO_ROUND(cosine, sine);
    }
    gQuestionRotations =
        HeapAlloc(GetHeap(GetCurrentHeapCall()), QUESTION_ROTATION_COUNT * sizeof(*gQuestionRotations));
    for (questionIndex = 0; questionIndex < QUESTION_ROTATION_COUNT; questionIndex++) {
        angleIndex = (u16) (((u32) questionIndex << 16) / QUESTION_ROTATION_COUNT) >> 4;
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
    itemBox->mBoxRotationIndex = ((u64) (u32) (random->mValue >> 32) * ITEM_BOX_BOX_ROTATION_STEPS) >> 32;
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemBox->mQuestionRotationIndex = ((u64) (u32) (random->mValue >> 32) * ITEM_BOX_QUESTION_ROTATION_STEPS) >> 32;
    itemBox->mFramesSinceHit = ITEM_BOX_HIT_FRAMES_MAX;
    if (row != NULL) {
        if (itemBox->mMapObject.mKind == MAP_OBJECT_KIND_ITEM_BOX_GROUP_SHADOW && row->mGroupIndex >= 0) {
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
                itemBox->mShadowMode = ITEM_BOX_SHADOW_MODE_REFRESH_FAILED;
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
