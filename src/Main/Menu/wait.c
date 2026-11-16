#include "Main/Menu/wait.h"

#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "vram_transfer_queue.h"
#include "cpu_copy_clear_16.h"
#include "Main/Menu/wait_load.h"

#pragma thumb on

const u16 gWaitBnclIndices[4] = {0, 1, 2, 0};

void AdvanceWait(void) {
    u16 *paletteData;
    Wait *wait;

    gWait->mFrameIndexFrames++;
    if (gWait->mFrameIndexFrames >= WAIT_FRAME_INDEX_CHANGE_FRAMES) {
        gWait->mFrameIndex++;
        if (gWait->mFrameIndex >= WAIT_FRAME_INDEX_COUNT) {
            gWait->mFrameIndex = 0;
        }
        gWait->mFrameIndexFrames = 0;
        QueueCellChars(gWaitBnclIndices[gWait->mFrameIndex], gWait->mNcer, gWait->mNcgr, gWait->mBncl,
                       gWait->mQueueSelector, gWait->mDestinationBnclIndex, gWait->mDestinationNcer,
                       gWait->mDestinationBncl);
        wait = gWait;
        paletteData = wait->mNclr->mData;
        switch (wait->mQueueSelector) {
            case 0:
                NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, wait->mPaletteIndex << 5,
                                                   paletteData + 0xe0, 0x20);
                break;
            case 1:
                NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, wait->mPaletteIndex << 5,
                                                   paletteData + 0xe0, 0x20);
                break;
        }
    }
}

#pragma thumb off
