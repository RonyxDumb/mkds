#include "Main/MapObjects/mkd_ef_bubble_kind_descriptor.h"
#include "Main/MapObjects/koopa_block.h"
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
#include "Main/MapObjects/mkd_ef_bubble.h"

const u16 gMkdEfBubbleInitFlag = 0x200;
const MapObjectKindDescriptor gMkdEfBubbleKindDescriptor = {0,
                                                            {0, 0},
                                                            0xf4,
                                                            InitMkdEfBubble,
                                                            CreateMkdEfBubbleKindData,
                                                            CreateMkdEfBubbleDrawList,
                                                            NULL,
                                                            NULL,
                                                            CreateMkdEfBubbleUpdateList,
                                                            NULL,
                                                            {NULL, NULL, NULL, NULL}};

StateCallbacks gMkdEfBubbleStateTable[2] = {{EnterMkdEfBubbleState0, UpdateMkdEfBubbleState0},
                                            {EnterMkdEfBubbleState1, UpdateMkdEfBubbleState1}};

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
