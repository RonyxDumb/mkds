#pragma once

#include "types.h"

#include "01/MapObjects/coin.h"
#include "01/MapObjects/map_object_animation.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "01/Race/mission_run_state.h"
#include "01/MapObjects/donketu_chase_kart_collision.h"
#include "01/MapObjects/mission_run_group_entry_queries.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/mission_run_collision_shadow_offsets.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "01/MapObjects/iwante.h"
#include "Main/System/heap_call.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/MapObjects/mission_run_map_objects_reset.h"
#include "01/MapObjects/item_bomb_throw_or_release.h"
#include "01/MapObjects/mission_run_hit_count.h"
#include "01/MapObjects/donketu_step_effects.h"
#include "01/MapObjects/mission_run_entry_index.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/mission_run_point_in_range_callback.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "Main/Sound/sound_handle_start_and_distance_change.h"
#include "01/MapObjects/donketu_fall.h"
#include "01/MapObjects/donketu_water_land_state.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"

#include "01/MapObjects/kuriking_state_shared.h"

// MissionRunMapObject.mStateNumber of Donketu after a kart hit launched it (boosted or not), while it falls, and after
// it landed in the water; hits no longer launch it.
#define DONKETU_STATE_LAUNCH_FALL_LAND 7

MapObjectList *CreateDonketuUpdateList(void);
MapObjectList *CreateKingIceDonketuDrawList(void);
MapObjectList *CreateBossDonketuDrawList(void);
MapObjectKindData *CreateDonketuKindData(void);
void DrawDonketu(void *mapObjectList, MissionRunMapObject *donketu);
void InitKingIceDonketu(MapObjectList *list);
void InitBossDonketu(MapObjectList *list);
void InitDonketuSoundSource(MissionRunMapObject *donketu);
void UpdateDonketu(u32 mapObjectList, MissionRunMapObject *donketu);
void InitDonketuObjects(MapObjectList *list);
void StartDonketuChainStartupFirst(MissionRunMapObject *donketu);
void StartDonketuChainStartupSecond(MissionRunMapObject *donketu);
void StartDonketuStartupFirst(MissionRunMapObject *donketu);
void StartDonketuStartupSecond(MissionRunMapObject *donketu);
void StartDonketuWaitForRaceStart(MissionRunMapObject *donketu);
s32 UpdateDonketuKingIceEffects(MissionRunMapObject *donketu);
int UpdateDonketuStartupEffects(MissionRunMapObject *donketu);
int UpdateDonketuWaitForRaceStart(MissionRunMapObject *donketu);
void DonketuStandingsEndCallback(void);
void StartDonketuKartEliminatedState(MissionRunMapObject *donketu);
void StartDonketuWaterFallState(MissionRunMapObject *donketu);
void StartDonketuWalkState(MissionRunMapObject *donketu);
void StartDonketuWalkToCourseMapRow(MissionRunMapObject *donketu);
void StartDonketuChaseKartState(MissionRunMapObject *donketu);
void StartDonketuChaseRunAtStart(MissionRunMapObject *donketu);
void StartDonketuChaseWaitState(MissionRunMapObject *donketu);
void StartDonketuChaseRunState(MissionRunMapObject *donketu);
void StartDonketuChaseStopState(MissionRunMapObject *donketu);
s32 UpdateDonketuChaseStop(MissionRunMapObject *donketu);
void StartDonketuJumpWaitState(MissionRunMapObject *donketu);
void StartDonketuJumpState(MissionRunMapObject *donketu);
u32 UpdateDonketuJumpSound(MissionRunMapObject *donketu);
void StartDonketuJumpLandState(MissionRunMapObject *donketu);
void StartDonketuKartNotEliminatedState(MissionRunMapObject *donketu);
void StartDonketuWaterSinkState(MissionRunMapObject *donketu);
void StartDonketuWaterWalkState(MissionRunMapObject *donketu);
void StartDonketuWaterJumpState(MissionRunMapObject *donketu);

extern MapObjectKindDescriptor gBossDonketuKindDescriptor;
extern MapObjectKindDescriptor gKingIceDonketuKindDescriptor;
