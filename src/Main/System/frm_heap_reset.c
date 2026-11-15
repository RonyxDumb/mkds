#include "Main/System/frm_heap_reset.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"

void ResetFrmHeap(void) {
    NNS_FndFreeToFrmHeap(gStartupWork->mHeap, 3);
}
