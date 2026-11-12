#include "Main/MapObjects/chandelier.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/seq_queue.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/bound.h"

u16 FX_Atan2Idx(s32 a, s32 b);

void CreateChandelier(void *mapObjectList) {
    CreateMapObjectModelNsbcaAnimation(gChandelier = CreateMapObjectModelAnimated(mapObjectList, gChandelierNsbmdName),
                                       gChandelierNsbcaName);
    SetMapObjectModelPolygonId(gChandelier, 0x3f);
}
