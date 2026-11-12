#pragma once

#include "types.h"

#include "01/MapObjects/coin.h"
#include "01/MapObjects/map_object_animation.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/code_02186000.h"
#include "01/Race/mission_run_state.h"
#include "01/code_021843b0.h"
#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188484.h"
#include "01/code_02188da4.h"
#include "01/MapObjects/iwante.h"
#include "Main/System/heap_call.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/data_020f36d8.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "01/code_02183000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188e24.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/code_021882b8.h"
#include "01/code_02187bfc.h"
#include "01/code_02188260.h"
#include "01/code_02184e18.h"
#include "01/code_02187e78.h"
#include "01/code_02188cd8.h"
#include "01/code_02188de0.h"
#include "01/code_02184000.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/snd_handle_start.h"
#include "01/code_021842b4.h"
#include "01/code_021842ec.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"

#include "01/code_0218b9b4.h"

void *CreateDonketuUpdateList(void);
void *CreateKingIceDonketuDrawList(void);
void *CreateBossDonketuDrawList(void);
void CreateDonketuKindData(void);
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

extern Unk021a7b64 gBossDonketuKindDescriptor;
extern Unk021a7b64 gKingIceDonketuKindDescriptor;
