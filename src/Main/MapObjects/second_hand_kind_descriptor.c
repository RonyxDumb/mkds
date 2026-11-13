#include "Main/MapObjects/second_hand_kind_descriptor.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Item/item_koura_w.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/MapObjects/pushed_motion.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/pushed_object_states_init.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/code_020ec1fc.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/Course/course_triangle_flag.h"

const u16 gSecondHandFlag = 0x200;
const MapObjectKindDescriptor gSecondHandKindDescriptor = {0,
                                                           {0, 0},
                                                           0xd0,
                                                           (void (*)(void *, CourseMapRow *, void *)) InitSecondHand,
                                                           CreateSecondHandKindData,
                                                           (MapObjectList *(*)(void)) CreateSecondHandDrawList,
                                                           NULL,
                                                           NULL,
                                                           CreateSecondHandUpdateList,
                                                           NULL,
                                                           {NULL, NULL, NULL, NULL}};

#pragma thumb on

StateCallbacks gSecondHandStateTable[4] = {{EnterSecondHandState0, UpdateSecondHandState0}, {(UnkFunc *) SecondHandState1ReturnArgument, UpdateSecondHandState1}, {EnterSecondHandState2, UpdateSecondHandState2}, {(UnkFunc *) SecondHandState3ReturnArgument, UpdateSecondHandState3}};

void InitSecondHand(SecondHand *secondHand, CourseMapRow *courseRow) {
    secondHand->mMapObject.mExtent.y = MUL_FIXED12_NO_ROUND(secondHand->mMapObject.mScale.x, 0x4b000);
    InitStateMachine(&secondHand->mMapObject.mStateMachine, gSecondHandStateTable, 4, secondHand);
    QuaternionFromVec3Degrees(&courseRow->mRotationDegrees, &secondHand->mRotationQuaternion);
    secondHand->mInitialRotationQuaternion = secondHand->mRotationQuaternion;
    secondHand->mRampFrameCount = courseRow->mSettings[2];
    secondHand->mSteadyFrameCount = courseRow->mSettings[1];
    secondHand->mPauseFrameCount = courseRow->mSettings[3];
    secondHand->mAnglePerFrame = (courseRow->mSettings[0] << 7) / 0x64;
    if (courseRow->mSettings[4] != 0) {
        secondHand->mAnglePerFrame = -secondHand->mAnglePerFrame;
    }
    secondHand->mMapObject.mAngle = 0;
    if (secondHand->mRampFrameCount != 0) {
        secondHand->mSpeedFractionPerFrame = 0x1000 / secondHand->mRampFrameCount;
    } else {
        secondHand->mSpeedFractionPerFrame = 0;
    }
    secondHand->mSpeedFraction = 0;
    secondHand->mMapObject.mStateMachine.mNextState = 0;
    secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    secondHand->mMapObject.mFlags |= gSecondHandFlag;
}
#pragma thumb off
