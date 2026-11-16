#pragma once

#include "types.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
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

void SetDonketuStepEffectCallbacks(MissionRunMapObject *mapObject);
void SetDonketuStepSoundCallbacks(MissionRunMapObject *mapObject);
void StartKingIceDonketuStepEffectSecond(MissionRunMapObject *mapObject);
void StartKingIceDonketuStepEffectFirst(MissionRunMapObject *mapObject);
void StartBossDonketuStepEffectSecond(MissionRunMapObject *mapObject);
void StartBossDonketuStepEffectFirst(MissionRunMapObject *mapObject);
