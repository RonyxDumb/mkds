#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188218.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/code_0218bfc8.h"
#include "01/code_0218c000.h"
#include "01/code_0218c55c.h"
#include "01/code_0218c5fc.h"
#include "01/code_0218c63c.h"
#include "01/callees_0219b000.h"
#include "Main/MapObjects/map_object_model_frame.h"
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
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/snd_handle_start.h"
#include "01/code_0218b000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "01/Race/mission_run_state.h"
#include "01/code_02187d14.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_0218c0a4.h"
#include "01/code_0218d520.h"
#include "01/MapObjects/map_object_model_load.h"
#include "01/code_0219b250.h"
#include "Main/Race/standings_balloons.h"
#include "tp.h"

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
