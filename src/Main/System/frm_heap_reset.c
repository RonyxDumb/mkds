#include "Main/System/frm_heap_reset.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

void ResetFrmHeap(void) {
    NNS_FndFreeToFrmHeap(gStartupWork->mHeap, 3);
}
