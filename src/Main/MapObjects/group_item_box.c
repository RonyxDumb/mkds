#include "Main/MapObjects/group_item_box.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/item_box.h"
#include "Main/System/state_machine_init.h"
#include "Main/Graphics/model_animation_loop_mode.h"
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
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/koopa_block.h"
#include "Main/MapObjects/mkd_ef_bubble.h"

const u16 gGroupItemBoxEntryFlag = 0x20;
const MapObjectList gGroupItemBoxUpdateListData = {NULL, 0, {0, 0}, (void (*)(MapObjectList *)) InitGroupItemBoxObjects, (void (*)(MapObjectList *)) UpdateGroupItemBoxHeightOffset, UpdateGroupItemBox, NULL, 0, NULL, 0, NULL};
const MapObjectKindData gGroupItemBoxKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithItemBox, NULL, 1, 0xf000, 0, 0, NULL, 0, 2, 0, 0, 0, 0, 0, 0, 0};
StateCallbacks gMkdEfBubbleStateTable[2] = {{EnterMkdEfBubbleState0, UpdateMkdEfBubbleState0}, {EnterMkdEfBubbleState1, UpdateMkdEfBubbleState1}};
u16 gGroupItemBoxHeightAngle;
MapObjectList *gGroupItemBoxUpdateList;
s32 gGroupItemBoxShadowScaleWord;
s32 gGroupItemBoxHeightOffset;
Vec3 gGroupItemBoxShadowScale;

#pragma thumb on
void CreateMkdEfBubble(void) {
    void *nsbmd;

    nsbmd = FindCourseMapObjFile("mkd_ef_bubble.nsbmd");
    CreateNsbmd(&gMkdEfBubble, nsbmd, NULL);
    SetNsbmdPolygonIdLightEmiAll(gMkdEfBubble, 0x3f, 2, 0x294a);
    gMkdEfBubbleNsbta = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(1, gMkdEfBubble, gMkdEfBubbleNsbta, nsbmd,
                                  FindCourseMapObjFile("mkd_ef_bubble.nsbta"));
    SetModelAnimationEntryLoopMode(gMkdEfBubbleNsbta, 0, 1);
}

void InitMkdEfBubble(MkdEfBubbleObject *bubble, CourseMapRow *row) {
    InitStateMachine(&bubble->mMapObject.mStateMachine, gMkdEfBubbleStateTable, 2, bubble);
    bubble->mDelayFrameCount = row->mSettings[0];
    bubble->mInitialY = bubble->mMapObject.mPos.y;
    bubble->mBottomY = bubble->mMapObject.mPos.y - 0x10000;
    bubble->mMapObject.mPosStep.x = 0;
    bubble->mMapObject.mPosStep.y = 0;
    bubble->mMapObject.mPosStep.z = 0;
    bubble->mAngleZ = 0;
    bubble->mMapObject.mStateMachine.mNextState = 0;
    bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&bubble->mShadowMatrix, &bubble->mMapObject.mPos,
                        MUL_FIXED12_NO_ROUND(bubble->mMapObject.mScale.x, 0x18000), 0xd);
    bubble->mMapObject.mFlags |= gMkdEfBubbleInitFlag;
}
#pragma thumb off

MapObjectKindData *CreateGroupItemBoxKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gGroupItemBoxKindData;
    return kindData;
}

MapObjectList *CreateGroupItemBoxUpdateList(void) {
    gGroupItemBoxUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *gGroupItemBoxUpdateList = gGroupItemBoxUpdateListData;
    SetUpdateListSlot(&gGroupItemBoxUpdateList);
    return gGroupItemBoxUpdateList;
}

void UpdateGroupItemBoxHeightOffset(void) {
    s32 sine;

    sine = FX_SinIdx(gGroupItemBoxHeightAngle);
    gGroupItemBoxHeightOffset = MUL_FIXED12_NO_ROUND(sine, 0x4000);
    gGroupItemBoxHeightAngle += 0x2d8;
    gGroupItemBoxShadowScaleWord = 0xf00 - (sine >> 4);
    gGroupItemBoxShadowScale.x = 0x1666;
    gGroupItemBoxShadowScale.y = 0x1666;
    gGroupItemBoxShadowScale.z = 0x1666;
}

void UpdateGroupItemBox(void *unused, ItemBox *itemBox) {
    if (itemBox->mFollower.mGroupFollower.mGroupIndex != 0xffff) {
        if (AdvanceGroupFollowerWithSpeeds(&itemBox->mFollower) != 0) {
            if (itemBox->mFollower.mGroupFollower.mFromEntry->mUnk_10 != 0) {
                SetupGroupFollowerWithSpeeds(&itemBox->mFollower, 0, 1);
            }
        }
        GetGroupFollowerCurvePosition(&itemBox->mFollower.mGroupFollower, &itemBox->mMapObject.mPos);
        if (itemBox->mFollower.mGroupFollower.mFromEntry->mUnk_0d != 0 &&
            itemBox->mFollower.mGroupFollower.mToEntry->mUnk_0d != 0) {
            itemBox->mMapObject.mFlags |= gGroupItemBoxEntryFlag;
        } else {
            itemBox->mMapObject.mFlags &= ~0x20;
        }
        itemBox->mMapObject.mPos.y += gGroupItemBoxHeightOffset;
        itemBox->mMapObject.mPos.y += 0x10000;
    }
    if (itemBox->mShadowMode == 0) {
        SetShadowPositionXZ(&itemBox->mUnk_0b4, &itemBox->mMapObject.mPos);
    }
    UpdateItemBox(unused, itemBox);
}

