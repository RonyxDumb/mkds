#include "Main/Kart/kart_appear.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"

#pragma thumb on

KartAppear *CreateKartAppear(void *heap) {
    KartAppear *kartAppear;
    kartAppear = HeapAlloc(heap, 4);
    kartAppear->mFileData = FindFileInLoadedArchives("/kart_appear.ktbl");
    return kartAppear;
}

#pragma thumb off
