#include "Main/MapObjects/koopa_block.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/System/state_machine_init.h"
#include "Main/System/heap_call.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/collision_hit_link.h"
#include "Main/MapObjects/group_item_box.h"
#include "Main/MapObjects/mkd_ef_bubble.h"
#include "Main/MapObjects/koopa_block_kind_descriptor.h"

const u16 gMkdEfBubbleState1SecondFlag = 8;
const u16 gMkdEfBubbleState1Flag = 2;
const MapObjectDrawList gMkdEfBubbleDrawListData = {{NULL,
                                                     0,
                                                     {0, 0},
                                                     (void (*)(MapObjectList *)) CreateMkdEfBubble,
                                                     NULL,
                                                     DrawMkdEfBubble,
                                                     NULL,
                                                     1,
                                                     NULL,
                                                     0,
                                                     NULL},
                                                    0};
const MkdEfBubbleUpdateList gMkdEfBubbleUpdateListData = {{NULL,
                                                           0,
                                                           {0, 0},
                                                           NULL,
                                                           (void (*)(MapObjectList *)) AdvanceMkdEfBubbleAnimation,
                                                           UpdateMkdEfBubble,
                                                           NULL,
                                                           0,
                                                           NULL,
                                                           0,
                                                           NULL},
                                                          0};
const MapObjectKindData gMkdEfBubbleKindData = {
    (s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithMkdEfBubble,
    (s32(*)(MapObject *, void *, void *, void *)) CollideItemObjectWithMkdEfBubble,
    1,
    0x19000,
    0,
    0,
    NULL,
    0,
    1,
    0x18d,
    0,
    0,
    0,
    0,
    0,
    0};

ModelAnimation *gMkdEfBubbleNsbta;
struct Nsbmd *gKoopaBlock;
MkdEfBubbleUpdateList *gMkdEfBubbleUpdateList;
MapObjectDrawList *gMkdEfBubbleDrawList;
struct Nsbmd *gMkdEfBubble;

#pragma thumb off

MapObjectKindData *CreateMkdEfBubbleKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gMkdEfBubbleKindData;
    return kindData;
}

MapObjectList *CreateMkdEfBubbleDrawList(void) {
    gMkdEfBubbleDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectDrawList));
    *gMkdEfBubbleDrawList = gMkdEfBubbleDrawListData;
    SetDrawListSlot(&gMkdEfBubbleDrawList);
    return &gMkdEfBubbleDrawList->mList;
}

MapObjectList *CreateMkdEfBubbleUpdateList(void) {
    gMkdEfBubbleUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MkdEfBubbleUpdateList));
    *gMkdEfBubbleUpdateList = gMkdEfBubbleUpdateListData;
    SetUpdateListSlot(&gMkdEfBubbleUpdateList);
    gMkdEfBubbleUpdateList->mAngleScale = FX_Div(0x4000000, 0x1333);
    return &gMkdEfBubbleUpdateList->mList;
}

void DrawMkdEfBubble(void *unused0, MkdEfBubbleObject *bubble, void *unused1, s32 alpha) {
    s32 value;
    s32 gxParam;
    MtxFx33 rotationMatrix;
    s32 amount;

    if (bubble->mMapObject.mStateMachine.mState != 0) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&bubble->mMapObject.mPos), 0xc);
    if (bubble->mAngleZ != 0) {
        MTX_RotZ33_(&rotationMatrix, SIN_OF_ANGLE(bubble->mAngleZ), COS_OF_ANGLE(bubble->mAngleZ));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bubble->mMapObject.mScale, 3);
    DrawNsbmdWithMaxAlpha(gMkdEfBubble, alpha);
    value = bubble->mMapObject.mPos.y - bubble->mInitialY;
    if (value > 0x10000) {
        value = 0x1000 - ((value - 0x10000) >> 8);
        bubble->mShadowMatrix.mAlphaCap = 0xd;
    } else {
        amount = 0xd - ((0x10000 - value) >> 13);
        value = 0x1000;
        if (amount < 1) {
            amount = 1;
        }
        bubble->mShadowMatrix.mAlphaCap = amount;
    }
    if (value <= 0) {
        return;
    }
    DrawObjShadow(&bubble->mShadowMatrix, &value, 0, alpha);
}

void AdvanceMkdEfBubbleAnimation(void) {
    AdvanceModelAnimation(gMkdEfBubbleNsbta);
}

void UpdateMkdEfBubble(void *unused, MkdEfBubbleObject *bubble) {
    AdvanceStateMachine(&bubble->mMapObject.mStateMachine);
    if (bubble->mEffectMissing != 0) {
        return;
    }
    if ((bubble->mMapObject.mFlags & 0x12) != 0) {
        bubble->mFirstEffect->mFlags.mHidden = 1;
        bubble->mSecondEffect->mFlags.mHidden = 1;
        return;
    }
    bubble->mFirstEffect->mFlags.mHidden = 0;
    bubble->mSecondEffect->mFlags.mHidden = 0;
    PlaceEffect(bubble->mFirstEffect, &bubble->mMapObject.mPos);
    PlaceEffect(bubble->mSecondEffect, &bubble->mMapObject.mPos);
}

void EnterMkdEfBubbleState0(MkdEfBubbleObject *bubble) {
    SoundStartParams soundRequest;
    s32 falloffIndex;
    BOOL effectMissing;

    bubble->mAngleZ = 0;
    bubble->mMapObject.mPos.y = bubble->mBottomY;
    bubble->mMapObject.mPosStep.y = 0x4b33;
    bubble->mMapObject.mFlags &= ~2;
    bubble->mMapObject.mFlags &= ~8;
    bubble->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    if ((bubble->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
        if (bubble->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
            falloffIndex = 2;
        } else if (bubble->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x18c;
        soundRequest.mPositionSource = &bubble->mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bubble->mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    bubble->mKartMask = 0;
    if (bubble->mFirstEffect == NULL) {
        bubble->mFirstEffect = StartEffect(0x45, &bubble->mMapObject.mPos);
    }
    if (bubble->mSecondEffect == NULL) {
        bubble->mSecondEffect = StartEffect(0x46, &bubble->mMapObject.mPos);
    }
    if (bubble->mFirstEffect == NULL || bubble->mSecondEffect == NULL) {
        effectMissing = TRUE;
    } else {
        effectMissing = FALSE;
    }
    bubble->mEffectMissing = effectMissing;
}

void UpdateMkdEfBubbleState0(MkdEfBubbleObject *bubble) {
    if (bubble->mMapObject.mPosStep.y < 0x1333) {
        if (bubble->mMapObject.mPosStep.y <= -0x1333) {
            bubble->mAngleZ = 0x8000;
        } else {
            bubble->mAngleZ = FROM_FIXED12(
                MUL_FIXED12_NO_ROUND(0x1333 - bubble->mMapObject.mPosStep.y, gMkdEfBubbleUpdateList->mAngleScale));
        }
    }
    bubble->mMapObject.mPosStep.y -= 0x199;
    if (bubble->mMapObject.mPosStep.y < -0x3000) {
        bubble->mMapObject.mPosStep.y = -0x3000;
    }
    bubble->mMapObject.mPos.y += bubble->mMapObject.mPosStep.y;
    if (bubble->mMapObject.mPos.y < bubble->mBottomY) {
        bubble->mMapObject.mStateMachine.mNextState = 1;
        bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}
