#include "Main/MapObjects/chandelier.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/seq_queue.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "fixed_arctangent.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/chandelier_rain_star.h"

MapObjectModel *gChandelier;

MapObjectKindDescriptor gChandelierKindDescriptor = {
    0, {0, 0}, 0xac, 0, CreateEmptyMapObjectKindData, CreateChandelierDrawList, 0, 0, CreateChandelierUpdateList};

void LoadChandelierMapObject(void *mapObjectList) {
    StructMapObject_AddAnimationNsbca_from_thumb(gChandelier = CreateMapObjectFromModel_from_thumb(mapObjectList, "chandelier.nsbmd"),
                                       "chandelier.nsbca");
    StructMapObject_MaybeSetPolygonId(gChandelier, 0x3f);
}
