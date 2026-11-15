#include "Main/MapObjects/second_hand_kind_descriptor.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor_distance_flag.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/Item/item_objects_and_race_progress.h"
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
#include "Main/MapObjects/map_object_response_and_quaternion_math.h"
#include "Main/MapObjects/pushed_motion.h"
#include "ITCM/kart_motion.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/pushed_object_states_init.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/MapObjects/woodbox1_kind_data.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
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
                                                           CreateSecondHandDrawList,
                                                           NULL,
                                                           NULL,
                                                           CreateSecondHandUpdateList,
                                                           NULL,
                                                           {NULL, NULL, NULL, NULL}};

#pragma thumb on

StateCallbacks gSecondHandStateTable[4] = {{EnterSecondHandSpeedUp, UpdateSecondHandSpeedUp},
                                           {SecondHandSteadyNop, UpdateSecondHandSteady},
                                           {EnterSecondHandSlowDown, UpdateSecondHandSlowDown},
                                           {SecondHandPauseNop, UpdateSecondHandPause}};

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
        secondHand->mSpeedFractionPerFrame = FIXED12_UNIT / secondHand->mRampFrameCount;
    } else {
        secondHand->mSpeedFractionPerFrame = 0;
    }
    secondHand->mSpeedFraction = 0;
    secondHand->mMapObject.mStateMachine.mNextState = SECOND_HAND_STATE_SPEED_UP;
    secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    secondHand->mMapObject.mFlags |= gSecondHandFlag;
}
#pragma thumb off
