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
#include "fixed_vector_math.h"
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

StateCallbacks gMkdEfBubbleStateTable[2] = {{EnterMkdEfBubbleLeap, UpdateMkdEfBubbleLeap},
                                            {EnterMkdEfBubbleWait, UpdateMkdEfBubbleWait}};

#pragma thumb on
void CreateMkdEfBubble(void) {
    void *nsbmd;

    nsbmd = FindCourseMapObjFile("mkd_ef_bubble.nsbmd");
    CreateNsbmd(&gMkdEfBubble, nsbmd, NULL);
    SetNsbmdPolygonIdLightEmiAll(gMkdEfBubble, 0x3f, 2, 0x294a);
    gMkdEfBubbleNsbta = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gMkdEfBubbleNsbta));
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
    bubble->mMapObject.mStateMachine.mNextState = MKD_EF_BUBBLE_STATE_LEAP;
    bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&bubble->mShadowMatrix, &bubble->mMapObject.mPos,
                        MUL_FIXED12_NO_ROUND(bubble->mMapObject.mScale.x, 0x18000), MKD_EF_BUBBLE_SHADOW_ALPHA_CAP);
    bubble->mMapObject.mFlags |= gMkdEfBubbleInitFlag;
}
