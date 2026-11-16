#include "Main/Item/dram_box.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/System/state_machine_init.h"
#include "Main/Menu/choises_s.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Sound/sound_start.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "fixed_vector_math.h"
#include "Main/Item/held_item.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_object_reset_collide.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Item/item_object_release.h"
#include "Main/Item/pooled_item_box_init.h"
#include "Main/Item/item_pool.h"
#include "Main/Sound/sound_data_sdat_path.h"

const u16 gMissionRunBoxMapObjectFlag = 1;
const u16 gItemObjectExcludedUntilCourseHitBit = ITEM_OWNER_EXCLUDED_UNTIL_COURSE_HIT;
const MapObjectKindDescriptor gMissionRunBoxKindDescriptor = {
    0,    {0, 0}, 0x144, InitMissionRunBoxMapObject, CreateMissionRunBoxKindData, NULL, NULL,
    NULL, NULL,   NULL,  {NULL, NULL, NULL, NULL}};

const MapObjectKindData gMissionRunBoxKindData = {NULL, NULL, 5, 0x190000, 0x64000, 0xaf000, NULL, 1,
                                                  1,    0,    0, 0,        0,       0,       0,    0};
MtxFx33 gItemFBoxRotation;
StateCallbacks gDramStateTable[6] = {{DramWaitDelayNop, UpdateDramWaitDelay}, {NULL, NULL},
                                     {EnterDramRampUp, UpdateDramRampUp},     {DramSteadyNop, UpdateDramSteady},
                                     {EnterDramRampDown, UpdateDramRampDown}, {EnterDramAlign, UpdateDramAlign}};

#pragma thumb on

void CreateDram(void) {
    CreateNsbmd(&gDram, FormatFindMapObjFileBuffer_from_thumb("dram.nsbmd"), NULL);
    StructML_SomeFn_1(gDram, 0x3f, 2, 0x294a);
}

void InitDram(Dram *dram, struct CourseMapRow *courseRow) {
    StateDualHandler_Create(&dram->mMapObject.mStateMachine, gDramStateTable, 6, dram);
    dram->mAnglePerFrameChoices[0] = courseRow->mSettings[0] * 0x80 / 100;
    dram->mAnglePerFrameChoices[2] = courseRow->mSettings[4] * 0x80 / 100;
    dram->mAnglePerFrameChoices[1] = (dram->mAnglePerFrameChoices[0] + dram->mAnglePerFrameChoices[2]) / 2;
    dram->mSteadyFrameCount = courseRow->mSettings[1];
    dram->mRampFrameCount = courseRow->mSettings[2];
    dram->mDelayFrameCount = courseRow->mSettings[3];
    dram->mAngleX = 0;
    if (dram->mRampFrameCount != 0) {
        dram->mRampPerFrame = DRAM_RAMP_FULL / dram->mRampFrameCount;
    } else {
        dram->mRampPerFrame = 0;
    }
    dram->mRamp = 0;
    dram->mMapObject.mStateMachine.mNextState = 1;
    dram->mMapObject.mStateMachine.mNextStateRequested = 1;
}

#pragma thumb off

MapObjectKindData *CreateMissionRunBoxKindData(void) {
    MapObjectKindData *kindData;

    kindData = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    kindData = Mem_AllocateHeap(kindData, sizeof(MapObjectKindData));
    *kindData = gMissionRunBoxKindData;
    return kindData;
}

BOOL IsMissionRunBoxKind(u32 kind) {
    return kind == 0xb;
}

#pragma thumb on

void InitMissionRunBoxMapObject(MissionRunBox *object) {
    object->mCollisionMapObject.mCollisionData.mPrevMatrix = object->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    object->mCollisionMapObject.mCollisionData.mTracksNormal = 0;
    object->mCollisionMapObject.mCollisionData.mHalfSizeX =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.x, 0x190000);
    object->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.y, 0x64000) >> 1;
    object->mCollisionMapObject.mCollisionData.mPositiveHalfSizeZ =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    object->mCollisionMapObject.mCollisionData.mNegativeHalfSizeZ =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    object->mCollisionMapObject.mCollisionData.mAxis0Flag = 0;
    object->mCollisionMapObject.mCollisionData.mHitFlagWords.x = 1;
    object->mCollisionMapObject.mCollisionData.mHitFlagWords.y = 0;
    object->mCollisionMapObject.mCollisionData.mHitFlagWords.z = 0;
    object->mCollisionMapObject.mCollisionData.mFloorThreshold = FIXED12_RATIO(1, 2);
    object->mCollisionMapObject.mCollisionData.mPreviousPos = object->mCollisionMapObject.mMapObject.mPos;
    object->mCollisionMapObject.mMapObject.mPosStep.x = 0;
    object->mCollisionMapObject.mMapObject.mPosStep.y = 0;
    object->mCollisionMapObject.mMapObject.mPosStep.z = 0;
    VecFx32_AddScale1(-object->mCollisionMapObject.mCollisionData.mHalfSizeY,
                &object->mCollisionMapObject.mMapObject.mMatrix.mRows[1], &object->mCollisionMapObject.mMapObject.mPos,
                &object->mCollisionMapObject.mCollisionData.mCenterPos);
    object->mCollisionMapObject.mCollisionData.mShape = COLLISION_SHAPE_BOX;
    object->mCollisionMapObject.mCollisionData.mCollisionFlag = 0;
    object->mCollisionMapObject.mSkipsFlaggedQueries = 1;
    object->mCollisionMapObject.mMapObject.mFlags |= gMissionRunBoxMapObjectFlag;
}

#pragma thumb off

void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out) {
    Vec3 *position;

    position = fbox->mBouncingItemObject.mItemObject.mPosPointer;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].x = position->x >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].y = position->y >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].z = position->z >> 4;
    *out = fbox->mBouncingItemObject.mItemObject.mTransformMtx;
    MTX_Concat33(&gItemFBoxRotation, &out->mAxes, &out->mAxes);
}

void SetItemFBoxPushedDrawMatrix(ItemFBox *fbox, MtxFx43 *out) {
    s32 scaledX, scaledZ;
    Vec3 *position;

    if ((fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADING_OUT) &&
        IsRaceOptionMenuOn_from_thumb() == 0) {
        s32 row0Dot, row2Dot;

        row0Dot = DOT2_FIXED12(fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x, fbox->mPushDirection.x,
                               fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z, fbox->mPushDirection.z);
        scaledX = MUL_FIXED12_NO_ROUND(fbox->mPushDirection.x, 0xa4);
        row2Dot = DOT2_FIXED12(fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x, fbox->mPushDirection.x,
                               fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z, fbox->mPushDirection.z);
        scaledZ = MUL_FIXED12_NO_ROUND(fbox->mPushDirection.z, 0xa4);
        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x =
            (s32) (fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x + scaledX);
        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].z += scaledZ;
        if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x *
                    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].x +
                (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].y *
                    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].y +
                (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].z *
                    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1].z >=
            0x10) {
            Vector3_MaybeNormalize(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1]);
        }
        if (row0Dot * row0Dot > row2Dot * row2Dot) {
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x =
                (s32) (fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x - scaledX);
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z -= scaledZ;
            Vector3_Cross(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
            if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z >=
                0x10) {
                Vector3_MaybeNormalize(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                                                   &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
            }
            Vector3_Cross(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
        } else {
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x -= scaledX;
            fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z -= scaledZ;
            Vector3_Cross(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
            if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].x +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].y *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].y +
                    (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z *
                        fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2].z >=
                0x10) {
                Vector3_MaybeNormalize(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2],
                                                   &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
            }
            Vector3_Cross(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2],
                               &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
        }
    }
    position = fbox->mBouncingItemObject.mItemObject.mPosPointer;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].x = position->x >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].y = position->y >> 4;
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[3].z = position->z >> 4;
    *out = fbox->mBouncingItemObject.mItemObject.mTransformMtx;
}

void ResetItemFBox(ItemFBox *fbox) {
    fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes = gItemFBoxRotation;
    ResetPooledMapObject(fbox->mPooledMapObject);
    fbox->mPooledMapObject->mShadowMode = ITEM_BOX_SHADOW_NONE;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, SetItemFBoxDrawMatrix, fbox);
}

void StartItemFBox(ItemFBox *fbox) {
    fbox->mPooledMapObject->mShadowMode = ITEM_BOX_SHADOW_AT_POSITION;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, SetItemFBoxPushedDrawMatrix, fbox);
}

void AdvanceItemFBoxInUse(ItemInUse *inUse, ItemFBox *fbox) {
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mBouncingItemObject.mItemObject.mAlpha,
                               &fbox->mBouncingItemObject.mItemObject.mScale);
}

u32 InitItemFBox(ItemInUse *inUse, ItemFBox *fbox) {
    StartItemObjectSoundSource(&fbox->mBouncingItemObject.mItemObject);
    fbox->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= gItemObjectExcludedUntilCourseHitBit;
    MTX_Concat33(&gItemFBoxRotation, &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes,
                 &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes);
    fbox->mPushDirection.x = 0;
    fbox->mPushDirection.y = 0;
    fbox->mPushDirection.z = 0;
    if ((inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&fbox->mBouncingItemObject, inUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StructMQRacerEntry_SomeFn_8(&fbox->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        fbox->mThrownForward = 1;
        return fbox->mThrownForward;
    }
    ThrowBouncingItem(&fbox->mBouncingItemObject, inUse, 0, 0, 0x4000, 0x3000, 0x59a);
    fbox->mThrownForward = 0;
    return fbox->mThrownForward;
}

void AdvanceItemFBox(ItemFBox *fbox) {
    s32 unusedOutput;

    if (fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) {
        if (fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADING_OUT) {
            AdvanceItemObjectFadeOut(&fbox->mBouncingItemObject.mItemObject);
        } else if (fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_RELEASING) {
            AdvanceItemObjectReleaseTimer(&fbox->mBouncingItemObject.mItemObject);
        }
    } else if (fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_RESTING) {
        AdvanceRestingItemObject(&fbox->mBouncingItemObject.mItemObject);
    } else if (fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_LAUNCHED) {
        AdvanceFallingItemObject(&fbox->mBouncingItemObject.mItemObject);
    } else {
        if (fbox->mThrownForward != 0) {
            AdvanceBouncingItem(&fbox->mBouncingItemObject, 0x1ec, 0xfec, 0, (u32 *) &unusedOutput);
        } else {
            AdvanceBouncingItem(&fbox->mBouncingItemObject, 0x2e1, 0xf85, 0, (u32 *) &unusedOutput);
        }
        if ((fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_LANDED) &&
            (fbox->mBouncingItemObject.mItemObject.mFlags &
             (ITEM_OBJECT_FLAG_FADE_OUT_STARTED | ITEM_OBJECT_FLAG_RELEASE_STARTED)) == 0) {
            if (fbox->mThrownForward != 0) {
                fbox->mBouncingItemObject.mItemObject.mVelocity.y *= 2;
            }
            StopSound(&fbox->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&fbox->mBouncingItemObject.mItemObject, &unusedOutput);
        }
    }
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mBouncingItemObject.mItemObject.mAlpha,
                               &fbox->mBouncingItemObject.mItemObject.mScale);
}

s32 ItemFBoxFadeOutCallback(ItemFBox *fbox) {
    Vec3 *vector;

    vector = gItemPushVector;
    if (LENGTH_SQUARED(*vector) >= 0x10) {
        Vector3_MaybeNormalize(vector, &fbox->mPushDirection);
    }
    fbox->mPooledMapObject->mShadowMode = ITEM_BOX_SHADOW_NONE;
    if ((fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        fbox->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
    return 2;
}

void SetupItemFBoxAfterLaunch(ItemFBox *fbox) {
    if ((s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x *
                fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].x +
            (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y *
                fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].y +
            (s64) fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z *
                fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0].z >=
        0x10) {
        Vector3_MaybeNormalize(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                                           &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0]);
    }
    Vector3_Cross(&fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[0],
                       &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[1],
                       &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mRows[2]);
    MTX_Concat33(&gItemFBoxRotation, &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes,
                 &fbox->mBouncingItemObject.mItemObject.mTransformMtx.mAxes);
    if ((fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        fbox->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
}
