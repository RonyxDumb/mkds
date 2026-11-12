#include "Main/MapObjects/chandelier.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/MapObjects/sun.h"

u16 FX_Atan2Idx(s32 a, s32 b);

void CreateChandelier(void *mapObjectList) {
    CreateMapObjectModelNsbcaAnimation(gChandelier = CreateMapObjectModelAnimated(mapObjectList, gChandelierNsbmdName),
                                       gChandelierNsbcaName);
    SetMapObjectModelPolygonId(gChandelier, 0x3f);
}
