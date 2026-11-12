#include "Main/Menu/wait.h"

#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "gfd_VramTransferManager.h"
#include "code_0214cfe4.h"
#include "Main/Menu/wait_load.h"

#pragma thumb on

const u16 gWaitBnclIndices[4] = {0, 1, 2, 0};

void AdvanceWait(void) {
    u16 *paletteData;
    Wait *wait;

    gWait->mFrameIndexFrames++;
    if (gWait->mFrameIndexFrames >= 4) {
        gWait->mFrameIndex++;
        if (gWait->mFrameIndex >= 3) {
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
                NNS_GfdRegisterNewVramTransferTask(0xe, wait->mPaletteIndex << 5, paletteData + 0xe0, 0x20);
                break;
            case 1:
                NNS_GfdRegisterNewVramTransferTask(0x1e, wait->mPaletteIndex << 5, paletteData + 0xe0, 0x20);
                break;
        }
    }
}

#pragma thumb off
