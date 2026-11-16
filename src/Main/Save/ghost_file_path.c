#include "Main/Save/ghost_file_path.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "formatted_text_to_buffer.h"


u32 FormatGhostFilePath(u32 number, char *buffer, u32 size) {
    OS_SNPrintf(buffer, size, "/data/ghost/ghost_%03d.bin", number);
    return 1;
}
