#include "Main/Kart/kart_appear.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"

#pragma thumb on

KartAppear *LoadKartAppearTablePointer_from_thumb(void *heap) {
    KartAppear *kartAppear;
    kartAppear = Mem_AllocateHeap(heap, 4);
    kartAppear->mFileData = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("/kart_appear.ktbl");
    return kartAppear;
}

#pragma thumb off
