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
#include "Main/Item/item_objects_and_race_progress.h"
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
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "vector_math.h"
#include "Main/MapObjects/koopa_block.h"
#include "Main/MapObjects/mkd_ef_bubble.h"
#include "Main/MapObjects/mkd_ef_bubble_kind_descriptor.h"

const u16 gGroupItemBoxEntryFlag = 0x20;
const MapObjectList gGroupItemBoxUpdateListData = {NULL,
                                                   0,
                                                   {0, 0},
                                                   (void (*)(MapObjectList *)) InitGroupItemBoxObjects,
                                                   (void (*)(MapObjectList *)) UpdateGroupItemBoxHeightOffset,
                                                   UpdateGroupItemBox,
                                                   NULL,
                                                   0,
                                                   NULL,
                                                   0,
                                                   NULL};
const MapObjectKindData gGroupItemBoxKindData = {(s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithItemBox,
                                                 NULL,
                                                 1,
                                                 0xf000,
                                                 0,
                                                 0,
                                                 NULL,
                                                 0,
                                                 2,
                                                 0,
                                                 0,
                                                 0,
                                                 0,
                                                 0,
                                                 0,
                                                 0};
u16 gGroupItemBoxHeightAngle;
MapObjectList *gGroupItemBoxUpdateList;
s32 gGroupItemBoxHeightOffset;
s32 gGroupItemBoxShadowScaleWord;
Vec3 gGroupItemBoxShadowScale;

#pragma thumb off

MapObjectKindData *CreateGroupItemBoxKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gGroupItemBoxKindData;
    return kindData;
}

MapObjectList *CreateGroupItemBoxUpdateList(void) {
    gGroupItemBoxUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
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
    if (itemBox->mFollower.mGroupFollower.mGroupIndex != GROUP_FOLLOWER_NO_GROUP) {
        if (AdvanceGroupFollowerWithSpeeds(&itemBox->mFollower) != 0) {
            if (itemBox->mFollower.mGroupFollower.mFromEntry->mExtraValue != 0) {
                SetupGroupFollowerWithSpeeds(&itemBox->mFollower, 0, 1);
            }
        }
        GetGroupFollowerCurvePosition(&itemBox->mFollower.mGroupFollower, &itemBox->mMapObject.mPos);
        if (itemBox->mFollower.mGroupFollower.mFromEntry->mFlagBitOn != 0 &&
            itemBox->mFollower.mGroupFollower.mToEntry->mFlagBitOn != 0) {
            itemBox->mMapObject.mFlags |= gGroupItemBoxEntryFlag;
        } else {
            itemBox->mMapObject.mFlags &= ~0x20;
        }
        itemBox->mMapObject.mPos.y += gGroupItemBoxHeightOffset;
        itemBox->mMapObject.mPos.y += 0x10000;
    }
    if (itemBox->mShadowMode == 0) {
        SetShadowPositionXZ(&itemBox->mShadowMatrix, &itemBox->mMapObject.mPos);
    }
    UpdateItemBox(unused, itemBox);
}

