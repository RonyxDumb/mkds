#include "Main/Menu/shuffled_indices.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/MapObjects/teresa_spawner.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/race_hud_sub_screen_pakkun_spit_cells.h"
#include "Main/Menu/menu_shared_clear.h"

u32 ShuffledIndicesGetConnectionKind(void) {
    return (g_GlobalP->mConnectionKind);
}

RandomState64 *ShuffledIndicesGetConnectionWorkRandomState(void) {
    return &g_GlobalZE->mRandomState;
}

#pragma optimize_for_size on

#pragma thumb on
void FillShuffledIndices(void) {
    s32 remaining[8];
    s32 remainingCount;
    s32 index;
    s32 pickIndex;
    s32 shiftIndex;
    RandomState64 *random;

    remainingCount = 8;
    if (g_GlobalB488->mIndicesShuffled == 0) {
        if (ShuffledIndicesGetConnectionKind() == 1 || ShuffledIndicesGetConnectionKind() == 2) {
            random = ShuffledIndicesGetConnectionWorkRandomState();
            for (index = 0; index < 8; index++) {
                remaining[index] = index;
            }
            for (index = 0; index < 8; index++) {
                pickIndex = (NextRandomU16(random) >> 8) % remainingCount;
                g_GlobalB488->mShuffledIndices[index] = remaining[pickIndex];
                remainingCount--;
                for (shiftIndex = pickIndex; shiftIndex < remainingCount; shiftIndex++) {
                    remaining[shiftIndex] = remaining[shiftIndex + 1];
                }
            }
            g_GlobalB488->mIndicesShuffled = 1;
        }
    }
}

void ResetB488HeyhoPaletteRows_from_thumb(void) {
    s32 index;
    BOOL clearValue;

    clearValue = FALSE;
    for (index = 0; index < 8; index++) {
        g_GlobalB488->mShuffledIndices[index] = clearValue;
    }
    g_GlobalB488->mIndicesShuffled = clearValue;
}
#pragma thumb off

BOOL CreateRaceHudSubScreenPakkunSpitCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPakkunSpitCells, 0x1ab);
}
