#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/kuriking_turn_to_entry_state.h"
#include "01/MapObjects/kuriking_face_kart_state.h"
#include "01/MapObjects/kuriking_sound_callbacks_setup.h"
#include "01/MapObjects/kuriking_collision_and_shadow_targets.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
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
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "01/Race/mission_run_state.h"
#include "01/MapObjects/item_bomb_node_placement.h"
#include "01/MapObjects/mission_run_entry_index.h"
#include "01/MapObjects/mission_run_group_entry_queries.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/kuriking_walk_state_starters.h"
#include "01/MapObjects/hanachan_move_and_followers.h"
#include "01/MapObjects/map_object_model_load.h"
#include "01/MapObjects/map_object_model_animation_load.h"
#include "Main/Race/standings_balloons.h"
#include "touch_panel_sampling.h"

void StartKurikingChaseKartState(MissionRunMapObject *mapObject);
void GrowKuriking(MissionRunMapObject *mapObject);
void StartKurikingGrowState(MissionRunMapObject *mapObject);
int UpdateKurikingGrowSound(MissionRunMapObject *mapObject);
void StartKurikingTurnToRowState(MissionRunMapObject *mapObject);
void StartKurikingJumpAnimationState(MissionRunMapObject *mapObject);
void StartKurikingJumpState(MissionRunMapObject *mapObject);
void StartKurikingJumpLandState(MissionRunMapObject *mapObject);
void StartKurikingFaceKartState(MissionRunMapObject *mapObject);
void StartKurikingThrowBombsState(MissionRunMapObject *mapObject);

#include "01/Menu/select_ghost.h"
